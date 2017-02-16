function p = p_pdata3demo()
    p.name      = mfilename;
    p.steps     = {@s_generateSignals};
	p.branches  = {};
end