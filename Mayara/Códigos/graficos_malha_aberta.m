figure

xmax=4000;
LW=2;

subplot(3,2,1)
hold on
plot(SimuladoNM.time,SimuladoNM.signals.values(:,5),'--r','LineWidth',LW)
plot(SimuladoM.time,SimuladoM.signals.values(:,5),'-b','LineWidth',LW)
xlabel('tempo (s)');
ylabel('\Delta v_1(V)');
axis([0 4000 0 0.2]);grid;

subplot(3,2,2)
hold on
plot(SimuladoNM.time,SimuladoNM.signals.values(:,6),'--r','LineWidth',LW)
plot(SimuladoM.time,SimuladoM.signals.values(:,6),'-b','LineWidth',LW)
xlabel('tempo (s)');
ylabel('\Delta v_2(V)');
axis([0 4000 0 0.2]);grid;

subplot(3,2,5)
hold on
plot(SimuladoNM.time,SimuladoNM.signals.values(:,1),'--r','LineWidth',LW)
plot(SimuladoM.time,SimuladoM.signals.values(:,1),'-b','LineWidth',LW)
xlabel('tempo (s)');
ylabel('\Delta h_1(cm)');
axis([0 xmax 0 10]);grid;

subplot(3,2,6)
hold on
plot(SimuladoNM.time,SimuladoNM.signals.values(:,2),'--r','LineWidth',LW)
plot(SimuladoM.time,SimuladoM.signals.values(:,2),'-b','LineWidth',LW)
xlabel('tempo (s)');
ylabel('\Delta h_2(cm)');
axis([0 xmax 0 6]);grid;

subplot(3,2,3)
hold on
plot(SimuladoNM.time,SimuladoNM.signals.values(:,3),'--r','LineWidth',LW)
plot(SimuladoM.time,SimuladoM.signals.values(:,3),'-b','LineWidth',LW)
xlabel('tempo (s)');
ylabel('\Delta h_3(cm)');
axis([0 xmax 0 8]);grid;

subplot(3,2,4)
hold on
plot(SimuladoNM.time,SimuladoNM.signals.values(:,4),'--r','LineWidth',LW)
plot(SimuladoM.time,SimuladoM.signals.values(:,4),'-b','LineWidth',LW)
xlabel('tempo (s)');
ylabel('\Delta h_4(cm)');
axis([0 xmax 0 6]);grid;

legend('Fase Não Mínima','Fase Mínima');
print -dpng fig13c1

return
print -depsc -tiff -r300 fig13a1
print -dtiff fig13b1
print -dpng fig13c1
