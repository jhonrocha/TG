function [h,v,A1,A2,A3,A4,a1,a2,a3,a4,g,k1,k2,gamma1,gamma2] = planta2()
% Bomba1 = 42, gamma1 = 0.8980, k1 = 7.4044 cm^3/V*s
% Bomba2 = 45, gamma2 = 0.6827, k2 = 7.3339 cm^3/V*s
% Tank Specs
A1 = 47.6;
A2 = 47.6;
A3 = 47.6;
A4 = 47.6;

kc = 1;
g = 981;

% Pump Specs
k1 = 7.4044;
k2 = 7.3339;

% Gamas
gamma1 = 0.8980;
gamma2 = 0.6827;


% % Non Minimum Phase
% k1 = 3.15;
% k2 = 3.29;
% 
% % Gamas
% gamma1 = 0.43;
% gamma2 = 0.34;

h = [16.3767   16.1350   11.4907   20.5671]; 
u = [42    45];
v = 0.05 * u;
a3 = (1-gamma2)*k2*v(2)/(sqrt(2*g*h(3)))
a4 = (1-gamma1)*k1*v(1)/(sqrt(2*g*h(4)))
a1 = ((gamma1*k1*v(1))+(a3*sqrt(2*g*h(3))))/sqrt(2*g*h(1))
a2 = ((gamma2*k2*v(2))+(a4*sqrt(2*g*h(4))))/sqrt(2*g*h(2))

% hp1 = h(1)
% hp2 = h(2)
% v2 = ((a1*sqrt(2*g*hp1)*((gamma1-1)/gamma1))+ a2*sqrt(2*g*hp2))*(gamma1/(k2*(gamma1+gamma2-1)))
% v1 = (a1*sqrt(2*g*hp1) + (gamma2-1)*(k2*v2))/(gamma1*k1)
% 
% hp3 = (1/(2*g))*((((1-gamma2)*k2*v2)/a3)^2)
% hp4 = (1/(2*g))*((((1-gamma1)*k1*v1)/a4)^2)
end