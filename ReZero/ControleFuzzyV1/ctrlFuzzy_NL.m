function output = ctrlFuzzy_NL()
% Minimum Fase
clear all; clc;

% Tanks Specs
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

% Initial Condition
h01 = 13.5199;
h02 = 14.0934;
h03 = 1.8014;
h04 = 1.5535;
hi1 = 0;
hi2 = 0;

K =[-4.8384    0.0849   -0.4874    0.0004;
    -0.0413   -5.6072   -0.0125   -0.4663];

Ki = [0.9999   -0.0118;
      0.0118    0.9999];


% Time
samp_time = 0.01;
final_time = 600;
tot_samps = final_time/samp_time;
t = linspace(0, final_time, tot_samps);

[t,y] = ode45(@quadtank,t,[h01 h02 h03 h04 hi1 hi2]);
for idx = 1:numel(t)
    v1(idx) = r1(t(idx));
    v2(idx) = r2(t(idx));
end

% pt = 1000;
% plot(t(1:pt),y(1:pt,6),t(1:pt),y(1:pt,2),t(1:pt),v1(1:pt));

figure
subplot(2,1,1)
plot(t,v1,'--b',t,y(:,1),'-b')
title('Fase Mínima Não Linear');
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('h1');
grid on

subplot(2,1,2)
plot(t,v2,'--r',t,y(:,2),'-r')
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('h2');
grid on


function dh = quadtank(t,h)
    dh = zeros(6,1);
    u = (K*[h(1); h(2); h(3); h(4)]) + (Ki*[h(5); h(6)]);
   
    % System Equation
    for index = 1:numel(h)
        if(h(index) <=0)
            h(index)=0;
        end
    end
    dh(1) = -(a1/A1)*sqrt(2*g*h(1)) + (a3/A1)*sqrt(2*g*h(3)) + y1*k1*u(1)/A1;
    dh(2) = -(a2/A2)*sqrt(2*g*h(2)) + (a4/A2)*sqrt(2*g*h(4)) + y2*k2*u(2)/A2;
    dh(3) = -(a3/A3)*sqrt(2*g*h(3)) + (1-y2)*k2*u(2)/A3;
    dh(4) = -(a4/A4)*sqrt(2*g*h(4)) + (1-y1)*k1*u(1)/A4;
    dh(5) = (r1(t) - h(1));
    dh(6) = (r2(t) - h(2));
end

% Entradas do sistema ( Atualmente: degrais)
% /////////////////////////////////////
% ---- Inputs ---- %
% /////////////////////////////////////
function r11 = r1(t)
    if (t < 150)
        r11 = 15;
    elseif (t > 150)&&(t < 300)
        r11 = 20;
    elseif (t > 300)&&(t < 450)
        r11 = 10;
    else
        r11 = 20;
    end
end
   
function r22 = r2(t)
    if (t < 150)
        r22 = 10;
    elseif (t > 150)&&(t < 300)
        r22 = 15;
    elseif (t > 300)&&(t < 450)
        r22 = 5;
    else
        r22 = 15;
    end
end

end