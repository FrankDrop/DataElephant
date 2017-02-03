function [r_t,decision,z_dec] = fetchDecision(obj,name,z_cum,z_step,r,hash,fasthash,decision_hash,stepnr,lastStepInSequence)

    % First check if the decision is in the fast hash memory
    [z_dec,~,decision,~] = checkOrSelectByHash(obj,hash,fasthash,stepnr,lastStepInSequence,true);
    
    z_dec       = z_dec{1};
    decision    = decision{1};
    
    if isempty(decision)
        % Then check if it is in the normal memory
        
        [z_dec,~,decision,~] = checkOrSelectByHash(obj,hash,fasthash,stepnr,lastStepInSequence,false);

        z_dec       = z_dec{1};
        decision    = decision{1};
        
        if isempty(decision)
            canCalcOnThisHost(obj,stepnr,name,z_cum);
            [decision,z_dec] = calcNewDecision(obj,z_cum,z_step,r,hash,fasthash,decision_hash,stepnr,lastStepInSequence);
        end
    end
    
    idx = find(all((decision_hash - repmat(decision,size(decision_hash,1),1)) == 0,2));
    r_t = obj.getIndividual(r, fieldnames(r), obj.steps(stepnr).decide, idx, size(decision_hash,1)); %#ok<FNDSB>
end