close all

% t = [0,1,2];
% y = [0,1,0];
% plot(t,y,'LineWidth',2);
% grid on
% title('Pertiência Triangular')
% 
% figure
% x = [0:1:9];
% y = [0,0,0,1,1,1,1,0,0,0];
% plot(x,y,'LineWidth',2)
% ylim([-0.1 1.1])
% grid on 
% title('Pertiência Trapezoidal')
% 
% figure
% x = 0:0.1:10;
% y = gaussmf(x,[2 5]);
% plot(x,y,'LineWidth',2)
% grid on 
% title('Pertiência Gaussiana')
% 
% figure
% x = 0:0.1:10;
% y = sigmf(x,[2 4]);
% plot(x,y,'LineWidth',2)
% ylim([-0.05 1.05])
% grid on 
% title('Pertiência Sigmoide')
% 
% figure
% x = [0,1,2,2,3,4,5,6,7,8,8,9,10];
% y = [0,0,0,1,1,1,1,1,1,1,0,0,0];
% plot(x,y,'LineWidth',2)
% ylim([-0.05 1.05])
% title('Pertinencia Quadrada')
% grid on

% t1 = [-5,5,15,20];
% y1 = [1,1,0,0];
% plot(t1,y1,'LineWidth',2);
% ylim([-0.05 1.05])
% grid on
% title('Muito Frio')
% 
% figure
% t2 = [0,5,15,25,30];
% y2 = [0,0,1,0,0];
% plot(t2,y2,'LineWidth',2);
% ylim([-0.05 1.05])
% grid on
% title('Frio')
% 
% figure
% t3 = [10,15,25,35,40];
% y3 = [0,0,1,0,0];
% plot(t3,y3,'LineWidth',2);
% ylim([-0.05 1.05])
% grid on
% title('Quente')
% 
% figure
% t4 = [20,25,35,40];
% y4 = [0,0,1,1];
% plot(t4,y4,'LineWidth',2);
% ylim([-0.05 1.05])
% grid on
% title('Muito Quente')

figure
t1 = [0,5,25,30];
y1 = [1,1,0,0];
y2 = [0,0,1,1];
plot(t1,y1,'-b',t1,y2,'-r','LineWidth',2);
ylim([-0.05 1.05])
legend('Nível Baixo','Nível Alto')
grid on
title('Pertinências dos Níveis')
