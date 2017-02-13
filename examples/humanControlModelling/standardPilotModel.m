function model = standardPilotModel(Yp)

model   = HMModel4('sd_task_new','sd_pilot');

model.setTaskLoggedSignalNames('u','u_prenms','u_p_t','u_p_e','y','e','ft_total');
model.setPilotLoggedSignalNames('u','u_p_e','u_p_t');
    
model.setYnms('pp.omega_nms^2 / (S^2 + 2*pp.zeta_nms*pp.omega_nms*S + pp.omega_nms^2)');

model.useSSforGenetic(0);

model.setMeasurementTimeVector((0:8191)*0.01);
model.setExperimentTimeVector((0:9000)*0.01);
model.setSimulationTimeVector((0:(3*9000-1))*0.01);
model.setDt(0.01);

model.setRemnantParams(0,12.7,0.26);


switch Yp
    case 'openloop test'
        openloop_test
    case 'bcm_1/s'
        bcm_1s
    case 'ffm_1/s'
        ffm_1s
	case 'ffm 1/s laurense'
        ffm_1s_laurense
	case 'ffm 1/s(s+2) laurense'
        ffm_1s_splus2_laurense
    case 'ffm 1/s2 laurense'
        ffm_1s2_laurense
	case 'ffm_1/s_fast'
        ffm_1s_fast
	case 'ffm_1/s_nms'
        ffm_1s_nms
	case 'ffm_1/s_hugo'
        ffm_1s_hugo
    case 'ffm_1/s(s+3)'
        ffm_1s_splus3
    case 'ffm_1/s(s+2)'
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
    case 'motion_scc_fout'
        motion_SCC_fout
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
    otherwise
        error('The model ''%s'' is not defined. See <a href="matlab:open standardPilotModel">standardPilotModel</a> for options.',Yp);
end

model.defineTransferFunctions(1);

if exist('lb','var') && exist('ub','var')
    model.setEstimationSettings(lb,ub);
end
end
