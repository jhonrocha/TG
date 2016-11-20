% UnB, Brasília: 26 de novembro de 2014
% Aluno: Jhonantans Moraes Rocha
% Matrícula: 11/0014090

% clear all; clc;
% warning off;

% Fuzzy Sets
vec_h1 = [10];
vec_h2 = [10];

% System to Each Point
[Ai, Bi, vec_v1, vec_v2, vec_h3, vec_h4] = fuzzy_pontos_v2(vec_h1,vec_h2);

% ------ Utilizando o Lema 8 da realimentação de estados:
% Tolerância
tolerance = 1e-7;

%new LMI system
LMIs = [];

%create the variables
vec_M = [];

% Lyapunov matrix
W = sdpvar(4,4,'symmetric');
LMIs = [LMIs, W>0];

Q = eye(2);
R = eye(2);
C = [1 0 0 0; 0 1 0 0];
D = zeros(2);

Z = sdpvar(2,4,'full');
A = Ai(:,:,1,1);
B = Bi(:,:,1,1);
T11 = A*W - B*Z + W*A' - Z'*B';
T21 = R*Z;
T22 = -R;
T31 = Q*C*W;
T32 = zeros(2);
T33 = -Q;
LMIs = [LMIs, [T11 T21' T31'; T21 T22 T32'; T31 T32 T33]<0];
obj = trace(W);
sol = optimize(LMIs,obj,sdpsettings('verbose',1,'solver','sedumi'));
K1 = value(Z)*inv((value(W)))
K2 = value(Z)
sys = ss(A,B,C,D);

% for m= 1:length(vec_h1)
%     for n= 1:length(vec_h2)
%         M = sdpvar(2,4,'full');
%         vec_M = [vec_M M];
% 
%         A = Ai(:,:,m,n);
%         B = Bi(:,:,m,n);
%         T12 = M'*B' + W*A';
%         T21 = A*W + B*M;
%         LMIs = [LMIs, [W T12, T21 W]];
%     end
% end
