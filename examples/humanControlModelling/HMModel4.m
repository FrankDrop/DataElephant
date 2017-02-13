classdef HMModel4 < matlab.mixin.Copyable
    
    properties
        % Model properties
        
        taskModel   % SIMULINK task model name
        pilotModel  % SIMULINK pilot model name
        
        taskParameterNames
        taskParameterValues
                
        pilotParameterNames
        latexPilotParameterNames
        
        taskInputFt
        taskInputFtn
        taskInputFd
        taskInputFdm
        taskInputFdLat
        
        pilotInputFt
        pilotInputY
        pilotInputPhi
        
        taskOutputSignalNames
        pilotOutputSignalNames
        
        % Simulation variables
        simulationTime
        measurementTime
        experimentTime
        dt
        
        % Simulation parameters
        Ypt             % Legacy
        Ype             % Legacy
        Ypp             % Legacy
        Ynms            % Legacy
        Yc              % Legacy
        Yroll           % Legacy
        Ylat            % Legacy
        YptBypassYnms   % Legacy
        
        % Define generic transfer functions, more flexibility
        defineTransferFunctions
        defTf
%         ptfCache
        
        % General estimation parameters
        measuredU
        measuredY
        realP
        estimationResults
        pickedResult
        
        % GA Parameters
        
        lowerBound
        upperBound
        
        useSS
        
        sA
        sB
        sC
        sD
        
        % Remnant
        remnantCalcMethod
        remnantRatioOrGain
        remnantOmegaN
        remnantDamping
        remnantSeed
        
        % Other   
        modifyReferenceSignal
        miscFields
