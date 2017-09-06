function rootfolder = getTempFolder(obj)
    if ispc
        rootfolder = obj.tempfolder;
    elseif isunix
        rootfolder = obj.unix_tempfolder;
    else
        error('This machine is not running Windows nor UNIX?');
    end
end