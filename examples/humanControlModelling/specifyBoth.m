function [] = specifyBoth(z,arg1,arg2)
    if ~isempty(z.(arg1)) && isempty(z.(arg2))
        error('You specified %s, but not %s.',arg1,arg2)
    elseif isempty(z.(arg1)) && ~isempty(z.(arg2))
        error('You specified %s, but not %s.',arg2,arg1)
    end
end