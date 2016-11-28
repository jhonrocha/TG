function [As, Bs, V1s, V2s, H3s, H4s] = fuzzy_pontos_v2(vec_h1, vec_h2)
% Plant Specs
[A1,A2,A3,A4,a1,a2,a3,a4,g,k1,k2,gamma1,gamma2] = planta();

outA = zeros(4,4,length(vec_h1),length(vec_h2));
outB = zeros(4,2,length(vec_h1),length(vec_h2));
outV1 = zeros(length(vec_h1),length(vec_h2));
outV2 = zeros(length(vec_h1),length(vec_h2));
outH3 = zeros(length(vec_h1),length(vec_h2));
outH4 = zeros(length(vec_h1),length(vec_h2));

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
        
        outA(:,:,i1,i2) = A;
        outB(:,:,i1,i2) = B;
        outV1(i1,i2) = v1;
        outV2(i1,i2) = v2;
        outH3(i1,i2) = hp3;
        outH4(i1,i2) = hp4;
    end
end

As = outA;
Bs = outB;
V1s = outV1;
V2s = outV2;
H3s = outH3;
H4s = outH4;