function stepTemplate(content)

    if nargin == 0
        [FileName,PathName] = uiputfile('*.m','Save template step file as...',[pwd '/s_newStep.m']);
        if ischar(FileName) && ischar(PathName)
            content = [PathName '/' FileName];
        else
            content = [];
        end
    end

    [pathstr,~,~]   = fileparts(which('DataElephant'));
    templtPath      = [pathstr '/../templates/'];
    
    if ~isempty(content)
        copyfile([templtPath 'step_template.m'],content)
        edit(content)
    end
end

