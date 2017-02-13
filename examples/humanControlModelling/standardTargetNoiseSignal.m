function ftn = standardTargetNoiseSignal(name,model,varargin)

p = inputParser;
p.CaseSensitive = true;
p.addParameter('Ktn',[]);
p.addParameter('tau_noise',[]);
p.parse(varargin{:});
z = p.Results;

switch name
    case 'none'
        ftn  = z.Ktn * zeros(size(model.measurementTime));
    case 'sdt noise 1'
        % Filter properties
        s               = tf('s');
        latFilter       = (0.4 * 2*s / (s + 2)) * 3^2 / (s^2 + 2*0.3*3*s + 3^2) * (4 + s) / 4;
        latFilterSys    = ss(latFilter);
        
        % Disturbance signal properties
        nd          = round([3 5 7 11 17   23   31   41   53  71   89]*81.92/55);
        phase       = [3.0164    3.6567    1.6974    4.8099    4.9964    1.1742...
                       3.0773    2.7997    4.0609    4.4571    2.9654];
        Ad          = [1 1 1 1  0.1  0.1  0.1  0.1  0.1  0.1 0.1];
                   
        % Now filter the specified amplitudes with the filter defined
        % above.
        
        filtFRF     = squeeze(freqresp(latFilterSys,2*pi/55 * nd))';
        Ad          = Ad .* abs(filtFRF);
        ftn         = (pi/180) * disturbanceSignals2('multisine',model,'nd',nd,'Ad',Ad,'phase',phase,'Td',81.92);
        ftn         = z.Ktn * ftn / max(abs(ftn)) / 0.4416 / 180 * pi;
        
        if ~isempty(z.tau_noise)
            ftn         = circshift(ftn,z.tau_noise);
        end
	case 'sdt noise 2'
        % Filter properties
        s               = tf('s');
        latFilter       = (0.4 * 2*s / (s + 2)) * 3^2 / (s^2 + 2*0.3*3*s + 3^2) * (4 + s) / 4;
        latFilterSys    = ss(latFilter);
        
        % Disturbance signal properties
        nd          = [7 10 16 25 34 46 61 79 106 133];
        phase       = [3.6567    1.6974    4.8099    4.9964    1.1742...
                       3.0773    2.7997    4.0609    4.4571    2.9654];
        Ad          = [1 1 1  0.1  0.1  0.1  0.1  0.1  0.1 0.1];
                   
        % Now filter the specified amplitudes with the filter defined
        % above.
        
        filtFRF     = squeeze(freqresp(latFilterSys,2*pi/55 * nd))';
        Ad          = Ad .* abs(filtFRF);
        ftn         = (pi/180) * disturbanceSignals2('multisine',model,'nd',nd,'Ad',Ad,'phase',phase,'Td',81.92);
        ftn         = z.Ktn * ftn / max(abs(ftn)) / 0.4416 / 180 * pi;
        
        if ~isempty(z.tau_noise)
            ftn         = circshift(ftn,z.tau_noise);
        end
    case 'zaal2009a'
        nd      = [6 13 27 41 53 73 103 139 194 229]';
        Ad      = [1.562 1.092 0.493 0.265 0.178 0.110 0.070 0.051 0.040 0.036] ./ sqrt(5) .* pi/180;
        phase   = [1.288 6.089 5.507 1.734 2.019 0.441 5.175 3.415 1.066 3.479];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
    case 'zaal2009f'
        nd      = [6 13 27 41 53 73 103 139 194 229]';
        Ad      = [1.562 1.092 0.493 0.265 0.178 0.110 0.070 0.051 0.040 0.036] .* pi/180;
        phase   = [1.288 6.089 5.507 1.734 2.019 0.441 5.175 3.415 1.066 3.479];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
	case 'ftn mf 1'
        nd      = [6 13 27 41 53 73 103 139 194 229]';
        Ad      = [1.562 1.092 0.493 0.265 0.178 0.110 0.070 0.051 0.040 0.036] ./ sqrt(5) .* pi/180;
        phase   = [1.288 6.089 5.507 1.734 2.019 0.441 5.175 3.415 1.066 3.479];
        ftn     = sqrt(3.7498) * z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
	case 'ftn mf 2 lb'
