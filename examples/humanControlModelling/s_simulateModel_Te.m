function step = s_simulateModel_Te()

    step.name       = mfilename;
    step.type       = 'step';
    step.input      = {'rCalcMethod','nr','rRatioOrGain'};
    step.optional   = {'K_t_y','K_t_phi','K_e_y','t_e_y','K_e_phi','K_y','K_phi','tau_t_y','tau_t_phi','tau_e_y','tau_y','tau_e_phi','tau_phi','K_p_y', ...
                       'K_p_t','K_p_t_n','K_p_e','tau_p_t','tau_p_e','tau_p_p','omega_nms','zeta_nms','K','tau','T','T_L','w_p_t','K_p_phi','tau_p_phi','omega_t', ...
                       'K_v','tau_v','T_lead','K_m','tau_m','T_I',...
                       'T_sc1','T_sc2','T_sc3','omega_s','T_s',...
                       'K_n_e','K_n_phi','K_n_nms',...
                       'Ypt_1','Ypt_2','Ypt_3',...
                       'omega_n','zeta_n'};
    step.output     = {'t_Te','u_Te','u_prenms_Te','u_p_t_Te','u_p_Te','y_Te','e_Te','ft_total_Te','n_Te','model_s_Te','phi_v_Te','phi_m_Te','u_p_phi_Te'};
    step.handle     = @myfunc;
    step.version    = 1;
    step.saveme     = 1;

    function [r_n] = myfunc(z,r,verbose,~)
        % z     = input parameters for this function
        % r     = output up till now
        % z_n   = any modifications made to the input parameters in this
        % step
        % r_n   = any new results produced by this function
        
        model = r.model_i.y.copy;
        
        if verbose == 1
            model.getRealP();
        end
        
        for oo=1:length(step.optional)
            model.setPilotParameter(step.optional{oo},z.(step.optional{oo}),verbose);
        end
        if isempty(z.omega_n)
            z.omega_n = 12.7;
        end
        if isempty(z.zeta_n)
            z.zeta_n = 0.26;
        end
        model.setRemnantParams(z.rRatioOrGain, z.omega_n, z.zeta_n,'calcMethod',z.rCalcMethod,'remnantSeed',z.nr);
        
        %% Run the model
        [~,x_e,~] = model.runTaskModel(model.getRealP());

        %% Save the results
        fn      = fieldnames(x_e);
        % A bit of an ugly hack to prevent us from outputting signals that
        % were already provided by the previous step, whilst maintaining
        % compatibility with older code.
        prevres = fieldnames(r);

        for oo=1:length(fn)
            if ~any(strcmp(fn{oo},prevres)) && any(strcmp(fn{oo},cellfun(@(x)x(1:(end-3)),step.output,'UniformOutput',false)))
                r_n.([fn{oo} '_Te']).x  = x_e.t;
                r_n.([fn{oo} '_Te']).y  = x_e.(fn{oo});
            end
        end
    end
end