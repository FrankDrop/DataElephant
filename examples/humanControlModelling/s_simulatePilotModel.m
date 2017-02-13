function step = s_simulatePilotModel()

    step.name       = mfilename;
    step.type       = 'step';
    step.input      = {'pilotInputFt','pilotInputY'};
    step.optional   = {};
    step.output     = {'u_pm','u_p_t_pm','u_p_e_pm'};
    step.handle     = @myfunc;
    step.version    = 2;
    step.saveme     = 1;

    function [r_n] = myfunc(z,r,verbose,~)
        % z     = input parameters for this function
        % r     = output up till now
        % z_n   = any modifications made to the input parameters in this
        % step
        % r_n   = any new results produced by this function
        
        model = r.model_i.y.copy;
        
        %% Run the model
        model.setPilotFt(r.(z.pilotInputFt).y);
        model.setPilotY(r.(z.pilotInputY).y);
        
        pilotParams = {'K_t_y','K_t_phi','K_e_y','t_e_y','K_e_phi','K_y','K_phi','tau_t_y','tau_t_phi','tau_e_y','tau_y','tau_e_phi','tau_phi','K_p_y', ...
                       'K_p_t','K_p_t_n','K_p_e','tau_p_t','tau_p_e','tau_p_p','omega_nms','zeta_nms','K','tau','T','T_L','w_p_t','K_p_phi','tau_p_phi','omega_t', ...
                       'K_v','tau_v','T_lead','K_m','tau_m','T_I',...
                       'T_sc1','T_sc2','T_sc3','omega_s','T_s',...
                       'K_n_e','K_n_phi','K_n_nms',...
                       'Ypt_1','Ypt_2','Ypt_3',...
                       'omega_n','zeta_n'};
        
        for oo=1:length(pilotParams)
            model.setPilotParameter(pilotParams{oo},z.(pilotParams{oo}),verbose);
        end
        
        [x_e,~]             = model.runPilotModel(model.getRealP());

        %% Save the results
        r_n.u_pm.x          = x_e.t;
        r_n.u_pm.y          = x_e.u;
        
        r_n.u_p_t_pm.x      = x_e.t;
        r_n.u_p_t_pm.y      = x_e.u_p_t;
        
        r_n.u_p_e_pm.x      = x_e.t;
        r_n.u_p_e_pm.y      = x_e.u_p_e;
    end
end