function output = controller()
% Minimum Fase
hp1 = 13.5199;
hp2 = 14.0934;
hp3 = 1.8014;
hp4 = 1.5535;

h1 = 13.5199;
h2 = 14.0934;
h3 = 1.8014;
h4 = 1.5535;

h01 = hp1 + h1;
h02 = hp2 + h2;
h03 = hp3 + h3;
h04 = hp4 + h4;

% Solving
samp_time = 0.01;
final_time = 1200;
tot_samps = final_time/samp_time;
t = linspace(0, final_time, tot_samps);

[t,Hv] = ode45(@quadtank,t,[h01 h02 h03 h04]);

% Vizualization
y = [ Hv(:,1)-hp1 Hv(:,2)-hp2 ];
figure
plot(t,y(:,1),'-r',t,y(:,2),'-b')
title('Linear Fase Minima');
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('H1','H2');
grid on
end

% /////////////////////////////////////
% ---- Fuzzy Takagi-Sugeno Model ---- %
% /////////////////////////////////////
function dh = quadtank(t,h)
% Fuzzy Sets
% vec_h1 = [5 15];
% vec_h2 = [5 15];
% vec_h3 = [5];
% vec_h4 = [5];

hp1 = 13.5199;
hp2 = 14.0934;
hp3 = 1.8014;
hp4 = 1.5535;
vec_h1 = [5 hp1];
vec_h2 = [5 hp2];
vec_h3 = [5];
vec_h4 = [5];

% System to Each Point
[Ai, Bi] = fuzzy_pontos_op(vec_h1,vec_h2,vec_h3,vec_h4)

% Inference System
alphas = fuzzy_pertinencia(h(1), h(2), vec_h1, vec_h2)

A = zeros(4,4);
B = zeros(4,2);
for i= 1:size(alphas,1)
    for j= 1:size(alphas,2)
        A = A + alphas(i,j) * Ai(:,:,i,j);
        B = B + alphas(i,j) * Bi(:,:,i,j);
    end
end

% Inputs
u = [v1(t); v2(t)];

% Result System
dh = A*h + B*u;
end

% /////////////////////////////////////
% ---- Inputs ---- %
% /////////////////////////////////////
function v11 = v1(t)
    if (t > 150)&&(t < 750)
        v11 = 3.15+0.5;
    else
        v11 = 3.15;
    end
end
   
function v22 = v2(t)
   if (t > 150)&&(t < 750)
        v22 = 3.15+0.5;
    else
        v22 = 3.15;
   end
end