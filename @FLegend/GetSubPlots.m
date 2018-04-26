function z = GetSubPlots(z)
    figChildren = get(z.FigureHandle,'Children');
    
    kk = 1;
    for oo=1:length(figChildren)
        if isa(figChildren(oo),'matlab.graphics.axis.Axes') && ~isfield(figChildren(oo).UserData,'FLegend')
            z.SubPlots(kk) = figChildren(oo);
            kk=kk+1;
        end
    end

    % Find out whether the subplots are horizontally or vertically aligned:
    % (no support for complex orientations)

    z.NumSubPlots       = length(z.SubPlots);
    z.SubPlotPosition   = zeros(z.NumSubPlots,4);

    z.SubPlotsHorizontallyAligned   = sum(abs(diff(z.SubPlotPosition(:,1)))) > sum(abs(diff(z.SubPlotPosition(:,2))));
    
    for ll=1:z.NumSubPlots
        z.SubPlotOuterPosition(ll,:) = get(z.SubPlots(ll),'OuterPosition');
    end
end

