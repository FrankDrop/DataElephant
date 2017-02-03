function [] = createAliases(obj)

    updateTree(obj);
    
    for oo=1:length(obj.allOutputs)
        obj.g.(obj.allOutputs{oo}) = @(z,varargin)obj.get(obj.allOutputs{oo},z,varargin{:});
    end

end