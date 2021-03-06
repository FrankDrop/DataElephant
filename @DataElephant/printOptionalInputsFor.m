function printOptionalInputsFor(obj,output,varargin)

    updateTree(obj,output);
    fprintf('\n------------------------------\n');
    
    variableName    = 'z';
    if nargin == 3
        variableName    = varargin{1};
    end
    
    printUntil  = 0;
    for oo=1:length(obj.steps)
        if any(strcmp(output,obj.steps(oo).output))
            printUntil = oo;
        end
    end
    
    if printUntil == 0
        fprintf('The output %s is not generated by process %s. Did you mean %s?\n',output,obj.process.name,'Boo!');
    else
        longestInputName    = 0;
        for oo=1:printUntil
            for ii=1:length(obj.steps(oo).input)
                longestInputName = max([longestInputName length(obj.steps(oo).input{ii})]);
            end
            for ii=1:length(obj.steps(oo).optional)
                longestInputName = max([longestInputName length(obj.steps(oo).optional{ii})]);
            end
        end
           
        longestInputName = longestInputName + 2;
        
        for oo=1:printUntil            
            for ii=1:length(obj.steps(oo).input)
                fprintf('%s.%s%s= ;\n',variableName,obj.steps(oo).input{ii},sprintf('%s',repmat(' ',1,longestInputName-length(obj.steps(oo).input{ii}))));
            end
        end
        
        fprintf('\n');
        
        for oo=1:printUntil            
            for ii=1:length(obj.steps(oo).optional)
                fprintf('%s.%s%s= ;\n',variableName,obj.steps(oo).optional{ii},sprintf('%s',repmat(' ',1,longestInputName-length(obj.steps(oo).optional{ii}))));
            end
        end
    end
end

