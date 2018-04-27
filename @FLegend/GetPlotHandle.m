function z = GetPlotHandle(z)
    if isempty(z.PlotHandle)
        z.PlotHandle    = z.AxesHandle.Children;

        kk  = 1;
        l   = gobjects(1,1);

        for oo=1:length(z.PlotHandle)
            if strncmp(class(z.PlotHandle(oo)),'matlab.graphics.chart.primitive.',length('matlab.graphics.chart.primitive.'))
                l(kk,1)     = z.PlotHandle(oo); 
                kk          = kk +1;
            end
        end
        z.PlotHandle = flipud(l);
    end
end

