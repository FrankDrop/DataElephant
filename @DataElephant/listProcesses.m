function listProcesses()

    % We assume this is only executed on oregano.
    if ~exist('D:\Dropbox\Promoveren\matlab2\00_Code\processes','dir')
        if ~exist('O:\Code\processes','dir')
            return
        else
            fprintf('The master processes folder does not exist, showing results for O: drive.');
            fldr    = 'O:\Code\processes';            
        end
    else
        fldr    = 'D:\Dropbox\Promoveren\matlab2\00_Code\processes';
    end

    files   = dir(fldr);
    files   = files(~[files.isdir]);
    
    
    for oo=1:length(files)
        fprintf('- <a href="matlab:clipboard(''copy'',''@%s'')">@%s</a> - <a href="matlab:open %s">Open</a>\n',files(oo).name(1:(end-2)),files(oo).name(1:(end-2)),...
            files(oo).name);
    end
end