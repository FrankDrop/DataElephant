function DrawLegend(z)

    set(z.AxesHandle,'units','centimeters');
    ax_pos = get(z.AxesHandle,'position');



    legendAxes = axes;
    legendAxes.UserData.FLegend = true;
    if ~isempty(z.color)
        legendAxes.Color = z.color;
    end

    if strcmp(z.Box,'yes')
        axis off;
    end

    hold on



    if ~isempty(z.title)
        ploty   = lh - (z.Spacing + z.TextHeight(1)/2);
        text(z.Spacing,ploty-0.05+z.textverticalshift,z.title,'VerticalAlignment','middle',...
                                                  'FontName','CMR6',...
                                                  'FontSize',z.FontSize,...
                                                  'Interpreter',z.Interpreter);
    end

    % Plotting the legend
    for oo=1:numLabels
        if ~isempty(z.title)    
            if strcmp(z.Orientation,'vertical')
                col = ceil(oo / (z.Rows-1));
                row = mod(oo-1, (z.Rows-1))+1+1;
            elseif strcmp(z.Orientation,'horizontal')            
                col = mod(oo-1, z.columns)+1;            
                row = ceil(oo / z.columns)+1;
            end
        else
            if strcmp(z.Orientation,'vertical')
                col = ceil(oo / (z.Rows));
                row = mod(oo-1, (z.Rows))+1;
            elseif strcmp(z.Orientation,'horizontal')            
                col = mod(oo-1, z.columns)+1;            
                row = ceil(oo / z.columns);
            end
        end

        plotx1  = z.Spacing + 2*z.Spacing * (col -1) + sum(z.TextWidth(1:(col-1))) + sum(z.MarkerWidth(1:(col-1)));
        plotx2  = plotx1 + z.MarkerWidth(col);        
        plotxt  = plotx2 + z.Spacing;

        ploty   = lh - (z.Spacing + sum(z.vSpacing(1:(row-1))) + sum(z.TextHeight(1:(row-1))) + z.TextHeight(row)/2);
        props   = get(z.PlotHandle(oo));

    %% Determine what kind of marker we need to draw

        if isa(z.PlotHandle(oo),'matlab.graphics.chart.primitive.Bar')
            iWillDraw   = 'Bar';
        elseif isa(z.PlotHandle(oo),'matlab.graphics.chart.primitive.Line')
            iWillDraw   = 'Line';
        elseif isa(z.PlotHandle(oo),'matlab.graphics.chart.primitive.Scatter') 
            iWillDraw   = 'Scatter';
        elseif isa(z.PlotHandle(oo),'matlab.graphics.chart.primitive.ErrorBar') 
            iWillDraw   = 'Line';
        elseif isa(z.PlotHandle(oo),'matlab.graphics.primitive.Rectangle')
            iWillDraw   = 'Rectangle';
        else
            z.PlotHandle(oo)
            error('You need to add the %s class.',class(z.PlotHandle(oo)))
        end

        if strcmp(iWillDraw,'Line')
            plot([plotx1 plotx2],[ploty ploty],...
                'Color',get(z.PlotHandle(oo),'Color'),...
                'LineStyle',get(z.PlotHandle(oo),'LineStyle'),...
                'LineWidth',get(z.PlotHandle(oo),'LineWidth'),...
                'Marker','none',...
                'MarkerSize',get(z.PlotHandle(oo),'MarkerSize'),...
                'MarkerEdgeColor',get(z.PlotHandle(oo),'MarkerEdgeColor'),...
                'MarkerFaceColor',get(z.PlotHandle(oo),'MarkerFaceColor'),...
                'UserData',get(z.PlotHandle(oo),'UserData'));

            if ~strcmp(props.Marker,'none')
                plot(mean([plotx1 plotx2]),ploty,...
                    'Color',get(z.PlotHandle(oo),'Color'),...
                    'LineStyle',get(z.PlotHandle(oo),'LineStyle'),...
                    'Marker',get(z.PlotHandle(oo),'Marker'),...
                    'MarkerSize',get(z.PlotHandle(oo),'MarkerSize'),...
                    'MarkerEdgeColor',get(z.PlotHandle(oo),'MarkerEdgeColor'),...
                    'MarkerFaceColor',get(z.PlotHandle(oo),'MarkerFaceColor'),...
                    'UserData',get(z.PlotHandle(oo),'UserData'));
            end
        elseif strcmp(iWillDraw,'Rectangle')
            rectangle('Position',[plotx1,ploty-z.TextHeight(row)/2,plotx2-plotx1,z.TextHeight(row)],...
                'EdgeColor',get(z.PlotHandle(oo),'EdgeColor'),...
                'LineStyle',get(z.PlotHandle(oo),'LineStyle'),...
                'LineWidth',get(z.PlotHandle(oo),'LineWidth'),...
                'UserData',get(z.PlotHandle(oo),'UserData'));
        elseif strcmp(iWillDraw,'Contour')
            plot([plotx1 plotx2],[ploty ploty],...
                'Color',get(z.PlotHandle(oo),'Color'),...
                'LineStyle',get(z.PlotHandle(oo),'LineStyle'),...
                'LineWidth',get(z.PlotHandle(oo),'LineWidth'),...
                'UserData',get(z.PlotHandle(oo),'UserData'));
        elseif strcmp(iWillDraw,'ErrorBar')
            plot([plotx1 plotx2],[ploty ploty],...
                'Color',get(z.PlotHandle(oo),'Color'),...
                'LineStyle',get(z.PlotHandle(oo),'LineStyle'),...
                'LineWidth',get(z.PlotHandle(oo),'LineWidth'),...
                'Marker','none',...
                'MarkerSize',get(z.PlotHandle(oo),'MarkerSize'),...
                'MarkerEdgeColor',get(z.PlotHandle(oo),'MarkerEdgeColor'),...
                'MarkerFaceColor',get(z.PlotHandle(oo),'MarkerFaceColor'),...
                'UserData',get(z.PlotHandle(oo),'UserData'));

            if ~strcmp(props.Marker,'none')
                plot(mean([plotx1 plotx2]),ploty,...
                    'Color',get(z.PlotHandle(oo),'Color'),...
                    'LineStyle',get(z.PlotHandle(oo),'LineStyle'),...
                    'Marker',get(z.PlotHandle(oo),'Marker'),...
                    'MarkerSize',get(z.PlotHandle(oo),'MarkerSize'),...
                    'MarkerEdgeColor',get(z.PlotHandle(oo),'MarkerEdgeColor'),...
                    'MarkerFaceColor',get(z.PlotHandle(oo),'MarkerFaceColor'),...
                    'UserData',get(z.PlotHandle(oo),'UserData'));
            end
        elseif strcmpi(iWillDraw,'Scatter')
            scatter(mean([plotx1 plotx2]),ploty,...
                'CData',get(z.PlotHandle(oo),'CData'),...
                'SizeData',get(z.PlotHandle(oo),'SizeData'),...
                'Marker',get(z.PlotHandle(oo),'Marker'),...
                'MarkerEdgeColor',get(z.PlotHandle(oo),'MarkerEdgeColor'),...
                'MarkerFaceColor',get(z.PlotHandle(oo),'MarkerFaceColor'),...
                'UserData',get(z.PlotHandle(oo),'UserData'));            
        elseif strcmpi(iWillDraw,'Bar')

            if strcmpi(get(z.PlotHandle(oo),'FaceColor'),'flat')
                set(z.PlotHandle(oo),'FaceColor','b');
            end

            tRec     = rectangle('Position',[plotx1,ploty-z.TextHeight(row)/2,plotx2-plotx1,z.TextHeight(row)]);
            tRec.UserData = get(z.PlotHandle(oo),'UserData');

            try %#ok<TRYNC>
                tRec.FaceColor  = get(z.PlotHandle(oo),'FaceColor');
            end
            try %#ok<TRYNC>
                tRec.EdgeColor  = get(z.PlotHandle(oo),'EdgeColor');
            end
            try %#ok<TRYNC>
                tRec.LineStyle  = get(z.PlotHandle(oo),'LineStyle');
            end
            try %#ok<TRYNC>
                tRec.LineWidth  = get(z.PlotHandle(oo),'LineWidth');
            end
        end


        thisLabel   = get(z.PlotHandle(oo),'DisplayName');

        if ~isempty(z.Labels)
            if iscell(z.Labels)
                if oo <= length(z.Labels) 
                    if ~isempty(z.Labels{oo})
                        thisLabel = z.Labels{oo};
                    end
                end
            end
        end

        text(plotxt,ploty-0.05+z.textverticalshift,thisLabel,'VerticalAlignment','middle',...
                                                  'FontName','CMR6',...
                                                  'FontSize',12,...
                                                  'Color',z.TextColor,...
                                                  'Interpreter',z.Interpreter);

    end

    xSpacing = 0.1;
    ySpacing = 0.1;

    switch lower(z.Location)
        case {'north'}
            autoLegendX = ax_pos(1) + (ax_pos(3) / 2 - lw/2);
            autoLegendY = ax_pos(2) + (ax_pos(4) - (ySpacing + lh));

        case {'northoutside','north outside'}
            autoLegendX = ax_pos(1) + (ax_pos(3)-lw)/2 - max([lw-ax_pos(3) 0])/2;
            autoLegendY = ax_pos(2) + ax_pos(4) + 2*z.Spacing;

        case {'northeast','north east'}
            autoLegendX = ax_pos(1) + (ax_pos(3) - (xSpacing + lw));
            autoLegendY = ax_pos(2) + (ax_pos(4) - (ySpacing + lh));

        case {'east'}
            autoLegendX = ax_pos(1) + (ax_pos(3) - (xSpacing + lw));
            autoLegendY = ax_pos(2) + (ax_pos(4) / 2 - lh/2);

        case {'eastoutside','east outside'}
            autoLegendX = ax_pos(1) + ax_pos(3) + 2*z.Spacing;
            autoLegendY = ax_pos(2) + (ax_pos(4)-lh)/2 - max([lh-ax_pos(4) 0])/2;

        case {'southeast','south east'}
            autoLegendX = ax_pos(1) + (ax_pos(3) - (xSpacing + lw));
            autoLegendY = ax_pos(2) + ySpacing;

        case {'south'}
            autoLegendX = ax_pos(1) + (ax_pos(3) / 2 - lw/2);
            autoLegendY = ax_pos(2) + ySpacing;

        case {'southwest','south west'}
            autoLegendX = ax_pos(1) + xSpacing;
            autoLegendY = ax_pos(2) + ySpacing;

        case {'west'}
            autoLegendX = ax_pos(1) + xSpacing;
            autoLegendY = ax_pos(2) + (ax_pos(4) / 2 - lh/2);

        case {'northwest','north west'}
            autoLegendX = ax_pos(1) + xSpacing;
            autoLegendY = ax_pos(2) + (ax_pos(4) - (ySpacing + lh));

        otherwise
            fprintf('The option ''%s'' does not exist!\n',Location)
            autoLegendX = ax_pos(1) + (ax_pos(3) - (xSpacing + lw));
            autoLegendY = ax_pos(2) + ySpacing;
    end    

    if z.legendx == 0
        z.legendx = autoLegendX;
    end

    if z.legendy == 0
        z.legendy = autoLegendY;
    end

    set(gca,'units','centimeters');
    set(gca,'position',[z.legendx+z.legend_dx  z.legendy+z.legend_dy lw lh]);
    set(gca,'Box','on');
    set(gca,'XTick',[]);
    set(gca,'YTick',[]);
    set(gca,'XLim',[0 lw]);
    set(gca,'YLim',[0 lh]);

    set(gcf,'CurrentAxes',currentAxes)
end