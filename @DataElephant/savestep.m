function savestep(obj,step,removeFromMemory)
                
    if obj.save_hdd == 0
        return;
    end
    
    if obj.steps(step).type
        idx_data     = find(obj.new == 1 & obj.saveme & obj.bystep == step);

        if obj.fileverbose
            fprintf('%sGoing to save %i results for step %i.\n',sprintf(repmat('\t',1,step)),length(idx_data),step);
        end
            
        if ~isempty(idx_data)

            % Because we are saving for each step separately, we can assume
            % that the hashes all have the same length. However, they might
            % not have the same prefix hash.
            allhashes       = cell2mat(obj.hash(idx_data).');
            prefixhash      = unique(allhashes(:,1:(end-obj.hashlength)),'rows');
            % Here is a possible problem: the prefixhash should be an
            % integer multiple of the hashlength. Right now there is no way
            % of knowing.
            
            if mod(size(prefixhash,2),obj.hashlength) ~= 0
                error('ha, see! it can happen! the line below should be the proper fix, right?');
            end
            
            prefixhash  = prefixhash(:,1:(floor(size(prefixhash,2)/obj.hashlength)*obj.hashlength));
            
            if isempty(prefixhash)
                
                    savestepbyidx(obj,[obj.getRootFolder() '/' obj.steps(step).name '_' num2str(obj.steps(step).version)],                                                      idx_data);
                
            elseif size(prefixhash,1) == 1
                
                    savestepbyidx(obj,[obj.getRootFolder() '/' obj.steps(step).name '_' num2str(obj.steps(step).version) '/' hexhash(obj,prefixhash)],                          idx_data);
                
            elseif size(prefixhash,1) == length(idx_data)
                
                for ii=1:length(idx_data)
                    
                    savestepbyidx(obj,[obj.getRootFolder() '/' obj.steps(step).name '_' num2str(obj.steps(step).version) '/'  hexhash(obj,allhashes(ii,1:(end-obj.hashlength)))],idx_data(ii));
                    
                end
                
            else
                error('didn''t think of this, huh?!');
            end
            obj.new(idx_data)   = false;
        end

        if removeFromMemory && obj.savememory
            idx_data                            = find(~obj.keepme & obj.bystep == step & ~obj.new);
            
            if obj.fileverbose
                fprintf('%sGoing to remove %i results from memory %i.\n',sprintf(repmat('\t',1,step)),length(idx_data),step);
            end
            
            obj.hash(idx_data)                  = [];
            obj.shorthash(idx_data,:)           = [];
            obj.time(idx_data)                  = [];
            obj.data(idx_data)                  = [];
            obj.new(idx_data)                   = [];
            obj.saveme(idx_data)                = [];
            obj.bystep(idx_data)                = [];
            obj.keepme(idx_data)                = [];
            obj.kk                              = length(obj.new) + 1;
        end
        
    else % decision
        idx_data        = find(obj.dec_new == 1 & obj.dec_saveme & obj.dec_bystep == step & obj.dec_hashash);
        idx_data_short  = find(obj.dec_new == 1 & obj.dec_saveme & obj.dec_bystep == step & obj.dec_hasfasthash);
        
        if ~isempty(idx_data_short)            
            if obj.fileverbose
                fprintf('%sGoing to save %i fast decision hashes.',sprintf(repmat('\t',1,step),length(idx_data_short)));
            end
            
            for oo=1:length(idx_data_short)
                N               = obj.dec_fasthash(idx_data_short(oo),:);
                D               = obj.dec_data(idx_data_short(oo));
                fldr = [obj.getRootFolder() '/' obj.steps(step).name '_' num2str(obj.steps(step).version) '/_FAST'];
                savedecisionto(obj,fldr,D,N);
            end
        end
        
        if ~isempty(idx_data)

            if obj.fileverbose
                fprintf('%sGoing to save %i decision hashes.',sprintf(repmat('\t',1,step),length(idx_data)));
            end
            
            prefixhash      = obj.dec_hash{idx_data(1)}(1:(end-obj.hashlength));
            N               = obj.dec_shorthash(idx_data,:);
            D               = obj.dec_data(idx_data);

            if ~isempty(prefixhash)
                fldr = [obj.getRootFolder() '/' obj.steps(step).name '_' num2str(obj.steps(step).version) '/' hexhash(obj,prefixhash)];
            else
                fldr = [obj.getRootFolder() '/' obj.steps(step).name '_' num2str(obj.steps(step).version)];
            end
            
            savedecisionto(obj,fldr,D,N);

            obj.dec_new(idx_data)   = false;
        end
        
        if removeFromMemory && obj.savememory
            idx_data                                = find(~obj.dec_keepme & obj.dec_bystep == step & ~obj.dec_new);
            obj.dec_hash(idx_data)                  = [];
            obj.dec_shorthash(idx_data,:)           = [];
            obj.dec_time(idx_data)                  = [];
            obj.dec_data(idx_data)                  = [];
            obj.dec_new(idx_data)                   = [];
            obj.dec_saveme(idx_data)                = [];
            obj.dec_bystep(idx_data)                = [];
            obj.dec_keepme(idx_data)                = [];
            obj.uuu                                 = length(obj.dec_new) + 1;
        end
    end
end