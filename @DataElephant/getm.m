function varargout = getm(obj,names,z)
    
    getNames    = regexp(names,',','split');
    varargout   = cell(length(getNames),1);
    
    if nargout ~= length(getNames)
        error('Provide as many output variables as data you request.');
    end
    
    for oo=1:length(getNames)
        varargout{oo}   = get(obj,getNames{oo},z);
    end
end