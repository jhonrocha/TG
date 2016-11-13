clear;clc;
display('Simulating Model');
main
load simulacao.mat
% simFmLinear
% figure
% plot(t,i1,'-r');
% figure
% plot(t,i2,'--b');
% figure
% plot(t,Hv(:,1),'-r');
% figure
% plot(t,Hv(:,2),'--b');

display('Setting idData');
tanks = iddata(outputs,inputs, samp_time);
tanks.InputName = {'V1', 'V2'};
tanks.OutputName = {'H1', 'H2', 'H3', 'H4'};
tanks.TimeUnit = 'seconds';
tanks.InputUnit = {'V', 'V'};
tanks.OutputUnit = {'cm', 'cm', 'cm', 'cm'};
get(tanks);

% ze = detrend(samp);
display('Estimating');
m1 = ssest(tanks);

display('Simulating Results');
[yEst, tEst] = lsim(m1,inputs,t,[0 0 0 0]);
plot(tEst, yEst(:,1), '--red', tEst, yEst(:,2),'--blue');