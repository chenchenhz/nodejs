function y = interplotzero(X,Y,method)
  zeroindex = find(~Y);
  nonzeroindex = find(Y);
  y = 1:X(end);
  y(X) = Y;
  interpdata = interp1(X(nonzeroindex), Y(nonzeroindex), zeroindex, ...
                       method);
  y(nonzeroindex) = interpdata;
