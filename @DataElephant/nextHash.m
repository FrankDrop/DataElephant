function id_req_s = nextHash(obj,z_cum,z_step,stepnr,id_req_s,id_dec_s,decisionFunctional,functionalStartAt,decisionStartAt,decisionTakenAt,decisionFunctionalRange,decisionDecidesOver)
    if isempty(id_req_s{stepnr+1})
        if stepnr > 1
            if ~obj.steps(stepnr-1).type % = decision
                id_req_s{stepnr+1}      = generateHash(obj,z_cum,z_step,stepnr,id_dec_s{stepnr},...
                    decisionFunctional,functionalStartAt,decisionStartAt,decisionTakenAt,decisionFunctionalRange,decisionDecidesOver);
                                                                                               
            else
                id_req_s{stepnr+1}      = generateHash(obj,z_cum,z_step,stepnr,id_req_s{stepnr},...
                    decisionFunctional,functionalStartAt,decisionStartAt,decisionTakenAt,decisionFunctionalRange,decisionDecidesOver);
            end
        else
            id_req_s{stepnr+1}      = generateHash(obj,z_cum,z_step,stepnr,id_req_s{stepnr},...
                decisionFunctional,functionalStartAt,decisionStartAt,decisionTakenAt,decisionFunctionalRange,decisionDecidesOver);
        end
    end
end

