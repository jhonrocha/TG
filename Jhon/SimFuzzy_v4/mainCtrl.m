function output = mainCtrl()
% Plant Specs
[A1,A2,A3,A4,a1,a2,a3,a4,g,k1,k2,gamma1,gamma2] = planta();

% Fuzzy Sets
vec_h1 = [5 15];
vec_h2 = [5 15];
% System to Each Point
[K_fuzzy] = fuzzy_ganhos(vec_h1,vec_h2);
K_fuzzy
% Initial Condition
h01 = 0;
h02 = 0;
h03 = 0;
h04 = 0;
hi1 = 0;
hi2 = 0;

% Time
tAmostragem = 0.01;
tFinal = 300;
totAmostras = tFinal/tAmostragem;
t = linspace(0, tFinal, totAmostras);

% Simulating
[t,y] = ode45(@quadtank,t,[h01 h02 h03 h04 hi1 hi2]);

% Getting Reference to Plot
for idx = 1:numel(t)
    v1(idx) = r1(t(idx));
    v2(idx) = r2(t(idx));
end

% figure
% hold on
% % plot(t,v1,'--r',t,y(:,1),'-b')
% plot(t,y(:,2),'-b')
% title('Fase Mínima Não Linear');
% ylabel('Altura (cm)');
% xlabel('Tempo (s)');
% % legend('ref h1', 'h1');
% grid on

figure
plot(t,v1,'--r',t,y(:,1),'-b','LineWidth',2)
title('Nível 1 Controlado - 4 Regras');
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('Referência h1', 'Nível h1','Location','southeast');
grid on

figure
plot(t,v2,'--r',t,y(:,2),'-b','LineWidth',2)
title('Nível 2 Controlador - 4 Regras');
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('Referência h2', 'Nível h2','Location','southeast');
grid on

% /////////////////////////////////////
% System Simulation
% /////////////////////////////////////
function dh = quadtank(t,h)
    alphas = fuzzy_pertinencia(h(1), h(2), vec_h1, vec_h2);

    K = zeros(2,6);
    for i= 1:size(alphas,1)
        for j= 1:size(alphas,2)
            K = K + alphas(i,j) * K_fuzzy(:,:,i,j);
        end
    end
    u = K*h;
    
    erro = [r1(t) - h(1);
            r2(t) - h(2)];
        
    if(u(1) >= 5)
        u(1) = 5.0;
%         erro(1) = 0;
%         erro(2) = 0;
    end
    
    if(u(2)>=5)
        u(2) = 5.0;
%         erro(1) = 0;
%         erro(2) = 0;
    end
    
    dh = zeros(6,1);
    % System Equation
    for index = 1:numel(h)
        if(h(index) <=0)
            h(index)=0;
        end
    end
    dh(1) = -(a1/A1)*sqrt(2*g*h(1)) + (a3/A1)*sqrt(2*g*h(3)) + gamma1*k1*u(1)/A1;
    dh(2) = -(a2/A2)*sqrt(2*g*h(2)) + (a4/A2)*sqrt(2*g*h(4)) + gamma2*k2*u(2)/A2;
    dh(3) = -(a3/A3)*sqrt(2*g*h(3)) + (1-gamma2)*k2*u(2)/A3;
    dh(4) = -(a4/A4)*sqrt(2*g*h(4)) + (1-gamma1)*k1*u(1)/A4;
    dh(5) = erro(1);
    dh(6) = erro(2);
end


% /////////////////////////////////////
% Reference Inputs
% /////////////////////////////////////
function r11 = r1(t)
%     if (t < 150)
%         r11 = 15;
%     elseif (t > 150)&&(t < 300)
%         r11 = 20;
%     elseif (t > 300)&&(t < 450)
%         r11 = 10;
%     else
%         r11 = 20;
%     end
    r11 = 10;
end
   
function r22 = r2(t)
%     if (t < 150)
%         r22 = 10;
%     elseif (t > 150)&&(t < 300)
%         r22 = 15;
%     elseif (t > 300)&&(t < 450)
%         r22 = 5;
%     else
%         r22 = 15;
%     end
    r22 = 15;
end

end