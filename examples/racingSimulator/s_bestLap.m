function step = s_bestLap()

    step.name       = mfilename;
    step.type       = 'step';
    step.decide     = {};
    step.baseon     = {};
    step.input      = {};
    step.optional   = {};
    step.output     = {'t_cont;f_x_best','t_cont;f_y_best','t_cont;f_z_best'};
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
        
        r_n.f_x_best     = r.f_x;
        r_n.f_y_best     = r.f_y;
        r_n.f_z_best     = r.f_z;
    end
end