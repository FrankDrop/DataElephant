function output_txt = FCursor(~,event_obj)
% ~            Currently not used (empty)
% event_obj    Object containing event data structure
% output_txt   Data cursor text (string or cell array of strings)

pos         = get(event_obj,'Position');
output_txt  = [get(get(event_obj,'Target'),'DisplayName') sprintf('\nx: %1.4f\ny: %1.4f',pos(1),pos(2))];