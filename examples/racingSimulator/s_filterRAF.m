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
                       't_cont;psi','t_cont;phi','t_cont;theta','t_cont;V'};
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
        
        %[b,a]           = butter(2,z.f_filt/50);
        
        s   = tf('s');
        w_c             = z.f_filt * 2 * pi;
        but             = ss(1/((s/w_c)^2+1.4142*(s/w_c)+1));
        
        r_n.omega_x     = flipud(lsim(but,flipud(lsim(but,r.omega_x_raw, r.t)),r.t));
        r_n.omega_y     = flipud(lsim(but,flipud(lsim(but,r.omega_y_raw, r.t)),r.t));
        r_n.omega_z     = flipud(lsim(but,flipud(lsim(but,r.omega_z_raw, r.t)),r.t));

        r_n.f_x         = flipud(lsim(but,flipud(lsim(but,r.f_x_raw, r.t)),r.t));
        r_n.f_y         = flipud(lsim(but,flipud(lsim(but,r.f_y_raw, r.t)),r.t));
        r_n.f_z         = flipud(lsim(but,flipud(lsim(but,r.f_z_raw, r.t)),r.t));
        
        r_n.x           = flipud(lsim(but,flipud(lsim(but,r.x_raw, r.t, [0 r.x_raw(1)/but.C(2)])),r.t,[0 r.x_raw(end)/but.C(2)]));
        r_n.y           = flipud(lsim(but,flipud(lsim(but,r.y_raw, r.t, [0 r.y_raw(1)/but.C(2)])),r.t,[0 r.y_raw(end)/but.C(2)]));
        r_n.z           = flipud(lsim(but,flipud(lsim(but,r.z_raw, r.t, [0 r.z_raw(1)/but.C(2)])),r.t,[0 r.z_raw(end)/but.C(2)]));
        
        r_n.psi         = flipud(lsim(but,flipud(lsim(but,r.psi_raw, r.t)),r.t));
        r_n.phi         = flipud(lsim(but,flipud(lsim(but,r.phi_raw, r.t)),r.t));
        r_n.theta       = flipud(lsim(but,flipud(lsim(but,r.theta_raw, r.t)),r.t));
        
        r_n.V           = flipud(lsim(but,flipud(lsim(but,r.V_raw, r.t)),r.t));
    end
end