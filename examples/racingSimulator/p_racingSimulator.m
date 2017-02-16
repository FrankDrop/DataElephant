function p = p_racingSimulator()
    p.name      = mfilename;
    p.steps     = {@s_readRAF,@s_filterRAF,@s_simClassicMCA};
	p.branches  = {{@s_filterRAF,@s_calculateStatistics,@d_bestLap,@s_bestLap,@s_fitModel}};
end