close all,
clear all,
clc

%CONTROLE LQR COM AÇÃO INTERGAL ROBUSTA MULTIVARIÁVEL OTIMIZADO VIA DESIGUALDADES MATRICIAIS LINEARES APLICADO AO TANQUE QUÁDRUPO

lambda_1 = 0.7363;
lambda_2 = 0.7577;
T1 = 56.0225;
T2 = 55.9087;
T3 = 345.3168;
T4 = 165.7055;

k1A1 = 0.4047;
k1A4 = 0.5555;
k2A2 = 0.4870;
k2A3 = 0.5453;

A3A1 = 0.3908;
A4A2 = 1.6651;

A = [-1/T1 0 A3A1/T3 0 ; 0 -1/T2 0 A4A2/T4 ; 0 0 -1/T3 0 ; 0 0 0 -1/T4];
B = [lambda_1*k1A1 0 ; 0 lambda_2*k2A2 ; 0 (1-lambda_2)*k2A3 ; (1-lambda_1)*k1A4 0];
C = [1 0 0 0 ; 0 1 0 0];
D = [0 0 ; 0 0];

% APLICAÇÃO DO CONTROLE DE AÇAO INTEGRAL
BB = [B ; zeros(size(D))];
AA = [A zeros(size(B)); -C zeros(size(D))];
 
% MATRIZES DE PONDERAÇÃO R e Q
R = 100*[1 0 ; 0 1];
Q = [1 0 0 0 0 0 ; 0 1 0 0 0 0 ; 0 0 1 0 0 0 ; 0 0 0 1 0 0 ; 0 0 0 0 0.1 0 ; 0 0 0 0 0 0.1];

% RESTRIÇOES LMIs
LMIs = set([]);
X = sdpvar(2,2,'symmetric');
Y = sdpvar(2,6,'full');
P = sdpvar(6,6,'symmetric');
mu = sdpvar(1,1,'full');

% RESTRIÇOES DE PROJETO
POS = 0.01;
Ts = 500;
zeta = (log(POS))/(sqrt((pi^2)+((log(POS))^2)));
wn = 4/(zeta*Ts);
sigma_p = zeta*wn
teta = pi - acos(zeta)

% LMIs
T1 = AA*P + P*AA' - BB*Y - Y'*BB';
T2 = AA*P - P*AA' - BB*Y + Y'*BB';
LMIs = LMIs + set([T1*sin(teta) T2*cos(teta) ; -T2*cos(teta) T1*sin(teta)] < 0);
LMIs = LMIs + set(AA*P + P*AA' - BB*Y - Y'*BB' + 2*sigma_p*P < 0);

LMIs = LMIs + set(P > 0);
LMIs = LMIs + set([X sqrt(R)*Y; Y'*sqrt(R) P] > 0);
    
LMIs = LMIs + set(trace(Q*P)+trace(X) < mu);
    
% Saturaçao  
saturacao = 2;
    
T311 = 1;
T321 = [1;1;1;1;0;0];
T312 = T321';
T322 = P;
LMIs = LMIs + set([T311 T312 ; T321 T322] >= 0);
    
T411 = P;
T421 = Y(1,:);
T412 = T421';
T422 = saturacao^2;
LMIs = LMIs + set([T411 T412 ; T421 T422] >= 0);
    
T511 = P;
T521 = Y(2,:);
T512 = T521';
T522 = saturacao^2;
LMIs = LMIs + set([T511 T512 ; T521 T522] >= 0);    
    
obj = mu;
%sol = solvesdp(LMIs,[]);
sol = solvesdp(LMIs,mu,sdpsettings('verbose',0,'solver','sedumi'));

%checkset(LMIs)

if min(checkset(LMIs))> -1e-8
    KK = double(Y)*inv(double(P))
else
    display ('Nao factível')
end
    p = min(checkset(LMIs))

% GANHOS DE REALIMENTAÇAO DE ESTADOS
K = KK(1:2,1:4)
Ki = -KK(1:2,5:6)

Amf = [A-B*K B*Ki ; -C zeros(size(D))];
Bmf = [zeros(size(B)) ; eye(size(D))];
Cmf = [C zeros(size(D))];
Dmf = D;

x0 = zeros(6,1);
t = 0:1:2000;
comp_t = length(t);

r = [7.17*ones(1,ceil(comp_t/4)) 8*ones(1,ceil(3*comp_t/4)-1) ; 9.34*ones(1,ceil(3*comp_t/4)) 10*ones(1,ceil(comp_t/4)-1)];

sys = ss(A,B,C,D);
sysc = ss(Amf,Bmf,Cmf,Dmf);
[y,t,x] = lsim(sysc,r,t,x0);
u = (-KK*x')';

%VALORES DE SIGMA DOS AUTOVALORES DE MALHA FECHADA
sigmas = eig(Amf)

%ÂNGULOS DE FASE
tetas = imag(sigmas)./real(sigmas)

% Respostas no tempo
figure(1),
subplot(2,1,1),
plot(t,r(1,:)','k-.',t,y(:,1),'k-','linewidth',2),
axis([0 comp_t-1 0 15]),
xlabel('Tempo(s)'),
ylabel('Altura h_1 (cm)'),
legend('ref','saída h_1'),
grid,
title('ALTURAS DOS TANQUES'),
subplot(2,1,2),
plot(t,r(2,:)','k-.',t,y(:,2),'k-','linewidth',2),
axis([0 comp_t-1 0 15]),
xlabel('Tempo(s)'),
ylabel('Altura h_2 (cm)'),
legend('ref','saída h_2'),
grid,

figure(2),
subplot(2,1,1),
plot(t,u(:,1),'k-','linewidth',2),
axis([0 comp_t-1 -5 10]),
xlabel('Tempo(s)'),
ylabel('u_1 (V)'),
grid,
title('TENSÕES DE ENTRADA'),
subplot(2,1,2),
plot(t,u(:,2),'k-','linewidth',2),
axis([0 comp_t-1 -5 10]),
xlabel('Tempo(s)'),
ylabel('u_2 (V)'),
grid,
