x = 00:0.1:40;
y = trimf(x,[0 10 30]);
y(1:100) = 1;
y2 = trimf(x,[10 30 35]);
y2(300:401) = 1;
plot(x,y,x,y2);
legend('fria','quente')
xlabel('Temperatura °C')
ylabel('Pertinência')
title('Função de Pertinência Triângular')
grid on
ylim([-0.05 1.05])