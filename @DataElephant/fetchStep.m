function r_n = fetchStep(obj,~,z_cum,z_step,r,hash,stepnr,lastStepInSequence)
    
    gotWhatWeWant   = false;
    submittedBefore = false;
    
    pauseSequence   = [3 3 3 5 5 5];
    hhh             = 1;
    n               = 0;

    while ~gotWhatWeWant
        [~,r_n,~,~] = checkOrSelectByHash(obj,hash,[],stepnr,lastStepInSequence,false);

        assert(iscell(r_n),'Big error!');
        r_n = r_n{1};
        
        if isempty(r_n)
            
            someNameOfThisStep  = obj.steps(stepnr).output{1}; % We have to request an output of this particular step, because z_cum contains the input arguments up to this step only.
            goodToGo = canCalcOnThisHost(obj,stepnr,someNameOfThisStep,z_cum,submittedBefore);
            
            if goodToGo == 1
                r_n = calcNewStep(obj,z_cum,z_step,r,hash,stepnr,lastStepInSequence);
                gotWhatWeWant = true;
            elseif goodToGo == 2
                % We submitted to the host. We wait and then check again
                % for availability on the cache.
                submittedBefore = true;
                obj.pverbose(repmat('\b',1,n))
                msg = sprintf('At %s the results were not there yet, waiting for %i seconds. Press ctrl+c to stop waiting.\r',datestr(now),pauseSequence(hhh));
                n=numel(msg);
                obj.pverbose(msg);
                pause(pauseSequence(hhh))
                hhh = min([hhh+1 length(pauseSequence)]);
            else
                error(['I (%s) can''t calculate this result on this host (%s) and you don''t want me to submit to other hosts.' ...
                       'Use get(name,args,''sth'',''y'') to submit to hosts. Also make sure that load_hdd is true.'],...
                       obj.myhostname,sprintf('%s\b\b',sprintf('%s, ',obj.steps(stepnr).hosts{:})));
            end
        else
            gotWhatWeWant = true;
        end
    end
end