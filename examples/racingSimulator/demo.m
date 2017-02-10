clc
close all
clear all

%%

a   = DataElephant(@p_racingSimulator);


%%

z.raf_path  = 'RAF/BlackwoodWR.raf';
z.f_filt    = 3;

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

a.verbose = 0;
a.get('laptime',z,'raf_path',{'RAF/BlackwoodWR.raf','RAF/lap2.raf','RAF/lap3.raf'}.').x
a.get('laptime',z,'raf_path',{'RAF/BlackwoodWR.raf','RAF/lap2.raf','RAF/lap3.raf'}.').y
a.get('laptime',z,'raf_path',{'RAF/BlackwoodWR.raf','RAF/lap2.raf','RAF/lap3.raf'}.').mo('raf_path')


%%

figure
    plot(a.get('f_x',z,'raf_path','RAF/BlackwoodWR.raf'),'r')
    plot(a.get('f_x',z,'raf_path','RAF/lap2.raf'),'g')
    plot(a.get('f_x',z,'raf_path','RAF/lap3.raf'),'b')
    plot(a.get('f_x_best',z,'raf_path',{'RAF/BlackwoodWR.raf','RAF/lap2.raf','RAF/lap3.raf'}.','howBest','laptime'),'k--')
    
