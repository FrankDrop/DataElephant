clc
close all
clear all

%%

a   = DataElephant(@p_pdata3demo,'verbose','no');

%%
close all
pobj    = a.get('sine','dt',0.01,'T',20,'f',0.1);

figure; pobj.plot; pobj.abs.plot                    % calculate the absolute value of y data
figure; pobj.plot; pobj.circshift(15).plot; pobj.circshift(-30).plot
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
close all
pobj    = a.get('imaginary_sine','dt',0.01,'T',20,'f',0.1);

figure; pobj.plot; pobj.real.plot; pobj.imag.plot
figure; pobj.conj.plot; pobj.conj.real.plot; pobj.conj.imag.plot

figure; pobj.angle.plot; pobj.angle.unwrap.plot;
figure; pobj.dangle.plot; pobj.dangle.dunwrap.plot;


