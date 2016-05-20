function y = interplotzero(X,Y,method)
  y = zeros(X(end),1);
  y(X) = Y;
  zeroindex = find(~y);
  nonzeroindex = find(Y);
  interpdata = interp1(X(nonzeroindex), Y(nonzeroindex), zeroindex, ...
                       method);
  y(zeroindex) = interpdata;
