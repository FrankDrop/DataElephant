function id = generateFasthash(obj,z_cum,stepnr)

    s_fields    = fieldnames(z_cum);
    n_fields    = length(s_fields);
    prehash     = -1*ones(2*n_fields+2*stepnr,16);

    for oo=1:stepnr
        prehash(2*n_fields+2*oo-1,:)    = CalcMD5(obj.steps(oo).name,'char','Dec');
        prehash(2*n_fields+2*oo,:)      = CalcMD5(obj.steps(oo).version,'char','Dec');
    end
 
    for oo=1:n_fields
        prehash(2*oo-1,:)         = CalcMD5(s_fields{oo},'char','Dec');
        
        if iscell(z_cum.(s_fields{oo}))
            assert(iscolumn(z_cum.(s_fields{oo})));
%             assert(isnumeric(z_cum.(s_fields{oo}){1}));
            assert(isfield(obj.fastfnchashcache,s_fields{oo}));
            
            prehash(2*oo,:)       = CalcMD5(obj.fastfnchashcache.(s_fields{oo}),'char','Dec');
        else
            prehash(2*oo,:)       = CalcMD5(z_cum.(s_fields{oo}),'char','Dec');
        end
    end
    
    if any(prehash(:) == -1)
        error('big error');
    end
    id = CalcMD5(prehash,'char','Dec');
end