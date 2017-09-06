function [decision,z_dec] = calcNewDecision(obj,z_cum,~,r,hash,fasthash,decision_hash,stepnr,lastStepInSequence)
    t_id=tic;
    if size(decision_hash,1) > 1 % It is possible to decide from just 1 option. In this case we do not have to run the decision.
        idx         = obj.steps(stepnr).handle(z_cum,r,obj.funcverbose,hexhash(obj,hash));
        decision    = decision_hash(idx,:);
        z_dec.(obj.steps(stepnr).decide) = z_cum.(obj.steps(stepnr).decide){idx};
    else
        decision    = decision_hash;
        z_dec.(obj.steps(stepnr).decide) = z_cum.(obj.steps(stepnr).decide);
    end
    t_i=toc(t_id);
    
    add(obj,hash,....
            fasthash,...
            z_dec,...
            [],...      % result
            decision,...
            true,...    % new
            t_i,...     % time
            stepnr,...    
            lastStepInSequence,...
            obj.steps(stepnr).saveme);
end