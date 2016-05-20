function y = interplotzero(X,Y,method)
  zeroindex = find(~Y);
  nonzeroindex = find(Y);
  y = zeros(X(end),1);
  y(X) = Y;
  interpdata = interp1(X(nonzeroindex), Y(nonzeroindex), zeroindex, ...
                       method);
  y(zeroindex) = interpdata;
