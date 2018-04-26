function z = StretchSubFigures(z)
    z.SubPlotWidth
    z.SubPlotHeight

    for yy=1:z.NumSubPlotRows
        for xx=1:z.NumSubPlotColumns
            pos = zeros(1,4);
            
            pp  = (yy-1)*z.NumSubPlotColumns + xx;
            
            [yy xx]
            
%             if isempty(get(get(figaxes(uu),'Title'),'String'))
%                 t_titleheight = 0;
%             else
%                 t_titleheight = z.titleheight;
%             end
            
            t_titleheight = 0;

            if z.Paper
                z.SubPlots(pp).Units                         = 'centimeter';
                
                z.SubPlots(pp).XLabel.Units                  = 'centimeter';
                z.SubPlots(pp).XLabel.VerticalAlignment      = 'Bottom';
                z.SubPlots(pp).XLabel.HorizontalAlignment    = 'Center';
                
                z.SubPlots(pp).YLabel.Units                  = 'centimeter';
                z.SubPlots(pp).YLabel.VerticalAlignment      = 'Top';
                z.SubPlots(pp).YLabel.HorizontalAlignment    = 'center';       
            end
            
            z.SubPlots(pp).XLabel.Position = convertPositions(z,[(z.SubPlotWidth(xx)-(z.YLabelWidth(xx)+z.RightYLabelWidth(xx)))/2 -z.XLabelHeight(yy) 0]); % + z.RightMargin
            z.SubPlots(pp).YLabel.Position = convertPositions(z,[-z.YLabelWidth(xx) (z.SubPlotHeight(yy)-z.XLabelHeight(yy))/2 0]);

            pos(1)  = sum(z.SubPlotWidth(1:(xx-1)))     + sum(z.SubPlotHorizontalSpacing(1:(xx-1)))     + z.YLabelWidth(xx);
            pos(2)  = sum(z.SubPlotHeight(1:(yy-1)))    + sum(z.SubPlotVerticalSpacing(1:(yy-1)))       + z.XLabelHeight(yy);
            
            pos(3)  = z.SubPlotWidth(xx) - (z.YLabelWidth(xx)  + z.RightYLabelWidth(xx)); %+ z.RightMargin(xx)
            pos(4)  = z.SubPlotHeight(yy) - (z.XLabelHeight(yy)  + t_titleheight); %+ z.TopMargin(yy)
            
            
            z.SubPlots(pp).Position = convertPositions(z,pos);
            
            
%             z.SubPlots((yy-1)*z.NumSubPlotColumns + xx).Position
%             z.SubPlots((yy-1)*z.NumSubPlotColumns + xx).Position = [3 3 7.5 7.5];
%             set(figaxes(uu),'Position',pos);

%             if ~isempty(z.rightYlimits)
%                 if ~isempty(z.rightYlimits{uu})
%                     a2 = axes('YAxisLocation', 'Right');
%                     set(a2, 'color', 'none');
%                     set(a2, 'XTick', []);
%                     set(a2, 'YLim', z.rightYlimits{uu});
%                     if ~isempty(z.rightYticks{uu})
%                         set(a2, 'YTicks', z.rightYticks{uu});
%                     end
%                     set(a2,'units','centimeter');
%                     set(a2,'Position',pos);
%                 end
%             end
        end
        
    end
end

function y = convertPositions(z,x)
    if z.Paper
        y = x;
    else
        if numel(x) == 4
            y = [x(1)/z.ImageHeight x(2)/z.ImageWidth x(3)/z.ImageHeight x(4)/z.ImageWidth];
        elseif numel(x) == 3
            y = [x(1)/z.ImageHeight x(2)/z.ImageWidth x(3)/z.ImageHeight];
        else
            error('ho!')
        end
    end
end

function oldStuff()
    for uu=1:z.NumSubPlots
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

            z.SubPlots.Title.units = 'centimeter';
            z.SubPlots.Title.VerticalAlignment = 'middle';
    %                 set(get(figaxes(uu),'Title'),'units','centimeter');
    %                 set(get(figaxes(uu),'Title'),'VerticalAlignment','middle');            

            if z.CenterTitleOverEntireFigure
                if z.singleHorizontalAxis
                    z.SubPlots(uu).Title.Position = [((z.imgwidth-(z.ylabelwidth+z.rightylabelwidth))-z.imgwidth/2) (subplotheight) 0];
                else
                    z.SubPlots(uu).Title.Position = [((z.imgwidth-(z.ylabelwidth+z.rightylabelwidth))-z.imgwidth/2) (subplotheight - (z.xlabelheight(uu) + z.topmargin + t_titleheight/2)) 0];
                end
            else
                if z.singleHorizontalAxis
                    z.SubPlots(uu).Title.Position = [(z.imgwidth-z.ylabelwidth)/2 (subplotheight) 0];
                else
                    z.SubPlots(uu).Title.Position = [(z.imgwidth-z.ylabelwidth)/2 (subplotheight - (z.xlabelheight(uu) + z.topmargin + t_titleheight/2)) 0];
                end
            end
        end



    %             if z.singleHorizontalAxis
    %                 pos(4)  = subplotheight;
    %             end

    %             if currentAxes == figaxes(uu)
    %                 pos(1)  = pos(1) + legendMargin(4);
    %                 pos(2)  = pos(2) + legendMargin(3);
    %                 pos(3)  = pos(3) - (legendMargin(2) + legendMargin(4));
    %                 pos(4)  = pos(4) - (legendMargin(1) + legendMargin(3));
    %             end

        set(figaxes(uu),'Position',pos);





        if z.singleHorizontalAxis && uu > 1
            figaxes(uu).XTickLabel = '';
            figaxes(uu).XLabel.String = '';
        else
            figaxes(uu).XLabel.Position = [(z.imgwidth-(z.ylabelwidth+z.rightylabelwidth))/2   (-z.xlabelheight(uu))+z.xlabel_dy    0];
        end




    %             if ~isempty(z.rightYlimits)
    %                 if ~isempty(z.rightYlimits{uu})
    %                     a2 = axes('YAxisLocation', 'Right');
    %                     set(a2, 'color', 'none');
    %                     set(a2, 'XTick', []);
    %                     set(a2, 'YLim', z.rightYlimits{uu});
    %                     set(a2,'units','centimeter');
    %                     set(a2,'Position',pos);
    %                     set(figaxes(uu),'box','off')
    %                 end
    %             end
    end
end