%         dataTimestamp
    end
    
    methods
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% CONSTRUCTOR
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        function obj=HMModel4(tM,pM)
            obj.taskModel   = tM;
            obj.pilotModel  = pM;
            obj.realP       = -1;
            obj.pickedResult = 0;
            obj.defineTransferFunctions = 0;
        end
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% SETTERS and GETTERS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        %% Models
        
        function obj=setModels(obj,tM,pM)
            obj.taskModel   = tM;
            obj.pilotModel  = pM;
        end
        
        function obj = setYpe(obj,s)
            obj.Ype = s;
        end
        
        function obj = setYpt(obj,s)
            obj.Ypt = s;
        end
        
        function obj = setYpp(obj,s)
            obj.Ypp = s;
        end
        
        function obj = setYnms(obj,s)
            obj.Ynms = s;
        end
        
        function obj = setYc(obj,s)
            obj.Yc = s;
        end
        
        function obj = setYroll(obj,s)
            obj.Yroll = s;
        end
        
        function obj = setYlat(obj,s)
            obj.Ylat = s;
        end
        
        function obj = defineTf(obj,name,tfstring)
            obj.defineTransferFunctions = 1;
            obj.defTf.(name) = tfstring;
        end
                
        %% Parameter names
        
        function obj = setParameterNames(obj,tPN, pPN)
            obj.taskParameterNames          = tPN;
            obj.pilotParameterNames         = pPN;
        end
        
        function obj = setTaskLoggedSignalNames(obj,varargin)
            obj.taskOutputSignalNames   = varargin;
        end
        
        function obj = setPilotLoggedSignalNames(obj,varargin)
            obj.pilotOutputSignalNames   = varargin;
        end
        
        %% Parameter values
        
        function obj=setTaskParameterValues(obj,tPV)
            obj.taskParameterValues     = tPV;
        end
        
        function obj = setParametersByName(obj,parname,parvalue,lb,ub)
            
            if ~any(strcmpi(obj.pilotParameterNames,parname))
                error('You tried setting a parameter that does not exist in this model.');
            end
            
            if ~isempty(parvalue)
                obj.realP(strcmpi(obj.pilotParameterNames,parname))         = parvalue;
                obj.lowerBound(strcmpi(obj.pilotParameterNames,parname))    = lb;
                obj.upperBound(strcmpi(obj.pilotParameterNames,parname))    = ub;
            end
        end
        
        function obj = setPilotParameter(obj,parname,parvalue,verbose)            
            if ~isempty(parvalue) && any(strcmpi(obj.pilotParameterNames,parname))
                if verbose == 1
                    fprintf('Setting pilot parameter %s: old value was %1.4f',parname,obj.realP(strcmpi(obj.pilotParameterNames,parname)));
                end
                obj.realP(strcmpi(obj.pilotParameterNames,parname)) = parvalue;
                if verbose == 1
                    fprintf(', new value is %1.4f.\n',obj.realP(strcmpi(obj.pilotParameterNames,parname)));
                end
            end
        end
        
        function val = getPilotParameterValue(obj,parname)
            val = obj.realP(strcmpi(obj.pilotParameterNames,parname));
        end
        
        function val = getPilotParameterLowerBound(obj,parname)            
            val = obj.lowerBound(strcmpi(obj.pilotParameterNames,parname));
        end
        
        function val = getPilotParameterUpperBound(obj,parname)            
            val = obj.upperBound(strcmpi(obj.pilotParameterNames,parname));
        end
        
        function obj = setEstimationSettings(obj,lB,uB)
            if length(lB) ~= length(obj.pilotParameterNames)
                error('You specified a lower bound parameter vector of length %i, but there are %i pilot parameters.',length(lB),length(obj.pilotParameterNames));
            end
            if length(uB) ~= length(obj.pilotParameterNames)
                error('You specified an upper bound parameter vector of length %i, but there are %i pilot parameters.',length(uB),length(obj.pilotParameterNames));
            end
            
            obj.lowerBound  = lB;
            obj.upperBound  = uB;
        end
        
        function obj = setRealP(obj,rP)
            if length(rP) ~= length(obj.pilotParameterNames)
                error('You specified a parameter vector of length %i, but there are %i pilot parameters.',length(rP),length(obj.pilotParameterNames));
            end
            obj.realP = rP;
        end
        
        function obj = doesYptBypassYnms(obj,s)
            obj.YptBypassYnms = s;
        end
        
        function obj = setRemnantParams(obj,rRatioOrGain,rOmegaN,rDamping,varargin)
            
            p = inputParser;
            p.addParamValue('calcMethod',[]);
            p.addParamValue('remnantSeed',[]);
            p.parse(varargin{:});
            z = p.Results;
            
            if ~isempty(z.calcMethod)
                obj.remnantCalcMethod   = z.calcMethod;
            else
                obj.remnantCalcMethod   = 'ratio';
            end
            
            obj.remnantRatioOrGain  = rRatioOrGain;
            obj.remnantOmegaN       = rOmegaN;
            obj.remnantDamping      = rDamping;

            if ~isempty(z.remnantSeed)
                obj.remnantSeed = z.remnantSeed;
            else
                obj.remnantSeed = [];
            end
        end
        %% Time vectors
        
        function obj = setDt(obj,dT)
            obj.dt = dT;
        end
        
        function obj = setMeasurementTimeVector(obj,timeVector)
            obj.measurementTime = timeVector(:);
        end
        
        function obj = setExperimentTimeVector(obj,timeVector)
            obj.experimentTime = timeVector(:);
        end
        
        function obj = setSimulationTimeVector(obj,timeVector)
            obj.simulationTime = timeVector(:);
        end
 
        %% Signal values
        
        function obj = setPilotFt(obj,ft)
            
            obj.pilotInputFt = ft;
            
            if length(ft) ~= length(obj.experimentTime)
                error('Target signal length(ft)=%i does not have the correct length (should be %i).',length(ft),length(obj.experimentTime));
            end
        end
        
        function obj = setPilotY(obj,y)
            
            obj.pilotInputY = y;

            if length(y) ~= length(obj.experimentTime)
                error('System output signal y does not have the correct length.');
            end
        end
        
        function obj = setPilotPhi(obj,ph)
            
            obj.pilotInputPhi = ph;

            if length(ph) ~= length(obj.experimentTime)
                error('System output signal phi does not have the correct length.');
            end
        end
        
        function obj = setMeasuredControlSignal(obj,mU)
            if (length(mU) ~= length(obj.experimentTime))
                error('The measured control signal should have the same length as the experiment time.')
            end
            
            obj.measuredU       = mU;
        end
        
        function obj = setMeasuredStateResponse(obj,mY)
            obj.measuredY   = mY;
        end
        
        function obj = setTaskFt(obj,ft)
            if length(ft) ~= length(obj.measurementTime)
                error('Target signal ft does not have the correct length.\nlength(ft) = %i, length(measurementTime) = %i.',...
                    length(ft),length(obj.measurementTime));
            end
            obj.taskInputFt = ft;
        end
        
        function obj = setTaskFtn(obj,ftn)
            if length(ftn) ~= length(obj.measurementTime)
                error('Target noise signal ftn does not have the correct length.\nlength(ftn) = %i, length(measurementTime) = %i.',...
                    length(ftn),length(obj.measurementTime));
            end
            obj.taskInputFtn = ftn;
        end
        
        function obj = setTaskFd(obj,fd)
            if length(fd) ~= length(obj.measurementTime)
                error('Disturbance signal fd does not have the correct length.\nlength(fd) = %i, length(measurementTime) = %i.',...
                    length(fd),length(obj.measurementTime));
            end
            
            obj.taskInputFd = fd;
        end
        
        function obj = setTaskFdm(obj,fd)
            if length(fd) ~= length(obj.measurementTime)
                error('Motion disturbance signal fdm does not have the correct length.\nlength(fdm) = %i, length(measurementTime) = %i.',...
                    length(fd),length(obj.measurementTime));
            end
            obj.taskInputFdm = fd;
        end
        
        function obj = setTaskFdLat(obj,fd2)            
            obj.taskInputFdLat = fd2;
            if length(fd2) ~= length(obj.measurementTime)
                error('Disturbance signal fd2 (lateral) does not have the correct length');
            end
        end
        
        
        %% Get
        
        function n = getNumPars(obj)
            n = length(obj.pilotParameterNames);
        end
        
        function r = getUpperBound(obj,index)
            r = obj.upperBound(index);
        end
        
        function r = getLowerBound(obj,index)
            r = obj.lowerBound(index);
        end
        
        function p = getRealP(obj,varargin)
            if nargin > 1
                p = obj.realP(varargin{1});
            else
                p = obj.realP;
            end
        end
        
        function s = getPilotParameterName(obj,index)
            s = obj.pilotParameterNames{index};
        end
        
        function s = getJacobianPilotParameterName(obj,index)
            s = obj.jacobianPilotParameterNames{index};
        end
        
        function obj = setLatexPilotParameterNames(obj,lPPN)
            obj.latexPilotParameterNames = lPPN;
        end
        
        function s = getLatexPilotParameterName(obj,index)
            s = ['$' obj.latexPilotParameterNames{index} '$'];
        end
        
        function s = getAllLatexPilotParameterNames(obj)
            for oo=1:obj.getNumPars()
                s{oo} = obj.getLatexPilotParameterName(oo); %#ok<AGROW>
            end
        end
        
        function obj = useSSforGenetic(obj,useBool)
            obj.useSS  = useBool;
        end        
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% FUNCTIONS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        function y = generateSimulationSignal2(obj,x,which)

            
            if length(x) ~= length(obj.measurementTime)
                error('Signal %s was not of the same length as the measurement time.\n\tlength(%s) = %i.\n\tlength(measurementTime) = %i.\n',...
                    which, which, length(x), length(obj.measurementTime));
            end
            
            if strcmpi(which,'ft')
                % First pad the signal with zeros to the length of the
                % experiment time.
                xn  = zeros(size(obj.experimentTime));
                xn((end-length(obj.measurementTime)+1):end)  = x;
                x   = xn;
                
                % Check if the experiment time is equal to the simulation time.
                % If so, we don't have to 'tile' the signal.
                if length(obj.experimentTime) == length(obj.simulationTime)
                    y = x;
                else
                    % If not, we have to tile/repeat the signal, such that a
                    % longer input signal is created.
                    repetitions     = ceil(length(obj.simulationTime) / length(obj.experimentTime));
                    b               = repmat(x,repetitions,1);
                    startAtIndex    = repetitions*length(obj.experimentTime) - length(obj.simulationTime) +1;

                    y = b(startAtIndex:end);
                end            
            end
            
            if strcmpi(which,'fd')
                % The disturbance signal is assumed to be periodic every
                % measurementTime seconds. Thus, we can simply 'tile' the
                % disturbance signal to the length of the simulationTime.
                
                repetitions     = ceil(length(obj.simulationTime) / length(obj.measurementTime));
                b               = repmat(x,repetitions,1);
                startAtIndex    = repetitions * length(obj.measurementTime) - length(obj.simulationTime) + 1;
                y               = b(startAtIndex:end);
            end
        end
        
        function y = generateSimulationSignal(obj,x,which)

            
            if length(x) ~= length(obj.measurementTime)
                error('Signal %s was not of the same length as the measurement time.\n\tlength(%s) = %i.\n\tlength(measurementTime) = %i.\n',...
                    which, which, length(x), length(obj.measurementTime));
            end
            
            if strcmpi(which,'ft')
                
                % Find out whether the target signal nicely starts and ends
                % with at least half a second of zeros.
                
                if all(x(1:round(0.5/obj.dt)) == 0) && all(x((end-round(0.5/obj.dt):end)) == 0)
                    % First pad the signal with zeros to the length of the
                    % experiment time.
                    xn  = zeros(size(obj.experimentTime));
                    xn((end-length(obj.measurementTime)+1):end)  = x;
                    x   = xn;

                    % Check if the experiment time is equal to the simulation time.
                    % If so, we don't have to 'tile' the signal.
                    if length(obj.experimentTime) == length(obj.simulationTime)
                        y = x;
                    else
                        % If not, we have to tile/repeat the signal, such that a
                        % longer input signal is created.
                        repetitions     = ceil(length(obj.simulationTime) / length(obj.experimentTime));
                        b               = repmat(x,repetitions,1);
                        startAtIndex    = repetitions*length(obj.experimentTime) - length(obj.simulationTime) +1;

                        y = b(startAtIndex:end);
                    end
                else
                    % So the signal does not start and end with zeros. The
                    % signal needs a fade in and fade out.
                    % The fade in will start at zero and will be the same
                    % duration as the difference between the measurement
                    % time and the experiment time.
                    
                    fadeinSamples                               = length(obj.experimentTime) - length(obj.measurementTime);
                    fadein                                      = zeros(fadeinSamples,1);
                    fadein((end-round(fadeinSamples/5)):end)    = 1;
                    rampupSamples                               = round(fadeinSamples/5):(length(fadein)-round(fadeinSamples/5));
                    fadein(rampupSamples)                       = sin(pi/2*(1:length(rampupSamples))/length(rampupSamples)).^2;
                    
                    fadeout         = flipud(fadein);
                    
                    intro           = fadein .* x((end-fadeinSamples+1):end);
                    outro           = fadeout .* x(1:fadeinSamples);
                    
                    xn      = [];
                    while length(xn) < length(obj.simulationTime)
                        xn  = [outro; intro; x; xn]; %#ok<AGROW>
                    end

                    y = xn((end-length(obj.simulationTime)+1):end);
                end
            elseif strcmpi(which,'fd')
                % The disturbance signal is assumed to be periodic every
                % measurementTime seconds. Thus, we can simply 'tile' the
                % disturbance signal to the length of the simulationTime.
                
                repetitions     = ceil(length(obj.simulationTime) / length(obj.measurementTime));
                b               = repmat(x,repetitions,1);
                startAtIndex    = repetitions * length(obj.measurementTime) - length(obj.simulationTime) + 1;
                y               = b(startAtIndex:end);
            end
        end
        
        %% Frequency responses
        
        function Ype = getYpeFRF(obj,p,w)
            if ~isempty(obj.Ype)
                Ype = getFRF(obj,'Ype',p,w);
            else
                error('You are requesting a frequency response function that is not defined.')
            end
        end
        
        function Ypt = getYptFRF(obj,p,w)
            if ~isempty(obj.Ypt)
                Ypt = getFRF(obj,'Ypt',p,w);
            else
                error('You are requesting a frequency response function that is not defined.')
            end
        end
        
        function Ypt = getYppFRF(obj,p,w)
            Ypt = getFRF(obj,'Ypp',p,w);
        end
        
        function Ynms = getYnmsFRF(obj,p,w)
            Ynms = getFRF(obj,'Ynms',p,w);
        end
        
        function Yc = getYcFRF(obj,p,w)
            Yc = getFRF(obj,'Yc',p,w);
        end
        
        function Yc = getYrollFRF(obj,p,w)
            Yc = getFRF(obj,'Yroll',p,w);
        end
        
        function Yc = getYlatFRF(obj,p,w)
            Yc = getFRF(obj,'Ylat',p,w);
        end
        
        function frf = getFRF(obj,which,p,w)
            
            if obj.defineTransferFunctions == 0
                for jj=1:length(obj.pilotParameterNames)
                    pp.(obj.pilotParameterNames{jj})    = p(jj);
                end

                for jj=1:length(obj.taskParameterNames)
                    tp.(obj.taskParameterNames{jj})     = obj.taskParameterValues{jj}; %#ok<*STRNU>
                end

                S = tf('s');
                switch which
                    case 'Ypt'
                        frf = squeeze(freqresp(tf(eval(['(' obj.Ypt ') * exp(-S * pp.tau_p_t)'])),w));
                    case 'Ype'
                        frf = squeeze(freqresp(tf(eval(['(' obj.Ype ') * exp(-S * pp.tau_p_e)'])),w));
                    case 'Ypp'
                        frf = squeeze(freqresp(tf(eval(['(' obj.Ypp ') * exp(-S * pp.tau_p_p)'])),w));
                    case 'Ynms'
                        frf = squeeze(freqresp(tf(eval(obj.Ynms)),w));
                    case 'Yc'
                        frf = squeeze(freqresp(tf(eval(obj.Yc)),w));
                    case 'Ylat'
                        frf = squeeze(freqresp(tf(eval(obj.Ylat)),w));
                    case 'Yroll'
                        frf = squeeze(freqresp(tf(eval(obj.Yroll)),w));
                    case 'Yn'
                        frf = squeeze(freqresp(getRemnantFilter(obj),w));
                    otherwise
                        error('You requested a response function that does not exist: %s.',which)
                end
            else
                for jj=1:length(obj.pilotParameterNames)
                    pp.(obj.pilotParameterNames{jj})    = p(jj);
                end

                for jj=1:length(obj.taskParameterNames)
                    tp.(obj.taskParameterNames{jj})     = obj.taskParameterValues{jj}; %#ok<*STRNU>
                end

                S   = tf('s');
                s   = tf('s');
                
                if strcmpi(which,'Yn')
                    frf     = squeeze(freqresp(getRemnantFilter(obj),w));
                else
                    frf     = squeeze(freqresp(tf(eval(obj.defTf.(which))),w));
                end
            end
        end
        
        %% Run models
        
        %%%
        % RunPilotModel
        %%%

        function [x_e,x_m] = runPilotModel(obj,p)
            
            x_e      = struct();
            x_e.t    = obj.experimentTime;
            
            for jj=1:length(obj.pilotParameterNames)
                pp.(obj.pilotParameterNames{jj}) = p(jj);
            end
            
            for jj=1:length(obj.taskParameterNames)
                tp.(obj.taskParameterNames{jj})  = obj.taskParameterValues{jj};
            end

            iS.ft   = obj.pilotInputFt;
            iS.y    = obj.pilotInputY;
            
            if ~isempty(obj.pilotInputPhi)
                iS.phi  = obj.pilotInputPhi;
            end
            
            t       = obj.experimentTime;
            S   = tf('s');
            s   = tf('s');
            
            if obj.defineTransferFunctions == 0
                S = tf('s');

                if ischar(obj.Ypt)
                    ptf_Ypt     = tf(eval(obj.Ypt));  %#ok<*NASGU>
                end

                if ischar(obj.Ype)
                    ptf_Ype     = tf(eval(obj.Ype));
                end

                if ischar(obj.Ypp)
                    ptf_Ypp     = tf(eval(obj.Ypp));
                end

                if ischar(obj.Ynms)
                    ptf_Ynms    = tf(eval(obj.Ynms));
                end

                if ischar(obj.Yc)
                    ptf_Yc      = tf(eval(obj.Yc));
                end

                if ischar(obj.Yroll)
                    ptf_Yroll   = tf(eval(obj.Yroll));
                end

                if ischar(obj.Ylat)
                    ptf_Ylat    = tf(eval(obj.Ylat));
                end

                if ~isempty(obj.YptBypassYnms)
                    ptf_Bypass  = obj.YptBypassYnms == 1;
                else
                    ptf_Bypass  = 0;
                end
            else
                tfNames     = fieldnames(obj.defTf);
                
                for oo=1:length(tfNames)
                    strippedFromTimeDelay   = regexprep(obj.defTf.(tfNames{oo}),'* exp\([\D]+\)','');
                    ptf.(tfNames{oo})       = tf(eval(strippedFromTimeDelay));
                end
            end

            simSettings = simset('SrcWorkspace','current');
            sim(obj.pilotModel,[],simSettings);

            for ii=1:length(obj.pilotOutputSignalNames)
                x_e.(obj.pilotOutputSignalNames{ii}) = eval(obj.pilotOutputSignalNames{ii});
            end
            
            x_e.ft  = iS.ft;
            x_e.y   = iS.y;
            
            if isfield(iS,'phi')
                x_e.phi = iS.phi;
            end
            
            x_m = obj.getMeasurementBit(x_e);
        end
        
        %%%
        % RunTaskModel
        %%%
        
        function [x_s,x_e,x_m] = runTaskModel(obj,p,z)

            if nargout ~= 3
                error('You are probably using old code!')
            end
            
            x_s     = struct();
            x_s.t   = obj.simulationTime;
            
            for jj=1:length(obj.pilotParameterNames)
                pp.(obj.pilotParameterNames{jj})    = p(jj);
            end
            
            for jj=1:length(obj.taskParameterNames)
                tp.(obj.taskParameterNames{jj})     = obj.taskParameterValues{jj}; %#ok<*STRNU>
            end
            
            if ~isempty(obj.taskInputFt)
                iS.ft       = obj.generateSimulationSignal(obj.taskInputFt,'ft');
            end
            
            if ~isempty(obj.taskInputFd)
                iS.fd       = obj.generateSimulationSignal(obj.taskInputFd,'fd');
            end
            
            if ~isempty(obj.taskInputFtn)
                iS.ftn      = obj.generateSimulationSignal(obj.taskInputFtn,'fd');
            end
            
            if ~isempty(obj.taskInputFdLat)
                iS.fdLat    = obj.generateSimulationSignal(obj.taskInputFdLat,'fd');
            end
            
            if ~isempty(obj.taskInputFdm)
                iS.fdm      = obj.generateSimulationSignal(obj.taskInputFdm,'fd');
            end

            S   = tf('s');
            s   = tf('s');
            
            if obj.defineTransferFunctions == 0
                if ischar(obj.Ypt)
                    ptf_Ypt     = tf(eval(obj.Ypt));  %#ok<*NASGU>
                end

                if ischar(obj.Ype)
                    ptf_Ype     = tf(eval(obj.Ype));
                end

                if ischar(obj.Ypp)
                    ptf_Ypp     = tf(eval(obj.Ypp));
                end

                if ischar(obj.Ynms)
                    ptf_Ynms    = tf(eval(obj.Ynms));
                end

                if ischar(obj.Yc)
                    ptf_Yc      = tf(eval(obj.Yc));
                end

                if ischar(obj.Yroll)
                    ptf_Yroll   = tf(eval(obj.Yroll));
                end

                if ischar(obj.Ylat)
                    ptf_Ylat    = tf(eval(obj.Ylat));
                end

                if ~isempty(obj.YptBypassYnms)
                    ptf_Bypass  = obj.YptBypassYnms == 1;
                else
                    ptf_Bypass  = 0;
                end
            else
                tfNames     = fieldnames(obj.defTf);
                for oo=1:length(tfNames)
                    strippedFromTimeDelay   = regexprep(obj.defTf.(tfNames{oo}),'* exp\([\D]+\)','');
                    ptf.(tfNames{oo})       = tf(eval(strippedFromTimeDelay));
                end
            end
            
