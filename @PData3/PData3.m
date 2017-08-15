classdef PData3 < matlab.mixin.Copyable
    
    properties
        x
        fValues
        fNames
        fLabels
        y
        xAxis
        yAxis
        stdv
        isEmpty
        myName
    end
    
    
    methods (Static)
        
        function str = subscriptUnderscore(str)
            str = strrep(str,'_','\_');
        end
        
        function xrms = rms_(x,dim)
%             xrms = sqrt((1./size(x,dim)) * sum(x.^2,dim));
            xrms = sqrt(mean(x .* conj(x),dim));
        end
        
        function isls = islinespec(x)
            isls    = false;

            if ~ischar(x)
                return;
            end

            lineStyleSpecifiers     = {'--','-.','-',':'};
            markerSpecifiers        = {'square','diamond','pentagram','hexagram','+','o','*','.','x','s','d','^','v','>','<','p','h'};
            colorSpecifiers         = {'r','g','b','c','m','y','k','w'};

            for oo=1:length(lineStyleSpecifiers)
                k = strfind(x,lineStyleSpecifiers{oo});
                if ~isempty(k)
                    x(k:(k+length(lineStyleSpecifiers{oo})-1)) = [];
                    break;
                end
            end

            for oo=1:length(markerSpecifiers)
                k = strfind(x,markerSpecifiers{oo});
                if ~isempty(k)
                    x(k:(k+length(markerSpecifiers{oo})-1)) = [];
                    break;
                end
            end

            for oo=1:length(colorSpecifiers)
                k = strfind(x,colorSpecifiers{oo});
                if ~isempty(k)
                    x(k:(k+length(colorSpecifiers{oo})-1)) = [];
                    break;
                end
            end

            if isempty(x)
                isls = true;
            end
        end
        
        function h = setGrayScaleProperties(h,z)
            for ii=1:length(h)
                h(ii).UserData.gColor               = z.gColor;
                h(ii).UserData.gLineStyle           = z.gLineStyle;
                h(ii).UserData.gLineWidth           = z.gLineWidth;
                h(ii).UserData.gMarker              = z.gMarker;
                h(ii).UserData.gMarkerSize          = z.gMarkerSize;
                h(ii).UserData.gMarkerFaceColor     = z.gMarkerFaceColor;
                h(ii).UserData.gMarkerEdgeColor     = z.gMarkerEdgeColor;
                h(ii).UserData.gFaceColor           = z.gFaceColor;
                hold(z.Axis,'on');
            end
        end
        
        function [z,unm] = parsePlotInput(varargin)
            p = inputParser;
            p.CaseSensitive     = true;
            p.KeepUnmatched     = true;
            
            addOptional(p,'LineSpec','',@(x)PData3.islinespec(x));
            addParameter(p,'BarStyle',[],@(x)any(strcmp(x,{'grouped','stacked','histc','hist'})));
            addParameter(p,'which',1,@isnumeric);
            addParameter(p,'w',logspace(-1,2,100)',@(x)(all(isnumeric(x)) & iscolumn(x)));
            addParameter(p,'pos','',@iscell);
            addParameter(p,'neg','',@iscell);
            addParameter(p,'magAxis',[],@(x)isa(x,'matlab.graphics.axis.Axes'));
            addParameter(p,'phaseAxis',[],@(x)isa(x,'matlab.graphics.axis.Axes'));
            addParameter(p,'unwrap',true,@(x)islogical(x));
            addParameter(p,'multisinePeaks',false,@(x)islogical(x));
            addParameter(p,'atIndex',[],@(x)isnumeric(x));
            addParameter(p,'phaseStartAt',[],@(x)isnumeric(x));
            addParameter(p,'phaseStartIdx',[],@(x)isnumeric(x));
            addParameter(p,'magnitude',1,@(x)islogical(x));
            addParameter(p,'phase',1,@(x)islogical(x));
            addParameter(p,'bins',[],@(x)isnumeric(x));
            parse(p,varargin{:});
            
            z       = p.Results;
            unm     = p.Unmatched;
        end
        
        function [z,unm] = parseGrayScalePlotInput(varargin)
            p = inputParser;
            p.CaseSensitive     = true;
            p.KeepUnmatched     = true;
            addOptional(p,'LineSpec',[],@PData3.islinespec);
            addParameter(p,'Axis',gca,@(x)isa(x,'matlab.graphics.axis.Axes'));
            addParameter(p,'setXLim',true,@(x)islogical(x));
            addParameter(p,'setYLim',true,@(x)islogical(x));
            addParameter(p,'gColor',[]);
            addParameter(p,'gFaceColor',[]);
            addParameter(p,'gLineStyle',[]);
            addParameter(p,'gLineWidth',[]);
            addParameter(p,'gMarker',[]);
            addParameter(p,'gMarkerSize',[]);
            addParameter(p,'gMarkerFaceColor',[]);
            addParameter(p,'gMarkerEdgeColor',[]);
            addParameter(p,'myName',[]);
            parse(p,varargin{:});
            z       = p.Results;
            unm     = p.Unmatched;
        end
        
        function M  = selectFromDim(M,sdim,sel,keep)
            nd          = ndims(M);
            sC          = repmat({':'},1,nd);
            sC{sdim}    = sel;
            M           = M(sC{:});
            
            if ~keep && length(sel) == 1 && sdim <= ndims(M)
                sz      = size(M);
                rsz     = [sz(1:(sdim-1)) sz((sdim+1):end)];
                if length(rsz) == 1
                    rsz     = [rsz 1];
                end
                M       = reshape(M,rsz);
            end
        end
        
    end
    
    methods (Access = private)
       function obj = setData(obj,varargin)
            
            p = inputParser;
            p.CaseSensitive = true;
            p.addParameter('x',[]);
            p.addParameter('y',[]);
            p.addParameter('fValues',[]);
            p.addParameter('fNames',[]);
            p.addParameter('myName',[]);
            p.parse(varargin{:});
            z = p.Results;
            
            % If the data is set as a single point, we have to encapsulate
            % it in a cell. If it is part of a functional result, it should
            % not.
            
            
            obj.x       = z.x;
            obj.y       = z.y;
            
            obj.fNames  = z.fNames;
            obj.myName  = z.myName;
            
            for oo=1:length(z.fValues)
                if iscell(z.fValues{oo})
                    if ischar(z.fValues{oo}{1})
                        obj.fValues{oo} = (1:length(z.fValues{oo})).';
                        obj.fLabels{oo} = z.fValues{oo}.';
                    elseif isnumeric(z.fValues{oo}{1})
                        if ~isscalar(z.fValues{oo}{1})
                            obj.fValues{oo} = z.fValues{oo};
                            obj.fLabels{oo} = z.fValues{oo};
                        else
                            obj.fValues{oo} = cell2mat(z.fValues{oo}).';
                            obj.fLabels{oo} = cell2mat(z.fValues{oo}).';
                        end
                    end
                else
                    error('This is weird.');
                end
            end
            obj.checkdimensions();
        end
        
    end
    
    methods
        function obj = PData3(varargin)
            if nargin == 0
                obj.isEmpty = 1;
            else
                obj.isEmpty = 0;
                obj.setData(varargin{:});
                obj.xAxis  = 'x';
                if numel(obj.x) == 1 && length(obj.fNames) == 1
                    obj.xAxis = obj.fNames{1};
                end
            end
        end
        
        function ss = sx(obj)
            ss = squeeze(obj.x);
        end
        
        function ss = sy(obj,order)
            if nargin == 1
                ss = squeeze(obj.y);
            else
                if ischar(order)
                    flds    = regexp(order,',','split');
                    dimOrder = [];

                    if ~any(strcmp(flds,'x'))
                        flds{end+1}     = 'x';
                    end
                    for oo=1:length(flds)
                        if any(strcmp(flds{oo},obj.fNames))
                            dimOrder    = [dimOrder find(strcmp(flds{oo},obj.fNames))]; %#ok<AGROW>
                        elseif strcmp(flds{oo},'x')
                            if isscalar(obj.x)
                                xdims   = length(obj.fNames)+1;
                            else
                                xdims   = length(obj.fNames)+(1:ndims(obj.x));
                            end
                            dimOrder    = [dimOrder xdims]; %#ok<AGROW>
                        else
                            error('I don''t know field %s.',flds{oo});
                        end
                    end
                    ss = permute(obj.y,dimOrder);
                else
                    ss = obj.y(order);
                end
            end
        end
        
        function ss = str(obj,varargin)
            ss = num2str(squeeze(obj.y),varargin{:});
        end
        
        
        
        function nobj = sUD(obj,fname,f)
            nobj = setUserData(obj,fname,f);
        end
        
        function nobj = setUserData(obj,fname,f)
            nobj    = obj.copy;
            
            if strcmpi(fname,'x')
                nobj.x = f;
            elseif strcmpi(fname,'y')
                nobj.y = f;
            else
                usrdatadim     = find(strcmpi(fname,nobj.fNames));
                if isempty(usrdatadim)
                    error('The function you want to assign data does not exist.');
                end
                if iscell(f)
                    if ischar(f{1})
                        nobj.fValues{usrdatadim}    = 1:length(f);
                        nobj.fLabels{usrdatadim}    = f;
                    else
                        error('This doesn''t make sense?');
                    end
                else
                    if isnumeric(f)
                        nobj.fValues{usrdatadim}    = f;
                        nobj.fLabels{usrdatadim}    = f;
                    else
                        error('This doesn''t make sense?');
                    end
                end
            end
            obj.checkdimensions();
        end
        
        function setFncXData(~,~,~,~)
            error('You use an outdated function! Use setUserData() instead.');
        end

        
%% Data manipulation

        function nobj = y0(obj,val)
           nobj     = obj.copy;
           nobj.y   = (nobj.y - nobj.y(1)) + val;
        end
        
        function nobj = x0(obj,val)
           nobj     = obj.copy;
           nobj.x   = (nobj.x - nobj.x(1)) + val;
        end

        function nobj = repmat(obj,varargin)
            nobj = obj.copy;
            if (mod(length(varargin),2) ~= 0)
                error('you should provide an even number of arguments.')
            end
            
            for oo=1:(length(varargin)/2)
                nobj.y = permute(repmat(nobj.y,1,1,length(varargin{2*oo})),[3 1 2]);
                nobj.fValues    = [varargin(2*oo) nobj.fValues];
                nobj.fNames     = [varargin(2*oo-1) nobj.fNames];
                nobj.fLabels    = [varargin(2*oo) nobj.fLabels];
            end
            nobj.checkdimensions();
        end
        
        function nobj = offsetx(obj,ox)
            nobj    = obj;
            nobj.x  = nobj.x + ox;
        end

        function obj = ha(obj,fname)
            for oo=1:length(obj)
                obj(oo).xAxis = fname;
            end
        end
        
        function obj = xa(obj,fname)
           for oo=1:length(obj)
                obj(oo).xAxis = fname;
            end
        end
        
        function obj = ya(obj,fname)
           for oo=1:length(obj)
                obj(oo).yAxis = fname;
           end
        end

        
        
        function nobj = genericxymath(obj,fncName,mainFnc,dim)
            nobj    = obj.copy;

            if iscell(nobj.y)
                error('I cannot calculate on items contained within a cell.');
            end

            sz              = size(nobj.y);
            nobj.y          = mainFnc(nobj.x,nobj.y,dim);

            if dim > length(nobj.fNames)
                
            else
                sz(dim)         = [];
                if length(sz) == 1
                    sz  = [sz 1];
                end
                nobj.y          = reshape(nobj.y,sz);

                if length(nobj.fLabels) == length(nobj.fNames)
                    nobj.fLabels(dim) = [];
                elseif ~isempty(nobj.fLabels)
                    error('Something weird here.')
                end
                nobj.fNames(dim)        = [];
                nobj.fValues(dim)       = [];
            end
            
            nobj.myName     = [fncName '(' nobj.myName ')'];
            nobj.checkdimensions();
        end
        
        function nobj = genericxymathover(obj,fncName,mainFnc,over,varargin)
            
            if strcmpi(over,'x')
                if length(varargin) == 1
                    xdim = varargin{1};
                else
                    if iscolumn(obj.x)
                        xdim = 1;
                    elseif isrow(obj.x)
                        error('untested code! please test');
                    else
                        error('You should provide one extra argument if you perform a math operation over x with more than one dimension. You provided %i.',length(varargin));
                    end
                end
                
                nobj        = genericxymath(obj,fncName,mainFnc,length(obj.fNames)+xdim,varargin{:});
            else
                error('you didn''t write this code yet')
                if ~isempty(varargin)
                    error('You cannot give additional arguments if you do not perform a math operation over x.')
                end
                
                overdim     = find(strcmpi(over,obj.fNames));

                if isempty(overdim)
                    error('The function over which you want to average does not exist.');
                end

                nobj        = genericmath(obj,fncName,mainFnc,overdim,varargin{:});
            end
            
            nobj.checkdimensions();
        end

        function nobj = genericmathover(obj,fncName,mainFnc,varFnc,over,applytox,varargin)
            
            if strcmpi(over,'x')
                if length(varargin) == 1
                    xdim = varargin{1};
                else
                    if iscolumn(obj.x)
                        xdim = 1;
                    elseif isrow(obj.x)
                        xdim = 2;
%                         warning('untested code! please test');
                    else
                        error('You should provide one extra argument if you perform a math operation over x with more than one dimension. You provided %i.',length(varargin));
                    end
                end
                
                nobj        = genericmath(obj,fncName,mainFnc,varFnc,length(obj.fNames)+xdim,applytox,varargin{:});
            else
                if ~isempty(varargin)
                    error('You cannot give additional arguments if you do not perform a math operation over x.')
                end
                
                meandim     = find(strcmpi(over,obj.fNames));

                if isempty(meandim)
                    error('The function over which you want to average does not exist.');
                end

                nobj        = genericmath(obj,fncName,mainFnc,varFnc,meandim,applytox,varargin{:});
            end
            
            nobj.checkdimensions();
        end

%% Math functions over a certain dimension specified by number

        function nobj = abs(pobj)
            nobj    = pobj.copy;
            % Because the abs function is not really taken over a certain
            % dimension, you provide [] as last argument.
            nobj    = nobj.genericmath('abs',@(x,d)abs(x),[],[],false);
        end
        
        function nobj = real(pobj)
            nobj    = pobj.copy;
            % Because the abs function is not really taken over a certain
            % dimension, you provide [] as last argument.
            nobj    = nobj.genericmath('real',@(x,d)real(x),[],[],false);
        end
        
        function nobj = imag(pobj)
            nobj    = pobj.copy;
            % Because the abs function is not really taken over a certain
            % dimension, you provide [] as last argument.
            nobj    = nobj.genericmath('imag',@(x,d)imag(x),[],[],false);
        end
        
        function nobj = conj(pobj)
            nobj    = pobj.copy;
            % Because the abs function is not really taken over a certain
            % dimension, you provide [] as last argument.
            nobj    = nobj.genericmath('conj',@(x,d)conj(x),[],[],false);
        end
        
        function nobj = cumtrapz(pobj,dim)
            nobj    = pobj.copy;
            if nargin == 1
                nobj    = nobj.genericxymath('cumtrapz',@(x,y,d)cumtrapz(x,y,d),1,false);
            else
                nobj    = nobj.genericxymath('cumtrapz',@(x,y,d)cumtrapz(x,y,d),dim,false);
            end
        end
        
        function nobj = angle(pobj)
            nobj    = pobj.copy;
            % Because the abs function is not really taken over a certain
            % dimension, you provide [] as last argument.
            nobj    = nobj.genericmath('angle',@(x,d)angle(x),[],[]);
        end
        
        
        
        function nobj = dangle(pobj)
            nobj    = pobj.copy;
            nobj    = nobj.genericmath('angle',@(x,d)angle(x),[],[]).deg;
        end
        
        function nobj = dunwrap(pobj,dim)
            nobj    = pobj.copy;

            if nargin == 1
                nobj    = nobj.rad.genericmath('unwrap',@(x,d)unwrap(x,[],d),[],1,false).deg;
            else
                nobj    = nobj.rad.genericmath('unwrap',@(x,d)unwrap(x,[],d),[],dim,false).deg;
            end
        end
        
        function nobj = unwrap(pobj,dim)
            nobj    = pobj.copy;
            if nargin == 1
                nobj    = nobj.genericmath('unwrap',@(x,d)unwrap(x,[],d),[],1,false);
            else
                nobj    = nobj.genericmath('unwrap',@(x,d)unwrap(x,[],d),[],dim,false);
            end
        end
        
        function nobj = circshift(pobj,K,dim)
            nobj    = pobj.copy;
            if nargin == 2
                nobj    = nobj.genericmath('circshift',@(x,d)circshift(x,K,d),[],1,false);
            else
                nobj    = nobj.genericmath('circshift',@(x,d)circshift(x,K,d),[],dim,false);
            end
        end
        
        function nobj = var(pobj,dim,varargin)
            nobj    = pobj.copy;
            if nargin == 1
                dim = 1;
            end
            nobj    = nobj.genericmath('var',@(x,d)var(x,1,d,'includenan'),[],dim,true,varargin{:});
        end

        function nobj = nanvar(pobj,dim,varargin)
            nobj    = pobj.copy;
            if nargin == 1
                dim = 1;
            end
            nobj    = nobj.genericmath('var',@(x,d)var(x,1,d,'omitnan'),[],dim,true,varargin{:});
        end

        function nobj = rms(pobj,dim,varargin)
            nobj    = pobj.copy;
            if nargin == 1
                dim = 1;
            end
            nobj    = nobj.genericmath('rms',@(x,d)PData3.rms_(x,d),[],dim,true,varargin{:});
        end

        function nobj = sum(pobj,dim,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmath('sum',@(x,d)sum(x,d),[],dim,false,varargin{:});
        end

        function nobj = nansum(pobj,dim,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmath('sum',@(x,d)nansum(x,d),[],dim,false,varargin{:});
        end

        function nobj = mean(pobj,dim,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmath('mean',@(x,d)mean(x,d),@(x,d)std(x,0,d),dim,false,varargin{:});
        end

        function nobj = nanmean(obj,dim,varargin)
            nobj = obj.genericmath('mean',@(x,d)nanmean(x,d),@(x,d)nanstd(x,0,d),dim,false,varargin{:});
        end

%% Math functions over a certain dimension specified by name

        function nobj = rmsover(pobj,over,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmathover('rms',@(x,d)PData3.rms_(x,d),[],over,true,varargin{:});
        end
        
        function nobj = unwrapover(pobj,over,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmathover('unwrap',@(x,d)unwrap(x,[],d),[],over,false,varargin{:});
        end
        
        function nobj = dunwrapover(pobj,over,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmathover('unwrap',@(x,d)unwrap(x*pi/180,[],d),[],over,false,varargin{:}).deg;
        end
        
        function nobj = circshiftover(pobj,over,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmathover('circshift',@(x,d)circshift(x,varargin{1},d),[],over,false);
        end
        
        function nobj = stdover(pobj,over,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmathover('std',@(x,d)std(x,0,d),[],over,true,varargin{:});
        end

        function nobj = varover(pobj,over,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmathover('var',@(x,d)var(x,1,d),[],over,true,varargin{:});
        end

        function nobj = nanvarover(pobj,over,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmathover('var',@(x,d)var(x,0,d,'omitnan'),[],over,true,varargin{:});
        end

        function nobj = maxover(pobj,over,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmathover('max',@(x,d)max(x,[],d),[],over,true,varargin{:});
        end

        function nobj = nanmaxover(pobj,over,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmathover('max',@(x,d)nanmax(x,[],d),[],over,true,varargin{:});
        end
        
        function nobj = minover(pobj,over,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmathover('min',@(x,d)min(x,[],d),[],over,true,varargin{:});
        end

        function nobj = nanminover(pobj,over,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmathover('min',@nanmin,[],over,true,varargin{:});
        end

        function nobj = sumover(pobj,over,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmathover('sum',@sum,[],over,true,varargin{:});
        end

        function nobj = nansumover(pobj,over,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmathover('sum',@nansum,[],over,true,varargin{:});
        end

        function nobj = mo(pobj,over,varargin)
            nobj    = pobj.meanover(over,varargin{:});
        end
        
        function nobj = nmo(pobj,over,varargin)
            nobj    = pobj.nanmeanover(over,varargin{:});
        end
        
        function nobj = meanover(pobj,over,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericmathover('mean',@mean,@(x,d)std(x,1,d),over,true,varargin{:});
        end
        
        
%         function nobj = diffover(pobj,over,varargin)
%             nobj    = pobj.copy;
%             nobj    = nobj.genericmathover('diff',@(x,d)diff(x,1,d),[],over,true,varargin{:});
%         end

        function nobj = nanmeanover(obj,over,varargin)
            nobj = obj.genericmathover('mean',@nanmean,@(x,d)nanstd(x,1,d),over,true,varargin{:});
        end

        function nobj = cumtrapzover(pobj,over,varargin)
            nobj    = pobj.copy;
            nobj    = nobj.genericxymathover('cumtrapz',@(x,y,d)cumtrapz(x,y,d),over,varargin{:});
        end
        
        function nobj = psd(pobj,varargin)
            nobj    = pobj.copy;
            
            dt      = mean(diff(pobj.x));
            N       = nobj.fft.lengthY;
            
            nobj    = nobj.fft.abs.power(2) .* dt ./ 2 ./ pi ./ N;
            nobj.myName  = ['psd(' pobj.myName ')'];
            nobj.checkdimensions();
        end
        
%% Selection functions

        function nobj = sw(obj,where,varargin)
            nobj = selectwhere(obj,where,varargin{:});
        end
        
        function nobj = selectwhere(obj,where,cond)
            
            keepField = strcmp(where(end),'*');
            if keepField
                where = where(1:(end-1));
            end
            
            assert(~strcmpi(where,'x'),'You can''t use conditional selection on ''x''.');
            sdim    = find(strcmpi(where,obj.fNames));
            assert(~isempty(sdim),'The field %s does not exist in these results.',where);
            nobj    = obj.copy;
            
            if isnumeric(cond)
                if length(unique(cond)) ~= length(cond)
                    tab = tabulate(cond);
                    error('You specified field(s) ''%s\b\b'' more than once, this is not allowed.',sprintf('%1.3f, ',tab(tab(:,2) > 1,1)))
                end
                
                if iscell(obj.fValues{sdim})
                    sel         = find(cellfun(@(x)isequal(x,cond),obj.fValues{sdim}));
                else
                    [~,sel,~]   = intersect(obj.fValues{sdim},cond);
                end                
            elseif ischar(cond)
                sel             = find(strcmp(cond,obj.fLabels{sdim}));
            elseif iscell(cond)
                [~,~,sel]       = intersect(cond,obj.fLabels{sdim},'stable');
            else
                error('Ha! You didn''t think of %ss, huh?!',class(cond));
            end
            
            if isempty(sel) || (~ischar(cond) && length(sel) ~= length(cond) && ~iscell(obj.fValues{sdim}))                
                if isnumeric(cond)
                    notAvailable    = cond(arrayfun(@(x)~any(sel == x),cond));
                    error('There are no results (or not all could be selected) for field ''%s'' equal to %s\b\b.',where,sprintf('%1.3f, ',notAvailable));
                elseif ischar(cond)
                    error('There are no results for field ''%s'' equal to %s. Available options are:\n%s',where,cond,sprintf('\t- %s\n',obj.fLabels{sdim}{:}));
                elseif iscell(cond)
                    notAvailable    = cond(cellfun(@(x)~any(strcmp(x,obj.fLabels{sdim}(sel))),cond));
                    error('There are no results for field ''%s'' equal to ''%s\b\b''. Available options for field ''%s'' are:\n%s',...
                        where,sprintf('%s, ',notAvailable{:}),where,sprintf('\t- %s\n',obj.fLabels{sdim}{:}));
                else
                    error('There are no results for %s equal to that thing you entered.',where,cond);
                end
            end
            
            nobj.y      = nobj.selectFromDim(nobj.y,sdim,sel,keepField);
            if ~isempty(nobj.stdv)
                nobj.stdv   = nobj.selectFromDim(nobj.stdv,sdim,sel,keepField);
            end
            
            if length(sel) == 1 && ~keepField
                if length(nobj.fLabels) == length(nobj.fNames)
                    nobj.fLabels(sdim) = [];
                elseif ~isempty(nobj.fLabels)
                    error('Something weird here.')
                end
                nobj.fNames(sdim)  = [];
                nobj.fValues(sdim) = [];
            else
                nobj.fValues{sdim} = nobj.fValues{sdim}(sel);
                nobj.fLabels{sdim} = nobj.fLabels{sdim}(sel);
            end
            
            nobj.checkdimensions();
        end
        
        function nobj = so(obj,over,varargin)
            nobj = selectover(obj,over,varargin{:});
        end
        
        function nobj = at(obj,sel)
            nobj = obj.selectover('x',1,sel);
        end

        function nobj = selectover(obj,over,varargin)
            nobj    = obj.copy;

            if strcmpi(over,'x')
                if length(varargin) ~= 2
                    error('If you want to select over x, you should provide 3 arguments in total (''x'', dim, sel).')
                end
                sel         = varargin{2};
                xdim        = varargin{1};
                sdim        = length(obj.fNames) + xdim;
            else
                sdim    = find(strcmpi(over,obj.fNames));
                if length(varargin) ~= 1
                    error('If you want to select over a functional dimension, you should provide 2 arguments in total (''fnc'', sel).')
                end
                sel     = varargin{1};
            end

            if isempty(nobj.stdv)
                nobj.stdv = zeros(size(nobj.y));
            end
            
            nobj.y      = nobj.selectFromDim(nobj.y,sdim,sel,false);
            nobj.stdv   = nobj.selectFromDim(nobj.stdv,sdim,sel,false);


            if ~strcmpi(over,'x')
                if length(sel) == 1
                    nobj.fNames(sdim)  = [];
                    nobj.fValues(sdim) = [];
                    nobj.fLabels(sdim) = [];
                else
                    nobj.fValues{sdim} = nobj.fValues{sdim}(sel);
                    nobj.fLabels{sdim} = nobj.fLabels{sdim}(sel);
                end
            else
                nobj.x  = nobj.selectFromDim(nobj.x,xdim,sel,false);
            end

            nobj.checkdimensions();
        end

%% Check

        

%% Plotting functions

        function h = plotter(obj,fhandle,x,y,varargin)
            % Check whether the x and y data are of the same dimensions. If
            % not, it probably means the y data was averaged over x and the
            % new x data was not correctly set yet.

            if ndims(x) ~= ndims(y)
                error('The x and y data do not belong together.')
            end

            if all(iscell(x))
                xlbl    = x;
                x       = 1:length(x);
            end
            
            [z,unm] = obj.parseGrayScalePlotInput(varargin{:});
            
            if isempty(z.LineSpec)
                if ~isempty(fieldnames(unm))
                    if isfield(unm,'DisplayName')
                        h = fhandle(z.Axis,x,y,unm);
                    elseif ~isempty(z.myName)
                        h = fhandle(z.Axis,x,y,unm,'DisplayName',z.myName);
                    else
                        h = fhandle(z.Axis,x,y,unm);
                    end
                else
                    if ~isempty(z.myName)
                        h = fhandle(z.Axis,x,y,'DisplayName',z.myName);
                    else
                        h = fhandle(z.Axis,x,y);
                    end
                end
            else
                if ~isempty(fieldnames(unm))
                    if isfield(unm,'DisplayName')
                        h = fhandle(z.Axis,x,y,z.LineSpec,unm);
                    elseif ~isempty(z.myName)
                        h = fhandle(z.Axis,x,y,z.LineSpec,unm,'DisplayName',z.myName);
                    else
                        h = fhandle(z.Axis,x,y,z.LineSpec,unm);
                    end
                else
                    if ~isempty(z.myName)
                        h = fhandle(z.Axis,x,y,z.LineSpec,'DisplayName',z.myName);
                    else
                        h = fhandle(z.Axis,x,y,z.LineSpec);
                    end
                end
            end
            h = obj.setGrayScaleProperties(h,z);
            
            if z.setXLim
                if strcmpi(z.Axis.XLimMode,'auto')
                    myxlim = [min(x(:)) max(x(:))];
                    if all(diff(myxlim) == 0)
                        myxlim = [myxlim(1)-1 myxlim(1)+1];
                    end
                    xlim(z.Axis,myxlim);
                elseif strcmpi(z.Axis.XLimMode,'manual')
                    xlim(z.Axis,[min([x(:);z.Axis.XLim(1)]) max([x(:); z.Axis.XLim(2)])]);
                end
            end
            
            if z.setYLim
                yL      = [min(real(double(y(:)))) max(real(double(y(:))))];
                if yL(1) == yL(2)
                    if isinf(yL(1))
                        yL = [-1 1];
                    else
                        yL(1)   = yL(1) - 1;
                        yL(2)   = yL(2) + 1;
                    end
                else
                    if strcmp(z.Axis.YScale,'linear')
                        yL(1)   = yL(1) - abs(yL(1) - yL(2)) * 0.1;
                        yL(2)   = yL(2) + abs(yL(1) - yL(2)) * 0.1;
                    elseif strcmp(z.Axis.YScale,'log')
                        yL(1)   = yL(1) * 0.1;
                        yL(2)   = yL(2) * 10;
                    end
                end
                
                if strcmpi(z.Axis.YLimMode,'auto')                    
                    ylim(z.Axis,yL);
                elseif strcmpi(z.Axis.YLimMode,'manual')
                    ylim(z.Axis,[min([yL(1) z.Axis.YLim(1)]) max([yL(2) z.Axis.YLim(2)])]);
                end
            end
            
            drawnow;            
            dc = datacursormode(gcf);
            set(dc,'UpdateFcn',@FCursor)
            
            if exist('xlbl','var')
                set(z.Axis,'XTick',x);
                set(z.Axis,'XTickLabel',xlbl)
            end
        end

%         function varargout = confidenceInterval(obj,varargin)
% 
%             assert(any(strcmp('subject',obj.fNames)),'At least one of the functionals should be called ''subject''.');
%             assert(length(obj.fNames) < 3,'This function works with two functionals maximum. You have %i:\n%s.',length(obj.fNames),sprintf('- %s\n',obj.fNames{:}));
%             
%             if length(obj.fNames) == 2
%                 subjectF    = find(strcmp(obj.fNames,'subject'));
%                 if subjectF == 1
%                     otherF          = 2;
%                     yt              = squeeze(obj.y).';
%                     xt              = obj.fValues{2};
%                 else
%                     otherF          = 1;
%                     yt              = squeeze(obj.y);
%                     xt              = obj.fValues{1};
%                 end
%                 
%                 assert(strcmp(obj.fNames{otherF},obj.xAxis),'You should explicitly set the horizontal axis to ''%s''.',obj.fNames{otherF});
%             elseif length(obj.fNames) == 1
%                 assert(isvector(obj.x),'The x data should be a vector.');
%                 yt              = squeeze(obj.y).';
%                 xt              = obj.x;
%             else
%                 error('Huh?');               
%             end
% 
%             if ~isempty(yt)
%                 % CONFIDENCE1D  Calculate the 95% confidence intervals corrected for
%                 % between-subject variance.
%                 %
%                 %     CONFIDENCE1D(data) with data an [M,N] matrix with N = number of
%                 %     subjects and M = number of conditions.
% 
%                 subject_mean        = nanmean(yt,1);
%                 grand_mean          = nanmean(subject_mean,2);
% 
%                 adjustment_factor   = grand_mean * ones(size(subject_mean)) - subject_mean;
%                 adjusted_data       = yt + ones(size(yt,1),1) * adjustment_factor;
% 
%                 zTable =    [2 4.3;
%                              3 3.18;
%                              4 2.78;
%                              5 2.57;
%                              6 2.45;
%                              7 2.36;
%                              8 2.31;
%                              9 2.26;
%                              10 2.23;
%                              11 2.2;
%                              12 2.18;
%                              13 2.16;
%                              14 2.14;
%                              15 2.13;
%                              16 2.12;
%                              30 2.04;
%                              90 1.99;
%                              400 1.97];
% 
%                 zv = interp1(zTable(:,1),zTable(:,2),size(yt,2)-1,'linear');
%                 
%                 
%                 
%                 if nargout < 2 
%                     if any(iscell(xt))
%                         set(gca,'XTick',1:length(xt));
%                         set(gca,'XTickLabel',xt);
%                         xlim([0 length(xt)+1])
%                     else
%                         xlim([min(xt) max(xt)])
%                     end
%                     
%                     [z,unm] = obj.parseGrayScalePlotInput(varargin{:});
%                 
%                     h = errorbar(xt,...
%                                  nanmean(adjusted_data,2),...
%                                  zv*nanstd(adjusted_data,[],2)./sqrt(size(yt,2)),...
%                                  zv*nanstd(adjusted_data,[],2)./sqrt(size(yt,2)),...
%                                  z.LineSpec); hold on
% 
%                     flds = fieldnames(unm);
%                     for oo=1:length(flds)
%                         h.(flds{oo}) = unm.(flds{oo});
%                     end
%                     h = obj.setGrayScaleProperties(h,z);
%                 
%                     if nargout == 1
%                         varargout{1} = h;
%                     end
%                 elseif nargout == 3
%                     varargout{1} = xt;
%                     varargout{2} = nanmean(adjusted_data,2);
%                     varargout{3} = zv*nanstd(adjusted_data,[],2)./sqrt(size(yt,2));
%                 end
%             end
%         end
        
        function h = varline(obj,varargin)
            [z,unm] = obj.parsePlotInput(varargin{:});
            h = obj.plot(z.LineSpec,unm); hold on
            
            nobj    = obj.copy;
            nobj.y  = nobj.y + nobj.stdv;
            nobj.plot(z.pos{:});
            
            nobj    = obj.copy;
            nobj.y  = nobj.y - nobj.stdv;
            
            if isempty(z.neg)
                nobj.plot(z.pos{:});
            else
                nobj.plot(z.neg{:}); hold on
            end
        end

        function h = errorbar(obj,varargin)
            [z,unm1]    = obj.parseGrayScalePlotInput(varargin{:});
            [z2,unm2]   = obj.parsePlotInput(z.LineSpec,unm1);
            
            if isempty(obj.stdv)
                error('There is no variance information available for the errorbar.');
            end
            
            if ~isempty(z2.atIndex)
                tx = getXData(obj);
                ty = obj.y;
                te = obj.stdv;
                z2.atIndex = z2.atIndex(z2.atIndex < length(tx) & z2.atIndex > 0);
                
                tx = tx(z2.atIndex);
                ty = ty(z2.atIndex);
                te = te(z2.atIndex);
            else
                tx = getXData(obj);
                ty = obj.y;
                te = obj.stdv;
            end
            
            h = errorbar(tx,...
                         ty,...
                         te,...
                         te,...
                         z.LineSpec); hold on
            flds = fieldnames(unm2);
            for oo=1:length(flds)
                h.(flds{oo}) = unm2.(flds{oo});
            end
            h = obj.setGrayScaleProperties(h,z);
        end

        function h = errorbar_var(obj,varargin)
            h = errorbar(getXData(obj),obj.y,...
                             obj.stdv.^2,...
                             obj.stdv.^2,...
                             varargin{:}); hold on
        end

        function h = plotStdv(obj,varargin)

            forcex = 0;
            if any(strcmpi(varargin,'forcex'))
                i = find(strcmpi(varargin,'forcex'),1,'first');
                varargin = {varargin{((1:length(varargin)) ~= i)}};
                forcex = 1;
            end

            offset = 0;
            if any(strcmpi(varargin,'offset'))
                i = find(strcmpi(varargin,'offset'),1,'first');
                offset = varargin{i+1};
                varargin = {varargin{((1:length(varargin)) ~= i & (1:length(varargin)) ~= i+1)}};
            end

            if ~isempty(obj.stdv)
                if ~isempty(getXData(obj)) && ~forcex
                    if iscell(getXData(obj))
                        h=errorbar( (1:size(obj.y,1))+offset,obj.y,...
                                    obj.stdv,...
                                    obj.stdv,...
                                    varargin{:});

                        set(gca,'XTick',(1:length(obj.f)))
                        set(gca,'XTickLabel',obj.f);
                    else
                        h=errorbar( getXData(obj)+offset,obj.y,...
                                    obj.stdv,...
                                    obj.stdv,...
                                    varargin{:});
                    end
                end
            end
        end

        function h = yboundary(obj,varargin)
            xL  = xlim;
            h   = obj.plotter(@plot,[-1e15 1e15],[obj.y(1) obj.y(1)],varargin{:});
            set(h,'Tag','Line');
            xlim(xL);
        end

        function h = msinefreq(obj,varargin)
            xL      = xlim;
            yL      = ylim;
            idx     = find(abs([obj.y]) > (max(abs([obj.y])) * 1e-6));

            for oo=1:length(idx)
                if strcmpi(get(gca,'YScale'),'log')
                    h   = obj.plotter(@plot,[abs(obj.x(idx(oo))) abs(obj.x(idx(oo)))],...
                                             [1e-15 1e15],varargin{:});
                else
                    h   = obj.plotter(@plot,[abs(obj.x(idx(oo))) abs(obj.x(idx(oo)))],...
                                             [-1e15 1e15],varargin{:});
                end
            end

            set(h,'Tag','Line');
            xlim(xL);
            ylim(yL);
        end

        
        
        function h = plot(obj,varargin)
            if ~isempty(obj.myName)
                h = obj.plotter(@plot,getXData(obj),obj.y,varargin{:},'myName',obj.subscriptUnderscore(obj.myName));
            else
                h = obj.plotter(@plot,getXData(obj),obj.y,varargin{:});
            end
            
            if nargout == 0
                clear h
            end
        end

        function h = scatter(obj,varargin)
            h = obj.plotter(@scatter,getXData(obj),obj.y,varargin{:});
            set(h,'Tag','Scatter');
        end

        function h = loglog(obj,varargin)
            h = obj.plotter(@loglog,getXData(obj),obj.y,varargin{:});
            set(h,'Tag','Line');
            if nargout == 0
                clear h
            end
        end

        function h = semilogx(obj,varargin)
            if ~isempty(obj.myName)
                h = obj.plotter(@semilogx,getXData(obj),obj.y,varargin{:},'myName',obj.subscriptUnderscore(obj.myName));
            else
                h = obj.plotter(@semilogx,getXData(obj),obj.y,varargin{:});
            end
            
            if nargout == 0
                clear h
            end
        end

        function h = semilogy(obj,varargin)
            h = obj.plotter(@semilogy,getXData(obj),obj.y,varargin{:});
            set(h,'Tag','Line');
            if nargout == 0
                clear h
            end
        end
        
        function x = getf(obj,field)
            prexAxis = obj.xAxis;
            x = squeeze(obj.ha(field).getXData());
            obj.xAxis = prexAxis;
        end

        function ha_d = getXData(obj)
            if strcmpi(obj.xAxis,'x') || isempty(obj.xAxis)
                ha_d = obj.x;
            else
                ha = strcmpi(obj.fNames,obj.xAxis);
                if any(ha)
                    ha_d    = obj.fValues{ha};
                else
                    error('You did not provide a valid name to set as x axis!');
                end
            end
        end
        
        function ha_d = getYData(obj)
            if strcmpi(obj.yAxis,'y') || isempty(obj.yAxis)
                ha_d = obj.y;
            else
                ha = strcmpi(obj.fNames,obj.yAxis);
                if any(ha)
                    ha_d    = obj.fValues{ha};
                else
                    error('You did not provide a valid name to set as y axis!');
                end
            end
        end

        function nobj = freqresp(obj,varargin)
            
            p = inputParser;
            p.CaseSensitive     = true;
            p.KeepUnmatched     = true;            
            addParameter(p,'which',[],@isnumeric);
            addParameter(p,'w',logspace(-1,2,98)',@(x)(all(isnumeric(x)) & iscolumn(x)));
            addParameter(p,'noresponse',@zeros,@(x)isa(x,'function_handle'));
            parse(p,varargin{:});
            
            z       = p.Results;
            nobj    = obj.copy;
            
            if iscell(obj.y)
                [~,nri] = size(obj.y{1});
            else
                [~,nri] = size(obj.y);
            end
            
            if isempty(z.which)
                z.which = 1:nri;
            end
            nri     = length(z.which);            
            newy    = zeros([size(obj.y) length(z.w) nri]);
            
            for oo=1:numel(obj.y)
                if iscell(obj.y)
                    H   = obj.y{oo};
                else
                    H   = obj.y;
                end

                assert(isa(H,'idpoly') || isa(H,'tf') || isa(H,'ss'),'This works only for idpoly, ss, or tf objects.');
                
                Hp_arx      = zeros([length(z.w) nri]);
                H_tauCor    = ones([length(z.w) nri]);
                
                for uu=1:length(z.which)
                    if isfield(H.UserData,'tau_iSignals')
                        if ~isempty(H.UserData.tau_iSignals)
                            H_tauCor(:,uu) = exp(-H.UserData.tau_iSignals(z.which(uu)) .* 1i .* z.w);
                        end
                    end
                    Hp_arx(:,uu) = squeeze(freqresp(H(z.which(uu)),z.w));

                    if all(Hp_arx(:,uu) == 0)
                        Hp_arx(:,uu) = z.noresponse(size(z.w));
                    end
                end
                Hp_arx = Hp_arx .* H_tauCor;
                newy(oo,:)  = Hp_arx(:); 
            end
            
            nobj.x  = squeeze(repmat(z.w,1,nri));
            nobj.y  = squeeze(newy);
            nobj.checkdimensions();
            
        end
        
        
        function [plotHandleOrMagAxis,PhaseAxis] = bode(obj,varargin)
            [z,unm]     = obj.parsePlotInput(varargin{:});
            
            if iscell(obj.y)
                if length(obj.y) > 1
                    error('Boo!');
                else
                    H   = obj.y{1};
                end
            else
                H   = obj.y;
            end
            
            
            
            if isa(H,'idpoly') || isa(H,'tf') || isa(H,'ss')
                H_tauCor    = ones(size(z.w));
                
                if isfield(H.UserData,'tau_iSignals')
                    if ~isempty(H.UserData.tau_iSignals)
                        H_tauCor    = exp(-H.UserData.tau_iSignals(z.which) .* 1i .* z.w);
                    end
                end

                if isa(H,'idpoly') && (~isempty(z.pos) || ~isempty(z.neg))
                    [Hp_arx,~,Hcov]     = freqresp(H(z.which),z.w);
                    Hp                  = squeeze(Hp_arx);
                    bodex               = z.w;

                    % Determine standard deviations of magnitude and phase
                    C1 = squeeze(Hcov(:,:,:,1,1));
                    C2 = squeeze(Hcov(:,:,:,2,2));
                    C3 = squeeze(Hcov(:,:,:,1,2));

                    sdm     =     real(sqrt((real(Hp).^2).*C1 + 2*((real(Hp)).*(imag(Hp))).*C3 + (imag(Hp).^2).*C2))./abs(Hp);
                    sdp     = (180/pi)*sqrt((imag(Hp).^2).*C1 - 2*((real(Hp)).*imag(Hp))  .*C3 + (real(Hp).^2).*C2) ./(abs(Hp).^2);
                else
                    Hp_arx  = freqresp(H(z.which),z.w);
                    Hp      = squeeze(Hp_arx);
                    bodex   = z.w;
                end
            else
                if iscolumn(obj.x)
                    Hp      = H(:,z.which);
                    bodex   = obj.x(:,z.which);
                elseif isrow(obj.x)
                    Hp      = H(z.which,:);
                    bodex   = obj.x(z.which,:);
                elseif ismatrix(obj.x)
                    Hp      = H(:,z.which);
                    bodex   = obj.x(:,z.which);
                end
                H_tauCor    = ones(size(bodex));
            end
            
            Hp          = squeeze(Hp) .* H_tauCor;            
            Hp_abs      = abs(Hp);
            if z.unwrap
                Hp_angle    = (180/pi)*unwrap(angle(Hp));
            else
                Hp_angle    = (180/pi)*angle(Hp);
            end
            
            if ~isempty(z.phaseStartAt)
                if isempty(z.phaseStartIdx)
                    z.phaseStartIdx = 1;
                end
                Hp_angle    = Hp_angle + round((z.phaseStartAt - Hp_angle(z.phaseStartIdx))/45)*45;
            end
            
            if ~isempty(z.neg)
                negative                = Hp_abs-3*sdm;
                negative(negative < 0)  = NaN;
            end
            
            if z.magnitude && z.phase
                if isempty(z.magAxis) && isempty(z.phaseAxis)
                    z.magAxis       = subplot(2,1,1);
                    z.phaseAxis     = subplot(2,1,2);
                elseif (~isempty(z.magAxis) && isempty(z.phaseAxis)) || (isempty(z.magAxis) && ~isempty(z.phaseAxis))
                    error('You have to specify magAxis and phaseAxis together.');
                end
            elseif z.magnitude && ~z.phase
                if isempty(z.magAxis)
                    z.magAxis = subplot(1,1,1);
                end
            elseif z.phase && ~z.magnitude
                if isempty(z.phaseAxis)
                    z.phaseAxis = subplot(1,1,1);
                end
            else
                error('Well, we want to plot at least one thing, don''t we?');
            end
            
            
            if ~isempty(obj.myName)
                if (z.phase)
                    obj.plotter(@semilogx,bodex,Hp_angle,z.LineSpec,'Axis',z.phaseAxis,'setYLim',false,'myName',obj.subscriptUnderscore(obj.myName),unm);
                end
                
                if (z.magnitude)
                    ph = obj.plotter(@loglog,bodex,Hp_abs,z.LineSpec,'Axis',z.magAxis,'setYLim',false,'myName',obj.subscriptUnderscore(obj.myName),unm);
                end
                
                if ~isempty(z.pos)
                    obj.plotter(@loglog,bodex,Hp_abs+3*sdm,z.pos{:},'Axis',z.magAxis,'setYLim',false,'myName',obj.subscriptUnderscore(obj.myName),unm);
                    obj.plotter(@semilogx,bodex,Hp_angle + sdp,z.pos{:},'Axis',z.phaseAxis,'setYLim',false,'myName',obj.subscriptUnderscore(obj.myName),unm);
                end
                
                if ~isempty(z.neg)
                    obj.plotter(@loglog,bodex,negative,z.neg{:},'Axis',z.magAxis,'setYLim',false,'myName',obj.subscriptUnderscore(obj.myName),unm);
                    obj.plotter(@semilogx,bodex,Hp_angle - sdp,z.neg{:},'Axis',z.phaseAxis,'setYLim',false,'myName',obj.subscriptUnderscore(obj.myName),unm);
                end
            else
                if (z.phase)
                    obj.plotter(@semilogx,bodex,Hp_angle,z.LineSpec,'Axis',z.phaseAxis,'setYLim',false,unm);
                end
                
                if z.magnitude
                    ph = obj.plotter(@loglog,bodex,Hp_abs,z.LineSpec,'Axis',z.magAxis,'setYLim',false,unm);                
                end 
                     
                if ~isempty(z.pos)
                    obj.plotter(@loglog,bodex,Hp_abs+3*sdm,z.pos{:},'Axis',z.magAxis,'setYLim',false,unm);
                    obj.plotter(@semilogx,bodex,Hp_angle + sdp,z.pos{:},'Axis',z.phaseAxis,'setYLim',false,unm);
                end
                if ~isempty(z.neg)
                    obj.plotter(@loglog,bodex,negative,z.neg{:},'Axis',z.magAxis,'setYLim',false,unm);
                    obj.plotter(@semilogx,bodex,Hp_angle - sdp,z.neg{:},'Axis',z.phaseAxis,'setYLim',false,unm);
                end
            end
            
            if z.magnitude
                xlabel(z.magAxis,'$\omega$, rad/s','interpreter','latex');
                ylabel(z.magAxis,'Magnitude, -');
            end
            
            if z.phase
                xlabel(z.phaseAxis,'$\omega$, rad/s','interpreter','latex');
                ylabel(z.phaseAxis,'Phase, deg');
                set(z.phaseAxis,'YTick',-9000:90:9000)
                ylim(z.phaseAxis,[-360 180])
            end
            
            if nargout == 1
                plotHandleOrMagAxis     = ph;
            elseif nargout == 2
                plotHandleOrMagAxis     = z.magAxis;
                PhaseAxis               = z.phaseAxis;
            end
        end

        function h = nyquist(obj,varargin)

            if iscell(obj.y)
                if isa(obj.y{1},'idpoly')

                    Y       = obj.y{1};

                    if size(Y,2) >= 1 && size(Y,1) == 1
                        w   = logspace(-1,2,100)';

                        for oo=1:size(Y,2)
                            Hp = squeeze(freqresp(Y(1,oo),w));

                            h = obj.plotter(@plot,real(Hp),imag(Hp),varargin{:}); hold on
                            xlabel('Real, -');
                            ylabel('Imag, -');
                            set(h,'Tag','Line');
                            xlim([w(1) w(end)])
                            drawnow;
                        end

                    elseif size(obj.y,1) > 1 && size(obj.y,2) > 1
                        error('MIMO models are not supported.');
                    end
                else
                    error('Something went wrong?');
                end
            else
                h = obj.plotter(@plot,real(obj.y),imag(obj.y),varargin{:}); hold on
            end
        end

        function h = hbode(PDataobj,varargin)
            subplot(1,2,1)
                h = plotmag(PDataobj,varargin{:});  hold on
            subplot(1,2,2)
                plotphase(PDataobj,varargin{:});  hold on
        end

        function h = fixbode(PDataobj,fllim,fulim,shift,varargin)

            if iscell(PDataobj.y)
                if isa(PDataobj.y{1},'idpoly')

                    Y       = PDataobj.y{1};

                    if size(Y,2) >= 1 && size(Y,1) == 1
                        w   = logspace(-1,2,100)';

                        for oo=1:size(Y,2)
                            Hp = squeeze(freqresp(Y(1,oo),w));

                            subplot(2,size(Y,2),oo)
                                h = PDataobj.plotter(@loglog,w,abs(Hp),varargin{:}); hold on
                                xlabel('$\omega$, rad/s');
                                ylabel('Magnitude, -');
                                set(h,'Tag','Line');
                                xlim([w(1) w(end)])

                            subplot(2,size(Y,2),oo+size(Y,2))
                                if (180/pi)*unwrap(angle(Hp(1))) < fllim && (180/pi)*unwrap(angle(Hp(1))) > fulim
                                    PDataobj.plotter(@semilogx,w,(180/pi)*unwrap(angle(Hp))+shift,varargin{:}); hold on
    %                                     fprintf('Hai!\n')
                                else
                                    PDataobj.plotter(@semilogx,w,(180/pi)*unwrap(angle(Hp)),varargin{:}); hold on
                                end
                                xlabel('$\omega$, rad/s');
                                ylabel('Phase, deg');
                                set(gca,'YTick',-9000:90:9000)
                                ylim([-360 180])
                                xlim([w(1) w(end)])
                                set(h,'Tag','Line');
                                drawnow;
                        end

                    elseif size(PDataobj.y,1) > 1 && size(PDataobj.y,2) > 1
                        error('MIMO models are not supported.');
                    end
                else
                    error('Something went wrong?');
                end
            else
                subplot(2,1,1)
                    h = plotmag(PDataobj,varargin{:});  hold on
                subplot(2,1,2)
                    plotphase(PDataobj,varargin{:});  hold on
            end
        end
        
        function [nobj,idx] = peaks(obj,varargin)
            nobj        = obj.copy;
            px          = obj.x;
            py          = abs(obj.y);
            minY        = log10(min(py(py > 0 & py < Inf)));
            maxY        = log10(max(py(py > 0 & py < Inf)));
            cutoff      = minY + (maxY-minY)*0.5;
            idx         = py > 10^cutoff;
            nobj.x      = obj.x(idx);
            nobj.y      = obj.y(idx);
            idx         = find(idx);
        end

        function h = plotmag(obj,varargin)
            [z,unm] = obj.parsePlotInput(varargin{:});
            
            px      = obj.x;
            py      = abs(obj.y);
            
            idx     = 1:length(px);
            
            if z.multisinePeaks
                minY        = log10(min(py(py > 0 & py < Inf)));
                maxY        = log10(max(py(py > 0 & py < Inf)));
                cutoff      = mean([minY maxY]);
                idx         = py > 10^cutoff;
            end
            
            if ~isempty(z.atIndex)
                idx         = z.atIndex;
            end
            
            px          = px(idx);
            py          = py(idx);
            
            h = obj.plotter(@loglog,px,py,z.LineSpec,unm,'setYLim',false);

            xlabel('$\omega$, rad/s');
            ylabel('Magnitude, -');
            set(h,'Tag','Line');
        end

        function h = plotmagdB(PDataobj,varargin)
            [z,unm] = PDataobj.parsePlotInput(varargin{:});
            h = PDataobj.plotter(@semilogx,PDataobj.x,20*log10(abs(PDataobj.y)),z.LineSpec,unm);

            xlabel('$\omega$, rad/s');
            ylabel('Magnitude, dB');
            set(h,'Tag','Line');
        end
        
        function h = plotphase(PDataobj,varargin)
            [z,unm] = PDataobj.parsePlotInput(varargin{:});
            
            px      = PDataobj.x;
            pyA     = abs(PDataobj.y);
            pyP     = angle(PDataobj.y);
                
            if z.multisinePeaks
                minY    = log10(min(pyA(pyA > 0 & pyA < Inf)));
                maxY    = log10(max(pyA(pyA > 0 & pyA < Inf)));
                cutoff  = mean([minY maxY]);
                idx     = pyA > 10^cutoff;
            else
                idx     = 1:length(px);
            end
            
            if ~isempty(z.atIndex)
                idx         = z.atIndex;
            end
            
            px      = px(idx);
            pyP     = pyP(idx);
            
            if z.unwrap
                h = PDataobj.plotter(@semilogx,px,(180/pi)*unwrap(pyP),z.LineSpec,unm);
            else
                h = PDataobj.plotter(@semilogx,px,(180/pi)*pyP,z.LineSpec,unm);
            end
            
            xlabel('$\omega$, rad/s');
            ylabel('Phase, deg');
            set(gca,'YTick',-9000:90:9000)
        end
        
        function h = hline(hx,obj,varargin)
            [z,unm]     = obj.parsePlotInput(varargin{:});
            
            if numel(obj.y) ~= 1
                error('I can only plot a horizontal line at one y coordinate.')
            end
            
            h=obj.plotter(@plot,hx,obj.y*ones(size(hx)),z.LineSpec,unm);
            
            if nargout == 0
                clear h
            end
        end
        
        function h = vlines(obj,varargin)
            [z,unm]     = obj.parsePlotInput(varargin{:});
            
            for oo=1:numel(obj.x)
                if isempty(z.LineSpec)
                    h=obj.plotter(@plot,[obj.x(oo) obj.x(oo)],[-1e6 1e6],unm);
                else
                    h=obj.plotter(@plot,[obj.x(oo) obj.x(oo)],[-1e6 1e6],z.LineSpec,unm);
                end 
            end
            
            if nargout == 0
                clear h
            end
        end
        
        function h = histbar(obj,varargin)
            [z,unm]     = obj.parsePlotInput(varargin{:});

            tY   = squeeze(obj.y);
            
            if ~ismatrix(tY)
                error('More than two dimensions exist, I cannot produce a histogram from this.');
            end
            
            if strcmp(obj.xAxis,'x')
                assert(length(obj.fNames) == 1,'This is not possible.');
                tY  = tY.';
            else
                assert(length(obj.fNames) == 2,'This is not possible.');
                xDim    = find(strcmp(obj.fNames,obj.xAxis));
                if xDim == 1
                    tY = tY.';
                end
            end
            
            [tCounts,tCenters] = hist(tY,z.bins);
            
            if ~isempty(z.BarStyle)
                if strcmp(z.BarStyle,'stacked')
                    if ~isempty(z.LineSpec)
                        h = bar(getXData(obj),tCounts.',z.BarStyle,z.LineSpec,unm);
                    else
                        h = bar(getXData(obj),tCounts.',z.BarStyle,unm);
                    end
                else
                    if ~isempty(z.LineSpec)
                        h = bar(tCenters,tCounts,z.BarStyle,z.LineSpec,unm);
                    else
                        h = bar(tCenters,tCounts,z.BarStyle,unm);
                    end
                end
            else
                if ~isempty(z.LineSpec)
                    h = bar(tCenters,tCounts,z.LineSpec,unm);
                else
                    h = bar(tCenters,tCounts,unm);
                end
            end
        end

%         function h = mesh(obj,varargin)
%             
%             if strcmp(obj.xAxis,'x')
%                 assert(ismatrix(obj.y));
%                 h = mesh(obj.getXData(),obj.fValues{1},obj.y,varargin{:});
%             else
%                 assert(isscalar(obj.x));
%                 assert(length(obj.fNames) == 2);
%                 
%                 if strcmp(obj.fNames{1},obj.xAxis)
%                     h = mesh(obj.fValues{1},obj.fValues{2},squeeze(obj.y).',varargin{:});
%                     xlabel(obj.fNames{1});
%                     ylabel(obj.fNames{2});
%                 else
%                     h = mesh(obj.fValues{2},obj.fValues{1},squeeze(obj.y),varargin{:});
%                     xlabel(obj.fNames{2});
%                     ylabel(obj.fNames{1});
%                 end
%             end
%         end

%         function [h1,h2] = contour_resample_hatched(obj,level,x0,plotProperties,hatchProperties,varargin)
% 
%             p = inputParser;
%             p.CaseSensitive = true;
%             p.addParameter('interpolate','no');
%             p.addParameter('plotfnc',@plot);
%             p.parse(varargin{:});
%             z = p.Results;
%             
%             if ~iscell(plotProperties) || ~iscell(hatchProperties)
%                 error('You have to specify the plot and hatchline properties as separate cells.');
%             end
% 
%             if length(obj.fValues) == 1
%                 if strcmp(obj.xAxis,obj.fNames{1})
%                     % We want to use one of the function values as
%                     % horizontal axis
%                     x_this  = obj.fValues{1};
%                     y_this  = obj.x;
%                     z_this  = squeeze(obj.y);
%                 elseif strcmp(obj.xAxis,'x')
%                     % The horizontal axis was not explicitly set to a
%                     % function value, so we'll just take the first one to
%                     % be the x data.
%                     x_this  = obj.x;
%                     y_this  = obj.fValues{1};
%                     z_this  = squeeze(obj.y).';
%                 else
%                     error('Something went wrong.');
%                 end
%             elseif length(obj.fValues) == 2
%                 % We assume that we want to use the two function axes for
%                 % the x and y axes, and use the x data to base the contour
%                 % on.
% 
%                 % Now figure out what function we want to use as horizontal
%                 % axis.                
%                 if strcmp(obj.xAxis,obj.fNames{1})
%                     % We want to use one of the function values as
%                     % horizontal axis
%                     x_this  = obj.fValues{1};
%                     y_this  = obj.fValues{2};
%                     z_this  = squeeze(obj.y).';
%                 elseif strcmp(obj.xAxis,obj.fNames{2})
%                     x_this  = obj.fValues{2};
%                     y_this  = obj.fValues{1};
%                     z_this  = squeeze(obj.y);
%                 else
%                     error('Something went wrong.');
%                 end
%             end
% 
%             if size(z_this,2) == length(x_this) && size(z_this,1) == length(y_this)
%                 if length(level) == 1 && all(level == 1)
%                     lvl     = [level level];
%                 else
%                     lvl     = level;                    
%                 end
%                 
%                 C   = contourc(x_this,y_this,z_this,lvl);
%                 
%                 if isempty(C)
%                     error('There is no contour at this level.')
%                 end
%                 
%                 startIdx    = 1;
%                 while startIdx < size(C,2)
%                     thisLength  = C(2,startIdx);
% 
%                     xC      = C(1,(startIdx+1):(startIdx+thisLength));
%                     yC      = C(2,(startIdx+1):(startIdx+thisLength));
%                                         
%                     xT                  = x0;
%                     xT(xT < min(xC))    = [];
%                     xT(xT > max(xC))    = [];
%                     
%                     if strcmp(z.interpolate,'yes')                    
%                         y0      = interp1(xC,yC,xT);
%                         h1      = plotter(obj,z.plotfnc,xT,y0,plotProperties{:});
%                         h2      = plotter(obj,@hatchedline,xT,y0,hatchProperties{:}); hold on
%                     else
%                         h1      = plotter(obj,z.plotfnc,xC,yC,plotProperties{:});
%                         h2      = plotter(obj,@hatchedline,xC,yC,hatchProperties{:}); hold on                        
%                     end
%                     set(h1,'Tag','Line');
%                     set(h2,'Tag','Line');
%                     startIdx    = startIdx+thisLength+1;
%                 end
%             else
%                 error('Something wrong with the dimensions.');
%             end
%         end

%         function h = semilogxmesh(PDataobj,varargin)
%             if size(PDataobj.y,1) == 1 && size(PDataobj.y,2) == size(PDataobj.f1,1) && size(PDataobj.y,3) == size(PDataobj.f2,1)
%                 h   = mesh(PDataobj.f1,PDataobj.f2,squeeze(PDataobj.y)',varargin{:});
%                 set(gca, 'XScale', 'log')
%             else
%                 error('I am sorry, but I don''t think I can plot this data set...')
%             end
%         end

%         function h = semilogymesh(PDataobj,varargin)
%             if size(PDataobj.y,1) == 1 && size(PDataobj.y,2) == size(PDataobj.f1,1) && size(PDataobj.y,3) == size(PDataobj.f2,1)
%                 h   = mesh(PDataobj.f1,PDataobj.f2,squeeze(PDataobj.y)',varargin{:});
%                 set(gca, 'YScale', 'log')
%             else
%                 error('I am sorry, but I don''t think I can plot this data set...')
%             end
%         end

%         function h = semilogzmesh(PDataobj,varargin)
%             if size(PDataobj.y,1) == 1 && size(PDataobj.y,2) == size(PDataobj.f1,1) && size(PDataobj.y,3) == size(PDataobj.f2,1)
%                 h   = mesh(PDataobj.f1,PDataobj.f2,squeeze(PDataobj.y)',varargin{:});
%                 set(gca, 'ZScale', 'log')
%             else
%                 error('I am sorry, but I don''t think I can plot this data set...')
%             end
%         end

%         function h = semilogxymesh(PDataobj,varargin)
%             if size(PDataobj.y,1) == 1 && size(PDataobj.y,2) == size(PDataobj.f1,1) && size(PDataobj.y,3) == size(PDataobj.f2,1)
%                 h   = mesh(PDataobj.f1,PDataobj.f2,squeeze(PDataobj.y)',varargin{:});
%                 set(gca, 'XScale', 'log', 'YScale', 'log')
%             else
%                 error('I am sorry, but I don''t think I can plot this data set...')
%             end
%         end

%         function h = logloglogmesh(PDataobj,varargin)
%             if size(PDataobj.y,1) == 1 && size(PDataobj.y,2) == size(PDataobj.f1,1) && size(PDataobj.y,3) == size(PDataobj.f2,1)
%                 h   = mesh(PDataobj.f1,PDataobj.f2,squeeze(PDataobj.y)',varargin{:});
%                 set(gca, 'XScale', 'log', 'YScale', 'log', 'ZScale', 'log')
%             else
%                 error('I am sorry, but I don''t think I can plot this data set...')
%             end
%         end

        function h = logloglogsurf(PDataobj,varargin)
            if size(PDataobj.y,1) == 1 && size(PDataobj.y,2) == size(PDataobj.f1,2) && size(PDataobj.y,3) == size(PDataobj.f2,3)
                h   = surf(PDataobj.f1,PDataobj.f2,squeeze(PDataobj.y)',varargin{:});
                set(gca, 'XScale', 'log', 'YScale', 'log', 'ZScale', 'log')
            else
                error('I am sorry, but I don''t think I can plot this data set...')
            end
        end

        function h = scatter3(PDataobj,varargin)
            if size(PDataobj.y,1) == 1 && size(PDataobj.y,2) == size(PDataobj.f1,1) && size(PDataobj.y,3) == size(PDataobj.f2,1)
                pz      = squeeze(PDataobj.y);
                pf1     = repmat(PDataobj.f1,size(PDataobj.y,3),1);
                pf2     = repmat(PDataobj.f2,1,size(PDataobj.y,2))';

                h = scatter3(pf1,pf2(:),pz(:),varargin{:});
            else
                error('I am sorry, but I don''t think I can plot this data set...')
            end
        end

    %% Unit conversion functions

        function nobj = deg(obj)
            nobj    = obj.copy;
            nobj    = nobj.*180./pi;
        end
        
        function nobj = rad(obj)
            nobj    = obj.copy;
            nobj    = nobj./180.*pi;
        end
        
        function nobj = deg2rad(obj)
            nobj    = obj.copy;
            nobj    = nobj.*180./pi;
        end
        
        function nobj = rad2deg(obj)
            nobj    = obj.copy;
            nobj    = nobj.*pi./180;
        end

        function nobj = ms2kmh(obj)
            nobj    = obj.copy;
            nobj    = nobj.*3.6;
        end
        
        function nobj = kmh2ms(obj)
            nobj    = obj.copy;
            nobj    = nobj./3.6;
        end
        
        function nobj = ms2mph(obj)
            nobj    = obj.copy;
            nobj    = nobj.*3.6./1.6;
        end
        
        function nobj = mph2ms(obj)
            nobj    = obj.copy;
            nobj    = nobj./3.6.*1.6;
        end

    %% Overloaded mathematical functions

    
        function nobj = fft(pobj)
            nobj    = pobj.copy;
            nobj    = nobj.genericmathover('fft',@(x,d)fft(x,[],d),[],'x',false);
            
            tx      = nobj.x;
            N       = length(tx);
            dt      = mean(diff(tx-tx(1)));
            dw      = 2*pi/N/dt;
            w2      = 0:dw:((N-1)*dw);
            iNyq    = (N-mod(N,2))/2 + 1;
            
            if iscolumn(nobj.x)
                nobj    = nobj.sUD('x',w2(:));
            else
                nobj    = nobj.sUD('x',w2);
            end
            nobj    = nobj.so('x',1,2:iNyq);
            nobj.checkdimensions();
        end
    
%         function nobj = lsim(pobj,sys,varargin)
%             
%             nobj    = pobj.copy;
%             
%             if ischar(sys)
%                 S   = tf('s'); %#ok<NASGU>
%                 s   = tf('s'); %#ok<NASGU>
%                 
%                 nobj.y  = lsim(eval(sys),nobj.y,nobj.x);
%             elseif isa(sys,'tf')
%                 nobj.y  = lsim(sys,nobj.y,nobj.x);
%             end
%         end
        
        function nobj = find(pobj,varargin)
            nobj    = pobj.copy;
            nobj.y  = find(nobj.y);
            nobj.x  = nobj.x(nobj.y);
            nobj.checkdimensions();
        end
    
        function nobj = diff(pobj,varargin)
            nobj    = pobj.copy;
            
            numDiff = 1;            
            if nargin > 1
                numDiff = varargin{1};
            end            
            nobj.y  = [zeros(numDiff,1); diff(nobj.y,varargin{:})];
            nobj.checkdimensions();
        end
        
        function nobj = squeeze(pobj,varargin)
            nobj    = pobj.copy;
            nobj.x  = squeeze(nobj.x);
            nobj.y  = squeeze(nobj.y);
        end
        
        
        function nobj = diff_dx(pobj,varargin)
            
            dt      = pobj.x(2)-pobj.x(1);
            nobj    = pobj.copy;
            numDiff = 1;
            
            if nargin > 1
                numDiff = varargin{1};
            end
            
            nobj.x  = pobj.x;
            nobj.y  = nan(size(pobj.x));
            theDiff = diff(pobj.y,varargin{:})./(dt^numDiff);
            nobj.y(1:(end-numDiff))  = theDiff(:);
            nobj.checkdimensions();
        end
        
        function nobj = filt_dx(pobj,varargin)
            
            dt      = mean(diff(pobj.x));
            nobj    = pobj.copy;
            
            Fs      = 1/dt;
            
            freq    = 0.1*Fs; % Hz
            order   = 2;
            
            if ~isempty(varargin)
                freq    = varargin{1};
            end
            if length(varargin) == 2
                order   = varargin{2};
            end
            
            h       = fdesign.lowpass('N,F3dB',order,freq,Fs); % Second order Butterworth filter, F3dB at 40Hz, data Fs = 250 Hz.
            d1      = design(h,'butter');
            
            warning('off','all')
            nobj.y = filtfilt(d1.sosMatrix,d1.ScaleValues,nobj.y);
            warning('on','all')
        end
        
        function nobj = diff_dt(pobj,dt,varargin)
            
            if nargin == 1 || isempty(dt)
                dt    = pobj.x(2)-pobj.x(1);
            end
            
            nobj    = pobj.copy;
            nobj.x  = pobj.x(1:(end-1));
            nobj.y  = diff(nobj.y,varargin{:})./dt;
        end
        
        

        function nobj = sqrt(pobj,varargin)
            nobj    = pobj.copy;
            nobj.y  = sqrt(nobj.y);
        end

        function nobj = log(pobj,varargin)
            nobj    = pobj.copy;
            nobj.y  = log(nobj.y,varargin{:});
        end
        
        function nobj = log10(pobj,varargin)
            nobj    = pobj.copy;
            nobj.y  = log10(nobj.y,varargin{:});
        end

        function nobj = round(pobj)
            nobj    = pobj.copy;
            nobj.y  = round(nobj.y);
        end

        function res = issingle(pobj)
            res = all(isinf(pobj.f1)) && all(isinf(pobj.f2)) && all(isinf(pobj.f3));
        end
        
        function nobj = horzcatObj(obj,varargin)
            overFunc    = varargin{end};
            overFuncId  = find(strcmp(overFunc,obj.fNames));
            concObjs    = varargin(1:(end-1));
            
            assert(all(cellfun(@(x)length(x.fNames) == length(obj.fNames),concObjs)));
            for oo=1:length(obj.fNames)
                assert(all(cellfun(@(x)strcmp(obj.fNames{oo},x.fNames{oo}),concObjs)));
                if ~strcmp(obj.fNames{oo},overFunc)
                    assert(all(cellfun(@(x)isequal(obj.fValues{oo},x.fValues{oo}),concObjs)));
                    assert(all(cellfun(@(x)isequal(obj.fLabels{oo},x.fLabels{oo}),concObjs)));
                end
            end
            
            
            pVec    = [overFuncId 1:(overFuncId-1) (overFuncId+1):length(obj.fNames)];
            tY      = permute(obj.y,pVec);
            tStdv   = permute(obj.stdv,pVec);
            funcL   = obj.fLabels{overFuncId};
            
            for oo=1:length(concObjs)
                tY      = [tY; permute(concObjs{oo}.y,pVec)]; %#ok<AGROW>
                tStdv   = [tStdv; permute(concObjs{oo}.stdv,pVec)]; %#ok<AGROW>
                funcL   = [funcL concObjs{oo}.fLabels{overFuncId}]; %#ok<AGROW>
            end
            
            nobj            = obj.copy;
            nobj.y          = ipermute(tY,pVec);
            nobj.stdv       = ipermute(tStdv,pVec);
            
            nobj.fLabels{overFuncId} = funcL;
            nobj.fValues{overFuncId} = 1:length(funcL);
        end
        
        function nobj = horzcat(obj,varargin)
            
            if all(cellfun(@(x)isa(x,'PData3'),varargin(1:(end-1)))) && ischar(varargin{end}) 
                nobj = horzcatObj(obj,varargin{:});
            else
                if ~ischar(varargin{end})
                    error('The last concatenation argument should be the name of the functional you are concatenating.')
                else
                    fName           = varargin{end};
                    varargin(end)   = [];
                end

                mainNdims   = ndims(obj.y);
                mainsize    = size(obj.y);
                objectNames = [];

                if any(cellfun(@(x)ischar(x),varargin))
                    if sum(cellfun(@(x)ischar(x),varargin)) == (length(varargin)+1)/2

                        objectNames     = varargin(1:2:end);
                        varargin        = varargin(2:2:end);

                        if ~all(cellfun(@(x)ischar(x),objectNames))
                            error('Something went wrong.');
                        end
                    else
                        error('Something went wrong.');
                    end
                end

                for oo=1:length(varargin)
                    if ~isa(varargin{oo},'PData3')
                        error('Input %i is not a PData3 object!',oo);
                    end
                    if ndims(varargin{oo}.y) ~= mainNdims
                        error('Input %i does not have the correct size (is %i, should be %i)!',oo,ndims(varargin{oo}.y),mainNdims);
                    end
                    if ~all(size(varargin{oo}.y) == mainsize)
                        error('Input %i does not have the correct size (is [%s\b], should be [%s\b])!',oo,sprintf('%i ',size(varargin{oo}.y)),sprintf('%i ',mainsize));
                    end
                end

                nobj    = PData3;
                nobj.x  = obj.x;

                if iscell(obj.y(1))
                    newy    = cell([length(varargin)+1 mainsize]);
                else
                    newy    = zeros([length(varargin)+1 mainsize]);
                end
                newfLabels      = cell(length(varargin)+1,1);

                newy(1,:)       = obj.y(:);
                newfLabels{1}   = inputname(1);
                for oo=1:length(varargin)
                    newy(oo+1,:)        = varargin{oo}.y(:);
                    newfLabels{oo+1}    = inputname(oo+1);
                end

                nobj.y          = newy;

                nobj.fValues    = {1:(length(varargin)+1) obj.fValues{:}}; %#ok<CCAT>
                if ~isempty(objectNames)
                    nobj.fLabels = {objectNames obj.fLabels{:}}; %#ok<CCAT>
                else
                    nobj.fLabels    = {newfLabels obj.fLabels{:}}; %#ok<CCAT> 
                end
                nobj.fNames     = {fName obj.fNames{:}}; %#ok<CCAT>
            end
            nobj.checkdimensions();
        end
        
        
        function l = lengthY(obj)
            l = length(obj.y);
        end

        function nobj = mathfunc(h,a,b,varargin)
            
            actOn   = 'y';
            if nargin > 3
                if ischar(varargin{1})
                    actOn   = varargin{1};
                end
            end
            
            funcSymbols.rdivide     = './';
            funcSymbols.ldivide     = '.\';
            funcSymbols.mrdivide    = '/';
            funcSymbols.mldivide    = '\';
            funcSymbols.plus        = '+';
            funcSymbols.minus       = '-';
            funcSymbols.uminus      = '-';
            funcSymbols.times       = '.*';
            funcSymbols.mtimes      = '*';
            funcSymbols.power       = '.^';
            funcSymbols.mpower      = '^';
            
            if isa(a,'PData3') && isa(b,'PData3')
                % First, we check whether the two results are a function of
                % some external variable, or only a function of x.
                
                if isequal(size(a.(actOn)),size(b.(actOn))) || (ismatrix(a.(actOn)) && ismatrix(b.(actOn)) && isequal(fliplr(size(a.(actOn))), size(b.(actOn))))
                    nobj    = a.copy;
                    if strcmp(actOn,'y')
                        if ~isequal(a.x(:),b.x(:))
                            warning('It seems you are %s-ing two objects with different x values!',func2str(h))
                        end
                        
                        % so we determined that the two objects have the
                        % same size. IF the two objects have the same
                        % functionals, we need to reorder the data such
                        % that we get the expected results.
                        
                        if isempty(setxor(a.fNames,b.fNames))
                            
                            [~,ib,~]    = intersect(a.fNames,b.fNames);
                            nb = b.copy;
                            nb.fNames   = b.fNames(ib);
                            nb.fValues  = b.fValues(ib);
                            nb.fLabels  = b.fLabels(ib);
                            pOrder      = [ib(:); ((length(ib)+1):(ndims(b.x)+length(ib))).'].';
                            nb.y        = permute(b.y,pOrder);
                            b = nb;
                        end
                    end
                elseif isscalar(a.(actOn))
                    nobj    = b.copy;
                elseif isscalar(b.(actOn))
                    nobj    = a.copy;
                else
                    error('These two objects cannot be operated on.');
                end
                
                
                
                beforeSize      = size(nobj.(actOn));
                nobj.(actOn)    = feval(h,a.(actOn),b.(actOn));
                if ~isequal(beforeSize,size(nobj.(actOn)))
                    % The size of the answer is different from the inputs,
                    % this can happen with matrix multiplication operators.
                    % We have to apply the same operation to both the x and
                    % y data, otherwise we'll run in trouble with the
                    % dimensions of the data.
                    
                    if strcmp(actOn,'x')
                        nobj.y = feval(h,a.y,b.y);
                    else
                        nobj.x = feval(h,a.x,b.x);
                    end
                end
                    
                % I think for now it is most safe to throw the variance
                % information away while doing math operations.
                
                
                if strcmp(actOn,'y')
                    nobj.stdv   = [];
                
                    if isfield(funcSymbols,func2str(h))
                        if any(cellfun(@(x)~isempty(strfind(a.myName,x)),{'+','-'}))
                            aName   = ['(' a.myName ')'];
                        else
                            aName   = a.myName;
                        end

                        if any(cellfun(@(x)~isempty(strfind(b.myName,x)),{'+','-'}))
                            bName   = ['(' b.myName ')'];
                        else
                            bName   = b.myName;
                        end

                        nobj.myName     = [aName funcSymbols.(func2str(h)) bName];
                    end
                end
                
                
                
            elseif isa(a,'PData3') && ~isa(b,'PData3')
                nobj            = a.copy;
                nobj.(actOn)    = feval(h,a.(actOn),b);
                
                if strcmp(actOn,'y')
                    nobj.stdv       = [];
                
                    if isfield(funcSymbols,func2str(h))
                        if any(cellfun(@(x)~isempty(strfind(a.myName,x)),{'+','-'}))
                            aName   = ['(' a.myName ')'];
                        else
                            aName   = a.myName;
                        end

                        nobj.myName     = [aName funcSymbols.(func2str(h)) sprintf('%1.2f',b)];
                    end
                end
            elseif ~isa(a,'PData3') && isa(b,'PData3')
                nobj            = b.copy;
                nobj.(actOn)    = feval(h,a,b.(actOn));
                
                if strcmp(actOn,'y')
                    nobj.stdv       = [];

                    if isfield(funcSymbols,func2str(h))
                        if any(cellfun(@(x)~isempty(strfind(b.myName,x)),{'+','-'}))
                            bName   = ['(' b.myName ')'];
                        else
                            bName   = b.myName;
                        end

                        nobj.myName     = [sprintf('%1.2f',a) funcSymbols.(func2str(h)) bName];
                    end
                end
            end
            nobj.checkdimensions();
        end
        
        function nobj = transpose(obj)
            nobj    = obj.copy;
            nobj.x  = transpose(nobj.x);
            if ismatrix(nobj.y)
                nobj.y = transpose(nobj.y);
            end
            nobj.checkdimensions();
        end

        function nobj = power(a,b)
            nobj = mathfunc(@power,a,b);
        end

        function nobj = mpower(a,b)
            nobj = mathfunc(@mpower,a,b);
        end

        function nobj = times(a,b)
            nobj = mathfunc(@times,a,b);
        end

        function nobj = mtimes(a,b)
            nobj = mathfunc(@mtimes,a,b);
        end

        function nobj = rdivide(a,b)
            nobj = mathfunc(@rdivide,a,b);
        end

        function nobj = mrdivide(a,b)
            nobj = mathfunc(@mrdivide,a,b);
        end

        function nobj = plus(a,b)
            nobj = mathfunc(@plus,a,b);
        end
        
        function nobj = gt(a,b)
            nobj = mathfunc(@gt,a,b);
        end
        
        function nobj = ge(a,b)
            nobj = mathfunc(@ge,a,b);
        end
        
        function nobj = eq(a,b)
            nobj = mathfunc(@eq,a,b);
        end
        
        function nobj = le(a,b)
            nobj = mathfunc(@le,a,b);
        end
        
        function nobj = lt(a,b)
            nobj = mathfunc(@lt,a,b);
        end
        
        function nobj = ne(a,b)
            nobj = mathfunc(@ne,a,b);
        end
        
        function nobj = xplus(a,b)
            nobj = mathfunc(@plus,a,b,'x');
        end
        
        function nobj = xminus(a,b)
            nobj = mathfunc(@minus,a,b,'x');
        end
        
        function nobj = minus(a,b)
            nobj = mathfunc(@minus,a,b);
        end
        
        function nobj = uminus(a)
            nobj = mathfunc(@times,a,-1);
        end
        
        

    end
    methods(Access=private)
        function obj = checkdimensions(obj)

            neededSize  = [];
            for oo=1:length(obj.fValues)
                neededSize  = [neededSize length(obj.fValues{oo})]; %#ok<AGROW>
            end

            neededSize  = [neededSize size(obj.x)];

            stop = false;
            while ~stop
                if neededSize(end) == 1 || neededSize(end) == 0
                    if neededSize(end) == 1 && length(neededSize) > 2
                        neededSize = neededSize(1:(end-1));
                    elseif neededSize(end) == 0
                        neededSize = neededSize(1:(end-1));
                    else
                        stop = true;
                    end
                else
                    stop = true;
                end
            end

            actualSize  = size(obj.y);
            
            assert(isequal(neededSize,actualSize),'There is something wrong with the size of the y data.\n\t- size(y) = [%s], but should be [%s]',num2str(actualSize),num2str(neededSize));

            if isscalar(neededSize) && iscell(obj.y)
                obj.y = obj.y{1};
            end
            
            % Also do some checks on the fLabels and fNames
            
            if length(obj.fNames) ~= length(obj.fLabels)
                error('There should be as many labels as functional names.')
            end
            
            if length(unique(obj.fNames)) < length(obj.fNames)
                error('There are multiple functionals with the same name:\n%s',sprintf('- %s',obj.fNames));
            end
            
            for oo=1:length(obj.fLabels)
                if iscell(obj.fLabels{oo})
                    if length(unique(cell2mat(obj.fLabels{oo}),'rows')) < length(obj.fLabels{oo})
                        tab         = tabulate(obj.fLabels{oo});
                        duplicates  = tab([tab{:,2}] > 1,1);
                        error('There are multiple labels within functional %s with the same value.',obj.fNames{oo},sprintf('- %s\n',duplicates{:}));
                    end
                else
                    if length(unique(obj.fLabels{oo})) < length(obj.fLabels{oo})
                        tab         = tabulate(obj.fLabels{oo});
                        duplicates  = tab([tab{:,2}] > 1,1);
                        error('There are multiple labels within functional %s with the same name:\n%s',obj.fNames{oo},sprintf('- %s\n',duplicates{:}));
                    end
                end
            end
        end
        
        function nobj = genericmath(obj,fncName,mainFnc,varFnc,dim,applytox)
            nobj    = obj.copy;
            
            if isempty(dim)
                dim = 1;
            end

            if iscell(nobj.y)
                error('I cannot calculate on items contained within a cell.');
            end

            if isa(varFnc,'function_handle')
                nobj.stdv       = varFnc(nobj.y,dim);            
                sz              = size(nobj.stdv);
                sz(dim)         = [];
                if length(sz) == 1
                    sz  = [sz 1];
                end
                nobj.stdv        = reshape(nobj.stdv,sz);
            end

            sz              = size(nobj.y);
            nobj.y          = mainFnc(nobj.y,dim);

            if dim > length(nobj.fNames)
                if applytox
                    nobj.x = mainFnc(nobj.x,dim-length(nobj.fNames));
                end
            else
                sz(dim)         = [];
                if length(sz) == 1
                    sz  = [sz 1];
                end
                nobj.y          = reshape(nobj.y,sz);

                if length(nobj.fLabels) == length(nobj.fNames)
                    nobj.fLabels(dim) = [];
                elseif ~isempty(nobj.fLabels)
                    error('Something weird here.')
                end
                nobj.fNames(dim)        = [];
                nobj.fValues(dim)       = [];
            end
            
            nobj.myName     = [fncName '(' nobj.myName ')'];
            nobj.checkdimensions();
        end
        
        function checkcompatibility(a,b)

            if any(size(a.x) ~= size(b.x))
                error('The ''x'' fields of ''a'' and ''b'' are not the same dimension!');
            end

            if any(size(a.f1) ~= size(b.f1))
                error('The ''f1'' fields of ''a'' and ''b'' are not the same dimension!');
            end

            if any(size(a.f2) ~= size(b.f2))
                error('The ''f2'' fields of ''a'' and ''b'' are not the same dimension!');
            end

            if any(size(a.y) ~= size(b.y))
                error('The ''y'' data of ''a'' and ''b'' are not the same dimension!');
            end

            if ~strcmp(a.xAxis,b.xAxis)
                error('The ''xAxis'' fields of ''a'' and ''b'' are not the same.')
            end
        end
    end
    
end