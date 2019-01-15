clc
close all
clear all

%%
% We start off by telling DataElephant we want to work with the process
% p_racingSimulator.

a   = DataElephant(@p_racingSimulator,'verbose','no',...
                    'unix_root','/home/fdrop/StorageElephants','unix_tempfolder','/home/fdrop/TemporaryElephants',...
                    'win_root','D:\StorageElephants','win_tempfolder','D:\TemporaryElephants');
a.info

%%
% In this example, we are going to work with some data that was generated
% by driving 9 laps around a track in a racing simulation.
% The raw datafiles are located in the subfolder RAF.
% In the first step, these datafiles are opened and converted into
% easy-to-work-with data structures and in the second step we filter the
% data to make the signals a bit smoother.

%%
% We can get results from any of the steps within the process
% p_racingSimulator by calling the get() function.
% Here, we get the result f_x_raw from the first step (s_readRAF)
% of this process.
% The data is returned in an object of class PData3. This is a very useful
% class, as it overloads a lot of commonly used functions, such as the plot
% function.

a.get('f_x_raw','raf_path','RAF/lap7.raf')


%%
% You can throw the PData3 object directly into a plot command, there is no
% need to manually take out the x and y data. (You are free to do that,
% however!)
% Here, we plot the raw acceleration signal in the x direction from two
% different laps on top of each other.

close all
figure
    plot(a.get('f_x_raw','raf_path','RAF/lap2.raf'),'r-','DisplayName','lap 2')
    plot(a.get('f_x_raw','raf_path','RAF/lap3.raf'),'b-','DisplayName','lap 3')
    legend show

%%
% Because the raw data is indeed a bit raw, we filter it in step
% s_filterRAF. This step needs the input f_filt, which is the fequency of a
% 2-nd order Butterworth filter that is applied to the data.

figure
    plot(a.get('f_x_raw','raf_path','RAF/lap2.raf'),'r-')
    plot(a.get('f_x','raf_path','RAF/lap2.raf','f_filt',4),'b-','DisplayName','f_x, filter corner freq. 4 Hz')
    plot(a.get('f_x','raf_path','RAF/lap2.raf','f_filt',1),'g-','DisplayName','f_x, filter corner freq. 1 Hz')
    legend show
    
% Note that if you change the value for 'f_filt' only step s_filterRAF is
% executed, and not the previous step s_readRAF. If you want to plot f_x
% for a value of f_filt that was calculated before, it will take the data
% from memory instead of running the function again.

%% 
% Typing all the inputs every time is annoying and takes up a lot of space,
% especially if you have many inputs, so let's use this shorter way of
% writing.

z.raf_path  = 'RAF/lap2.raf';
z.f_filt    = 3;

figure
    plot(a.get('f_x',z),'r-','DisplayName','lap 2')
    
    % Below we get the data from lap3, because inputs in the get() call override the
    % inputs set in the struct (z).
    plot(a.get('f_x',z,'raf_path','RAF/lap3.raf'),'b-','DisplayName','lap 3'); 
    legend show
%% 
% What about the x-axis? Look at this line in the s_filterRAF file:
% step.output     = {'t_cont;f_x','t_cont;f_y','t_cont;f_z',...
%                        't_cont;omega_x','t_cont;omega_y','t_cont;omega_z',...
%                        't_cont;x','t_cont;y','t_cont;z',...
%                        't_cont;psi','t_cont;phi','t_cont;theta'};
% Here, the outputs are defined. They are defined as pairs of x and y data.
% If you want to plot y (the y position of the car in the world),
% the horizontal axis is automatically equal to 
% the signal t_cont.

figure
    subplot(2,1,1)
    plot(a.get('t;y','raf_path','RAF/lap4.raf','f_filt',3),'b')
    plot(a.get('y','raf_path','RAF/lap4.raf','f_filt',3),'r--')
     % Both notations are equivalent, because of the definition in the s_filterRAF file.
    subplot(2,1,2)
    plot(a.get('Di;y','raf_path','RAF/lap4.raf','f_filt',3),'g-') 
    % choosing another vector for the x data is possible to (here it is the
    % distance traveled), as long as this vector is the right size

%%
% ... but you can also redefine it to be another signal. Just make sure
% they have the same size, or otherwise matlab will complain (cannot do
% anything about that...). This now shows the path of the car (x and y
% coordinates) as it went around the track:
figure
    plot(a.get('x;y','raf_path','RAF/lap2.raf','f_filt',4),'k')
    axis equal

%%
% Now, let's say we want to calculate something trivial (such as the 
% laptime) based on data that is generated in the beginning of the process.
% We do not want to add a step all the way at the end of the sequence of 
% steps, because then we would have to walk through ALL those steps, which
% takes a lot of time. Instead, we can add a 'branch':
%   p.steps     = {@s_readRAF,@s_filterRAF,@s_simClassicMCA};
%   p.branches  = {{@s_filterRAF,@s_calculateStatistics,@d_bestLap,@s_bestLap}};
% This branch starts after s_filterRAF.

a.get('laptime',z,'raf_path','RAF/lap1.raf')
a.get('laptime',z,'raf_path','RAF/lap2.raf')
a.get('laptime',z,'raf_path','RAF/lap3.raf')
a.get('laptime',z,'raf_path','RAF/lap4.raf')
a.get('laptime',z,'raf_path','RAF/lap5.raf')
a.get('laptime',z,'raf_path','RAF/lap6.raf')
a.get('laptime',z,'raf_path','RAF/lap7.raf')
a.get('laptime',z,'raf_path','RAF/lap8.raf')
a.get('laptime',z,'raf_path','RAF/lap9.raf')


%%
% Suppose now, we want to calculate the laptime as a function of the lap
% number. We can do this by throwing a cell column vector into the get
% statement. You will now obtain a list of laptimes

a.verbose = 0;
allLaps =  {'RAF/lap2.raf';'RAF/lap3.raf';'RAF/lap4.raf';...
            'RAF/lap5.raf';'RAF/lap6.raf';'RAF/lap7.raf';...
            'RAF/lap8.raf';'RAF/lap9.raf'};
a.get('laptime',z,'raf_path',allLaps,'f_filt',2).y

%%
% You can also plot these results as a function of lap number
figure
    plot(a.get('laptime',z,'raf_path',allLaps,'f_filt',2).ha('raf_path'),'b')

    % The function .ha('') is required only if there are multiple functions
    % in the results. So the code below is valid as well:

    plot(a.get('laptime',z,'raf_path',allLaps,'f_filt',2),'r--')