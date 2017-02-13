function ft = generateFt(model,gain,T)

    dt              = model.measurementTime(2) - model.measurementTime(1);
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
        ft  = [ft; segment{oo}]; %#ok<AGROW>
    end
    
    runin   = zeros(length(model.measurementTime)-length(ft),1);
    
    ft  = [runin; ft];
    ft = ft * gain * (5 * (pi/180));   
    ft = circshift(ft,-8.09/dt);
end
