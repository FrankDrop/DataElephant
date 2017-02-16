function z = args(varargin)

    z   = struct();
    rem = [];
    
    for oo=1:length(varargin)
        if isstruct(varargin{oo})
            z   = DataElephant.catstruct(z,varargin{oo});
            rem = [rem oo]; %#ok<AGROW>
        end
    end
    
    varargin(rem) = [];
    
    if length(varargin(1:2:end)) ~= length(unique(varargin(1:2:end)))
        [~,ia,~]    = unique(varargin(1:2:end));
        missing     = ones(length(varargin(1:2:end)),1);
        missing(ia) = 0;
        f = varargin(2*find(missing)-1);
        error('You provided inputs %s more than once.',sprintf('%s, ',f{:}));
    end
    
    for oo=1:2:length(varargin)
        z.(varargin{oo}) = varargin{oo+1};
    end
    
end