function step = s_readRAF()

    step.name       = mfilename;
    step.type       = 'step';
    step.decide     = {};
    step.baseon     = {};
    step.input      = {'raf_path'};
    step.optional   = {};
    step.output     = {'t_cont;t','t_cont','t_cont;Di','t_cont;Di_cont',...
                       't_cont;f_x_raw','t_cont;f_y_raw','t_cont;f_z_raw',...
                       't_cont;omega_x_raw','t_cont;omega_y_raw','t_cont;omega_z_raw',...
                       't_cont;x_raw','t_cont;y_raw','t_cont;z_raw',...
                       't_cont;psi_raw','t_cont;phi_raw','t_cont;theta_raw',...
                       't_cont;steer','t_cont;gear','t_cont;throttle','t_cont;clutch','t_cont;brake'};
    step.handle     = @myfunc;
    step.version    = 1;
    step.saveme     = 1;
    step.memorizeme = 1;
    
    function [r_n] = myfunc(z,r,v,id)
        
        if v
            fprintf('This is a demonstration of the DataElephant.funcverbose option. If this is set to true, this line will be displayed.\n')
        end
        
        if v
            fprintf('The input parameter ''id'' contains a unique identifier, which is valid only for this specific step file and combination of inputs. For this call it is %s.',id);
        end
        
        % [r_n] = myfunc(z,r,~,~)
        % Inputs:
        % z     = input parameters for this function
        % r     = output up till now
        % v     = true if the user wants verbose output of the step
        % functions
        % id    = unique identifier of the current step and input
        % parameters
        % r_n   = any new results produced by this function
        
        
        % Some intialization of variables        
        idx             = 0;
        
        r_n.t           = [];
        r_n.Di          = [];
        
        r_n.t_cont      = [];
        r_n.Di_cont     = [];
        
        r_n.throttle    = [];
        r_n.brake       = [];
        r_n.steer       = [];
        r_n.clutch      = [];
        r_n.gear        = [];
        
        r_n.f_x_raw     = [];
        r_n.f_y_raw     = [];
        r_n.f_z_raw     = [];

        RX          = [];
        RY          = [];
        RZ          = [];

        FX          = [];
        FY          = [];
        FZ          = [];

        r_n.psi_raw     = [];
        r_n.theta_raw   = [];
        r_n.phi_raw     = [];
        
        r_n.x_raw       = [];
        r_n.y_raw       = [];
        r_n.z_raw       = [];
        
        t_prev          = 0;
        Di_prev         = 0;
        
        % The function supports reading in multiple RAF files, to create
        % one long dataset. Paths to the files are separated by a ;
        names           = regexp(z.raf_path,';','split');
        
        % For each of the provided names
        for ii=1:length(names)
        
            % Open the file, read it into memory, and close it.
            raf_file        = fopen(names{ii});
            raf_contents    = uint8(fread(raf_file).');
            fclose(raf_file);

            % Each RAF file starts with some header information.
            
            %         6     char    0       LFSRAF              : do not read file if no match
            LFSRAF  = char(raf_contents(1:6));
            if ~strcmpi(LFSRAF,'LFSRAF')
                error('This is not a RAF file, the header is %s.',LFSRAF);
            end
            
            %         1     byte    8       RAF version (2)     : do not read if increased
            RAF_version  = raf_contents(9);
            if (RAF_version ~= 2)
                error('The RAF file version is %i, but it should be 2.',RAF_version);
            end
            
            %         1     byte    9       update interval     : ms (normally 10 / hlvc 100)
            RAF_rate    = double(raf_contents(10));
            if ~any(RAF_rate == [10 100])
                error('The RAF update rate is %i ms, but it should be 10 or 100 ms.',RAF_rate);
            end

            %         1     word    12      header size         : data blocks start    (A)
            RAF_A       = typecast(raf_contents(13:14),'uint16');
            %         1     word    14      block size          : size of a data block (B)
            RAF_B       = double(typecast(raf_contents(15:16),'uint16'));
            %         1     word    16      wheel block size    : inside data block    (C)
            RAF_C       = typecast(raf_contents(17:18),'uint16');
            %         1     word    18      wheel block offset  : within data block    (D)
            RAF_D       = typecast(raf_contents(19:20),'uint16');
            %         1     int     20      number of blocks    : total number of data blocks
            RAF_N       = double(typecast(raf_contents(21:24),'uint32'));
            %         4     char    24      short track name    : e.g. BL2R
            RAF_track   = char(raf_contents(25:28));
            %         1     float   28      track ruler length  : total index distance
            res.Di_max  = double(typecast(raf_contents(29:32),'single'));
            
            
            
            % After the header, the actual car data stream starts.
            
            
            r_n.t               = [r_n.t; zeros(RAF_N,1)];          
            r_n.t_cont          = [r_n.t_cont; zeros(RAF_N,1)];     
            
            r_n.Di              = [r_n.Di; zeros(RAF_N,1)];         
            r_n.Di_cont         = [r_n.Di_cont; zeros(RAF_N,1)];    
            
            r_n.throttle        = [r_n.throttle; zeros(RAF_N,1)];   
            r_n.brake           = [r_n.brake; zeros(RAF_N,1)];      
            r_n.steer           = [r_n.steer; zeros(RAF_N,1)];      
            r_n.clutch          = [r_n.clutch; zeros(RAF_N,1)];     
            r_n.gear            = [r_n.gear; zeros(RAF_N,1)];       
            
            r_n.f_x_raw         = [r_n.f_x_raw; zeros(RAF_N,1)];    
            r_n.f_y_raw         = [r_n.f_y_raw; zeros(RAF_N,1)];    
            r_n.f_z_raw         = [r_n.f_z_raw; zeros(RAF_N,1)];    

            RX                  = [RX; zeros(RAF_N,1)];         %#ok<AGROW>
            RY                  = [RY; zeros(RAF_N,1)];         %#ok<AGROW>
            RZ                  = [RZ; zeros(RAF_N,1)];         %#ok<AGROW>

            FX                  = [FX; zeros(RAF_N,1)];         %#ok<AGROW>
            FY                  = [FY; zeros(RAF_N,1)];         %#ok<AGROW>
            FZ                  = [FZ; zeros(RAF_N,1)];         %#ok<AGROW>

            r_n.psi_raw         = [r_n.psi_raw; zeros(RAF_N,1)];        
            r_n.theta_raw       = [r_n.theta_raw; zeros(RAF_N,1)];      
            r_n.phi_raw         = [r_n.phi_raw; zeros(RAF_N,1)];        
            
            r_n.x_raw           = [r_n.x_raw; zeros(RAF_N,1)];        
            r_n.y_raw           = [r_n.y_raw; zeros(RAF_N,1)];      
            r_n.z_raw           = [r_n.z_raw; zeros(RAF_N,1)];      


            for oo=1:RAF_N

                sidx        = double(1024 + (oo-1)*RAF_B);

                r_n.t(idx+oo)       = (oo-1)*RAF_rate/1000;
                r_n.t_cont(idx+oo)  = (oo-1)*RAF_rate/1000 + t_prev;

            %         DATA BLOCKS : 192 bytes (B) every 100th of a second
            % 
            %         1     float   0       throttle            : 0 to 1
                r_n.throttle(idx+oo)    = double(typecast(raf_contents(sidx+(1:4)),'single'));
            %         1     float   4       brake               : 0 to 1
                r_n.brake(idx+oo)       = double(typecast(raf_contents(sidx+(5:8)),'single'));
            %         1     float   8       input steer         : radians
                r_n.steer(idx+oo)       = double(typecast(raf_contents(sidx+(9:12)),'single'));
            %         1     float   12      clutch              : 0 to 1
                r_n.clutch(idx+oo)      = double(typecast(raf_contents(sidx+(13:16)),'single'));
            %         1     float   16      handbrake           : 0 to 1
            %         1     byte    20      gear                : 0=R, 1=N, 2=first gear
                r_n.gear(idx+oo)        = double(typecast(raf_contents(sidx+21),'int8'))-1;
            %         1     char    21      lateral G * 20      : -120 to 120 = -6 to 6 G
                r_n.f_y_raw(idx+oo)     = double(typecast(raf_contents(sidx+22),'int8'))/20*9.81;
            %         1     char    22      forward G * 20      : -120 to 120 = -6 to 6 G
                r_n.f_x_raw(idx+oo)     = -double(typecast(raf_contents(sidx+23),'int8'))/20*9.81;
            %         1     char    23      upwards G * 20      : -120 to 120 = -6 to 6 G
                r_n.f_z_raw(idx+oo)     = -double(typecast(raf_contents(sidx+24),'int8'))/20*9.81;


            %         1     float   24      speed               : m/s
            %         1     float   28      car distance        : m - travelled by car
            %         1     int     32      position X          : map X    (1m = 65536)
                r_n.x_raw(idx+oo)          = double(typecast(raf_contents(sidx+(33:36)),'int32'))/65536;
            %         1     int     36      position Y          : map Y    (1m = 65536)
                r_n.y_raw(idx+oo)          = double(typecast(raf_contents(sidx+(37:40)),'int32'))/65536;
            %         1     int     40      position Z          : altitude (1m = 65536)
                r_n.z_raw(idx+oo)          = double(typecast(raf_contents(sidx+(41:44)),'int32'))/65536;
            %         1     float   44      engine speed        : radians/s
            %         1     float   48      index distance      : m - track ruler measurement
                r_n.Di(idx+oo)          = double(typecast(raf_contents(sidx+(49:52)),'single'));
                r_n.Di_cont(idx+oo)     = double(typecast(raf_contents(sidx+(49:52)),'single')) + Di_prev;                
                
            %         1     short   52      RX                  : x of right-vector
                RX(idx+oo) = double(typecast(raf_contents(sidx+(53:54)),'int16')) / 32767.0;
            %         1     short   54      RY                  : y of right-vector
                RY(idx+oo) = double(typecast(raf_contents(sidx+(55:56)),'int16')) / 32767.0;
            %         1     short   56      RZ                  : z of right-vector
                RZ(idx+oo) = double(typecast(raf_contents(sidx+(57:58)),'int16')) / 32767.0;
            %         1     short   58      FX                  : x of forward-vector
                FX(idx+oo) = double(typecast(raf_contents(sidx+(59:60)),'int16')) / 32767.0;
            %         1     short   60      FY                  : y of forward-vector
                FY(idx+oo) = double(typecast(raf_contents(sidx+(61:62)),'int16')) / 32767.0;
            %         1     short   62      FZ                  : z of forward-vector
                FZ(idx+oo) = double(typecast(raf_contents(sidx+(63:64)),'int16')) / 32767.0;
            %         4     wheel   64 (D)  DYNAMIC WHEEL INFO  : (see below)
            %         To work out heading from the forward-vector
            %         -------------------------------------------
            %         float b = FX / 32767.0f;        // convert FX to a float from -1 to 1
            %         float e = FY / 32767.0f;        // convert FY to a float from -1 to 1
            %         float heading = atan2(-b, e);   // heading (anti-clockwise from above)    
                r_n.psi_raw(idx+oo)     = atan2(-FX(oo),FY(oo));
                r_n.theta_raw(idx+oo)   = atan2(FZ(oo),sqrt(FX(oo).^2 + FY(oo).^2)); % not sure if this is correct.
                r_n.phi_raw(idx+oo)     = atan2(RZ(oo),sqrt(RX(oo).^2 + RY(oo).^2)); % not sure if this is correct.

            end
            
            t_prev  = r_n.t(end) + RAF_rate/1000;
            Di_prev = r_n.Di(end);
            idx     = idx + oo;
        end

        r_n.omega_x_raw = [0; diff(unwrap(r_n.phi_raw))] / (RAF_rate/1000); % angular velocity around x
        r_n.omega_y_raw = [0; diff(unwrap(r_n.theta_raw))] / (RAF_rate/1000); % angular velocity around y
        r_n.omega_z_raw = [0; diff(unwrap(r_n.psi_raw))] / (RAF_rate/1000); % angular velocity around z        
    end
end