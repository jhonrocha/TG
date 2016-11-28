% Working!
function output = controleAlocacao()
A = [0 1 0;
     0 0 1;
     -1 2 -1];
B = [0 0;
      0 1;
      1 0];

C = [1 0 0];
%new LMI system
LMIs = [];

Aa = [A zeros(3,1); -C 0];
Ba = [B; zeros(1,2)];
% Bwa = [Bw zeros(2); zeros(2) -eye(2)];
Ca = [C 0];

%create the variables
S = sdpvar(4,4,'symmetric');
L = sdpvar(2,4,'full');

LMIs = [LMIs, S>0];

% LMIs:
LMIs = [LMIs, Aa*S + S*Aa' + Ba*L + L'*Ba' <0];

% Solving
sol = optimize(LMIs,0,sdpsettings('verbose',0,'solver','sedumi'));

W = double(S)
Z = double(L)
K = Z*inv(W)
K1 = K(:,1:3)
K2 = K(:,4:4)
% Timing
samp_time = 0.1;
final_time = 20;
tot_samps = final_time/samp_time;
t = 0:samp_time:final_time;

% Getting Reference to Plot
for idx = 1:numel(t)
    v1(idx) = r1(t(idx));
    v2(idx) = r2(t(idx));
end

inputs = [v1' v2'];
Ac = [(A+B*K1) B*K2; -C 0];
Bc = [zeros(3,2); 1 0];
% [tv,Hv] = ode15s(@quadtank,t,[h1 h2 h3 h4]);
sys = ss(Ac,Bc,eye(4),0)
[y, t] = lsim(sys,inputs,t,[2 1 -1 0]);

% figure;
% plot(t,y(:,1),'-b',t,inputs(:,1),'-r');
% ylabel('Altura (cm)');
% xlabel('Tempo (s)');
% figure;
% plot(t,y(:,2),'-b',t,inputs(:,2),'-r');
% ylabel('Altura (cm)');
% xlabel('Tempo (s)');
plot(t,y(:,1),t,y(:,2),t,y(:,3),t,y(:,4),'--r');
legend('h1','h2','h3','eh1');
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
    r11 = 10;
end
   
function r22 = r2(t)
    r22 = 5;
end

end
