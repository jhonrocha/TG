function l5 = lema5_poli(gama,delta,ctes)
order = 6;
sys=ss_linsys(gama,ctes);
s=tf('s');        
A = get(sys,'A');
C_temp= get(sys,'C');
C = [C_temp(1,1)*eye(2),zeros(2)];
D = zeros(2);    

A = [A zeros(4,2);-C zeros(2,2)]; %6x6

deltamax=delta;
deltamin=delta;
if deltamax(1)+gama(1) > 1
    deltamax(1)= 1-gama(1);
end
if deltamax(2)+gama(2) > 1
    deltamax(2)= 1-gama(2);
end
if gama(1)-deltamin(1) < 0
    deltamin(1)= gama(1);
end
if gama(2)-deltamin(2) < 0
    deltamin(2)= gama(2);
end


B=cell(1,4);
sys=ss_linsys([gama(1)-deltamin(1) gama(2)-deltamin(2)],ctes);
B{1} = get(sys,'B');
sys=ss_linsys([gama(1)-deltamin(1) gama(2)+deltamax(2)],ctes);
B{2} = get(sys,'B');
sys=ss_linsys([gama(1)+deltamax(1) gama(2)-deltamin(2)],ctes);
B{3} = get(sys,'B');
sys=ss_linsys([gama(1)+deltamax(1) gama(2)+deltamax(2)],ctes);
B{4} = get(sys,'B');

for idx = 1:1:4
    B{idx} = [B{idx};zeros(2)]; %6x2
end

% new LMI system
LMIs=set([]);

% generate the variables
W = sdpvar(order,order,'symmetric');
X = sdpvar(order,order,'full');
Z = sdpvar(2,6,'full');
eps=1.1;
   

% LMIs
LMIs = LMIs + set(W > 0);

    
for idx = 1:1:4

    T11 = A*X+X'*A'+B{idx}*Z+Z'*B{idx}';
    T21 = W-X+eps*X'*A'+eps*Z'*B{idx}';
    T12 = T21';
    T22 = -eps*X-eps*X';
    LMIs = LMIs + set([T11 T12 ;T21 T22 ] < 0);
    
    
end

sol = solvesdp(LMIs,[],sdpsettings('verbose',0,'solver','sedumi'));

% checking the lmis
checkset(LMIs);

W=double(W);
x0=[1;1;1;1;0;0];
x0Wx0 = x0'*inv(W)*x0

% retrieving the minimal primal residual
p=min(checkset(LMIs));

if p > 0
    display('feaseble')
    p = double(p);    
    K = double(Z)/(double(X));            
    l5.K=K;
    l5.feaseble=1;    
    eig(A+B{1}*K)
    
else 
    display('lema 5 poli unfeaseble');
    l5.feaseble=0;
end    

end