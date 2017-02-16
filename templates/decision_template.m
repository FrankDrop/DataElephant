function step = d_DECISIONNAME()

    step.name       = mfilename;
    step.type       = 'decision';
    step.decide     = % required %;
    step.basedon    = {% required %};
    step.input      = {};
    step.optional   = {};
    step.handle     = @myfunc;
    step.version    = 1;
    step.saveme     = 1;
    step.memorizeme = 1;
    
    function [r_n] = myfunc(z,r,v,id)
        
    end
end