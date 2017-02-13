function step = d_bestLap()

    step.name       = mfilename;
    step.type       = 'decision';
    step.decide     = 'raf_path';
    step.basedon    = {'f_x_max','f_y_max','f_z_max','laptime'};
    step.input      = {'howBest'};
    step.optional   = {};
	step.output     = {};
    step.handle     = @myfunc;
    step.version    = 1;
    step.saveme     = 1;
    step.memorizeme = 1;

    function idx = myfunc(z,r,~,~)

        switch z.howBest
            case 'laptime'
                [~,idx]     = min([r.laptime{:}]);
            case 'f_x'
                [~,idx]     = min([r.f_x_max{:}]);
            case 'f_y'
                [~,idx]     = min([r.f_y_max{:}]);
            case 'f_z'
                [~,idx]     = min([r.f_z_max{:}]);
            otherwise
                error('This step cannot decide based on %s.',z.howBest)
        end
    end
end