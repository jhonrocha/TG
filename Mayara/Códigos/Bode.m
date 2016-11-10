% FNM
% G11 = tf([0.03139],[1 0.006824])
% GF = tf([1],[1 1])
% bode(G11,'b')
% hold on
% bode(GF,'--r')

% FM
figure
G11 = tf([0.298],[1 0.01784])
GF = tf([1],[1 1])
bode(G11,'b')
hold on
bode(GF,'--r')