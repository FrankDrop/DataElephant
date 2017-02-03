function saveall(obj,removeFromMemory)
                
    if ~obj.save_hdd
        return;
    end
    
    % To make sure all the data was saved (might not be the case if ctrl+c
    % was pressed) we force a save for all steps.
    for oo=1:length(obj.steps)
        savestep(obj,oo,removeFromMemory);
    end
end