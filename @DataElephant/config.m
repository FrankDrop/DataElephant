function [s] = config(obj, hostname)
    switch hostname
        otherwise
            s.save                  = 'yes';
            s.load                  = 'yes';
            s.validate              = 'yes';
            s.verbose               = 'yes';
            s.fileverbose           = 'no';
            s.deepverbose           = 'no';
            s.funcverbose           = 'no';
            s.flockverbose          = 'no';
            s.win_root              = 'O:\AnalysisCache';
            s.win_distfolder        = 'O:\DistCache';
            s.win_tempfolder        = 'D:\CacheProcessDataTemp';
            s.unix_root             = '/home/fdrop/StorageElephants';
            s.unix_distfolder       = '/home/fdrop/DistributedElephants';
            s.unix_tempfolder       = '/home/fdrop/TemporaryElephants';
            s.flock                 = 'no';
            s.flockport             = 5600;
            s.flockip               = '10.38.120.47';
            s.submittohost          = 'no';
            s.savetotemp            = 'yes';
            s.savememory            = 'no';
            s.addfinalstep          = 'yes';
            s.continueonerror       = 'yes';
            s.hostname              = []; 
    end
end