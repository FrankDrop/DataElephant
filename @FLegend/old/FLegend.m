function [] = FLegend(varargin)

% FLegend(varargin)
% Example:
% FLegend('textwidth',[],'rows',2,'location','SouthEast','imgscale',1.5,'imgheight',8,'imgwidth',5);
% 
% Other options:
% - rows
% - markerwidth
% - textwidth
% - location
% - textheight
% - spacing
% - imgscale
% - imgwidth
% - imgheight
% - legendx
% - legendy
% - legend_dx
% - legend_dy
% - subplotmargin
% - type

p = inputParser;
p.addParameter('showLegend','yes');
p.addParameter('figureHandle',gcf);
p.addParameter('subplotHandle',gca);
p.addParameter('plotHandle',-1);
p.addParameter('rows', [], @(x)isnumeric(x));
p.addParameter('columns', [], @(x)isnumeric(x));
p.addParameter('markerwidth', 0.3, @(x)isnumeric(x));
p.addParameter('textwidth', 1);
p.addParameter('location', 'SouthWest');
p.addParameter('textheight', 0.25, @(x)isnumeric(x));
p.addParameter('spacing', 0.05, @(x)isnumeric(x));
p.addParameter('textverticalshift', 0, @(x)isnumeric(x));
p.addParameter('vspacing', 0.05, @(x)isnumeric(x));
p.addParameter('imgscale', 1.5, @(x)isnumeric(x));
p.addParameter('imgwidth', 5, @(x)isnumeric(x));
p.addParameter('imgheight', 5, @(x)isnumeric(x));
p.addParameter('xlabelheight', 0.75, @(x)isnumeric(x)); % Percentage
p.addParameter('ylabelwidth', 0.75, @(x)isnumeric(x));
p.addParameter('xlabel_dy', 0.0, @(x)isnumeric(x));
p.addParameter('rightylabelwidth', 0, @(x)isnumeric(x));
p.addParameter('rightmargin', 0.08, @(x)isnumeric(x));
p.addParameter('topmargin', 0.05, @(x)isnumeric(x));
p.addParameter('titleheight', 0.75, @(x)isnumeric(x)); % Percentage
p.addParameter('legendx', 0, @(x)isnumeric(x));
p.addParameter('legendy', 0, @(x)isnumeric(x));
p.addParameter('legend_dx', 0, @(x)isnumeric(x));
p.addParameter('legend_dy', 0, @(x)isnumeric(x));
p.addParameter('subplotmargin', 0.25, @(x)isnumeric(x));
p.addParameter('centerTitleOverEntireFigure', false);
p.addParameter('type', 'plot');
p.addParameter('direction','vertical');
p.addParameter('labels',[]);
p.addParameter('interpreter','none');
p.addParameter('transparent',0);
p.addParameter('title',[],@(x)ischar(x));
p.addParameter('rightYlimits',[],@(x)(all(isnumeric(x)) || iscell(x)));
p.addParameter('rightYticks',[],@(x)(all(isnumeric(x)) || iscell(x)));
p.addParameter('singleHorizontalAxis','no',@(x)ischar(x));
p.addParameter('color',[]);
p.addParameter('textcolor',[0 0 0],@(x)(isnumeric(x) && numel(x) == 3));

p.parse(varargin{:});

z = p.Results;

z.markerwidth       = z.markerwidth         * z.imgscale;
z.textverticalshift = z.textverticalshift   * z.imgscale;
z.textwidth         = z.textwidth           * z.imgscale;
z.textheight        = z.textheight          * z.imgscale;
z.spacing           = z.spacing             * z.imgscale;
z.imgwidth          = z.imgwidth            * z.imgscale;
z.imgheight         = z.imgheight           * z.imgscale;
z.legendx           = z.legendx             * z.imgscale;
z.legendy           = z.legendy             * z.imgscale;
z.legend_dx         = z.legend_dx           * z.imgscale;
z.legend_dy         = z.legend_dy           * z.imgscale;
z.subplotmargin     = z.subplotmargin       * z.imgscale;
z.xlabelheight      = z.xlabelheight        * z.imgscale;
z.ylabelwidth       = z.ylabelwidth         * z.imgscale;
z.titleheight       = z.titleheight         * z.imgscale;
z.rightmargin       = z.rightmargin         * z.imgscale;
z.topmargin         = z.topmargin           * z.imgscale;
z.vspacing          = z.vspacing            * z.imgscale;
z.rightylabelwidth  = z.rightylabelwidth    * z.imgscale;
z.xlabel_dy         = z.xlabel_dy           * z.imgscale;
z.singleHorizontalAxis  = strcmp(z.singleHorizontalAxis,'yes');

