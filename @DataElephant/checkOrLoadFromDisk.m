function varargout = checkOrLoadFromDisk(obj,hash,fasthash,step,lastStepInSequence,lookForFasthash)

    requestToLoad   = nargout == 4;
    
    saveme  = obj.steps(step).saveme;
    
    if lookForFasthash
        n_hash          = size(fasthash,1);
        
        uniqueHashes    = unique(fasthash,'rows');
        
        if size(uniqueHashes,1) ~= size(fasthash,1)
            error('hu?');
        end
    else
        prefixhash      = unique(hash(:,1:(end-obj.hashlength)),'rows');
        shrthash        = hash(:,(end-(obj.hashlength-1)):end);
        n_hash          = size(hash,1);
        
        uniqueHashes    = unique(hash,'rows');
        
        if size(uniqueHashes,1) ~= size(hash,1)
            error('hu?');
        end
        
        assert(size(prefixhash,1) == 1 || size(prefixhash,1) == size(uniqueHashes,1),'Boo!');
        
        if obj.fileverbose
            fprintf('%sGoing to search for %i hashes on the hdd.\n',sprintf(repmat('\t',1,step)),n_hash);
            if n_hash < 30
                for uu=1:n_hash
                    fprintf('%s- %s [%s\b]\n',sprintf(repmat('\t',1,step)),hexhash(obj,shrthash(uu,:)),sprintf('%3i ',shrthash(uu,:)));
                end
            end
        end
    end

    checklist       = false(n_hash,1);
        
    if requestToLoad
        z_n         = cell(n_hash,1);
        r_n         = cell(n_hash,1);
        decision    = cell(n_hash,1);
    end
    
    for jj=1:3 % There are three sources and methods for loading.
        if jj == 1
            if obj.steps(step).type % step
                for ll=1:size(prefixhash,1)                    
                    if size(prefixhash,1) == 0
                        fldr        = [obj.getRootFolder() '/' obj.steps(step).name '_' num2str(obj.steps(step).version)];
                    elseif size(prefixhash,1) == 1
                        fldr        = [obj.getRootFolder() '/' obj.steps(step).name '_' num2str(obj.steps(step).version) '/' hexhash(obj,prefixhash)];
                    elseif size(prefixhash,1) > 1
                        fldr        = [obj.getRootFolder() '/' obj.steps(step).name '_' num2str(obj.steps(step).version) '/' hexhash(obj,prefixhash(ll,:))];
                    end
                    
                    if strcmp(fldr(end),'/')
                        fldr = fldr(1:(end-1));
                    end

                    if obj.fileverbose
                        fprintf('%sGoing to search for the data in the folder %s.\n',sprintf(repmat('\t',1,step)),fldr);
                    end

                    getLock(obj,fldr,true);

                    N_files     = dir([fldr '/N_*.mat']);
                    kk = 0;

                    if obj.fileverbose
                        fprintf('%sFound %i files that potentially have useful data. We are still looking for %i results.\n',sprintf(repmat('\t',1,step)),length(N_files),sum(~checklist));
                    end

                    while kk < length(N_files) && ((size(prefixhash,1) <= 1 && ~all(checklist)) || (size(prefixhash,1) > 1 && ~checklist(ll)))

                        tkn     = regexp(N_files(kk+1).name,'([0-9]*)','tokens');
                        fid     = [tkn{1}{:}];                
                        fn_D    = [fldr '/D_' fid '.mat'];
                        fn_N    = [fldr '/' N_files(kk+1).name];

                        if exist(fn_D,'file') == 2 && exist(fn_N,'file') == 2

                            getLock(obj,fn_D,true);
                            getLock(obj,fn_N,true);

                            ndata                   = load(fn_N);
                            
                            if size(prefixhash,1) > 1
                                [~,~,ib]    = intersect(shrthash(ll,:),ndata.H,'rows');
                                if ~isempty(ib)
                                    ia          = ll;
                                else
                                    ia          = [];
                                end
                            else
                                [~,ia,ib]   = intersect(shrthash,ndata.H,'rows');
                            end
                            
                            inThisFile              = ia;
                            checklist(inThisFile)   = true;

                            if obj.fileverbose
                                fprintf('%sI just found %i earlier computed results on the HDD from file %s.\n',sprintf(repmat('\t',1,step)),length(ia),fn_D);
                            end

                            if requestToLoad && ~any(inThisFile)
                                if obj.fileverbose
                                    fprintf('%sThe file exists, but no useful data is in the file %s.\n',sprintf(repmat('\t',1,step)),fn_D);
                                end
                            end

                            if requestToLoad && any(inThisFile)
                                if obj.fileverbose
                                    fprintf('%sLoading %i earlier computed results from the HDD from file %s.\n',sprintf(repmat('\t',1,step)),length(ia),fn_D);
                                end

                                sdata       = load(fn_D);

                                if obj.fileverbose && length(ia) > 100
                                    fprintf('%sFinished loading, processing loaded data.\n',sprintf(repmat('\t',1,step)));
                                end

                                added   = true;

                                for ii=1:length(ia)
                                    z_n{ia(ii)}     = sdata.H(ib(ii)).z;
                                    r_n{ia(ii)}     = sdata.H(ib(ii)).r_n;

                                    
                                    if added
