function savestepto(obj,fldr,D,N)

    getLock(obj,fldr,true);     % Get a lock on the folder we are going to write to.
    
    if ~exist(fldr,'dir')
        try
            mkdir(fldr);
        catch ee
            fprintf('Error creating folder %s.\n',fldr);
            rethrow(ee);
        end
        if obj.verbose
            fprintf('Created directory %s.\n',fldr);
        end
    end

    D_files   = dir([fldr '\D_*.mat']);
    N_files   = dir([fldr '\N_*.mat']);
    
    if isempty(D_files) && isempty(N_files)
        fileIndex   = 1;
    else
        fileIndex   = max([length(D_files) length(N_files)])+1;
    end
    
    itemsPerFile    = 1e5;
    
    if length(D) > itemsPerFile
        itemsPerFile    = round(length(D) / round(length(D) / itemsPerFile));
    end
    
    while ~isempty(D)
    
        fn_D    = [fldr '/' sprintf('D_%010i.mat',fileIndex)];
        fn_N    = [fldr '/' sprintf('N_%010i.mat',fileIndex)];
        
        getLock(obj,fn_D,true);
        getLock(obj,fn_N,true);

        if exist(fn_D,'file')
            error('boo!');
        end
        
        itemsToSave     = min([itemsPerFile length(D)]);
        
        savestepsave(obj,fn_D,D(1:itemsToSave));
        savestepsave(obj,fn_N,N(1:itemsToSave,:));
        
        D(1:itemsToSave)   = [];
        N(1:itemsToSave,:) = [];
        
        releaseLock(obj,fn_D,true);
        releaseLock(obj,fn_N,true);
        
        fileIndex   = fileIndex + 1;
    end
    releaseLock(obj,fldr,true);
end