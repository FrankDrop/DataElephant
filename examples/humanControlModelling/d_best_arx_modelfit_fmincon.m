function step = d_best_arx_modelfit_fmincon()

    step.name       = mfilename;
    step.type       = 'decision';
    step.decide     = 'ga_nr';
    step.basedon    = {'fmincon_V'};
    step.input      = {};
    step.optional   = {};
	step.output     = {};
    step.handle     = @myfunc;
    step.version    = 1;
    step.saveme     = 1;
    step.memorizeme = 1;

    function idx = myfunc(~,r,verbose,~)
        if verbose
            close all
        end
        fmincon_V   = [r.fmincon_V.y{:}];
        [~,idx]     = min(fmincon_V);
        if verbose
            fprintf('I am making a decision from %i different GA and fmincon runs with %i unique cost values. Run %i was the best. I chose from:\n%s\n',...
                length(fmincon_V),length(unique(fmincon_V)),idx,sprintf('- %1.10f\n',fmincon_V));
        end
    end
end