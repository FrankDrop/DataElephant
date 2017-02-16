function step = s_simClassicMCA()

    step.name       = mfilename;
    step.type       = 'step';
    step.decide     = {};
    step.baseon     = {};
    step.input      = {'modelname','g','cart0','k_x','k_y','k_z','k_P','k_Q','k_R','SatAngVel','SatSpecForce',...
                       'x_csi','y_csi','z_csi','x_wn','y_wn','z_wn','x_wn2','y_wn2','z_wn2',...
                       'roll_csi','roll_wn','pitch_csi','pitch_wn','yaw_csi','yaw_wn','TC_ratelimit','Kinput_linacc','Kinput_rotvel'};
    step.optional   = {};
    step.output     = {'Hpx','Hpy','Hpz','Lpx','Lpy','Lpz','Hproll','Hppitch','Hpyaw',...
                       't_cont;f_x_s','t_cont;f_y_s','t_cont;f_z_s',...
                       't_cont;omega_x_s','t_cont;omega_y_s','t_cont;omega_z_s'};
    step.handle     = @myfunc;
    step.version    = 6;
    step.saveme     = 1;
    step.memorizeme = 1;
    
    function [r_n] = myfunc(z,r,~,~)

        % define translational high-pass filters (3rd order)
        r_n.Hpx     = tf([1 0 0], [1 2*z.x_csi*z.x_wn z.x_wn^2])*tf([1 0], [1 z.x_wn2]);
        r_n.Hpy     = tf([1 0 0], [1 2*z.y_csi*z.y_wn z.y_wn^2])*tf([1 0], [1 z.y_wn2]);
        r_n.Hpz     = tf([1 0 0], [1 2*z.z_csi*z.z_wn z.z_wn^2])*tf([1 0], [1 z.z_wn2]);

        % define corresponding low-pass filters
        r_n.Lpx     = 1 - r_n.Hpx;
        r_n.Lpy     = 1 - r_n.Hpy;
        r_n.Lpz     = 1 - r_n.Hpz;

        % define rotational high-pass filters
        r_n.Hproll      = tf([1 0 0], [1 2*z.roll_csi*z.roll_wn z.roll_wn^2]);
        r_n.Hppitch     = tf([1 0 0], [1 2*z.pitch_csi*z.pitch_wn z.pitch_wn^2]);
        r_n.Hpyaw       = tf([1 0 0], [1 2*z.yaw_csi*z.yaw_wn z.yaw_wn^2]);

        % Run the model
        out                 = sim(z.modelname,'SrcWorkspace','current');
        
        omega_fb            = out.get('omega_fb');
        sf_fb               = out.get('sf_fb');
        
        r_n.f_x_s           = sf_fb(:,1);
        r_n.f_y_s           = sf_fb(:,2);
        r_n.f_z_s           = -sf_fb(:,3);

        r_n.omega_x_s       = omega_fb(:,4);
        r_n.omega_y_s       = omega_fb(:,5);
        r_n.omega_z_s       = omega_fb(:,6);
    end
end