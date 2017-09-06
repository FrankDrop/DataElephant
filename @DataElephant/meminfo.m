function meminfo(obj,varargin)

    updateTree(obj);
    
    fprintf('\tThere are %i step results stored in memory, of which %i are new.\n',length(obj.hash),sum(obj.new));
    fprintf('\tThere are %i decisions stored in memory, of which %i are new.\n',length(obj.dec_hash),sum(obj.dec_new));
    
    fprintf('\tMy ID is %s.\n',obj.myid);
    
    fprintf('<a href="matlab:%s.info">Show process info.</a>\n',inputname(1));
    
end