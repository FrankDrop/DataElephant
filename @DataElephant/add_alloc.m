function obj = add_alloc(obj,N,step)

    N   = N - 1;
    
    if obj.steps(step).type
        obj.data(obj.kk+N).z                            = [];
        obj.data(obj.kk+N).r_n                          = [];
        obj.hash{obj.kk+N}                              = [];
        obj.shorthash(obj.kk+N,obj.hashlength)          = uint8(0);
        obj.new(obj.kk+N)                               = false;
        obj.saveme(obj.kk+N)                            = false;
        obj.time(obj.kk+N)                              = 0;
        obj.bystep(obj.kk+N)                            = 0;
        obj.keepme(obj.kk+N)                            = false;
    else
        obj.dec_data(obj.uuu+N).z                       = [];
        obj.dec_data(obj.uuu+N).decision                = [];
        obj.dec_hash{obj.uuu+N}                         = [];
        obj.dec_hashash(obj.uuu+N)                      = false;
        obj.dec_shorthash(obj.uuu+N,obj.hashlength)     = uint8(0);
        obj.dec_fasthash(obj.uuu+N,obj.hashlength)      = uint8(0);
        obj.dec_hasfasthash(obj.uuu+N)                  = false;
        obj.dec_new(obj.uuu+N)                          = false;
        obj.dec_saveme(obj.uuu+N)                       = false;
        obj.dec_time(obj.uuu+N)                         = 0;
        obj.dec_bystep(obj.uuu+N)                       = 0;
        obj.dec_keepme(obj.uuu+N)                       = false;
    end

end