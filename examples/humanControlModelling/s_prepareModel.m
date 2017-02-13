function step = s_prepareModel()

    step.name       = mfilename;
    step.type       = 'step';
    step.decide     = {};
    step.basedon    = {};
    step.input      = {'Yp'};
    step.optional   = {'K_c','omega_b',...
                       'Tm','Ts','Te','dt'};
    step.output     = {'model_p'};
    step.handle     = @myfunc;
    step.version    = 1;
    step.saveme     = 0;
    step.memorizeme = 1;

    function r_n = myfunc(z,~,~,~)
        model   = HMModel4('sd_task_new','sd_pilot');
        model.setTaskLoggedSignalNames('u','u_prenms','u_p_t','u_p_e','y','e','ft_total');
        model.setPilotLoggedSignalNames('u','u_p_e','u_p_t');
        model.useSSforGenetic(0);
        
        switch z.Yp
            case 'ifac'
                ffm_ifac
            case 'openloop test'
                openloop_test
            case 'bcm_1/s'
                bcm_1s
            case 'ffm arm'
                ffm_arm
            case 'ffm_1/s'
                ffm_1s
            case 'ffm 1/s laurense'
%                 error('Don''t use this model without checking it first.');
                ffm_1s_laurense
            case 'ffm 1/s(s+2) laurense'
%                 error('Don''t use this model without checking it first.');
                ffm_1s_splus2_laurense
            case 'ffm 1/s2 laurense'
%                 error('Don''t use this model without checking it first.');
                ffm_1s2_laurense
            case 'ffm 1/s real laurense'
                ffm_1s_laurense2
            case 'ffm 1/s(s+2) real laurense'
                ffm_1s_splus2_laurense2
            case 'ffm 1/s2 real laurense'
                ffm_1s2_laurense2
            case 'ffm 1/s laurense TI fix'
                error('Don''t use this model without checking it first.');
                ffm_1s_laurense_TI
            case 'ffm 1/s laurense anticipate'
                error('Don''t use this model without checking it first.');
                ffm_1s_laurense_ant
            case 'ffm 1/s(s+2) laurense anticipate'
                error('Don''t use this model without checking it first.');
                ffm_1s_splus2_laurense_ant
            case 'ffm 1/s2 laurense anticipate'
                error('Don''t use this model without checking it first.');
                ffm_1s2_laurense_ant
            case 'ffm 1/s real laurense anticipate'
                ffm_1s_laurense_ant_nonmsff
            case 'ffm 1/s(s+2) real laurense anticipate'
                ffm_1s_splus2_laurense_ant_nonmsff
            case 'ffm 1/s2 real laurense anticipate'
                ffm_1s2_laurense_ant_nonmsff
            case 'ffm 1/s laurense anticipate TI fix'
                error('Don''t use this model without checking it first.');
                ffm_1s_laurense_ant_TI
            case 'ffm 1/s(s+2) laurense anticipate TI'
                error('Don''t use this model without checking it first.');
                ffm_1s_splus2_laurense_ant_TI
            case 'ffm 1/s2 laurense anticipate TI'
                error('Don''t use this model without checking it first.');
                ffm_1s2_laurense_ant_TI
            case 'ffm_1/s_fast'
                error('Don''t use this model without checking it first.');
                ffm_1s_fast
            case 'ffm_1/s_nms'
                error('Don''t use this model without checking it first.');
                ffm_1s_nms
            case 'ffm_1/s_hugo'
                error('Don''t use this model without checking it first.');
                ffm_1s_hugo
            case 'ffm_1/s(s+3)'
                error('Don''t use this model without checking it first.');
                ffm_1s_splus3
            case 'ffm_1/s(s+2)'
                error('Don''t use this model without checking it first.');
                ffm_1s_splus2
            case 'motion_1/s(s+2)'
                motion_1s_splus2
            case 'motion_scc'
                motion_SCC
            case 'motion_scc_inverse'
                motion_SCC_inverse
            case 'motion_scc_noise'
                motion_SCC_noise
            case 'motion_scc_simple'
                motion_SCC_simple
            case 'motion_scc_yc'
                motion_SCC_yc
            case 'motion_scc_simple_timedelay'
                motion_SCC_timedelay
            case 'motion_scc_simple_r'
                motion_SCC_simple_r
            case 'motion_scc_fout'
                motion_SCC_fout
            case 'motion_scc_firstpade'
                motion_SCC_firstpade
            case 'motion_scc_arm'
                motion_SCC_arm
            case 'motion_scc_cms'
                motion_SCC_cms
            case 'motion_scc_bdft'
                motion_SCC_bdft
            case 'motion_scc_complex'
                motion_SCC_complex
            case 'm_zaal2009f'
                m_zaal2009f
            case 'ffm_1/s(s+2)_red'
                ffm_1s_splus2_red
            case 'ffm_1/s(s+1)'
                ffm_1s_splus1
            case 'bcm_1/s2'
                bcm_1s2
            case 'ffm_1/s2'
                ffm_1s2
            case 'ffm_1/s2_waveform'
                ffm_1s2_waveform
            case 'sffm_1/s2'
                sffm_1s2
            case 'ffm_1/s2_fast'
                ffm_1s2_fast
            case 'ffm_1/s2_nms'
                ffm_1s2_nms
            case 'ffm_1/s2_red'
                ffm_1s2_red
            case 'ahs feedforward simple'
                ahs_feedforward_simple
            case 'ahs feedback simple'
                ahs_feedback_simple
            case 'ahs hess feedforward simple'
                ahs_hess_feedforward_simple
            case 'ahs hess simple'
                ahs_hess_simple
            case 'ahs hess'
                ahs_hess
            case 'ahs nieuwenhuizen stable'
                ahs_nieuwenhuizen_stable
            case 'ahs nieuwenhuizen'
                ahs_nieuwenhuizen
            case 'ahs feedback'
                ahs_feedback
            case 'ahs feedforward'
                ahs_feedforward
            case 'ahs multiloop'
                ahs_multiloop
            case 'ahs no roll'
                ahs_no_roll
            case 'ahs rate feedback'
                ahs_ratefeedback
            case 'td 1/s(s+2)'
                td_1s_splus2
            otherwise
                error('The model ''%s'' is not defined. See <a href="matlab:open s_prepareModel">s_prepareModel</a> for options.',z.Yp);
        end

        model.defineTransferFunctions(1);
        
        if isempty(z.dt)
            z.dt    = 0.01;
        end
        
        if isempty(z.Tm)
            z.Tm    = 81.92;
        end
        
        if isempty(z.Te)
            z.Te    = 90.01;
        end
        
        if isempty(z.Ts)
            z.Ts    = 3*90.01;
        end

        model.setDt(z.dt);
        model.setMeasurementTimeVector((0:(z.Tm/z.dt-1))*z.dt);
        model.setExperimentTimeVector((0:(z.Te/z.dt-1))*z.dt);
        model.setSimulationTimeVector((0:(z.Ts/z.dt-1))*z.dt);
        
        r_n.model_p     = model.copy;
    end
end