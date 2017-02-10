function [r,id_cum,f,z_cum,z_step] = getAll(obj,name,z_cum,z_step,startAtStep,stopAtStep,lastStepInSequence,r,id_cum,minStep)

    fnc             = {};
    fnc_step        = [];
    dec             = {};
    dec_step_start  = [];
    dec_step_stop   = [];
    ll              = 1;
    ff              = 1;

    if obj.verbose
        fprintf('%sgetAll(''%s'',z_cum,z_step,startAtStep=%i,stopAtStep=%i,lastStepInSequence=%i,r,''%s''); @ %s\n',sprintf(repmat('\t',1,startAtStep)),...
            sprintf('%s;',name{:}),startAtStep,stopAtStep,lastStepInSequence,hexhash(obj,id_cum),datestr(now));
    end

    
%% Determine the order of execution.

% The first code-cell contains the code that determines what steps should be
% handled first and in what order the code will proceed through the
% processes.

    stopFncAtStep           = stopAtStep;
    simpleFunctional        = false;
    getDecisionAsFncOf      = false;

    % Figure out what functionals are provided at which steps, and what
    % decisions are made at which steps.
    for oo=startAtStep:stopAtStep
        t_step      = obj.steps(oo);
        if ~isempty(z_step{oo})
            t_inputs    = fieldnames(z_step{oo});
            n_inputs    = length(t_inputs);

            for ii=1:n_inputs
                if iscell(z_step{oo}.(t_inputs{ii}))
                    fnc{ll}         = t_inputs{ii}; %#ok<AGROW>
                    fnc_step(ll)    = oo; %#ok<AGROW>
                    ll              = ll+1;
                end
            end
        end

        if ~obj.steps(oo).type % = decision
            dec{ff}             = t_step.decide; %#ok<AGROW>
            dec_step_stop(ff)   = oo; %#ok<AGROW>
            ff = ff+1;
        end
    end

    % Figure out at which steps the functionals start, that are used later
    % to make a decision.
    for oo=startAtStep:stopAtStep
        if ~isempty(z_step{oo})
            t_inputs    = fieldnames(z_step{oo});
            n_inputs    = length(t_inputs);

            for ii=1:n_inputs
                if any(strcmp(t_inputs{ii},dec))                            
                    dec_step_start(strcmp(t_inputs{ii},dec))    = oo; %#ok<AGROW>
                end
            end
        end
    end

    % First eliminate a few possibilities...
    % All functionals that are done after the last decision step
    % should of course not be handled now.

    % So we found at least one function call            
    if ~isempty(fnc_step)

        if obj.verbose
            fprintf('%sThese functionals are left: %s\b\b.\n%sThese decisions are to be taken: %s\b\b.\n',...
                sprintf(repmat('\t',1,startAtStep)),...
                sprintf('%s, ',fnc{:}),...
                sprintf(repmat('\t',1,startAtStep)),...
                sprintf('%s, ',dec{:}));
        end

        satisfied = false;
        
        if isempty(dec) && length(fnc) == 1
            if obj.verbose
                fprintf('%sWe need results as a function of one functional only (%s).\n',sprintf(repmat('\t',1,startAtStep)),sprintf('%s, ',fnc{:}));
            end
            simpleFunctional    = true;
        end

        
        if length(dec) == 1 && length(fnc) == 1
            if obj.verbose
                fprintf('%sThe only functional is a decision, so we can handle everything in this getAll() call.\n',sprintf(repmat('\t',1,startAtStep)));
            end
            singleUntilStep     = stopAtStep;
            satisfied           = true;
        end

        % Before we start throwing stuff away, we first
        % need to check whether or not _all_ function calls
        % belong to a decision. In that case we need to do
        % the one that decides last first.
        
        if length(dec) > 1
            if length(intersect(fnc,dec)) == length(fnc)
                if obj.verbose
                    fprintf('%sThe only functionals (%s\b\b) are decisions (%s\b\b). What to do?\n',sprintf(repmat('\t',1,startAtStep)),sprintf('%s, ',fnc{:}),sprintf('%s, ',dec{:}));
                end

                % First check if all functionals are sequential or
                % not. Then we can just let getSingleResult handle
                % it.

                allDecisionsSequential = true;
                for qq=1:(length(fnc)-1)
                    if ~(all(dec_step_stop(qq) < dec_step_start(dec_step_start > dec_step_start(qq))) && all(dec_step_start(qq) > dec_step_stop(dec_step_start < dec_step_start(qq))))
                        allDecisionsSequential = false;
                        break;
                    end
                end

                if allDecisionsSequential
                    if obj.verbose
                        fprintf('%sAll decisions are sequential (they end before another one opens). We can let getSingleResult handle this.\n',sprintf(repmat('\t',1,startAtStep)));
                    end
                    singleUntilStep     = stopAtStep;
                else
                    [~,finLast]         = max(dec_step_stop);
                    getAsFuncOf         = dec{finLast};
                    singleUntilStep     = min(fnc_step)-1;
                    stopFncAtStep       = dec_step_stop(finLast)-1;
                    if obj.verbose
                        fprintf('%sNot all decisions are sequential. We start with the one that closes last, which is %s.\n',sprintf(repmat('\t',1,startAtStep)),getAsFncOf);
                    end
                end
                satisfied = true;
            else
                if obj.verbose
                    fprintf('%sNot all functionals (%s\b\b) are decisions (%s\b\b).\n',sprintf(repmat('\t',1,startAtStep)),sprintf('%s, ',fnc{:}),sprintf('%s, ',dec{:}));
                end
            end
        end
                
        % Then there are some remaining cases. Probably this code could be
        % written more efficient, but let's stick to this for now...
        
        while ~satisfied
            
            % First, we determine the first step that has functionals:
            firstStepWithFuncs          = min(fnc_step);
            % Thus, the functionals of this first step with functionals
            % are: (might be multiple)
            funcsOfFirstStepWithFuncs   = fnc(fnc_step == firstStepWithFuncs);
            
            % Is any of those functionals part of a decision?            
            if ~isempty(intersect(funcsOfFirstStepWithFuncs,dec))
                % Yes, these functionals are part of a decision. Now we need to determine
                % how we are going to handle this.
                
                % We need to know at what step the functionals stop:
                [fnc_dec,~,di]      = intersect(funcsOfFirstStepWithFuncs,dec);
                [~,dec_as_fnc_idx]  = find(fnc_step ~= firstStepWithFuncs);
                
                obj.pverbose('%sFunction %s belongs to a decision.\n',sprintf(repmat('\t',1,startAtStep)),fnc_dec{1})
                
                % This is in the code since a long time, but I don't know
                % exactly why... It seems that this error is thrown if 2
                % decisions need to be made over functionals that start at
                % the same step... that should be possible, though? Maybe
                % the code is simply not prepared for this?
                if length(fnc_dec) > 1
                    error('Big error!');
                end
                
                
                % So now we know what the functional(s) are that belong to
                % the first step we are considering, whether it belongs to
                % a decision or not, and what decision this is.
                % If we end up here, the functional is part of a decision.

                % Now, there are two possibilities: either the functional
                % completely 'closes' after the decision, or the decision has to be
                % taken as a function of something.
                
                if dec_step_stop(di) > min(fnc_step(fnc_step ~= firstStepWithFuncs))
                    % This is basically the case were a functional
                    % belonging to a decision starts at step i, a different
                    % functional starts at step i+x, and the decision that
                    % closes the first functional is at step i+x+1 or later
                    obj.pverbose('%sBefore %s closes, another function opens, we cannot start this one now.\n',sprintf(repmat('\t',1,startAtStep)),fnc_dec{1});
                    % Hence, we throw the decision out, and let subsequent
                    % code decide what functional to start first.
                    fnc_step(strcmp(fnc_dec{1},fnc))    = []; %#ok<AGROW>
                    fnc(strcmp(fnc_dec{1},fnc))         = []; %#ok<AGROW>
                    fnc_step                            = fnc_step - (min(fnc_step) - firstStepWithFuncs);
                    dec(di)                             = []; %#ok<AGROW>
                    dec_step_start(di)                  = []; %#ok<AGROW>
                    dec_step_stop(di)                   = []; %#ok<AGROW>
                    
                elseif dec_step_stop(di) == min(fnc_step(fnc_step ~= firstStepWithFuncs)) && length(dec_as_fnc_idx) > 1
                    % The decision needs to be taken as a function of
                    % multiple functionals. We throw the decision out and
                    % let subsequent code decide what functional to do
                    % first.
                    
                    fnc_step(strcmp(fnc_dec{1},fnc))    = []; %#ok<AGROW>
                    fnc(strcmp(fnc_dec{1},fnc))         = []; %#ok<AGROW>
                    fnc_step                            = fnc_step - (min(fnc_step) - firstStepWithFuncs);
                    dec(di)                             = []; %#ok<AGROW>
                    dec_step_start(di)                  = []; %#ok<AGROW>
                    dec_step_stop(di)                   = []; %#ok<AGROW>
                elseif dec_step_stop(di) == min(fnc_step(fnc_step ~= firstStepWithFuncs)) && length(dec_as_fnc_idx) == 1
                    % There is just one functional that is closed by this
                    % decision. That is, we need to take a decision as a
                    % function of one parameter. We can handle this in a
                    % faster way.
                    singleUntilStep                     = firstStepWithFuncs -1;
                    getDecisionAsFncOf                  = true;
                    getAsFuncOf                         = fnc{dec_as_fnc_idx};
                    satisfied                           = true;
                    obj.pverbose('%sThe decision over %s is to be taken as a function of %s.\n',sprintf(repmat('\t',1,startAtStep)),fnc_dec{1},fnc{dec_as_fnc_idx});
                else
                    obj.pverbose('%sThe decision %s closes before all other functions open, so we can remove this one from the list.\n',sprintf(repmat('\t',1,startAtStep)),fnc_dec{1});
                    fnc_step(strcmp(fnc_dec{1},fnc))    = []; %#ok<AGROW>
                    fnc(strcmp(fnc_dec{1},fnc))         = []; %#ok<AGROW>
                    dec(di)                             = []; %#ok<AGROW>
                    dec_step_start(di)                  = []; %#ok<AGROW>
                    dec_step_stop(di)                   = []; %#ok<AGROW>
                end
            else
                % No, it is not part of a decision.
                singleUntilStep = firstStepWithFuncs-1;
                if length(funcsOfFirstStepWithFuncs) > 1
                    % We need to decide which function goes first.
                    num_inputs  = zeros(length(funcsOfFirstStepWithFuncs),1);
                    for oo=1:length(funcsOfFirstStepWithFuncs)
                        num_inputs(oo) = length(z_cum{stopAtStep}.(funcsOfFirstStepWithFuncs{oo}));
                    end
                    [~,small_idx]   = min(num_inputs);
                    getAsFuncOf     = funcsOfFirstStepWithFuncs{small_idx};
                    if obj.verbose
                        fprintf('%sInput %s has the least amount of variations, so goes first.\n',sprintf(repmat('\t',1,startAtStep)),getAsFuncOf);
                    end
                    satisfied       = true;
                else
                    getAsFuncOf     = funcsOfFirstStepWithFuncs{1};
                    satisfied       = true;
                    if obj.verbose
                        fprintf('%sInput %s is the only functional.\n',sprintf(repmat('\t',1,startAtStep)),getAsFuncOf);
                    end
                end
            end
        end
    else
        singleUntilStep = stopAtStep;
    end
    
    
