function id_hex = hexhashold(obj,dec_hash)
    
    if mod(length(dec_hash),obj.hashlength) ~= 0
        error('boo!')
    end
    
    if isempty(dec_hash)
        id_hex = '';
    else
        id_hex = reshape(dec2hex(dec_hash((end-(obj.hashlength-1)):end)).',1,[]);
    end
end