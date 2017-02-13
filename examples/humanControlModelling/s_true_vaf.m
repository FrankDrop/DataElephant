function step = s_true_vaf()

    step.name       = mfilename;
    step.type       = 'step';
    step.input      = {'eval_vaf_from','eval_vaf_to'};
    step.optional   = {};
	step.output     = {'vaf_true'};
    step.handle     = @myfunc;
    step.version    = 1;
    step.saveme     = 1;

    function [r_n] = myfunc(z,r,~,~)
        epsilon             = (r.u_pm.y(z.eval_vaf_from:z.eval_vaf_to) - r.u_Te.y(z.eval_vaf_from:z.eval_vaf_to));
        r_n.vaf_true.y      = 100*(1 - epsilon.' * epsilon / (r.u_Te.y.' * r.u_Te.y));
    end
end