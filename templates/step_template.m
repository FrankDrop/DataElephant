function step = s_STEPNAME()

    step.name       = mfilename;        % Required
    step.type       = 'step';           % Required
    step.input      = {};
    step.optional   = {};
    step.output     = {};
    step.handle     = @myfunc;
    step.version    = 1;
    step.saveme     = 1;
    step.memorizeme = 1;
    
    function [r_n] = myfunc(z,r,v,id)
        
    end
end