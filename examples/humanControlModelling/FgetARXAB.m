function [A,B] = FgetARXAB(par, ny, nu, na, nb, nk)
% Create A and B polynomials using model orders and parameter vector.

%   Author(s): Rajiv Singh
%   Copyright 1986-2011 The MathWorks, Inc.
%   $Revision: 1.1.10.1 $ $Date: 2011/10/22 21:44:39 $

A = num2cell(eye(ny)); B = num2cell(zeros(ny,nu));
Offset = 0;
for ky = 1:ny
   if any(na(:))
      for ky2 = 1:ny
         A{ky, ky2} = [A{ky, ky2}, par(Offset+1:Offset+na(ky,ky2))];
         Offset = Offset+na(ky,ky2);
      end
   end
   
   if any(nb(:))
      for ku = 1:nu
         B{ky, ku} = [zeros(1,nk(ky,ku)),par(Offset+1:Offset+nb(ky,ku))];
         Offset = Offset+nb(ky,ku);
      end
   end
end