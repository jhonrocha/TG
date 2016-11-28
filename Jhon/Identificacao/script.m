figure
plot(outputs.Time,outputs.Data(:,1),'-b');
hold on
plot(tEst1, yEst1(:,1),'-r');
% title('H1 Ident1');

figure
plot(outputs.Time,outputs.Data(:,2),'-b');
figure
plot(outputs.Time,outputs.Data(:,3),'-b');
figure
plot(outputs.Time,outputs.Data(:,4),'-b');
% hold on
% plot(tEst1, yEst1(:,2),'-r');
% title('H2 Ident1');

% figure
% plot(outputs.Time,outputs.Data(:,1),'-b');
% hold on
% plot(tEst1(inicio:final), yEst1(inicio:final,1),'-r');
% title('H1 Ident1');
% 
% figure
% plot(outputs.Time,outputs.Data(:,2),'-b');
% hold on
% plot(tEst1(inicio:final), yEst1(inicio:final,2),'-r');
% title('H2 Ident2');

% figure
% plot(outputs.Time,outputs.Data(:,1),'-b');
% hold on
% plot(tEst2(inicio:final), yEst2(inicio:final,1),'-r');
% title('H1 Ident1');
% 
% figure
% plot(outputs.Time,outputs.Data(:,2),'-b');
% hold on
% plot(tEst2(inicio:final), yEst2(inicio:final,2),'-r');
% title('H2 Ident2');
% figure
% plot(outputs.Time(inicio:final),outputs.Data(inicio:final,2));
% hold on
% plot(tEst, yEst(:,2));
% title('Tank3');
% 
% figure
% plot(outputs.Time(inicio:final),outputs.Data(inicio:final,3));
% hold on
% plot(tEst, yEst(:,3));
% title('Tank2');
% 
% figure
% plot(outputs.Time(inicio:final),outputs.Data(inicio:final,4));
% hold on
% plot(tEst, yEst(:,4));
% title('Tank1');
