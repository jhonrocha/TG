function [As, Bs] = fuzzy_pontos_op(vec_h1, vec_h2, vec_h3, vec_h4)
% Tank Specs
A1 = 28;
A2 = 32;
A3 = 28;
A4 = 32;

a1 = 0.071;
a2 = 0.057;
a3 = 0.071;
a4 = 0.057;

kc = 1;
g = 981;

% Pump Specs
k1 = 3.33;
k2 = 3.35;

% Gamas
y1 = 0.70;
y2 = 0.60;

outA = [];
outB = [];

for i1 = 1:length(vec_h1)
    hp1 = vec_h1(i1);
    
    for i2 = 1:length(vec_h2)
        hp2 = vec_h2(i2);
        
        for i3 = 1:length(vec_h3)
            hp3 = vec_h3(i3);
    
            for i4 = 1:length(vec_h4)
                hp4 = vec_h4(i4);
                
                T1 = (A1/a1)*sqrt(2*hp1/g);
                T2 = (A2/a2)*sqrt(2*hp2/g);
                T3 = (A3/a3)*sqrt(2*hp3/g);
                T4 = (A4/a4)*sqrt(2*hp4/g);

                c1 = T1*k1*kc/A1;
                c2 = T2*k2*kc/A2;

                A = [-(1/T1) 0 (A3/(A1*T3)) 0;
                     0 -(1/T2) 0 (A4/(A2*T4));
                     0 0 -(1/T3) 0;
                     0 0 0 -(1/T4)];

                B = [y1*k1/A1 0;
                    0 y2*k2/A2;
                    0 (1 - y2)*k2/A3;
                    (1 - y1)*k1/A4 0];
                
                outA(:,:,i1,i2,i3,i4) = A;
                outB(:,:,i1,i2,i3,i4) = B;
            end
        end
    end
end

As = outA;
Bs = outB;