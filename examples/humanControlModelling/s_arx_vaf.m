function step = s_arx_vaf()

    step.name       = mfilename;
    step.type       = 'step';
    step.input      = {};
    step.optional   = {};
	step.output     = {'vaf_arx','vaf_arx_eval'};
    step.handle     = @myfunc;
    step.version    = 2;
    step.saveme     = 1;

    function [r_n] = myfunc(~,r,~,~)
        r_n.vaf_arx.y       = 100*(1 - (r.u_arx_sim.y                 - r.o_arx.y                ).' * (r.u_arx_sim.y                 - r.o_arx.y                ) / ...
                                (r.o_arx.y.'                 * r.o_arx.y));
        r_n.vaf_arx_eval.y  = 100*(1 - (r.u_arx_sim.y(r.evalon_arx.y) - r.o_arx.y(r.evalon_arx.y)).' * (r.u_arx_sim.y(r.evalon_arx.y) - r.o_arx.y(r.evalon_arx.y)) / ...
                                (r.o_arx.y(r.evalon_arx.y).' * r.o_arx.y(r.evalon_arx.y)));
    end
end