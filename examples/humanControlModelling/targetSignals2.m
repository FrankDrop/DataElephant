function [ft,t] = targetSignals2(which,model,varargin)

    p = inputParser;

    p.addParameter('sName',[]);
    p.addParameter('sTime',[]);
    p.addParameter('sGain',[]);

    p.addParameter('gain',1);
    p.addParameter('period',[]);
    p.addParameter('rate',[]);
    p.addParameter('T',[]);
    p.addParameter('spacing',1)
    p.addParameter('amount',1)
    p.addParameter('runin',5)
    p.addParameter('hold',0)
    p.addParameter('dt',[])
    p.parse(varargin{:});
    z = p.Results;

    if ~isempty(z.dt)
        dt  = z.dt;
    else
        dt  = model.measurementTime(2) - model.measurementTime(1);
%         dt  = 0.01;
    end

    if ~isempty(z.T)
        t   = 0:0.01:z.T;
    else
        t   = model.measurementTime;
    end

    if strcmpi(which,'drop2011b') || strcmpi(which,'drop2012a')

        T               = 10;
        T_stabilize     = 8;

        segment{1}  = linspace(0,1,0.5*T/dt)';
        segment{2}  = ones(T_stabilize/dt,1);
        segment{3}  = linspace(1,-1,T/dt)';
        segment{4}  = -ones(T_stabilize/dt,1);
        segment{5}  = linspace(-1,1,T/dt)';
        segment{6}  = ones(T_stabilize/dt,1);
        segment{7}  = linspace(1,0,0.5*T/dt)';
        segment{8}  = zeros(T_stabilize/dt,1);

        ft  = 0;
        for oo=1:length(segment)
            ft  = [ft; segment{oo}]; 
        end

        runin   = zeros(length(t)-length(ft),1);    
        ft      = [runin; ft];
        ft      = ft * z.gain * (5 * (pi/180));   
        ft      = circshift(ft,-8.09/dt);

    elseif strcmpi(which,'roundedRamp')

        T_ramp  = 10;
        T       = length(t);
        T_ramp  = T_ramp / dt;
        a       = round((T - 3*T_ramp)/5);

        u                                       = zeros(size(t));
        u(((a+1):(a+T_ramp/2)))                 = z.rate;
        u(((2*a+T_ramp/2+1):(2*a+3*T_ramp/2)))  = -z.rate;
        u(end/2+1:end)                          = -1*flipud(u(1:end/2));

        freq    = 3;    
        sys     = tf(freq,[1 freq 0]);
        ft1     = lsim(sys,u,t);
        ft2     = -1*flipud(lsim(sys,flipud(u),t));

        ft      = mean([ft1 ft2],2);
        ft      = z.gain * ft .*(pi/180);

    elseif strcmpi(which,'sine')    
        ft  = z.gain * (pi / 180) * sin((2 * pi / z.period) * t);

    elseif strcmpi(which,'triangle_s1')

        ft  = targetSignals2('triangle',model,varargin{:});
        ft  = cumsum(ft)*dt;

    elseif strcmpi(which,'triangle_s2')

        ft  = targetSignals2('triangle',model,varargin{:});
        ft  = cumsum(cumsum(ft))*dt*dt;

    elseif strcmpi(which,'parabola_s1')

        ft  = targetSignals2('parabola',model,varargin{:});
        ft  = cumsum(ft)*dt;

    elseif strcmpi(which,'parabola_s2')

        ft  = targetSignals2('parabola',model,varargin{:});
        ft  = cumsum(cumsum(ft))*dt*dt;

    elseif strcmpi(which,'cosinebell_s1')

        ft  = targetSignals2('cosinebell',model,varargin{:});
        ft  = cumsum(ft)*dt;

    elseif strcmpi(which,'cosinebell_s2')

        ft  = targetSignals2('cosinebell',model,varargin{:});
        ft  = cumsum(cumsum(ft))*dt*dt;

    elseif strcmpi(which,'triangle')

        % First make a triangle 'primitive' at the correct period
        % The period should be provided in multiples of 0.02, not 0.01, to
        % ensure the triangle to be symmetrical
        if any(mod(z.period,0.02) ~= 0) || any(mod(z.hold,0.02) ~= 0)
            error('The period and hold time of the triangle should be provided in multiples of 0.02 s.');
        end

        if length(z.segmentgain) ~= length(z.period)
            error('Segmentgain and period arrays are not equal in length')
        end

        msamples    = round(z.period ./ dt);
        hsamples    = round(z.hold ./ dt);
        tsamples    = round((z.period + z.hold) ./ dt);

        for ii=1:length(z.period)
            base{ii}                                        = zeros(tsamples(ii),1);
            base{ii}(1:msamples(ii)/2)                      =  2/msamples(ii);
            base{ii}((hsamples + msamples(ii)/2+1):end)     = -2/msamples(ii);
            base{ii}                                        = [0; cumsum(base{ii},1)];
        end

        runin       = zeros(round((z.runin+dt) / dt),1);

        ft_parts{1} = runin;

        for ii=1:z.amount
            if length(z.segmentgain) > 1
                idx             = mod(ii-1,length(z.segmentgain))+1;
                ft_parts{end+1} = z.segmentgain(idx) * base{idx}; %#ok<*AGROW>
            else
                ft_parts{end+1} = z.segmentgain * base; %#ok<*AGROW>
            end

            if ii < z.amount
                if length(z.spacing) > 1
                    ft_parts{end+1} = zeros(round((z.spacing(mod(ii-1,length(z.spacing))+1)+dt) / dt),1);
                else
                    ft_parts{end+1} = zeros(round((z.spacing+dt) / dt),1);
                end
            end
        end
        ft_parts{end+1}     = runin;

        ft  = [];
        for ii=1:length(ft_parts)
            ft  = [ft; ft_parts{ii}];
        end

        ft  = z.gain * (pi/180) * ft;

    elseif strcmpi(which,'parabola')

        % First make a parabola 'primitive' at the correct period
        % The period should be provided in multiples of 0.04, not 0.01, to
        % ensure the parabola to be symmetrical
        if any(mod(z.period,0.04) ~= 0) || any(mod(z.hold,0.04) ~= 0)
            error('The period and hold time of the triangle should be provided in multiples of 0.02 s.');
        end

        if length(z.segmentgain) ~= length(z.period)
            error('Segmentgain and period arrays are not equal in length')
        end

        msamples    = round(z.period ./ dt);
        hsamples    = round(z.hold ./ dt);
        tsamples    = round((z.period + z.hold) ./ dt);

        for ii=1:length(z.period)
            base{ii}                                                            = zeros(tsamples(ii),1);
            base{ii}(1:msamples(ii)/4)                                          =  (4/msamples(ii))^2;
            base{ii}((msamples(ii)/4+1):(msamples(ii)/2))                       = -(4/msamples(ii))^2;
            base{ii}((msamples(ii)/2+1):(hsamples+msamples(ii)/2))              = 0;
            base{ii}((hsamples+msamples(ii)/2+1):(hsamples+3*msamples(ii)/4))   = -(4/msamples(ii))^2;
            base{ii}((hsamples+3*msamples(ii)/4+1):end)                         =  (4/msamples(ii))^2;
            base{ii}                                                            = [0; cumsum(cumsum(base{ii}))];
        end

        runin       = zeros(round((z.runin+dt) / dt),1);

        ft_parts{1} = runin;

        for ii=1:z.amount

            if length(z.segmentgain) > 1
                idx             = mod(ii-1,length(z.segmentgain))+1;
                ft_parts{end+1} = z.segmentgain(idx) * base{idx}; %#ok<*AGROW>
            else
                ft_parts{end+1} = z.segmentgain * base; %#ok<*AGROW>
            end

            if ii < z.amount
                if length(z.spacing) > 1
                    ft_parts{end+1} = zeros(round((z.spacing(mod(ii-1,length(z.spacing))+1)+dt) / dt),1);
                else
                    ft_parts{end+1} = zeros(round((z.spacing+dt) / dt),1);
                end
            end
        end
        ft_parts{end+1}     = runin;

        ft  = [];
        for ii=1:length(ft_parts)
            ft  = [ft; ft_parts{ii}];
        end

        ft  = z.gain * (pi/180) * ft;

    elseif strcmpi(which,'cosinebell')

        % First make a parabola 'primitive' at the correct period
        % The period should be provided in multiples of 0.04, not 0.01, to
        % ensure the parabola to be symmetrical 


        if any(mod(z.period,0.04) ~= 0) || any(mod(z.hold,0.04) ~= 0)
            error('The period and hold time of the triangle should be provided in multiples of 0.02 s.');
        end

        if length(z.segmentgain) ~= length(z.period)
            error('Segmentgain and period arrays are not equal in length')
        end

        msamples    = round(z.period ./ dt);
        hsamples    = round(z.hold ./ dt);

        for ii=1:length(z.period)
            bbase       = sin((2*pi / z.period(ii) /2) * (0:dt:(z.period(ii)))).^2;    
            base{ii}(1:msamples(ii)/2)                                      = bbase(1:msamples(ii)/2);
            base{ii}((msamples(ii)/2+1):(hsamples+msamples(ii)/2))          = 1;
            base{ii}((hsamples+msamples(ii)/2+1):(hsamples+msamples(ii)+1)) = bbase((msamples(ii)/2+1):end);
            base{ii}    = base{ii}';
        end

        runin       = zeros(round((z.runin+dt) / dt),1);

        ft_parts{1} = runin;

        for ii=1:z.amount

            if length(z.segmentgain) > 1
                idx             = mod(ii-1,length(z.segmentgain))+1;
                ft_parts{end+1} = z.segmentgain(idx) * base{idx}; %#ok<*AGROW>
            else
                ft_parts{end+1} = z.segmentgain * base; %#ok<*AGROW>
            end

            if ii < z.amount
                if length(z.spacing) > 1
                    ft_parts{end+1} = zeros(round((z.spacing(mod(ii-1,length(z.spacing))+1)+dt) / dt),1);
                else
                    ft_parts{end+1} = zeros(round((z.spacing+dt) / dt),1);
                end
            end
        end
        ft_parts{end+1}     = runin;

        ft  = [];
        for ii=1:length(ft_parts)
            ft  = [ft; ft_parts{ii}];
        end

        ft  = z.gain * (pi/180) * ft;

    elseif strcmpi(which,'nieuwenhuizen2008')
    %     gain    = varargin{1};
        nd = [  6
                13
                27
                41
                53
                73
                103
                139
                194
                229];

        Ad = [  0.744
                0.567
                0.288
                0.161
                0.097
                0.062
                0.40
                0.028
                0.021
                0.017];


        wm = 2*pi / 98.3;

        phase =     [0.537
                     1.649
                     5.033
                     0.184
                     5.836
                     4.589
                     3.070
                     3.635
                     1.491
                     2.883];

        ft  = zeros(size(model.measurementTime));

        for oo=1:length(phase)
            ft  = ft + Ad(oo) * sin(nd(oo) * wm * (model.measurementTime + 8.09) + phase(oo));
        end

        ft = z.gain * ft;

    elseif strcmpi(which,'sequence')

        kk = 1;
        
        z.sName = strrep(z.sName,' ','');
        
        if length(z.sName) ~= length(z.sTime) || length(z.sName) ~= length(z.sGain)
            error('sName, sTime and/or sGain are not of the same length')
        end

        for oo=1:z.amount
            for ii=1:length(z.sName)

                if z.sName(ii) == 'c'
                    bit = zeros(round(z.sTime(ii)/dt),1);
                elseif z.sName(ii) == 'r'
                    bit = ramp(z.sTime(ii),dt);
                elseif z.sName(ii) == 'p'
                    bit = parabola(z.sTime(ii),dt);
                elseif z.sName(ii) == 'b'
                    bit = cosinebell(z.sTime(ii),dt);
                elseif z.sName(ii) == 's'
                    bit = step(z.sTime(ii),dt);
                else
                    error('Not a valid segment identifier.');
                end

                ft_parts{kk} = z.sGain(ii) * bit;

                kk = kk +1;
            end
        end

        ft  = 0;
        for ii=1:length(ft_parts)
            ft  = [ft; ft(end)+ft_parts{ii}];
        end    
        ft  = ft(2:end);
        ft  = z.gain * (pi/180) * ft;

    end

    if length(ft) > length(t)
        ft  = ft(1:length(t));
    elseif length(ft) < length(t)
        ft  = [ft; zeros(length(t)-length(ft),1)];
    end
end



function x = ramp(t,dt)
    x = linspace(0,1,t/dt)';
end

function x = step(t,dt)
    x = ones((t/dt),1);
end

function x = parabola(t,dt)
    if mod(t/dt,2) > 0
        error('The length of a parabola should be an even amount of samples.')
    end
    x                   = zeros((t/dt),1);
    x(1:(t/dt/2))       = 1;
    x((t/dt/2 + 1):end) = -1;
    x                   = cumsum(cumsum(x));
    x                   = x / max(x);
end

function x = cosinebell(t,dt)
    if mod(t/dt,2) > 0
        error('The length of a cosinebell should be an even amount of samples.')
    end

    x                   = sin((2*pi / t /4) * (0:dt:t)).^2;    
    x                   = x' / max(x);

end