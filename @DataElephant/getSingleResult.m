function [r,rf,id_cum_s,z_cum,z_step] = getSingleResult(obj,name,z_cum,z_step,startAtStep,singleUntilStep,lastStepInSequence,r,rf,id_cum,returnMultiple,functional,minStep)

    if obj.verbose
        fprintf('%sgetSingleResult(''%s'', z_cum, z_step, startAtStep=%i, stopAtStep=%i, lastStepInSequence=%i, r, id_cum=''%s'', returnMultiple=%s, functional=''%s''); @ %s\n',...
                sprintf(repmat('\t',1,startAtStep)),sprintf('%s;',name{:}),startAtStep,singleUntilStep,lastStepInSequence,hexhash(obj,id_cum),num2str(returnMultiple),functional,datestr(now));
    end

    % First we check whether there are any decisions in this stream
    % that end with a single result. If so, we can check whether
    % this decision already exists and use it as an efficient
    % savepoint.
    
    id_req_s                = cell(singleUntilStep+1,1);
    id_dec_s                = cell(singleUntilStep+1,1);
    id_fast_s               = cell(singleUntilStep+1,1);
    
    id_req_s{startAtStep}   = id_cum;
    id_dec_s{startAtStep}   = id_cum;
    
    dataMissingAt           = singleUntilStep +1;
    startCheckingAt         = startAtStep;
    
    z_cum_unaffected        = z_cum;    % The fast decision hashes should be calculated over the unaffected arguments.
    
    cDFI       = -1*ones(singleUntilStep,1);
    
    functionalStartAt       = lastStepInSequence+1;
    functionalRange         = [];
    decisionTakenAt         = [];
    
    decisionDecidesOver     = {};
    
%%
% Let's write some super stupid code, simply to determine these variables.
% Perhaps they are already available in getAll, but nevermind.
    foundDecision = false;
    
    if ~isempty(functional)
        % We can only have one decision
        for oo=startAtStep:singleUntilStep
            if ~obj.steps(oo).type
                if foundDecision
                    error('You defined a functional decision, but there are multiple decisions in this stream.')
                end
                functionalStartAt       = oo;
                decisionTakenAt         = oo;
                decisionDecidesOver{1}  = obj.steps(oo).decide;
                decideOverRange{1}      = z_cum{oo}.(obj.steps(oo).decide);
                functionalRange         = z_cum{oo}.(functional);
                foundDecision           = true;
            end
        end
        
        if ~foundDecision
            % So apparently there is no decision to take as a function of
            % something, but just a result that needs to be calculated as a
            % function of something.
            
            for oo=startAtStep:singleUntilStep
                if any(strcmp(obj.steps(oo).input,functional)) || any(strcmp(obj.steps(oo).optional,functional))
                    functionalStartAt   = oo;
                    functionalRange     = z_cum{oo}.(functional);
                end
            end
        end
    else
        kk = 0;
        functionalStartAt   = [];
        functionalRange     = [];
        for oo=startAtStep:singleUntilStep
            if ~obj.steps(oo).type
                kk = kk + 1;
                decisionTakenAt(kk)     = oo; %#ok<AGROW>
                decisionDecidesOver{kk} = obj.steps(oo).decide; %#ok<AGROW>
            end
        end
    end
    
    decisionStartAt     = zeros(size(decisionTakenAt));
    for uu=1:length(decisionDecidesOver)
        for oo=startAtStep:singleUntilStep
            if any(strcmp(decisionDecidesOver{uu},obj.steps(oo).input)) || any(strcmp(decisionDecidesOver{uu},obj.steps(oo).optional))
                decisionStartAt(uu) = oo;
            end
        end
    end
    