currentAxes     = gca;
drawLegend      = ~((isempty(z.plotHandle) && isempty(z.title)) || ~strcmpi(z.showLegend,'yes'));

if isnumeric(z.plotHandle) && ~isempty(z.plotHandle)
    z.plotHandle    = z.subplotHandle.Children;

    kk  = 1;
    l   = gobjects(1,1);
    
    for oo=1:length(z.plotHandle)
        if strncmp(class(z.plotHandle(oo)),'matlab.graphics.chart.primitive.',length('matlab.graphics.chart.primitive.'))
            l(kk,1)     = z.plotHandle(oo); 
            kk          = kk +1;
        end
    end
    z.plotHandle = flipud(l);
end


if drawLegend
    if ~isempty(z.labels)
        numLabels = min(length(z.plotHandle),length(z.labels));
    else
        numLabels = length(z.plotHandle);
    end

    if isempty(z.columns) && ~isempty(z.rows)
        if numLabels < z.rows
            z.rows = numLabels;
        end

        if strcmp(z.direction,'horizontal')
            z.columns   = ceil(numLabels / z.rows);      
            z.rows      = ceil(numLabels / z.columns);
        else
            z.columns = ceil(numLabels / z.rows);
        end
    elseif ~isempty(z.columns) && isempty(z.rows)
        if numLabels < z.columns
            z.columns = numLabels;
        end
        if strcmp(z.direction,'horizontal')
            z.rows      = ceil(numLabels / z.columns);
        else
            z.rows      = ceil(numLabels / z.columns);
            z.columns   = ceil(numLabels / z.rows);
        end
    elseif isempty(z.columns) && isempty(z.rows)
        z.rows      = numLabels;
        z.columns   = 1;
    else
        if numLabels < z.rows
            z.rows = numLabels;
        end
        if strcmp(z.direction,'horizontal')
            z.columns   = ceil(numLabels / z.rows);        
            z.rows      = ceil(numLabels / z.columns);
        else
            z.columns = ceil(numLabels / z.rows);
        end
    end

    if isempty(z.plotHandle) && ~isempty(z.title)
        z.rows = 1;
        z.columns = 1;
    elseif ~isempty(z.title) 
        z.rows = z.rows + 1;
    end
%%
    % If the user provides only one value for the textwidth, we simply use
    % this one for all columns.
    if length(z.textwidth) < z.columns
        z.textwidth     = repmat(z.textwidth,1,ceil(z.columns / length(z.textwidth)));
    end

    if length(z.markerwidth) < z.columns
        z.markerwidth   = repmat(z.markerwidth,1,ceil(z.columns / length(z.markerwidth)));
    end
    
    

    if length(z.textheight) < z.rows
        z.textheight    = repmat(z.textheight,1,ceil(z.rows / length(z.textheight)));
    end
    
   

    if length(z.vspacing) < z.rows
        z.vspacing    = repmat(z.vspacing,1,ceil(z.rows / length(z.vspacing)));
    end
    
    

    % If the user provides more values than columns, we simply take the
    % ones we need.
    z.textwidth         = z.textwidth(1:z.columns);
    z.markerwidth       = z.markerwidth(1:z.columns);
    z.textheight        = z.textheight(1:z.rows);
    z.vspacing          = z.vspacing(1:(z.rows-1));
    

