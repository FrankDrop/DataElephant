function [X, w, dw, dt, X2, w2, fs, wNyq, iNyq, Ns, df] = fftx(x, t, dt)
% Extended Fast Fourier Transform
% [X, w, dw, dt, X2, w2, fs, wNyq, iNyq, Ns, df] = fftx(x, t, dt)
%
% Arguments:
% x  = discrete sampled signal
% t  = discrete sampled time in seconds
%
% Optional arguments
% dt = sample time in seconds
% 
% Return values:
% X    = onesided fast fourier transform up to the Nyquist frequency
% w    = onesided frequency vector up to the Nyquist frequency (rad/s)
% dw   = frequency interval
% dt   = sample time
% X2   = twosided fast fourier transform
% w2   = twosided frequency vector (rad/s)
% fs   = sample frequency
% wNyq = Nyquist frequency (rad/s)
% iNyq = index of Nyquist frequency
% Ns   = number of samples
% df   = frequency interval

Ns = length(x);

if (nargin == 2)
   % no dt present, let's guess it from the time vector
   % shift t to t(1) = 0:
   t = t-t(1);

   % calculate mean and variance of dt:
   dt_vec  = t(2:end) - t(1:end-1);
   mean_dt = mean(dt_vec);
   var_dt  = var(dt_vec);

   % check that deviation is smaller than tollerance percent:
   tol = 0.010;    % percent tollerance
   if ( sum(abs(dt_vec-mean_dt)/mean_dt > tol) > 0 )
      disp(['..    dt     (dt-mean)/mean']);
      for cntr = 1:length(dt_vec)
         if (abs(dt_vec(cntr) - mean_dt)/mean_dt > tol)
            disp([dt_vec(cntr) abs(dt_vec(cntr)-mean_dt)/mean_dt ]);
         end
      end
      disp(['accuracy tolerance of dt exceeded ', num2str(tol)]);
      disp('using new t with average dt instead');
      t = (0:1:Ns-1)*mean_dt;
   end

   dt    = mean_dt;
   Tmeas = Ns*dt;

elseif (nargin == 3)

    error('Doing this seems to be a bit dangerous.')
    % dt is present, let's use it!
    t = 0:dt:(Ns-1)*dt;
    Tmeas = Ns*dt;
end

fs    = 1/dt;

dw    = 2*pi/Tmeas;
df    = 1/Tmeas;

ws    = (Ns-1)*dw;
w2    = 0:dw:ws;

X2    = fft(x);


if (mod(Ns,2) == 0)
   %% Ns even

   % Ns = 20

   %    index        dw
   %    1 mean       0
   %    2  t/m 11    1*dw  t/m 10*dw
   %    11 t/m 20    10*dw t/m 19*dw

   % Nyquist freq: 10*dw
   wNyq = Ns/2 * dw;

   % Nyquist index: 11
   iNyq = Ns/2 + 1;
   
else
   %% Ns odd

   % Ns = 21

   %    index        dw
   %    1 mean       0
   %    2  t/m 11    1*dw  t/m 10*dw
   %    12 t/m 21    11*dw t/m 20*dw

   % Nyquist freq: 10*dw
   wNyq = (Ns-1)/2 * dw;

   % Nyquist index: 11
   iNyq = (Ns-1)/2 + 1;
   
end

% onesided FFT:
X = X2(1:iNyq);
w = w2(1:iNyq);

end