%%
% Here we check, starting at the last step, whether any of the steps are
% decisions and whether they can be found under their 'fast' hash.

    if returnMultiple
        for oo=singleUntilStep:-1:(startAtStep+1)
            if ~obj.steps(oo).type % decision                
                if oo >= functionalStartAt
                    id_fast_s{oo+1} = zeros(length(functionalRange),16);
                    for uu=1:length(functionalRange)
                        z_cum_unaffected_f  = z_cum_unaffected{oo};
                        z_cum_unaffected_f.(functional)     = z_cum_unaffected{oo}.(functional){uu};
                        id_fast_s{oo+1}(uu,:) = generateFasthash(obj,z_cum_unaffected_f,oo);
                    end
                else
                    id_fast_s{oo+1} = generateFasthash(obj,z_cum_unaffected{oo},oo);
                end
                    
                if ~isempty(id_fast_s{oo+1})
                    if all(checkOrSelectByHash(obj,[],id_fast_s{oo+1},oo,lastStepInSequence,true))
                        [~,~,dec,~]         = checkOrSelectByHash(obj,[],id_fast_s{oo+1},oo,lastStepInSequence,true);
                        id_dec_s{oo+1}      = cell2mat(dec);
                        startCheckingAt     = oo + 1;
                        break;
                    end
                end
            end
        end
    else
        for oo=singleUntilStep:-1:(startAtStep+1)
            if ~obj.steps(oo).type % decision
                id_fast_s{oo+1} = generateFasthash(obj,z_cum_unaffected{oo},oo);
                if ~isempty(id_fast_s{oo+1})
                    if all(checkOrSelectByHash(obj,[],id_fast_s{oo+1},oo,lastStepInSequence,true))
                        [~,~,dec,~]         = checkOrSelectByHash(obj,[],id_fast_s{oo+1},oo,lastStepInSequence,true);
                        id_dec_s{oo+1}      = dec{1};
                        startCheckingAt     = oo + 1;
                        break;
                    end
                end
            end
        end
    end
  
%%
    % First we check if the end result of this getSingleResult call is in
    % memory or on the hdd. We simultaneously create the required hashes.
    
    for oo=startCheckingAt:singleUntilStep
        id_req_s = nextHash(obj,z_cum,z_step,oo,id_req_s,id_dec_s,functional,functionalStartAt,decisionStartAt,decisionTakenAt,functionalRange,decisionDecidesOver);
        
        if ~obj.steps(oo).type % = decision
            if returnMultiple
                if all(checkOrSelectByHash(obj,id_req_s{oo+1},id_fast_s{oo+1},oo,lastStepInSequence,false))
                    [~,~,dec,~]         = checkOrSelectByHash(obj,id_req_s{oo+1},id_fast_s{oo+1},oo,lastStepInSequence,false);
                    id_dec_s{oo+1}      = cell2mat(dec);
                else
                    dataMissingAt = oo;
                    break;
                end
            else
                if isempty(id_fast_s{oo+1})
                    id_fast_s{oo+1}   = generateFasthash(obj,z_cum_unaffected{oo},oo);
                end

                if all(checkOrSelectByHash(obj,id_req_s{oo+1},id_fast_s{oo+1},oo,lastStepInSequence,false))
                    [~,~,dec,~]         = checkOrSelectByHash(obj,id_req_s{oo+1},id_fast_s{oo+1},oo,lastStepInSequence,false);
                    
                    if length(dec) > 1
                        error('huh?')
                    end
                    
                    id_dec_s{oo+1}      = dec{1};
                else
                    dataMissingAt = oo;
                    break;
                end
            end
        end
        
        if oo == singleUntilStep
            if ~all(checkOrSelectByHash(obj,id_req_s{oo+1},[],oo,lastStepInSequence,false))
                dataMissingAt = oo;
            end
        end
    end
    
    
