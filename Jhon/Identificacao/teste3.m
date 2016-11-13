%% Tank Especifications
A1 = 28;
A2 = 32;
A3 = 28;
A4 = 32;

a1 = 0.071;
a2 = 0.057;
a3 = 0.071;
a4 = 0.057;

%kc = 0.5;
kc = 1;
g = 981;

%% Minimum Fase
hp1 = 13.5199;
hp2 = 14.0934;
hp3 = 1.8014;
hp4 = 1.5535;

h1 = 13.5199;
h2 = 14.0934;
h3 = 1.8014;
h4 = 1.5535;

% h1 = 0;
% h2 = 0;
% h3 = 0;
% h4 = 0;

% h1 = 5;
% h2 = 5;
% h3 = 2;
% h4 = 2;

% h1 = 12.4;
% h2 = 12.7;
% h3 = 1.8;
% h4 = 1.4;

% h01 = 12.4;
% h02 = 12.7;
% h03 = 1.8;
% h04 = 1.4;
% dh1 = h01 - hp1
% dh2 = h02 - hp2
% dh3 = h03 - hp3
% dh4 = h04 - hp4

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

%% Linearized State-Space
T1 = (A1/a1)*sqrt(2*hp1/g)
T2 = (A2/a2)*sqrt(2*hp2/g)
T3 = (A3/a3)*sqrt(2*hp3/g)
T4 = (A4/a4)*sqrt(2*hp4/g)

c1 = T1*k1*kc/A1;
c2 = T2*k2*kc/A2;
% x' = A*x + B*u
% y = C*x + D*u
% G = C*(inv(sI - A))*B

A = [-(1/T1) 0 (A3/(A1*T3)) 0;
     0 -(1/T2) 0 (A4/(A2*T4));
     0 0 -(1/T3) 0;
     0 0 0 -(1/T4)];
 
B = [y1*k1/A1 0;
    0 y2*k2/A2;
    0 (1 - y2)*k2/A3;
    (1 - y1)*k1/A4 0];

C = eye(4);

%% Entradas do sistema
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

v = [v(:,1)-v01 v(:,2)-v02];

% Simula��o do Sistema Linearizado
sys = ss(A,B,C,0)
[y, t2] = lsim(sys,v,t,[0 0 0 0]);
s = [ y(:,1)+hp1 y(:,2)+hp2 y(:,3)+hp3 y(:,4)+hp4];
inputs = v;
outputs = s;
% save s
figure
%plot(t, y(:,1), '-', t, y(:,2));
grid on
hold on
plot(t, s(:,1), '--red', t, s(:,2),'--blue');
% plot(t, y(:,1), '--red', t, y(:,2),'--blue');
legend('H1','H2','dH1','dH2');
title('Linear Mínima Fase');
ylabel('Altura (cm)');
xlabel('Tempo (s)');