function [r,id_cum] = get(obj,name,varargin)

    t_getStart          = tic;
    obj.getTime         = 0;

    [z_thisCall,z_nuf]  = obj.args(varargin{:});
    
    if ~isempty(z_nuf)
        assert(iscell(z_nuf) && mod(length(z_nuf),2) == 0 && all(cellfun(@(x)iscell(x) && iscolumn(x),z_nuf(2:2:end))));
    end
    
    thisCallInputNames  = [fieldnames(z_thisCall); z_nuf(1:2:end).'];
        
    if ~isempty(obj.z_default)
        z = obj.args(obj.z_default,z_thisCall);
    else
        z = obj.args(z_thisCall);
    end
    
    ccc = onCleanup(@()cleanexit(obj,'get'));
    
    [atStep, names_stripped, names_raw] = prepareBranchAndNames(obj,name);
    
    minStep     = min(atStep);
    maxStep     = max(atStep);    
    
    % Check whether the requested outputs are indeed produced by this process
    for oo=1:length(names_stripped)
        if ~any(strcmp(names_stripped{oo},obj.allOutputs))
            error('This process does not produce requested output %s.',names_stripped{oo});
        end
    end
    
    % The get function can work in 2 modes.
    
    if isempty(z_nuf)
        % The first mode is the original, optimized mode that assumes
        % either no or single functionals, or multiple functionals that are
        % uniformly 'gridded'. That is, if there are multiple functionals,
        % then the full factorial combination of those functionals are
        % calculated.
        
        [z_cum,z_step]  = prepareInputs(obj, name, z, thisCallInputNames, maxStep);

        % After all the preparation, we are ready to actually get some results:
    
        if nargout <= 1
            try
                [r,~,id_cum,f,~,~]  = getAll(obj,names_stripped,z_cum,z_step,1,maxStep,maxStep,struct(),struct(),[],minStep,false);
            catch e
                if contains(e.stack(1).file,'@DataElephant')
                    rethrow(e);
                else
                    error('Error using <a href="matlab:open %s">%s</a> (<a href="matlab:opentoline(''%s'',%i)">line %i</a>):\n%s',...
                            e.stack(1).file,...
                            e.stack(1).name,...
                            e.stack(1).file,...
                            e.stack(1).line,...
                            e.stack(1).line,...
                            e.message);
                end
            end
            
            [x,y,fn,fv]         = obj.getY(r,names_stripped,names_raw,f,{},{},1);
            r                   = PData3('x',x,'y',y,'fNames',fn,'fValues',fv,'myName',name,'raw',obj.raw);
        end
        
    else    
        % The second mode is a 'newer' mode, that is not particularly
        % optimized for speed, that allows for 'custom' functional 
        % combinations. That is, the user provides vectors of input
        % parameter values.
        
        if nargout > 1
            error('This is not supported');
        end
        
        req_length  = length(z_nuf{2});
        
        for ii=1:2:length(z_nuf)
            assert(isequal(size(z_nuf{ii+1}),[req_length 1]));
        end
        
        for ss=req_length:-1:1
            z_i     = z;
            
            pverbose(obj,'(%i / %i) Going to retrieve data for ',ss,req_length);
            for ii=1:2:(length(z_nuf)-2)
                z_i = obj.args(z_i,z_nuf{ii},z_nuf{ii+1}{ss});
                pverbose(obj,'%s : %s, ',z_nuf{ii},num2str(z_nuf{ii+1}{ss}));
            end
            
            z_i = obj.args(z_i,z_nuf{end-1},z_nuf{end}{ss});
            pverbose(obj,'%s : %s.\n',z_nuf{end-1},num2str(z_nuf{end}{ss}));
            
%             pverbose(obj,'.\n');
            
            [z_cum,z_step,func] = prepareInputs(obj, name, z_i, thisCallInputNames, maxStep);
            
            if func
                error('This is not possible');
            end
            
            [r,~,id_cum,f,~,~]  = getAll(obj,names_stripped,z_cum,z_step,1,maxStep,maxStep,struct(),struct(),[],minStep,false);
            [x,y,~,~]           = obj.getY(r,names_stripped,names_raw,f,{},{},1);
            
            y_all(ss,:)     = y;
        end
        
        fn  = z_nuf(1:2:end);
        fv  = z_nuf(2:2:end);
        
        r = PData3('x',x,'y',y_all,'fNames',fn,'fValues',fv,'myName',name,'fullFactorial',false,'raw',obj.raw);
    end

    t_totalGetTime  = toc(t_getStart);
    if obj.verbose
        fprintf('Done. This get() call took %1.3f s, of which %1.3f s was inside steps calculating results. Overhead = %1.1f%%.',t_totalGetTime,obj.getTime,100*(1-obj.getTime/t_totalGetTime));
    end
end