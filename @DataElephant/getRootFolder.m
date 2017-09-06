function rootfolder = getRootFolder(obj)
    if ispc
        rootfolder = obj.rootfolder;
    elseif isunix
        rootfolder = obj.unix_rootfolder;
    else
        error('This machine is not running Windows nor UNIX?');
    end
end