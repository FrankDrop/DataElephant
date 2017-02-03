function obj = revertAlloc(obj)
    
    if iscell(obj.dec_hash)
        emptyDec                        = cellfun(@(x)isempty(x),obj.dec_hash);
        obj.dec_data(emptyDec)          = [];    
        obj.dec_hash(emptyDec)          = [];
        obj.dec_hashash(emptyDec)       = [];
        obj.dec_shorthash(emptyDec,:)   = [];
        obj.dec_fasthash(emptyDec,:)    = [];
        obj.dec_hasfasthash(emptyDec)   = [];
        obj.dec_new(emptyDec)           = [];
        obj.dec_saveme(emptyDec)        = [];
        obj.dec_time(emptyDec)          = [];
        obj.dec_bystep(emptyDec)        = [];
        obj.dec_keepme(emptyDec)        = [];
    end
    
    if iscell(obj.hash)
        emptyStep                       = cellfun(@(x)isempty(x),obj.hash);
        
        if obj.fileverbose
            fprintf('Reverting the allocation of memory. Deleting %i items out of %i in total.\n',length(find(emptyStep)),length(obj.hash));
        end
        
        obj.data(emptyStep)             = [];
        obj.hash(emptyStep)             = [];
        obj.shorthash(emptyStep,:)      = [];
        obj.new(emptyStep)              = [];
        obj.saveme(emptyStep)           = [];
        obj.time(emptyStep)             = [];
        obj.bystep(emptyStep)           = [];
        obj.keepme(emptyStep)           = [];
    end
end