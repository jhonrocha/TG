function alo = alocacao(gama,ctes,Ts,PO,saturacao)

order = 6;
sys=ss_linsys(gama,ctes);
s=tf('s');        
A = get(sys,'A');
C_temp= get(sys,'C');
C = [C_temp(1,1)*eye(2),zeros(2)];
D = zeros(2);    

B = get(sys,'B');

A = [A zeros(4,2);-C zeros(2,2)]; %6x6
B = [B;zeros(2)]; %6x2
B2 = [zeros(4,2);eye(2)];%6x2
C = [-C zeros(2,2)];%2x6

% new LMI system
LMIs=set([]);

% generate the variables
W = sdpvar(order,order,'symmetric');
Z = sdpvar(2,6,'full');

%Ts %settle_time(98%)
%PO %Porcentagem de Overshoot
ksi=sqrt(log(PO/100)^2/(pi^2+log(PO/100)^2));
teta=acos(ksi);
%D-Estabilidade
 L = 8/Ts; %Re{A+B*K}=L/2     settle_time(98%)=4/Re{s}   L=2*Re{s}
 M = 1;
   

% LMIs
LMIs = LMIs + set(W > 0);
    %D-Estabilidade
    LMIs = LMIs + set(L*W+M*A*W+M*B*Z+M'*W'*A'+M'*Z'*B' < 0);       
    T311 = (A*W+B*Z)+(A*W+B*Z)';
    T322 = (A*W+B*Z)-(A*W+B*Z)';       
    T4 = [T311*sin(teta) T322*cos(teta); -T322*cos(teta) T311*sin(teta)];    
    LMIs = LMIs + set(T4 < 0);
    
%      %saturacao
%     T311=1;
%     T321=[1;1;1;1;0;0];
%     T312=T321';
%     T322=W;
%     LMIs = LMIs + set([T311 T312 ;T321 T322] > 0);
%     
%     T411=W;
%     T421=Z(1,:);
%     T412=T421';
%     T422=saturacao^2;
%     LMIs = LMIs + set([T411 T412 ;T421 T422] > 0);
%     
%     T511=W;
%     T521=Z(2,:);
%     T512=T521';
%     T522=saturacao^2;
%     LMIs = LMIs + set([T511 T512 ;T521 T522] > 0);

sol = solvesdp(LMIs,[],sdpsettings('verbose',0,'solver','sedumi'));

% checking the lmis
checkset(LMIs);

% retrieving the minimal primal residual
p=min(checkset(LMIs));


if p > 0
    display('feaseble')
    p = double(p);
    
    alo.K = double(Z)/(double(W));    
    alo.feaseble=1;
    eig(A+B*alo.K)
     
else 
    display('root locus statefeedback W (constant) unfeaseble');
    alo.feaseble=0;
end    

end