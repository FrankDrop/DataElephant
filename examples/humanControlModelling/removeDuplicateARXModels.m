function NN = removeDuplicateARXModels(NN)

    ni = (size(NN,2)-1)/2;

    if ni ~= round(ni)
        error('something wrong with the NN matrix you provided.')
    end
    
    % Also remove the models where all nb parameters are zero
    NN(all(NN(:,1+(1:ni)) == 0,2),:) = [];
    
    minnk = zeros(ni,1);
    for oo=1:ni
        minnk(oo)   = min(unique(NN(:,ni+oo+1)));
    end
    
    for oo=1:ni
        NN(NN(:,oo+1) == 0 & NN(:,ni+oo+1) > minnk(oo),:) = [];
    end
    
end