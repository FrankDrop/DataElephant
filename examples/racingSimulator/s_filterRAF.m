function step = s_filterRAF()

    step.name       = mfilename;
    step.type       = 'step';
    step.decide     = {};
    step.baseon     = {};
    step.input      = {'f_filt'};
    step.optional   = {};
    step.output     = {'t_cont;f_x','t_cont;f_y','t_cont;f_z',...
                       't_cont;omega_x','t_cont;omega_y','t_cont;omega_z',...
                       't_cont;x','t_cont;y','t_cont;z',...
                       't_cont;psi','t_cont;phi','t_cont;theta'};
    step.handle     = @myfunc;
    step.version    = 1;
    step.saveme     = 1;
    step.memorizeme = 1;
    
    function [r_n] = myfunc(z,r,~,~)
        
        % [r_n] = myfunc(z,r,~,~)
        % Inputs:
        % z     = input parameters for this function
        % r     = output up till now
        % v     = true if the user wants verbose output of the step
        % functions
        % id    = unique identifier of the current step and input
        % parameters
        % r_n   = any new results produced by this function
        
        [b,a]           = butter(2,z.f_filt/50);

        r_n.omega_x     = filtfilt(b,a,r.omega_x_raw);
        r_n.omega_y     = filtfilt(b,a,r.omega_y_raw);
        r_n.omega_z     = filtfilt(b,a,r.omega_z_raw);

        r_n.f_x         = filtfilt(b,a,r.f_x_raw);
        r_n.f_y         = filtfilt(b,a,r.f_y_raw);
        r_n.f_z         = filtfilt(b,a,r.f_z_raw);
        
        r_n.x           = filtfilt(b,a,r.x_raw);
        r_n.y           = filtfilt(b,a,r.y_raw);
        r_n.z           = filtfilt(b,a,r.z_raw);
        
        r_n.psi         = filtfilt(b,a,r.psi_raw);
        r_n.phi         = filtfilt(b,a,r.phi_raw);
        r_n.theta       = filtfilt(b,a,r.theta_raw);
        
    end
end