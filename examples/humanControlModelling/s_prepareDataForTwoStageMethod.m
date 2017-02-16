function step = s_prepareDataForTwoStageMethod()

    step.name       = mfilename;
    step.type       = 'step';
    step.input      = {'iSignals1','oSignals1','iSignals','oSignals','si','fit_from','fit_to','eval_from','eval_to','tau_iSignals1','tau_iSignals','filter_o1','filter_o','NN1'};
    step.optional   = {};
	step.output     = {'t_arx','t_arx_i','t_arx;o_arx','t_arx_i;i_arx','evalon_arx','fiton_arx','N_arx'};
    step.handle     = @myfunc;
    step.version    = 1;
    step.saveme     = 1;
    step.memorizeme = 1;

    function [r_n] = myfunc(z,r,~,~)
                
        inputSignalNames1   = regexp(z.iSignals1,',','split');
        outputSignalNames1  = regexp(z.oSignals1,',','split');
        
        inputSignalNames2   = regexp(z.iSignals,',','split');
        outputSignalNames2  = regexp(z.oSignals,',','split');
        
        i_m_1   = zeros(length(r.t),length(inputSignalNames1));
        o_m_1   = zeros(length(r.t),length(outputSignalNames1));
        
        i_m_2   = zeros(length(r.t),length(inputSignalNames2));
        o_m_2   = zeros(length(r.t),length(outputSignalNames2));
        
        if size(z.tau_iSignals1,2) ~= length(inputSignalNames1)
            error('Input tau_iSignals1 should have size [1, %i].',length(inputSignalNames1));
        end
        
        if size(z.tau_iSignals,2) ~= length(inputSignalNames2)
            error('Input tau_iSignals2 should have size [1, %i].',length(inputSignalNames2));
        end
        
        
        for oo=1:length(inputSignalNames1)
            if oo == 1
                t_m         = r.t_m;
            end
            i_m_1(:,oo)     = circshift(r.(inputSignalNames1{oo}),z.tau_iSignals1(oo));
        end
        
        for oo=1:length(inputSignalNames2)
            if ~strcmp('*',inputSignalNames2{oo})
                i_m_2(:,oo)     = circshift(r.(inputSignalNames2{oo}),z.tau_iSignals(oo));
            end
        end
        
        for oo=1:length(outputSignalNames1)
            o_m_1(:,oo) = r.(outputSignalNames1{oo});
        end
        
        for oo=1:length(outputSignalNames2)
            o_m_2(:,oo) = r.(outputSignalNames2{oo});
        end
        
        fiton   = z.fit_from:z.fit_to;
        evalon  = z.eval_from:z.eval_to;
        
        if z.si > 1
            i_m_rs_1 = zeros(length(1:z.si:size(i_m_1,1)),length(inputSignalNames1));
            o_m_rs_1 = zeros(length(1:z.si:size(o_m_1,1)),length(outputSignalNames1));
            i_m_rs_2 = zeros(length(1:z.si:size(i_m_2,1)),length(inputSignalNames2));
            o_m_rs_2 = zeros(length(1:z.si:size(o_m_2,1)),length(outputSignalNames2));

            for oo=1:length(inputSignalNames1)
                [t_m_rs,i_m_rs_1(:,oo)] = FResample(t_m,i_m_1(:,oo),z.si,z.si);
            end
            
            for oo=1:length(inputSignalNames2)
                [~,i_m_rs_2(:,oo)] = FResample(t_m,i_m_2(:,oo),z.si,z.si);
            end
            
            for oo=1:length(outputSignalNames1)
                [~,o_m_rs_1(:,oo)] = FResample(t_m,o_m_1(:,oo),z.si,z.filter_o1(oo));
            end
            
            for oo=1:length(outputSignalNames2)
                [~,o_m_rs_2(:,oo)] = FResample(t_m,o_m_2(:,oo),z.si,z.filter_o(oo));
            end

            fiton_rs  = unique(floor((fiton-1)/z.si)+1);
            evalon_rs = unique(floor((evalon-1)/z.si)+1);
        else
            i_m_rs_1 = i_m_1;
            o_m_rs_1 = o_m_1;
            i_m_rs_2 = i_m_2;
            o_m_rs_2 = o_m_2;
            
            fiton_rs  = fiton;
            evalon_rs = evalon;
        end
        
        Ts          = t_m_rs(2) - t_m_rs(1);        
        d           = iddata(o_m_rs_1,i_m_rs_1,Ts);
        sys_1       = arx(d,z.NN1);
        o_m_rs1_r   = lsim(sys_1,i_m_rs_1,t_m_rs);
        
        for oo=1:length(inputSignalNames2)
            if strcmp('*',inputSignalNames2{oo})
                i_m_rs_2(:,oo) = circshift(o_m_rs1_r,z.tau_iSignals(oo));
            end
        end
        
        r_n.t_arx         = t_m_rs;
        r_n.t_arx_i       = [t_m_rs t_m_rs];
        r_n.i_arx         = i_m_rs_2;
        r_n.o_arx         = o_m_rs_2;
        r_n.fiton_arx     = fiton_rs;
        r_n.evalon_arx    = evalon_rs;
        r_n.N_arx         = length(fiton_rs);
    end
    function [t,y] = FResample(t,x,si,filt)

        % define n_points?
        n_points = length(x);

        % define sampling frequency
        fs   = 1/(t(2)-t(1));
        t_id = n_points/fs;
        N_id = n_points;

        % block filter the data
        % perform fourier transform
        xf = fft(x);

        % set amplitudes to zero
        xf(round(fs/2/filt*t_id+1):round(N_id-fs/2/filt*t_id)) = 0;

        % transform back
        xs = ifft(xf,'symmetric');

    %     plot(t,xs,'g'); hold on
        % resample the data
        t = t(1:si:end);
        y = xs(1:si:end);
    end
end