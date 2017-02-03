function obj = makeFunctionalCache(obj,inputName,inputContent)

    if obj.verbose
        fprintf('\tI will make a fnc hash cache for %s with %i entries.\n',inputName,length(inputContent));
    end
    
    if ~iscolumn(inputContent)
        error('You should provide each functional as a cell column vector (%s).',obj.steps(ii).input{aa});
    end

    fnchashtmp  = -1*ones(length(inputContent),16,'uint8');

    for uu=1:length(inputContent)
        fnchashtmp(uu,:) = CalcMD5(inputContent{uu},'char','Dec');
    end
    
    if size(unique(fnchashtmp,'rows'),1) ~= size(fnchashtmp,1)
        error('You should provide unique functionals.')
    end
    
    obj.fnchashcache.(inputName) = fnchashtmp;


    if isnumeric(inputContent{1})
        obj.fastfnchashcache.(inputName) = cell2mat(inputContent);        
    elseif ischar(inputContent{1})
        charhash     = zeros(length(inputContent),16,'uint8');
        for uu=1:length(inputContent)
            charhash(uu,:)   = CalcMD5(inputContent{uu},'char','Dec');
        end
        obj.fastfnchashcache.(inputName)   = charhash;
    else
        error('boo!')
    end
    
end