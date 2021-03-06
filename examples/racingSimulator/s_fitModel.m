function step = s_fitModel()

    step.name       = mfilename;
    step.type       = 'step';
    step.decide     = {};
    step.baseon     = {};
    step.input      = {'na','nb','nk','fit_on'};
    step.optional   = {};
    step.output     = {'t_fit','t_fit;f_y_fit','m'};
    step.handle     = @myfunc;
    step.version    = 4;
    step.saveme     = 1;
    step.memorizeme = 1;
    
    function [r_n] = myfunc(z,r,~,~)
        
        r_n.m           = arx(iddata(r.f_y(z.fit_on),r.steer(z.fit_on),0.01),[z.na z.nb z.nk]);
        r_n.f_y_fit     = sim(r_n.m,r.steer(z.fit_on));
        r_n.t_fit       = r.t(z.fit_on);
    end
end