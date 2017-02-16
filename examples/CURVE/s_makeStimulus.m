function step = s_makeStimulus()

    step.name       = mfilename;
    step.type       = 'step';
    step.decide     = {};
    step.baseon     = {};
    step.input      = {'mnv','dt'};
    step.optional   = {};
    step.output     = {'t','t;wz'};
    step.handle     = @myfunc;
    step.version    = 4;
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
        
        switch z.mnv
            case 'CURVE1'
                % parameters for mnv 1:3
                omega_max = 63*0.95*pi/180 ;
                n = 1;
                [r_n.wz, r_n.t] = MakeStimulusCURVE1(omega_max, n, z.dt);
            case 'CURVE3'
                % parameters for mnv 1:3
                omega_max = 63*0.95*pi/180 ;
                n = 1;
                [r_n.wz, r_n.t] = MakeStimulusCURVE1(omega_max, n, z.dt);
            case 'CURVE2'
                omega_max = 50*pi/180;
                acc = 20 * pi/180;
                [r_n.wz, r_n.t, ~] = MakeStimulusCURVE2(acc, omega_max, 1.25, z.dt);
        end
    end

    function [wz, t] = MakeStimulusCURVE1(omega_max, n, dt)
        tend        = (4*pi*n)/omega_max;
        t           = [0:dt:tend].';
        N           = length(t);
        Z           = zeros(length(t),1);
        wz          = omega_max*(-0.5 * cos(2*pi*t./tend) + 0.5);
    end

    function [wz, t, t_plateau] = MakeStimulusCURVE2(acc, omega_max_trap, n, dt)
        psi_total = 2*pi*n;
        dec = acc;
        f = acc/(omega_max_trap*2);
        omega_max = omega_max_trap;

        A = acc*pi*f;
        tt = [0:dt:1/f]';

        j = A*sin(2*pi*f.*tt);
        a = -(A/(2*pi*f)) * cos(2*pi*f.*tt) + A/(2*pi*f);
        v1 = -(A/(2*pi*f)^2) * sin(2*pi*f.*tt) + A.*tt/(2*pi*f);
        v2 = flipud(v1);

        % calculate total displacement
        %x = (A/(2*pi*f)^3) * cos(2*pi*f.*tt) + (A.*tt.^2)/(4*pi*f);
        amax = [A/(pi*f)];
        vmax = [amax(1)/(2*f)];
        %xmax = x(end);%[vmax(1)/(2*f)+amax(1)/(8*pi^2*f^2)];

        D = 2 * max(cumtrapz(tt,v1)); %displacement during acc/dec
        total_displacement = psi_total;
        t_plateau = (total_displacement - D)/vmax;
        %t_total = t_plateau+2/f;

        % make velocity signal
        wz = [v1; vmax*ones(ceil(t_plateau/dt),1); v2];
        t = (0:dt:(length(wz)-1)*dt).';
        % X = (cumtrapz(t,wz))*180/pi;
        % plot(t,X); shg;

        % t = 0:dt:t_total;
        % wz = vmax*ones(length(t),1);
        % wz(1:length(v1)) = v1;
        % wz(end-length(v2)+1:end) = v2;
    end
end