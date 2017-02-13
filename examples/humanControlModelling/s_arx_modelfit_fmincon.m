function step = s_arx_modelfit_fmincon()

    step.name       = mfilename;
    step.type       = 'step';
    step.input      = {};
    step.optional   = {};
	step.output     = {'fmincon_x','fmincon_V'};
    step.handle     = @myfunc;
    step.version    = 4;
    step.saveme     = 1;
    step.memorizeme = 1;
    
    function [r_n] = myfunc(z,r,verbose,~)
        
        if size(z.model_fit_lb,1) > size(z.model_fit_lb,2)
            error('lowerBound should be a row vector!');
        end

        if size(z.model_fit_ub,1) > size(z.model_fit_ub,2)
            error('upperBound should be a row vector!');
        end

        if size(z.model_fit_ub,2) ~= size(z.model_fit_lb,2)
            error('The lower and upper bounds have a different size.');
        end
        
        if size(z.model_fit_ub,2) ~= length(r.model_p.y.pilotParameterNames)
            error('The bounds should match the number of pilot parameters in the model.');
        end
        
        resp            = h_create_arx_model_response_functions(r,z.model_fit_response,z.iSignals);
        Y_arx_best_tf   = r.Y_arx_best_tf.y{1};
        
        Y_arx = zeros(length(z.w_model_fit),length(resp));
        for oo=1:length(resp)
            Y_arx(:,oo)     = squeeze(freqresp(Y_arx_best_tf(oo),z.w_model_fit));
        end
        
        if verbose
            figure
            for oo=1:length(resp)
                subplot(2,1,1);
                    loglog(z.w_model_fit,abs(Y_arx(:,oo)),'r'); hold on
                subplot(2,1,2);
                    semilogx(z.w_model_fit,180/pi*unwrap(angle(Y_arx(:,oo))),'r'); hold on
            end
            display = 'iter';
        else
            display = 'none';
        end
        
        fun                     = @(x) h_arx_model_cost(Y_arx, resp, x, z.w_model_fit, z.model_fit_lb, z.model_fit_ub);
        fmc_options             = optimset('Display',display,'Algorithm','active-set');
        [fmincon_x,fmincon_V]   = fmincon(fun,r.ga_x.y,[],[],[],[],z.model_fit_lb,z.model_fit_ub,[],fmc_options);
        
        [~,Yhat]    = fun(fmincon_x);
        
        if verbose
            for oo=1:length(resp);
                subplot(2,1,1);
                    loglog(z.w_model_fit,abs(Yhat(:,oo)),'b--'); hold on
                subplot(2,1,2);
                    semilogx(z.w_model_fit,180/pi*unwrap(angle(Yhat(:,oo))),'b--'); hold on
            end
        end
        
        r_n.fmincon_x.y      = fmincon_x;
        r_n.fmincon_V.y      = fmincon_V;
    end
    
    
end