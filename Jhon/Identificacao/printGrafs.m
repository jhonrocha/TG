figure
plot(outputs.Time(inicio:final),outputs.Data(inicio:final,1));
hold on
grid on
plot(tEst2(inicio:final), yEst2(inicio:final,1),'-r');
title('Nível 1');

figure
plot(outputs.Time(inicio:final),outputs.Data(inicio:final,2));
hold on
grid on
plot(tEst2(inicio:final), yEst2(inicio:final,2),'-r');
title('Nível 2');

figure
plot(outputs.Time(inicio:final),outputs.Data(inicio:final,3));
hold on
grid on
plot(tEst2(inicio:final), yEst2(inicio:final,3),'-r');
title('Nível 3');

figure
plot(outputs.Time(inicio:final),outputs.Data(inicio:final,4));
hold on
grid on
plot(tEst2(inicio:final), yEst2(inicio:final,4),'-r');
title('Nível 4');

%   4000
%   a = 
%                x1          x2          x3          x4
%    x1      0.9985  -0.0002098   0.0007881   0.0001684
%    x2    0.000169       0.999  -7.159e-05   0.0004413
%    x3   -0.000736   0.0001313           1   0.0001939
%    x4  -0.0009293  -0.0008117     0.00109           1
%  
%   b = 
%                u1          u2
%    x1  -0.0006189   0.0008599
%    x2    0.000715  -0.0005701
%    x3   0.0001636   -2.26e-05
%    x4  -0.0009055     0.00109

%   6000
%   a = 
%                x1          x2          x3          x4
%    x1       0.999      0.0002    0.000456   3.182e-05
%    x2  -0.0001421           1  -0.0001671   0.0002886
%    x3  -0.0005784   0.0003516      0.9999   0.0001039
%    x4   0.0006769   -0.001255   0.0006098      0.9999
%  
%   b = 
%                u1          u2
%    x1  -0.0004175   0.0005107
%    x2   0.0006248  -0.0005959
%    x3   0.0002711  -0.0002032
%    x4  -0.0002449   0.0002294

%   6000 v3
%   a = 
%               x1         x2         x3         x4
%    x1     0.9834    0.02014  -0.007577   -0.00362
%    x2    -0.0117      1.019  -0.009873  -0.003866
%    x3  -0.009733    0.02102     0.9863  -0.004788
%    x4   -0.02114    0.02447  -0.008362     0.9952
%  
%   b = 
%               u1         u2
%    x1  -0.007073   0.009851
%    x2  -0.004253   0.006861
%    x3  -0.002624   0.005544
%    x4  -0.009936    0.01346