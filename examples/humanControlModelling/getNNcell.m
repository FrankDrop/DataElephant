function NN = getNNcell(varargin) 
    NN      = struc(varargin{:});
    NN      = removeDuplicateARXModels(NN);
    NN      = mat2cell(NN,ones(size(NN,1),1),size(NN,2));
end