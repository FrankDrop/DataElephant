clc
close all
clear all

%%
% We start off by telling DataElephant we want to work with the process
% p_racingSimulator.

a   = DataElephant(@p_racingSimulator,'verbose','no',...
                    'win_root','D:\StorageElephants','win_tempfolder','D:\TemporaryElephants');

%%
% We can get results from any of the steps within the process
% p_racingSimulator by calling the get() function.
% Here, we get the result f_x_raw from the first step (s_readRAF)
% of this process.
% clc
a.get('f_x_raw','raf_path','RAF/lap7.raf')
% return

figure
    plot(a.get('f_x_raw','raf_path','RAF/lap2.raf'),'r-','DisplayName','lap 2')
    plot(a.get('f_x_raw','raf_path','RAF/lap3.raf'),'b-','DisplayName','lap 3')
    legend show
% return
%%
% Because the raw data is indeed a bit raw, we filter it in step
% s_filterRAF. This step needs the input f_filt, which is the fequency of a
% 2-nd order Butterworth filter that is applied to the data.

figure
    plot(a.get('f_x_raw','raf_path','RAF/lap2.raf'),'r-')
    plot(a.get('f_x','raf_path','RAF/lap2.raf','f_filt',3),'b-')
    legend show
% return
%% 
% Typing all the inputs every time is annoying and takes up a lot of space,
% especially if you have many inputs, so let's use this shorter way of
% writing.

z.raf_path  = 'RAF/lap2.raf';
z.f_filt    = 3;

figure
    plot(a.get('f_x',z),'r-','DisplayName','lap 2')
    
    % Below we get lap3, because inputs in the get() call override the
    % inputs set in the struct (z).
    plot(a.get('f_x',z,'raf_path','RAF/lap3.raf'),'b-','DisplayName','lap 3'); 
    legend show
%% 
% What about the x-axis? Remember this line in the s_filterRAF file:
% step.output     = {'t_cont;f_x','t_cont;f_y','t_cont;f_z',...
%                        't_cont;omega_x','t_cont;omega_y','t_cont;omega_z',...
%                        't_cont;x','t_cont;y','t_cont;z',...
%                        't_cont;psi','t_cont;phi','t_cont;theta'};
% Here, the outputs are defined. They are defined as pairs of x and y data.
% If you want to plot y (the y position of the car in the world),
% the horizontal axis is automatically equal to 
% the signal t_cont.
figure
    plot(a.get('y','raf_path','RAF/lap5.raf','f_filt',3),'k')

%%
% ... but you can also redefine it to be another signal. Just make sure
% they have the same size, or otherwise matlab will complain (cannot do
% anything about that...). This now shows the path of the car (x and y
% coordinates) as it went around the track:
figure
    plot(a.get('x;y','raf_path','RAF/lap2.raf','f_filt',3),'k')
    axis equal
    
%%
% Let's send this data through a classic washout filter.
% This happens in the step s_simClassicMCA, which takes a lot of input
% parameters:

z.modelname     = 'kuka_classic_mda_daan_carthesian';
z.g             = 9.81;
z.cart0         = [2.7541; 0; 3.8237];
z.k_x           = 0.6;
z.k_y           = 0.2;
z.k_z           = 0.2;
z.k_P           = 0.5;
z.k_Q           = 0.5;
z.k_R           = 0.5;
z.SatAngVel     = [.5 .5 .5];
z.SatSpecForce  = [3 3 3];
% translational high-pass parameters, x
z.x_csi         = 1;
z.x_wn          = 0.2;
z.x_wn2         = 12;
% translational high-pass parameters, y
z.y_csi         = 1;
z.y_wn          = 0.8;
z.y_wn2         = 0.15;
% translational high-pass parameters, z
z.z_csi         = 1;
z.z_wn          = 0.5;
z.z_wn2         = 14;
% rotational high-pass filter parameters
z.roll_csi      = 1;
z.roll_wn       = 1;
z.pitch_csi     = 1;
z.pitch_wn      = 1;
z.yaw_csi       = 1;
z.yaw_wn        = 1;
z.TC_ratelimit  = 5*pi/180;
z.Kinput_linacc = eye(3);
z.Kinput_rotvel = eye(3);

%%
% The specific force provided by the simulator is stored in variables with
% subscript _s:

figure
    subplot(3,1,1)
    plot(a.get('f_x',z),'r')
    plot(a.get('f_x_s',z),'b')
    % What happens if we set the tilt coordination rate limit to Inf?
    plot(a.get('f_x_s',z,'TC_ratelimit',Inf),'g')
    legend show
    
    subplot(3,1,2)
    plot(a.get('f_y',z),'r')
    plot(a.get('f_y_s',z),'b')
    plot(a.get('f_y_s',z,'TC_ratelimit',Inf),'g')
    legend show
    
    subplot(3,1,3)
    plot(a.get('f_z',z),'r')
    plot(a.get('f_z_s',z),'b')
    plot(a.get('f_z_s',z,'TC_ratelimit',Inf),'g')
    legend show

