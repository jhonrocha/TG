% Calcula níveis estacionários para dadas tensões
v1 = 2
v2 = 2

h1 = (1/(2*g))*((((1-y2)*k2*v2 + y1*k1*v1)/a1)^2)
h2 = (1/(2*g))*((((1-y1)*k1*v1 + y2*k2*v2)/a2)^2)
h3 = (1/(2*g))*((((1-y2)*k2*v2)/a3)^2)
h4 = (1/(2*g))*((((1-y1)*k1*v1)/a4)^2)

% Calcula tensões estacionárias para dados níveis
h1 = h1;
h2 = h2;
v20 = ((a1*sqrt(2*g*h1)*((y1-1)/y1))+ a2*sqrt(2*g*h2))*(y1/(k2*(y1+y2-1)))
v10 = (a1*sqrt(2*g*h1) + (y2-1)*(k2*v2))/(y1*k1)