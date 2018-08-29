function z = GetSubPlotProperties(z)

    figChildren = get(z.FigureHandle,'Children');
    
    kk = 1;
    for oo=1:length(figChildren)
        if isa(figChildren(oo),'matlab.graphics.axis.Axes') && ~isfield(figChildren(oo).UserData,'FLegend')
            z.SubPlots(kk) = figChildren(oo);
            kk=kk+1;
        end
    end

    z.NumSubPlots               = length(z.SubPlots);
    z.SubPlotOuterPosition      = zeros(z.NumSubPlots,4);
    
    for ll=1:z.NumSubPlots
        z.SubPlotOuterPosition(ll,:) = get(z.SubPlots(ll),'OuterPosition');
    end
    
    % Check the orientation of the subplots 
    if isempty(z.NumSubPlotColumns)
        z.NumSubPlotColumns     = length(unique(round(z.SubPlotOuterPosition(:,1),3)));
    end
    if isempty(z.NumSubPlotRows)
        z.NumSubPlotRows        = length(unique(round(z.SubPlotOuterPosition(:,2),3)));    
    end
    
    % The Y axes on the right inputs

    if ~isempty(z.RightYLimits) || ~isempty(z.RightYTicks)
        error('Did not implement this yet.');
        if z.NumSubPlots == 1
            assert(~iscell(z.RightYLimits) && ~iscell(z.RightYTicks));
            z.RightYLimits  = {z.RightYLimits};
            z.RightYTicks   = {z.RightYTicks};
        else
            assert(iscell(z.RightYLimits) && iscell(z.rightYticks) && isvector(z.rightYlimits) && isvector(z.rightYticks));
            assert(length(z.RightYLimits) == z.NumSubPlots && length(z.rightYticks) == z.NumSubPlots);
        end

        for ii=1:z.NumSubPlots
            if isempty(z.rightYlimits{ii})
                z.rightYlimits{ii} = [min(z.rightYticks{ii}) max(z.rightYticks{ii})];
            end
        end
    else
        z.RightYLabelWidth = 0;
    end

    % Determine some sizes
    
    z.YLabelWidth                   = FLegend.RepeatRequiredTimes(z.YLabelWidth,        z.NumSubPlotColumns,    true);
    z.RightYLabelWidth              = FLegend.RepeatRequiredTimes(z.RightYLabelWidth,   z.NumSubPlotColumns,    true);
    z.XLabelHeight                  = FLegend.RepeatRequiredTimes(z.XLabelHeight,       z.NumSubPlotRows,       true);
    z.TitleHeight                   = FLegend.RepeatRequiredTimes(z.TitleHeight,        z.NumSubPlotRows,       true);
    
    z.SubPlotHorizontalSpacing      = FLegend.RepeatRequiredTimes(z.SubPlotHorizontalSpacing,   z.NumSubPlotColumns-1,            false);
    z.SubPlotVerticalSpacing        = FLegend.RepeatRequiredTimes(z.SubPlotVerticalSpacing,     z.NumSubPlotRows-1,              false);
    
    z.SubPlotWidth                  = (z.ImageWidth     - sum(z.SubPlotHorizontalSpacing) - (z.PaddingLeft + z.PaddingRight))  / z.NumSubPlotColumns;
    z.SubPlotHeight                 = (z.ImageHeight    - sum(z.SubPlotVerticalSpacing)   - (z.PaddingTop + z.PaddingBottom))  / z.NumSubPlotRows;

    z.SubPlotWidth                  = FLegend.RepeatRequiredTimes(z.SubPlotWidth, z.NumSubPlotColumns, false);
    z.SubPlotHeight                 = FLegend.RepeatRequiredTimes(z.SubPlotHeight, z.NumSubPlotRows, false);


end

