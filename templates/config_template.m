function [s] = config(obj, hostname)
    switch hostname
        otherwise
            s.save                  = 'yes';
            s.load                  = 'yes';
            s.verbose               = 'yes';
            s.fileverbose           = 'no';
            s.deepverbose           = 'no';
            s.funcverbose           = 'no';
            s.flockverbose          = 'no';
            s.win_root              = '';           % e.g., 'C:/DataElephant/Storage/'
            s.win_distfolder        = '';           % e.g., 'C:/DataElephant/Dist/'
            s.win_tempfolder        = '';           % e.g., 'C:/DataElephant/Temp/'
            s.unix_root             = '';           % e.g., '/home/username/DataElephant/Storage'
            s.unix_distfolder       = '';           % e.g., '/home/username/DataElephant/Dist'
            s.unix_tempfolder       = '';           % e.g., '/home/username/DataElephant/Temp'
            s.flock                 = 'no';
            s.flockport             = 5600;
            s.flockip               = '';           % e.g., '127.168.0.1'
            s.submittohost          = 'no';
            s.savetotemp            = 'yes';
            s.savememory            = 'no';
            s.addfinalstep          = 'yes';
            s.continueonerror       = 'yes';
            s.hostname              = []; 
    end
end