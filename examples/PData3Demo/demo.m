clc
close all
clear all

%%

a   = DataElephant(@p_pdata3demo,'verbose','no',...
                    'unix_root','/home/fdrop/StorageElephants','unix_tempfolder','/home/fdrop/TemporaryElephants',...
                    'win_root','D:\StorageElephants','win_tempfolder','D:\TemporaryElephants');

% This demo is simply a demonstration of all the data manipulations the
% PData3 object supports. This demo is far from exhaustive, but a
% useful introduction into PData3.

%%
close all
pobj    = a.get('sine','dt',0.01,'T',20,'f',0.1);

figure; pobj.plot('r'); pobj.abs.plot('b'); legend show                    % calculate the absolute value of y data
figure; pobj.plot('r'); pobj.circshift(15).plot('b'); pobj.circshift(-30).plot('g'); legend show
figure; pobj.plot('r'); pobj.cumtrapz.plot('b'); legend show
figure; pobj.plot('r'); pobj.diff.plot('b'); legend show
figure; pobj.plot('r'); pobj.diff_dx.plot('b'); legend show
figure; pobj.plot('r'); pobj.diff(2).plot('b'); legend show
figure; pobj.plot('r'); pobj.diff_dx(2).plot('b'); legend show

%% Unit conversions
close all
figure; pobj.plot; pobj.deg.plot; legend show                    % Multiply by 180/pi
figure; pobj.plot; pobj.rad.plot; legend show                    % Divide by 180/pi

figure; pobj.plot; pobj.deg2rad.plot; legend show
figure; pobj.plot; pobj.rad2deg.plot; legend show
figure; pobj.plot; pobj.ms2kmh.plot; legend show
figure; pobj.plot; pobj.kmh2ms.plot; legend show
figure; pobj.plot; pobj.mph2ms.plot; legend show


%%
close all
pobj    = a.get('imaginary_sine','dt',0.01,'T',20,'f',0.1);

pobj.y

figure; pobj.plot('r'); pobj.real.plot('b--'); pobj.imag.plot('g'); legend show
figure; pobj.conj.plot('r'); pobj.conj.real.plot('b--'); pobj.conj.imag.plot('g'); legend show

figure; pobj.angle.plot('r'); pobj.angle.unwrap.plot('b'); legend show
figure; pobj.dangle.plot('r'); pobj.dangle.dunwrap.plot('b'); legend show


