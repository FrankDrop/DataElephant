function anyTemplate(template,name)
    
    [FileName,PathName] = uiputfile('*.m','Save template step file as...',[pwd '/' name '.m']);
    if ischar(FileName) && ischar(PathName)
        content = [PathName '/' FileName];
    else
        content = [];
    end

    [pathstr,~,~]   = fileparts(which('DataElephant'));
    templtPath      = [pathstr '/../templates/'];
    
    if ~isempty(content)
        copyfile([templtPath template],content)
        edit(content)
    end
end

