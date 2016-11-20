% UnB, Brasília: 26 de novembro de 2014
% Aluno: Jhonantans Moraes Rocha
% Matrícula: 11/0014090

clear all; clc;
% warning off;

% Fuzzy Sets
vec_h1 = [5 10];
vec_h2 = [5 10];

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
X = sdpvar(4,4,'symmetric');
LMIs = [LMIs, X>0];
% M1 = sdpvar(2,4,'full');
% M2 = sdpvar(2,4,'full');
% M3 = sdpvar(2,4,'full');
% M4 = sdpvar(2,4,'full');
% 
% for m= 1:length(vec_h1)
%     for n= 1:length(vec_h2)
%         A = Ai(:,:,m,n);
%         B = Bi(:,:,m,n);
%         T1 = M1'*B' + X*A';
%         T2 = A*X + B*M1;
%         LMIs = [LMIs, [X T1, T2 X]];
%         
%         T3 = M2'*B' + X*A';
%         T4 = A*X + B*M2;
%         LMIs = [LMIs, [X T3, T4 X]];
%         
%         T5 = M3'*B' + X*A';
%         T6 = A*X + B*M3;
%         LMIs = [LMIs, [X T5, T6 X]];
%         
%         T7 = M4'*B' + X*A';
%         T8 = A*X + B*M4;
%         LMIs = [LMIs, [X T7, T8 X]];
%     end
% end


for m= 1:length(vec_h1)
    for n= 1:length(vec_h2)
        M = sdpvar(2,4,'full');
        vec_M = [vec_M M];

        A = Ai(:,:,m,n);
        B = Bi(:,:,m,n);
        T12 = M'*B' + X*A';
        T21 = A*X + B*M;
        LMIs = [LMIs, [X T12, T21 X]];
    end
end
% Solving
sol = solvesdp(LMIs,0,sdpsettings('verbose',1,'solver','sedumi'));

% p=min(checkset(LMIs));
% 
% %capturing the solutions (if ones exist)
% if p > -tolerance;
%     output.feas = 1;
%     Z = double(Z);
%     W = double(W);
%     K = Z*inv(W)
%     K1 = K(:,1:2)
%     K2 = K(:,3:4)
%     display('Done')
% else
%     display('Error MSG!')
% end
