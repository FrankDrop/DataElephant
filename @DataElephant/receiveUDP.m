function mssg = receiveUDP(obj,port)
    import java.io.*
    import java.net.DatagramSocket
    import java.net.DatagramPacket
    import java.net.InetAddress

    mssg        = int8(zeros(obj.flockpacketlength,1));
    dp          = DatagramPacket(zeros(1,length(mssg),'int8'),length(mssg)); % Will not throw an error.

    try
        obj.socket  = DatagramSocket(port); % Will try to bind to the port we got assigned to when sending. If it doesn't work we need to try the sending again.
        obj.socket.setSoTimeout(1000);
        obj.socket.setReuseAddress(1);
    catch err
        if ~isempty(strfind(err.message,'java.net.SocketException'))
            obj.socket.close;
        else % Some error we did not expect, so let's rethrow it.
            rethrow(err);
        end
    end

    % So apparently we are now bound to the same socket from where
    % we sent. We should also get an answer back on this port.

    try
        obj.socket.receive(dp);
        mssg = dp.getData;
        mssg = mssg(1:dp.getLength);
    catch receiveError
        if ~isempty(strfind(receiveError.message,'java.net.SocketTimeoutException'))
            if obj.flockverbose
                fprintf('Timeout.\n');
            end
        else
            rethrow(receiveError)
        end
    end
    obj.socket.close;
end