% function [P, Info] = Farx(P, Data, Orders, Options)
function [A,B] = Farx(y, u, na, nb, nk)
    
% ARX function based on the arx_time_prediction function by Lennart Ljung,
% part of the MATLAB System Identification toolbox.

% ARX estimation when Focus = 'prediction'

% Info    = idresults.arx;
% ny      = Data.Ny;
% nu      = Data.Nu;
% nexp    = Data.Ne;

ny      = size(y,2);
nu      = size(u,2);
nexp    = 1;

% na      = Orders.na;
% nb      = Orders.nb;
% nk      = Orders.nk;

for oo=1:length(nb)
    if nb(oo) == 0
        nk(oo) = 0;
    end
end

% if isempty(nk)
%    nk = zeros(ny,nu);
% end

% NI = P.Structure.IntegrateNoise;
% if NI(1)
%    Data = idpack.utDataOp('diff',Data);
%    P.Structure.IntegrateNoise = false(size(NI));
% end

% % Since only DT models can be estimated using time domain data, combine
% % ioDelay with nk
% iod = P.Structure.ioDelay; % only the value of ioDelay (separate from nk-1)
iod     = 0;
nk      = nk+iod;

% fLinSolve = Options.LinearSolver; % function handle
fLinSolve   = @idpack.mldividecov;
% fLinSolve   = @mldivide;
% ParBoundsExist = localParBoundsExist(P.Structure);
ParBoundsExist  = false;
% 
% if ParBoundsExist && ~idpack.isOptimInstalled
%    ctrlMsgUtils.warning('Ident:estimation:ARXwithBounds')
%    %P.Structure = resetBounds(P.Structure);
%    ParBoundsExist = false;
% end

% MaxSize = Options.MaxSize;
MaxSize     = 250000;
% W = Options.OutputWeight;
% if isempty(W) || isequal(W,eye(size(W)))
   W = eye(ny);
% end

nma         = max(na(:));
nbplusnk    = nb+nk;
nbkm        = max(nbplusnk(:))-1;
nkm         = min(nk(:));
%np = sum(na(:))+sum(nb(:));
if nu>0
   n = nma*ny+(nbkm-nkm+1)*nu;
else
   n = nma*ny;
end

% kloop           = Options.EstCovar+1;
% parvec          = getp(P);
parvec              = [];
np                  = sum(na(:))+sum(nb(:));
% np              = length(parvec);
% OldParExists    = ~isempty(parvec) && ~any(isnan(parvec));
OldParExists        = false;
% Free            = isfree(P);
Free                = true(np,1);
FreeIndex           = find(Free);
ni  = length(FreeIndex);
% FreeIndex           = true(n,1);
% ni              = length(FreeIndex);
% if ni==0
%    Info.Status = ctrlMsgUtils.message('Ident:estimation:msgZeroOrders');
%    return;
% end

% All parameters are free, so we will fix ni to the number of parameters.
% ni  = sum(na(:))+sum(nb(:))
% It appears that n contains the number of parameters.



nmax = max([nma nbkm 1],[],2);

% For now we will only estimate the parameters and not the covariance, so
% we force kloop to 1.
kloop = 1;

for klc = 1:kloop
   if klc==1
      % Estimate the parameters
      e     = [];
      R1    = zeros(0,ni+1);
   else
      % Compute covariance
      R1 = zeros(0,ni);
      melam = W*idpack.sqrtmcov(lam0);
      R1f = zeros(0,ni);
   end
   
%    sqrlam   = idpack.sqrtmcov(W);
    sqrlam  = 1;
%     sqrlam  = eye(n);
   OEflag   = false;
   
    % We will never compute an OE model. That is, sum(na) will always be
    % larger than 0.

    %    if sum(na(:))==0 && klc==2
    %       % Compute the true variance in the OE case.
    %       OEflag = true; % true only for second loop
    %       try
    %          if ny==1, Ord = 5; else Ord = 4*ny; end % b.c.
    %          me = idpack.ssdata.createTemplate(ny,0,Ord,P.Ts,false,true);
    %          edat = idpack.createDataStruct(e,[],cell(0,1),P.Ts,[],true,Data.IsReal);
    %          me = n4sid_time(me,edat,Ord,n4sidOptions('EstCovar',false)); 
    %          me.Structure.a.Value = fstab(me.Structure.a.Value,1,0.99);
    %          %me = pvset(me,'A',oestab(pvget(me,'A'),0.99,1));
    %          [av,~,cv,~,kv] = getABCDKX0(me);
    %          cv1 = cv; av = av'; cv = kv'; kv = cv1';
    %          melam = W*idpack.sqrtmcov(me.NoiseVariance);
    %       catch
    %          av = zeros(1,1); cv = zeros(ny,1); kv = zeros(1,ny);
    %       end
    %    end
   
   
   M = floor(MaxSize/n/ny);
   
    for kexp = 1:nexp
    %       z     = [Data.y{kexp},Data.u{kexp}]; % REVISIT (eventually): Use Data API
        z       = [y, u];
