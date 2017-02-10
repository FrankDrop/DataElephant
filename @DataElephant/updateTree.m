function [branchNumber,stepNumber] = updateTree(obj,varargin)

    obj.process     = feval(obj.fHandle);
    obj.allInputs   = {};
    ll              = 1;
    obj.allOutputs  = {};
    hh              = 1;
    
    branchNumber    = -1;
    stepNumber      = -1;
    
    if ~isfield(obj.process,'steps')
        % Either we are dealing with a FUBAR process definition file or
        % with a single step file.
        if isfield(obj.process,'type')
            if strcmp(obj.process.type,'step')
            % Looks like we are dealing with a step file. Lets fool the
            % code below into thinking this is a properly defined process
            % consisting of one single step.
                obj.process         = [];
                obj.process.name    = func2str(obj.fHandle);
                obj.process.steps   = {obj.fHandle};
            else
                error('Something is wrong with the process or single step function %s you provided.',obj.createLink(func2str(obj.fHandle)));
            end
        else
            error('Something is wrong with the process or single step function %s you provided.',obj.createLink(func2str(obj.fHandle)));
        end
    end
    
    foundBranch = false;
    
    if ~isempty(varargin)
        names   = varargin{1};
        
        % First look for the result in the main branch
        for oo=1:length(obj.process.steps)
            stp = obj.process.steps{oo}();
            if any(strcmp(names,obj.splitOutput(stp.output)))
                % obj.pverbose('To obtain result %s, we need to follow the main branch.\n',name)
                foundBranch     = true;
                newBranch       = obj.process.steps;
                branchNumber    = 0; %Branch number 0 is the main branch
                stepNumber      = oo;
                break;
            end
        end
        
        if isfield(obj.process,'branches')
            if ~isempty(obj.process.branches)
                % Then in the alternative branches
                for oo=1:length(obj.process.branches)
                    assert(length(obj.process.branches) > 1);
                    assert(any(strcmp(func2str(obj.process.branches{oo}{1}),cellfun(@(x)func2str(x),obj.process.steps,'UniformOutput',false))),...
                        sprintf('The branch starting with step %s is invalid, because this step is not part of the main branch.',obj.createLink(func2str(obj.process.branches{oo}{1}))));
                    
                    % Start at the second one, because the first step is
                    % both in the main thread as in the branches, hence it
                    % would throw an error.
                    for uu=2:length(obj.process.branches{oo})
                        stp = obj.process.branches{oo}{uu}();
                        if any(strcmp(names,obj.splitOutput(stp.output)))
                            if foundBranch
                                error('Branch #%i also provides the result %s.',uu,names)
                            end
                            % obj.pverbose('To obtain result %s, we need to follow alternative branch #%i.\n',name,oo)
                            
                            branchStartsAt  = find(strcmp(func2str(obj.process.branches{oo}{1}),cellfun(@(x)func2str(x),obj.process.steps,'UniformOutput',false)));
                            newBranch       = [obj.process.steps(1:branchStartsAt-1) obj.process.branches{oo}];
                            foundBranch     = true;
                            branchNumber    = oo;
                            stepNumber      = branchStartsAt+uu;
                        end
                    end
                end
            end
        end
        
        if ~foundBranch
            error('I did not find result %s on any branch...',names);
        else
            obj.process.steps   = newBranch;
        end
    end

    obj.steps               = [];
    for oo=1:length(obj.process.steps)
        
        step                        = obj.process.steps{oo}();
        obj.steps(oo).number        = oo;
        obj.steps(oo).name          = step.name;
        obj.steps(oo).type          = strcmp(step.type,'step');
        obj.steps(oo).saveme        = step.saveme == 1;
        obj.steps(oo).memorizeme    = step.memorizeme == 1;
        
        if ~isfield(step,'hosttypes')
            obj.steps(oo).hosttypes     = 'all';
        else
            assert(ischar(step.hosttypes),'Incorrect hosttypes definition in step %s.',obj.createLink(step.name));
            assert(any(strcmp(step.hosttypes,{'all','unix','windows'})),...
                'Incorrect hosttypes definition in step %s. Value given: %s, options: ''all'', ''unix'', ''windows''.',obj.createLink(step.name),step.hosttypes);
            obj.steps(oo).hosttypes     = step.hosttypes;
        end
        
        if ~isfield(step,'hosts')
            obj.steps(oo).hosts     = [];
        else
            assert(iscell(step.hosts),'Incorrect hosts definition in step %s, must be a cell.',obj.createLink(step.name));
            assert(all(cellfun(@(x)ischar(x),step.hosts)),'Incorrect hosts definition in step %s, each cell must be a string.',obj.createLink(step.name));
            obj.steps(oo).hosts = step.hosts;
        end

        if strcmpi(step.type,'decision')

            if oo == 1
                error('The first step in this process (%s) is a decision, but that is not possible.',obj.createLink(obj.process.name));
            end

            obj.steps(oo).decide    = step.decide;
            obj.steps(oo).basedon   = step.basedon;

            if ~any(strcmp(step.decide,obj.allInputs))
                error('Decision %s will decide on %s, but this input is not used by any of the previous steps.',obj.createLink(step.name),step.decide);
            end

            if ~iscell(step.basedon)
                error('You have to provide the list of outputs this decision will be based on as a cell vector.')
            end

            for uu=1:length(step.basedon)
                if ~any(strcmp(step.basedon{uu},obj.allOutputs))
                    error('Decision %s will base its decision on %s, but this output is not provided by any of the previous steps.',obj.createLink(step.name),step.basedon{uu});
                end
            end
        end

        obj.steps(oo).input     = sort(step.input);
        for ii=1:length(step.input)
            if isempty(step.input{ii})
                error('A step should have at least one input parameter (%s).',obj.createLink(step.name))
            end

            if ~any(strcmp(step.input{ii},obj.allInputs))
                obj.allInputs{ll} = step.input{ii};
                ll=ll+1;
            else
                error('Step %s declared input %s, but this input was already declared by a previous step.',obj.createLink(step.name),step.input{ii});
            end
        end

        obj.steps(oo).optional  = sort(step.optional);
        for ii=1:length(step.optional)
            if ~any(strcmp(step.optional{ii},obj.allInputs))
                obj.allInputs{ll} = step.optional{ii};
                ll=ll+1;
            else
                error('Step %s declared input %s, but this input was already declared by a previous step.',obj.createLink(step.name),step.optional{ii});
            end
        end

        actualOutput            = cell(length(step.output),1);
        obj.steps(oo).x_output  = cell(length(step.output),1);
        
        for ii=1:length(step.output)
            [x_out, actualOutput{ii}]           = obj.splitOutput(step.output{ii});
            obj.x_output.(actualOutput{ii})     = x_out;
        end
        
        step.output     = actualOutput;
        
        obj.steps(oo).output    = sort(step.output);
        for ii=1:length(step.output)
            if ~any(strcmp(step.output{ii},obj.allOutputs))
                obj.allOutputs{hh} = step.output{ii};
                hh=hh+1;
            else
                error('Step %s declared output %s, but this output was already declared by a previous step.',obj.createLink(step.name),step.output{ii});
            end
        end

        obj.steps(oo).handle    = step.handle;
        obj.steps(oo).version   = step.version;
    end
end