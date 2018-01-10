function [ z_cum, z_step, func ] = prepareInputs(obj,name,z,thisCallInputNames,maxStep)
    
    func = false;

    % Check whether the provided inputs are indeed required by this process
    t_inputs = fieldnames(z);
    for oo=1:length(t_inputs)
        if ~any(strcmp(t_inputs{oo},obj.allInputs))
            z = rmfield(z,t_inputs{oo});
            if obj.verbose
                warning('This process is not sensitive to parameter %s.',t_inputs{oo});
            end
        end
    end
    
    % Determine until which step we have to proceed
    pverbose(obj,'The requested result %s is an output of step %i (%s).\n',name,maxStep,obj.steps(maxStep).name);

    % Check whether all the arguments are either numeric, cells or chars    
    zflds   = fieldnames(z);
    for oo=1:length(zflds)
        if islogical(z.(zflds{oo})) % TODO: Raar, kan dit niet anders?
            z.(zflds{oo}) = double(z.(zflds{oo}));
        end
    end
    
    % Check if there are any decisions to be taken between just one option    
    for ii=1:maxStep
        if ~obj.steps(ii).type
            if ~iscell(z.(obj.steps(ii).decide))
                z.(obj.steps(ii).decide) = {z.(obj.steps(ii).decide)};
            end
        end
    end

    % Pre-construct the z objects that are necessary later, to
    % prevent that you constantly have to build them again and
    % again.
    z_cum   = cell(maxStep,1);
    z_step  = cell(maxStep,1);

    for ii=1:maxStep
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
                error('The step %s requires parameter %s, but it is not set.',obj.createLink(obj.steps(ii).name),obj.steps(ii).input{aa});
            end
            
            if iscell(z.(obj.steps(ii).input{aa}))
                func    = true;
                
                if ~any(strcmp(obj.steps(ii).input{aa}, obj.defaultInputs)) || any(strcmp(obj.steps(ii).input{aa},thisCallInputNames))
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
                
                func    = true;
                
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
end

