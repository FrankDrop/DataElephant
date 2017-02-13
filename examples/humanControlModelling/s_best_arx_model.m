function step = s_best_arx_model()

    step.name       = mfilename;
    step.type       = 'step';
    step.input      = {};
    step.optional   = {};
	step.output     = {'Y_arx_best_ss','Y_arx_best_tf','nn_arx_best','u_arx_sim','u_arx_sim_part','Y_arx_best_idpoly'};
    step.handle     = @myfunc;
    step.version    = 9;
    step.saveme     = 1;
    step.memorizeme = 1;

    function [r_n] = myfunc(z,r,verbose,~)
        
        if ~isfield(z,'tau_iSignals')
            inputSignalNames    = regexp(z.iSignals,',','split');
            z.tau_iSignals      = zeros(1,length(inputSignalNames));
        end
        
        if verbose
            fprintf('I am executed!\n');
        end
        
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

        for ii=1:nr_i
            b   = B{1,ii};
            b   = fliplr(b((nk(ii)+1):end));
            ssB((end-length(b)+1):end,ii)   = b';
        end

        ssC(end)    = 1;

        nk(nb == 0) = 1;
        
        Ts      = r.t_arx(2) - r.t_arx(1);
        Y       = ss(ssA,ssB,ssC,ssD,'Ts',Ts,'InputDelay',nk-1);
        
        % Also use the standard MATLAB arx command to be sure we are
        % correct.
        i_data              = iddata(r.o_arx(r.fiton_arx,:),...
                                     r.i_arx(r.fiton_arx,:),Ts);
        Y_arx_best_idpoly   = arx(i_data,z.NN);
        
        
        
        Y.UserData.tau_iSignals                     = z.tau_iSignals * (r.t(2)-r.t(1));
        Y_arx_best_idpoly.UserData.tau_iSignals     = z.tau_iSignals * (r.t(2)-r.t(1));
        
        u_sim   = lsim(Y, r.i_arx, r.t_arx);
        
        r_n.u_arx_sim             = u_sim;
        
        for oo=1:nr_i
            r_n.u_arx_sim_part(:,oo)  = lsim(Y_arx_best_idpoly(oo), r.i_arx(:,oo), r.t_arx);
        end
        
        r_n.Y_arx_best_ss         = {Y};
        r_n.Y_arx_best_tf         = {tf(Y)};
        r_n.nn_arx_best           = z.NN;
        r_n.Y_arx_best_idpoly     = {Y_arx_best_idpoly};
    end
end