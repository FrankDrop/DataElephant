function [] = submit(obj,name,z,varargin)

    oldflock = obj.flock;
    obj.flock = 1;

    p = inputParser;
    p.CaseSensitive     = true;
    addParameter(p,'split','');
    addParameter(p,'to','');
    addParameter(p,'pre','zzz');
    parse(p,varargin{:});
    tz          = p.Results;   
    splitBy     = regexp(tz.split,',','split');
    toHosts     = sort(regexp(tz.to,',','split'));
    if iscell(toHosts)
        tz.to       = sprintf('%s,',toHosts{:});
        tz.to       = tz.to(1:(end-1));
    end
    
    kk = 1;
    while kk < length(splitBy)+1
        if isempty(splitBy{kk})
            splitBy(kk) = [];
        else
            kk= kk+1;
        end
    end

    updateTree(obj,name);
    
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
    if iscell(name)
        error('why the f did I program this?')
    else
        for ll=length(obj.steps):-1:1
            if any(strcmp(name,obj.steps(ll).output))
                untilStepNumber  = obj.steps(ll).number;
                break;
            end
        end
    end
    
    % Find all the decisions that need to be taken before the final step:
    allDecisions = {};
    for ll=1:untilStepNumber
        if ~obj.steps(ll).type
            allDecisions{end+1} = obj.steps(ll).decide; %#ok<AGROW>
        end
    end
    
    if isempty(untilStepNumber)
        error('The requested result %s is not an output of any step in this process.',name);
    end
    
    
    for oo=1:length(splitBy)
        if ~isfield(z,splitBy{oo})
            error('I cannot split this up over the field %s, because it does not exist.',splitBy{oo})
        end
        if ~iscell(z.(splitBy{oo})) || ~iscolumn(z.(splitBy{oo}))
            error('I cannot split this up over the field %s, because it does not (correctly) define a functional.',splitBy{oo})
        end
        if any(strcmp(splitBy{oo},allDecisions))
            error('You want to split up over field %s, but I also have to make a decision over this field. I don''t think this is a smart move...',splitBy{oo})
        end
    end
    
    if ~isempty(splitBy)
        for oo=1:length(z.(splitBy{1}))
            z_this              = z;
            z_this.(splitBy{1}) = z.(splitBy{1}){oo};
            tz_this             = tz;
            if length(splitBy) > 1
                tz_this.split       = sprintf('%s,',splitBy{2:end});
                tz_this.split       = tz_this.split(1:(end-1));
            else
                tz_this.split       = '';
            end
            submit(obj,name,z_this,tz_this)
        end
    else
        % This is where the magic happens.
        iter.process    = obj.fHandle;
        iter.name       = name;
        iter.z          = z;  %#ok<STRNU>
        
        if ~isempty(tz.to)
            toString    = strrep(tz.to,',','_');
        else
            toString    = 'all';
        end
        
        if isempty(obj.getDistFolder())
            error('You should define the distfolder!');
        end
        fdr     = [obj.getDistFolder() '/' toString];
        
        getLock(obj,fdr,true);
        
        if ~exist(fdr,'dir')
            res = input(sprintf('You want to submit to hosts ''%s'', but the folder ''%s'' does not exist yet. Do you want me to create this folder? (y/n)',tz.to,strrep(fdr,'\','\\')),'s');
            if strcmp(res,'y')
                mkdir(fdr);
            else
                error('Exit!');
            end
        end
        
        founduniquename = false;
        while ~founduniquename
            suffix = CalcMD5(rand,'char','HEX');
            fn = [fdr '/' tz.pre '_' suffix];
            if ~exist(fn,'file')
                getLock(obj,fn,true);
                save(fn,'-struct','iter','-v6');
                releaseLock(obj,fn,true);
                founduniquename = true;
            end
        end
        
        releaseLock(obj,fdr,true);
    end
    
    obj.flock = oldflock;
end