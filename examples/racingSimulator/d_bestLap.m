function step = d_bestLap()

    step.name       = mfilename;
    step.type       = 'decision';
    step.decide     = 'raf_path';
    step.basedon    = {'laptime'};
    step.input      = {};
    step.optional   = {};
	step.output     = {};
    step.handle     = @myfunc;
    step.version    = 1;
    step.saveme     = 1;
    step.memorizeme = 1;

    function idx = myfunc(~,r,~,~)
        
        [~,idx]     = min([r.laptime{:}]);
        
    end
end