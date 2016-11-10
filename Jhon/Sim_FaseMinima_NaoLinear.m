function output = Sim_FaseMinima_NaoLinear()
%% Minimum Fase
clear all

h01 = 0;
h02 = 0;
h03 = 0;
h04 = 0;

% h01 = 5;
% h02 = 5;
% h03 = 2;
% h04 = 2;

h01 = 13.5199;
h02 = 14.0934;
h03 = 1.8014;
h04 = 1.5535;

%% Solving
samp_time = 0.01;
final_time = 1200;
tot_samps = final_time/samp_time;
t = linspace(0, final_time, tot_samps);

[t,Hv] = ode45(@quadtank,t,[h01 h02 h03 h04]);

% Visualizaï¿½ï¿½o
figure
plot(t,Hv(:,1),'-r',t,Hv(:,2),'-b')
title('Fase Mínima Não Linear');
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('H1','H2');
grid on

function dh = quadtank(t,h)
%Especificaï¿½ï¿½es do tank e do sistema
A1 = 28;
A2 = 32;
A3 = 28;
A4 = 32;

a1 = 0.071;
a2 = 0.057;
a3 = 0.071;
a4 = 0.057;

g = 981;

k1 = 3.33;
k2 = 3.35;
y1 = 0.70;
y2 = 0.60;

% Equaï¿½ï¿½es que descrevem o sistema
dh = zeros(4,1);
dh(1) = -(a1/A1)*sqrt(2*g*h(1)) + (a3/A1)*sqrt(2*g*h(3)) + y1*k1*v1(t)/A1;
dh(2) = -(a2/A2)*sqrt(2*g*h(2)) + (a4/A2)*sqrt(2*g*h(4)) + y2*k2*v2(t)/A2;
dh(3) = -(a3/A3)*sqrt(2*g*h(3)) + (1-y2)*k2*v2(t)/A3;
dh(4) = -(a4/A4)*sqrt(2*g*h(4)) + (1-y1)*k1*v1(t)/A4;

% Entradas do sistema ( Atualmente: degrais)
function v11 = v1(t)
    if (t > 150)&&(t < 750)
        v11 = 3.15+0.5;
    else
        v11 = 3.15;
    end
   
function v22 = v2(t)
   if (t > 150)&&(t < 750)
        v22 = 3.15+0.5;
    else
        v22 = 3.15;
    end