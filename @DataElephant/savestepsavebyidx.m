function savestepsavebyidx(obj,fnm,H) %#ok<INUSD>
    savesuccess     = false;
    while ~savesuccess
        try
            if obj.savetotemp
                tmpflname   = [obj.getTempFolder() '/' obj.myid '-temp.mat'];
                if obj.deepverbose
                    fprintf('Saving to temporary file %s.\n',tmpflname);
                end

                save(tmpflname,'-v6','H');

                src_fileMD5 = CalcMD5(tmpflname,'File','HEX');
                if obj.deepverbose
                    fprintf('Saved to temporary file %s with MD5 hash %s.\n',tmpflname,src_fileMD5);
                end

                movefile(tmpflname,fnm);
                dest_fileMD5 = CalcMD5(fnm,'File','HEX');
                if obj.deepverbose
                    fprintf('Moved temporary file %s to %s with MD5 hash %s.\n',tmpflname,fnm,dest_fileMD5);
                end

                savesuccess = strcmp(src_fileMD5,dest_fileMD5);
                if obj.deepverbose
                    fprintf('MD5 hashes are the same!\n');
                end
            else
                save(fnm,'-v6','H');
                savesuccess = true;
            end
        catch e
            fprintf('\nERROR SAVING: %s\n%s.\n',fnm,e.message);
            pause(5);
        end
    end
end