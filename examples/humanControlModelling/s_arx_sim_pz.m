function step = s_arx_sim_pz()

    step.name       = mfilename;
    step.type       = 'step';
    step.input      = {'NN'};
    step.optional   = {};
	step.output     = {'epsilon_arx','k_arx','p_arx','z_arx','A_arx','B_arx','VAF_arx'};
    step.handle     = @myfunc;
    step.version    = 6;
    step.saveme     = 1;
    step.memorizeme = 1;

    function [r_n] = myfunc(z,r,~,~)
        
        nr_i        = size(r.i_arx,2);
        nr_o        = size(r.o_arx,2);
        
        if size(z.NN,1) ~= 1 || size(z.NN,2) ~= (1 + 2*nr_i)
            error('The size of z.NN should be [%i, %i], but it is [%s].',1,(1 + 2*nr_i),num2str(size(z.NN)));
        end
        
        if nr_o ~= 1
            error('This function does not support multi output systems.')
        end
        
        na          = z.NN(1);
        nb          = z.NN(2:(1+nr_i));
        nk          = z.NN((2+nr_i):end);

        [A,B]       = Farx(r.o_arx(r.fiton_arx,:),...
                           r.i_arx(r.fiton_arx,:),...
                           na,nb,nk);

        nmax        = max([na nb]);
        namax       = max(na);

        ssA         = zeros(nmax,nmax);
        ssB         = zeros(nmax,nr_i);
        ssC         = zeros(1,nmax);
        ssD         = zeros(1,nr_i);

        A           = -1*fliplr(A{1});
            
        if nmax > 1
            ssA(2:end,1:(end-1)) = eye(nmax-1);
        end
        ssA((end-namax+1):end,end) = A(1:(end-1));

        Ts              = r.t_arx(2) - r.t_arx(1);

        for ii=1:nr_i
            b   = B{1,ii};
            b   = fliplr(b((nk(ii)+1):end));
            ssB((end-length(b)+1):end,ii)   = b';
        end

        ssC(end)        = 1;

        nk(nb == 0)     = 1;
        
        if any(isinf(ssA(:))) || any(isnan(ssA(:))) || ...
           any(isinf(ssB(:))) || any(isnan(ssB(:))) || ...
           any(isinf(ssC(:))) || any(isnan(ssC(:))) || ...
           any(isinf(ssD(:))) || any(isnan(ssD(:)))
        
            r_n.epsilon_arx   = 1e3;
            r_n.k_arx         = na+sum(nb);
        else

            nk_act                  = nk -1;
            i_del                   = zeros(size(r.i_arx));
            for uu=1:nr_i
                i_del((nk_act(uu)+1):end,uu) = r.i_arx(1:(end-nk_act(uu)),uu);
            end
            u_sim  = ltitr(ssA,ssB,i_del) * ssC.' + i_del * ssD.';
            u_sim  = u_sim(r.evalon_arx);
            
            r_n.p_arx     = {abs(log(roots(-1*fliplr(A)))/Ts)};
            r_n.z_arx     = cell(nr_i,1);
            for ii=1:nr_i
                r_n.z_arx{ii} = abs(log(roots(B{1,ii}))/Ts);
            end
            
            e       = u_sim - r.o_arx(r.evalon_arx);
            e_sim   = (1 / length(e)) * (e).' * e;

            r_n.epsilon_arx   = e_sim;
            r_n.k_arx         = na+sum(nb);
            r_n.A_arx         = {A};
            r_n.B_arx         = B;
            r_n.VAF_arx       = 100 * (1 - (e.' * e) / ( r.o_arx(r.evalon_arx).' * r.o_arx(r.evalon_arx)));
        end
    end
end
