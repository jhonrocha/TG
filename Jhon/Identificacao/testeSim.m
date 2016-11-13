clear all; clc;
main;
% Minimum Fase
hp1 = 13.5199;
hp2 = 14.0934;
hp3 = 1.8014;
hp4 = 1.5535;

h1 = 13.5199;
h2 = 14.0934;
h3 = 1.8014;
h4 = 1.5535;

h01 = hp1 + h1;
h02 = hp2 + h2;
h03 = hp3 + h3;
h04 = hp4 + h4;

v01 = 3.15;
v02 = 3.15;
k1 = 3.33;
k2 = 3.35;

y1 = 0.70;
y2 = 0.60;

% Entradas do sistema
samp_time = 0.01;
final_time = 1200;
tot_samps = final_time/samp_time;
t = linspace(0, final_time, tot_samps);

vi1 = ones(tot_samps/8,1); 
vi2 = ones(tot_samps/8,1); 
v1 = ones(tot_samps,1);
v2 = ones(tot_samps,1);

% v = [v01*v1 v02*v2];
v = [v01*vi1 v02*vi2;
    (v01+0.5)*vi1 (v02+0.5)*vi2;
    (v01+0.5)*vi1 (v02+0.5)*vi2;
    (v01+0.5)*vi1 (v02+0.5)*vi2;
    (v01+0.5)*vi1 (v02+0.5)*vi2;
    v01*vi1 v02*vi2;
    v01*vi1 v02*vi2;
    v01*vi1 v02*vi2];

% Simula��o do Sistema Linearizado
load simulacao.mat
sys = ss(Ai,Bi,eye(4),0)
[y, t2] = lsim(sys,inputs,t,[h01 h02 h03 h04]);
s = [ y(:,1)-hp1 y(:,2)-hp2 y(:,3)-hp3 y(:,4)-hp4];
inputs = v;
outputs = s;
% save s
figure
%plot(t, y(:,1), '-', t, y(:,2));
grid on
hold on
plot(t, s(:,1), '--red', t, s(:,2),'--blue');
legend('H1','H2','dH1','dH2');
title('Linear Mínima Fase');
ylabel('Altura (cm)');
xlabel('Tempo (s)');