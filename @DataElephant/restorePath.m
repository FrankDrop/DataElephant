function restorePath(obj)
    if obj.verbose
        fprintf(2,'\nRestoring your original path... ');
    end
    path(obj.priorPath);
    if obj.verbose
        fprintf(2,'done.\n');
    end
end