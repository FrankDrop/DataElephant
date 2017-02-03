function fldr = tidyfoldername(fldr)
% Windows matlab can handle forward slashes, even though windows works with
% backslashes natively.

    if ~isempty(fldr)
        % First replace all backslashes with forward slashes
        fldr    = strrep(fldr,'\','/');
        
        % Remove multiple slashes
        fldr    = regexprep(fldr,'[\/]*','\/');
        
        % Remove a slash at the end
        if strcmp(fldr(end),'/')
            fldr    = fldr(1:(end-1));
        end
    end
end