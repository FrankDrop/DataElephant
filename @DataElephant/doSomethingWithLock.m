function gotConfirmed = doSomethingWithLock(obj,action,filename,keepWaiting)
    tx_mssg = createMessage(obj,action,filename);
    gotConfirmed = false;
    while ~gotConfirmed
        port            = sendUDP(obj,tx_mssg);
        if obj.flockverbose
            fprintf('Sent from port %i.\n',port);
        end
        mssg            = receiveUDP(obj,port);
        [answer,id,fn]  = obj.readMessage(mssg);

        if obj.flockverbose
            fprintf('Action : %i.\nID : %s.\nFilename : %s.\n',answer,id,fn);
        end

        if ~isempty(filename)
            correctFilename = strcmp(fn,filename);
        else
            correctFilename = true;
        end
        gotConfirmed    = (answer == int8(action) && strcmp(obj.myid,id) && correctFilename) || ~keepWaiting;
    end
end