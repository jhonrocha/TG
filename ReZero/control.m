function output = control()
% Initial Conditions
h1 = 13.5199;
h2 = 14.0934;
h3 = 1.8014;
h4 = 1.5535;

% h1 = 12.4419;
% h2 = 13.1668;
% h3 = 4.7303;
% h4 = 4.9863;

% Fuzzy Sets
vec_h1 = [10];
vec_h2 = [10];

% System to Each Point
[Ai, Bi, vec_v1, vec_v2, vec_h3, vec_h4, Ki] = fuzzy_control(vec_h1,vec_h2);

% Solving
samp_time = 0.01;
final_time = 1200;
tot_samps = final_time/samp_time;
t = linspace(0, final_time, tot_samps);

% [t,Hv] = ode45(@quadtank,t,[h01 h02 h03 h04]);
[t,Hv] = ode45(@quadtank,t,[h1 h2 h3 h4]);

% Vizualization
y = [ Hv(:,1) Hv(:,2)];
figure
plot(t,y(:,1),'-r',t,y(:,2),'-b')
title('Linear Fase Minima');
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('H1','H2');
grid on


% /////////////////////////////////////
% ---- Fuzzy Takagi-Sugeno Model ---- %
% /////////////////////////////////////
function dh = quadtank(t,h)
% Inference System
alphas = fuzzy_pertinencia(h(1), h(2), vec_h1, vec_h2);

A = zeros(4,4);
B = zeros(4,2);
resp = zeros(size(h));

% Inputs
u = [v1(t)-10; v2(t)-10];

for i= 1:size(alphas,1)
    for j= 1:size(alphas,2)
%         A = A + alphas(i,j) * Ai(:,:,i,j);
%         B = B + alphas(i,j) * Bi(:,:,i,j);
        resp = resp + alphas(i,j) * (Ai(:,:,i,j)*[h(1)-vec_h1(i); h(2)-vec_h2(j); h(3)-vec_h3(i,j); h(4)-vec_h4(i,j)] + Bi(:,:,i,j) * [u(1)-vec_v1(i,j); u(2)-vec_v2(i,j)]);
    end
end

% Result System
% dh = A*h + B*u;
dh = resp;
end

% /////////////////////////////////////
% ---- Inputs ---- %
% /////////////////////////////////////
function v11 = v1(t)
%     if (t > 150)&&(t < 750)
%         v11 = 3.15+0.5;
%     else
%         v11 =3.15;
%     end
      v11 = 15;
end
   
function v22 = v2(t)
%    if (t > 150)&&(t < 750)
%         v22 = 3.15+0.5;
%     else
%         v22 = 3.15;
%    end
    v22 = 15;
end

end