%                                         [~,uD_idx]      = min(sum(abs(uniqueHashes - repmat(hash(ia(ii),:),size(uniqueHashes,1),1)),2));
                                        
%                                         if ~addedYet(uD_idx)
                                            added = add(obj,hash(ia(ii),:),...
                                                    [],...
                                                    z_n{ia(ii)},...
                                                    r_n{ia(ii)},...
                                                    [],...
                                                    false,...               % new
                                                    0,...                   % time
                                                    step,...
                                                    lastStepInSequence,...
                                                    saveme);
%                                             addedYet(uD_idx) = true;
                                            
%                                             if ~added
%                                                 error('why not?')
%                                             end
%                                         end
                                    end
                                end
                            end

                            if obj.fileverbose && length(ia) > 100
                                fprintf('%sFinished processing loaded data.\n',...
                                    sprintf(repmat('\t',1,step)));
                            end

                            releaseLock(obj,fn_D,true);
                            releaseLock(obj,fn_N,true);
                        else
                            if obj.fileverbose
                                fprintf(2,'Did not find %s or %s.\n',fn_D,fn_N);
                            end
                        end
                        kk = kk + 1;
                    end

                    releaseLock(obj,fldr,true);
                end
                
            else % decision
                
                for oo=1:n_hash
                    
                    if lookForFasthash
                        
                        fldr        = [obj.getRootFolder() '/' obj.steps(step).name '_' num2str(obj.steps(step).version) '/_FAST'];
                        fnm         = [fldr '/' hexhash(obj,fasthash(oo,:)) '.mat'];
                        
                        if obj.fileverbose
                            fprintf('%sLooking for a fast decision in the file %s for step %i.\n',sprintf(repmat('\t',1,step)),fnm,step);
                        end
                        
                        if exist(fnm,'file') == 2
                            getLock(obj,fnm, true);
                                H               = load(fnm);
                                z_n{oo}         = H.(['H_' hexhash(obj,fasthash(oo,:))]).z;
                                decision{oo}    = H.(['H_' hexhash(obj,fasthash(oo,:))]).decision;
                                checklist(oo)   = true;

                                add(obj,[],...
                                        fasthash(oo,:),...
                                        z_n{oo},...
                                        [],...
                                        decision{oo},...
                                        false,...               % new
                                        0,...                   % time
                                        step,...
                                        lastStepInSequence,...
                                        saveme);
                            releaseLock(obj,fnm,true);
                            if obj.fileverbose
                                fprintf('%sFound and loaded the fast decision %s for step %i.\n',sprintf(repmat('\t',1,step)),fnm,step);
                            end
                        else
                            checklist(oo)   = false;
                            if obj.fileverbose
                                fprintf('%Did not find the fast decision %s for step %i.\n',sprintf(repmat('\t',1,step)),fnm,step);
                            end
                        end
                    else
                        if isempty(prefixhash)
                            fldr        = [obj.getRootFolder '/' obj.steps(step).name '_' num2str(obj.steps(step).version)];
                        else
                            fldr        = [obj.getRootFolder '/' obj.steps(step).name '_' num2str(obj.steps(step).version) '/' hexhash(obj,prefixhash)];
                        end
                        
                        if strcmp(fldr(end),'/')
                            fldr = fldr(1:(end-1));
                        end
                        
                        fnm         = [fldr '/' hexhash(obj,hash(oo,:)) '.mat'];
                        
                        if obj.fileverbose
                            fprintf('%sLooking for a normal decision in the file %s for step %i.\n',sprintf(repmat('\t',1,step)),fnm,step);
                        end
                        
                        if exist(fnm,'file') == 2
                            
                            getLock(obj,fnm, true);
                            H               = load(fnm);
                            z_n{oo}         = H.(['H_' hexhash(obj,hash(oo,:))]).z;
                            decision{oo}    = H.(['H_' hexhash(obj,hash(oo,:))]).decision;
                            checklist(oo)   = true;
                            
                            
