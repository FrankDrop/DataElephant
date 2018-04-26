classdef FLegend
    
    methods(Static, Access = public)
        
        z = DrawLegend(z);
        z = GetPlotHandle(z);
        z = ParseInputs(varargin);
        z = CalculateShapesAndSizes(z);
        z = GetSubPlotProperties(z);
        z = SetSize(z);
        z = StretchSubFigures(z);
        
        h = RepeatRequiredTimes(in,N,flip);
        
        function h = FLegend(varargin)

            % FLegend(varargin)
            % Example:
            % FLegend('TextWidth',[],'Rows',2,'Location','SouthEast','imgscale',1.5,'imgheight',8,'imgwidth',5);
            % 
            % Other options:
            % - Rows
            % - Columns
            % - MarkerWidth
            % - TextWidth
            % - TextHeight
            % - Location
            % - TextHeight
            % - Spacing
            % - imgscale
            % - imgwidth
            % - imgheight
            % - legendx
            % - legendy
            % - legend_dx
            % - legend_dy
            % - subplotmargin
            % - type

            z               = FLegend.ParseInputs(varargin{:});
            z               = FLegend.GetPlotHandle(z);            
            z               = FLegend.CalculateShapesAndSizes(z);
            drawnow;
            z               = FLegend.SetSize(z);
            z               = FLegend.GetSubPlotProperties(z);
            z               = FLegend.StretchSubFigures(z);
            drawnow;
        end
    end
end

