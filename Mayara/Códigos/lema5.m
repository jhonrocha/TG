function l5 = lema5(gama,ctes)

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
X = sdpvar(order,order,'full');
Z = sdpvar(2,6,'full');
eps=10;


% LMIs
LMIs = LMIs + set(W > 0);


    T11 = A*X+X'*A'+B*Z+Z'*B';
    T21 = W-X+eps*X'*A'+eps*Z'*B';
    T12 = T21';
    T22 = -eps*X-eps*X';
    
    LMIs = LMIs + set([T11 T12 ;T21 T22 ] < 0);

sol = solvesdp(LMIs,[],sdpsettings('verbose',0,'solver','sedumi'));

% checking the lmis
checkset(LMIs);

% retrieving the minimal primal residual
p=min(checkset(LMIs));


if p > 0
    display('feaseble')
    p = double(p);
    
    l5.K = double(Z)/(double(X));    
    l5.feaseble=1;
     
else 
    display('lema 5 statefeedback W (constant) unfeaseble');
    l5.feaseble=0;
end    

end