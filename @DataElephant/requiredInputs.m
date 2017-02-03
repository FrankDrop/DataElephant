function requiredInputs(obj,output)

    updateTree(obj,output);
    
    fprintf('%% Required\n');
    reachedStep = false;
    kk = 1;
    while ~reachedStep
        for oo=1:length(obj.steps(kk).input)
           fprintf('z.%s%s\t\t= '''';\n',obj.steps(kk).input{oo},repmat(' ',1,15-length(obj.steps(kk).input{oo})));
        end
        if any(strcmp(obj.steps(kk).output,output))
            reachedStep = true;
        end
        kk=kk+1;
    end
    
    fprintf('%% Optional\n');
    reachedStep = false;
    kk = 1;
    while ~reachedStep
        for oo=1:length(obj.steps(kk).optional)
           fprintf('z.%s%s\t\t= '''';\n',obj.steps(kk).optional{oo},repmat(' ',1,15-length(obj.steps(kk).optional{oo})));
        end
        if any(strcmp(obj.steps(kk).output,output))
            reachedStep = true;
        end
        kk=kk+1;
    end
end