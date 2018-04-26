function z = GetSubPlotProperties(z)
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
%%
    z.SubPlotsHorizontallyAligned   = sum(abs(diff(z.SubPlotPosition(:,1)))) > sum(abs(diff(z.SubPlotPosition(:,2))));
    
    if z.SubPlotsHorizontallyAligned
        z.NumSubPlotRows            = 1;
        z.NumSubPlotColumns         = z.NumSubPlots;
    else
        z.NumSubPlotRows            = z.NumSubPlots;
        z.NumSubPlotColumns         = 1;
        
    end

%%
    for ll=1:z.NumSubPlots
        z.SubPlotOuterPosition(ll,:) = get(z.SubPlots(ll),'OuterPosition');
    end
    
    %% Check the Y axes on the right inputs

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

    %%
    
    z.YLabelWidth                   = FLegend.RepeatRequiredTimes(z.YLabelWidth,        z.NumSubPlotColumns,    true);
    z.RightYLabelWidth              = FLegend.RepeatRequiredTimes(z.RightYLabelWidth,   z.NumSubPlotColumns,    true);
    z.XLabelHeight                  = FLegend.RepeatRequiredTimes(z.XLabelHeight,       z.NumSubPlotRows,       true);
    z.TitleHeight                   = FLegend.RepeatRequiredTimes(z.TitleHeight,        z.NumSubPlotRows,       true);
    
    z.SubPlotHorizontalSpacing      = FLegend.RepeatRequiredTimes(z.SubPlotHorizontalSpacing,   z.NumSubPlotColumns-1,            false);
    z.SubPlotVerticalSpacing        = FLegend.RepeatRequiredTimes(z.SubPlotVerticalSpacing,     z.NumSubPlotRows-1,              false);
    
    z.SubPlotWidth                  = (z.ImageWidth     - sum(z.SubPlotHorizontalSpacing))  / z.NumSubPlotColumns;
    z.SubPlotHeight                 = (z.ImageHeight    - sum(z.SubPlotVerticalSpacing))    / z.NumSubPlotRows;

    z.SubPlotWidth                  = FLegend.RepeatRequiredTimes(z.SubPlotWidth, z.NumSubPlotColumns, false);
    z.SubPlotHeight                 = FLegend.RepeatRequiredTimes(z.SubPlotHeight, z.NumSubPlotRows, false);

%     if z.SubPlotsHorizontallyAligned
%         if length(z.ylabelwidth) < z.NumSubPlots
%             z.ylabelwidth   = repmat(z.ylabelwidth,1,ceil(z.NumSubPlots / length(z.YLabelWidth)));
%         end
%         error('check this')
%         z.ylabelwidth       = z.ylabelwidth(numSubPlots:-1:1); 
%         z.xlabelheight      = z.xlabelheight(1);
%         z.titleheight       = z.titleheight(1);
%         
%         z.YLabelWidth       = RepeatRequiredTimes(z.YLabelWidth,z.NumSubPlots);
%         z.XLabelHeight      = RepeatRequiredTimes(z.xlabelheight,1);
%         z.TitleHeight       = RepeatRequiredTimes(z.TitleHeight,z.(1);
%     else
%         if length(z.xlabelheight) < numSubPlots
%             z.xlabelheight    = repmat(z.xlabelheight,1,ceil(numSubPlots / length(z.xlabelheight)));
%         end
%         if length(z.titleheight) < numSubPlots
%             z.titleheight    = repmat(z.titleheight,1,ceil(numSubPlots / length(z.titleheight)));
%         end
% 
%         z.ylabelwidth       = z.ylabelwidth(1);
%         z.xlabelheight      = z.xlabelheight(numSubPlots:-1:1);
%         z.titleheight       = z.titleheight(numSubPlots:-1:1);
%     end


end

