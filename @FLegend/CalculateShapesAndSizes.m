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
        if z.NumLabels < z.Rows
            z.Rows = z.NumLabels;
        end
        if strcmp(z.Orientation,'horizontal')
            z.Columns   = ceil(z.NumLabels / z.Rows);        
            z.Rows      = ceil(z.NumLabels / z.Columns);
        else
            z.Columns = ceil(z.NumLabels / z.Rows);
        end
    end

    if isempty(z.PlotHandle) && ~isempty(z.Title)
        z.Rows      = 1;
        z.Columns   = 1;
    elseif ~isempty(z.Title) 
        z.Rows      = z.Rows + 1;
    end

    % If the user provides only one value for the TextWidth, we simply use
    % this one for all Columns.
%     if length(z.TextWidth) < z.Columns
%         z.TextWidth     = repmat(z.TextWidth,1,ceil(z.Columns / length(z.TextWidth)));
%     end
    
    z.TextWidth     = FLegend.RepeatRequiredTimes(z.TextWidth,z.Columns,false);
    z.MarkerWidth   = FLegend.RepeatRequiredTimes(z.MarkerWidth,z.Columns,false);
    z.TextHeight    = FLegend.RepeatRequiredTimes(z.TextHeight,z.Rows,false);
    
%     if length(z.MarkerWidth) < z.Columns
%         z.MarkerWidth   = repmat(z.MarkerWidth,1,ceil(z.Columns / length(z.MarkerWidth)));
%     end


    
%     if length(z.TextHeight) < z.Rows
%         z.TextHeight    = repmat(z.TextHeight,1,ceil(z.Rows / length(z.TextHeight)));
%     end



%     if length(z.vSpacing) < z.Rows
%         z.vSpacing    = repmat(z.VerticalSpacing,1,ceil(z.Rows / length(z.vSpacing)));
%     end



    % If the user provides more values than Columns, we simply take the
    % ones we need.
%     z.TextWidth         = z.TextWidth(1:z.Columns);
%     z.MarkerWidth       = z.MarkerWidth(1:z.Columns);
%     z.TextHeight        = z.TextHeight(1:z.Rows);
%     z.vSpacing          = z.vSpacing(1:(z.Rows-1));


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
    
%% Legend sizes
    z.LegendWidth  = z.LegendPaddingLeft + ...
                     sum(z.MarkerWidth) + ...
                     sum(z.TextWidth) + ...
                     z.LegendPaddingRight;
                 %z.Columns * 2 * z.Spacing + ...

    % Calculate the height of the legend
    z.LegendHeight  = z.LegendPaddingTop + ...
                      sum(z.TextHeight) + ...
                      z.LegendPaddingBottom;

% Removed support for legens outside the plotting area
%     switch lower(z.Location)
%         case {'north outside','northoutside'}
%             z.LegendMargin = [z.LegendHeightlh+z.Spacing*2 0 0 0];
%         case {'east outside','eastoutside'}
%             z.LegendMargin = [0 z.LegendWidth+z.Spacing*2 0 0];
%         case {'south outside','southoutside'}
%             z.LegendMargin = [0 0 z.LegendHeightlh+z.Spacing*2 0];
%         case {'west outside','westoutside'}
%             z.LegendMargin = [0 0 0 z.LegendWidth+z.Spacing*2];
%         otherwise
%             z.LegendMargin = [0 0 0 0];
%     end

end

