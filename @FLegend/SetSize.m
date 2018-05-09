function z = SetSize(z)
    if z.Paper
        z.FigureHandle.Units            = 'centimeters';
        z.FigureHandle.Position         = [3,3,z.ImageWidth,z.ImageHeight];
        z.FigureHandle.PaperUnits       = 'centimeters';
        z.FigureHandle.PaperPosition    = [3,3,z.ImageWidth,z.ImageHeight];
    else
        % dont think we need to do anything here
    end
end

