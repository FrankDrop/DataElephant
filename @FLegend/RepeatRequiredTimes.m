function h = RepeatRequiredTimes(in,N,flip)

    h   = repmat(in,1,ceil(N / length(in)));
    
    if flip
        h   = h(end:-1:(end-N+1));
    else
        h   = h(1:1:N);
    end

end

