function id = lastCommonHash(obj,id_req_s)
    dc  = sum(abs(diff(uint8(id_req_s))));
    id  = id_req_s(1,dc == 0);
    id  = id(1:(floor(length(id)/obj.hashlength)*obj.hashlength));
end