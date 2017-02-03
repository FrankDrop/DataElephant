function savestepbyidx(obj,fldr,idx)

    getLock(obj,fldr,true);     % Get a lock on the folder we are going to write to.
    
    if ~exist(fldr,'dir')
        try
            mkdir(fldr);
        catch ee
            fprintf('Error creating folder %s.\n',fldr);
            rethrow(ee);
        end
        if obj.fileverbose
            fprintf('Created directory %s.\n',fldr);
        end
    end

    D_files   = dir([fldr '/D_*.mat']);
    N_files   = dir([fldr '/N_*.mat']);
    
    if isempty(D_files) && isempty(N_files)
        fileIndex   = 1;
    else
        fileIndex   = max([length(D_files) length(N_files)])+1;
    end
    
    itemsPerFile    = 1e4;
    startAt         = 1;
    
    if length(idx) > itemsPerFile
        itemsPerFile    = round(length(idx) / round(length(idx) / itemsPerFile));
    end
    
    while startAt <= length(idx)
    
        fn_D    = [fldr '/' sprintf('D_%010i.mat',fileIndex)];
        fn_N    = [fldr '/' sprintf('N_%010i.mat',fileIndex)];
        
        getLock(obj,fn_D,true);
        getLock(obj,fn_N,true);

        if exist(fn_D,'file')
            error('boo!');
        end
        
        itemsToSave     = min([itemsPerFile length(idx)-startAt]);
        
        if obj.fileverbose
            fprintf('Saving %i till %i.\n',idx(startAt),idx(startAt+itemsToSave))
        end
        
        savestepsave(obj,fn_D,obj.data(idx(startAt:(startAt+itemsToSave))));
        savestepsave(obj,fn_N,obj.shorthash(idx(startAt:(startAt+itemsToSave)),:));
        
        startAt     = startAt + itemsToSave + 1;
        
        releaseLock(obj,fn_D,true);
        releaseLock(obj,fn_N,true);
        
        fileIndex   = fileIndex + 1;
    end
    releaseLock(obj,fldr,true);
end