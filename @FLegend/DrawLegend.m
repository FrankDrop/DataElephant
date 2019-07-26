function z = DrawLegend(z)

    % Calculate legend size

    z.LegendWidth  = z.LegendPaddingLeft + ...
                     sum(z.MarkerWidth) + ...
                     sum(z.LegendItemHorizontalSpacing) + ...
                     sum(z.LegendMarkerTextSpacing) + ...
                     sum(z.TextWidth) + ...
                     z.LegendPaddingRight;

    z.LegendHeight  = z.LegendPaddingTop + ...
                      sum(z.TextHeight) + ...
                      sum(z.LegendItemVerticalSpacing) + ...
                      z.LegendPaddingBottom;

                  
    if z.Paper
        set(z.AxesHandle,'units','centimeters');
    end
        
    ax_pos  = get(z.AxesHandle,'position');

    legendAxes = axes;
    legendAxes.UserData.FLegend = true;
    
    if ~isempty(z.Color)
        legendAxes.Color = z.Color;
    end

    if strcmp(z.Box,'yes')
        axis off;
    end

    hold on

    if ~isempty(z.Title)
        ploty   = z.LegendHeight - z.TextHeight(1)/2;
        text(z.LegendItemSpacing,ploty-0.05+z.TextVerticalShift,z.Title,'VerticalAlignment','middle',...
                                                  'FontName','CMR6',...
                                                  'FontSize',z.FontSize,...
                                                  'Interpreter',z.Interpreter);
    end

    % Plotting the legend
    for oo=1:z.NumLabels
        
        if strcmp(z.Direction,'Regular')
            oo_order = oo;
        else
            oo_order = z.NumLabels - oo + 1;
        end
        
        
        if ~isempty(z.Title)    
            if strcmp(z.Orientation,'Vertical')
                col = ceil(oo / (z.Rows-1));
                row = mod(oo-1, (z.Rows-1))+1+1;
            elseif strcmp(z.Orientation,'Horizontal')            
                col = mod(oo-1, z.Columns)+1;            
                row = ceil(oo / z.Columns)+1;
            end
        else
            if strcmp(z.Orientation,'Vertical')
                col = ceil(oo / (z.Rows));
                row = mod(oo-1, (z.Rows))+1;
            elseif strcmp(z.Orientation,'Horizontal')            
                col = mod(oo-1, z.Columns)+1;            
                row = ceil(oo / z.Columns);
            end
        end

        plotx1  = z.LegendPaddingLeft + ...
                    sum(z.LegendMarkerTextSpacing(1:(col-1))) + ...
                    sum(z.LegendItemHorizontalSpacing(1:(col -1))) + ...
                    sum(z.TextWidth(1:(col-1))) + ...
                    sum(z.MarkerWidth(1:(col-1)));
                
        plotx2  = plotx1 + z.MarkerWidth(col);
        plotxt  = plotx2 + z.LegendMarkerTextSpacing(col);

        ploty   = z.LegendHeight - ( ...
                        z.LegendPaddingTop + ...
                        sum(z.LegendItemVerticalSpacing(1:(row-1))) + ...
                        sum(z.TextHeight(1:(row-1))) + ...
                        z.TextHeight(row)/2 ...
                    );
                    
        props   = get(z.PlotHandle(oo_order));

    %% Determine what kind of marker we need to draw

        if isa(z.PlotHandle(oo_order),'matlab.graphics.chart.primitive.Bar')
            iWillDraw   = 'Bar';
        elseif isa(z.PlotHandle(oo_order),'matlab.graphics.chart.primitive.Line')
            iWillDraw   = 'Line';
        elseif isa(z.PlotHandle(oo_order),'matlab.graphics.chart.primitive.Scatter') 
            iWillDraw   = 'Scatter';
        elseif isa(z.PlotHandle(oo_order),'matlab.graphics.chart.primitive.ErrorBar') 
            iWillDraw   = 'Line';
        elseif isa(z.PlotHandle(oo_order),'matlab.graphics.primitive.Rectangle')
            iWillDraw   = 'Rectangle';
        else
            error('You need to add the %s class.',class(z.PlotHandle(oo_order)))
        end

        if strcmp(iWillDraw,'Line')
            plot([plotx1 plotx2],[ploty ploty],...
                'Color',get(z.PlotHandle(oo_order),'Color'),...
                'LineStyle',get(z.PlotHandle(oo_order),'LineStyle'),...
                'LineWidth',get(z.PlotHandle(oo_order),'LineWidth'),...
                'Marker','none',...
                'MarkerSize',get(z.PlotHandle(oo_order),'MarkerSize'),...
                'MarkerEdgeColor',get(z.PlotHandle(oo_order),'MarkerEdgeColor'),...
                'MarkerFaceColor',get(z.PlotHandle(oo_order),'MarkerFaceColor'),...
                'UserData',get(z.PlotHandle(oo_order),'UserData'));

            if ~strcmp(props.Marker,'none')
                plot(mean([plotx1 plotx2]),ploty,...
                    'Color',z.PlotHandle(oo_order).Color,...
                    'LineStyle',get(z.PlotHandle(oo_order),'LineStyle'),...
                    'Marker',get(z.PlotHandle(oo_order),'Marker'),...
                    'MarkerSize',get(z.PlotHandle(oo_order),'MarkerSize'),...
                    'MarkerEdgeColor',get(z.PlotHandle(oo_order),'MarkerEdgeColor'),...
                    'MarkerFaceColor',get(z.PlotHandle(oo_order),'MarkerFaceColor'),...
                    'UserData',get(z.PlotHandle(oo_order),'UserData'));
            end
        elseif strcmp(iWillDraw,'Rectangle')
            rectangle('Position',[plotx1,ploty-z.TextHeight(row)/2,plotx2-plotx1,z.TextHeight(row)],...
                'EdgeColor',get(z.PlotHandle(oo_order),'EdgeColor'),...
                'LineStyle',get(z.PlotHandle(oo_order),'LineStyle'),...
                'LineWidth',get(z.PlotHandle(oo_order),'LineWidth'),...
                'UserData',get(z.PlotHandle(oo_order),'UserData'));
        elseif strcmp(iWillDraw,'Contour')
            plot([plotx1 plotx2],[ploty ploty],...
                'Color',get(z.PlotHandle(oo_order),'Color'),...
                'LineStyle',get(z.PlotHandle(oo_order),'LineStyle'),...
                'LineWidth',get(z.PlotHandle(oo_order),'LineWidth'),...
                'UserData',get(z.PlotHandle(oo_order),'UserData'));
        elseif strcmp(iWillDraw,'ErrorBar')
            plot([plotx1 plotx2],[ploty ploty],...
                'Color',get(z.PlotHandle(oo_order),'Color'),...
                'LineStyle',get(z.PlotHandle(oo_order),'LineStyle'),...
                'LineWidth',get(z.PlotHandle(oo_order),'LineWidth'),...
                'Marker','none',...
                'MarkerSize',get(z.PlotHandle(oo_order),'MarkerSize'),...
                'MarkerEdgeColor',get(z.PlotHandle(oo_order),'MarkerEdgeColor'),...
                'MarkerFaceColor',get(z.PlotHandle(oo_order),'MarkerFaceColor'),...
                'UserData',get(z.PlotHandle(oo_order),'UserData'));

            if ~strcmp(props.Marker,'none')
                plot(mean([plotx1 plotx2]),ploty,...
                    'Color',get(z.PlotHandle(oo_order),'Color'),...
                    'LineStyle',get(z.PlotHandle(oo_order),'LineStyle'),...
                    'Marker',get(z.PlotHandle(oo_order),'Marker'),...
                    'MarkerSize',get(z.PlotHandle(oo_order),'MarkerSize'),...
                    'MarkerEdgeColor',get(z.PlotHandle(oo_order),'MarkerEdgeColor'),...
                    'MarkerFaceColor',get(z.PlotHandle(oo_order),'MarkerFaceColor'),...
                    'UserData',get(z.PlotHandle(oo_order),'UserData'));
            end
        elseif strcmpi(iWillDraw,'Scatter')
            scatter(mean([plotx1 plotx2]),ploty,...
                'CData',get(z.PlotHandle(oo_order),'CData'),...
                'SizeData',get(z.PlotHandle(oo_order),'SizeData'),...
                'Marker',get(z.PlotHandle(oo_order),'Marker'),...
                'MarkerEdgeColor',get(z.PlotHandle(oo_order),'MarkerEdgeColor'),...
                'MarkerFaceColor',get(z.PlotHandle(oo_order),'MarkerFaceColor'),...
                'UserData',get(z.PlotHandle(oo_order),'UserData'));            
        elseif strcmpi(iWillDraw,'Bar')

            if strcmpi(get(z.PlotHandle(oo_order),'FaceColor'),'flat')
                set(z.PlotHandle(oo_order),'FaceColor','b');
            end

            tRec     = rectangle('Position',[plotx1,ploty-z.TextHeight(row)/2,plotx2-plotx1,z.TextHeight(row)]);
            tRec.UserData = get(z.PlotHandle(oo_order),'UserData');

            try %#ok<TRYNC>
                tRec.FaceColor  = get(z.PlotHandle(oo_order),'FaceColor');
            end
            try %#ok<TRYNC>
                tRec.EdgeColor  = get(z.PlotHandle(oo_order),'EdgeColor');
            end
            try %#ok<TRYNC>
                tRec.LineStyle  = get(z.PlotHandle(oo_order),'LineStyle');
            end
            try %#ok<TRYNC>
                tRec.LineWidth  = get(z.PlotHandle(oo_order),'LineWidth');
            end
        end


        thisLabel   = get(z.PlotHandle(oo_order),'DisplayName');

        if ~isempty(z.Labels)
            if iscell(z.Labels)
                if oo_order <= length(z.Labels) 
                    if ~isempty(z.Labels{oo_order})
                        thisLabel = z.Labels{oo_order};
                    end
                end
            end
        end

        text(plotxt,ploty+z.TextVerticalShift,thisLabel, 'VerticalAlignment','middle',...
                                                              'FontName',z.FontName,...
                                                              'FontSize',12,...
                                                              'Color',z.TextColor,...
                                                              'Interpreter',z.Interpreter);

    end

    xSpacing = 0.1;
    ySpacing = 0.1;

    switch lower(z.Location)
        case {'north'}
            autoLegendX = ax_pos(1) + (ax_pos(3) / 2 - z.LegendWidth/2);
            autoLegendY = ax_pos(2) + (ax_pos(4) - (ySpacing + z.LegendHeight));

        case {'northoutside','north outside'}
            autoLegendX = ax_pos(1) + (ax_pos(3)-z.LegendWidth)/2 - max([z.LegendWidth-ax_pos(3) 0])/2;
            autoLegendY = ax_pos(2) + ax_pos(4) + 2*z.LegendItemSpacing;

        case {'northeast','north east'}
            autoLegendX = ax_pos(1) + (ax_pos(3) - (xSpacing + z.LegendWidth));
            autoLegendY = ax_pos(2) + (ax_pos(4) - (ySpacing + z.LegendHeight));

        case {'east'}
            autoLegendX = ax_pos(1) + (ax_pos(3) - (xSpacing + z.LegendWidth));
            autoLegendY = ax_pos(2) + (ax_pos(4) / 2 - z.LegendHeight/2);

        case {'eastoutside','east outside'}
            autoLegendX = ax_pos(1) + ax_pos(3) + 2*z.LegendItemSpacing;
            autoLegendY = ax_pos(2) + (ax_pos(4)-z.LegendHeight)/2 - max([z.LegendHeight-ax_pos(4) 0])/2;

        case {'southeast','south east'}
            autoLegendX = ax_pos(1) + (ax_pos(3) - (xSpacing + z.LegendWidth));
            autoLegendY = ax_pos(2) + ySpacing;

        case {'south'}
            autoLegendX = ax_pos(1) + (ax_pos(3) / 2 - z.LegendWidth/2);
            autoLegendY = ax_pos(2) + ySpacing;

        case {'southwest','south west'}
            autoLegendX = ax_pos(1) + xSpacing;
            autoLegendY = ax_pos(2) + ySpacing;

        case {'west'}
            autoLegendX = ax_pos(1) + xSpacing;
            autoLegendY = ax_pos(2) + (ax_pos(4) / 2 - z.LegendHeight/2);

        case {'northwest','north west'}
            autoLegendX = ax_pos(1) + xSpacing;
            autoLegendY = ax_pos(2) + (ax_pos(4) - (ySpacing + z.LegendHeight));

        otherwise
            fprintf('The option ''%s'' does not exist!\n',Location)
            autoLegendX = ax_pos(1) + (ax_pos(3) - (xSpacing + z.LegendWidth));
            autoLegendY = ax_pos(2) + ySpacing;
    end    

    if isempty(z.LegendHorizontalPosition)
        z.LegendHorizontalPosition = autoLegendX;
    end

    if isempty(z.LegendVerticalPosition)
        z.LegendVerticalPosition = autoLegendY;
    end
    
    z.LegendHorizontalPosition  = z.LegendHorizontalPosition + z.LegendHorizontalShift;
    z.LegendVerticalPosition    = z.LegendVerticalPosition + z.LegendVerticalShift;

    set(gca,'units','centimeters');
    set(gca,'position',[z.LegendHorizontalPosition  z.LegendVerticalPosition z.LegendWidth z.LegendHeight]);
    set(gca,'Box','on');
    set(gca,'XTick',[]);
    set(gca,'YTick',[]);
    set(gca,'XLim',[0 z.LegendWidth]);
    set(gca,'YLim',[0 z.LegendHeight]);

    set(gcf,'CurrentAxes',z.CurrentAxes)
end