function r_n = calcNewStep(obj,z_cum,z_step,r,hash,stepnr,lastStepInSequence)
    t_id=tic;
    r_n = obj.steps(stepnr).handle(z_cum,r,obj.funcverbose,hexhash(obj,hash));
    t_i=toc(t_id);
    
    outputs = fieldnames(r_n);
    for oo=1:length(outputs)
        if ~any(strcmp(outputs{oo},obj.steps(stepnr).output))
            error('Step %s returned result %s, but it was not in its output list.',obj.createLink(obj.steps(stepnr).name),obj.steps(stepnr).name,outputs{oo})
        end
    end
    
    if isfield(obj.steps(stepnr),'memorizeme')
        if obj.steps(stepnr).memorizeme == 0
            fprintf('Not saving the data of step %i.\n',stepnr);
            return;
        end
    end
    
    add(obj,hash,...
            [],...
            z_step,...
            r_n,...
            [],...          % decision
            true,...        % new
            t_i,...         % time
            stepnr,...
            lastStepInSequence,...
            obj.steps(stepnr).saveme);
end