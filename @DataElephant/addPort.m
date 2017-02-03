function mssg = addPort(mssg,port)
    charport                            = num2str(port);
    mssg((6-length(charport)+1):6)      = charport;
end