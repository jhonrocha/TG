function system = ss_linsys(gama,ctes)
% ----------------

T1=ctes.A1/ctes.a1*sqrt(2*ctes.hlin(1)/ctes.g);
T2=ctes.A2/ctes.a2*sqrt(2*ctes.hlin(2)/ctes.g);
T3=ctes.A3/ctes.a3*sqrt(2*ctes.hlin(3)/ctes.g);
T4=ctes.A4/ctes.a4*sqrt(2*ctes.hlin(4)/ctes.g);

Ass = [-1/T1 0 ctes.A3/(ctes.A1*T3) 0;
    0 -1/T2 0 ctes.A4/(ctes.A2*T4);
    0 0 -1/T3 0;
    0 0 0 -1/T4];
Bss = [gama(1)*ctes.k1/ctes.A1 0;
       0 gama(2)*ctes.k2/ctes.A2;
       0 (1-gama(2))*ctes.k2/ctes.A3;
       (1-gama(1))*ctes.k1/ctes.A4 0];
Css = [ctes.kc 0 0 0;
       0 ctes.kc 0 0;
       0 0 ctes.kc 0;
       0 0 0 ctes.kc];
Dss = [0 0;
       0 0;
       0 0;
       0 0];
     
system = ss(Ass,Bss,Css,Dss);

end