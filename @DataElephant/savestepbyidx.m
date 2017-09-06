function savestepbyidx(obj,fldr,idx)

%     tic
    if (obj.sql)
%         dbname  = 'DataElephant';
        dbname  = 'DataElephant';
        tblname = 'DataElephant';
        
        if ~strcmp(dbname,':memory:')
            try
                sqlite3.open([fldr '/' dbname '.db']);
            catch 
                mkdir(fldr);
                sqlite3.open([fldr '/' dbname '.db']);
            end
        else
            sqlite3.open(dbname);
        end
        
%         try 
%             
% %             tmpdata = getByteStreamFromArray(obj.data(idx(1)));
%             
%             result = sqlite3.execute(['PRAGMA TABLE_INFO(' tblname ')']);
%             if isempty(result)
%                 sqlite3.execute('PRAGMA page_size=1024');
%                 sqlite3.execute('PRAGMA cache_size=10000');
%                 sqlite3.execute('PRAGMA synchronous = OFF');
%                 sqlite3.execute('PRAGMA journal_mode = MEMORY');
%                 tmpdata = getByteStreamFromArray(obj.data(idx(1)));
%                 sqlite3.execute(['CREATE TABLE ' tblname '(hash bigint NOT NULL PRIMARY KEY, data blob(' num2str(int32(length(tmpdata)*1.5)) '))']);
%             end
%             sqlite3.execute('BEGIN');
%             for ii = 1:length(idx)
%                 tmpdata = getByteStreamFromArray(obj.data(idx(ii)));
% %                 size(tmpdata)
%                 sqlite3.execute(['INSERT INTO ' tblname ' (hash, data) VALUES (?,?);'],obj.shorthash(idx(ii),:),tmpdata);
%             end
%             sqlite3.execute('COMMIT');
% %             sqlite3.execute('VACUUM');
%             sqlite3.close();
%         catch e
%             sqlite3.close();
%             fprintf('Error: %s. %s \n',e.message,[fldr '/DataElephant.db']);
%         end
        
        try
            result = sqlite3.execute(['PRAGMA TABLE_INFO(' tblname ')']);
            if isempty(result)
                sqlite3.execute('PRAGMA page_size=1024');
                sqlite3.execute('PRAGMA cache_size=10000');
                sqlite3.execute('PRAGMA synchronous = OFF');
                sqlite3.execute('PRAGMA journal_mode = MEMORY');
                sqlite3.execute(['CREATE TABLE ' tblname '(hash bigint NOT NULL PRIMARY KEY, id bigint)']);
            end
            
            fl = fopen([fldr '/test.dat'],'a');
            
            sqlite3.execute('BEGIN');
            for ii = 1:length(idx)
                sqlite3.execute(['INSERT INTO ' tblname ' (hash, id) VALUES (?,?);'],obj.shorthash(idx(ii),:),idx(ii));
                fwrite(fl,getByteStreamFromArray(obj.data(idx(ii))));
            end
            sqlite3.execute('COMMIT');
            sqlite3.close();
            fclose(fl);
        catch e
            sqlite3.close();
            fprintf('Error: %s. %s \n',e.message,[fldr '/DataElephant.db']);
        end
    end
    
%     toc
    
    
%     tic
    getLock(obj,fldr,true);     % Get a lock on the folder we are going to write to.

    if ~exist(fldr,'dir')
        try
            mkdir(fldr);
        catch ee
            fprintf('Error creating folder %s.\n',fldr);
            rethrow(ee);
        end
        if obj.fileverbose
            fprintf('Created directory %s.\n',fldr);
        end
    end

    D_files   = dir([fldr '/D_*.mat']);
    N_files   = dir([fldr '/N_*.mat']);

    if isempty(D_files) && isempty(N_files)
        fileIndex   = 1;
    else
        fileIndex   = max([length(D_files) length(N_files)])+1;
    end

    itemsPerFile    = 1e4;
    startAt         = 1;

    if length(idx) > itemsPerFile
        itemsPerFile    = round(length(idx) / round(length(idx) / itemsPerFile));
    end

    while startAt <= length(idx)

        fn_D    = [fldr '/' sprintf('D_%010i.mat',fileIndex)];
        fn_N    = [fldr '/' sprintf('N_%010i.mat',fileIndex)];

        getLock(obj,fn_D,true);
        getLock(obj,fn_N,true);

        if exist(fn_D,'file')
            error('boo!');
        end

        itemsToSave     = min([itemsPerFile length(idx)-startAt]);

        if obj.fileverbose
            fprintf('Saving %i till %i.\n',idx(startAt),idx(startAt+itemsToSave))
        end

        savestepsave(obj,fn_D,obj.data(idx(startAt:(startAt+itemsToSave))));
%         tic
        savestepsave(obj,fn_N,obj.shorthash(idx(startAt:(startAt+itemsToSave)),:));
%         toc

        startAt     = startAt + itemsToSave + 1;

        releaseLock(obj,fn_D,true);
        releaseLock(obj,fn_N,true);

        fileIndex   = fileIndex + 1;
    end
    releaseLock(obj,fldr,true);

%     toc
end