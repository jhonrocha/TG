clear all; clc;

path(pathdef);
warning('off','YALMIP:strict');

clc
QT=dynamics();
save export.mat

Simulink.Bus.createObject(QT.ctes);
%Simulink.Bus.createObject(QT.ctes);
