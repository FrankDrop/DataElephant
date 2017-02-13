clc
close all
clear all

%%

a   = DataElephant(@p_racingSimulator);

% return
%%

z.raf_path  = 'RAF/BlackwoodWR.raf';
z.f_filt    = 3;

figure
    plot(a.get('laptime',z,'raf_path',{'RAF/BlackwoodWR.raf','RAF/lap2.raf','RAF/lap3.raf'}.').ha('raf_path'))


a.get('f_x_best',z,'raf_path',{'RAF/lap2.raf','RAF/BlackwoodWR.raf','RAF/lap3.raf'}.','howBest',{'f_x','f_z'}.')
a.get('f_x_best',z,'raf_path',{'RAF/lap2.raf','RAF/BlackwoodWR.raf','RAF/lap3.raf','RAF/lap4.raf'}.','howBest',{'f_x','f_z'}.')
return

%%


%%

figure
    plot(a.get('f_x_raw',z),'r')
    plot(a.get('f_y_raw',z),'g')
    plot(a.get('f_z_raw',z),'b')

%%

figure
    plot(a.get('f_x_raw',z),'r')
    plot(a.get('f_x_raw',z,'raf_path','RAF/lap2.raf'),'b')
    
    
%%

figure
    plot(a.get('Di_cont;f_x_raw',z),'r')
    plot(a.get('Di_cont;f_x_raw',z,'raf_path','RAF/lap2.raf'),'b')
    
%%    

figure
    plot(a.get('Di_cont;f_x',z),'r')
    plot(a.get('Di_cont;f_x',z,'raf_path','RAF/lap2.raf'),'b')

%%

figure
    plot(a.get('f_y;f_x',z),'r')
    axis equal
%%

figure
    plot(a.get('x;y',z),'r')
    axis equal
    
    
%%

a.get('laptime',z).x
a.get('laptime',z).y
a.get('laptime',z,'raf_path','RAF/lap2.raf').y
%%

a.get('laptime',z,'raf_path',{'RAF/BlackwoodWR.raf','RAF/lap2.raf','RAF/lap3.raf'}.').x
a.get('laptime',z,'raf_path',{'RAF/BlackwoodWR.raf','RAF/lap2.raf','RAF/lap3.raf'}.').y
a.get('laptime',z,'raf_path',{'RAF/BlackwoodWR.raf','RAF/lap2.raf','RAF/lap3.raf'}.').mo('raf_path')


% TODO: Solve this error
% a.get('f_x_best',z,'raf_path','RAF/BlackwoodWR.raf','howBest','laptime')

%%
close all

% figure
%     plot(a.get('Di;f_x',z,'raf_path','RAF/BlackwoodWR.raf'),'r')
%     plot(a.get('Di;f_x',z,'raf_path','RAF/lap2.raf'),'g-.')
%     plot(a.get('Di;f_x',z,'raf_path','RAF/lap3.raf'),'b')
%     plot(a.get('Di;f_x_best',z,'raf_path',{'RAF/lap2.raf','RAF/BlackwoodWR.raf'}.','howBest','laptime'),'k--')

%%
close all

%%
% return
% %%
% clc
a.get('f_x_best',z,'raf_path',{'RAF/lap2.raf','RAF/BlackwoodWR.raf','RAF/lap3.raf'}.','howBest',{'f_x','f_z'}.')

