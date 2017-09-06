function gotConfirmed = releaseLock(obj,filename,keepWaiting)
    if ~obj.flock
        gotConfirmed = true;
        return;
    end
    gotConfirmed = doSomethingWithLock(obj,0,filename,keepWaiting);
end