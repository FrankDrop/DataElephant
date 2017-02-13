function id = generateHash(obj,~,z_step,stepnr,id_req_s,decisionFunctional,functionalStartAt,decisionStartAt,decisionTakenAt,decisionFunctionalRange,decisionDecidesOver)

    % Putting some variables in easy to access variable names.
    t_step  = obj.steps(stepnr);
    z_step  = z_step{stepnr};
    
    if isstruct(z_step)
        s_fields     = fieldnames(z_step);
    else
        s_fields     = {};
    end
    n_fields    = length(s_fields);
    
    % If there is no decision to take as a function of something, we have
    % just 1 nr_func
    if ~isempty(decisionFunctional)
        if stepnr >= functionalStartAt
            nr_func     = length(decisionFunctionalRange);
        else
            nr_func     = 1;
        end
    else
        nr_func = 1;
    end
    
    if stepnr == 1
        prehash     = -1*ones(2*n_fields+2,16,nr_func);
    elseif stepnr > 1
        prehash     = -1*ones(2*n_fields+3,16,nr_func);
    end
    
    prehash(2*n_fields+1,:,:) = repmat(CalcMD5(obj.steps(stepnr).name,   'char','Dec').',1,nr_func);
    prehash(2*n_fields+2,:,:) = repmat(CalcMD5(obj.steps(stepnr).version,'char','Dec').',1,nr_func);
    
    betweenDecisions    = false;
    atDecision          = [];
    for oo=1:length(decisionStartAt)
        if stepnr >= decisionStartAt(oo) && stepnr <= decisionTakenAt(oo)
            betweenDecisions    = true;
            atDecision          = oo;
            break;
        end
    end
    
    if stepnr >= functionalStartAt
        
        for oo=1:length(s_fields)
            if iscell(z_step.(s_fields{oo})) 
                if strcmp(s_fields{oo},decisionFunctional)
                    if isfield(obj.fnchashcache,s_fields{oo})
                        fnchash     = obj.fnchashcache.(s_fields{oo});
                    else
                        error('The function hash cache is missing for %s.',s_fields{oo});
                    end

                    prehash(2*oo-1,:,:)     = repmat(CalcMD5(s_fields{oo},'char','Dec').',1,nr_func);
                    prehash(2*oo  ,:,:)     = fnchash.';
                else
                    error('Big error!');
                end
            else
                prehash(2*oo-1,:,:) = repmat(CalcMD5(s_fields{oo},'char','Dec').',1,nr_func);
                prehash(2*oo  ,:,:) = repmat(CalcMD5(z_step.(s_fields{oo}),'char','Dec').',1,nr_func);
            end
        end


        if ~t_step.type % decision
            % We need to combine the prior hashes into the number of
            % decisions to be taken again
            thislastcommon              = lastCommonHash(obj,id_req_s);
            
            id                          = -1*ones(nr_func,length(thislastcommon) + obj.hashlength);
            prevhash                    = CalcMD5(id_req_s(:,(end-obj.hashlength+1):end),'char','Dec');
            prehash(2*n_fields+3,:,:)   = repmat(prevhash.',1,nr_func);
            

            for uu=1:nr_func
                id(uu,:) = [thislastcommon CalcMD5(prehash(:,:,uu),'char','Dec')];
            end
        elseif stepnr == functionalStartAt
            if stepnr > 1
                assert(size(id_req_s,1) == 1);
            else
                assert(size(id_req_s,1) == 0);
            end
            
            id                              = -1*ones(nr_func,size(id_req_s,2)+16);
            
            if stepnr > 1
                prevhash                    = id_req_s(:,(end-obj.hashlength+1):end);
                prehash(2*n_fields+3,:,:)   = repmat(prevhash.',1,nr_func);
            end
            
            for uu=1:nr_func
                id(uu,:) = [id_req_s CalcMD5(prehash(:,:,uu),'char','Dec')];
            end
        else
            assert(size(id_req_s,1) == nr_func);
            
            % We simply need to calculate as many hashes as there
            % were provided.
            id  = zeros(size(id_req_s,1),size(id_req_s,2)+16);

            for uu=1:size(id_req_s,1)
                prehash(2*n_fields+3,:,uu)     = id_req_s(uu,((end-(obj.hashlength-1)):end));
                id(uu,:)                       = [id_req_s(uu,:) CalcMD5(prehash(:,:,uu),'char','Dec')];
            end
        end
        
    elseif betweenDecisions
        
        assert(~(size(id_req_s,1) > 1 && stepnr == decisionStartAt(atDecision)));
        assert(nr_func == 1);
        
        fld_nr = [];
        
        for oo=1:length(s_fields)
            if iscell(z_step.(s_fields{oo}))
                if ~strcmp(s_fields{oo},decisionDecidesOver{atDecision})
                    error('huh?')
                end
                
                if ~iscolumn(z_step.(s_fields{oo}))
                    error('The function field %s should be specified as a column vector of cells.',s_fields{oo});
                end
                
                if isfield(obj.fnchashcache,s_fields{oo})
                    fnchash     = obj.fnchashcache.(s_fields{oo});
                    fld_nr = oo;
                else
                    error('The function hash cache is missing for %s.',s_fields{oo});
                end
            else
                prehash(2*oo,:,:) = repmat(CalcMD5(z_step.(s_fields{oo}),'char','Dec').',1,nr_func);
            end
            prehash(2*oo-1,:,:) = repmat(CalcMD5(s_fields{oo},'char','Dec').',1,nr_func);
        end

        if ~t_step.type % decision
            
            prevhash                    = id_req_s(:,(end-obj.hashlength+1):end);
            prehash(2*n_fields+3,:)     = CalcMD5(prevhash,'char','Dec');
            id                          = [lastCommonHash(obj,id_req_s) CalcMD5(prehash,'char','Dec')];
            
        else            
            if stepnr == decisionStartAt(atDecision)
                if stepnr > 1
%                     prehash(2*n_fields+3,:,:) = repmat(id_req_s((end-(obj.hashlength-1)):end).',1,nr_func);
%                 else
                    prehash(2*n_fields+3,:,:) = repmat(id_req_s((end-(obj.hashlength-1)):end).',1,nr_func);
                end
                
                id  = zeros(length(z_step.(decisionDecidesOver{atDecision})),size(id_req_s,2)+16);
                
                for uu=1:size(id,1)
                    prehash(2*fld_nr,:,:)   = repmat(fnchash(uu,:),1,nr_func);
                    id(uu,:)                = [id_req_s CalcMD5(prehash,'char','Dec')];
                end
            else
                id  = zeros(size(id_req_s,1),size(id_req_s,2)+16);
                for uu=1:size(id,1)
                    prehash(2*n_fields+3,:)     = id_req_s(uu,(end-obj.hashlength+1):end);
                    id(uu,:)                    = [id_req_s(uu,:) CalcMD5(prehash,'char','Dec')];
                end
            end
        end
        
    else
        if size(id_req_s,1) > 1
            error('huh?!')
        end
        
        for oo=1:length(s_fields)
            prehash(2*oo  ,:) = CalcMD5(z_step.(s_fields{oo}),'char','Dec');
            prehash(2*oo-1,:) = CalcMD5(s_fields{oo},'char','Dec');
        end

        if ~t_step.type % decision
            error('huh?!');
        else
            if stepnr > 1
                prehash(2*n_fields+3,:)    = id_req_s((end-(obj.hashlength-1)):end);
            end
            
            id = [id_req_s CalcMD5(prehash,'char','Dec')];    
        end
    end
    
    if mod(size(id,2),obj.hashlength) ~= 0
        error('boo!')
    end
end