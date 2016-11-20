% UnB, Brasília: 26 de novembro de 2014
% Aluno: Jhonantans Moraes Rocha
% Matrícula: 11/0014090

clear all; clc;
warning off;

% Modelo de controle inicial:

% x(t)' = A*x(t) + Bu*u(t) + Bw*w(t)
% z(t) = Cz*x(t)

% x = [x1; x2]
% u = [u1; u2]
% w = [w1; w2]
% z = [z1; z2]

% x1(t) e x2(t) são os níveis dos tanques
% z1(t) = x1(t) e z2(t) = x2(t) são as variáveis a serem controladas
% Devem seguir as referências z1ref(t) e z2ref(t), constantes por partes

% u1(t) e u2(t) são entradas de controle proporcionais às vazões de
% entrada nos tanques.

% w1(t) e w2(t) variações nas vazões de entrada ou saída nos tanques.

A = [-3 2; 4 -5];
Bu = [1 0; 0 1];
Bw = [1 0; 0 1];
Cz = [1 0; 0 1];

%------ Estado aumentado:
% xi(t)' = z(t) - zref(t) :: novo vetor de estados
% e = [x; xi] = [x1; x2; xi] :: novo vetor de estados

% e(t)' = Aa*e(t) + Bua*u(t) + Bwa*wa(t)
% z(t) = Cza*e(t)

% wa(t) = [w; zref] = [w1; w2; zref]

% Aa = [A 0; C 0]
% Bua = [Bu; 0]
% Bwa = [Bw 0; 0 -I]
% Cza = [Cz 0]

Aa = [A zeros(2); Cz zeros(2)];
Bua = [Bu; zeros(2)];
Bwa = [Bw zeros(2); zeros(2) -eye(2)];
Cza = [Cz zeros(2)];

% ------ Utilizando o Lema 8 da realimentação de estados:
% Tolerância
tolerance = 1e-7;

%new LMI system
LMIs = set([]);

%create the variables
Z = sdpvar(2,4,'full');

% Lyapunov matrix
W = sdpvar(4,4,'symmetric');
mu = sdpvar(1);

LMIs = LMIs + set(W > 0);

% LMIs:
T11 = Aa*W + W*Aa' + Bua*Z + Z'*Bua';
T12 = W*Cza';
T13 = Bwa;
T22 = -eye(2);
T23 = zeros(2,4);
T33 = -mu*eye(4);
LMIs = LMIs + set([T11 T12 T13; T12' T22 T23; T13' T23' T33] < 0);

% ----- Acrescentando a D-estabilidade
% --- Alocação dos pólos, utilizando a definição 3, temos:
% Para a região R(s) < -1: L1 = -2 e M1 = 1
L1 = 2;
M1 = 1;
% Para a região R(s) > -2.5: L2 = 5 e M2 = -1
L2 = -5;
M2 = -1;

% Utilizando o teorema 3
LMIs = LMIs + set((kron(L1,W) + kron(M1,(Aa*W + Bua*Z)) + kron(M1',(W*Aa' + Z'*Bua'))) < 0);
LMIs = LMIs + set((kron(L2,W) + kron(M2,(Aa*W + Bua*Z)) + kron(M2',(W*Aa' + Z'*Bua'))) < 0);

% ----- Solving
obj = mu;
sol = solvesdp(LMIs,obj,sdpsettings('verbose',1,'solver','sedumi'));

p=min(checkset(LMIs));

%capturing the solutions (if ones exist)
if p > -tolerance;
    output.feas = 1;
    Z = double(Z);
    W = double(W);
    mu = double(mu);
    
    K = Z*inv(W)
    Hinf_cost = sqrt(mu)
    
    display('Done')
else
    display('Error MSG!')
end
