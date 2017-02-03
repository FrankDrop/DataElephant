function [answer,id,filename] = readMessage(mssg)
    answer      = mssg(1);

    if length(mssg) == 362 % Check for correct length!
        id          = char(mssg(7:106)).';
        id          = id(id > 0);

        filename    = char(mssg(107:362)).';
        filename    = filename(filename > 0);
    else
        id          = [];
        filename    = [];
    end
end