%                             [~,uD_idx]      = min(sum(abs(uniqueHashes - repmat(hash(oo,:),size(uniqueHashes,1),1)),2));
                            
%                             if ~addedYet(uD_idx)
                                if ~isempty(fasthash)
                                    % If we are looking for a normal decision
                                    % hash (and find it), it is very likely
                                    % this is because the fast hash does not
                                    % exist yet. So we mark it new so that it
                                    % will be saved.
                                    add(obj,hash(oo,:),...
                                            fasthash(oo,:),...
                                            z_n{oo},...
                                            [],...
                                            decision{oo},...
                                            true,...                % new
                                            0,...                   % time
                                            step,...
                                            lastStepInSequence,...
                                            saveme);
                                else
                                    % Obviously, we can only do that if the
                                    % fasthash is actually set.
                                    add(obj,hash(oo,:),...
                                            [],...
                                            z_n{oo},...
                                            [],...
                                            decision{oo},...
                                            false,...               % new
                                            0,...                   % time
                                            step,...
                                            lastStepInSequence,...
                                            saveme);
                                end
%                                 addedYet(uD_idx)    = true;
%                             end
                            releaseLock(obj,fnm,true);
                            
                            if obj.fileverbose
                                fprintf('%sFound and loaded the normal decision %s for step %i.\n',sprintf(repmat('\t',1,step)),fnm,step);
                            end
                        else
                            checklist(oo)   = false;
                            if obj.fileverbose
                                fprintf('%Did not find the normal decision %s for step %i.\n',sprintf(repmat('\t',1,step)),fnm,step);
                            end
                        end
                    end
                end
            end
        else
            if lookForFasthash
                break;
            end
            
            oo = jj -1;

            if oo == 1 && obj.load_old && ~all(checklist)
                error('You still want to use this?!')
                [filename,~,varname,ori_id] = getFolderAndVarname(obj,hash,step);
                go = true;
            elseif oo == 2 && obj.load_really_old && ~all(checklist)
                error('You still want to use this?!')
                [filename,~,varname,ori_id] = getFolderAndVarnameOld(obj,hash,obj.steps(step).type);
                go = true;
            else
                go = false;
            end

            if go
                for uu=1:length(filename)                
                    if exist(filename{uu},'file') == 2

                        if obj.fileverbose
                            fprintf(2,'Found %s. Number of data sets in memory: %i. Number of hashes: %i.\n',filename{uu},length(obj.data),length(obj.hash));
                        end
                        getLock(obj,filename{uu},true);

                        vars                    = whos('-file',filename{uu});
                        [~,ia,~]                = intersect(varname{uu},{vars.name});
                        inThisFile              = ori_id{uu}(ia);
                        checklist(inThisFile)   = true;
                        
                        
                        if requestToLoad && any(inThisFile)

                            if obj.verbose
                                fprintf('%sLoading %i earlier computed results from the HDD from file %s.\n',...
                                    sprintf(repmat('\t',1,step)),length(ia),filename{uu});
                            end
                            sdata       = load(filename{uu});
                            if obj.verbose && length(ia) > 100
                                fprintf('%sFinished loading, processing loaded data.\n',...
                                    sprintf(repmat('\t',1,step)));
                            end

                            ttt                     = 0;
                            
                            if obj.steps(step).type % = step
                                added   = true;
                                for ii=1:length(ia)
                                    if isempty(z_n{ori_id{uu}(ia(ii))})
                                        z_n{ori_id{uu}(ia(ii))}         = sdata.(varname{uu}{ia(ii)}).z;
                                        r_n{ori_id{uu}(ia(ii))}         = sdata.(varname{uu}{ia(ii)}).r_n;
                                        ttt = ttt + 1;
                                        
                                        if added
                                            added = add(obj,hash(ori_id{uu}(ia(ii)),:),...
                                                    [],...
                                                    z_n{ori_id{uu}(ia(ii))},...
                                                    r_n{ori_id{uu}(ia(ii))},...
                                                    decision{ori_id{uu}(ia(ii))},...
                                                    true,...
                                                    0,...
                                                    step,...
                                                    lastStepInSequence,...
                                                    saveme);
                                        end
                                    end
                                end
                            else
