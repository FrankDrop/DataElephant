function [ varargout ] = splitOutput( out )

    if iscell(out)
        x   = cell(length(out),1);
        y   = cell(length(out),1);
        
        for ii=1:length(out)
            x_y_bits        = regexp(out{ii},',','split');

            if length(x_y_bits) > 2
                error('The syntax of the output definition ''%s'' is wrong. It should be ''x,y'' or ''y''.',out{ii});
            elseif length(x_y_bits) == 2
                x{ii}   = x_y_bits{1};
                y{ii}   = x_y_bits{2};
            else
                x{ii}   = {};
                y{ii}   = x_y_bits{1};
            end
        end
    else
        x_y_bits        = regexp(out,',','split');

        if length(x_y_bits) > 2
            error('The syntax of the output definition ''%s'' is wrong. It should be ''x,y'' or ''y''.',out);
        elseif length(x_y_bits) == 2
            x  = x_y_bits{1};
            y  = x_y_bits{2};
        else
            x   = [];
            y   = x_y_bits{1};
        end
    end
    
    if nargout == 2
        varargout{1} = x;
        varargout{2} = y;
    elseif nargout == 1
        varargout{1} = y;
    end

end

