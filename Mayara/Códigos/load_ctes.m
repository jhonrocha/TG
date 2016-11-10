function out = load_ctes() 
% % Settup Constants
% % Fase Mínima
% out.A1=44.6023;
% out.A2=19.5142;
% out.A3=17.4287;
% out.A4=32.4925;
% out.k1=18.0507;
% out.k2=9.5035;
% out.g=981;
% out.a1=0.1072;
% out.a2=0.0498;
% out.a3=0.0067;
% out.a4=0.0275;
% out.hlin=[8.9,9.97,8.65,9.67];
% out.vlin=[2.3,1.8];
% out.gama=[0.7363,0.7577];


% Settup Constants
% Fase Não Mínima
out.A1=7.8681;
out.A2=9.2779;
out.A3=7.1895;
out.A4=4.8286;
out.k1=1.7079;
out.k2=3.123;
out.g=981;
out.a1=0.0071;
out.a2=0.0265;
out.a3=0.0107;
out.a4=0.0066;
out.hlin=[8.5761,9.0253,8.107,8.8679];
out.vlin=[2.3,1.8];
out.gama=[0.1446,0.133];



% Ai : cross-section of tank i [cm^2]
% kc : The measured level signals are kc*h1 e kc*h2 [V/cm]
out.kc=1;
% ki : the water flow through Pump i is ki*vi [cm^3/Vs]
% g : gravity [cm/s^2]
% ai : cross-setion of the outlet hole [cm^2]
% linearized at hlin
% hi : water level [cm]
out.h0=out.hlin;
% linearized at vlin
out.v0=out.vlin;

