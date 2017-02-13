function step = s_arx_modelfit_ga()

    step.name       = mfilename;
    step.type       = 'step';
    step.input      = {'ga_populationSize','ga_generations','ga_fitnessLimit','ga_nr','model_fit_response','w_model_fit','model_fit_lb','model_fit_ub'};
    step.optional   = {};
	step.output     = {'ga_x','ga_V'};
    step.handle     = @myfunc;
    step.version    = 7;
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
        
        if size(z.model_fit_ub,2) ~= length(r.model_p.pilotParameterNames)
            error('The bounds should match the number of pilot parameters in the model.');
        end
        
        resp            = h_create_arx_model_response_functions(r,z.model_fit_response,z.iSignals);
        
        if verbose
            inputSignalNames    = regexp(z.iSignals,',','split');
            ga_fit_responses    = regexp(z.model_fit_response,',','split');
            for oo=1:length(resp)
                fprintf('Response signal %i : %s.\n',oo,inputSignalNames{oo});
                fprintf('\tResponse definition : %s.\n',ga_fit_responses{oo});
                fprintf('\tResponse function : %s.\n',func2str(resp(oo).func));
            end
        end
        
        Y_arx_best_tf   = r.y_arx_best_tf{1};
        
        Y_arx = zeros(length(z.w_model_fit),length(resp));
        
        for oo=1:length(resp);
            Y_arx(:,oo)     = squeeze(freqresp(Y_arx_best_tf(oo),z.w_model_fit));
        end
        
        if verbose
            figure
            for oo=1:length(resp);
                subplot(2,1,1);
                    loglog(z.w_model_fit,abs(Y_arx(:,oo)),'r'); hold on
                subplot(2,1,2);
                    semilogx(z.w_model_fit,180/pi*unwrap(angle(Y_arx(:,oo))),'r'); hold on
            end
            display = 'iter';
        else
            display = 'none';
        end
        
        fun             = @(x) h_arx_model_cost(Y_arx, resp, x, z.w_model_fit, z.model_fit_lb, z.model_fit_ub);
        ga_options      = gaoptimset('Display',display,'PopulationSize',z.ga_populationSize,'Generations',z.ga_generations,'FitnessLimit',z.ga_fitnessLimit);
        [ga_x,ga_V]     = ga(fun,length(z.model_fit_lb),[],[],[],[],z.model_fit_lb, z.model_fit_ub, [],ga_options);
        
        
        if verbose
            [~,Yhat]    = fun(ga_x);
            for oo=1:length(resp);
                subplot(2,1,1);
                    loglog(z.w_model_fit,abs(Yhat(:,oo)),'b--'); hold on
                subplot(2,1,2);
                    semilogx(z.w_model_fit,180/pi*unwrap(angle(Yhat(:,oo))),'b--'); hold on
            end
        end
        
        r_n.ga_x      = ga_x;
        r_n.ga_V      = ga_V;
    end
end