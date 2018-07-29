classdef DataElephant < handle
    
    properties (Access = public)
        verbose
    end
        
    properties (Access = private)
        
        % Storage for data
        hash
        shorthash
        time
        data
        new
        saveme
        bystep
        keepme
        kk
        providexy
        
        % 'default' input parameters
        z_default
        defaultInputs

        % Storage for decisions
        dec_hash
        dec_hashash
        dec_shorthash
        dec_fasthash
        dec_hasfasthash
        dec_time
        dec_data
        dec_new
        dec_saveme
        dec_bystep
        dec_keepme
        uuu
        
        % Process stuff
        fHandle
        process
        steps
        
        % Settings
        initCollection
        mpool
        strict
        load_hdd
        save_hdd
        load_old
        load_really_old
        savememory
%         verbose
        fileverbose
        deepverbose
        funcverbose
        flockverbose
        allInputs
        allOutputs
        savepoints
        continueonerror
        addfinalstep
        submitToHost % submit If Restricted To Host
        
        % Hash stuff
        hashlength
        fnchashcache
        fastfnchashcache
        
        % Folders
        rootfolder
        oldrootfolder
        distfolder
        tempfolder
        unix_rootfolder
        unix_distfolder
        unix_tempfolder
        
        % Distributed computing stuff
        savetotemp
        priorPath
        
        % FileLock stuff
        flock
        socket
        myid
        myhostname
        myport
        flockport
        flockip
        flockpacketlength
        
        % sql
        sql
        
        x_output
        getTime
    end
    
    methods(Static, Access = public)
        
        stepTemplate();
        decisionTemplate();
        processTemplate();
        configTemplate();
        varargout   = splitOutput(out);
        checkMex();
    end
    
    methods(Static, Access = private)
        
        A                       = catstruct(varargin);
                                  anyTemplate(template,name);
        fldr                    = tidyfoldername(fldr);
        mssg                    = addPort(mssg,port);
        s                       = createLink(n);
        [z,z_nuf]               = args(varargin);
        
        [answer,id,filename]    = readMessage(mssg);
        [r_i,f_i]               = getIndividual(r_i,f_i,fields,fnc,idx,n_choices);
        r                       = addIndividual(r,r_i,uu);
        
        
        
    end
    
    methods(Access = public)
        info(obj,varargin);
        requiredInputs(obj,output);
        meminfo(obj,varargin);
        printInputsFor(obj,varargin);
        printOptionalInputsFor(obj,output,varargin);
        
        [r,id_cum] = get(obj,name,z,varargin);
        
        function obj = DataElephant(varargin)

            if isa(varargin{1}, 'function_handle')
                fH  = varargin{1};
                varargin(1)     = [];
            else
                fH  = [];
            end
            
            if isempty(fH)
                init(obj,varargin{:});
                releaseAllLocks(obj,true);
                DistributedCacheProcessData(obj,varargin{:});
            else
                setProcessHandle(obj,fH);
                init(obj,varargin{:});
            end
            
            DataElephant.checkMex();
            updateTree(obj);
        end
        function delete(obj)
            cleanexit(obj,'delete');
        end
    end
    
	methods(Access = private)
        
        cleanexit(obj,fnc);
        s = config(obj, hostname);
        obj = DistributedCacheProcessData(obj,varargin);
        obj = setProcessHandle(obj,fH);
    
        pverbose(obj,varargin);
        pdebug(obj,varargin);
        
        obj     = add_alloc(obj,N_total,N_new,step);
        obj     = revertAlloc(obj);
        added   = add(obj,hash,fasthash,z,r_n,decision,n,time,step,lastStepInSequence,saveme);
        
        id      = lastCommonHash(obj,id_req_s);
        id_hex  = hexhash(obj,dec_hash,varargin);
        
        [atStep, names_stripped, names_raw, names_unequal ] = prepareBranchAndNames(obj, name )
        
        rootfolder  = getRootFolder(obj);
        rootfolder  = getTempFolder(obj);
        rootfolder  = getDistFolder(obj);
        
        [filename,cumhash,varname,ori_id] = getFolderAndVarname(obj,hash,step);
        [filename,cumhash,varname,ori_id] = getFolderAndVarnameOld(obj,hash,type);
        
        varargout = checkOrLoadFromDisk(obj,hash,fasthash,step,lastStepInSequence,lookForFasthash);
        varargout = checkOrSelectByHash(obj,hash,fasthash,step,lastStepInSequence,lookForFasthash);
       
        [r,rf,id_cum,f,z_cum,z_step] =            getAll(obj,name,z_cum,z_step,startAtStep,stopAtStep,     lastStepInSequence,r,rf,id_cum,minStep,drawStructure);
        [r,rf,id_cum_s,z_cum,z_step] =   getSingleResult(obj,name,z_cum,z_step,startAtStep,singleUntilStep,lastStepInSequence,r,rf,id_cum,returnMultiple,functional,minStep)

                            r_n =   fetchStep(    obj,z_cum,z_step,r,hash,step,lastStepInSequence);
                            r_n = calcNewStep(    obj,z_cum,z_step,r,hash,step,lastStepInSequence,checkOutputs);
        
        [r_t,rf_t,decision,z_dec]    =   fetchDecision(obj,z_cum,z_step,r,rf,hash,fasthash,decision_hash,step,lastStepInSequence);
        [r,decision,z_dec]           = calcNewDecision(obj,z_cum,z_step,r,   hash,fasthash,decision_hash,step,lastStepInSequence);
        
        id = generateHash(obj,z_cum,z_step,stepnr,id_req_s,         decisionFunctional,functionalStartAt,decisionStartAt,decisionTakenAt,decisionFunctionalRange,decisionDecidesOver);
        id = nextHash(    obj,z_cum,z_step,stepnr,id_req_s,id_dec_s,decisionFunctional,functionalStartAt,decisionStartAt,decisionTakenAt,decisionFunctionalRange,decisionDecidesOver);
        id = generateFasthash(obj,z_cum,stepnr);
        obj = makeFunctionalCache(obj,inputName,inputContent);
        
        obj = init(obj,varargin);
        
        [bn,sn] = updateTree(obj,name);
        
        obj = setDefault(obj,z);
        
        
        
        goodToGo = canCalcOnThisHost(obj,step,z,submittedBefore);
        submit(obj,name,z,varargin);
        
        savestepsave(obj,fnm,H);
        savedecisionsave(obj,fnm,H);
        
        savestepbyidx(obj,fldr,idx);
        
        savestepto(obj,fldr,D,N);
        savedecisionto(obj,fldr,D,N);
        
        savestep(obj,step,removeFromMemory);
        saveall(obj,removeFromMemory);
        
        
        mssg = createMessage(obj,action,filename);
        
        gotConfirmed = doSomethingWithLock(obj,action,filename,keepWaiting);
        gotConfirmed = getLock(obj,filename,keepWaiting);
        gotConfirmed = releaseLock(obj,filename,keepWaiting);
        gotConfirmed = releaseAllLocks(obj,keepWaiting);
        
        port = sendUDP(obj,mssg);
        mssg = receiveUDP(obj,port);
        
        obj = uniqueHashes(obj,silent); 

        [x,y,fn,fv] = getY(obj,r,names_stripped,names_raw,f,fn,fv,ll);

    end
end