%             param.far_delay             = (z.mpc_N+1)*z.mpc_ts;           
            
            iS.n    = obj.generateRemnant(p);
            t       = obj.simulationTime;
            simdt   = t(2) - t(1);
            
            T_end           = t(end); %+param.far_delay;
            
            simSettings = simset('SrcWorkspace','current');
            sim(obj.taskModel,[],simSettings);
            
            for ii=1:length(obj.taskOutputSignalNames)
                x_s.(obj.taskOutputSignalNames{ii})  = eval(obj.taskOutputSignalNames{ii});
            end
            
            iSfields    = fieldnames(iS);
            for ii=1:length(iSfields)
                x_s.(iSfields{ii}) = iS.(iSfields{ii});
            end
            
            x_e         = obj.getExperimentBit(x_s);
            x_m         = obj.getMeasurementBit(x_s);
            
        end
        
        function L = getCost(obj,p,varargin)
            
            n = inputParser;
            n.addParamValue('fiton',[]);
            n.parse(varargin{:});
            z = n.Results;

            if obj.useSS
                [~,x_m] = obj.runSSModel(p,0);
            else
                for ii=1:obj.getNumPars()
                    if (p(ii) > obj.getUpperBound(ii) || p(ii) < obj.getLowerBound(ii))
                        L = 999;
                        return;
                    end
                end
                [~,x_m] = obj.runPilotModel(p);
            end
            
            if ~isempty(z.fiton)
