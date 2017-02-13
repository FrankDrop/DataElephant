model.setModels('sd_task_new','sd_pilot');

model.setParameterNames({'K_c'},{'K_p_t','T_I','tau_p_t','K_p_e','tau_p_e','omega_nms','zeta_nms'});
model.setLatexPilotParameterNames({'K_{p_t}','T_I','\tau_{p_t}','K_{p_e}','\tau_{p_e}','\omega_{nms}','\zeta_{nms}'});

if exist('z','var')
    if isempty(z.K_c)
        z.K_c = 1;
    end
else
    z.K_c = 1;
end

model.setTaskParameterValues({z.K_c});

% This model is not correct. It has (T_I * s + 1)^1 instead of (T_I * s +
% 1)^2 as described in Laurense. The FB parameters are adjusted for the
% drop, 2011b disturbance signal.

model.defineTf('Ype'    ,'pp.K_p_e                                          * exp(-S * pp.tau_p_e)');
model.defineTf('Ypt'    ,'pp.K_p_t * (S / tp.K_c) * (1 / (pp.T_I * S + 1))  * exp(-S * pp.tau_p_t)');
model.defineTf('Ynms'   ,'pp.omega_nms^2 / (S^2 + 2*pp.zeta_nms*pp.omega_nms*S + pp.omega_nms^2)');
model.defineTf('Yc'     ,'tp.K_c / S');
           
model.defineTransferFunctions(1);

model.setParametersByName('K_p_t',        1,      0,      2);     % Was 0.8 in the Sys Dyn paper.
model.setParametersByName('T_I',          0.28,   0.01,   2);     % See the Sys Dyn paper.
model.setParametersByName('tau_p_t',      0.2,    0.01,   0.8);   % See the Sys Dyn paper.

model.setParametersByName('K_p_e',        2.3,    0,      3);     % See the Sys Dyn paper.
model.setParametersByName('tau_p_e',      0.21,   0,      0.6);   % See the Sys Dyn paper.

model.setParametersByName('omega_nms',    12,     5,      20);    % See the Sys Dyn paper.
model.setParametersByName('zeta_nms',     0.2,    0.01,   1);     % See the Sys Dyn paper.
