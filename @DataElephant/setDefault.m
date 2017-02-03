function obj = setDefault(obj,varargin)
    
    obj.z_default       = obj.args(varargin{:});
    obj.defaultInputs   = fieldnames(obj.z_default);
    
    for aa=1:length(obj.defaultInputs)
        
        % Check if any of the default inputs are functionals.
        if iscell(obj.z_default.(obj.defaultInputs{aa}))

            if ~iscolumn(obj.z_default.(obj.defaultInputs{aa}))
                error('You should provide each functional as a cell column vector (%s).',obj.defaultInputs{aa});
            end

            makeFunctionalCache(obj,...
                                obj.defaultInputs{aa},...
                                obj.z_default.(obj.defaultInputs{aa}));
        end        
    end
end