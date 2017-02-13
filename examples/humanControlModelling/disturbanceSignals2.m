function [fd,t] = disturbanceSignals2(which,model,varargin)

    p = inputParser;

    p.addParameter('nd',[]);
    p.addParameter('Ad',[]);
    p.addParameter('phase',[]);

    p.addParameter('T',[]);
    p.addParameter('Td',[]);
    
    p.addParameter('TA1',[]);
    p.addParameter('TA2',[]);
    p.addParameter('KA',[]);
    
    p.parse(varargin{:});
    z = p.Results;
    
    dt  = model.measurementTime(2) - model.measurementTime(1);
    
    if strcmpi(which,'multisine')
        
        if ~isempty(z.T)
            t   = 0:dt:z.T;
        else
            t   = model.measurementTime;
        end

        wm = (2*pi) / z.Td;

        if ~isnumeric(z.Ad)
            if strcmpi(z.Ad,'poolFilter')
                s       = tf('s');
                H_A     = (1 + z.TA1 * s)^2 / (1 + z.TA2 * s)^2;
                z.Ad    = z.KA * abs(squeeze(freqresp(H_A,z.nd*wm)));
            end
        end

        if ~isnumeric(z.phase)
            if strcmpi(z.phase,'rand')
                z.phase = 2*pi*rand(size(z.Ad));
            elseif strcmpi(z.phase,'crest')
                f = 2*pi*rand(size(z.Ad));
                z.phase = fminunc(@(x)max(abs(generateMultiSine(model.measurementTime,z.Ad,z.nd,wm,x)))/var(generateMultiSine(model.measurementTime,z.Ad,z.nd,wm,x)),f);
            end
        end

        fd = generateMultiSine(model.measurementTime,z.Ad,z.nd,wm,z.phase);
    end
end

function ms = generateMultiSine(t,Ad,nd,wm,phase)
    if any(diff([length(Ad) length(nd) length(phase)]) ~= 0)
        error('Ad, nd, and phase should have equal lengths.')
    end
    
    ms  = zeros(size(t));
    for oo=1:length(phase)
        ms  = ms + Ad(oo) * sin(nd(oo) * wm * t + phase(oo));
    end
end