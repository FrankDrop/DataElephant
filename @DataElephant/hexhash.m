function id_hex = hexhash(obj,dec_hash,varargin)    
    if mod(length(dec_hash),obj.hashlength) ~= 0
        error('boo!')
    end
    
    if ~isempty(varargin)
        stepsBack   = varargin{1};
    else
        stepsBack   = 1;
    end
    
    if isempty(dec_hash)
        id_hex = '';
    else
        if length(dec_hash) >= stepsBack*obj.hashlength
            hex_hash    = dec2hex(dec_hash((end-stepsBack*obj.hashlength+1):(end-(stepsBack-1)*obj.hashlength)));
            id_hex      = reshape(hex_hash.',1,[]);
        else
            id_hex      = '';
        end
    end
end