%% The single part
% This is the part that is done before any functional starts. This data is
% equal for all functionals in subsequent steps.

    if singleUntilStep >= startAtStep
        [r,id_cum_s,z_cum,z_step]   = getSingleResult(obj,name,z_cum,z_step,startAtStep,singleUntilStep,lastStepInSequence,r,id_cum,false,[],minStep);
        id_cum                      = id_cum_s;
    end
    
%% The functional part

    f       = [];
    if singleUntilStep < stopFncAtStep
        f.this.name     = getAsFuncOf;
        f.this.value    = z_cum{stopFncAtStep}.(getAsFuncOf);

        if simpleFunctional || getDecisionAsFncOf
            
            [r_s,id_cum_f,~,~] = getSingleResult(obj,name,z_cum,z_step,singleUntilStep+1,stopFncAtStep,lastStepInSequence,r,id_cum,true,getAsFuncOf,minStep);
            
            f.sub     = '';
            
            % The output of getSingleResult is slightly different from
            % getAll, so we have to convert it.
            r_f             = cell(length(z_cum{stopFncAtStep}.(getAsFuncOf)),1);
            
            
%             if obj.process.xy
%                 if isfield(r_s.(name),'x')
%                     if ~isempty(r_s.(name).x{1})
%                         for rr=1:length(z_cum{stopFncAtStep}.(getAsFuncOf))
%                             r_f{rr}.(name).x   = r_s.(name).x{rr};
%                         end
%                     end
%                 end
% 
%                 for rr=1:length(z_cum{stopFncAtStep}.(getAsFuncOf))
%                     r_f{rr}.(name).y   = r_s.(name).y{rr};
%                 end
%             else
                for rr=1:length(z_cum{stopFncAtStep}.(getAsFuncOf))
                    r_f{rr}.(name)   = r_s.(name){rr};
                end