%% Calculate the size of the legend.

    lw  = z.spacing + ...
          z.columns * 2 * z.spacing + ...
          sum(z.markerwidth) + ...
          sum(z.textwidth);

    % Calculate the height of the legend
    lh  = z.spacing + ...
          sum(z.textheight) + ...
          sum(z.vspacing) + ...
          z.spacing;

    switch lower(z.location)
        case {'north outside','northoutside'}
            legendMargin = [lh+z.spacing*2 0 0 0];
        case {'east outside','eastoutside'}
            legendMargin = [0 lw+z.spacing*2 0 0];
        case {'south outside','southoutside'}
            legendMargin = [0 0 lh+z.spacing*2 0];
        case {'west outside','westoutside'}
            legendMargin = [0 0 0 lw+z.spacing*2];
        otherwise
            legendMargin = [0 0 0 0];
    end
else
    legendMargin = [0 0 0 0];
end





drawnow;

z.figureHandle.Units            = 'centimeters';
z.figureHandle.Position         = [3,3,z.imgwidth,z.imgheight];
z.figureHandle.PaperUnits       = 'centimeters';
z.figureHandle.PaperPosition    = [3,3,z.imgwidth,z.imgheight];

figchildren = get(z.figureHandle,'Children');
kk = 1;
for oo=1:length(figchildren)
    if isa(figchildren(oo),'matlab.graphics.axis.Axes') && ~isfield(figchildren(oo).UserData,'FLegend')
        figaxes(kk) = figchildren(oo); %#ok<AGROW>
        kk=kk+1;
    end
end

% Find out whether the subplots are horizontally or vertically aligned:
% (no support for complex orientations)

numSubPlots     = length(figaxes);
subplotpos      = zeros(numSubPlots,4);

horizontalAligned   = sum(abs(diff(subplotpos(:,1)))) > sum(abs(diff(subplotpos(:,2))));

for ll=1:numSubPlots
    subplotpos(ll,:) = get(figaxes(ll),'OuterPosition');
end

%% Check the Y axes on the right inputs

if ~isempty(z.rightYlimits) || ~isempty(z.rightYticks)
    
    if (z.rightylabelwidth == 0)
        z.rightylabelwidth = 0.6;
    end
    
    if length(figaxes) == 1
        assert(~iscell(z.rightYlimits) && ~iscell(z.rightYticks));
        z.rightYlimits  = {z.rightYlimits};
        z.rightYticks   = {z.rightYticks};
    else
        assert(iscell(z.rightYlimits) && iscell(z.rightYticks) && isvector(z.rightYlimits) && isvector(z.rightYticks));
        assert(length(z.rightYlimits) == length(figaxes) && length(z.rightYticks) == length(figaxes));
    end
    
    for ii=1:length(figaxes)
        if isempty(z.rightYlimits{ii})
            z.rightYlimits{ii} = [min(z.rightYticks{ii}) max(z.rightYticks{ii})];
        end
    end
end

%%

if horizontalAligned
    if length(z.ylabelwidth) < numSubPlots
        z.ylabelwidth   = repmat(z.ylabelwidth,1,ceil(numSubPlots / length(z.ylabelwidth)));
    end
    error('check this')
    z.ylabelwidth       = z.ylabelwidth(numSubPlots:-1:1); 
    z.xlabelheight      = z.xlabelheight(1);
    z.titleheight       = z.titleheight(1);
else
    if length(z.xlabelheight) < numSubPlots
        z.xlabelheight    = repmat(z.xlabelheight,1,ceil(numSubPlots / length(z.xlabelheight)));
    end
    if length(z.titleheight) < numSubPlots
        z.titleheight    = repmat(z.titleheight,1,ceil(numSubPlots / length(z.titleheight)));
    end
    
    z.ylabelwidth       = z.ylabelwidth(1);
    z.xlabelheight      = z.xlabelheight(numSubPlots:-1:1);
    z.titleheight       = z.titleheight(numSubPlots:-1:1);
end


%% Stretch the subfigures to the maximum size possible

