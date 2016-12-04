% Run Scripts
mainTS2;
mainNL;
mainLinear;
mainTS5;
mainTS15;

load('mainLinear.mat');
load('mainNL.mat');
load('mainTS2.mat');
load('mainTS5.mat');
load('mainTS15.mat');

figure
plot(t,mNL_h(:,1),t,mTS2_h(:,1),t,mML_h(:,1),'LineWidth',2);
title('Nível H1 - 4 Regras')
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('Não Linear', 'TS [5 15]', 'Linearizado','Location','southeast');
grid on

figure
plot(t,mNL_h(:,2),t,mTS2_h(:,2),t,mML_h(:,2),'LineWidth',2);
title('Nível H2 - 4 Regras')
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('Não Linear', 'TS [5 15]', 'Linearizado','Location','southeast');
grid on

figure
plot(t,mNL_h(:,1),t,mTS5_h(:,1),t,mML_h(:,1),'LineWidth',2);
title('Nível H1 - 25 Regras')
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('Não Linear', 'Fuzzy TS', 'Linearizado','Location','southeast');
grid on

figure
plot(t,mNL_h(:,2),t,mTS5_h(:,2),t,mML_h(:,2),'LineWidth',2);
title('Nível H2 - 25 Regras')
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('Não Linear', 'Fuzzy TS', 'Linearizado','Location','southeast');
grid on

figure
plot(t,mNL_h(:,1),t,mTS15_h(:,1),t,mML_h(:,1),'LineWidth',2);
title('Nível H1 - 225 Regras')
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('Não Linear', 'Fuzzy TS', 'Linearizado','Location','southeast');
grid on

figure
plot(t,mNL_h(:,2),t,mTS15_h(:,2),t,mML_h(:,2),'LineWidth',2);
title('Nível H2 - 225 Regras')
ylabel('Altura (cm)');
xlabel('Tempo (s)');
legend('Não Linear', 'Fuzzy TS', 'Linearizado','Location','southeast');
grid on
