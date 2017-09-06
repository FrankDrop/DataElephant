function varargout = checkOrSelectByHash(obj,hash,fasthash,stepnr,lastStepInSequence,lookForFasthash)
    
    requestToLoad       = nargout == 4;
    
    if lookForFasthash
        n_hash                  = size(fasthash,1);
        [uniqueHash,~,icu]      = unique(fasthash,'rows');
    else
        n_hash                  = size(hash,1);
        [uniqueHash,~,icu]      = unique(hash,'rows');
    end
    
    ia  = [];
    ib  = [];
    
    n_uhash                 = size(uniqueHash,1);
    
    if obj.steps(stepnr).type % = step
        if ~isempty(obj.shorthash)
            [~,ia,ib]       = intersect(obj.shorthash,uniqueHash(:,(end-(obj.hashlength-1)):end),'rows');
        end
    else % = decision
        if lookForFasthash
            if ~isempty(obj.dec_fasthash)
                [~,ia,ib]       = intersect(obj.dec_fasthash,uniqueHash,'rows');
            end
        else
            if ~isempty(obj.dec_shorthash)
                [~,ia,ib]       = intersect(obj.dec_shorthash,uniqueHash(:,(end-(obj.hashlength-1)):end),'rows');
            end
        end
    end

    if requestToLoad
        z_n_u           = cell(n_uhash,1);
        r_n_u           = cell(n_uhash,1);
        decision_u      = cell(n_uhash,1);
        
        z_n             = cell(n_hash,1);
        r_n             = cell(n_hash,1);
        decision        = cell(n_hash,1);

        if obj.steps(stepnr).type % = step
            for oo=1:length(ia)
                if ~isempty(obj.data(ia(oo)).z)
                    z_n_u{ib(oo)} = obj.data(ia(oo)).z;
                end
                if ~isempty(obj.data(ia(oo)).r_n)
                    r_n_u{ib(oo)} = obj.data(ia(oo)).r_n;
                end
            end
        else
            for oo=1:length(ia)
                if ~isempty(obj.dec_data(ia(oo)).z)
                    z_n_u{ib(oo)}       = obj.dec_data(ia(oo)).z;
                end
                if ~isempty(obj.dec_data(ia(oo)).decision)
                    decision_u{ib(oo)}  = obj.dec_data(ia(oo)).decision;
                end
            end
        end
    end

    checklist_u     = false(n_uhash,1);
    for oo=1:length(ib)
        checklist_u(ib(oo)) = true;
    end
    
    if obj.fileverbose
        fprintf('%sJust retrieved %i results from memory.\n',sprintf(repmat('\t',1,stepnr)),length(ia));
    end
    
    if sum(checklist_u) ~= n_hash && obj.load_hdd == 1 && obj.steps(stepnr).saveme

        ids = find(~checklist_u);
        if requestToLoad
            if lookForFasthash
                [z_n_i,r_n_i,decision_i,checklist_i] = checkOrLoadFromDisk(obj,[],               uniqueHash(ids,:),stepnr,lastStepInSequence,true);
            else
                [z_n_i,r_n_i,decision_i,checklist_i] = checkOrLoadFromDisk(obj,uniqueHash(ids,:),[]               ,stepnr,lastStepInSequence,false);
            end
            
            for hh=1:length(ids)
                z_n_u{ids(hh)}         = z_n_i{hh};
                r_n_u{ids(hh)}         = r_n_i{hh}; 
                decision_u{ids(hh)}    = decision_i{hh};
                checklist_u(ids(hh))   = checklist_i(hh);
            end
            
            if obj.fileverbose
                fprintf('%sJust retrieved %i results from HDD.\n',sprintf(repmat('\t',1,stepnr)),sum(checklist_i));
            end
        else
            if lookForFasthash
                checklist_u(ids) = checkOrLoadFromDisk(obj,[],               uniqueHash(ids,:),stepnr,lastStepInSequence,true);
            else
                checklist_u(ids) = checkOrLoadFromDisk(obj,uniqueHash(ids,:),[]               ,stepnr,lastStepInSequence,false);
            end
        end
    end
    
    if requestToLoad
        if obj.steps(stepnr).type % = step
            for oo=1:length(icu)
                z_n{oo}     = z_n_u{icu(oo)};
                r_n{oo}     = r_n_u{icu(oo)};
            end
        else
            for oo=1:length(icu)
                z_n{oo}         = z_n_u{icu(oo)};
                decision{oo}    = decision_u{icu(oo)};
            end
        end
    end
    
    checklist       = false(n_hash,1);
    for oo=1:length(icu)
        checklist(oo)   = checklist_u(icu(oo));
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