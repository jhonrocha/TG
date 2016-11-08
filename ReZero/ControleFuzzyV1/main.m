function output = main()
% Minimum Phase
h1 = 13.5199;
h2 = 14.0934;
h3 = 1.8014;
h4 = 1.5535;
hi1 = 0;
hi2 = 0;

% h1 = 12.4419;
% h2 = 13.1668;
% h3 = 4.7303;
% h4 = 4.9863;

% Fuzzy Sets
vec_h1 = [10 15 20];
vec_h2 = [10 15 20];

% System to Each Point
[Ai, Bi, vec_v1, vec_v2, vec_h3, vec_h4] = fuzzy_pontos_control(vec_h1,vec_h2);

% Simulation Time
final = 1200;
t = 0: 0.01: final; 
totalAmostras = (final/0.01)+1;

% [t,Hv] = ode45(@quadtank,t,[h01 h02 h03 h04]);
[t,Hv] = ode45(@quadtank,t,[h1 h2 h3 h4 hi1 hi2]);

% Vizualization
y = [ Hv(:,1) Hv(:,2)];
figure
% save H_FZ
plot(t,y(:,1),'-b',t,y(:,2),'-r')
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

resp = zeros(size(h));

% Inputs
u = [v1(t); v2(t)];

for i= 1:size(alphas,1)
    for j= 1:size(alphas,2)
%         A = A + alphas(i,j) * Ai(:,:,i,j);
%         B = B + alphas(i,j) * Bi(:,:,i,j);
%         resp = resp + alphas(i,j) * (Ai(:,:,i,j)*[h(1)-vec_h1(i); h(2)-vec_h2(j); h(3)-vec_h3(i,j); h(4)-vec_h4(i,j); h(5); h(6)] + Bi(:,:,i,j) * [u(1); u(2)]);
        resp = resp + alphas(i,j) * (Ai(:,:,i,j)*[h(1); h(2); h(3); h(4); h(5); h(6)] + Bi(:,:,i,j) * [u(1); u(2)]);
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
    if (t > 150)&&(t < 750)
        v11 = 15;
    else
        v11 = 18;
    end
end
   
function v22 = v2(t)
   if (t > 150)&&(t < 750)
        v22 = 13;
    else
        v22 = 13;
   end
end

end