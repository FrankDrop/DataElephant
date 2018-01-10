function [z,z_nuf] = args(varargin)

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
    
    idx     = cellfun(@(x)ischar(x) && strcmp(x,'*'),varargin,'UniformOutput',false);
    idx     = [idx{:}];
    
    if any(idx)
        z_nuf   = varargin{find(idx)+1};
        
        varargin(find(idx):(find(idx)+1))   = [];
    else
        z_nuf   = [];
    end
    
    for oo=1:2:length(varargin)
        z.(varargin{oo}) = varargin{oo+1};
    end
    
end