%             end
        else
            obj.pverbose('%sGetting results as a function of the complex functional %s.\n',sprintf(repmat('\t',1,singleUntilStep)),getAsFuncOf);
            
            r_f             = cell(length(z_cum{stopFncAtStep}.(getAsFuncOf)),1);
            f_f             = cell(length(z_cum{stopFncAtStep}.(getAsFuncOf)),1);
            id_cum_f        = cell(length(z_cum{stopFncAtStep}.(getAsFuncOf)),1);
            z_cum_ret_f     = cell(length(z_cum{stopFncAtStep}.(getAsFuncOf)),1);
            z_step_ret_f    = cell(length(z_cum{stopFncAtStep}.(getAsFuncOf)),1);
        
            for ii=1:length(z_cum{stopFncAtStep}.(getAsFuncOf))
                z_cum_f     = z_cum;
                z_step_f    = z_step;

                if obj.verbose
                    fprintf('%s%s = %s.\n',sprintf(repmat('\t',1,singleUntilStep)),getAsFuncOf,num2str(z_cum{stopFncAtStep}.(getAsFuncOf){ii}));
                end

                for uu=1:length(z_cum_f)
                    if isfield(z_cum_f{uu},getAsFuncOf)
                        z_cum_f{uu}.(getAsFuncOf)  = z_cum{stopFncAtStep}.(getAsFuncOf){ii};
                    end
                end

                for uu=1:length(z_step_f)
                    if isfield(z_step_f{uu},getAsFuncOf)
                        z_step_f{uu}.(getAsFuncOf) = z_cum{stopFncAtStep}.(getAsFuncOf){ii};
                    end
                end
                [r_f{ii},id_cum_f{ii},f_f{ii},z_cum_ret_f{ii},z_step_ret_f{ii}] = getAll(obj,name,z_cum_f,z_step_f,singleUntilStep+1,stopFncAtStep,lastStepInSequence,r,id_cum);                
            end
            f.sub     = f_f{1};
        end
        
        %% The part after
        if stopFncAtStep < stopAtStep
            error('I think the code you are about to use is very old and should be checked!');
        else
            r           = r_f;
            id_cum      = id_cum_f;
        end
    end
    
    

    if stopAtStep == lastStepInSequence
        % At the end throw away all the stuff in the r object that
        % is not required for further steps anymore.
        if ~iscell(r)
            for oo=1:length(name)
                if isfield(r,name{oo})
                    rn.(name{oo})   = r.(name{oo});
                else
                    error('The requested output (%s) is not part of variable r. Which is weird!',name);
                end
            end
        end 
        r   = rn;
    end
end