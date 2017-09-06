function gotConfirmed = releaseAllLocks(obj,keepWaiting)
    if ~obj.flock
        gotConfirmed = true;
        return;
    end
    gotConfirmed = doSomethingWithLock(obj,2,[],keepWaiting);
end