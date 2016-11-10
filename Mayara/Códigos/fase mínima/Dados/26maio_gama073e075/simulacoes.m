ti=0;
tf=900;

% sim('FM_01_Descentralizado_Sintese_Direta',[ti tf]);
% save 26maio_FM_01_Descentralizado_Sintese_Direta.mat

% sim('FM_02_Desacoplado',[ti tf]);
% save 26maio_FM_02_Desacoplado.mat
% 
% sim('FM_03_Desacoplado_antecipatorio',[ti tf]);
% save 26maio_FM_03_Desacoplado_antecipatorio.mat

% sim('FM_04_Desacoplado_Simplificado',[ti tf]);
% save 26maio_FM_04_Desacoplado_Simplificado.mat
% 
% sim('FM_05_Descentralizado_IMC',[ti tf]);
% save 26maio_FM_05_Descentralizado_IMC.mat
% 
% sim('FM_06_Descentralizado_LGR',[ti tf]);
% save 26maio_FM_06_Descentralizado_LGR.mat
% 
% sim('FM_07_Finsler',[ti tf]);
% save 26maio_FM_07_Finsler.mat
% 
% sim('FM_08_H2',[ti tf]);
% save 26maio_FM_08_H2.mat
% 
% sim('FM_09_Hinf',[ti tf]);
% save 26maio_FM_09_Hinf.mat
% 
% sim('FM_10_Controle_LQR',[ti tf]);
% save 26maio_FM_10_Controle_LQR.mat

sim('FM_11_Robusto_Finsler',[ti tf]);
save 26maio_FM_11_Robusto_Finsler.mat
% 
% sim('FM_12_PI_Descentralizado',[ti tf]);
% save 26maio_FM_12_PI_Descentralizado.mat

