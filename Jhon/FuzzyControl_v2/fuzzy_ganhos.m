function [outK] = fuzzy_ganhos(vec_h1, vec_h2)
warning off;
% Plant Specs
[A1,A2,A3,A4,a1,a2,a3,a4,g,k1,k2,gamma1,gamma2] = planta();

% C and D
C = [1 0 0 0;
     0 1 0 0];

D = [0 0;
     0 0];
% Auxiliar Matrices
I2 = eye(2);
I4_2 = eye(4,2);
I6 = eye(6);
Z4_2 = zeros(4,2);
Z2 = zeros(2);
Z6 = zeros(6);

% Returns
% outK = zeros(2,4,length(vec_h1),length(vec_h2));
outK = zeros(2,6,length(vec_h1),length(vec_h2));
% outF = zeros(2,4,length(vec_h1),length(vec_h2));
% outG = zeros(2,2,length(vec_h1),length(vec_h2));

%new LMI system
LMIs = [];

%create the variables
vec_M = [];

% % Lyapunov matrix
% X = sdpvar(4,4,'symmetric');
% LMIs = [LMIs, X>0];

% Lyapunov matrix
W = sdpvar(6,6,'symmetric');
mu = sdpvar(1);
LMIs = [LMIs, W>0];


for i1 = 1:length(vec_h1)
    hp1 = vec_h1(i1);
    
    for i2 = 1:length(vec_h2)
        hp2 = vec_h2(i2);

        v2 = ((a1*sqrt(2*g*hp1)*((gamma1-1)/gamma1))+ a2*sqrt(2*g*hp2))*(gamma1/(k2*(gamma1+gamma2-1)));
        v1 = (a1*sqrt(2*g*hp1) + (gamma2-1)*(k2*v2))/(gamma1*k1);
        
        hp3 = (1/(2*g))*((((1-gamma2)*k2*v2)/a3)^2);
        hp4 = (1/(2*g))*((((1-gamma1)*k1*v1)/a4)^2);
        
        T1 = (A1/a1)*sqrt(2*hp1/g);
        T2 = (A2/a2)*sqrt(2*hp2/g);
        T3 = (A3/a3)*sqrt(2*hp3/g);
        T4 = (A4/a4)*sqrt(2*hp4/g);

        A = [-(1/T1) 0 (A3/(A1*T3)) 0;
             0 -(1/T2) 0 (A4/(A2*T4));
             0 0 -(1/T3) 0;
             0 0 0 -(1/T4)];

        B = [gamma1*k1/A1 0;
            0 gamma2*k2/A2;
            0 (1 - gamma2)*k2/A3;
            (1 - gamma1)*k1/A4 0];
        
        Aa = [ A    Z4_2;
              -C    Z2];
        Ba = [B; I2];
        Ca = [C Z2]; %2x6
        
        M = sdpvar(2,6,'full');
        vec_M = [vec_M M];
        T11 = Aa*W + W*Aa' + Ba*M + M'*Ba'; %6x6
        T12 = W*Ca'; %6*2
        T13 = Z6; %6x6
        T22 = -I2;
        T23 = zeros(2,6);
        T33 = -mu*I6;
        LMIs = [LMIs, [T11 T12 T13; T12' T22 T23; T13' T23' T33]<0];
%         M = sdpvar(2,4,'full');
%         vec_M = [vec_M M];
%         T12 = M'*B' + X*A';
%         T21 = A*X + B*M;
%         LMIs = [LMIs, [X T12, T21 X]];
        
    end
end
% Solving
obj = mu;
sol = solvesdp(LMIs,mu,sdpsettings('verbose',1,'solver','sedumi'));
Mi = value(vec_M)
vW = value(W);
invW = inv(vW)

Mn = Mi(:,1:6);
outK(:,:,1,1) = Mn*invW;
% Mn = Mi(:,7:12);
% outK(:,:,1,2) = Mn*invW;
% Mn = Mi(:,13:18);
% outK(:,:,2,1) = Mn*invW;
% Mn = Mi(:,19:24);
% outK(:,:,2,2) = Mn*invW;

% sol = solvesdp(LMIs,0,sdpsettings('verbose',1,'solver','sedumi'));
% Mi = value(vec_M);
% vX = value(X);
% invX = inv(vX);
% 
% Mn = Mi(:,1:4);
% outK(:,:,1,1) = Mn*invX;
% Mn = Mi(:,5:8);
% outK(:,:,1,2) = Mn*invX;
% Mn = Mi(:,9:12);
% outK(:,:,2,1) = Mn*invX;
% Mn = Mi(:,13:16);
% outK(:,:,2,2) = Mn*invX;
% [Kt,S,e] = lqi(sys,Q,R);
% outK(:,:,i1,i2) = -Kt;
% outF(:,:,i1,i2) = -Kt(:,1:4);
% outG(:,:,i1,i2) = -Kt(:,5:6);
% 
% K = outK;
% F = outF;
% G = outG;