%         3.0000    5.0000   11.0000   17.0000   23.0000   31.0000   47.0000   73.0000  113.0000
%         0.9677    0.9153    0.6919    0.4871    0.3447    0.2288    0.1213    0.0624    0.0357
%         3.3513    4.7142    5.1701    4.5238    4.2344    3.3590    1.3774    2.0121    5.8443
        nd      = [3.0000    5.0000   11.0000   17.0000   23.0000   31.0000   47.0000   73.0000  113.0000];
        Ad      = [0.9677    0.9153    0.6919    0.4871    0.3447    0.2288    0.1213    0.0624    0.0357] ./ 2.6465 .* pi/180;
        phase   = [3.3513    4.7142    5.1701    4.5238    4.2344    3.3590    1.3774    2.0121    5.8443];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
	case 'ftn mf 2 mb'
%         3.0000    5.0000   11.0000   17.0000   23.0000   31.0000   47.0000   73.0000  113.0000  179.0000
%         0.9677    0.9153    0.6919    0.4871    0.3447    0.2288    0.1213    0.0624    0.0357    0.0237
%         4.7377    1.3013    4.8508    2.1077    1.7113    3.1874    2.0431    3.4519    5.3182    2.7906
        nd      = [3.0000    5.0000   11.0000   17.0000   23.0000   31.0000   47.0000   73.0000  113.0000  179.0000];
        Ad      = [0.9677    0.9153    0.6919    0.4871    0.3447    0.2288    0.1213    0.0624    0.0357    0.0237] ./ 2.9234 .* pi/180;
        phase   = [4.7377    1.3013    4.8508    2.1077    1.7113    3.1874    2.0431    3.4519    5.3182    2.7906];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
    case 'ftn mf 2 hb'
%         3.0000    5.0000   11.0000   17.0000   23.0000   31.0000   47.0000   73.0000  113.0000  179.0000  277.0000
%         0.9677    0.9153    0.6919    0.4871    0.3447    0.2288    0.1213    0.0624    0.0357    0.0237    0.0190
%         2.3228    2.2112    4.3061    2.9756    3.4982    0.7141    0.4295    0.4573    5.6707    3.0966    3.5570
        nd      = [3.0000    5.0000   11.0000   17.0000   23.0000   31.0000   47.0000   73.0000  113.0000  179.0000  277.0000];
        Ad      = [0.9677    0.9153    0.6919    0.4871    0.3447    0.2288    0.1213    0.0624    0.0357    0.0237    0.0190] ./ 3.1942 .* pi/180;
        phase   = [2.3228    2.2112    4.3061    2.9756    3.4982    0.7141    0.4295    0.4573    5.6707    3.0966    3.5570];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
    case 'ftn mf simona lb'
%         3.0000    5.0000   11.0000   17.0000   23.0000   31.0000   47.0000   73.0000  113.0000
%         0.9677    0.9153    0.6919    0.4871    0.3447    0.2288    0.1213    0.0624    0.0357
%         3.3513    4.7142    5.1701    4.5238    4.2344    3.3590    1.3774    2.0121    5.8443
        nd      = [3.0000    5.0000   11.0000   17.0000   23.0000   31.0000   47.0000   73.0000  113.0000];
        Ad      = [0.9677    0.9153    0.6919    0.4871    0.3447    0.2288    0.1213    0.0624    0.0357] ./ 2.6465 .* pi/180;
        phase   = [3.3513    4.7142    5.1701    4.5238    4.2344    3.3590    1.3774    2.0121    5.8443];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
	case 'ftn mf simona mb'
%         3.0000    5.0000   11.0000   17.0000   23.0000   31.0000   47.0000   73.0000  113.0000  179.0000
%         0.9677    0.9153    0.6919    0.4871    0.3447    0.2288    0.1213    0.0624    0.0357    0.0237
%         4.7377    1.3013    4.8508    2.1077    1.7113    3.1874    2.0431    3.4519    5.3182    2.7906
        nd      = [3.0000    5.0000   11.0000   17.0000   23.0000   31.0000   47.0000   73.0000  113.0000  179.0000];
        Ad      = [0.9677    0.9153    0.6919    0.4871    0.3447    0.2288    0.1213    0.0624    0.0357    0.0237] ./ 2.9234 .* pi/180;
        phase   = [4.7377    1.3013    4.8508    2.1077    1.7113    3.1874    2.0431    3.4519    5.3182    2.7906];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
	case 'ftn mf simona hb'
