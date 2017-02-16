function step = s_perceptionModelInputs()

    step.name       = mfilename;
    step.type       = 'step';
    step.decide     = {};
    step.baseon     = {};
    step.input      = {};
    step.optional   = {};
    step.output     = {'omega_vis_ts','omega_ves_ts','a_ves_ts','gia_ves_ts','v_vis_ts',...
                       't;omega_vis','t;omega_ves','t;a_ves','t;gia_ves','t;v_vis',...
                       'N'};
    step.handle     = @myfunc;
    step.version    = 1;
    step.saveme     = 1;
    step.memorizeme = 1;
    
    function [r_n] = myfunc(z,r,~,~)
        
        % [r_n] = myfunc(z,r,v,id)
        % Inputs:
        % z     = input parameters for this function
        % r     = output up till now
        % v     = true if the user wants verbose output of the step
        % functions
        % id    = unique identifier of the current step and input
        % parameters
        % r_n   = any new results produced by this function
        % calculate acceleration acting on subject
        
        
        r_n.N   = length(r.t);
        Z       = zeros(r_n.N,1);
        psi     = Z;
        R       = 1.93 * ones(r_n.N,1);
        w       = [Z, Z, r.wz];
        
        dw      = [0 0 0; diff(w)./z.dt];
        dR      = [0; diff(R)./z.dt];
        ddR     = [0; diff(dR)./z.dt];

        a       = [Z,Z,Z]';

        a1      = zeros(3,r_n.N);
        a2      = zeros(3,r_n.N);
        a3      = zeros(3,r_n.N);
        a4      = zeros(3,r_n.N);
        
        for k = 1:length(r.t)
            % 4 Components: ddR; tangential acc; Centrifugal acc; Lin.
            % Coriolis acc;

            a1(:,k) = [-ddR(k) * sin(psi(k)) -ddR(k)*cos(psi(k)) 0]';
            a2(:,k) = cross(dw(k,:)', [-R(k) * sin(psi(k)) -R(k)*cos(psi(k)) 0]');
            a3(:,k) = cross(w(k,:)', cross(w(k,:)',[-R(k) * sin(psi(k)) -R(k)*cos(psi(k)) 0]'));
            a4(:,k) = 2 * cross(w(k,:)', [-dR(k) * sin(psi(k)) -dR(k)*cos(psi(k)) 0]');

            a = a1 + a2 + a3 + a4;
        end
        a   = a';

        %make new time base
%         t   = 0:dt:(N-1)*dt;
        % Why?!

        % construct GIA
        GIA         = a;
        GIA(:,3)    = GIA(:,3) + z.g;
%         time        = t;

        % initialize input
        r_n.omega_vis_ts    = timeseries(w,r.t);
        r_n.omega_ves_ts    = timeseries(w,r.t);
        r_n.a_ves_ts        = timeseries(a,r.t);
        r_n.gia_ves_ts      = timeseries(GIA,r.t);
        r_n.v_vis_ts        = timeseries([cumtrapz(r.t,a(:,1)), zeros(length(a),2)],r.t);
        
        r_n.omega_vis       = w;
        r_n.omega_ves       = w;
        r_n.a_ves           = a;
        r_n.gia_ves         = GIA;
        r_n.v_vis           = [cumtrapz(r.t,a(:,1)), zeros(length(a),2)];
    end
end