function port = sendUDP(obj,mssg)
    import java.io.*
    import java.net.DatagramSocket
    import java.net.DatagramPacket
    import java.net.InetAddress

    try %#ok<TRYNC>
        obj.socket.close;
    end

    try
        obj.socket  = DatagramSocket();
        port        = obj.socket.getLocalPort();
        if obj.flockverbose
            fprintf('I was assigned port %i.\nMessage is |%s| .\n',port,mssg);
        end
        mssg        = obj.addPort(mssg,port);
        if obj.flockverbose
            fprintf('Message, to be sent to %s at port %i is |%s|.\n\n',char(obj.flockip.toString()),obj.flockport,char(mssg));
        end
        dp          = DatagramPacket(mssg, length(mssg), obj.flockip, obj.flockport); % Will not throw errors
        obj.socket.send(dp);
        obj.socket.close;
    catch err
        % Actually if something goes wrong here we can't do much,
        % there must be something seriously wrong. Perhaps it's
        % best to just rethrow the error?
        rethrow(err);
    end
end