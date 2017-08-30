clc
close all
clear all

%%
a   = DataElephant(@p_twostagemethod,'win_root','D:\StorageElephants','win_tempfolder','D:\TemporaryElephants');

%%

ft.ramp                 = 'sdt ramp';
ft.parabola             = 'sdt parabola';

Yp.SI                   = 'ffm 1/s laurense';
Yp.DI                   = 'ffm 1/s2 laurense';

%%
NN.SI                   = getNNcell(1:7,0:7,0:7,1:15,1:15);
NN.DI                   = getNNcell(1:7,0:7,0:7,1:15,1:15);

%%
z.dt                    = 0.01;
z.fd                    = 'drop, 2011b, normalized';
z.ftn                   = 'sdt noise 1';
z.Kt                    = 20;
z.Ktn                   = 0;
z.Kd                    = 1;
z.rCalcMethod           = 'ratio';
z.rRatioOrGain          = 0.15;

z.fit_from              = 256;
z.fit_to                = 4096;
z.eval_from             = 4097;
z.eval_to               = 8192;

z.K_p_t                 = 1;
z.T_I                   = 0.2;
z.tau_p_t               = 0.2;
z.K_p_e                 = 2.3;
z.tau_p_e               = 0.21;
z.omega_nms             = 12;
z.zeta_nms              = 0.2;


z.iSignals1             = 'ft_total,fd';
z.oSignals1             = 'e';
z.NN1                   = [4 2 2 6 6];
z.iSignals              = 'ft_total,*';
z.oSignals              = 'u';
z.si                    = 4;
z.filter_o1             = 4;
z.filter_o              = 4;

z.tau_iSignals1         = [0 0];
z.tau_iSignals          = [0 0];

z.nr                    = 1;
z.pmax                  = Inf;
z.zmax                  = [Inf Inf];
z.Yp                    = Yp.SI;
z.ft                    = 'sdt ramp';
z.NN                    = getNNcell(1:4,0:4,0:4,1:8,1:8);
z.c                     = 3;

%%

figure
    plot(a.get('o_arx',z).deg,'k'); hold on
    plot(a.get('e',z).deg,'r','LineWidth',2)
    plot(a.get('i_arx',z,'NN1',[5 5 5 3 3]).deg,'g');
    ylim([-20 20])

%%

z.NN1   = [5 5 5 3 3];
z.NN    = getNNcell(1:4,0:4,0:5,1:8,1:9);
z.c     = 3;

a.get('nn_arx_best',z).sy

a.get('nn_arx_best',z,'c',{1,2}.').sy

figure
    bode(a.get('Y_arx_best_idpoly',z),'r','which',1);
    bode(a.get('Y_arx_best_idpoly',z),'b','which',2);