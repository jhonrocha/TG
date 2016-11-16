function output = teste()
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
vec_h1 = [13.5199];
vec_h2 = [14.0934];

% System to Each Point
[Ai, Bi, vec_v1, vec_v2, vec_h3, vec_h4] = fuzzy_pontos_v2(vec_h1,vec_h2);

% Solving
samp_time = 0.01;
final_time = 1200;
tot_samps = final_time/samp_time;
t = linspace(0, final_time, tot_samps);

% Getting Reference to Plot
for idx = 1:numel(t)
    i1(idx) = v1(t(idx));
    i2(idx) = v2(t(idx));
end
inputs = [i1' i2'];

% [t,Hv] = ode45(@quadtank,t,[h01 h02 h03 h04]);
[t,Hv] = ode45(@quadtank,t,[h1 h2 h3 h4]);
sys = ss(Ai(:,:,1),Bi(:,:,1),eye(4),0);
% [Hv, t] = lsim(sys,inputs,t,[0 0 0 0]);

% Vizualization
y = [ Hv(:,1) Hv(:,2)];
hold on;
% plot(t,y(:,1),'--r',t,y(:,2),'--b');
plot(t,y(:,1),'--r', 'LineWidth',2);

% title('Linear Fase Minima');
 title('Linearização Convencional em h1 = 13.5')
ylabel('Altura (cm)');
xlabel('Tempo (s)');

h = figure(1);
a = get(h, 'CurrentAxes');
c = get(a, 'Children');
% legend(c([1 3 2 4]), 'h1 Não Linear','h1 Linearizado', 'h2 Não Linear', 'h2 Linearizado');
legend('h1 Não Linear','h1 Linearizado');
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
u = [v1(t); v2(t)];

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
    if (t > 150)&&(t < 850)
        v11 = 3.15+1;
    else
        v11 = 3.15;
    end
end
   
function v22 = v2(t)
   if (t > 150)&&(t < 850)
        v22 = 3.15+1;
    else
        v22 = 3.15;
   end
end

end