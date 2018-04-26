function z = ParseInputs(varargin)

    if any(cellfun(@(x)isa(x,'matlab.ui.Figure'),varargin))
        FigureHandle    = varargin{cellfun(@(x)isa(x,'matlab.ui.Figure'),varargin)};
        varargin(cellfun(@(x)isa(x,'matlab.ui.Figure'),varargin))     = [];
    else
        FigureHandle    = gcf;
    end
    
    if any(cellfun(@(x)isa(x,'matlab.graphics.axis.Axes'),varargin))
        AxesHandle      = varargin{cellfun(@(x)isa(x,'matlab.graphics.axis.Axes'),varargin)};
        varargin(cellfun(@(x)isa(x,'matlab.graphics.axis.Axes'),varargin))     = [];
    else
        AxesHandle      = gca;
    end
    
    plotFunction        = @(x)isa(x,'matlab.graphics.Graphics');
    if any(cellfun(plotFunction,varargin))
        PlotHandle      = varargin{cellfun(plotFunction,varargin)};
        varargin(cellfun(plotFunction,varargin))     = [];
    else
        PlotHandle      = [];
    end
    
    labelFunction       = @(x)(iscell(x) && all(cellfun(@(y)ischar(y),x)));
    if any(cellfun(labelFunction,varargin))
        Labels          = varargin{cellfun(labelFunction,varargin)};
        varargin(cellfun(labelFunction,varargin))     = [];
    else
        Labels          = [];
    end
        

    p = inputParser;
    
    p.addParameter('Show','yes',@(x)isYesNoString(x));
    
    p.addParameter('Rows', [], @(x)isnumeric(x));
    p.addParameter('Columns', [], @(x)isnumeric(x));
    p.addParameter('MarkerWidth', 0.3, @(x)isnumeric(x));
    p.addParameter('TextWidth', 1, @(x)isnumeric(x));
    p.addParameter('TextHeight', 0.25, @(x)isnumeric(x));
    p.addParameter('Location', 'SouthWest',@(x)isOptionsString(x,{'North','NorthEast','East','SouthEast','South','SouthWest','West','NorthWest'}));

    % Paper options
    p.addParameter('Paper','yes',@(x)isYesNoString(x));

    % Legend options
    p.addParameter('Box','on',@(x)isYesNoString(x));
    p.addParameter('Orientation','vertical',@(x)isOptionsString(x,{'vertical','horizontal'}));
    p.addParameter('FontSize', 12,@(x)isnumerical(x));
    p.addParameter('FontName', 'CMR6',@(x)ischar(x));
    p.addParameter('TextColor',[0 0 0],@(x)(isnumeric(x) && numel(x) == 3));
    p.addParameter('Interpreter','none',@(x)ischar(x));

    % Legend sizing options
    p.addParameter('LegendPadding',0.05, @(x)isnumeric(x));
    
    p.addParameter('LegendPaddingTop', 0.05, @(x)isnumeric(x));
    p.addParameter('LegendPaddingBottom', 0.05, @(x)isnumeric(x));
    p.addParameter('LegendPaddingLeft', 0.05, @(x)isnumeric(x));
    p.addParameter('LegendPaddingRight', 0.05, @(x)isnumeric(x));
    
    p.addParameter('TextVerticalShift', 0, @(x)isnumeric(x));
    p.addParameter('TextHorizontalShift', 0, @(x)isnumeric(x));
    
