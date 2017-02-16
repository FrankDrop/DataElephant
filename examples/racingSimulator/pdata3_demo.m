clc
close all
clear all

%%

a   = DataElephant(@p_racingSimulator,'verbose','no');

%%
close all
pobj    = a.get('f_x','raf_path','RAF/lap2.raf','f_filt',3);

figure; pobj.plot; pobj.abs.plot                    % calculate the absolute value of y data
figure; pobj.plot; pobj.circshift(300).plot
figure; pobj.plot; pobj.cumtrapz.plot
figure; pobj.plot; pobj.cumtrapz.plot
figure; pobj.plot; pobj.diff.plot
figure; pobj.plot; pobj.diff_dx.plot
figure; pobj.plot; pobj.diff(2).plot
figure; pobj.plot; pobj.diff_dx(2).plot

%% Unit conversions

figure; pobj.plot; pobj.deg.plot                    % Multiply by 180/pi
figure; pobj.plot; pobj.rad.plot                    % Divide by 180/pi

figure; pobj.plot; pobj.deg2rad.plot
figure; pobj.plot; pobj.rad2deg.plot
figure; pobj.plot; pobj.ms2kmh.plot
figure; pobj.plot; pobj.kmh2ms.plot
figure; pobj.plot; pobj.mph2ms.plot


%%

z.raf_path  = 'RAF/lap2.raf';
z.f_filt    = 3;
z.fit_on    = 1500:5000;
z.na        = 3;
z.nb        = 1;
z.nk        = 1;
z.w_m       = logspace(-2,1,5);

pobj        = a.get('H_m',z);

a.get('H_m',z).y
[a.get('H_m',z).y a.get('H_m',z).angle.y]
[a.get('H_m',z).y a.get('H_m',z).dangle.y]
[a.get('H_m',z).y a.get('H_m',z).conj.y]

%%

bode(a.get('H_m',z));