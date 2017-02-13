function step = s_inputSignals()

    step.name       = mfilename;
    step.type       = 'step';
    step.decide     = {};
    step.baseon     = {};
    step.input      = {};
    step.optional   = {'ft','Kt',...
                       'fd','Kd','fdShift',...
                       'ftn','Ktn','tau_noise',...
                       'fdm','Kdm',...
                       'fdLat','KdLat'};
    step.output     = {'t_m;t_m','model_i','t_m;ft','t_m;fd','t_m;ftn','t_m;fdm','t_m;fdLat'};
    step.handle     = @myfunc;
    step.version    = 1;
    step.saveme     = 0;
    step.memorizeme = 1;
    
    function [r_n] = myfunc(z,r,~,~)
        % z     = input parameters for this function
        % r     = output up till now
        % z_n   = any modifications made to the input parameters in this
        % step
        % r_n   = any new results produced by this function
        model = r.model_p.copy;
        
        r_n.t_m       = model.measurementTime;
        
        specifyBoth(z,'Kt','ft');
        if ~isempty(z.Kt) && ~isempty(z.ft)    
            r_n.ft      = standardTargetSignal(z.ft,model,'Kt',z.Kt);
            model.setTaskFt(r_n.ft);
        end
        
        specifyBoth(z,'Kdm','fdm');        
        if ~isempty(z.Kdm) && ~isempty(z.fdm)
            r_n.fdm    = z.Kdm * standardMotionDisturbanceSignal(z.fdm,model);
            model.setTaskFdm(r_n.fdm);
        end
        
        specifyBoth(z,'Ktn','ftn');
        if ~isempty(z.Ktn) && ~isempty(z.ftn) && ~isempty(z.tau_noise)
            r_n.ftn     = standardTargetNoiseSignal(z.ftn,model,'Ktn',z.Ktn,'tau_noise',z.tau_noise);
            model.setTaskFtn(r_n.ftn);
        elseif ~isempty(z.Ktn) && ~isempty(z.ftn) && isempty(z.tau_noise)
            r_n.ftn     = standardTargetNoiseSignal(z.ftn,model,'Ktn',z.Ktn);
            model.setTaskFtn(r_n.ftn);
        end
        
        specifyBoth(z,'Kd','fd');
        if ~isempty(z.Kd) && ~isempty(z.fd)
            fd = z.Kd * standardDisturbanceSignal(z.fd,model);
            if ~isempty(z.fdShift)
                fd = circshift(fd,z.fdShift);
            end
            r_n.fd     = fd;
            model.setTaskFd(r_n.fd);
        end

        specifyBoth(z,'KdLat','fdLat');
        if ~isempty(z.KdLat) && ~isempty(z.fdLat)
            r_n.fdLat   = z.KdLat * standardDisturbanceSignal(z.fdLat,model);
            model.setTaskFdLat(r_n.fdLat);
        end
        
        r_n.model_i   = model.copy;
    end
end