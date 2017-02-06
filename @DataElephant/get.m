function [r,id_cum] = get(obj,name,varargin)

    z_thisCall          = obj.args(varargin{:});
    thisCallInputNames  = fieldnames(z_thisCall);
    
    if ~isempty(obj.z_default)
        z                   = obj.args(obj.z_default,z_thisCall);
    else
        z                   = obj.args(z_thisCall);
    end
    
    ccc = onCleanup(@()cleanexit(obj,'get'));
    
    xy    = regexp(name,',','split');
    if obj.process.xy
        if length(xy) > 1
            error('You cannot specify multiple results for this process, because it will automatically output x and y data.')
        end
        
        name    = xy{1};
        xname   = name;
        yname   = name;
        
        updateTree(obj,name);
    else
        if length(xy) == 1
            name    = xy{1};
            updateTree(obj,name);
            xname   = name;
            yname   = name;
        elseif length(xy) == 2
            [b1,s1] = updateTree(obj,xy{1});
            [b2,s2] = updateTree(obj,xy{2});
            
            if any([b1,s1,b2,s2] == -1)
                error('Something went wrong');
            end
            
            if (all([b1 b2] > 0) && b1 ~= b2)
               error('I can only combine x and y data from the same branch.')
            end
            
            if s1 > s2
                name    = xy{1};
            else
                name    = xy{2};
            end
            
            xname   = xy{1};
            yname   = xy{2};
        end
    end
    
    
    
    t_inputs = fieldnames(z);
    for oo=1:length(t_inputs)
        if ~any(strcmp(t_inputs{oo},obj.allInputs))
            error('This process is not sensitive to parameter %s.',t_inputs{oo});
        end
    end

    if ~any(strcmp(name,obj.allOutputs))
        error('This process does not produce requested output %s.',name);
    end

    untilStepNumber = [];
    if ~ischar(name)
        error('The first argument should be a string.')
    end

    % Determine what step produces the requested result
    for ll=length(obj.steps):-1:1
        if any(strcmp(name,obj.steps(ll).output))
            untilStepNumber  = obj.steps(ll).number;
            break;
        end
    end

    assert(~isempty(untilStepNumber),'The requested result %s is not an output of any step in this process.',name);
    pverbose(obj,'The requested result %s is an output of step %i (%s).\n',name,untilStepNumber,obj.steps(untilStepNumber).name);

    
    % Check whether all the arguments are either numeric, cells or chars    
    zflds   = fieldnames(z);
    for oo=1:length(zflds)
        if islogical(z.(zflds{oo}))
            z.(zflds{oo}) = double(z.(zflds{oo}));
        end
    end
    
    
    % Pre-construct the z objects that are necessary later, to
    % prevent that you constantly have to build them again and
    % again.
    z_cum   = cell(untilStepNumber,1);
    z_step  = cell(untilStepNumber,1);

    for ii=1:untilStepNumber
        if ii > 1
            z_cum{ii}   = z_cum{ii-1};
        end
        
        if obj.deepverbose
            fprintf('Processing %i required and %i optional inputs from step %i (%s).\n',length(obj.steps(ii).input),length(obj.steps(ii).optional),ii,obj.steps(ii).name);
        end

        for aa=1:length(obj.steps(ii).input)
            
            try
                z_cum{ii}.(obj.steps(ii).input{aa})     = z.(obj.steps(ii).input{aa});
                z_step{ii}.(obj.steps(ii).input{aa})    = z.(obj.steps(ii).input{aa});
            catch %#ok<CTCH>
                error('The step %s requires parameter %s, but it is not set.',obj.steps(ii).name,obj.steps(ii).input{aa});
            end
            
            if iscell(z.(obj.steps(ii).input{aa}))
                if ~any(strcmp(obj.steps(ii).input{aa},obj.defaultInputs)) || any(strcmp(obj.steps(ii).input{aa},thisCallInputNames))
                    makeFunctionalCache(obj,obj.steps(ii).input{aa},z.(obj.steps(ii).input{aa}));
                end
            end
        end

        for aa=1:length(obj.steps(ii).optional)
            try
                z_cum{ii}.(obj.steps(ii).optional{aa})      = z.(obj.steps(ii).optional{aa});
                z_step{ii}.(obj.steps(ii).optional{aa})     = z.(obj.steps(ii).optional{aa});
            catch  %#ok<CTCH>
                z_cum{ii}.(obj.steps(ii).optional{aa})      = [];
                z_step{ii}.(obj.steps(ii).optional{aa})     = [];
            end
            
            if ~iscell(z_cum{ii}.(obj.steps(ii).optional{aa}))
                
                if isnan(z_cum{ii}.(obj.steps(ii).optional{aa}))
                    if obj.verbose
                        fprintf('\tRemoving argument %s, because it was set to NaN.\n',obj.steps(ii).optional{aa});
                    end
                    z_cum{ii}   = rmfield(z_cum{ii},obj.steps(ii).optional{aa});
                    z_step{ii}  = rmfield(z_step{ii},obj.steps(ii).optional{aa});
                end
                
            else
                
                if ~iscolumn(z.(obj.steps(ii).optional{aa}))
                    error('You should provide each functional as a cell column vector (%s).',obj.steps(ii).optional{aa});
                end

                if obj.verbose
                    fprintf('\tI will make a fnc hash cache for %s with %i entries.\n',obj.steps(ii).optional{aa},length(z.(obj.steps(ii).optional{aa})));
                end

                fnchashtmp = -1*ones(length(z.(obj.steps(ii).optional{aa})),16);
                fnccell     = z.(obj.steps(ii).optional{aa});
                for uu=1:length(fnccell)
                    fnchashtmp(uu,:) = CalcMD5(fnccell{uu},'char','Dec');
                end
                obj.fnchashcache.(obj.steps(ii).optional{aa})       = fnchashtmp;
                
                if isnumeric(z.(obj.steps(ii).optional{aa}){1})
                    obj.fastfnchashcache.(obj.steps(ii).optional{aa})   = cell2mat(z.(obj.steps(ii).optional{aa}));
                elseif ischar(z.(obj.steps(ii).optional{aa}){1})
                    charhash     = zeros(length(z.(obj.steps(ii).optional{aa})),16);
                    for uu=1:length(z.(obj.steps(ii).optional{aa}))
                        charhash(uu,:)   = CalcMD5(z.(obj.steps(ii).optional{aa}){uu},'char','Dec');
                    end
                    obj.fastfnchashcache.(obj.steps(ii).optional{aa})   = charhash;
                else
                    error('boo!')
                end
            end
        end
    end
    
    [r,id_cum,f,~,~] = getAll(obj,name,z_cum,z_step,1,untilStepNumber,untilStepNumber,struct(),[],xname,yname);
    
    if nargout == 0 || nargout == 1
        [x,y,fn,fv] = obj.getY(r,name,f,{},{},1,xname,yname);
        r           = PData3('x',x,'y',y,'fNames',fn,'fValues',fv,'myName',name);
    end

end