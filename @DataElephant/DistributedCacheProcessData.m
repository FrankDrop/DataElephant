function obj = DistributedCacheProcessData(obj,varargin)
    while true

        pause(1);
        
        % TODO : Include a lock on the dist folder. Choose the
        % first file, load it, move it, then give up the lock for
        % the next process to act on the folder...


        % First get a lock on the entire folder where the
        % assignments are stored.
        if processFilesInFolder(obj.myhostname)
            continue;
        end
        
        foldersWithHostName     = dir([obj.getDistFolder() '/*' obj.myhostname '*']);                
        for oo=1:length(foldersWithHostName)
            hostsInFolderName = regexp(foldersWithHostName(oo).name,'_','split');
            if any(strcmpi(obj.myhostname,hostsInFolderName))
                if processFilesInFolder(foldersWithHostName(oo).name)
                    continue;
                end
            end
        end
        
        if processFilesInFolder('all')
            continue;
        end

        % Just to make sure we do not keep locks on files we aren't using
        % anymore we release all the locks we have.
        releaseAllLocks(obj,true);
    end
    
    function foundAny = processFilesInFolder(folder)
        
        %Define some useful folder names
        datafolder      = [obj.getDistFolder() '/' folder];
        workfolder      = [datafolder '/work'];
        donefolder      = [datafolder '/done'];
        
        
%         if obj.verbose
%             fprintf('\nGoing to process files in folder %s. Waiting for a lock... ',datafolder)
%         end
        
        getLock(obj,datafolder,true);
        
%         if obj.verbose
%             fprintf('I got it!',datafolder)
%         end
        
        files = dir([datafolder '/*.mat']);
        
        foundAny = false;
        
        if ~isempty(files)
            i_file          = 1;
            fnm             = files(i_file).name;
            
            datafilename    = [datafolder '/' files(i_file).name];
            workfilename    = [workfolder '/' files(i_file).name];
            donefilename    = [donefolder '/' files(i_file).name];

            if ~exist(workfolder,'dir')
                mkdir(workfolder);
            end
            
            if ~exist(donefolder,'dir')
                mkdir(donefolder);
            end

            if ~getLock(obj,datafilename,false)
                % If we don't get the lock on this file, it must be because
                % some other process already got a lock on this file. We
                % should not keep waiting, but just look for another file
                % to process. We release the lock on the folder and return.
                releaseLock(obj,datafolder,true);
                return;
            end
            getLock(obj,workfilename,true);

            try
                [s,~] = movefile(datafilename,workfilename);
            catch ee
                fprintf('\nThere was an error moving %s to %s:\n%s',datafilename,workfilename,ee.message);
                s = 0;
            end

            % We successfully moved the assignment file, so we can
            % now release the lock on the distributed assignment 
            % folder.

            releaseLock(obj,datafolder,true);
            releaseLock(obj,datafilename,true);

            if s == 1
                loadsuccess = false;
                triesLeft   = 10;
                while ~loadsuccess && triesLeft > 0
                    try
                        iter = load(workfilename);
                        loadsuccess = true;
                    catch e
                        triesLeft = triesLeft -1;
                        fprintf('\nERROR loading work file (%i tries left...) : %s.\n',e.message,triesLeft);
                        pause(5);
                    end
                end

                zfields = fieldnames(iter.z);
                argumentstring = '';
                for hh=1:length(zfields)
                    if iscell(iter.z.(zfields{hh}))
                        val = sprintf('cell(%s)',num2str(size(iter.z.(zfields{hh}))));
                    elseif ischar(iter.z.(zfields{hh}))
                        val = sprintf('''%s''',iter.z.(zfields{hh}));
                    elseif isscalar(iter.z.(zfields{hh}))
                        val = sprintf('%s',num2str(iter.z.(zfields{hh})));
                    elseif isvector(iter.z.(zfields{hh}))
                        val = sprintf('vector(%s)',num2str(size(iter.z.(zfields{hh}))));
                    elseif ismatrix(iter.z.(zfields{hh}))
                        val = sprintf('matrix(%s)',num2str(size(iter.z.(zfields{hh}))));
                    end
                    argumentstring = [argumentstring '''' zfields{hh} ''',' val ',']; %#ok<AGROW>
                    if mod(hh,6) == 0
                        argumentstring = [argumentstring '\n\t']; %#ok<AGROW>
                    end
                end

                if mod(hh,6) == 0
                    argumentstring = argumentstring(1:(end-5));
                else
                    argumentstring = argumentstring(1:(end-1));
                end

                if obj.flock
                    fprintf('\nMy ID is %s.',obj.myid);
                end
                fprintf('\n%s - %s\\ %s\nx = CacheProcessData5(%s);\nx.get(%s,%s);\n',datestr(now),folder,fnm,func2str(iter.process),iter.name,sprintf(argumentstring));

                setProcessHandle(obj,iter.process);
                init(obj,varargin{:});
                try
                    get(obj,iter.name,iter.z);
                    foundAny = true;
                    
                    % After successfully processing this file we move it to
                    % the done folder.
                    getLock(obj,donefilename,true);
                    try
                        movefile(workfilename,donefilename);
                    catch ee
                        fprintf('\nThere was an error moving %s to %s:\n%s',workfilename,donefilename,ee.message);
                    end
                    releaseLock(obj,donefilename,true);
                catch ee
                    if obj.continueonerror
                        fprintf('\nThis get() call failed because of an error:\n%s\n\n',ee.message);
                    else
                        rethrow(ee)
                    end
                end
                % Issue a close all to prevent the funcverbose option to
                % create a huge amount of figures crashing the system.
                close all
            end

            releaseLock(obj,workfilename,true);
        else
            releaseLock(obj,datafolder,true);
        end
    end
end