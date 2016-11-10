clear all;
clc;

% Funçoes de transeferência do sistema:
% G12(s):
K12 = 34.2310;
T1 = 146.1827;
T3 = 86.5907;

% G21(s):
K21 = 20.0771;
T2 = 47.4660;
T4 = 98.2159;

%% Projeto de controladores PI Descentralizados por LGR:

% Requisitos de projeto:
% Ultrapassagem Precentual:
Mp = 0.15;     % <= 10%
% Tempo de acomodaçao:
Ts = 30;      % <= 10s

Ksi = -((log(Mp)) / (sqrt((pi^2)+(log(Mp))^2)));
Wn = Ts / Ksi;
Wd = Wn*sqrt(1-(Ksi^2));
sigma = Ksi*Wn;
sd1 = -sigma + Wd*i;
sd2 = -sigma - Wd*i;


teta_1 = 0 - (180 - (180/pi)*(atan((Wd) / (sigma - (1/T1))))) - (180 - (180/pi)*(atan((Wd) / (sigma - (1/T3)))));
teta_2 = teta_1 - 3*(180 - (180/pi)*(atan(Wd/sigma)));
teta_av = -(teta_2 + 3*180);
x = Wd / tan((teta_av)*(pi/180));
Zc = (x + sigma);

Zc1 = ((Wd / tan((-(((0 - (180 - (180/pi)*(atan((Wd) / (sigma - (1/T1))))) - (180 - (180/pi)*(atan((Wd) / (sigma - (1/T3)))))) - 3*(180 - (180/pi)*(atan(Wd/sigma)))) + 3*180))*(pi/180))) + sigma);
KK1 = abs(((sd1^3)*(1+sd1*T1)*(1+sd1*T3)) / ((K12)*((sd1) + (Zc1))));
NumC1_LGR = [KK1 KK1*Zc1];
DenC1_LGR = [1 0 0 0];

C1_LGR = (tf(NumC1_LGR,DenC1_LGR))


Zc2 = ((Wd / tan((-(((0 - (180 - (180/pi)*(atan((Wd) / (sigma - (1/T2))))) - (180 - (180/pi)*(atan((Wd) / (sigma - (1/T4)))))) - 3*(180 - (180/pi)*(atan(Wd/sigma)))) + 3*180))*(pi/180))) + sigma);
KK2 = abs(((sd1^3)*(1+sd1*T2)*(1+sd1*T4)) / ((K21)*((sd1) + (Zc2))));
NumC2_LGR = [KK2 KK2*Zc2];
DenC2_LGR = [1 0 0 0];

C2_LGR = (tf(NumC2_LGR,DenC2_LGR))

%% Projeto de controladores PI Descentralizados por IMC:

% Tempo morto do processo:
%teta = 10;    % 1s

% Parâmetro de desempenho "lambda":
    % Requisito de desempenho:
    % lambda/teta > 1.7
lambda1 = 40;
lambda2 = 300;

% Sintonia do Controlador PI pela tabela 3.11 (e 3.12) do livro "Controles Típicos
% de equipamentos e processos industriais":
Kp1 = (T1 + T3)/(K12*lambda1);
Ti1 = T1 + T3;
Td1 = (T1*T3)/(T1 + T3);

NumC1_IMC = [Kp1 Kp1/Ti1];
DenC1_IMC = [1 0];
C1_IMC = (tf(NumC1_IMC,DenC1_IMC))

Kp2 = (T2 + T4)/(K21*lambda2);
Ti2 = T2 + T4;
Td2 = (T2*T4)/(T2 + T4);

NumC2_IMC = [Kp2 Kp2/Ti2];
DenC2_IMC = [1 0];
C2_IMC = (tf(NumC2_IMC,DenC2_IMC))
