function output = mainNL()
% Minimum Fase
[A1,A2,A3,A4,a1,a2,a3,a4,g,k1,k2,gamma1,gamma2] = planta();
h01 = 5;
h02 = 5;
h03 = 0.0334;
h04 = 2.9076;
v01 = 3.2321;
v02 = 0.5716;

% h03 = 2.0804;
% h04 = 1.7175;
% v01 = 1.8428;
% v02 = 2.0890;

% Solving
samp_time = 0.01;
final_time = 1200;
tot_samps = final_time/samp_time;
t = linspace(0, final_time, tot_samps);

[t,Hv] = ode45(@quadtank,t,[h01 h02 h03 h04]);

% figure
% plot(t,Hv(:,1),'-r','LineWidth',2)
% title('H1 Não Linear');
% ylabel('Altura (cm)');
% xlabel('Tempo (s)');
% legend('h1');
% grid on
% 
% figure
% plot(t,Hv(:,2),'-r','LineWidth',2)
% title('H2 Não Linear');
% ylabel('Altura (cm)');
% xlabel('Tempo (s)');
% legend('h2');
% grid on

mNL_h = Hv;
save('mainNL.mat');
function dh = quadtank(t,h)
dh = zeros(4,1);
dh(1) = -(a1/A1)*sqrt(2*g*h(1)) + (a3/A1)*sqrt(2*g*h(3)) + gamma1*k1*v1(t)/A1;
dh(2) = -(a2/A2)*sqrt(2*g*h(2)) + (a4/A2)*sqrt(2*g*h(4)) + gamma2*k2*v2(t)/A2;
dh(3) = -(a3/A3)*sqrt(2*g*h(3)) + (1-gamma2)*k2*v2(t)/A3;
dh(4) = -(a4/A4)*sqrt(2*g*h(4)) + (1-gamma1)*k1*v1(t)/A4;
end

% /////////////////////////////////////
% ---- Inputs ---- %
% /////////////////////////////////////
function v11 = v1(t)
    if (t < 100)
        v11 = v01;
    else
        v11 = v01+2;
    end
end
   
function v22 = v2(t)
    if (t < 500)
         v22 = v02;
    else
        v22 = v02+2;
    end
end

end