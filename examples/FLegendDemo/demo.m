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
clc
pobj    = a.get('sine','dt',0.01,'T',20,'f',0.1);

figure;
    subplot(1,2,1)
    plot(a.get('sine','dt',0.01,'T',20,'f',0.1),'r','DisplayName','Data 1');
    plot(a.get('sine','dt',1,'T',20,'f',0.1),'b','DisplayName','Data 2');
    xlabel('t, s')
    ylabel('Sines')
    subplot(1,2,2)
    plot(a.get('sine','dt',0.12,'T',20,'f',0.1),'g','DisplayName','Data 3');
    plot(a.get('sine','dt',2,'T',20,'f',0.1),'k','DisplayName','Data 4');
    xlabel('t, s')
    ylabel('More sines')
    title('A beautiful sine')
    FLegend(gcf,'Show','yes','Paper','yes','ImageHeight',5,'ImageWidth',10,'Padding',0,'Location','North','LegendPadding',0); %[0.5 0.5 0.5 0.5]*0)
%     return
figure;
    subplot(2,1,1)
    plot(a.get('sine','dt',0.01,'T',20,'f',0.1),'r','DisplayName','Data 1');
    plot(a.get('sine','dt',1,'T',20,'f',0.1),'b','DisplayName','Data 2');
    xlabel('t, s')
    ylabel('Sines')
    subplot(2,1,2)
    plot(a.get('sine','dt',0.12,'T',20,'f',0.1),'g','DisplayName','Data 3');
    plot(a.get('sine','dt',2,'T',20,'f',0.1),'k','DisplayName','Data 4');
    xlabel('t, s')
    ylabel('More sines')
%     title('A beautiful sine')
    FLegend(gcf,'Show','yes','Paper','yes','ImageHeight',10,'ImageWidth',5,'Padding',0)
%%
close all
clc

figure;
    subplot(2,2,1)
    plot(a.get('sine','dt',0.01,'T',20,'f',0.1),'r','DisplayName','Data 1');
    plot(a.get('sine','dt',1,'T',20,'f',0.1),'b','DisplayName','Data 2');
    xlabel('t, s')
    ylabel('Sines')
    subplot(2,2,2)
    plot(a.get('sine','dt',0.12,'T',20,'f',0.1),'g','DisplayName','Data 3');
    plot(a.get('sine','dt',2,'T',20,'f',0.1),'k','DisplayName','Data 4');
    xlabel('t, s')
    ylabel('More sines')
    title('A beautiful sine')
    subplot(2,2,3)
    plot(a.get('sine','dt',0.01,'T',20,'f',0.1),'b','DisplayName','Data 1');
    plot(a.get('sine','dt',1,'T',20,'f',0.1),'y','DisplayName','Data 2');
    xlabel('t, s')
    ylabel('Sines')
    subplot(2,2,4)
    plot(a.get('sine','dt',0.12,'T',20,'f',0.1),'m','DisplayName','Data 3');
    plot(a.get('sine','dt',2,'T',20,'f',0.1),'c','DisplayName','Data 4');
    xlabel('t, s')
    ylabel('More sines')
    title('A more beautiful sine')
    FLegend(gcf,'Show','yes','Paper','yes','ImageHeight',10,'ImageWidth',10,'Padding',0.15)