function r_n = calcNewStep(obj,z_cum,z_step,r,hash,step,lastStepInSequence)
    t_id=tic;
    r_n = obj.steps(step).handle(z_cum,r,obj.funcverbose,hexhash(obj,hash));
    t_i=toc(t_id);
    
    outputs = fieldnames(r_n);
    for oo=1:length(outputs)
        if ~any(strcmp(outputs{oo},obj.steps(step).output))
            error('Step <a href="matlab:open %s">%s</a> returned result %s, but it was not in its output list.',obj.steps(step).name,obj.steps(step).name,outputs{oo})
        end
        
        if obj.process.xy
            if isfield(r_n.(outputs{oo}),'x') && isfield(r_n.(outputs{oo}),'y')
                if ~isequal(size(r_n.(outputs{oo}).x),size(r_n.(outputs{oo}).y))
                    error('For output field ''%s'' the size of x=[%s\b] and y=[%s\b]. These should match. Problem is in <a href="matlab:open %s">%s</a>.',outputs{oo},...
                                                                               sprintf('%i ',size(r_n.(outputs{oo}).x)),...
                                                                               sprintf('%i ',size(r_n.(outputs{oo}).y)),...
                                                                               obj.steps(step).name,...
                                                                               obj.steps(step).name)
                end
            end
        end
    end
    
    add(obj,hash,...
            [],...
            z_step,...
            r_n,...
            [],...          % decision
            true,...        % new
            t_i,...         % time
            step,...
            lastStepInSequence,...
            obj.steps(step).saveme);
end