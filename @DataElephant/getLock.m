function gotConfirmed = getLock(obj,filename,keepWaiting)
%     if obj.verbose
%         fprintf('Something asked for a lock on %s with %i.',filename,keepWaiting);
%     end

    if ~obj.flock
        gotConfirmed = true;
        return;
    end
    gotConfirmed = doSomethingWithLock(obj,1,filename,keepWaiting);
    
end