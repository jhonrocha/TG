 function l6 = lema6(gama,ctes)
saturacao=2;
order = 6;
sys=ss_linsys(gama,ctes);
s=tf('s');        
A = get(sys,'A');
C_temp= get(sys,'C');
C = [C_temp(1,1)*eye(2),zeros(2)];
D = zeros(2);    
B2 = get(sys,'B');

A = [A zeros(4,2);-C zeros(2,2)]; %6x6
B2 = [B2;zeros(2)]; %6x2
C = [-C zeros(2,2)];%2x6
B1 = [B2(1:4,1:2)];%4x2
B1 = [B1 zeros(4,2);zeros(2,2),eye(2)];%6x4
C = [zeros(2,4),eye(2)];% alterado para que y seja a integral do erro. Podemos então minimizar H2/Hinf

% new LMI system
LMIs=set([]);

% generate the variables
W = sdpvar(order,order,'symmetric');

X = sdpvar(4,4,'symmetric');
Z = sdpvar(2,6,'full');
mu = trace(X);

PO=1; %Porcentagem de Overshoot
ksi=sqrt(log(PO/100)^2/(pi^2+log(PO/100)^2));
teta=acos(ksi);


% LMIs
LMIs = LMIs + set(W > 0);

    T11 = A*W+W*A'+B2*Z+Z'*B2';
    T21 = C*W;
    T12 = T21';
    T22 = -eye(2);
    LMIs = LMIs + set([T11 T12 ;T21 T22] < 0);
    
    T211 = X;
    T221 = B1;
    T212 = T221';
    T222 = W;
    LMIs = LMIs + set([T211 T212 ;T221 T222] > 0);
   
   
%     %D-Estabilidade    
    T311 = (A*W+B2*Z)+(A*W+B2*Z)';
    T322 = (A*W+B2*Z)-(A*W+B2*Z)';       
    T4 = [T311*sin(teta) T322*cos(teta); -T322*cos(teta) T311*sin(teta)];    
    LMIs = LMIs + set(T4 < 0);
    
    %saturacao
%     T311=1;
%     T321=[1;1;1;1;0;0];
%     T312=T321';
%     T322=W;
%     LMIs = LMIs + set([T311 T312 ;T321 T322] > 0);
    
    T411=W;
    T421=Z(1,:);
    T412=T421';
    T422=saturacao^2;
    LMIs = LMIs + set([T411 T412 ;T421 T422] > 0);
    
    T511=W;
    T521=Z(2,:);
    T512=T521';
    T522=saturacao^2;
    LMIs = LMIs + set([T511 T512 ;T521 T522] > 0);
    
          
sol = solvesdp(LMIs,mu,sdpsettings('verbose',0,'solver','sedumi'));


% checking the lmis
checkset(LMIs);

% retrieving the minimal primal residual
p=min(checkset(LMIs))
mu=double(mu)
tol = 1e-7;
if p > -tol
    display('feaseble')
    p = double(p)
    mu = sqrt(double(mu))  
    K = double(Z)/(double(W));    
    l6.K=K;
    l6.A=A;
    l6.B=B2;
    l6.C=C;
    l6.feaseble=1;
    sys = ss((l6.A+l6.B*K),B1,l6.C,zeros(2,4));
    norm_h2=norm(sys,2)
    eig(l6.A+l6.B*K)    
else 
    display('lema 6 statefeedback W (constant) unfeaseble')
    l6.feaseble=0;
end    

end