function [r_i,f_i] = getIndividual(r_i, f_i, fields, fnc, idx, n_choices)

    for oo=1:length(fields)
        if isfield(r_i,fields{oo}) && isfield(f_i,fields{oo})
            if isfield(f_i.(fields{oo}),'f')                
                if strcmp(f_i.(fields{oo}).f,fnc)
                    assert(length(r_i.(fields{oo})) == n_choices,'Something wrong here!');
                    r_i.(fields{oo})  = r_i.(fields{oo}){idx};
                end                
                f_i.(fields{oo}) = rmfield(f_i.(fields{oo}),'f');
            end
        end
    end
end