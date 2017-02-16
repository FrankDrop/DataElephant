clc
close all
clear all

%%

a   = DataElephant(@p_curve);

%%

% These parameters can be (of course) hardcoded into
% s_preceptionModelParameters, but this allows you to investigate how a
% particular result depends on the input values easily.

z.g             = 9.81;
z.tau_oto       = 0.03;
z.tau_HSCC1     = 15;
z.tau_HSCC2     = 80;
z.tau_alb       = 0.02;

z.KB_v_vis      = 1;
z.KB_omega_vis  = 1;
z.KB_g_vis      = 1;

z.K_a           = -4;
z.K_f           = 4;
z.K_fomega      = 8;
z.K_omega       = 8;
z.K_omegaf      = 1;
z.K_1           = (z.K_omega+1)/z.K_omega;
z.K_xdot_V      = 0.75;
z.K_g_V         = 10;
z.K_omega_V     = 10;
z.tau_x         = 16.67;
z.tau_y         = 16.67;
z.tau_z         = 1;
z.K_iv          = 0;

z.mnv           = 'CURVE1';
z.dt            = 0.01;

z.KB_v_vis      = 0;
z.KB_omega_vis  = 0;
z.KB_g_vis      = 0;

z.modelname     = 'wabs_perceptionmodel_VPT_Limbic_v3_adj';

%%
clc
figure
    bode(a.get('HSCC_hat',z))
    bode(a.get('HSCC_hat',z,'tau_HSCC1',10),'b-')
    bode(a.get('HSCC_hat',z),'r--')
    bode(a.get('HVISxdot_hat',z))
    bode(a.get('Hbr',z))
    
%%

figure
    plot(a.get('wz',z,'mnv','CURVE1'),'r')
    plot(a.get('wz',z,'mnv','CURVE2'),'b')
    
%%

figure
    plot(a.get('wz',z,'mnv','CURVE1').diff_dx.deg,'r')
    plot(a.get('wz',z,'mnv','CURVE2').diff_dx.deg,'b')
    
%%

figure
    plot(a.get('omega_vis(:,2)',z,'mnv','CURVE1'),'r')
    plot(a.get('omega_vis(:,2)',z,'mnv','CURVE1'),'g--')
    plot(a.get('omega_vis(:,3)',z,'mnv','CURVE1'),'b-.')
    
%%

figure
    plot(a.get('O_path',z),'r')
    plot(a.get('O_path',z,'K_a',-20),'g')
    plot(a.get('O_path',z,'K_a',-0.8),'b')
    plot(a.get('O_head',z),'m')
%%
figure
    plot(a.get('O_path',z),'r')
    plot(a.get('O_path',z,'K_f',20),'g')
    plot(a.get('O_path',z,'K_f',0.8),'b')
    
%%
figure
    plot(a.get('HP',z,'K_a',num2cell(linspace(-20,-0.8,10)).').xa('K_a'),'r')
    plot(a.get('H',z,'K_a',num2cell(linspace(-20,-0.8,10)).').xa('K_a'),'b')
    plot(a.get('P',z,'K_a',num2cell(linspace(-20,-0.8,10)).').xa('K_a'),'g')
    
%%

figure
    plot(a.get('HP',z,'K_a',num2cell(linspace(-20,-0.8,4)).','K_f',num2cell(linspace(0.8,20,4)).').xa('K_a'));
    plot(a.get('H',z,'K_a',num2cell(linspace(-20,-0.8,4)).','K_f',num2cell(linspace(0.8,20,4)).').xa('K_a'),'b');
    plot(a.get('P',z,'K_a',num2cell(linspace(-20,-0.8,4)).','K_f',num2cell(linspace(0.8,20,4)).').xa('K_a'),'g');
    

