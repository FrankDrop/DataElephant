function [x,y,fn,fv] = getY(obj,r,names_stripped,names_raw,f,fn,fv,ll)

    if isempty(f) % f contains the functional. if it is empty, we only have one result.
        
        x   = r.(names_stripped{1});
        y   = r.(names_stripped{2});

        if ~(strcmp(names_raw{1},names_stripped{1}) && strcmp(names_raw{2},names_stripped{2}))
            try
                x   = eval(strrep(names_raw{1},names_stripped{1},'x'));
            catch
                error('Size of x = [%s]',sprintf('%i, ',size(x)));
            end
            
            try
                y   = eval(strrep(names_raw{2},names_stripped{2},'y'));
            catch
                error('Size of y = [%s]',sprintf('%i, ',size(y)));
            end
        end
    else
        fn{ll}  = f.this.name;
        fv{ll}  = f.this.value;

        if isempty(f.sub)
            % If f.sub is empty, there were no functionals in lower layers.
            
            if iscell(r{1})
                % Why would this be the case?
                
                y   = cell([length(f.this.value) size(r{1}.(names_stripped{2}))]);
                
                if strcmp(names_raw{1},names_raw{2})
                    x   = reshape(1:numel(r{1}.(names_stripped{1})),size(r{1}.(names_stripped{2})));
                else
                    x   = r{1}.(names_stripped{1});
                end

                if (strcmp(names_raw{1},names_stripped{1}) && strcmp(names_raw{2},names_stripped{2}))
                    for oo=1:length(f.this.value)
                        y{oo,:}     = r{oo}.(names_stripped){:};
                    end
                else
                    for oo=1:length(f.this.value)
                        y           = r{oo}.(names_stripped{2}); %#ok<NASGU>
                        y           = eval(strrep(names_raw{2},names_stripped{2},'y'));
                        y{oo,:}     = y{:};
                    end
                end
            else
                if iscell(r{1}.(names_stripped{2}))
                    exmpl   = r{1}.(names_stripped{2}); %#ok<NASGU>
                    sz      = eval(strrep(names_raw{2},names_stripped{2},'exmpl'));
                    
                    y = cell([length(f.this.value) size(sz)]);
%                     y = cell([length(f.this.value) size(r{1}.(names_stripped{2}))]);
                else
                    exmpl   = r{1}.(names_stripped{2}); %#ok<NASGU>
                    sz      = eval(strrep(names_raw{2},names_stripped{2},'exmpl'));
                    
                    y = zeros([length(f.this.value) size(sz)]);
%                     y = zeros([length(f.this.value) size(r{1}.(names_stripped{2}))]);
                end

                if strcmp(names_raw{1},names_raw{2})
                    x   = reshape(1:numel(r{1}.(names_stripped{1})), size(r{1}.(names_stripped{1})));
                else
                    x   = r{1}.(names_stripped{1});
                end
                
                try
                    if (strcmp(names_raw{1},names_stripped{1}) && strcmp(names_raw{2},names_stripped{2}))
                        for oo=1:length(f.this.value)
                            y(oo,:)     = r{oo}.(names_stripped{2})(:);
                        end
                    else
                        for oo=1:length(f.this.value)
                            y_          = r{oo}.(names_stripped{2}); %#ok<NASGU>
                            y_          = eval(strrep(names_raw{2},names_stripped{2},'y_'));
                            y(oo,:)     = y_(:);
                        end
%                         y = eval(strrep(names_raw{2},names_stripped{2},'y'));
                    end
                catch e
                    if strcmp(e.identifier,'MATLAB:subsassigndimmismatch')
                        error('The result %s is not always the same size over the functional %s.',names_stripped{2},f.this.name,names_stripped{2});
                    else
                        rethrow(e);
                    end
                end
            end
        else
            % If f.sub was not empty, there are results hidden in lower
            % layers. We retrieve them by recursively calling the getY()
            % function again.
            f_i = f.sub;
            y_i = cell(length(f.this.value),1);
            for oo=1:length(f.this.value)
                [x,y_oo,fn_i,fv_i]  = getY(obj,r{oo},names_stripped,names_raw,f_i,fn,fv,ll+1);
                y_i{oo}             = y_oo;
            end
            
            fn  = fn_i;
            fv  = fv_i;

            if iscell(y_i{1})
                y = cell([length(f.this.value) size(y_i{1})]);
                
                for oo=1:length(f.this.value)
                    y(oo,:)     = y_i{oo}(:);
                end
            else
                y = zeros([length(f.this.value) size(y_i{1})]);
                for oo=1:length(f.this.value)
                    y(oo,:)     = y_i{oo}(:);
                end
            end
        end
    end
% end
end