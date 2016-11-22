% NOT working!
function output = t()
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

% A =[0.9989   -0.0005    0.0006   -0.0001;
%     0.0004    0.9994   -0.0012    0.0012;
%    -0.0005   -0.0002    1.0003   -0.0003;
%    -0.0001   -0.0020    0.0021    0.9985]
% 
% Bu =[0.0001    0.0001;
%     0.0014   -0.0013;
%     0.0006   -0.0004;
%     0.0001    0.0002]

A =[0 1 0 0;
    0 0 1 0;
    0 0 0 1;
    -1 -2 3 -1]
Bu = [0; 0; 0; 1]
Bw = [0 0;
      0 0;
      1 0;
      0 1]
Cz = [1 0 0 0;
      0 1 0 0]
Du = [0; 0.1]
% ------ Utilizando o Lema 8 da realimentação de estados:
% Tolerância
tolerance = 1e-7;

%new LMI system
LMIs = [];
%create the variables
Y = sdpvar(1,4,'full');

% Lyapunov matrix
N = sdpvar(2,2,'symmetric');
Q = sdpvar(4,4,'symmetric');

LMIs = [LMIs, Q>0];
% LMIs = [LMIs, N>0];
% LMIs:
LMIs = [LMIs, [N (Cz*Q)+(Du*Y); (Q*(Cz'))+((Y')*(Du')) Q]>0];
LMIs = [LMIs, [Q*(A') + A*Q + (Y')*(Bu') + Bu*Y + Bw*(Bw')]<0];
obj = trace(N);

% Solving
sol = optimize(LMIs,obj,sdpsettings('verbose',0,'solver','sedumi'));

% p=min(checkset(LMIs));

%capturing the solutions (if ones exist)
% if p > -tolerance;
    output.feas = 1;
    Z = double(Y)
    W = double(Q)
    trace(double(N))
    K = Z*inv(W)
    K1 = K(:,1:4)
    K2 = K(:,5:6)
%     K1 = Z*inv(W)
%     K2 = Z
    display('Done')
% else
%     display('Error MSG!')
% end

% Timing
samp_time = 0.01;
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


