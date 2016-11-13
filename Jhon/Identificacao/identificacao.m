display('Simulating Model');
load ident_4000_full.mat
inicio = 1;
final = 20000;
% figure
% plot(inputs.Time(inicio:final),inputs.Data(inicio:final,1));
% figure
% plot(inputs.Time(inicio:final),inputs.Data(inicio:final,2));
figure
plot(outputs.Time(inicio:final),outputs.Data(inicio:final,1));
title('Tank4');
figure
plot(outputs.Time(inicio:final),outputs.Data(inicio:final,2));
title('Tank3');
figure
plot(outputs.Time(inicio:final),outputs.Data(inicio:final,3));
title('Tank2');
figure
plot(outputs.Time(inicio:final),outputs.Data(inicio:final,4));
title('Tank1');

% display('Setting idData');
% samp_time = 0.2;
% tanks = iddata(outputs.Data,inputs.Data, samp_time);
% tanks.InputName = {'V1', 'V2'};
% tanks.OutputName = {'H1', 'H2', 'H3', 'H4'};
% tanks.TimeUnit = 'seconds';
% tanks.InputUnit = {'V', 'V'};
% tanks.OutputUnit = {'cm', 'cm', 'cm', 'cm'};
% get(tanks);
% 
% % ze = detrend(samp);
% display('Estimating');
% amostra = tanks(inicio:final);
% m1 = ssest(amostra);
% 
% display('Simulating Results');
% [yEst, tEst] = lsim(m1,inputs.Data,outputs.Time,[0 0 0 0]);
% % plot(tEst, yEst(:,1), '--red', tEst, yEst(:,2),'--blue');
% plot(tEst, yEst(:,3));