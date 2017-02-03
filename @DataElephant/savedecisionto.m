function savedecisionto(obj,fldr,D,N)

    getLock(obj,fldr,true);     % Get a lock on the folder we are going to write to.
    
    if ~exist(fldr,'dir')
        try
            mkdir(fldr);
            
            if obj.fileverbose
                fprintf('Created directory %s.\n',fldr);
            end
        catch ee
            fprintf('Error creating folder %s.\n',fldr);
            rethrow(ee);
        end
    end
    
    for oo=1:size(N,1)
        hxhsh               = hexhash(obj,N(oo,:));
        fn_D                = [fldr '/' hxhsh '.mat'];
        H.(['H_' hxhsh])    = D(oo);
        
        if obj.fileverbose
            fprintf('Saving a decision to %s.\n',fn_D);
        end
        
        getLock(obj,fn_D,true);
        savedecisionsave(obj,fn_D,H);
        releaseLock(obj,fn_D,true);
    end
    
    releaseLock(obj,fldr,true);

end