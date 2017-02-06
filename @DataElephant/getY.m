function [x,y,fn,fv] = getY(obj,r,name,f,fn,fv,ll,xname,yname)

if obj.process.xy
    if isempty(f) % f contains the functional. if it is empty, we only have one result.
        y = r.(name).y;
        
        if iscell(r.(name).y)
            x = cell(1,1);
        else
            if isfield(r.(name),'x')
                x   = r.(name).x;
            else
                x   = zeros(size(y));
            end
        end
    else
        fn{ll}  = f.this.name;
        fv{ll}  = f.this.value;

        if isempty(f.sub)
            % If f.sub is empty, there were no functionals in lower layers.
            
            if iscell(r{1})
                % Why would this be the case?
                
                y = cell([length(f.this.value) size(r{1}.(name).y)]);

                if isfield(r{1}.(name),'x')
                    x   = r{1}.(name).x;
                else
                    x   = zeros(size(r{1}.(name).y));
                end

                for oo=1:length(f.this.value)
                    y{oo,:}     = r{oo}.(name).y{:};
                end
            else
                if iscell(r{1}.(name).y)
                    y = cell([length(f.this.value) size(r{1}.(name).y)]);
                else
                    y = zeros([length(f.this.value) size(r{1}.(name).y)]);
                end

                if isfield(r{1}.(name),'x')
                    x   = r{1}.(name).x;
                else
                    x   = zeros(size(r{1}.(name).y));
                end

                for oo=1:length(f.this.value)
                    y(oo,:)     = r{oo}.(name).y(:);
                end
            end
        else
            % If f.sub was not empty, there are results hidden in lower
            % layers. We retrieve them by recursively calling the getY()
            % function again.
            f_i = f.sub;
            y_i = cell(length(f.this.value),1);
            for oo=1:length(f.this.value)
                [x,y_oo,fn_i,fv_i]  = getY(obj,r{oo},name,f_i,fn,fv,ll+1);
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
else
    if isempty(f) % f contains the functional. if it is empty, we only have one result.
        y   = r.(yname);
        x   = r.(xname);
        
%         if iscell(r.(xname))
%             x = cell(1,1);
%         else
%             if isfield(r.(xname),'x')
%                 
%             else
%                 x   = zeros(size(y));
%             end
%         end
    else
        fn{ll}  = f.this.name;
        fv{ll}  = f.this.value;

        if isempty(f.sub)
            % If f.sub is empty, there were no functionals in lower layers.
            
            if iscell(r{1})
                % Why would this be the case?
                
                y = cell([length(f.this.value) size(r{1}.(name).y)]);

                if isfield(r{1}.(name),'x')
                    x   = r{1}.(name).x;
                else
                    x   = zeros(size(r{1}.(name).y));
                end

                for oo=1:length(f.this.value)
                    y{oo,:}     = r{oo}.(name).y{:};
                end
            else
                if iscell(r{1}.(name).y)
                    y = cell([length(f.this.value) size(r{1}.(name).y)]);
                else
                    y = zeros([length(f.this.value) size(r{1}.(name).y)]);
                end

                if isfield(r{1}.(name),'x')
                    x   = r{1}.(name).x;
                else
                    x   = zeros(size(r{1}.(name).y));
                end

                for oo=1:length(f.this.value)
                    y(oo,:)     = r{oo}.(name).y(:);
                end
            end
        else
            % If f.sub was not empty, there are results hidden in lower
            % layers. We retrieve them by recursively calling the getY()
            % function again.
            f_i = f.sub;
            y_i = cell(length(f.this.value),1);
            for oo=1:length(f.this.value)
                [x,y_oo,fn_i,fv_i]  = getY(obj,r{oo},name,f_i,fn,fv,ll+1);
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
end
end