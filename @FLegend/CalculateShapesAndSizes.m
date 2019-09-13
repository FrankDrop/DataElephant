function z = CalculateShapesAndSizes(z)

    if ~isempty(z.Labels)
        z.NumLabels = min(length(z.PlotHandle),length(z.Labels));
    else
        z.NumLabels = length(z.PlotHandle);
    end

    if isempty(z.Columns) && ~isempty(z.Rows)
        if z.NumLabels < z.Rows
            z.Rows = z.NumLabels;
        end

        if strcmp(z.Orientation,'horizontal')
            z.Columns   = ceil(z.NumLabels / z.Rows);      
            z.Rows      = ceil(z.NumLabels / z.Columns);
        else
            z.Columns = ceil(z.NumLabels / z.Rows);
        end
    elseif ~isempty(z.Columns) && isempty(z.Rows)
        if z.NumLabels < z.Columns
            z.Columns = z.NumLabels;
        end
        if strcmp(z.Orientation,'horizontal')
            z.Rows      = ceil(z.NumLabels / z.Columns);
        else
            z.Rows      = ceil(z.NumLabels / z.Columns);
            z.Columns   = ceil(z.NumLabels / z.Rows);
        end
    elseif isempty(z.Columns) && isempty(z.Rows)
        z.Rows      = z.NumLabels;
        z.Columns   = 1;
    else
        z.AutoReduceColumnsAndRows
        if strcmp(z.AutoReduceColumnsAndRows,'yes')
            if z.NumLabels < z.Rows
                z.Rows = z.NumLabels;
            end
            if strcmp(z.Orientation,'horizontal')
                z.Columns   = ceil(z.NumLabels / z.Rows);        
                z.Rows      = ceil(z.NumLabels / z.Columns);
            else
                z.Columns = ceil(z.NumLabels / z.Rows);
            end
        else
            disp('boo');
            % maintain the number of columns and rows as specified by user.
        end
    end

    if isempty(z.PlotHandle) && ~isempty(z.Title)
        z.Rows      = 1;
        z.Columns   = 1;
    elseif ~isempty(z.Title) 
        z.Rows      = z.Rows + 1;
    end
    
    z.TextWidth     = FLegend.RepeatRequiredTimes(z.TextWidth,z.Columns,false);
    z.MarkerWidth   = FLegend.RepeatRequiredTimes(z.MarkerWidth,z.Columns,false);
    z.TextHeight    = FLegend.RepeatRequiredTimes(z.TextHeight,z.Rows,false);
    
    z.LegendItemHorizontalSpacing   = FLegend.RepeatRequiredTimes(z.LegendItemHorizontalSpacing,    z.Columns-1,false);
    z.LegendMarkerTextSpacing       = FLegend.RepeatRequiredTimes(z.LegendMarkerTextSpacing,        z.Columns,false);
    z.LegendItemVerticalSpacing     = FLegend.RepeatRequiredTimes(z.LegendItemVerticalSpacing,      z.Rows-1,false);
    

%% Figure padding

    if numel(z.Padding) == 1
        z.Padding     = z.Padding*[1 1 1 1];
    elseif numel(z.Padding) ~= 4
        error('The ''Padding'' setting should be a scalar or a vector of length 4.')
    end
    
    if isempty(z.PaddingTop)
        z.PaddingTop = z.Padding(1);
    end
    
    if isempty(z.PaddingRight)
        z.PaddingRight = z.Padding(2);
    end
    
    if isempty(z.PaddingBottom)
        z.PaddingBottom = z.Padding(3);
    end
    
    if isempty(z.PaddingLeft)
        z.PaddingLeft = z.Padding(4);
    end
    
%% Legend padding

    if numel(z.LegendPadding) == 1
        z.LegendPadding     = z.LegendPadding*[1 1 1 1];
    elseif numel(z.LegendPadding) ~= 4
        error('The ''LegendPadding'' setting should be a scalar or a vector of length 4.')
    end
    
    if isempty(z.LegendPaddingTop)
        z.LegendPaddingTop = z.LegendPadding(1);
    end
    
    if isempty(z.LegendPaddingRight)
        z.LegendPaddingRight = z.LegendPadding(2);
    end
    
    if isempty(z.LegendPaddingBottom)
        z.LegendPaddingBottom = z.LegendPadding(3);
    end
    
    if isempty(z.LegendPaddingLeft)
        z.LegendPaddingLeft = z.LegendPadding(4);
    end
    


% Removed support for legends outside the plotting area
%     switch lower(z.Location)
%         case {'north outside','northoutside'}
%             z.LegendMargin = [z.LegendHeightlh+z.LegendItemSpacing*2 0 0 0];
%         case {'east outside','eastoutside'}
%             z.LegendMargin = [0 z.LegendWidth+z.LegendItemSpacing*2 0 0];
%         case {'south outside','southoutside'}
%             z.LegendMargin = [0 0 z.LegendHeightlh+z.LegendItemSpacing*2 0];
%         case {'west outside','westoutside'}
%             z.LegendMargin = [0 0 0 z.LegendWidth+z.LegendItemSpacing*2];
%         otherwise
%             z.LegendMargin = [0 0 0 0];
%     end

end

