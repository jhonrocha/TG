% NOT working!
function output = controleAl4TanksE1()
A=[0.9393   -0.1778    0.0225    0.0571;
   -0.0041    0.8500    0.0215    0.0396;
   -0.1032   -0.7817    0.9478    0.2216;
    0.1469    0.9801    0.0230    0.7180];

B=[0.0283    0.0196;
    0.0373   -0.0108;
    0.1750    0.0444;
   -0.2160   -0.0482];

% A=[0.9994   -0.0008    0.0006   -0.0003;
%     0.0005    0.9995   -0.0015    0.0015;
%    -0.0013    0.0003    1.0008   -0.0008;
%    -0.0006   -0.0018    0.0029    0.9974];
% 
% B=1.0e-03 *[0.2508         0;
%               0    0.0854;
%               0    0.2105;
%               0.3246         0];

C = [1 0 0 0];
%new LMI system
LMIs = [];

Aa = [A zeros(4,1); -C 0];
Ba = [B; zeros(1,2)];

%create the variables
S = sdpvar(5,5,'symmetric');
L = sdpvar(2,5,'full');

LMIs = [LMIs, S>0];

% LMIs:
LMIs = [LMIs, Aa*S + S*Aa' + Ba*L + L'*Ba' <0];

% Solving
sol = optimize(LMIs,0,sdpsettings('verbose',0,'solver','sedumi'));

W = double(S)
Z = double(L)
K = Z*inv(W)
K1 = K(:,1:4)
K2 = K(:,5:5)

% Timing
samp_time = 0.1;
final_time = 150;
tot_samps = final_time/samp_time;
t = 0:samp_time:final_time;

% Getting Reference to Plot
for idx = 1:numel(t)
    v1(idx) = r1(t(idx));
    v2(idx) = r2(t(idx));
end

inputs = [v1' v2'];
% Ac = (A+B*K);
Ac = [(A+B*K1) B*K2; -C 0];
Bc = [zeros(4,2); 1 0];
% [tv,Hv] = ode15s(@quadtank,t,[h1 h2 h3 h4]);
sys = ss(Ac,Bc,eye(5),0)
[y, t] = lsim(sys,inputs,t,[2 1 -1 0 0]);

% figure;
% plot(t,y(:,1),'-b',t,inputs(:,1),'-r');
% ylabel('Altura (cm)');
% xlabel('Tempo (s)');
% figure;
% plot(t,y(:,2),'-b',t,inputs(:,2),'-r');
% ylabel('Altura (cm)');
% xlabel('Tempo (s)');
plot(t,y(:,1),'-b',t,y(:,2),'-r',t,y(:,3),'-g',t,y(:,4),'-y',t,y(:,5),'--b');
legend('h1','h2','h3','h4','eh1');
ylabel('Altura (cm)');
xlabel('Tempo (s)');
% figure;
% plot(t,y(:,3),'-b');
% ylabel('Altura (cm)');
% xlabel('Tempo (s)');
% figure;
% plot(t,y(:,4),'-b');
% ylabel('Altura (cm)');
% xlabel('Tempo (s)');
% figure;
% plot(t,y(:,5),'--r');
% ylabel('Altura (cm)');
% xlabel('Tempo (s)');
% figure;
% plot(t,y(:,6),'--r');
% ylabel('Altura (cm)');
% xlabel('Tempo (s)');
% /////////////////////////////////////
% Reference Inputs
% /////////////////////////////////////
function r11 = r1(t)
    r11 = 2;
end
   
function r22 = r2(t)
    r22 = 0;
end

end