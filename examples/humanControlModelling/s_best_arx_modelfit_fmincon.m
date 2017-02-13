function step = s_best_arx_modelfit_fmincon()

    step.name       = mfilename;
    step.type       = 'step';
    step.input      = {};
    step.optional   = {};
	step.output     = {'best_fmincon_V','best_fmincon_x','best_Yhat'};
    step.handle     = @myfunc;
    step.version    = 6;
    step.saveme     = 1;
    step.memorizeme = 1;

    function [r_n] = myfunc(z,r,~,~)
        
        Yhat = h_create_arx_model_response_tf(r,z.model_fit_response,z.iSignals,r.fmincon_x.y);
        
        if ~isfield(z,'tau_iSignals')
            inputSignalNames    = regexp(z.iSignals,',','split');
            z.tau_iSignals      = zeros(1,length(inputSignalNames));
        end
        
        Yhat.UserData.tau_iSignals  = z.tau_iSignals * (r.t.x(2)-r.t.x(1));
        
        r_n.best_fmincon_V.y        = r.fmincon_V.y;
        r_n.best_fmincon_x.y        = r.fmincon_x.y;
        r_n.best_Yhat.y             = {Yhat};
    end
end