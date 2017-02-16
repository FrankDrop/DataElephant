function step = s_runPerceptionModel()

    step.name       = mfilename;
    step.type       = 'step';
    step.decide     = {};
    step.baseon     = {};
    step.input      = {'modelname'};
    step.optional   = {};
    step.output     = {'t;O_path','t;O_head','t;O_diff','HP','P','H'};
    step.handle     = @myfunc;
    step.version    = 4;
    step.saveme     = 1;
    step.memorizeme = 1;
    
    function [r_n] = myfunc(z,r,~,~)
        
        out         = sim(z.modelname,'SrcWorkspace','current');

        RPY         = out.get('RPY');
        pos_limbic  = out.get('pos_limbic');
        
        r_n.O_path  = unwrap(atan2([0;diff(pos_limbic(:,2))], [0;diff(pos_limbic(:,1))])) * 180/pi;
        r_n.O_head  = unwrap(RPY(:,3))*180/pi;
        r_n.O_diff  = r_n.O_path - r_n.O_head;
        
        r_n.HP      = r_n.O_diff(round(length(r.t)/2));
        r_n.P       = r_n.O_path(round(length(r.t)/2));
        r_n.H       = r_n.O_head(round(length(r.t)/2));
    end
end