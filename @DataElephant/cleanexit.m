function cleanexit(obj,fnc)
    
    pverbose(obj,'\nClean exit being called by %s function. Taking care of a clean exit, please do not press Cltr + C again.\n',fnc);
    pverbose(obj,'Freeing allocated memory. ');
    
    revertAlloc(obj);
    
    pverbose(obj,'Checking duplicate hashes. ');
    uniqueHashes(obj,true);
    
    pverbose(obj,'Saving. ');
    saveall(obj,true);
    
    pverbose(obj,'Releasing locks. ');
    releaseAllLocks(obj,true);
    
    pverbose(obj,'Closing sockets. ');
    if ~isempty(obj.socket)
        obj.socket.close;
    end
    
    pverbose(obj,'Goodbye. Thanks for spending your CPU time!\n');
end