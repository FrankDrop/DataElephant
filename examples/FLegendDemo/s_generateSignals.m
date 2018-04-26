function step = s_generateSignals()

    step.name       = mfilename;
    step.type       = 'step';
    step.decide     = {};
    step.baseon     = {};
    step.input      = {'dt','T','f'};
    step.optional   = {};
    step.output     = {'t','t;sine','t;imaginary_sine'};
    step.handle     = @myfunc;
    step.version    = 4;
    step.saveme     = 1;
    step.memorizeme = 1;
    
    function [r_n] = myfunc(z,~,~,~)
        r_n.t                   = (0:z.dt:z.T).';
        r_n.sine                = sin(2*pi*z.f*r_n.t);
        r_n.imaginary_sine      = sin(2*pi*z.f*r_n.t) + 1i.* cos(z.f.*2*pi*r_n.t);
    end
end