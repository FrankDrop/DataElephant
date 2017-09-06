function obj = uniqueHashes(obj,silent)

    if ~isempty(obj.shorthash)
        uniqueHashNr    = size(unique(obj.shorthash,'rows'),1);
        hashNr          = size(obj.shorthash,1);
        if uniqueHashNr ~= hashNr
            error('We have a problem... There are %i unique hashes, and %i hashes in total.',uniqueHashNr,hashNr);
        else
            if obj.verbose && ~silent
                fprintf('Checked for duplicate hashes. Didn''t find any. Why? %s\n',Fwhy);
            end
        end
    end
    
    if ~isempty(obj.dec_shorthash)
        uniqueHashNr    = size(unique(obj.dec_shorthash(obj.dec_hashash == 1,:),'rows'),1);
        hashNr          = sum(obj.dec_hashash);
        
        if uniqueHashNr ~= hashNr
            error('We have a problem... There are %i unique decision hashes, and %i decision hashes in total.',uniqueHashNr,hashNr);
        else
            if obj.verbose && ~silent
                fprintf('Checked for duplicate decision hashes. Didn''t find any. Why? %s\n',Fwhy);
            end
        end
    end
    
    if ~isempty(obj.dec_fasthash)
        uniqueHashNr    = size(unique(obj.dec_fasthash(obj.dec_hasfasthash == 1,:),'rows'),1);
        hashNr          = sum(obj.dec_hasfasthash);
        
        if uniqueHashNr ~= hashNr
            error('We have a problem... There are %i unique fast decision hashes, and %i fast decision hashes in total.',uniqueHashNr,hashNr);
        else
            if obj.verbose && ~silent
                fprintf('Checked for duplicate fast decision hashes. Didn''t find any. Why? %s\n',Fwhy);
            end
        end
    end
end