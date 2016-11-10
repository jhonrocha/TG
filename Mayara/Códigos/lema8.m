function l8 = lema8(gama,ctes)
saturacao=3;

order = 6;
sys=ss_linsys(gama,ctes);
s=tf('s');        
A = get(sys,'A');
C_temp= get(sys,'C');
C = [C_temp(1,1)*eye(2),zeros(2)];
B2 = get(sys,'B');

A = [A zeros(4,2);-C zeros(2,2)]; %6x6
B2 = [B2;zeros(2)]; %6x2

B1 = B2(1:4,1:2);%4x2
B1 = [B1 zeros(4,2);zeros(2,2),eye(2)];%6x4
C = [zeros(2,4),eye(2)];% alterado para que y seja a integral do erro. Podemos então minimizar H2/Hinf


% new LMI system
LMIs=set([]);

% generate the variables
W = sdpvar(order,order,'symmetric');
Z = sdpvar(2,6,'full');
mu = sdpvar(1,1,'full');
   

PO=10; %Porcentagem de Overshoot
ksi=sqrt(log(PO/100)^2/(pi^2+log(PO/100)^2));
teta=acos(ksi);


% LMIs
LMIs = LMIs + set(W > 0);
LMIs = LMIs + set(mu > 0);
    
    T11 = A*W+W*A'+B2*Z+Z'*B2';
    T21 = C*W;
    T12 = T21';
    T22 = -eye(2);
    T13 = B1;
    T31= T13';
    T23 = zeros(2,4);
    T32 = T23'; 
    T33 = -mu*eye(4);    
    
    LMIs = LMIs + set([T11 T12 T13;T21 T22 T23; T31 T32 T33] < 0);
    
    
    T311=1;
    T321=[1;1;1;1;0;0];
    T312=T321';
    T322=W;
    LMIs = LMIs + set([T311 T312 ;T321 T322] >= 0);
    
    T411=W;
    T421=Z(1,:);
    T412=T421';
    T422=saturacao^2;
    LMIs = LMIs + set([T411 T412 ;T421 T422] >= 0);
    
    T511=W;
    T521=Z(2,:);
    T512=T521';
    T522=saturacao^2;
    LMIs = LMIs + set([T511 T512 ;T521 T522] >= 0);

sol = solvesdp(LMIs,mu,sdpsettings('verbose',0,'solver','sedumi'));

% checking the lmis
checkset(LMIs);

% retrieving the minimal primal residual
p=min(checkset(LMIs));

tol = 1e-7;

if p > -tol
    display('feaseble')
    p = double(p);
    mu = sqrt(double(mu))
    K = double(Z)/(double(W));    
    l8.K=K;
    l8.A=A;
    l8.B=B2;
    l8.C=C;
    l8.feaseble=1;
    sys = ss((l8.A+l8.B*K),B1,l8.C,zeros(2,4));
    norm_inf=norm(sys,Inf)  
    eig(l8.A+l8.B*l8.K)
else 
    display('lema 8 statefeedback W (constant) unfeaseble');
    l8.feaseble=0;
end    

end