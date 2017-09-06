function mssg = createMessage(obj,action,filename)
    mssg                                    = int8(zeros(obj.flockpacketlength,1));
    mssg(1)                                 = int8(action);
    mssg(7:(7+length(obj.myid)-1))          = int8(obj.myid);
    if ~isempty(filename)
        mssg(107:(107+length(filename)-1))  = int8(filename);
    end
end