%                                 added   = true;
                                for ii=1:length(ia)
                                    if isempty(z_n{ori_id{uu}(ia(ii))})
                                        z_n{ori_id{uu}(ia(ii))}         = sdata.(varname{uu}{ia(ii)}).z;
                                        decision{ori_id{uu}(ia(ii))}    = sdata.(varname{uu}{ia(ii)}).decision;
                                        ttt = ttt + 1;
                                        
                                        isempty(fasthash)
                                        length(ia)
                                        
                                        if ~isempty(fasthash) && length(ia) == 1
                                            add(obj,hash(ori_id{uu}(ia(ii)),:),...
                                                    fasthash(1,:),...
                                                    z_n{ori_id{uu}(ia(ii))},...
                                                    r_n{ori_id{uu}(ia(ii))},...
                                                    decision{ori_id{uu}(ia(ii))},...
                                                    true,...
                                                    0,...
                                                    step,...
                                                    lastStepInSequence,...
                                                    saveme);
                                        else
                                            add(obj,hash(ori_id{uu}(ia(ii)),:),...
                                                    [],...
                                                    z_n{ori_id{uu}(ia(ii))},...
                                                    r_n{ori_id{uu}(ia(ii))},...
                                                    decision{ori_id{uu}(ia(ii))},...
                                                    true,...
                                                    0,...
                                                    step,...
                                                    lastStepInSequence,...
                                                    saveme);
                                        end
                                    end
                                end
                            end
                            
                            if obj.verbose && length(ia) > 100
                                fprintf('%s%i results were useful.\n',...
                                    sprintf(repmat('\t',1,step)),ttt);
                            end
                        end

                        if obj.verbose && length(ia) > 100
                            fprintf('%sFinished processing loaded data.\n',...
                                sprintf(repmat('\t',1,step)));
                        end
                        releaseLock(obj,filename{uu},true);
                    end
                end
            end
        end
    end

    if requestToLoad
        varargout{1} = z_n;
        varargout{2} = r_n;
        varargout{3} = decision;
        varargout{4} = checklist;
    else
        varargout{1} = checklist;
    end
end