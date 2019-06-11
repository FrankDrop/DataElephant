function r_n = calcNewStep(obj,z_cum,z_step,r,hash,stepnr,lastStepInSequence,checkOutputs)
    t_id=tic;
    r_n = obj.steps(stepnr).handle(z_cum,r,obj.funcverbose,hexhash(obj,hash));
    t_i=toc(t_id);
    
    if checkOutputs
        outputs = fieldnames(r_n);
        missing_outputs = {};
        for oo=1:length(outputs)
            if ~any(strcmp(outputs{oo},obj.steps(stepnr).output))                
                missing_outputs{end+1} = outputs{oo};
            end
        end
        
        if ~isempty(missing_outputs)
            error('Step %s returned the results ''%s\b\b'', but these were not in its output list.',...
                    obj.createLink(obj.steps(stepnr).name), sprintf('%s, ',missing_outputs{:}));
        end
        
        for oo=1:length(obj.steps(stepnr).output)
            if ~any(strcmp(obj.steps(stepnr).output{oo},outputs))
                error('Step %s did not return result %s, but it is in the step''s output list.',obj.createLink(obj.steps(stepnr).name),obj.steps(stepnr).output{oo})
            end
        end
        
        for oo=1:length(outputs)
            if isempty(r_n.(outputs{oo}))
                error('Step %s returned result %s, but it was empty.',obj.createLink(obj.steps(stepnr).name),outputs{oo})
            end
        end
    end
    
    
    if obj.steps(stepnr).memorizeme == 0 && obj.verbose
        fprintf('Not saving the data of step %i.\n',stepnr);
        return;
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