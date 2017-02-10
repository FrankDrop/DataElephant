function [r,id_cum] = dbug(obj,name,varargin)

    tmp_save        = obj.save_hdd;    
    
    [r,id_cum]      = get(obj,name,varargin{:});
    
    
    obj.save_hdd    = tmp_save;

end