%%
    % Then, starting from the last savepoint, we check if the
    % individual step results exist or not.
    
    if dataMissingAt > singleUntilStep && singleUntilStep == lastStepInSequence
        if obj.verbose
            fprintf('%sSuper, all the data was calculated before. We simply load the last result and pass it on.\n',...
                sprintf(repmat('\t',1,startAtStep)));
        end
        startCollectingAt = singleUntilStep;
    else
        startCollectingAt = startAtStep;
        
        if obj.verbose
            if dataMissingAt <= singleUntilStep
                if size(id_req_s{dataMissingAt+1},1) == 1
                    fprintf('%sData (%s/%s) is missing at step %i/%i (%s).\n',...
                        sprintf(repmat('\t',1,dataMissingAt)),...
                        hexhash(obj,id_req_s{dataMissingAt+1},2),...
                        hexhash(obj,id_req_s{dataMissingAt+1},1),...
                        dataMissingAt,singleUntilStep,obj.steps(dataMissingAt).name);
                else
                    fprintf('%sData (many) is missing at step %i/%i (%s).\n',...
                        sprintf(repmat('\t',1,dataMissingAt)),dataMissingAt,singleUntilStep,obj.steps(dataMissingAt).name);
                end
            else
                fprintf('%sThe end result is not the last step in the sequence.\n',...
                    sprintf(repmat('\t',1,dataMissingAt)));
            end
        end
        
    end
    
    % Here a little hack to ensure that we start at minstep
    startCollectingAt   = min([startCollectingAt minStep]);
    
    
    
    % So at this point we know whether we are going to collect the data
    % starting at 'singleUntilStep' or at 'startAtStep'. If we start at
    % singleUntilStep, we only have to collect one result, so we cannot
    % really speed that up. However, if we have to collect stuff at
    % startAtStep, we might load a lot of prior results associated to a
    % decision, without actually using all this data, because the decision
    % was already taken in the past. So we look through all the decisions
    % to see if they exist and then only load the data associated to the
    % taken decisions, rather than all the options.
    
    
    
    if startCollectingAt == startAtStep && ~returnMultiple
        
        % Because we are in getSingleResult, we can only have one
        % functional open at a time, and only if it is associated to a
        % decision to be taken later, right?
        
        for oo=startCollectingAt:singleUntilStep
            
            id_req_s = nextHash(obj,z_cum,z_step,oo,id_req_s,id_dec_s,functional,functionalStartAt,decisionStartAt,decisionTakenAt,functionalRange,decisionDecidesOver);
                   
            if ~obj.steps(oo).type % decision
                
                if isempty(id_dec_s{oo+1})
                    if all(checkOrSelectByHash(obj,id_req_s{oo+1},[],oo,lastStepInSequence,false))
                        [~,~,dec,~]         = checkOrSelectByHash(obj,id_req_s{oo+1},id_fast_s{oo+1},oo,lastStepInSequence,false);
                        id_dec_s{oo+1}      = dec{1};
                    else
                        break;
                    end
                end
                
                if ~isempty(id_dec_s{oo+1})
                    % Determine at what step this decision starts
                    thisStartAt     = decisionStartAt(strcmp(decisionDecidesOver,obj.steps(oo).decide));
                    
                    decisionIdx = find(all((id_req_s{oo} - repmat(id_dec_s{oo+1},size(id_req_s{oo},1),1)) == 0,2));
                    cDFI(thisStartAt:(oo-1))   = decisionIdx;
                    obj.pverbose('%sDecision at step %i is present, we will decide for %s.\n',sprintf(repmat('\t',1,oo)),oo,hexhash(obj,id_dec_s{oo+1}));
                else
                    obj.pverbose('%sDecision at step %i is not present.\n',sprintf(repmat('\t',1,oo)),oo);
                end
            end
        end
    end
    
    

    % The output fields that are added from the step where the
    % functional starts:
    fnc_output_fields   = {};
    uncalculatedResultsWithCounter = 10;
    
    decidedOver         = [];
    
    for oo=startCollectingAt:singleUntilStep
        
        id_req_s = nextHash(obj,z_cum,z_step,oo,id_req_s,id_dec_s,functional,functionalStartAt,decisionStartAt,decisionTakenAt,functionalRange,decisionDecidesOver);
        
        if size(id_req_s{oo+1},1) > 1
            if ~isempty(decisionStartAt)
                if oo >= decisionStartAt && oo < decisionTakenAt
                    t_field     = decisionDecidesOver{sum(oo >= decisionStartAt)};
                    t_values    = z_cum{decisionStartAt}.(t_field);
                    n_values    = length(t_values);
                elseif oo == decisionTakenAt
                    t_field     = functional;
                    t_values    = z_cum{oo}.(t_field);
                    n_values    = length(t_values);
                end
            else
                t_field     = functional;
                t_values    = z_cum{oo}.(t_field);
                n_values    = length(t_values);
            end
        end
        
        if obj.steps(oo).type
            
            %%%%%%%%%%%%%%%%%
            % STEP
            %%%%%%%%%%%%%%%%%
            
            if size(id_req_s{oo+1},1) > 1
                % So apparently one of the arguments is a
                % cell... but it might not be an argument in this
                % step.

%                 if isstruct(z_step{oo})
%                     t_fields    = fieldnames(z_step{oo});
%                     cell_fields = find(cellfun(@(x) iscell(z_step{oo}.(x)),t_fields));
%                 else
%                     t_fields    = {};
%                     cell_fields = [];
%                 end