if horizontalAligned
    % The distances between the subplots is larger in horizontal
    % direction than in vertical direction. It is most likely that the
    % subplots are arranged horizontally.

    subplotwidth = (z.imgwidth-z.subplotmargin*(length(figaxes)-1))/length(figaxes);

    assert(numel(z.xlabelheight) == 1,'I believe xlabelheight should be size 1 here.');
    
    for uu=1:numSubPlots
        if isempty(get(get(figaxes(uu),'Title'),'String'))
            t_titleheight = 0;
        else
            t_titleheight = z.titleheight;
        end        
        
        set(figaxes(uu),'units','centimeter');
        set(get(figaxes(uu),'XLabel'),'units','centimeter');
        set(get(figaxes(uu),'XLabel'),'VerticalAlignment','Bottom');
        set(get(figaxes(uu),'XLabel'),'Position',[(subplotwidth-(z.ylabelwidth+z.rightylabelwidth+z.rightmargin))/2 (-sum(z.xlabelheight)) 0]);
        
        set(get(figaxes(uu),'YLabel'),'units','centimeter');
        set(get(figaxes(uu),'YLabel'),'VerticalAlignment','Top');
        set(get(figaxes(uu),'YLabel'),'Position',[-z.ylabelwidth (z.imgheight-sum(z.xlabelheight))/2 0]);

        pos(1)  = (length(figaxes)-uu)*(subplotwidth + z.subplotmargin) + z.ylabelwidth;
        pos(2)  = sum(z.xlabelheight);
        pos(3)  = subplotwidth - (z.ylabelwidth + z.rightmargin + z.rightylabelwidth);
        pos(4)  = z.imgheight - (sum(z.xlabelheight) + t_titleheight + z.topmargin);

        set(figaxes(uu),'Position',pos);
        
        if ~isempty(z.rightYlimits)
            if ~isempty(z.rightYlimits{uu})
                a2 = axes('YAxisLocation', 'Right');
                set(a2, 'color', 'none');
                set(a2, 'XTick', []);
                set(a2, 'YLim', z.rightYlimits{uu});
                if ~isempty(z.rightYticks{uu})
                    set(a2, 'YTicks', z.rightYticks{uu});
                end
                set(a2,'units','centimeter');
                set(a2,'Position',pos);
            end
        end
    end
else
    for uu=1:numSubPlots
        if z.singleHorizontalAxis
            error('fix this first')
            subplotheight = (z.imgheight - (z.subplotmargin*(numSubPlots-1) + z.xlabelheight(end)))/numSubPlots;
        else
            subplotheight = (z.imgheight - z.subplotmargin*(numSubPlots-1) -z.topmargin)/numSubPlots;
        end
        
        set(figaxes(uu),'units','centimeter');
        
        if isempty(get(get(figaxes(uu),'Title'),'String')) || (uu == length(figaxes) && z.singleHorizontalAxis)
            t_titleheight = 0;
        else
            t_titleheight = z.titleheight(uu);
            
            set(get(figaxes(uu),'Title'),'units','centimeter');
            set(get(figaxes(uu),'Title'),'VerticalAlignment','middle');            
            
            if z.centerTitleOverEntireFigure
                if z.singleHorizontalAxis
                    figaxes(uu).Title.Position = [((z.imgwidth-(z.ylabelwidth+z.rightylabelwidth))-z.imgwidth/2) (subplotheight) 0];
                else
                    figaxes(uu).Title.Position = [((z.imgwidth-(z.ylabelwidth+z.rightylabelwidth))-z.imgwidth/2) (subplotheight - (z.xlabelheight(uu) + z.topmargin + t_titleheight/2)) 0];
                end
            else
                if z.singleHorizontalAxis
                    figaxes(uu).Title.Position = [(z.imgwidth-z.ylabelwidth)/2 (subplotheight) 0];
                else
                    figaxes(uu).Title.Position = [(z.imgwidth-z.ylabelwidth)/2 (subplotheight - (z.xlabelheight(uu) + z.topmargin + t_titleheight/2)) 0];
                end
            end
        end
        
        pos(1)  = z.ylabelwidth;
        pos(2)  = (uu-1)*(subplotheight + z.subplotmargin) + z.xlabelheight(uu);
        pos(3)  = z.imgwidth - (z.ylabelwidth + z.rightylabelwidth + z.rightmargin);
        pos(4)  = subplotheight - (z.xlabelheight(uu) + z.topmargin + t_titleheight);
        
        if z.singleHorizontalAxis
            pos(4)  = subplotheight;
        end
        
        if currentAxes == figaxes(uu)
            pos(1)  = pos(1) + legendMargin(4);
            pos(2)  = pos(2) + legendMargin(3);
            pos(3)  = pos(3) - (legendMargin(2) + legendMargin(4));
            pos(4)  = pos(4) - (legendMargin(1) + legendMargin(3));
        end
        
        set(figaxes(uu),'Position',pos);
        
        
        
        figaxes(uu).XLabel.Units                = 'centimeter';
        figaxes(uu).XLabel.VerticalAlignment    = 'Bottom';
        figaxes(uu).XLabel.HorizontalAlignment  = 'Center';
        
        if z.singleHorizontalAxis && uu > 1
            figaxes(uu).XTickLabel = '';
            figaxes(uu).XLabel.String = '';
        else
            figaxes(uu).XLabel.Position = [(z.imgwidth-(z.ylabelwidth+z.rightylabelwidth))/2   (-z.xlabelheight(uu))+z.xlabel_dy    0];
        end
        
        figaxes(uu).YLabel.Units = 'centimeter';
        figaxes(uu).YLabel.VerticalAlignment = 'Top';
        figaxes(uu).YLabel.HorizontalAlignment = 'center';
        
