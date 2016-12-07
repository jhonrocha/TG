function [A1,A2,A3,A4,a1,a2,a3,a4,g,k1,k2,gamma1,gamma2] = planta()
% Tank Specs
A1 = 47.6;
A2 = 47.6;
A3 = 47.6;
A4 = 47.6;

kc = 1;
g = 981;

% Pump Specs
k1 = 8;
k2 = 12;

% Gamas
gamma1 = 0.62;
gamma2 = 0.7;


% % Non Minimum Phase
% k1 = 3.15;
% k2 = 3.29;
% 
% % Gamas
% gamma1 = 0.43;
% gamma2 = 0.34;

h = [11.8522   12.2311   14.0215    8.5018]; 
u = [45    42];
v = 0.05 * u;
a3 = (1-gamma2)*k2*v(2)/(sqrt(2*g*h(3)))
a4 = (1-gamma1)*k1*v(1)/(sqrt(2*g*h(4)))
a1 = ((gamma1*k1*v(1))+(a3*sqrt(2*g*h(3))))/sqrt(2*g*h(1))
a2 = ((gamma2*k2*v(2))+(a4*sqrt(2*g*h(4))))/sqrt(2*g*h(2))
end