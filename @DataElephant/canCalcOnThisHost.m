function [goodToGo] = canCalcOnThisHost(obj,step,z,submittedBefore)

    onRightPlatform = strcmp(obj.steps(step).hosttypes,'all') || (isunix && strcmp(obj.steps(step).hosttypes,'unix')) || ...
                (ispc && strcmp(obj.steps(step).hosttypes,'windows'));
    onRightHost = true;
            
    if onRightPlatform
        % We are on the right platform, but are we on the correct host?
        if ~isempty(obj.steps(step).hosts)
            onRightHost = any(strcmp(obj.myhostname,obj.steps(step).hosts));
        else
            onRightHost = true;
        end
    end
    
    if ~(onRightPlatform && onRightHost)
        if obj.submitToHost && obj.load_hdd
            toHosts     = sprintf('%s,',obj.steps(step).hosts{:});
            toHosts     = toHosts(1:(end-1));
            if ~submittedBefore
%                 submit(obj,name,z,'to',toHosts,'pre','0'); % 0 as prefix to get highest priority on host.
                submit(obj,obj.steps(step).outputs{1},z,'to',toHosts,'pre','0'); % 0 as prefix to get highest priority on host.
            end
            goodToGo = 2;  % Means submitted, we have to wait.
        else
            goodToGo = 0;  % We don't want to submit, so we cannot continue
        end
    else
        goodToGo = 1; % We can calculate it on this host
    end
end