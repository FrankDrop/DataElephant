function obj = setProcessHandle(obj,fH)
    obj.fHandle     = fH;
    if ~isempty(obj.fHandle)
        fDir = dir(which(func2str(obj.fHandle)));
        if isempty(fDir)
            error('The process or single step function %s does not exist.',func2str(obj.fHandle))
        end
    else
        error('You have to provide a handle to a process or a single step function.');
    end
end