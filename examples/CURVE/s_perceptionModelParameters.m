function step = s_perceptionModelParameters()

    step.name       = mfilename;
    step.type       = 'step';
    step.decide     = {};
    step.baseon     = {};
    step.input      = {'g','tau_oto','tau_HSCC1','tau_HSCC2','tau_alb','KB_v_vis','KB_omega_vis',...
                       'KB_g_vis','K_a','K_f','K_fomega','K_omega','K_omegaf','K_1','K_xdot_V','K_g_V',...
                       'K_omega_V','tau_x','tau_y','tau_z','K_iv'};
    step.optional   = {};
    step.output     = {'HV_xdot','HV_omega','HV_g','Hoto','HVISxdot','HVISomega','HVISg',...
                       'HOTO','HSCC','Hbr','HVISxdot_hat','HVISomega_hat','HVISg_hat','HOTO_hat',...
                       'HSCC_hat','G0_vis','G0_mot','G0_hat','G_iv'};
    step.handle     = @myfunc;
    step.version    = 1;
    step.saveme     = 1;
    step.memorizeme = 1;
    
    function [r_n] = myfunc(z,r,v,id)
        
        % [r_n] = myfunc(z,r,v,id)
        % Inputs:
        % z     = input parameters for this function
        % r     = output up till now
        % v     = true if the user wants verbose output of the step
        % functions
        % id    = unique identifier of the current step and input
        % parameters
        % r_n   = any new results produced by this function
        
        r_n.HV_xdot             = tf(1, [1]); % [Zupan, 2002]
        r_n.HV_omega            = tf(1, [1]); % [Zupan, 2002]
        r_n.HV_g                = tf(1, [1]); % No ref, same as xdot and omega

        r_n.Hoto                = tf(1, [1]);
        r_n.HVISxdot            = -1*r_n.HV_xdot;
        r_n.HVISomega           = -1*r_n.HV_omega;
        r_n.HVISg               = r_n.HV_g;
        r_n.HOTO                = r_n.Hoto;
        HSCC                    = tf([z.tau_HSCC1 0],[z.tau_HSCC1 1])*tf([z.tau_HSCC2 0],[z.tau_HSCC2 1]);

        r_n.Hbr                 = tf(1, [z.tau_alb 1])^2;
        r_n.HSCC                = HSCC*r_n.Hbr;
        
        r_n.HVISxdot_hat        = -r_n.HVISxdot;
        r_n.HVISomega_hat       = -r_n.HVISomega;
        
        r_n.HVISg_hat           = r_n.HVISg;
        r_n.HOTO_hat            = r_n.HOTO;
        r_n.HSCC_hat            = tf([z.tau_HSCC1 0],[z.tau_HSCC1 1]); % adaptation term removed
        r_n.G0_vis              = [0; 0; -1];
        r_n.G0_mot              = [0; 0; -1];
        r_n.G0_hat              = [0; 0; -1];
        r_n.G_iv                = [0; 0; -1];

    end


    
    function [r_n] = myfunc2(z,~,~,~)
        
        % [r_n] = myfunc(z,r,v,id)
        % Inputs:
        % z     = input parameters for this function
        % r     = output up till now
        % v     = true if the user wants verbose output of the step
        % functions
        % id    = unique identifier of the current step and input
        % parameters
        % r_n   = any new results produced by this function
        
        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % 
        % Parameter initialization file for:
        %        wabs_perceptionmodel_v1c.mdl vesion curve
        %
        % Suzanne Nooij
        %jan 2015
        %
        % 
        % 
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % Global model parameters
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        % gravitational constant
%         g = 9.81;

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % sensory dynamics
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        % visual sensor transfer functions from Zupan and TNO models
        r_n.HV_xdot     = tf(1, [1]); % [Zupan, 2002]
        r_n.HV_omega    = tf(1, [1]); % [Zupan, 2002]
        r_n.HV_g        = tf(1, [1]); % No ref, same as xdot and omega

        % otolith transfer function from [Zupan, 2002]
%         tau_oto  = 0.03;
        r_n.Hoto        = tf(1, [1]);

        % VISUAL, LINEAR VELOCITY
        r_n.HVISxdot        = -1*r_n.HV_xdot;
