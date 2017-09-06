function pdebug(obj,varargin)
    if obj.debug
        fprintf(varargin{:});
    end
end