%                 if length(cell_fields) > 1
%                     error('More than one field is a cell, but that is not possible.');
%                 elseif length(cell_fields) == 1
%                     t_field     = t_fields{cell_fields};
%                     
%                     t_values    = z_step{oo}.(t_field);
%                     n_values    = length(t_values);
%                     if n_values ~= size(id_req_s{oo+1},1)
%                         error('The amount of hashes to get is not equal to the amount of variables of the functional.');
%                     end
%                 elseif isempty(cell_fields)
%                     % We might get away with just leaving the
%                     % previous values unaltered?
%                     % t_field, t_values and n_values are the same
%                     % as in the previous iteration of this
%                     % for-loop.
%                     if ~returnMultiple
%                         % If we are not required to return multiple
%                         % results, we can only end up here if we need to
%                         % take a decision at some point.
%                         decisionStillToCome = false;
%                         for jjj=oo:singleUntilStep
%                             if ~obj.steps(jjj).type
%                                 decisionStillToCome = true;
%                                 continue;
%                             end
%                         end
%                         if ~decisionStillToCome
%                             error('We ended up here but there is no decision left to take. This is not right.');
%                         end
%                     else
%                         t_field     = functional;
%                         t_values    = z_cum{oo}.(t_field);
%                         n_values    = length(t_values);
%                     end
%                     
%                     if n_values ~= size(id_req_s{oo+1},1)
%                         error('The amount of hashes to get is not equal to the amount of variables of the functional.');
%                     end
%                 end
                
                % Save the r object into r_prev to avoid confusion by the
                % current step. For example, if the current step checks whether
                % a certain result field it wants to add already exists in
                % the r object.
                
                r_prev  = r;
                rf_prev = rf;

                new_output_fields = obj.steps(oo).output;
                for bb=1:length(new_output_fields)
                    r.(new_output_fields{bb})   = cell(size(id_req_s{oo+1},1),1);
                end
                fnc_output_fields = [fnc_output_fields; new_output_fields]; %#ok<AGROW>

                if cDFI(oo) > 0
                    
                    r_o         = cell(size(id_req_s{oo+1},1),1);
                    chklst      = zeros(size(id_req_s{oo+1},1),1);
                    
                    if obj.steps(oo).saveme || obj.steps(oo).memorizeme
                        [~,r_o(cDFI(oo)),~,chklst(cDFI(oo))]        = checkOrSelectByHash(obj,id_req_s{oo+1}(cDFI(oo),:),[],oo,lastStepInSequence,false);