%         if z.singleHorizontalAxis && uu > 1
%             figaxes(uu).YLabel.String = '';
%         elseif z.singleHorizontalAxis && uu == 1
%             figaxes(uu).YLabel.Position = [-z.ylabelwidth (z.imgheight-z.xlabelheight(uu))/2 0];
%         else
%         if z.singleHorizontalAxis
%             figaxes(uu).YLabel.Position = [-z.ylabelwidth (z.imgheight-z.xlabelheight(uu))/2 0];
%         else
            figaxes(uu).YLabel.Position = [-z.ylabelwidth (subplotheight-z.xlabelheight(uu))/2 0];
%             figaxes(uu).YLabel.Position = [-z.ylabelwidth (subplotheight-z.xlabelheight(uu))/2 0];
%         end

        
        
        
        if ~isempty(z.rightYlimits)
            if ~isempty(z.rightYlimits{uu})
                a2 = axes('YAxisLocation', 'Right');
                set(a2, 'color', 'none');
                set(a2, 'XTick', []);
                set(a2, 'YLim', z.rightYlimits{uu});
                set(a2,'units','centimeter');
                set(a2,'Position',pos);
                set(figaxes(uu),'box','off')
            end
        end
    end
end

drawnow;

%% Draw the legend

if ~drawLegend
    return;
end

set(z.subplotHandle,'units','centimeters');
ax_pos = get(z.subplotHandle,'position');



legendAxes = axes;
legendAxes.UserData.FLegend = true;
if ~isempty(z.color)
    legendAxes.Color = z.color;
end

if strcmp(z.transparent,'yes') || all(z.transparent == 1)
    axis off;
end

hold on
   


if ~isempty(z.title)
    ploty   = lh - (z.spacing + z.textheight(1)/2);
    text(z.spacing,ploty-0.05+z.textverticalshift,z.title,'VerticalAlignment','middle',...
                                              'FontName','CMR6',...
                                              'FontSize',12,...
                                              'Interpreter',z.interpreter);
end
    
% Plotting the legend
for oo=1:numLabels
    if ~isempty(z.title)    
        if strcmp(z.direction,'vertical')
            col = ceil(oo / (z.rows-1));
            row = mod(oo-1, (z.rows-1))+1+1;
        elseif strcmp(z.direction,'horizontal')            
            col = mod(oo-1, z.columns)+1;            
            row = ceil(oo / z.columns)+1;
        end
    else
        if strcmp(z.direction,'vertical')
            col = ceil(oo / (z.rows));
            row = mod(oo-1, (z.rows))+1;
        elseif strcmp(z.direction,'horizontal')            
            col = mod(oo-1, z.columns)+1;            
            row = ceil(oo / z.columns);
        end
    end

    plotx1  = z.spacing + 2*z.spacing * (col -1) + sum(z.textwidth(1:(col-1))) + sum(z.markerwidth(1:(col-1)));
    plotx2  = plotx1 + z.markerwidth(col);        
    plotxt  = plotx2 + z.spacing;

    ploty   = lh - (z.spacing + sum(z.vspacing(1:(row-1))) + sum(z.textheight(1:(row-1))) + z.textheight(row)/2);
    props   = get(z.plotHandle(oo));
    