%                 fprintf('Fitting on part of the data.')
                N   = length(x_m.t(z.fiton));
                
                % calculate output error
                mesu    = gmt(length(obj.measurementTime),obj.measuredU);
                Res     = mesu(z.fiton) - x_m.u(z.fiton);

                % % calculate output error covariance
                R = 1/length(Res)*(Res.')*Res;

                % calculate likelihood function
                L = N/2*log(2*pi) + N/2*log(det(R)) + (1/2*(Res).') * pinv(R) * (Res);
            else
%                 fprintf('Fitting on all data.')
                N   = length(x_m.t);
                
                % calculate output error
                Res = gmt(length(obj.measurementTime),obj.measuredU) - x_m.u;

                % % calculate output error covariance
                R = 1/length(Res)*(Res.')*Res;

                % calculate likelihood function
                L = N/2*log(2*pi) + N/2*log(det(R)) + (1/2*(Res).') * pinv(R) * (Res);
            end
            
            
        end
        
        function obj = addEstimationResult(obj,varargin)
            
            p = inputParser;
            p.addParamValue('estimationMethod',[]);
            p.addParamValue('parameterVector',[]);
            p.addParamValue('parameterHistory',[]);            
            p.addParamValue('likelihood',[]);
            p.addParamValue('crlb',[]);
            p.addParamValue('p0',[]);
            p.addParamValue('p0source',[]);
            p.addParamValue('costHistory',[]);
            p.parse(varargin{:});
            z = p.Results;
            
            index = length(obj.estimationResults)+1;
            obj.estimationResults{index}.ID                 = index;
            obj.estimationResults{index}.estimationMethod   = z.estimationMethod;
            obj.estimationResults{index}.parameterVector    = z.parameterVector;
            obj.estimationResults{index}.parameterHistory   = z.parameterHistory;
            obj.estimationResults{index}.likelihood         = z.likelihood;
            obj.estimationResults{index}.crlb               = z.crlb;
            obj.estimationResults{index}.p0                 = z.p0;
            obj.estimationResults{index}.p0source           = z.p0source;
            obj.estimationResults{index}.costHistory        = z.costHistory;

        end
        
        function obj = addMiscField(obj,fieldName,fieldValue)
            obj.miscFields.(fieldName)  = fieldValue;
        end
        
        function result = getEstimationResults(obj,estimationMethod,which)
            jj=1;
            
            result = {};
            latest = {};
            
            if length(obj.estimationResults) < 1
                return;
            end
            
            for ii=1:length(obj.estimationResults)
                if strcmp(obj.estimationResults{ii}.estimationMethod, estimationMethod)
                    result{jj} = obj.estimationResults{ii}; %#ok<AGROW>
                    jj  = jj+1;
                end
            end
            
            if strcmp(which,'all')    
                return;
            elseif strcmp(which,'allwithinbounds')
                clear newresult;
                kk = 1;
                for oo=1:length(result)
                    if sum(logical(result{oo}.parameterVector < obj.lowerBound') | logical(result{oo}.parameterVector > obj.upperBound')) > 0
                        disp('Result not within bounds')
                        newresult{kk} = result{oo}; %#ok<AGROW>
                        kk=kk+1;
                    else
                        newresult{kk} = result{oo}; %#ok<AGROW>
                        kk=kk+1;
                    end
                end
                result = newresult;
            elseif strcmp(which,'picked')
                try
                    result = {result{obj.pickedResult}}; %#ok<CCAT1>
                catch e
                    fprintf('\nThe picked-index (%i) does not belong to a result.',obj.pickedResult)
                end
            elseif strcmp(which,'last') && length(result) > 1
                latest{1} = result{1};
                for ii=2:length(result)
                    if result{ii}.ID > latest{1}.ID
                        latest{1} = result{ii}; 
                    end
                end
                result = {latest{1}}; %#ok<CCAT1>
            else
                return;
            end
        end
        
%         function obj = calculateSS(obj,pade_order,varargin) %#ok<INUSD>
% 
%             fprintf('\nGoing to generate SS model function files.');
%             
%             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%             % generate model parts for mle estimation
%             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
%             % create symbolic variables workspace
%             for pars = 1:obj.getNumPars()
%                 eval([obj.getPilotParameterName(pars) ' = sym(''' obj.getPilotParameterName(pars) ''', ''real'');'])
%             end
%             
%             % Set the task parameters            
%             for jj=1:length(obj.taskParameterNames)
%                 eval([obj.taskParameterNames{jj} ' = obj.taskParameterValues{jj};'])
%             end
%             
%             % generate symbolic Laplace 's'
%             S = sym('S');
% 
%             for oo=1:obj.getNumSSSubExpressions()
%                 eval([obj.getSSSubExpressionName(oo) ' = expand(' obj.getSSSubExpression(oo) ');']);
%             end
% 
%             for iii=1:obj.getNumSSMainExpressions()
% 
%                 % retrieve numerator and denominator of symbolic transfer function
% 
%                 eval(['Hmain = ' obj.getSSMainExpression(iii) ';']);
% 
%                 [num_sym,den_sym] = numden(simplify(expand(Hmain)));
% 
%                 % retrieve coefficients of num and den polynomials
%                 [num_coeffs_sym, num_ords] = SYM_COEFFS(num_sym,S);
%                 [den_coeffs_sym, den_ords] = SYM_COEFFS(den_sym,S);
% 
%                 % retrieve highest order in denominator: size of A
%                 N(iii) = den_ords(end); %#ok<AGROW>
% 
%                 % retrieve coefficient of highest order coefficient in the denominator
%                 aN = den_coeffs_sym(end);
% 
%                 % generate symbolic variables for the row in A and C that hold symbolic
%                 % variables
%                 As = [[zeros(N(iii)-1,1) eye(N(iii)-1)]; zeros(1,N(iii))];
%                 As = sym(As);
%                 Cs = sym(zeros(1,N(iii)));
%                 B  = zeros(N(iii),1);
%                 B(end) = 1;
% 
%                 % insert coefficients in state-space matrices
%                 for ns = 0:N(iii)-1
%                     inds = find(den_ords == ns);
%                     if ~isempty(inds)
%                         As(end,ns+1) = -den_coeffs_sym(inds(1))/aN;
%                     end
% 
%                     inds = find(num_ords == ns);
%                     if ~isempty(inds)
%                         Cs(1,ns+1) =  num_coeffs_sym(inds(1))/aN;     
%                     end
%                 end
% 
%                 ssABC(iii).As   = As; %#ok<AGROW>
%                 ssABC(iii).B    = B; %#ok<AGROW>
%                 ssABC(iii).Cs   = Cs; %#ok<AGROW>
%             end
% 
%             fprintf('\nGoing to generate symbolic state-space model.');
%             
%             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%             % generate symbolic state-space pilot model, dependent on condition
%             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%       
% 
%             % combine individual channel state-space models
%             As = sym(zeros(sum(N)));
%             As(1:N(1),1:N(1)) = ssABC(1).As;
%             
%             for iii=2:length(N)
%                 As((sum(N(1:(iii-1)))+1):(sum(N(1:iii))),(sum(N(1:(iii-1)))+1):(sum(N(1:iii)))) = ssABC(iii).As;
%             end
% 
%             Cs = ssABC(1).Cs;
%             for iii=2:length(N)
%                 Cs = [Cs ssABC(iii).Cs]; %#ok<AGROW>
%             end
% 
%             Bs  = [ssABC(1).B zeros(N(1),length(N)-1)];
%             for iii=2:length(N)
%                 newB    = [zeros(N(iii),iii-1) ssABC(iii).B zeros(N(iii),length(N)-iii)];
%                 Bs      = [Bs; newB]; %#ok<AGROW>
%             end
% 
%             Ds = zeros(1,obj.getNumSSMainExpressions());
%            
%             fprintf('\nGoing to calculate pilot model jacobians.');
%             
%             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%             % calculate pilot model jacobians
%             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%       
% 
%             % retrieve size of total As
%             NN = size(As,1);
% 
%             % Jacobians of A and C            
%             JAs = sym(zeros(NN,NN,obj.getNumPars()));
%             JCs = sym(zeros(1,NN,obj.getNumPars()));
%             
%             for pars = 1:obj.getNumPars()
%                 for rows = cumsum(N)
%                     eval(['JAs(rows,:,pars) = diff(As(rows,:), ' obj.getPilotParameterName(pars) ');' ]);
%                 end
%                 eval(['JCs(1,:,pars) = diff(Cs(1,:), ' obj.getPilotParameterName(pars) ');' ])
%             end
% 
%             % Jacobians of B and C
%             JBs = zeros(NN,size(Ds,2),obj.getNumPars());
%             JDs = zeros(1,size(Ds,2),obj.getNumPars());
%             
%             obj.sA  = As;
%             obj.sB  = Bs;
%             obj.sC  = Cs;
%             obj.sD  = Ds;
%             
%             if isempty(varargin)
%                 fprintf('\nWriting matrix A.');
%                 writeMatrixFile([obj.SSModelName 'matrixA.m'],[obj.SSModelName 'matrixA'],obj.sA,obj.pilotParameterNames);
%                 fprintf('\nWriting matrix B.');
%                 writeMatrixFile([obj.SSModelName 'matrixB.m'],[obj.SSModelName 'matrixB'],obj.sB,obj.pilotParameterNames);
%                 fprintf('\nWriting matrix C.');
%                 writeMatrixFile([obj.SSModelName 'matrixC.m'],[obj.SSModelName 'matrixC'],obj.sC,obj.pilotParameterNames);
%                 fprintf('\nWriting matrix D.');
%                 writeMatrixFile([obj.SSModelName 'matrixD.m'],[obj.SSModelName 'matrixD'],obj.sD,obj.pilotParameterNames);
% 
%                 fprintf('\nWriting matrix JA.');
%                 writeMatrixFile([obj.SSModelName 'matrixJA.m'],[obj.SSModelName 'matrixJA'],JAs,obj.pilotParameterNames);
%                 fprintf('\nWriting matrix JB.');
%                 writeMatrixFile([obj.SSModelName 'matrixJB.m'],[obj.SSModelName 'matrixJB'],JBs,obj.pilotParameterNames);
%                 fprintf('\nWriting matrix JC.');
%                 writeMatrixFile([obj.SSModelName 'matrixJC.m'],[obj.SSModelName 'matrixJC'],JCs,obj.pilotParameterNames);
%                 fprintf('\nWriting matrix JD.');
%                 writeMatrixFile([obj.SSModelName 'matrixJD.m'],[obj.SSModelName 'matrixJD'],JDs,obj.pilotParameterNames);
%             else
%                 fprintf('\nWriting matrix A.');
%                 writeMatrixFile(['D:\Dropbox\MLEStorage\' varargin{1} '_A.m'],[varargin{1} '_A'],obj.sA,obj.pilotParameterNames);
%                 fprintf('\nWriting matrix B.');
%                 writeMatrixFile(['D:\Dropbox\MLEStorage\' varargin{1} '_B.m'],[varargin{1} '_B'],obj.sB,obj.pilotParameterNames);
%                 fprintf('\nWriting matrix C.');
%                 writeMatrixFile(['D:\Dropbox\MLEStorage\' varargin{1} '_C.m'],[varargin{1} '_C'],obj.sC,obj.pilotParameterNames);
%                 fprintf('\nWriting matrix D.');
%                 writeMatrixFile(['D:\Dropbox\MLEStorage\' varargin{1} '_D.m'],[varargin{1} '_D'],obj.sD,obj.pilotParameterNames);
% 
%                 fprintf('\nWriting matrix JA.');
%                 writeMatrixFile(['D:\Dropbox\MLEStorage\' varargin{1} '_JA.m'],[varargin{1} '_JA'],JAs,obj.pilotParameterNames);
%                 fprintf('\nWriting matrix JB.');
%                 writeMatrixFile(['D:\Dropbox\MLEStorage\' varargin{1} '_JB.m'],[varargin{1} '_JB'],JBs,obj.pilotParameterNames);
%                 fprintf('\nWriting matrix JC.');
%                 writeMatrixFile(['D:\Dropbox\MLEStorage\' varargin{1} '_JC.m'],[varargin{1} '_JC'],JCs,obj.pilotParameterNames);
%                 fprintf('\nWriting matrix JD.');
%                 writeMatrixFile(['D:\Dropbox\MLEStorage\' varargin{1} '_JD.m'],[varargin{1} '_JD'],JDs,obj.pilotParameterNames);
%             end
%         end
        
%         function [x_e,x_m] = runSSModel(obj, p, calculateJacobian)
%             
%             path([pwd '/functions'],path);
%             
%             IN = [];
%             
%             for jj=1:length(obj.pilotParameterNames)
%                 pars.(obj.pilotParameterNames{jj})      = p(jj); %#ok<STRNU>
%             end
%             
%             for ii=1:length(obj.pilotInputSignalNames)
%                     IN      = [IN obj.pilotInputSignals{ii}]; %#ok<AGROW>
%             end
%             
%             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%             % substitute symbolic variables with their current values
%             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
%             % create model parameter variables in this workspace
%             
%             A   = eval([obj.SSModelName 'matrixA(p)']);
%             B   = eval([obj.SSModelName 'matrixB(p)']);
%             C   = eval([obj.SSModelName 'matrixC(p)']);
%             D   = eval([obj.SSModelName 'matrixD(p)']);
%             
%             % retrieve number of states and inputs
%             [~, n_inputs] = size(B);
% 
%             % retrieve number of parameters (final entry is variance of residue!)
%             n_pars = obj.getNumPars();
%                         
%             if calculateJacobian == 1
%             
%                 JA  = eval([obj.SSModelName 'matrixJA(p)']);
%                 JB  = eval([obj.SSModelName 'matrixJB(p)']);
%                 JC  = eval([obj.SSModelName 'matrixJC(p)']);
%                 JD  = eval([obj.SSModelName 'matrixJD(p)']);
% 
%                 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                 % construct model to simulate output and calculate output derivatives
%                 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
%                 % calculate the output and derivatives of the output
%                 IN = [IN zeros(length(obj.experimentTime),n_pars*n_inputs)]; % dudp is zero
% 
%                 At = [A zeros(size(A,1), size(A,2)*n_pars)];
%                 Bt = [B zeros(size(B,1), size(B,2)*n_pars)];
%                 Ct = [C zeros(size(C,1), size(C,2)*n_pars)];
%                 Dt = [D zeros(size(D,1), size(D,2)*n_pars)];
%                 for go_pars = 1:n_pars
%                     At = [At; JA(:,:,go_pars) zeros(size(A,1), size(A,2)*(go_pars-1)) A zeros(size(A,1),size(A,2)*(n_pars-go_pars))]; %#ok<AGROW>
%                     Bt = [Bt; JB(:,:,go_pars) zeros(size(B,1), size(B,2)*(go_pars-1)) B zeros(size(B,1),size(B,2)*(n_pars-go_pars))]; %#ok<AGROW>
%                     Ct = [Ct; JC(:,:,go_pars) zeros(size(C,1), size(C,2)*(go_pars-1)) C zeros(size(C,1),size(C,2)*(n_pars-go_pars))]; %#ok<AGROW>
%                     Dt = [Dt; JD(:,:,go_pars) zeros(size(D,1), size(D,2)*(go_pars-1)) D zeros(size(D,1),size(D,2)*(n_pars-go_pars))]; %#ok<AGROW>
%                 end
%                 
%                 y_mod       = lsim(ss(At,Bt,Ct,Dt), IN, obj.experimentTime);
%                 x_e.t       = obj.experimentTime;
%                 x_e.u       = y_mod(:,1);
%                 x_e.dydp    = y_mod(:, 2:obj.getNumPars()+1);
%             else
% %                 size(obj.experimentTime)
%                 y_mod   = lsim(ss(A,B,C,D), IN, obj.experimentTime);
%                 x_e.t   = obj.experimentTime;
%                 x_e.u   = y_mod(:,1);
%             end
%             
%             x_m = obj.getMeasurementBit(x_e);
%         end

%         function [An,Bn,Cn,Dn] = getSSNumeric(obj, p) %#ok<INUSD>
% 
%             % create model parameter variables
%             for pars = 1:obj.getNumPars()
%                 eval([obj.pilotParameterNames{pars} ' = p(pars);'])
%             end
% 
%             % evaluate symbolic transfer function, if not numeric
%             if ~isnumeric(obj.sA)
%                 An = eval(obj.sA);
%             else
%                 An = obj.sA;
%             end
%             if ~isnumeric(obj.sB)
%                 Bn = eval(obj.sB);
%             else
%                 Bn = obj.sB;
%             end
%             if ~isnumeric(obj.sC)
%                 Cn = eval(obj.sC);
%             else
%                 Cn = obj.sC;
%             end
%             if ~isnumeric(obj.sB)
%                 Dn = eval(obj.sD);
%             else
%                 Dn = obj.sD;
%             end
%         end
        
%         function [dL, dF, L] = getMLEfromSS(obj,p)
%            
%             [~,x_m] = obj.runSSModel(p,1);
%             
%             N = length(x_m.t);
%             
%             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%             % calculate residual and residual variance
%             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%             
%             % calculate output error
%             Res = obj.measuredU - x_m.u;
% 
%             % % calculate output error covariance
%             R = 1/length(Res)*(Res.')*Res;
% 
%             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%             % do likelihood calculations
%             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%             
%             % calculate likelihood function gradient
%             dL =  -x_m.dydp.' * inv(R) * (obj.measuredU-x_m.u);
%             
%             % calculate Fisher information matrix
%             dF = -x_m.dydp.' * inv(R) * -x_m.dydp;
%             
%             % calculate likelihood function
%             L = N/2*log(2*pi) + N/2*log(det(R)) + 1/2 * (obj.measuredU-x_m.u) .' * inv(R) * (obj.measuredU-x_m.u);
%         end
        
%         function vaf = getSSVAF(obj,p)
%             [~,x_m] = obj.runSSModel(p,0);
%             
%             measured    = obj.measuredU;
%             estimated   = x_m.u;
%             
%             vaf     = (1- (((measured - estimated)' * (measured - estimated)) / (measured' * measured)))*100;
%         end
        
        function vaf = getPilotVAF(obj,p)
            [~,x_m] = obj.runPilotModel(p);
            
            measured    = obj.measuredU;
            estimated   = x_m.u;
            
            vaf     = (1- (((measured - estimated)' * (measured - estimated)) / (measured' * measured)))*100;
        end
        
        function vaf = getTaskVAF(obj,p)
            [~,~,x_m] = obj.runTaskModel(p);
            
            measured    = obj.measuredY;
            estimated   = x_m.y;
            
            vaf     = (1- (((measured - estimated)' * (measured - estimated)) / (measured' * measured)))*100;
        end
        
        function obj = setPickedResult(obj,pR)
            obj.pickedResult = pR;
        end
        
        function output = getMeasurementBit(obj,x)
            fields = fieldnames(x);
            
            output = struct();
            for oo=1:length(fields)
                if strcmp(fields{oo},'t')
                    output.t    = obj.measurementTime;
                else
                    output.(fields{oo}) = x.(fields{oo})((end-length(obj.measurementTime)+1):end,:);
                end
            end
        end
        
        function output = getExperimentBit(obj,x)
            fields = fieldnames(x);
            
            if isempty(fields)
                error('The result object did not contain any fields.')
            end
            
            output = struct();
            for oo=1:length(fields)
                if strcmp(fields{oo},'t')
                    output.(fields{oo}) = obj.experimentTime;
                else
                    output.(fields{oo}) = x.(fields{oo})((end-length(obj.experimentTime)+1):end,:);
                end
            end
        end
        
        function remnantFilter = getRemnantFilter(obj)
            filterNum       = [0 0 0 obj.remnantOmegaN^3];
            filterDen       = [1 obj.remnantOmegaN*(2*obj.remnantDamping+1) (2*obj.remnantDamping+1)*obj.remnantOmegaN^2 obj.remnantOmegaN^3];
            remnantFilter   = tf(filterNum,filterDen);
        end
        
        function frf = getYnFRF(obj,w)
            frf = squeeze(freqresp(obj.getRemnantFilter(),w));
        end
        
        function remnantSignal = generateRemnant(obj,p)
            
            if ~isempty(obj.remnantSeed)
                scurr   = rng;
                rng(obj.remnantSeed);
            end
            
            Kn              = obj.calculateRemnantGain(obj.remnantRatioOrGain,p);
            
            if Kn == 0
                remnantSignal  = zeros(size(obj.simulationTime));
            else
                remnantSignal   = lsim(Kn*obj.getRemnantFilter(),randn(size(obj.simulationTime)),obj.simulationTime);
                if ~isempty(obj.remnantSeed)
                    rng(scurr);
                end
            end
        end
        
        function Kn = calculateRemnantGain(obj,nr,p)

            if nr == 0
                Kn = 0;
            elseif strcmpi(obj.remnantCalcMethod,'ratio')
                [FD, w, ~, ~, ~, ~, ~, ~, ~, ~, ~]     = fftx(obj.taskInputFd, obj.measurementTime);
                FD      = FD(2:end);
                w       = w(2:end);
                
                if obj.defineTransferFunctions == 0
                    frfYpe      = obj.getYpeFRF(p,w);
                    frfYnms     = obj.getYnmsFRF(p,w);
                    if ~isempty(obj.Yc)
                        frfYc       = obj.getYcFRF(p,w);                
                    else
                        frfYc       = obj.getYrollFRF(p,w);
                    end
                else
                    frfYpe  = obj.getFRF('Ype',p,w);
                    frfYnms = obj.getFRF('Ynms',p,w);
                    
                    if isfield(obj.defTf,'Ypphi')
                        frfYpphi = obj.getFRF('Ypphi',p,w);
                    else
                        frfYpphi = zeros(size(frfYpe));
                    end
                    
                    if isfield(obj.defTf,'Yc')
                        frfYc       = obj.getFRF('Yc',p,w);
                    else
                        frfYc       = obj.getFRF('Yroll',p,w);
                    end
                end
                
                frfYn       = obj.getYnFRF(w);

                S_fdfd      = 1 ./ length(obj.measurementTime) .* abs( FD ).^2;

                S_uu_fd     = S_fdfd    .* abs( -1*(frfYpphi  + frfYpe) .* frfYnms ./ (1 + (frfYpphi  + frfYpe) .* frfYnms .* frfYc)).^2;
                S_uu_n      = 1         .* abs( frfYn          ./ (1 + (frfYpphi  + frfYpe) .* frfYnms .* frfYc)).^2;
                S_nn        = 1         .* abs( frfYn ).^2;

                B           = trapz(w,S_uu_fd ./ pi);
                A           = trapz(w,S_uu_n  ./ pi);
                C           = trapz(w,S_nn ./ pi);

                r_n_max     = C / A;

                if nr > r_n_max
                    Kn  = sqrt( nr * B / (C - A * (r_n_max-0.0001))) * (nr / r_n_max) * 5; % Waar komt die 5 nou weer vandaan?
                else
                    Kn  = sqrt( nr * B / (C - A * nr));
                end
            elseif strcmpi(obj.remnantCalcMethod,'gain')
                Kn  = obj.remnantRatioOrGain;
            end
        end
    end
end