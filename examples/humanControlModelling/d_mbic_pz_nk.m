function step = d_mbic_pz_nk()

    step.name       = mfilename;
    step.type       = 'decision';
    step.decide     = 'NN';
    step.basedon    = {'epsilon_arx','k_arx','N_arx','p_arx','z_arx'};
    step.input      = {'c','pmax','zmax'};
    step.optional   = {};
	step.output     = {};
    step.handle     = @myfunc;
    step.version    = 1;
    step.saveme     = 1;
    step.memorizeme = 1;

    function idx = myfunc(z,r,~,~)
        
        nr_i    = length(r.z_arx{1});
        assert(length(z.zmax) == nr_i,'You need to provide as many maximum zero values as input channels.');
        assert(length(z.NN) == length(r.z_arx));
        assert(length(z.NN) == length(r.p_arx));

        nnn = 2:((length(z.NN{1})+1)/2);
            
        if ~isinf(z.pmax)
            for oo=1:length(r.p_arx)
                if any(r.p_arx{oo}{1} > z.pmax)
                    r.epsilon_arx{oo}     = 1e3;
                end
                
                r.k_arx{oo} = r.k_arx{oo} + sum(z.NN{oo}(nnn) > 0);
            end
        else
            for oo=1:length(r.p_arx)
                r.k_arx{oo} = r.k_arx{oo} + sum(z.NN{oo}(nnn) > 0);
            end
        end
        
        for ii=1:nr_i
            if ~isinf(z.zmax(ii))
                for oo=1:length(r.z_arx)
                    nonInfZeros     = r.z_arx{oo}{ii};
                    nonInfZeros     = nonInfZeros(~isinf(nonInfZeros));
                    if any(nonInfZeros > z.zmax(ii))
                        r.epsilon_arx{oo}     = 1e3;
                    end
                end
            end
        end
                
        epsilon_arx     = [r.epsilon_arx{:}];
        k_arx           = [r.k_arx{:}];
        N_arx           = r.N_arx;

        mbic        = log(epsilon_arx) + z.c .* k_arx .* log(N_arx) ./ N_arx;
        [~,idx]     = min(mbic);
    end
end