figure

xmax=4000;
LW=2;


subplot(2,1,1)
hold on
title('Desacoplado Simplificado Simulado');
plot(Simulado.time,Simulado.signals.values(:,4),'--r','LineWidth',LW)
plot(Simulado.time,Simulado.signals.values(:,1),'-b','LineWidth',LW)
xlabel('tempo (s)');
ylabel('\Delta h_1(cm)');
legend('Referência','Simulado');
% axis([0 4000 0 0.2]);
grid;

subplot(2,1,2)
hold on
plot(Simulado.time,Simulado.signals.values(:,3),'--r','LineWidth',LW)
plot(Simulado.time,Simulado.signals.values(:,2),'-b','LineWidth',LW)
xlabel('tempo (s)');
ylabel('\Delta h_2(cm)');
legend('Referência','Simulado');
% axis([0 4000 0 0.2]);
grid;



print -dpng fig13c1

