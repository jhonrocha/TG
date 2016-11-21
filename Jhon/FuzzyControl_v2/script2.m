% UnB, Brasília: 26 de novembro de 2014
% Aluno: Jhonantans Moraes Rocha
% Matrícula: 11/0014090
function outPut = script2()
% clear all; clc;
% warning off;

% Fuzzy Sets
vec_h1 = [10];
vec_h2 = [10];

% System to Each Point
[Ai, Bi, vec_v1, vec_v2, vec_h3, vec_h4] = fuzzy_pontos_v2(vec_h1,vec_h2);
C = [1 0 0 0; 0 1 0 0];
D = zeros(2);
% ------ Utilizando o Lema 8 da realimentação de estados:
% Tolerância
% tolerance = 1e-7;

%new LMI system
LMIs = [];

%create the variables
vec_M = [];

W = sdpvar(6,6,'symmetric');
M = sdpvar(2,6,'full');
mu = sdpvar(1);
LMIs = [LMIs, W>0];
A = Ai(:,:,1,1);
B = Bi(:,:,1,1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Aa = [ A    zeros(4,2);
      -C    zeros(2)];
Ba = [B; eye(2)];
Ca = [C zeros(2)]; %2x6
T11 = Aa*W + W*Aa' + Ba*M + M'*Ba'; %6x6
T12 = W*Ca'; %6*2
T13 = zeros(6); %6x6
T22 = -eye(2);
T23 = zeros(2,6);
T33 = -mu*eye(6);
LMIs = [LMIs, [T11 T12 T13; T12' T22 T23; T13' T23' T33]<0]
obj = mu;
sol = solvesdp(LMIs,obj,sdpsettings('verbose',1,'solver','sedumi'));
K = double(M)*inv(double(W))
Kp = K(:,1:4);
Ke = K(:,5:6);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% % Lyapunov matrix
% W = sdpvar(4,4,'symmetric');
% LMIs = [LMIs, W>0];
% 
% for m= 1:length(vec_h1)
%     for n= 1:length(vec_h2)
%         M = sdpvar(2,4,'full');
%         vec_M = [vec_M M];
% 
%         A = Ai(:,:,m,n)
%         B = Bi(:,:,m,n)
%         T12 = M'*B' + W*A';
%         T21 = A*W + B*M;
%         LMIs = [LMIs, [W T12, T21 W]];
%     end
% end
% obj = trace(W);
% sol = optimize(LMIs,obj,sdpsettings('verbose',1,'solver','sedumi'));
% K = value(M)*inv(value(W))

% Solving
samp_time = 0.01;
final_time = 10;
tot_samps = final_time/samp_time;
t = linspace(0, final_time, tot_samps);

% Getting Reference to Plot
for idx = 1:numel(t)
    i1(idx) = r1(t(idx));
    i2(idx) = r2(t(idx));
end

inputs = [i1' i2'];

Ac = [(A-B*Kp) B*Ke; -C zeros(2)];
Bc = [zeros(4,2); eye(2)];
% [tv,Hv] = ode15s(@quadtank,t,[h1 h2 h3 h4]);
sys = ss(Ac,Bc,Ca,0);
[y, t] = lsim(sys,inputs,t,[0 0 0 0 0 0]);

figure;
plot(t,y(:,1),'--r');
ylabel('Altura (cm)');
xlabel('Tempo (s)');

% /////////////////////////////////////
% ---- Inputs ---- %
% /////////////////////////////////////
function r11 = r1(t)
%     if (t < 150)
%         r11 = 15;
%     elseif (t > 150)&&(t < 300)
%         r11 = 20;
%     elseif (t > 300)&&(t < 450)
%         r11 = 10;
%     else
%         r11 = 20;
%     end
    r11 = 3;
end
   
function r22 = r2(t)
%     if (t < 150)
%         r22 = 10;
%     elseif (t > 150)&&(t < 300)
%         r22 = 15;
%     elseif (t > 300)&&(t < 450)
%         r22 = 5;
%     else
%         r22 = 15;
%     end
    r22 = 2;
end

end