function r_i = getIndividual(r_i, fields, fnc, idx, n_choices)

    for oo=1:length(fields)
        if isfield(r_i,fields{oo})

            if isfield(r_i.(fields{oo}),'f')
                
                if strcmp(r_i.(fields{oo}).f,fnc)
                    
                    if isfield(r_i.(fields{oo}),'x')
                        assert(iscell(r_i.(fields{oo}).x),'Something wrong here!');
                        assert(length(r_i.(fields{oo}).x) == n_choices,'Something wrong here!');

                        r_i.(fields{oo}).x  = r_i.(fields{oo}).x{idx};
                    end
                    
                    assert(iscell(r_i.(fields{oo}).y),'Something wrong here!');
                    assert(length(r_i.(fields{oo}).y) == n_choices,'Something wrong here!');
                    
                    r_i.(fields{oo}).y  = r_i.(fields{oo}).y{idx};
                end
                
                r_i.(fields{oo}) = rmfield(r_i.(fields{oo}),'f');
            end
        end
    end
end