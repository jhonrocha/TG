clear
display('Simulating Model');
% load ident_4000_full.mat
load simulation_6000_full.mat
inicio = 1;
final = 10000;

display('Setting idData');
samp_time = 0.2;
tanks = iddata(outputs.Data,inputs.Data, samp_time);
tanks.InputName = {'V1', 'V2'};
tanks.OutputName = {'H1', 'H2', 'H3', 'H4'};
tanks.TimeUnit = 'seconds';
tanks.InputUnit = {'V', 'V'};
tanks.OutputUnit = {'cm', 'cm', 'cm', 'cm'};
get(tanks);

% ze = detrend(samp);
display('Estimating');
amostra = tanks(inicio:final);
A = 0.01*ones(4);
K = 0.01*ones(4);
B = zeros(4,2);
C  = eye(4);
D = zeros(4,2);
m = idss(A,B,C,D,K);
S = m.Structure;
% S.b.Free(1,2) = false;
% S.b.Free(2,1) = false;
% S.b.Free(3,1) = false;
% S.b.Free(4,2) = false;
S.c.Free = false;
S.d.Free = false;
m.Structure = S;
m1 = ssest(amostra,m);

display('Simulating Results');
% [yEst, tEst] = lsim(m1,inputs.Data,outputs.Time,[0 0 0 0]);
sys = ss(m1.a, m1.b, m1.c, m1.d, samp_time);
% [yEst1, tEst1] = lsim(sys,inputs.Data(inicio:final,:),outputs.Time(inicio:final),[0 0 0 0]);
[yEst1, tEst1] = lsim(sys,inputs.Data,outputs.Time,[0 0 0 0]);
% figure
% plot(inputs.Time(inicio:final),inputs.Data(inicio:final,1));
% figure
% plot(inputs.Time(inicio:final),inputs.Data(inicio:final,2));
figure
plot(outputs.Time(inicio:final),outputs.Data(inicio:final,1));
hold on
plot(tEst1, yEst1(:,1));
title('Tank4');
% 
% figure
% plot(outputs.Time(inicio:final),outputs.Data(inicio:final,2));
% hold on
% plot(tEst, yEst(:,2));
% title('Tank3');
% 
% figure
% plot(outputs.Time(inicio:final),outputs.Data(inicio:final,3));
% hold on
% plot(tEst, yEst(:,3));
% title('Tank2');
% 
% figure
% plot(outputs.Time(inicio:final),outputs.Data(inicio:final,4));
% hold on
% plot(tEst, yEst(:,4));
% title('Tank1');