function [K,F,G] = fuzzy_ganhos(vec_h1, vec_h2)
% Plant Specs
[A1,A2,A3,A4,a1,a2,a3,a4,g,k1,k2,gamma1,gamma2] = planta();

% C and D
C = [1 0 0 0;
     0 1 0 0];

D = [0 0;
     0 0];
 
% Q and R to LQI Tunning
Q = eye(6);
R = eye(2);

% Returns
outK = zeros(2,6,length(vec_h1),length(vec_h2));
outF = zeros(2,4,length(vec_h1),length(vec_h2));
outG = zeros(2,2,length(vec_h1),length(vec_h2));

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
        
        sys = ss(A,B,C,D);
        [Kt,S,e] = lqi(sys,Q,R);

        outK(:,:,i1,i2) = -Kt;
        outF(:,:,i1,i2) = -Kt(:,1:4);
        outG(:,:,i1,i2) = -Kt(:,5:6);
    end
end

K = outK;
F = outF;
G = outG;