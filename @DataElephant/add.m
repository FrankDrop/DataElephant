function added = add(obj,hash,fasthash,z,r_n,decision,n,time,step,lastStepInSequence,saveme)

    obj.getTime     = obj.getTime + time;

    if ~isempty(decision)
        obj.dec_data(obj.uuu).z         = z;
        obj.dec_data(obj.uuu).decision  = decision;        
            
        obj.dec_new(obj.uuu)            = n;
        obj.dec_saveme(obj.uuu)         = saveme;
        obj.dec_time(obj.uuu)           = time;
        obj.dec_bystep(obj.uuu)         = step;
        obj.dec_keepme(obj.uuu)         = true;
        
        if ~isempty(fasthash)
            obj.dec_fasthash(obj.uuu,:)     = uint8(fasthash);
            obj.dec_hasfasthash(obj.uuu)    = true;
        else
            obj.dec_fasthash(obj.uuu,:)     = zeros(1,obj.hashlength,'uint8');
            obj.dec_hasfasthash(obj.uuu)    = false;
        end
        
        % The hash has to be added last, to make sure the revertAlloc
        % function works properly.
        if ~isempty(hash)
            obj.dec_hashash(obj.uuu)        = true;
            obj.dec_shorthash(obj.uuu,:)    = uint8(hash((end-(obj.hashlength-1)):end));
            obj.dec_hash{obj.uuu}           = uint8(hash);
        else
            obj.dec_hashash(obj.uuu)        = false;
            obj.dec_shorthash(obj.uuu,:)    = zeros(1,obj.hashlength,'uint8');
            obj.dec_hash{obj.uuu}           = zeros(1,obj.hashlength,'uint8');
        end
        obj.uuu                         = obj.uuu + 1;
        added                           = true;
    else
        if ~obj.savememory || n || (step == lastStepInSequence && obj.addfinalstep)
            
            obj.data(obj.kk).z              = z;
            obj.data(obj.kk).r_n            = r_n;
            obj.shorthash(obj.kk,:)         = uint8(hash((end-(obj.hashlength-1)):end));
            obj.new(obj.kk)                 = n;
            obj.saveme(obj.kk)              = saveme;
            obj.time(obj.kk)                = time;
            obj.bystep(obj.kk)              = step;
            obj.keepme(obj.kk)              = step == lastStepInSequence;
            
            % The hash has to be added last, to make sure the revertAlloc
            % function works properly.
            obj.hash{obj.kk}                = uint8(hash);
            obj.kk                          = obj.kk + 1;
            added                           = true;
        else
            added                           = false;
        end
    end
end