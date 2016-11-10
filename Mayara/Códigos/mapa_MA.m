figure(1);
num1 = [0 0.298];
den1 = [1 0.01784];
G = tf(num1,den1)
num2 = [1.282 0.5023];
den2 = [1 0];
C = tf(num2,den2)
MA = G*C
rlocus([0.382 0.1497],[1 0.01784 0]);
grid;
% subplot(1,2,2);
% num2 = [0 0.369];
% den2 = [1 0.0179];
% rlocus(num2,den2);
% grid;