%% Determine what kind of marker we need to draw
    
    if isa(z.plotHandle(oo),'matlab.graphics.chart.primitive.Bar')
        iWillDraw   = 'Bar';
    elseif isa(z.plotHandle(oo),'matlab.graphics.chart.primitive.Line')
        iWillDraw   = 'Line';
    elseif isa(z.plotHandle(oo),'matlab.graphics.chart.primitive.Scatter') 
        iWillDraw   = 'Scatter';
    elseif isa(z.plotHandle(oo),'matlab.graphics.chart.primitive.ErrorBar') 
        iWillDraw   = 'Line';
    elseif isa(z.plotHandle(oo),'matlab.graphics.primitive.Rectangle')
        iWillDraw   = 'Rectangle';
    else
        z.plotHandle(oo)
        error('You need to add the %s class.',class(z.plotHandle(oo)))
    end
    
    if strcmp(iWillDraw,'Line')
        plot([plotx1 plotx2],[ploty ploty],...
            'Color',get(z.plotHandle(oo),'Color'),...
            'LineStyle',get(z.plotHandle(oo),'LineStyle'),...
            'LineWidth',get(z.plotHandle(oo),'LineWidth'),...
            'Marker','none',...
            'MarkerSize',get(z.plotHandle(oo),'MarkerSize'),...
            'MarkerEdgeColor',get(z.plotHandle(oo),'MarkerEdgeColor'),...
            'MarkerFaceColor',get(z.plotHandle(oo),'MarkerFaceColor'),...
            'UserData',get(z.plotHandle(oo),'UserData'));

        if ~strcmp(props.Marker,'none')
            plot(mean([plotx1 plotx2]),ploty,...
                'Color',get(z.plotHandle(oo),'Color'),...
                'LineStyle',get(z.plotHandle(oo),'LineStyle'),...
                'Marker',get(z.plotHandle(oo),'Marker'),...
                'MarkerSize',get(z.plotHandle(oo),'MarkerSize'),...
                'MarkerEdgeColor',get(z.plotHandle(oo),'MarkerEdgeColor'),...
                'MarkerFaceColor',get(z.plotHandle(oo),'MarkerFaceColor'),...
                'UserData',get(z.plotHandle(oo),'UserData'));
        end
    elseif strcmp(iWillDraw,'Rectangle')
        rectangle('Position',[plotx1,ploty-z.textheight(row)/2,plotx2-plotx1,z.textheight(row)],...
            'EdgeColor',get(z.plotHandle(oo),'EdgeColor'),...
            'LineStyle',get(z.plotHandle(oo),'LineStyle'),...
            'LineWidth',get(z.plotHandle(oo),'LineWidth'),...
            'UserData',get(z.plotHandle(oo),'UserData'));
    elseif strcmp(iWillDraw,'Contour')
        plot([plotx1 plotx2],[ploty ploty],...
            'Color',get(z.plotHandle(oo),'Color'),...
            'LineStyle',get(z.plotHandle(oo),'LineStyle'),...
            'LineWidth',get(z.plotHandle(oo),'LineWidth'),...
            'UserData',get(z.plotHandle(oo),'UserData'));
    elseif strcmp(iWillDraw,'ErrorBar')
        plot([plotx1 plotx2],[ploty ploty],...
            'Color',get(z.plotHandle(oo),'Color'),...
            'LineStyle',get(z.plotHandle(oo),'LineStyle'),...
            'LineWidth',get(z.plotHandle(oo),'LineWidth'),...
            'Marker','none',...
            'MarkerSize',get(z.plotHandle(oo),'MarkerSize'),...
            'MarkerEdgeColor',get(z.plotHandle(oo),'MarkerEdgeColor'),...
            'MarkerFaceColor',get(z.plotHandle(oo),'MarkerFaceColor'),...
            'UserData',get(z.plotHandle(oo),'UserData'));

        if ~strcmp(props.Marker,'none')
            plot(mean([plotx1 plotx2]),ploty,...
                'Color',get(z.plotHandle(oo),'Color'),...
                'LineStyle',get(z.plotHandle(oo),'LineStyle'),...
                'Marker',get(z.plotHandle(oo),'Marker'),...
                'MarkerSize',get(z.plotHandle(oo),'MarkerSize'),...
                'MarkerEdgeColor',get(z.plotHandle(oo),'MarkerEdgeColor'),...
                'MarkerFaceColor',get(z.plotHandle(oo),'MarkerFaceColor'),...
                'UserData',get(z.plotHandle(oo),'UserData'));
        end
    elseif strcmpi(iWillDraw,'Scatter')
        scatter(mean([plotx1 plotx2]),ploty,...
            'CData',get(z.plotHandle(oo),'CData'),...
            'SizeData',get(z.plotHandle(oo),'SizeData'),...
            'Marker',get(z.plotHandle(oo),'Marker'),...
            'MarkerEdgeColor',get(z.plotHandle(oo),'MarkerEdgeColor'),...
            'MarkerFaceColor',get(z.plotHandle(oo),'MarkerFaceColor'),...
            'UserData',get(z.plotHandle(oo),'UserData'));            
    elseif strcmpi(iWillDraw,'Bar')
        
        if strcmpi(get(z.plotHandle(oo),'FaceColor'),'flat')
            set(z.plotHandle(oo),'FaceColor','b');
        end
        
        tRec     = rectangle('Position',[plotx1,ploty-z.textheight(row)/2,plotx2-plotx1,z.textheight(row)]);
        tRec.UserData = get(z.plotHandle(oo),'UserData');
        
        try %#ok<TRYNC>
            tRec.FaceColor  = get(z.plotHandle(oo),'FaceColor');
        end
        try %#ok<TRYNC>
            tRec.EdgeColor  = get(z.plotHandle(oo),'EdgeColor');
        end
        try %#ok<TRYNC>
            tRec.LineStyle  = get(z.plotHandle(oo),'LineStyle');
        end
        try %#ok<TRYNC>
            tRec.LineWidth  = get(z.plotHandle(oo),'LineWidth');
        end
    end

    
    thisLabel   = get(z.plotHandle(oo),'DisplayName');

    if ~isempty(z.labels)
        if iscell(z.labels)
            if oo <= length(z.labels) 
                if ~isempty(z.labels{oo})
                    thisLabel = z.labels{oo};
                end
            end
        end
    end

    text(plotxt,ploty-0.05+z.textverticalshift,thisLabel,'VerticalAlignment','middle',...
                                              'FontName','CMR6',...
                                              'FontSize',12,...
                                              'Color',z.textcolor,...
                                              'Interpreter',z.interpreter);

end

xSpacing = 0.1;
ySpacing = 0.1;

switch lower(z.location)
    case {'north'}
        autoLegendX = ax_pos(1) + (ax_pos(3) / 2 - lw/2);
        autoLegendY = ax_pos(2) + (ax_pos(4) - (ySpacing + lh));
        
	case {'northoutside','north outside'}
        autoLegendX = ax_pos(1) + (ax_pos(3)-lw)/2 - max([lw-ax_pos(3) 0])/2;
        autoLegendY = ax_pos(2) + ax_pos(4) + 2*z.spacing;

    case {'northeast','north east'}
        autoLegendX = ax_pos(1) + (ax_pos(3) - (xSpacing + lw));
        autoLegendY = ax_pos(2) + (ax_pos(4) - (ySpacing + lh));

    case {'east'}
        autoLegendX = ax_pos(1) + (ax_pos(3) - (xSpacing + lw));
        autoLegendY = ax_pos(2) + (ax_pos(4) / 2 - lh/2);

	case {'eastoutside','east outside'}
        autoLegendX = ax_pos(1) + ax_pos(3) + 2*z.spacing;
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
        fprintf('The option ''%s'' does not exist!\n',location)
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
    