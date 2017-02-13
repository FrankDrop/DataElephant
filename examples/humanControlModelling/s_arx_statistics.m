function step = s_arx_statistics()

    step.name       = mfilename;
    step.type       = 'step';
    step.input      = {};
    step.optional   = {};
	step.output     = {'arx_vaf','u_1','u_2','u_3','u_4','u_5','var_u_1_var_u','var_u_2_var_u','var_u_3_var_u','var_u_4_var_u','var_u_5_var_u'};
    step.handle     = @myfunc;
    step.version    = 2;
    step.saveme     = 1;

    function [r_n] = myfunc(~,r,~,~)
        nr_i            = size(r.i_arx.y,2);
        r_n.arx_vaf.y   = 100*(1 - (r.u_arx_sim.y(r.evalon_arx.y) - r.o_arx.y(r.evalon_arx.y)).' * (r.u_arx_sim.y(r.evalon_arx.y) - r.o_arx.y(r.evalon_arx.y)) / ...
                                (r.o_arx.y(r.evalon_arx.y).' * r.o_arx.y(r.evalon_arx.y)));
        
        for oo=1:nr_i
            u_sim                                       = lsim(r.Y_arx_best_ss.y{1}(oo), r.i_arx.y(:,oo), r.t_arx.y);
            r_n.(['u_' num2str(oo)]).y                  = u_sim;
            u_sim                                       = u_sim(r.evalon_arx.y);
            r_n.(['var_u_' num2str(oo) '_var_u']).y     = var(u_sim) / var(r.u_arx_sim.y(r.evalon_arx.y));
        end
    end
end