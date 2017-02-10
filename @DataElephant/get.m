function [r,id_cum] = get(obj,name,varargin)

    t_getStart          = tic;
    obj.getTime         = 0;

    z_thisCall          = obj.args(varargin{:});
    thisCallInputNames  = fieldnames(z_thisCall);
    
    if ~isempty(obj.z_default)
        z                   = obj.args(obj.z_default,z_thisCall);
    else
        z                   = obj.args(z_thisCall);
    end
    
    ccc = onCleanup(@()cleanexit(obj,'get'));
    
    names_raw       = regexp(name,';','split');
    if length(names_raw) == 1
        names_raw{2} = names_raw{1};
    end
    
    names_stripped  = cell(size(names_raw));
    
    for oo=1:length(names_raw)
        strip_special           = regexp(names_raw{oo},'(?<=squeeze\().*(?=\))[.'']*','match');
        if isempty(strip_special)
            strip_special       = names_raw{oo};
        else
            strip_special       = strip_special{1};
        end
        names_stripped{oo}      = regexprep(strip_special,'\([,a-zA-Z0-9:()'']*\)[.'']*','');
    end
    

    if strcmp(names_stripped{1},names_stripped{2})
        [atBranch(2),atStep(2)] = updateTree(obj,names_stripped{2});
        
        if ~isempty(obj.x_output.(names_stripped{2}))
            names_stripped{1}       = obj.x_output.(names_stripped{2});
            names_raw{1}            = obj.x_output.(names_stripped{2});
            
            [atBranch(1),atStep(1)] = updateTree(obj,names_stripped{1});
            [atBranch(2),atStep(2)] = updateTree(obj,names_stripped{2});
        else
            atBranch(1)     = atBranch(2);
            atStep(1)       = atStep(2);
        end
    else
        atBranch    = -1*ones(size(names_stripped));
        atStep      = -1*ones(size(names_stripped));

        for oo=1:length(names_stripped)
            [atBranch(oo),atStep(oo)] = updateTree(obj,names_stripped{oo});
        end
    end

    if any([atBranch,atStep] == -1)
        error('Something went wrong');
    end

    if (any(diff(atBranch) ~= 0))
        error('I can only combine data from the same branch.')
    end

    minStep     = min(atStep);
    maxStep     = max(atStep);
    
    t_inputs = fieldnames(z);
    for oo=1:length(t_inputs)
        if ~any(strcmp(t_inputs{oo},obj.allInputs))
            error('This process is not sensitive to parameter %s.',t_inputs{oo});
        end
    end

    for oo=1:length(names_stripped)
        if ~any(strcmp(names_stripped{oo},obj.allOutputs))
            error('This process does not produce requested output %s.',names_stripped{oo});
        end
    end

    untilStepNumber = maxStep;
    pverbose(obj,'The requested result %s is an output of step %i (%s).\n',name,untilStepNumber,obj.steps(untilStepNumber).name);

    
    % Check whether all the arguments are either numeric, cells or chars    
    zflds   = fieldnames(z);
    for oo=1:length(zflds)
        if islogical(z.(zflds{oo})) % TODO: Raar, kan dit niet anders?
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
                error('The step %s requires parameter %s, but it is not set.',obj.createLink(obj.steps(ii).name),obj.steps(ii).input{aa});
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
    
    [r,f,id_cum,~,~] = getAll(obj,names_stripped,z_cum,z_step,1,untilStepNumber,untilStepNumber,struct(),struct(),[],minStep);
    
    if nargout == 0 || nargout == 1
        
        [x,y,fn,fv] = obj.getY(r,names_stripped,names_raw,f,{},{},1);
        r           = PData3('x',x,'y',y,'fNames',fn,'fValues',fv,'myName',name);
    end

    t_totalGetTime  = toc(t_getStart);
    if obj.verbose
        fprintf('Done. This get() call took %1.3f s, of which %1.3f s was inside steps calculating results. Overhead = %1.1f%%.',t_totalGetTime,obj.getTime,100*(1-obj.getTime/t_totalGetTime));
    end
end