%                         r_o(cDFI(oo))   = r_only;
                    end
                    
                    if ~chklst(cDFI(oo))
                        pauseSequence   = [1 1 1 3 3 3 5 5 5];
                        hhh             = 1;
                        n               = 0;
                        
                        goodToGo        = canCalcOnThisHost(obj,oo,z_cum{oo},false);
                        gotWhatWeWant   = false;
                        if goodToGo == 1 % We can calculate it all by ourselves!
                            gotWhatWeWant = true;
                        elseif goodToGo == 0 % We cant submit and cant calculate ourselves... :(
                            error('I can''t calculate this result on this host and you don''t want me to submit to other hosts. Use get(name,args,''sth'',''y'') to submit to hosts.');
                        end
                        
                        while ~gotWhatWeWant
                            [~,r_o{cDFI(oo)},~,chklst(cDFI(oo))]        = checkOrSelectByHash(obj,id_req_s{oo+1}(cDFI(oo),:),[],oo,lastStepInSequence,false);
                    
                            if ~chklst(cDFI(oo))
                                % We submitted to the host. We wait and then check again
                                % for availability on the cache.
                                obj.pverbose(repmat('\b',1,n))
                                msg = sprintf('At %s, %i out of %i results were not there yet, waiting for %i seconds. Press ctrl+c to stop waiting.\r',...
                                    datestr(now),1,1,pauseSequence(hhh));
                                n = numel(msg);
                                obj.pverbose(msg);
                                pause(pauseSequence(hhh))
                                hhh = min([hhh+1 length(pauseSequence)]);
                            else
                                gotWhatWeWant = true;
                            end
                        end
                    end
                    
                    for uu=cDFI(oo)
                        if isempty(r_o{uu})
                            % In the cumulative z argument, the field
                            % of the functional has to be in there.
                            z_cum_f             = z_cum{oo};
                            z_cum_f.(t_field)   = t_values{uu};

                            % In the step z argument, the field of the
                            % functional might not be in there, if the
                            % functional was started in a previous
                            % step.
                            z_step_f            = z_step{oo};
                            if isfield(z_step_f,t_field)
                                z_step_f.(t_field)  = t_values{uu};
                            end

                            if ~isempty(decidedOver)
                                if isfield(z_cum_f,decidedOver)
                                    if iscell(z_cum_f.(decidedOver))
                                        if length(z_cum_f.(decidedOver)) == size(id_req_s{oo+1},1)
                                            z_cum_f.(decidedOver) = z_cum_f.(decidedOver){uu};
                                        else
                                            error('boo!')
                                        end
                                    end
                                end                                
                                if isfield(z_step_f,decidedOver)
                                    if iscell(z_step_f.(decidedOver))
                                        if length(z_step_f.(decidedOver)) == size(id_req_s{oo+1},1)
                                            z_step_f.(decidedOver) = z_step_f.(decidedOver){uu};
                                        else
                                            error('boo!')
                                        end
                                    end
                                end
                            end

                            r_i         = obj.getIndividual(r_prev,rf_prev,fnc_output_fields,t_field,uu,size(id_req_s{oo+1},1));

                            % After we've taken a decision, we assume all
                            % the new data to be truely new. However, if
                            % the decision decided for the same result
                            % twice or more, we will get the same result
                            % multiple times and we run into issues with
                            % the unique hashes....

                            if ~isempty(decidedOver)
                                r_o{uu}     =   fetchStep(obj, z_cum_f, z_step_f, r_i ,id_req_s{oo+1}(uu,:), oo, lastStepInSequence);
                            else
                                r_o{uu}     = calcNewStep(obj, z_cum_f, z_step_f, r_i ,id_req_s{oo+1}(uu,:), oo, lastStepInSequence,uu == 1);
                            end
                        end

                        for bb=1:length(new_output_fields)
                            if isfield(r_o{uu},new_output_fields{bb})
                                r.(new_output_fields{bb}){uu}       = r_o{uu}.(new_output_fields{bb});
                                rf.(new_output_fields{bb}).f        = t_field;
                            end
                        end
                    end
                else
                    obj.pverbose('%sGetting %i possible previous results at %i (%s) from memory or HDD.\n',sprintf(repmat('\t',1,oo)),size(id_req_s{oo+1},1),oo,obj.steps(oo).name);
                                        
                    add_alloc(obj,size(id_req_s{oo+1},1),oo);
                    
                    [~,r_o,~,chklst]        = checkOrSelectByHash(obj,id_req_s{oo+1},[],oo,lastStepInSequence,false);
                    uncalculatedResults     = sum(~chklst);
                    
                    if uncalculatedResults > 0                        
                        pauseSequence   = [1 1 1 3 3 3 5 5 5];
                        hhh             = 1;
                        n               = 0;
                        
                        goodToGo        = canCalcOnThisHost(obj,oo,z_cum{oo},false);
                        gotWhatWeWant   = false;
                        if goodToGo == 1 % We can calculate it all by ourselves!
                            gotWhatWeWant = true;
                        elseif goodToGo == 0 % We cant submit and cant calculate ourselves... :(
                            error('I can''t calculate this result on this host and you don''t want me to submit to other hosts. Use get(name,args,''sth'',''y'') to submit to hosts.');
                        end
                        
                        while ~gotWhatWeWant
                            [~,r_o,~,chklst]        = checkOrSelectByHash(obj,id_req_s{oo+1},[],oo,lastStepInSequence,false);
                            uncalculatedResults     = sum(~chklst);
                    
                            if uncalculatedResults > 0
                                % We submitted to the host. We wait and then check again
                                % for availability on the cache.
                                obj.pverbose(repmat('\b',1,n))
                                msg = sprintf('At %s, %i out of %i results were not there yet, waiting for %i seconds. Press ctrl+c to stop waiting.\r',...
                                    datestr(now),uncalculatedResults,length(chklst),pauseSequence(hhh));
                                n = numel(msg);
                                obj.pverbose(msg);
                                pause(pauseSequence(hhh))
                                hhh = min([hhh+1 length(pauseSequence)]);
                            else
                                gotWhatWeWant = true;
                            end
                        end
                    end
                    
                    
                    
                    if obj.verbose && uncalculatedResults > uncalculatedResultsWithCounter
                        fprintf('%sGoing to calculate (or fetch, if we just submitted) the remaining %i results. Going to count till 10: ',...
                            sprintf(repmat('\t',1,oo)),uncalculatedResults);
                        calculatedResults   = 0;
                    end
                    
                    

                    for uu=1:size(id_req_s{oo+1},1)
                        if isempty(r_o{uu})
                            % In the cumulative z argument, the field
                            % of the functional has to be in there.
                            z_cum_f             = z_cum{oo};
                            z_cum_f.(t_field)   = t_values{uu};

                            % In the step z argument, the field of the
                            % functional might not be in there, if the
                            % functional was started in a previous
                            % step.
                            z_step_f            = z_step{oo};
                            if isfield(z_step_f,t_field)
                                z_step_f.(t_field)  = t_values{uu};
                            end
                            
                            if ~isempty(decidedOver)
                                if isfield(z_cum_f,decidedOver)
                                    if iscell(z_cum_f.(decidedOver))
                                        if length(z_cum_f.(decidedOver)) == size(id_req_s{oo+1},1)
                                            z_cum_f.(decidedOver) = z_cum_f.(decidedOver){uu};
                                        else
                                            error('boo!')
                                        end
                                    end
                                end                                
                                if isfield(z_step_f,decidedOver)
                                    if iscell(z_step_f.(decidedOver))
                                        if length(z_step_f.(decidedOver)) == size(id_req_s{oo+1},1)
                                            z_step_f.(decidedOver) = z_step_f.(decidedOver){uu};
                                        else
                                            error('boo!')
                                        end
                                    end
                                end
                            end

                            r_i         = obj.getIndividual(r_prev,rf_prev,fnc_output_fields,t_field,uu,size(id_req_s{oo+1},1));
                            
                            % After we've taken a decision, we assume all
                            % the new data to be truely new. However, if
                            % the decision decided for the same result
                            % twice or more, we will get the same result
                            % multiple times and we run into issues with
                            % the unique hashes....
                            
                            if ~isempty(decidedOver)
                                r_o{uu}     =   fetchStep(obj, z_cum_f, z_step_f, r_i ,id_req_s{oo+1}(uu,:), oo, lastStepInSequence);
                            else
                                r_o{uu}     = calcNewStep(obj, z_cum_f, z_step_f, r_i ,id_req_s{oo+1}(uu,:), oo, lastStepInSequence,uu == 1);
                            end

                            if obj.verbose && uncalculatedResults > uncalculatedResultsWithCounter
                                calculatedResults = calculatedResults + 1;
                                if floor(calculatedResults / uncalculatedResults * 10) ~= floor((calculatedResults -1)/ uncalculatedResults * 10)
                                    fprintf('%i ',floor(calculatedResults / uncalculatedResults * 10));
                                end
                            end
                        end

                        for bb=1:length(new_output_fields)
                            if isfield(r_o{uu},new_output_fields{bb})
                                r.(new_output_fields{bb}){uu}       = r_o{uu}.(new_output_fields{bb});
                                rf.(new_output_fields{bb}).f        = t_field;
                            end
                        end
                    end

                    if obj.verbose && uncalculatedResults > uncalculatedResultsWithCounter
                        fprintf('.\n');
                    end

                    revertAlloc(obj);
                end
            else
                if obj.verbose
                    fprintf('%sGetting single result at %i (%s) : %s.\n',sprintf(repmat('\t',1,oo)),oo,obj.steps(oo).name,hexhash(obj,id_req_s{oo+1}));
                end
                r = obj.addIndividual(r, fetchStep(obj,z_cum{oo},z_step{oo},r,id_req_s{oo+1},oo,lastStepInSequence), []);
            end
        else
            
            %%%%%%%%%%%%%%%%%
            % DECISION
            %%%%%%%%%%%%%%%%%
            
            
            if size(id_req_s{oo+1},1) > 1                
%                 if isstruct(z_step{oo})
%                     t_fields    = fieldnames(z_step{oo});
%                     cell_fields = find(cellfun(@(x) iscell(z_step{oo}.(x)),t_fields));
%                 else
%                     t_fields    = {};
%                     cell_fields = [];
%                 end
% 
%                 
%                 
%                 if length(cell_fields) > 1
%                     error('More than one field is a cell, but that is not possible.');
%                 elseif length(cell_fields) == 1
%                     t_field     = t_fields{cell_fields};
%                     
%                     t_values    = z_step{oo}.(t_field);
%                     n_values    = length(t_values);
%                     if n_values ~= size(id_req_s{oo+1},1)
%                         error('The amount of hashes to get is not equal to the amount of variables of the functional.');
%                     end
%                 elseif isempty(cell_fields)
%                     % We might get away with just leaving the
%                     % previous values unaltered?
%                     % t_field, t_values and n_values are the same
%                     % as in the previous iteration of this
%                     % for-loop.
%                     if ~returnMultiple
%                         % If we are not required to return multiple
%                         % results, we can only end up here if we need to
%                         % take a decision at some point.
%                         decisionStillToCome = false;
%                         for jjj=oo:singleUntilStep
%                             if ~obj.steps(jjj).type
%                                 decisionStillToCome = true;
%                                 continue;
%                             end
%                         end
%                         if ~decisionStillToCome
%                             error('We ended up here but there is no decision left to take. This is not right.');
%                         end
%                     else
%                         t_field     = functional;
%                         t_values    = z_cum{oo}.(t_field);
%                         n_values    = length(t_values);
%                     end
%                     
%                     if n_values ~= size(id_req_s{oo+1},1)
%                         error('The amount of hashes to get is not equal to the amount of variables of the functional.');
%                     end
%                 end
                
                
                decide_output_fields    = [];
                yyy                     = oo;
                foundDecision           = false;
                while ~foundDecision
                    decide_output_fields    = [decide_output_fields; obj.steps(yyy).output]; %#ok<AGROW>
                    foundDecision           = any(strcmp(obj.steps(oo).decide,obj.steps(yyy).input)) || any(strcmp(obj.steps(oo).decide,obj.steps(yyy).optional));
                    yyy = yyy-1;
                end
                
                r_n         = r;
                rf_n        = rf;
                z_cum_n     = z_cum;
                z_step_n    = z_step;
                
                for nn=1:length(z_cum_n)
                    if isfield(z_cum_n{nn},obj.steps(oo).decide)
                        z_cum_n{nn}.(obj.steps(oo).decide) = cell(size(id_req_s{oo+1},1),1);
                    end
                end
                
                for nn=1:length(z_step_n)
                    if isfield(z_step_n{nn},obj.steps(oo).decide)
                        z_step_n{nn}.(obj.steps(oo).decide) = cell(size(id_req_s{oo+1},1),1);
                    end
                end
                
                for bb=1:length(decide_output_fields)
                    r_n.(decide_output_fields{bb})    = cell(size(id_req_s{oo+1},1),1);
                end
             
                if obj.verbose
                    fprintf('%sWe need to take a decision %i times at %i (%s) as a function of %s.\n',...
                        sprintf(repmat('\t',1,oo)),size(id_req_s{oo+1},1),oo,obj.steps(oo).name,functional);
                end
                
                [z_dec_o,r_o,dec_o,chklst]  = checkOrSelectByHash(obj,id_req_s{oo+1},[],oo,lastStepInSequence,false);
                uncalculatedResults         = sum(~chklst);
                
                if obj.verbose && uncalculatedResults > uncalculatedResultsWithCounter
                    fprintf('%sGoing to calculate (or fetch, if we just submitted) the remaining %i decisions. Going to count till 10: ',...
                        sprintf(repmat('\t',1,oo)),uncalculatedResults);
                    calculatedResults   = 0;
                end
                
                for uu=1:size(id_req_s{oo+1},1)
                    if isempty(dec_o{uu})
                        
                        z_cum_f             = z_cum{oo};
                        z_cum_f.(t_field)   = t_values{uu};

                        z_step_f            = z_step{oo};
                        if isfield(z_step_f,t_field)
                            z_step_f.(t_field)  = t_values{uu};
                        end
                        
                        [dec_o{uu},z_dec_o{uu}] = calcNewDecision(obj,z_cum_f,z_step_f,r,id_req_s{oo+1}(uu,:),id_fast_s{oo+1}(uu,:),id_req_s{oo},oo,lastStepInSequence);
                        
                        t_dec_idx           = find(all((id_req_s{oo} - repmat(dec_o{uu},size(id_req_s{oo},1),1)) == 0,2));
                        [r_o{uu},~]         = obj.getIndividual(r, rf, fieldnames(r), obj.steps(oo).decide, t_dec_idx, size(id_req_s{oo},1)); %#ok<FNDSB>

                        if obj.verbose && uncalculatedResults > uncalculatedResultsWithCounter
                            calculatedResults = calculatedResults + 1;
                            if floor(calculatedResults / uncalculatedResults * 10) ~= floor((calculatedResults -1)/ uncalculatedResults * 10)
                                fprintf('%i ',floor(calculatedResults / uncalculatedResults * 10));
                            end
                        end
                    end

                    for bb=1:length(decide_output_fields)
                        if isfield(r_o{uu},decide_output_fields{bb})
                            r_n.(decide_output_fields{bb}){uu}      = r_o{uu}.(decide_output_fields{bb});
                            rf_n.(decide_output_fields{bb}).f       = t_field;
                        end
                    end
                    
                    for nn=1:length(z_cum_n)
                        if isfield(z_cum_n{nn},obj.steps(oo).decide)
                            z_cum_n{nn}.(obj.steps(oo).decide){uu} = z_dec_o{uu}.(obj.steps(oo).decide);
                        end
                    end

                    for nn=1:length(z_step_n)
                        if isfield(z_step_n{nn},obj.steps(oo).decide)
                            z_step_n{nn}.(obj.steps(oo).decide){uu} = z_dec_o{uu}.(obj.steps(oo).decide);
                        end
                    end
                end

                if obj.verbose && uncalculatedResults > uncalculatedResultsWithCounter
                    fprintf('.\n');
                end

                id_dec_s{oo+1}  = cell2mat(dec_o); % Just a guess...
                z_cum           = z_cum_n;
                z_step          = z_step_n;
                r               = r_n;
                rf              = rf_n;
                
                decidedOver     = obj.steps(oo).decide;
                
                revertAlloc(obj);
            else
                if isempty(id_fast_s{oo+1})
                    id_fast_s{oo+1} = generateFasthash(obj,z_cum_unaffected{oo},oo);
                end

                if obj.verbose
                    fprintf('%sWe need to take a decision at %i (%s) : %s / F:%s.\n',sprintf(repmat('\t',1,oo)),oo,obj.steps(oo).name,hexhash(obj,id_req_s{oo+1}),hexhash(obj,id_fast_s{oo+1}));
                end

                [r,rf,id_dec_s{oo+1},z_dec]    = fetchDecision(obj,z_cum{oo},z_step{oo},r,rf,id_req_s{oo+1},id_fast_s{oo+1},id_req_s{oo},oo,lastStepInSequence);                    

                for nn=1:length(z_cum)
                    if isfield(z_cum{nn},(obj.steps(oo).decide))
                        z_cum{nn}.(obj.steps(oo).decide)    = z_dec.(obj.steps(oo).decide);
                    end
                end

                for nn=1:length(z_step)
                    if isfield(z_step{nn},(obj.steps(oo).decide))
                        z_step{nn}.(obj.steps(oo).decide)   = z_dec.(obj.steps(oo).decide);
                    end
                end

                obj.pverbose('%sWe decided for : %s with fast hash %s.\n',sprintf(repmat('\t',1,oo)),hexhash(obj,id_dec_s{oo+1}),hexhash(obj,id_fast_s{oo+1}));
            end
        end
        
        % After performing a step, we get rid of all the data that is
        % standing around in memory, slowing down everything we do. The
        % data is either saved or thrown away.
        
        % Before saving, first check if everything went alright.
        
        uniqueHashes(obj,true);
        if obj.fileverbose
            fprintf('%sAbout to command data for step %i to be saved.\n',sprintf(repmat('\t',1,oo)),oo);
        end
        savestep(obj,oo,true);
    end
    
    assert(returnMultiple || size(id_req_s{oo+1},1) == 1,'Not good!');

    id_cum_s    = id_req_s{oo+1};    
    
    if obj.verbose
        fprintf('%sLeaving getSingleResult().\n',sprintf(repmat('\t',1,startAtStep)))
    end

    if singleUntilStep == lastStepInSequence
        % At the end throw away all the stuff in the r object that
        % is not required for further steps anymore.

        
        if ~iscell(r)
            for oo=1:length(name)
                if isfield(r,name{oo})
                    rn.(name{oo})   = r.(name{oo});
                else
%                     error('The requested output (%s) is not part of variable r. Which is weird!',name{oo});
                end
            end
            r   = rn;
        end
    end
end