%         3.0000    5.0000   11.0000   17.0000   23.0000   31.0000   47.0000   73.0000  113.0000  179.0000  277.0000
%         0.9677    0.9153    0.6919    0.4871    0.3447    0.2288    0.1213    0.0624    0.0357    0.0237    0.0190
%         2.3228    2.2112    4.3061    2.9756    3.4982    0.7141    0.4295    0.4573    5.6707    3.0966    3.5570
        nd      = [3.0000    5.0000   11.0000   17.0000   23.0000   31.0000   47.0000   73.0000  113.0000  179.0000  277.0000];
        Ad      = [0.9677    0.9153    0.6919    0.4871    0.3447    0.2288    0.1213    0.0624    0.0357    0.0237    0.0190] ./ 3.1942 .* pi/180;
        phase   = [2.3228    2.2112    4.3061    2.9756    3.4982    0.7141    0.4295    0.4573    5.6707    3.0966    3.5570];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
	case 'ftn mf simona zaal'
        nd      = [6 13 27 41 53 73 103 139 194 229]';
        Ad      = [1.562 1.092 0.493 0.265 0.178 0.110 0.070 0.051 0.040 0.036] ./ 4.9463 .* pi/180;
        phase   = [1.288 6.089 5.507 1.734 2.019 0.441 5.175 3.415 1.066 3.479];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
    case 'ftn mf simona mb norm'
%         3.0000    5.0000   11.0000   17.0000   23.0000   31.0000   47.0000   73.0000  113.0000  179.0000
%         0.9677    0.9153    0.6919    0.4871    0.3447    0.2288    0.1213    0.0624    0.0357    0.0237
%         4.7377    1.3013    4.8508    2.1077    1.7113    3.1874    2.0431    3.4519    5.3182    2.7906
        nd      = [3.0000    5.0000   11.0000   17.0000   23.0000   31.0000   47.0000   73.0000  113.0000  179.0000];
        Ad      = [0.9677    0.9153    0.6919    0.4871    0.3447    0.2288    0.1213    0.0624    0.0357    0.0237] ./ 1.098071018438 .* pi/180;
        phase   = [4.7377    1.3013    4.8508    2.1077    1.7113    3.1874    2.0431    3.4519    5.3182    2.7906];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
	case 'ftn mf simona zaal norm'
        nd      = [6         13        27        41        53        73        103       139       194       229]';
        Ad      = [0.6984    0.4885    0.2204    0.1187    0.0797    0.0494    0.0314    0.0229    0.0178    0.0163] ./ 0.621747641870 .* pi/180;
        phase   = [1.2876    6.0892    5.5074    1.7336    2.0192    0.4411    5.1749    3.4146    1.0656    3.4793];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
	case 'ftn mf simona zaal norm goed'
        nd      = [6         13        27        41        53        73        103       139       194       229]';
        Ad      = [0.6984    0.4885    0.2204    0.1187    0.0797    0.0494    0.0314    0.0229    0.0178    0.0163] ./ 0.63247279450621496000 .* pi/180;
        phase   = [1.2876    6.0892    5.5074    1.7336    2.0192    0.4411    5.1749    3.4146    1.0656    3.4793];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
	case 'SIN2_H'
        nd      = [8 16];
        Ad      = [3.538 2.289] .* pi/180;
        phase   = [0 0];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
    case 'SIN2_NH'
        nd      = [8 15];
        Ad      = [3.538 2.430] .* pi/180;
        phase   = [0 0];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
    case 'SIN3_H'
        nd      = [8 16 24];
        Ad      = [3.538 2.289 1.445] .* pi/180;
        phase   = [0 0 0];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
    case 'SIN3_NH'
        nd      = [8 15 25];
        Ad      = [3.538 2.430 1.370] .* pi/180;
        phase   = [0 0 0];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
    case 'SIN4_H'
        nd      = [8 16 24 32];
        Ad      = [3.538 2.289 1.445 0.967] .* pi/180;
        phase   = [0 0 0 0];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
    case 'SIN4_NH'
        nd      = [8 15 25 31];
        Ad      = [3.538 2.430 1.370 1.013] .* pi/180;
        phase   = [0 0 0 0];
        ftn     = z.Ktn * disturbanceSignals2('multisine',model,'Td',81.92,'nd',nd,'Ad',Ad,'phase',phase);
	otherwise
        error('The target noise signal ''%s'' does not exist.\n\tSee <a href="matlab:open standardTargetNoiseSignal">standardTargetNoiseSignal</a> for options.',name)
end
