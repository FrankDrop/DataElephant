function [atStep, names_stripped, names_raw ] = prepareBranchAndNames(obj, name )
    
    names_raw       = regexp(name,';','split');
    
    bareRequest     = length(names_raw) == 1;
    if bareRequest
        names_raw{2}    = names_raw{1};
    end
    
    names_stripped  = cell(size(names_raw));
    
    for oo=1:length(names_raw)
        
        if strcmp(names_raw{oo}(1),'$')
            names_stripped{oo} = '$';
            names_raw{oo} = names_raw{oo}(2:end);
        else

            % Aparently here we remove the @ sign? But why would we?
    %         strip_special1      = regexprep(names_raw{oo},'@','');

            % Then we check whether the raw name is still equal to the name
            % stripped from the @ sign
    %         names_unequal       = names_unequal | ~strcmp(names_raw{oo},strip_special1);

            % Then we replace the raw name with the stripped version
    %         names_raw{oo}       = strip_special1;

            % Then we check whether it is encapsulated by the squeeze command
            strip_special       = regexp(names_raw{oo},'(?<=squeeze\().*(?=\))[.'']*','match');        

            % If it is encapsulated by squeeze, we take the internals
            if isempty(strip_special)
                strip_special       = names_raw{oo};
            else
                strip_special       = strip_special{1};
            end

            % Then we strip the raw names from all junk
            names_stripped{oo}      = regexprep(strip_special,'\([,a-zA-Z0-9:()'']*\)[.'']*','');
        end
    end

    if strcmp(names_stripped{1},'$')
        names_stripped{1} = names_stripped{2};
    end
    
    if strcmp(names_stripped{2},'$')
        names_stripped{2} = names_stripped{1};
    end
    
    
%     if strcmp(names_stripped{1},names_stripped{2})
    if bareRequest
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
            if ~strcmp(names_stripped{oo},'$')
                [atBranch(oo),atStep(oo)] = updateTree(obj,names_stripped{oo});
            else
                atBranch(oo) = -2;
                atStep(oo)   = -2;
            end
        end
    end
    
    if atStep(1) == -2
        atStep(1) = atStep(2);
        atBranch(1) = atBranch(2);
    end
    
    if atStep(2) == -2
        atStep(2) = atStep(1);
        atBranch(2) = atBranch(1);
    end
    
    
    
    if any([atBranch,atStep] == -1)
        error('Something went wrong');
    end
    
    
    
    
    if (any(diff(atBranch) ~= 0))
        % We might be able to recover... if one of the results is from the
        % main branch:
        if any(atBranch == 0)
            % Update the tree to 
            updateTree(obj,names_stripped{atBranch ~= 0});
            foundIt = false;
            for oo=1:length(obj.steps)
                if any(strcmp(obj.steps(oo).output,names_stripped{atBranch == 0}))
                    foundIt = true;
                end
            end
            
            if ~foundIt
                error('I can only combine data from the same branch.');
            end
        else
            error('I can only combine data from the same branch.');
        end
    end
end

