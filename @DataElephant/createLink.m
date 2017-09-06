function [ s ] = createLink( n )
    s   = sprintf('<a href="matlab:open %s">%s</a>',n,n);
end

