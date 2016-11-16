function output = mainIdent()
h1 = 0;
h2 = 0;
h3 = 0;
h4 = 0;

% % h1 = 12.4419;
% % h2 = 13.1668;
% % h3 = 4.7303;
% % h4 = 4.9863;
% 
% Fuzzy Sets
vec_h1 = [10];
vec_h2 = [10];
% 
% % System to Each Point
[Ai, Bi] = fuzzy_pontos_ident()
% 
% Solving
samp_time = 0.2;
final_time = 4000;
tot_samps = final_time/samp_time;
t = 0:samp_time:final_time;

% Getting Reference to Plot
for idx = 1:numel(t)
    i1(idx) = v1(t(idx));
    i2(idx) = v2(t(idx));
end
inputs = [i1' i2'];

% [tv,Hv] = ode15s(@quadtank,t,[h1 h2 h3 h4]);
sys = ss(Ai(:,:,2),Bi(:,:,2),eye(4),0);
[Hv, tv] = lsim(sys,inputs,t,[0 0 0 0]);

% Vizualization
y = Hv;
% y = [ Hv(:,1)-h1 Hv(:,2)-h2 Hv(:,3)-h3 Hv(:,4)-h4];

save auxiliar.mat
figure
plot(tv,y(:,1),'-r',tv,y(:,2),'-b');
title('Modelo Identificado')
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('h1','h2');
grid on

figure
plot(t,inputs(:,1),'-r',t,inputs(:,2),'-b');
title('Inputs')
xlabel('Tempo (s)');
legend('V1','V2');
grid on

% /////////////////////////////////////
% ---- Fuzzy Takagi-Sugeno Model ---- %
% /////////////////////////////////////
function dh = quadtank(t,h)
% % Inference System
% alphas = fuzzy_pertinencia(h(1), h(2), vec_h1, vec_h2)
% 
% A = zeros(4,4);
% B = zeros(4,2);
% % resp = zeros(size(h));
% 
% % Inputs
u = [v1(t); v2(t)];
% 
% for i= 1:size(alphas,1)
%     for j= 1:size(alphas,2)
%         A = A + alphas(i,j) * Ai(:,:,i,j);
%         B = B + alphas(i,j) * Bi(:,:,i,j);
% %         resp = resp + alphas(i,j) * (Ai(:,:,i,j)*[h(1)-vec_h1(i); h(2)-vec_h2(j); h(3)-vec_h3(i,j); h(4)-vec_h4(i,j)] + Bi(:,:,i,j) * [u(1)-vec_v1(i,j); u(2)-vec_v2(i,j)]);
%     end
% end
% % resp = A*h + B*u;
% % Result System
dh = Ai(:,:,2)*h + Bi(:,:,2)*u;
% % dh = resp;
end

% /////////////////////////////////////
% ---- Inputs ---- %
% /////////////////////////////////////
function v11 = v1(t)
    if (t > 1500)
        v11 = 45;
    else
        v11 = 42;
    end
end
   
function v22 = v2(t)
   if (t > 3000)
        v22 = 45;
    else
        v22 = 42;
   end
end

end