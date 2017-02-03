function r = addIndividual(r,r_i,uu)
    fields  = fieldnames(r_i);
    if isempty(uu)
        for oo=1:length(fields)
            r.(fields{oo}) = r_i.(fields{oo});
        end
    else
        for oo=1:length(fields)
            r.(fields{oo}){uu}  = r_i.(fields{oo});
        end
    end
end