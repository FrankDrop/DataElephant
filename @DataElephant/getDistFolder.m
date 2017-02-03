function rootfolder = getDistFolder(obj)
    if ispc
        rootfolder = obj.distfolder;
    elseif isunix
        rootfolder = obj.unix_distfolder;
    else
        error('This machine is not running Windows nor UNIX?');
    end
end