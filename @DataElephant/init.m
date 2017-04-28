function obj = init(obj,varargin)
    
    [~, hostname]   = system('hostname');
    hostname        = hostname(1:(end-1));

    s   = config(obj,hostname);
    
    p = inputParser;
    p.CaseSensitive = true;
    p.addParameter('save',             s.save);
    p.addParameter('load',             s.load);
    p.addParameter('verbose',          s.verbose);
    p.addParameter('fileverbose',      s.fileverbose);
    p.addParameter('deepverbose',      s.deepverbose);
    p.addParameter('funcverbose',      s.funcverbose);
    p.addParameter('flockverbose',     s.flockverbose);
    p.addParameter('win_root',         s.win_root);
    p.addParameter('win_distfolder',   s.win_distfolder);
    p.addParameter('win_tempfolder',   s.win_tempfolder);
    p.addParameter('unix_root',        s.unix_root);
    p.addParameter('unix_distfolder',  s.unix_distfolder);
    p.addParameter('unix_tempfolder',  s.unix_tempfolder);
    p.addParameter('flock',            s.flock);
    p.addParameter('flockport',        s.flockport);
    p.addParameter('flockip',          s.flockip);
    p.addParameter('submittohost',     s.submittohost);
    p.addParameter('savetotemp',       s.savetotemp);
    p.addParameter('savememory',       s.savememory);
    p.addParameter('addfinalstep',     s.addfinalstep);
    p.addParameter('continueonerror',  s.continueonerror);
    p.addParameter('hostname',         s.hostname);
    p.addParameter('sql',              s.sql);
    p.parse(varargin{:});
    z = p.Results;
    
    obj.initCollection  = z;

    % Make sure the storage for data is cleared
    obj.hash            = [];
    obj.shorthash       = uint8([]);
    obj.time            = [];
    obj.data            = [];
    obj.new             = [];
    obj.saveme          = [];
    obj.bystep          = [];
    obj.keepme          = [];
    obj.kk              = 1;

    % Make sure the storage for data is cleared
    clear obj.dec_hash obj.dec_shorthash obj.dec_time obj.dec_data obj.dec_new

    obj.dec_hash        = [];
    obj.dec_shorthash   = [];
    obj.dec_fasthash    = [];
    obj.dec_hasfasthash = [];
    obj.dec_hashash     = [];
    obj.dec_time        = [];
    obj.dec_data        = [];
    obj.dec_new         = [];
    obj.dec_saveme      = [];
    obj.dec_bystep      = [];
    obj.dec_keepme      = [];
    obj.uuu             = 1;

    % Processing the varargin stuff
    
    % Folders
    obj.rootfolder      = obj.tidyfoldername(z.win_root);
    obj.distfolder      = obj.tidyfoldername(z.win_distfolder);
    obj.tempfolder      = obj.tidyfoldername(z.win_tempfolder);
    
    % unix folders
    obj.unix_rootfolder = obj.tidyfoldername(z.unix_root);
    obj.unix_distfolder = obj.tidyfoldername(z.unix_distfolder);
    obj.unix_tempfolder = obj.tidyfoldername(z.unix_tempfolder);
    
    obj.load_hdd        = strcmp(z.load,                'yes');
    obj.save_hdd        = strcmp(z.save,                'yes');
    obj.verbose         = strcmp(z.verbose,             'yes');
    obj.deepverbose     = strcmp(z.deepverbose,         'yes');
    obj.fileverbose     = strcmp(z.fileverbose,         'yes');
    obj.funcverbose     = strcmp(z.funcverbose,         'yes');
    obj.flock           = strcmp(z.flock,               'yes');
    obj.flockverbose    = strcmp(z.flockverbose,        'yes');
    obj.submitToHost    = strcmp(z.submittohost,        'yes');
    
    obj.savetotemp      = strcmp(z.savetotemp,          'yes');
    obj.savememory      = strcmp(z.savememory,          'yes');
    obj.continueonerror = strcmp(z.continueonerror,     'yes');
    obj.addfinalstep    = strcmp(z.addfinalstep,        'yes');
    
    obj.sql             = strcmp(z.sql,                 'yes');
    
    obj.hashlength          = 16;    
    
    if isempty(z.hostname)
        [~, hostname]           = system('hostname');
        z.hostname              = hostname(1:(end-1));
    end
    obj.myid                = [z.hostname '-' num2str(feature('getpid'))];
    obj.myhostname          = z.hostname;
    
    % file lock stuff    
    import java.io.*
    import java.net.DatagramSocket
    import java.net.DatagramPacket
    import java.net.InetAddress

    obj.flockport           = round(z.flockport);
    obj.flockip             = InetAddress.getByName(z.flockip);
    obj.flockpacketlength   = 1+5+100+256;
    
    if (obj.load_hdd || obj.save_hdd) && ~exist(obj.getRootFolder(),'dir')
        if ispc
            error('The folder you specified for loading does not exist (%s). Set ''win_root'' to a valid folder.',obj.getRootFolder());
        elseif isunix
            error('The folder you specified for loading does not exist (%s). Set ''unix_root'' to a valid folder.',obj.getRootFolder());
        end
    end
    
    if obj.save_hdd && obj.savetotemp && ~exist(obj.getTempFolder(),'dir')
        if ispc
            error('The temporary save folder you specified does not exist (%s). Set ''win_tempfolder'' to a valid folder.',obj.getTempFolder());
        elseif isunix
            error('The temporary save folder you specified does not exist (%s). Set ''unix_tempfolder'' to a valid folder.',obj.getTempFolder());
        end
    end
end