function obj = init(obj,varargin)
    
    p = inputParser;
    p.CaseSensitive = true;
    p.addParameter('save',             'yes');
    p.addParameter('load',             'yes');
    p.addParameter('loadFromOld',      'no');
    p.addParameter('loadFromReallyOld','no');
    p.addParameter('validate',         'yes');
    p.addParameter('verbose',          'yes');
    p.addParameter('debug',            'no');
    p.addParameter('fileverbose',      'no');
    p.addParameter('deepverbose',      'no');
    p.addParameter('funcverbose',      'no');
    p.addParameter('flockverbose',     'no');
    p.addParameter('root',             'O:\AnalysisCache');
    p.addParameter('distfolder',       'O:\DistCache');
    p.addParameter('tempfolder',       'D:\CacheProcessDataTemp');
    p.addParameter('unix_root',        '/home/mpsim/CacheProcessData/AnalysisCache');
    p.addParameter('unix_distfolder',  '/home/mpsim/CacheProcessData/DistCache');
    p.addParameter('unix_tempfolder',  '/home/mpsim/CacheProcessDataTemp');
    p.addParameter('oldroot',          '-');
    p.addParameter('strict',           'yes');
    p.addParameter('flock',            'no');
    p.addParameter('flockport',        5600);
    p.addParameter('flockip',          '10.38.120.47');
    p.addParameter('hostname',         []);
    p.addParameter('submittohost',     'yes');
    
    p.addParameter('savetotemp',       'yes');
    p.addParameter('savememory',       'yes');
    p.addParameter('addfinalstep',     'yes');
    p.addParameter('continueonerror',  'yes');
    
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
    obj.validate        = z.validate;
    
    % Folders
    obj.rootfolder      = obj.tidyfoldername(z.root);
    obj.oldrootfolder   = obj.tidyfoldername(z.oldroot);
    obj.distfolder      = obj.tidyfoldername(z.distfolder);
    obj.tempfolder      = obj.tidyfoldername(z.tempfolder);
    
    % unix folders
    obj.unix_rootfolder = obj.tidyfoldername(z.unix_root);
    obj.unix_distfolder = obj.tidyfoldername(z.unix_distfolder);
    obj.unix_tempfolder = obj.tidyfoldername(z.unix_tempfolder);
    
    obj.memuse          = 0;
    obj.memoryverbose   = 0;

    obj.load_hdd        = strcmp(z.load,                'yes');
    obj.load_old        = strcmp(z.loadFromOld,         'yes');
    obj.load_really_old = strcmp(z.loadFromReallyOld,   'yes');
    obj.save_hdd        = strcmp(z.save,                'yes');
    obj.verbose         = strcmp(z.verbose,             'yes');
    obj.debug           = strcmp(z.debug,               'yes');
    obj.deepverbose     = strcmp(z.deepverbose,         'yes');
    obj.fileverbose     = strcmp(z.fileverbose,         'yes');
    obj.strict          = strcmp(z.strict,              'yes');
    obj.funcverbose     = strcmp(z.funcverbose,         'yes');
    obj.flock           = strcmp(z.flock,               'yes');
    obj.flockverbose    = strcmp(z.flockverbose,        'yes');
    obj.submitToHost    = strcmp(z.submittohost,        'yes');
    
    obj.savetotemp      = strcmp(z.savetotemp,          'yes');
    obj.savememory      = strcmp(z.savememory,          'yes');
    obj.continueonerror = strcmp(z.continueonerror,     'yes');
    obj.addfinalstep    = strcmp(z.addfinalstep,        'yes');

    if (obj.save_hdd == 1 || obj.load_hdd == 1) && strcmp(obj.rootfolder,'-')
        error('You need to provide the location to the cache files. For example: ''root'',''O:\AnalysisCache\''.');
    end
    
    obj.hashlength  = 16;

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
    
    % Check if all folders exist
    if obj.load_hdd && ~exist(obj.getRootFolder(),'dir')
        error('The folder you specified for loading does not exist (%s). Set ''root'' or ''unixroot'' to a valid folder.',obj.getRootFolder());
    end
    
    if obj.load_old && ~exist(obj.oldrootfolder,'dir')
        error('The (legacy) folder you specified for loading does not exist (%s).',obj.oldrootfolder);
    end
    
    if obj.save_hdd && ~exist(obj.getRootFolder(),'dir')
        error('The folder you specified for saving does not exist (%s).',obj.getRootFolder());
    end
    
    if obj.save_hdd && obj.savetotemp && ~exist(obj.getTempFolder(),'dir')
        try
            mkdir(obj.getTempFolder());
        catch e
            error('Tried creating the temporary folder %s, but this failed: %s.',obj.getTempFolder(),e.message());
        end
    end
end