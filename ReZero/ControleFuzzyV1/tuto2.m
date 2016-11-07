A = [  -0.0153     0    0.0418         0;
         0   -0.0105         0    0.0317;
         0         0   -0.0418         0;
         0         0         0   -0.0317 ];

B =[0.0833         0;
         0    0.0628;
         0    0.0479;
    0.0312         0];

C = [1 0 0 0;
     0 1 0 0];

D = [0 0;
     0 0];
 
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
        -C     Z2];

Bc = [Z4_2; I2];
Cc = [C Z2];
Dc = Z2;

sys2 = ss(Ac,Bc,Cc,Dc)
step(sys2)

% Simulation Time
final = 120;
t = 0: 0.01: final; 
totalAmostras = (final/0.01)+1;

% References
r1 = 15*ones(totalAmostras,1);
r2 = 15*ones(totalAmostras,1);
r = [r1 r2];

% Initial States
h01 = 13.5199;
h02 = 14.0934;
h03 = 1.8014;
h04 = 1.5535;
hi1 = 0;
hi2 = 0;

% Simulation
[y, t, x] = lsim(sys2,r,t,[h01 h02 h03 h04 hi1 hi2]);
plot(t,y(:,1),'-r',t,y(:,2),'-b')
title('Linear Fase Minima');
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('H1','H2');