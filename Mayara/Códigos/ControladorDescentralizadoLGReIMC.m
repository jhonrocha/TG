% clear all;
% clc;

% Funçoes de transeferência do sistema:
% G11(s):
K1 = 16.6942;
T1 = 56.0225;

% G22(s):
K2 = 20.6307;
T2 = 55.9087;

%% Projeto de controladores PI Descentralizados por LGR:

% Requisitos de projeto:
% Ultrapassagem Precentual:
Mp = 0.15;     % <= 10%
% Tempo de acomodaçao:
Ts = 0.2;      % <= 20s

Ksi = -((log(Mp)) / (sqrt((pi^2)+(log(Mp))^2)));
Wn = Ts / Ksi;
Wd = Wn*sqrt(1-(Ksi^2));
sigma = Ksi*Wn;
sd1 = -sigma + Wd*i;
sd2 = -sigma - Wd*i;

% teta_1 = 0 - (180 - (180/pi)*(atan((Wd) / (sigma - (1/T1)))));
% teta_2 = teta_1 - (180 - (180/pi)*(atan(Wd/sigma)));
% teta_av = -(teta_2 + 180);
% x = Wd / tan((teta_av)*(pi/180));
% Zc = (x+sigma);

Zc1 = ((Wd / tan((-(((0 - (180 - (180/pi)*(atan((Wd) / (sigma - (1/T1)))))) - (180 - (180/pi)*(atan(Wd/sigma)))) + 180))*(pi/180))) + (Ksi*Wn));
KK1 = abs((sd1) * ((sd1) + (1/(T1))) / ((K1/T1)*((sd1) + (Zc1))));
NumC1_LGR = [KK1 KK1*Zc1];
DenC1_LGR = [1 0];

C1_LGR = (tf(NumC1_LGR,DenC1_LGR))

Zc2 = ((Wd / tan((-(((0 - (180 - (180/pi)*(atan((Wd) / (sigma - (1/T2)))))) - (180 - (180/pi)*(atan(Wd/sigma)))) + 180))*(pi/180))) + (Ksi*Wn));
KK2 = abs((sd1) * ((sd1) + (1/(T2))) / ((K2/T2)*((sd1) + (Zc2))));
NumC2_LGR = [KK2 KK2*Zc2];
DenC2_LGR = [1 0];

C2_LGR = (tf(NumC2_LGR,DenC2_LGR))

%% Projeto de controladores PI Descentralizados por IMC:

% Tempo morto do processo:
%teta = 1;    % 1s

% Parâmetro de desempenho "lambda":
    % Requisito de desempenho:
    % lambda/teta > 1.7
lambda = 2;

% Sintonia do Controlador PI pela tabela 3.11 (e 3.12) do livro "Controles Típicos
% de equipamentos e processos industriais":
% Kp1 = (2*T1 + teta)/(K1 + 2*lambda);
% Ti1 = T1 + teta/2;

Kp1 = T1/(K1*lambda);
Ti1 = T1;

NumC1_IMC = [Kp1 Kp1/Ti1];
DenC1_IMC = [1 0];
C1_IMC = (tf(NumC1_IMC,DenC1_IMC))

% Kp2 = (2*T2 + teta)/(K2 + 2*lambda);
% Ti2 = T2 + teta/2;

Kp2 = T2/(K2*lambda);
Ti2 = T2;

NumC2_IMC = [Kp2 Kp2/Ti2];
DenC2_IMC = [1 0];
C2_IMC = (tf(NumC2_IMC,DenC2_IMC))

