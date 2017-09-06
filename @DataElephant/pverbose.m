function pverbose(obj,varargin)
    if obj.verbose
        fprintf(varargin{:});
    end
end

