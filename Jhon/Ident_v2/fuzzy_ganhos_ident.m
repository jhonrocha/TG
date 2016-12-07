function [outK] = fuzzy_ganhos_ident()
outA = zeros(4,4,2,2);
outB = zeros(4,2,2,2);
outV1 = zeros(2,2);
outV2 = zeros(2,2);
outH3 = zeros(2,2);
outH4 = zeros(2,2);

% C
C = [1 0 0 0;
     0 1 0 0];

% Returns
outK = zeros(2,6,2,2);
size(outK)

%new LMI system
LMIs = [];

%create the variables
vec_M = [];

% Lyapunov matrix
W = sdpvar(6,6,'symmetric');
LMIs = [LMIs, W>0];

% Sistema 1
i1 = 1;
i2 = 1;

[h,v,A1,A2,A3,A4,a1,a2,a3,a4,g,k1,k2,gamma1,gamma2] = planta1();

hp1 = h(1);
hp2 = h(2);
hp3 = h(3)
hp4 = h(4)
v1 = v(1);
v2 = v(2);

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

outA(:,:,i1,i2) = A;
outB(:,:,i1,i2) = B;
outV1(i1,i2) = v1;
outV2(i1,i2) = v2;
outH3(i1,i2) = hp3;
outH4(i1,i2) = hp4;

Aa = [A zeros(4,2); -C zeros(2)];
Ba = [B; zeros(2)];

M = sdpvar(2,6,'full');
vec_M = [vec_M M];
LMIs = [LMIs, Aa*W + W*Aa' + Ba*M + M'*Ba' <0];

% Sistema 2
i1 = 1;
i2 = 2;

[h,v,A1,A2,A3,A4,a1,a2,a3,a4,g,k1,k2,gamma1,gamma2] = planta2();

hp1 = h(1);
hp2 = h(2);
hp3 = h(3)
hp4 = h(4)
v1 = v(1);
v2 = v(2);

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

outA(:,:,i1,i2) = A;
outB(:,:,i1,i2) = B;
outV1(i1,i2) = v1;
outV2(i1,i2) = v2;
outH3(i1,i2) = hp3;
outH4(i1,i2) = hp4;

Aa = [A zeros(4,2); -C zeros(2)];
Ba = [B; zeros(2)];

M = sdpvar(2,6,'full');
vec_M = [vec_M M];
LMIs = [LMIs, Aa*W + W*Aa' + Ba*M + M'*Ba' <0];

% Sistema 3
i1 = 2;
i2 = 1;

[h,v,A1,A2,A3,A4,a1,a2,a3,a4,g,k1,k2,gamma1,gamma2] = planta3();

hp1 = h(1);
hp2 = h(2);
hp3 = h(3)
hp4 = h(4)
v1 = v(1);
v2 = v(2);

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

outA(:,:,i1,i2) = A;
outB(:,:,i1,i2) = B;
outV1(i1,i2) = v1;
outV2(i1,i2) = v2;
outH3(i1,i2) = hp3;
outH4(i1,i2) = hp4;

Aa = [A zeros(4,2); -C zeros(2)];
Ba = [B; zeros(2)];

M = sdpvar(2,6,'full');
vec_M = [vec_M M];
LMIs = [LMIs, Aa*W + W*Aa' + Ba*M + M'*Ba' <0];

% Sistema 4
i1 = 2;
i2 = 2;

[h,v,A1,A2,A3,A4,a1,a2,a3,a4,g,k1,k2,gamma1,gamma2] = planta4();

hp1 = h(1);
hp2 = h(2);
hp3 = h(3)
hp4 = h(4)
v1 = v(1);
v2 = v(2);

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

outA(:,:,i1,i2) = A;
outB(:,:,i1,i2) = B;
outV1(i1,i2) = v1;
outV2(i1,i2) = v2;
outH3(i1,i2) = hp3;
outH4(i1,i2) = hp4;

Aa = [A zeros(4,2); -C zeros(2)];
Ba = [B; zeros(2)];

M = sdpvar(2,6,'full');
vec_M = [vec_M M];
LMIs = [LMIs, Aa*W + W*Aa' + Ba*M + M'*Ba' <0];

obj = 0;
sol = optimize(LMIs,obj,sdpsettings('verbose',0,'solver','sedumi'));
Mi = value(vec_M);
vW = value(W);
invW = inv(vW);
Mn = Mi(:,1:6);
outK(:,:,1,1) = Mn*invW;
Mn = Mi(:,7:12);
outK(:,:,1,2) = Mn*invW;
Mn = Mi(:,13:18);
outK(:,:,2,1) = Mn*invW;
Mn = Mi(:,19:24);
outK(:,:,2,2) = Mn*invW;

As = outA;
Bs = outB;
V1s = outV1;
V2s = outV2;
H3s = outH3;
H4s = outH4;