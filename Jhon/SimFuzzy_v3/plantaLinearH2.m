% NOT working!
function output = plantaLinearH2()
clear all; clc;
warning off;

% Modelo de controle inicial:
% A = [-0.0251         0    0.0719         0;
%          0   -0.0176         0    0.0508;
%          0         0   -0.0719         0;
%          0         0         0   -0.0508];
% Bu = [0.0833         0;
%          0    0.0628;
%          0    0.0479;
%     0.0312         0];

A =[0.9989   -0.0005    0.0006   -0.0001;
    0.0004    0.9994   -0.0012    0.0012;
   -0.0005   -0.0002    1.0003   -0.0003;
   -0.0001   -0.0020    0.0021    0.9985]

Bu =[0.0001    0.0001;
    0.0014   -0.0013;
    0.0006   -0.0004;
    0.0001    0.0002]

Cz = [1 0 0 0; 0 1 0 0];

%------ Estado aumentado:
% Aa = [A 0; -C 0]
% Bua = [Bu; 0]
% Cza = [Cz 0]
Aa = [A zeros(4,2); -Cz zeros(2)];
Bua = [Bu; zeros(2)];
Cza = [Cz zeros(2)];

% ------ Utilizando o Lema 8 da realimentação de estados:
% Tolerância
tolerance = 1e-7;

%new LMI system
LMIs = [];

% %create the variables
% Z = sdpvar(2,4,'full');
% 
% % Lyapunov matrix
% % W = sdpvar(6,6,'symmetric');
% mu = sdpvar(1);
% 
% W = sdpvar(4,4,'symmetric');
% LMIs = [LMIs, W>0];
% 
% % % LMIs:
% Q = eye(2);
% R = eye(2);
% T11 = A*W - Bu*Z + W*A' - Z'*Bu';
% T21 = R*Z;
% T31 = Q*Cz*W;
% T22 = -R;
% T32 = zeros(2);
% T33 = -Q;
% LMIs = [LMIs, [T11 T21' T31'; T21 T22 T32'; T31 T32 T33]<0];
% obj = trace(W);

%create the variables
Y = sdpvar(2,6,'full');

% Lyapunov matrix
% W = sdpvar(6,6,'symmetric');
N = sdpvar(2,2,'symmetric');
Q = sdpvar(6,6,'symmetric');

% LMIs = [LMIs, Q>0];
% LMIs:
LMIs = [LMIs, [N Cza*Q; Q*Cza' Q]>0];
LMIs = [LMIs, [Q*Aa' + Aa*Q + Y'*Bua' + Bua*Y]<0];
obj = trace(N);

% Solving
sol = optimize(LMIs,obj,sdpsettings('verbose',0,'solver','sedumi'));

p=min(checkset(LMIs));

%capturing the solutions (if ones exist)
if p > -tolerance;
    output.feas = 1;
    Z = double(Y);
    W = double(Q);
    K = Z*inv(W)
    K1 = K(:,1:4)
    K2 = K(:,5:6)
%     K1 = Z*inv(W)
%     K2 = Z
    display('Done')
else
    display('Error MSG!')
end
trace(double(N))
% Timing
samp_time = 0.01;5
final_time = 50;
tot_samps = final_time/samp_time;
t = 0:samp_time:final_time;

% Getting Reference to Plot
for idx = 1:numel(t)
    v1(idx) = r1(t(idx));
    v2(idx) = r2(t(idx));
end

inputs = [v1' v2'];
Ac = [(A+Bu*K1) Bu*K2; -Cz zeros(2)];
Bc = [zeros(4,2); eye(2)];
% [tv,Hv] = ode15s(@quadtank,t,[h1 h2 h3 h4]);
sys = ss(Ac,Bc,Cza,zeros(2),samp_time)
[y, t] = lsim(sys,inputs,t,[0 0 0 0 0 0]);
figure;
plot(t,y(:,1),'--r');
ylabel('Altura (cm)');
xlabel('Tempo (s)');
figure;
plot(t,y(:,2),'--r');
ylabel('Altura (cm)');
xlabel('Tempo (s)');
% /////////////////////////////////////
% Reference Inputs
% /////////////////////////////////////
function r11 = r1(t)
    r11 = 10;
end
   
function r22 = r2(t)
    r22 = 5;
end

end