%     p.addParameter('VerticalSpacing', 0.05, @(x)isnumeric(x));
    p.addParameter('ImageScale', 1.5, @(x)isnumeric(x));
    p.addParameter('ImageWidth', 5, @(x)isnumeric(x));
    p.addParameter('ImageHeight', 5, @(x)isnumeric(x));
    p.addParameter('XLabelHeight', 0.75, @(x)isnumeric(x)); % Percentage
    p.addParameter('YLabelWidth', 0.75, @(x)isnumeric(x));
    p.addParameter('XLabelVerticalShift', 0.0, @(x)isnumeric(x));
    p.addParameter('RightYLabelWidth', 0.6, @(x)isnumeric(x));
    p.addParameter('RightMargin', 0.08, @(x)isnumeric(x));
    p.addParameter('TopMargin', 0.05, @(x)isnumeric(x));
    p.addParameter('TitleHeight', 0.75, @(x)isnumeric(x)); % Percentage
    p.addParameter('LegendHorizontalPosition', 0, @(x)isnumeric(x));
    p.addParameter('LegendVerticalPosition', 0, @(x)isnumeric(x));
    p.addParameter('LegendHorizontalShift', 0, @(x)isnumeric(x));
    p.addParameter('LegendVerticalShift', 0, @(x)isnumeric(x));
    p.addParameter('SubPlotSpacing', 0.25, @(x)isnumeric(x));
    p.addParameter('CenterTitleOverEntireFigure','no',@(x)isYesNoString(x));
    p.addParameter('Type', 'plot');




    p.addParameter('Title',[],@(x)ischar(x));
    p.addParameter('RightYLimits',[],@(x)(all(isnumeric(x)) || iscell(x)));
    p.addParameter('RightYTicks',[],@(x)(all(isnumeric(x)) || iscell(x)));
%     p.addParameter('SingleHorizontalAxis','no',@(x)isYesNoString(x));
    p.addParameter('Color',[]);


    p.parse(varargin{:});

    
    z = p.Results;
    
    
    z.FigureHandle              = FigureHandle;
    z.AxesHandle                = AxesHandle;
    z.Labels                    = Labels;
    z.PlotHandle                = PlotHandle;
    
    z.Paper                             = strcmp(z.Paper,'yes');
    z.CenterTitleOverEntireFigure       = strcmp(z.CenterTitleOverEntireFigure,'yes');

    if z.Paper
        z.MarkerWidth               = z.MarkerWidth                 * z.ImageScale;
        z.textverticalshift         = z.TextVerticalShift           * z.ImageScale;
        z.TextWidth                 = z.TextWidth                   * z.ImageScale;
        z.TextHeight                = z.TextHeight                  * z.ImageScale;

        z.ImageWidth                = z.ImageWidth                  * z.ImageScale;
        z.ImageHeight               = z.ImageHeight                 * z.ImageScale;
        z.LegendHorizontalPosition  = z.LegendHorizontalPosition    * z.ImageScale;
        z.LegendVerticalPosition    = z.LegendVerticalPosition      * z.ImageScale;
        z.LegendHorizontalShift     = z.LegendHorizontalShift       * z.ImageScale;
        z.LegendVerticalShift       = z.LegendVerticalShift         * z.ImageScale;
        z.SubPlotSpacing            = z.SubPlotSpacing              * z.ImageScale;
        
        z.XLabelHeight              = z.XLabelHeight                * z.ImageScale;
        z.YLabelWidth               = z.YLabelWidth                 * z.ImageScale;
        z.TitleHeight               = z.TitleHeight                 * z.ImageScale;
        z.RightMargin               = z.RightMargin                 * z.ImageScale;
        z.TopMargin                 = z.TopMargin                   * z.ImageScale;
        z.RightYLabelWidth          = z.RightYLabelWidth            * z.ImageScale;
        z.XLabelVerticalShift       = z.XLabelVerticalShift         * z.ImageScale;
    end
    
    z.SubPlotHorizontalSpacing  = z.SubPlotSpacing;
    z.SubPlotVerticalSpacing    = z.SubPlotSpacing;
    
    
    z.LegendMargin      = [0 0 0 0];
end

function s = isYesNoString(x)
    s = isOptionsString(x,{'yes','no'});
end

function s = isOptionsString(x,opt)
    s = ischar(x) && any(strcmp(x,opt));
end