%         Ncap    = Data.Ncaps(kexp);
        Ncap    = size(z,1);

        stps    = nmax:M:Ncap-1;
        clrpsi  = length(stps) > 1;
        
        for samples = stps
            if min(Ncap,samples+M)<samples+1,break,end

            jj = (samples+1:min(Ncap,samples+M));
            phi = zeros(length(jj)*ny,np);
            sp = 1;
            % Collect dA
            for ky = 1:ny
                na_max_ky = max(na(ky,:));
                for ky2 = 1:ny
                    for ydelct = 1:na_max_ky
                        phitemp = zeros(length(jj),ny);
                        if na(ky,ky2)>=ydelct
                            phitemp(:,ky) = -z(jj-ydelct,ky2); %r.s.
                            if klc==2
                                if OEflag
                                    psitemp1 = ltitr(av,kv,phitemp(end:-1:1,:));
                                    psitemp = (psitemp1*cv.'+phitemp(end:-1:1,:))*melam;
                                    psi(:,sp) = psitemp(:);
                                else
                                    psitemp = phitemp*melam;
                                    psi(:,sp) = psitemp(:);
                                end
                            end
%                             size(phitemp)
                            phitemp     = phitemp*sqrlam;
                            phi(:,sp)   = phitemp(:);
                            sp          = sp+1;
                        end
                    end
                end

                % Collect dB
                if ~isempty(nb)
                    for ku = 1:nu
                        for udelct = min(nk(ky,:)):max(nk(ky,:)+nb(ky,:))-1 % process lagged inputs
                            phitemp = zeros(length(jj),ny);
                            if (nk(ky,ku)<=udelct) && (nk(ky,ku)+nb(ky,ku)-1>=udelct)
                                phitemp(:,ky) = z(jj-udelct,ny+ku);
                                if klc==2
                                    if OEflag
                                        psitemp1 = ltitr(av,kv,phitemp(end:-1:1,:));
                                        psitemp = (psitemp1*cv.'+phitemp(end:-1:1,:))*melam;
                                        psi(:,sp) = psitemp(:);
                                    else
                                        psitemp = phitemp*melam;
                                        psi(:,sp) = psitemp(:);
                                    end
                                end
                                phitemp = phitemp*sqrlam;
                                phi(:,sp) = phitemp(:);
                                sp = sp+1;
                            end
                        end
                    end % ku
                end % if
            end %ky

            if klc==1
                yy      = z(jj,1:ny)*sqrlam;
                yvec    = yy(:);

                if OldParExists
                    evec = yvec - phi*parvec;
                else
                    evec = yvec;
                end
            else
                evec = zeros(size(phi,1),0);
            end

            phi        = phi(:,FreeIndex);
            R1         = triu(qr([R1; phi, evec]));
            [nRr,nRc]  = size(R1);
            R1         = R1(1:min(nRr, nRc),:);

            if klc==2
                psi = psi(:, FreeIndex);
                R1f = triu(qr([R1f ; psi]));
                [nRrf,nRcf] = size(R1f);
                R1f = R1f(1:min(nRrf, nRcf), :);
            end
            
            if clrpsi
                clear psi
%                 fprintf('clearing psi\n')
            end
        end %samples
    end %kexp
   
   if klc==1 % estimate
      if size(R1,1)<ni+1
         ctrlMsgUtils.error('Ident:estimation:tooFewSamples')
      end
      
      if ParBoundsExist
         MinMax = getpbounds(P);
         Min = MinMax(:,1); Max = MinMax(:,2);
      else
         Min = []; Max = [];
      end
      
      parvec = idpack.lsqbound(parvec, R1(1:ni,1:ni), R1(1:ni,ni+1), Free, ...
         fLinSolve, ParBoundsExist, Min, Max);
     
      if any(~isfinite(parvec)) && strcmp(func2str(fLinSolve),'mldivide')
         parvec = idpack.lsqbound(parvec, R1(1:ni,1:ni), R1(1:ni,ni+1), Free, ...
         @(x_,y_)pinv(x_)*y_, ParBoundsExist, Min, Max);
      end
      
      if OldParExists
         P = setParInfo(P,'Value',parvec);
      else
         % Cold start estimation; delta_par is new parameter value.
         nk = nk-iod;
         [A,B] = FgetARXAB(parvec.', ny, nu, na, nb, nk);
%          P = idpoly(A,B,'Ts',Data.Ts);
%          S = pmodel.polynomial(A,B,[],[],[],iod);
%          % Fix zeros corresponding to nk
%          P.Structure = pmodel.polynomial.fixNkInB(S,1,nk);
         
%          P.Structure.a
%          P.Structure.b
         
%          Y.a    = P.Structure.a.Value;
%          Y.b    = P.Structure.b.Value;
      end
      
%       e = pe(P,Data,'e',1); % init = 'e' is required since calculating over 
%                             % entire data range and not just jj.
%       if ny>1
%          % REVISIT: Difference in V between SO and MO models 
%          lamhat = zeros(ny); Nc = 0;
%          for kexp = 1:nexp
%             e1 = e{kexp}(nmax:end,:);
%             lamhat = lamhat + e1'*e1;
%             Nc = Nc + length(e1);
%          end
%          %e = cat(1,e{:});
%          lam0 = lamhat/(Nc-np/ny); % Exact interpretation:
%          % Same parameterization in each output channel.
%          V = abs(det(lam0)); % abs to protect against singular lam0
%       else
%          Ncapeff = sum(Data.Ncaps)-Data.Ne*nmax-np;
%          lam0 = R1(ni+1,ni+1)^2/Ncapeff;
%          V = lam0*Ncapeff/sum(Data.Ncaps);
%       end
   else
      R3 = triu(qr(idpack.mldividecov(R1f',R1'))); % was: R3 = triu(qr(R1f'\R1'));
      cov = idpack.FactoredCovariance(R3*R1,[],Free);
      P.Covariance = cov;
   end 
end 

% P.NoiseVariance = lam0;
% P.Structure.IntegrateNoise = NI;
% if nargout>1
%    Info.Status = ctrlMsgUtils.message('Ident:estimation:msgStatusValue', 'ARX','prediction');
%    Info.Fit.LossFcn = V;
%    Info.Fit.FPE = V*(1+2*np/sum(Data.Ncaps));
% end