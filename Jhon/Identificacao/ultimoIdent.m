gamma1 = 0.62;
gamma2 = 0.7;
k1 = 8;
k2 = 12;
h = [11.8522   12.2311   14.0215    8.5018]; 
u = [45    42];
v = 0.05 * u;

a3 = (1-gamma2)*k2*v(2)/(sqrt(2*g*h(3)))
a4 = (1-gamma1)*k2*v(1)/(sqrt(2*g*h(4)))
a1 = ((gamma1*k1*v(1))+(a3*sqrt(2*g*h(3))))/sqrt(2*g*h(1))
a2 = ((gamma2*k2*v(2))+(a4*sqrt(2*g*h(4))))/sqrt(2*g*h(2))