%%
% It is a bit difficult to compare the output of the simulator with the
% vehicle accelerations, because these are scaled first. It would make more
% sense to look at the scaled vehicle accelerations. We can go into the
% simulink model and create an output that logs the scaled vehicle
% accelerations, but we can also multiply the input (e.g. f_x) with the
% gain:

figure
    subplot(3,1,1)
    plot(a.get('f_x',z).*z.k_x,'r')
    plot(a.get('f_x_s',z),'b')
    legend show
    
    subplot(3,1,2)
    plot(a.get('f_y',z).*z.k_y,'r')
    plot(a.get('f_y_s',z),'b')
    legend show

% The manipulation that is necessary for the z channel is a bit more
% complicated, but that is no problem for the PData3 object:
    
    subplot(3,1,3)
    plot((a.get('f_z',z)  +z.g).*z.k_z,'r')
    plot( a.get('f_z_s',z)+z.g,'b')
    legend show
%%
% Actually, you can pretty much do all sorts of manipulations on pdata...

figure
    subplot(2,2,1)
        % divide two signals by eachother
        plot(a.get('f_z_s',z) ./ a.get('f_z',z),'r')
        legend show
    subplot(2,2,2)
        % calculate the total velocity of the car, by first differentiating
        % the x and y position and then applying Pythagoras
        plot(sqrt(a.get('x',z).diff_dx.^2 + a.get('y',z).diff_dx.^2),'r')
        plot(a.get('V',z),'b--')
        xlim([1 60])
        legend show
    subplot(2,2,3)
        plot(a.get('omega_z',z).deg,'r')
        legend show
    subplot(2,2,4)
        plot(a.get('V',z).ms2kmh,'b-')
        legend show
%%
% PData3 can draw bode plots if you hand it a transfer function object (or
% something similar)
figure
    bode(a.get('Hpx',z),'b')
    bode(a.get('Hpx',z),'r--','w',logspace(-2,2,50).')
    
%%
% Now, let's say we want to calculate something trivial (such as the 
% laptime) based on data that is generated in the beginning of the process.
% We do not want to add a step all the way at the end of the sequence of 
% steps, because then we would have to walk through ALL those steps, which
% takes a lot of time. Instead, we can add a 'branch':
%   p.steps     = {@s_readRAF,@s_filterRAF,@s_simClassicMCA};
%   p.branches  = {{@s_filterRAF,@s_calculateStatistics,@d_bestLap,@s_bestLap}};
% This branch starts after s_filterRAF.

a.get('laptime',z,'raf_path','RAF/lap2.raf')
a.get('laptime',z,'raf_path','RAF/lap3.raf')
a.get('laptime',z,'raf_path','RAF/lap4.raf')
a.get('laptime',z,'raf_path','RAF/lap5.raf')
a.get('laptime',z,'raf_path','RAF/lap6.raf')
a.get('laptime',z,'raf_path','RAF/lap7.raf')
a.get('laptime',z,'raf_path','RAF/lap8.raf')
a.get('laptime',z,'raf_path','RAF/lap9.raf')
a.get('laptime',z,'raf_path','RAF/lap10.raf')

%%
a.verbose = 0;
allLaps =  {'RAF/lap2.raf';'RAF/lap3.raf';'RAF/lap4.raf';...
            'RAF/lap5.raf';'RAF/lap6.raf';'RAF/lap7.raf';...
            'RAF/lap8.raf';'RAF/lap9.raf';'RAF/lap10.raf'};
a.get('laptime',z,'raf_path',allLaps,'f_filt',num2cell([3 4 5]).').y

%%
% Obviously, we can also plot this.

figure
    plot(a.get('laptime',z,'raf_path',allLaps),'r')
    
%%
% Making a decision

figure
    for ii=1:length(allLaps)
        plot(a.get('Di_cont;f_y',z,'raf_path',allLaps{ii}),'r')
    end
    plot(a.get('Di_cont;f_y_best',z,'raf_path',allLaps),'b--')
    
%%

figure
    plot(-a.get('steer_best',z,'raf_path',allLaps).deg,'r')
    plot(a.get('f_y_best',z,'raf_path',allLaps),'b')
    
%%
clc
figure
    plot(a.get('f_y_best',z,'raf_path',allLaps),'k','LineWidth',3)
    plot(a.get('f_y_fit',z,'raf_path',allLaps,'na',1,'nb',1,'nk',1,'fit_on',1500:5500),'r')
    plot(a.get('f_y_fit',z,'raf_path',allLaps,'na',2,'nb',1,'nk',1,'fit_on',1500:5500),'g-.')
    plot(a.get('f_y_fit',z,'raf_path',allLaps,'na',3,'nb',2,'nk',1,'fit_on',1500:5500),'b--')
    