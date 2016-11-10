h01 = 13.5199;
h02 = 14.0934;
h03 = 1.8014;
h04 = 1.5535;


% Fuzzy Sets
vec_h1 = [h01];
vec_h2 = [h02];

% System to Each Point
[Ai, Bi, vec_v1, vec_v2, vec_h3, vec_h4] = fuzzy_pontos_v2(vec_h1,vec_h2);

A = Ai;
B = Bi;
C = [ 1 0 0 0;
      0 1 0 0];
D = zeros(2);
I2 = eye(2);
I6 = eye(6);
Z2 = zeros(2);
Z4_2 = zeros(4,2);
Q = I6;
R = I2;

sys = ss(A,B,C,D);
[Kt,S,e] = lqi(sys,Q,R);
K = -Kt(:,1:4)
Ki = -Kt(:,5:6)

Ac = [(A+B*K) B*Ki;
        -C     z2];

Bc = [Z4_2; I2];
Cc = [C Z2];
Dc = Z2;

%% Entradas do sistema
samp_time = 0.01;
final_time = 1200;
tot_samps = final_time/samp_time;
t = linspace(0, final_time, tot_samps);

v1 = 15*ones(tot_samps,1);
v2 = 15*ones(tot_samps,1);
v = [v1 v2];
sys_cl = ss(Ac,Bc,Cc,Dc)
[y, t, x] = lsim(sys_cl,v,t,[h01 h02 h03 h04 0 0]);
s = [ y(:,1)-h01 y(:,2)-h02 ];

plot(t,y(:,1),'-r',t,y(:,2),'-b')
title('Linear Fase Minima');
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('H1','H2');