%         r_n.num_HVISxdot    = r_n.HVISxdot.num{1};
%         r_n.den_HVISxdot    = r_n.HVISxdot.den{1};

        % VISUAL, ROTATIONAL VELOCITY
        r_n.HVISomega       = -1*r_n.HV_omega;
%         r_n.num_HVISomega   = HVISomega.num{1};
%         r_n.den_HVISomega   = HVISomega.den{1};

        % VISUAL, ORIENTATION
        r_n.HVISg     = r_n.HV_g;
%         num_HVISg = HVISg.num{1};
%         den_HVISg = HVISg.den{1};

        % VESTIBULAR, OTOLITHS
        r_n.HOTO     = r_n.Hoto;
%         num_HOTO = HOTO.num{1};
%         den_HOTO = HOTO.den{1};

        % VESTIBULAR, SCC
        % SCC dynamics from [Newman, 2009, see also originalpaper of Merfeld & Zupen 2002]
%         tau_HSCC1 = 5;
%         tau_HSCC2 = 80;
        HSCC = tf([z.tau_HSCC1 0],[z.tau_HSCC1 1])*tf([z.tau_HSCC2 0],[z.tau_HSCC2 1]);

        % added low-pass filter algebraic loop breaker
%         tau_alb = 0.02;
        r_n.Hbr     = tf(1, [z.tau_alb 1])^2;
        r_n.HSCC    = HSCC*r_n.Hbr;

%         num_HSCC = HSCC.num{1};
%         den_HSCC = HSCC.den{1};

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % internal models of sensory dynamics
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        % VISUAL, LINEAR VELOCITY
        r_n.HVISxdot_hat     = -r_n.HVISxdot;
%         num_HVISxdot_hat =  HVISxdot_hat.num{1};
%         den_HVISxdot_hat =  HVISxdot_hat.den{1};

        % VISUAL, ROTATIONAL VELOCITY
        r_n.HVISomega_hat     = -r_n.HVISomega;
%         num_HVISomega_hat =  HVISomega_hat.num{1};
%         den_HVISomega_hat =  HVISomega_hat.den{1};

        % VISUAL, ORIENTATION
        r_n.HVISg_hat     = r_n.HVISg;
%         num_HVISg_hat = HVISg_hat.num{1};
%         den_HVISg_hat = HVISg_hat.den{1};

        % VESTIBULAR, OTOLITHS
        r_n.HOTO_hat     = r_n.HOTO;
%         num_HOTO_hat = HOTO_hat.num{1};
%         den_HOTO_hat = HOTO_hat.den{1};

        % VESTIBULAR, SCC
        r_n.HSCC_hat = tf([z.tau_HSCC1 0],[z.tau_HSCC1 1]); % adaptation term removed
%         num_HSCC_hat  = HSCC_hat.num{1};
%         den_HSCC_hat  = HSCC_hat.den{1};



        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % Visual path breakers
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        % These gains (either 1 or 0) enable or disable the visual pathways, 
        % to allow for eyes closed scenarios. Default is enabled.
%         KB_v_vis     = 1;
%         KB_omega_vis = 1;
%         KB_g_vis     = 1;

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % model parameters
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        % taken from [Newman, 2009], Table 2 
%         K_a       = -4;
%         K_f       =  4;
%         K_fomega  =  8;
%         K_omega   =  8;
%         K_omegaf  =  1;
%         K_1       =  (K_omega+1)/K_omega;
%         K_xdot_V  =  0.75;
%         K_g_V     = 10;
%         K_omega_V = 10;
%         tau_x     = 16.67;
%         tau_y     = 16.67;
%         tau_z     =  1;

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % Initial states
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        % initial gravity orientation (used in internal model of kinematics, g)
        r_n.G0_vis = [0; 0; -1];
        r_n.G0_mot = [0; 0; -1];
        r_n.G0_hat = [0; 0; -1];

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % Idiotropic vector parameters
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        % idiotropic vector direction: aligned with vertical body axis (do not modify)
        r_n.G_iv = [0; 0; -1];

        % idiotropic vector weight
        % 0    = no idiotropic vector
        % 0.05 = idiotropic vector weight from TNO model [Bos, 2002]
        % 0.2  = idiotropic vector weight from [Vingerhoets, 2007] (this vestibular model)
%         K_iv = 0;

    end
end