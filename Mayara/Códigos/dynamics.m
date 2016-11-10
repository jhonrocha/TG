function out = dynamics()
%gama : how the valve is set prior to an experiment [0,1]


ctes=load_ctes();
gama=ctes.gama;

Tmax = 2000;

out.ctes=ctes;
out.gama=gama;
ss = ss_linsys(gama,ctes);
out.ss.A = ss.A;
out.ss.B = ss.B;
out.ss.C = ss.C;
out.ss.D = ss.D;

out.G = transfer_function(gama,ctes);

if(out.G.Fase == 1)
    out.l5 = lema5(gama,ctes);
    out.l6 = lema6(gama,ctes);
    out.l8 = lema8(gama,ctes);
    out.alo = alocacao(gama,ctes,200,3,2);
    delta = [gama(1)*0.15 gama(2)*0.15];
    out.CR5=lema5_poli(gama,delta,ctes);
else
    out.l5 = lema5NM(gama,ctes);
    out.l6 = lema6NM(gama,ctes);
    out.l8 = lema8NM(gama,ctes);
    out.alo = alocacao(gama,ctes,200,10,2);
    delta = [0.2 0.2];
    out.CR5=lema5_poli_NM(gama,delta,ctes);
end

end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% FUNCTIONS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%_______________________________________
function dh = nonlinsys(t,h,gama,ctes)
dh = zeros(4,1);    % a column vector

% ----------------
dh(1) = -ctes.a1/ctes.A1*sqrt(2*ctes.g*h(1))+ctes.a3/ctes.A1*sqrt(2*ctes.g*h(3))+gama(1)*ctes.k1*v1(t)/ctes.A1;
dh(2) = -ctes.a2/ctes.A2*sqrt(2*ctes.g*h(2))+ctes.a4/ctes.A2*sqrt(2*ctes.g*h(4))+gama(2)*ctes.k2*v2(t)/ctes.A2;
dh(3) = -ctes.a3/ctes.A3*sqrt(2*ctes.g*h(3))+(1-gama(2))*ctes.k2*v2(t)/ctes.A3; 
dh(4) = -ctes.a4/ctes.A4*sqrt(2*ctes.g*h(4))+(1-gama(1))*ctes.k1*v1(t)/ctes.A4;
end
function dx = linsys(t,x,gama,ctes)
dx = zeros(4,1);    % a column vector
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
dx = Ass*x+Bss*[v1(t)-ctes.v0(1);v2(t)-ctes.v0(2)];

end
function V1=v1(t) %gsecond
V1=2.05*ones(1,length(t))+0*sin(t/10);
end
function V2=v2(t) %gsecond
V2=2.13*ones(1,length(t))+0*t;
end
function comparison_nl_l(gama,Tmax,ctes)

options = odeset('RelTol',1e-4,'AbsTol',[1e-2 1e-2 1e-2 1e-2]);
figure, plot(0,0), 
hold on
[Tnl,Xnl] = ode23t(@nonlinsys,[0 Tmax],ctes.h0,options,gama,ctes);
[Tl,Xl] = ode45(@linsys,[0 Tmax],[ctes.h0-ctes.hlin],options,gama,ctes);
subplot(2,2,1);
plot(Tnl,Xnl(:,1),'r',Tl,Xl(:,1)+ctes.h0(1)*ones(length(Xl),1),'g');
title('H(1)');
legend('non linear','linear');
subplot(2,2,2);
plot(Tnl,Xnl(:,2),'r',Tl,Xl(:,2)+ctes.h0(2)*ones(length(Xl),1),'g');
title('H(2)');
subplot(2,2,3);
plot(Tnl,Xnl(:,3),'r',Tl,Xl(:,3)+ctes.h0(3)*ones(length(Xl),1),'g');
title('H(3)');
subplot(2,2,4);
plot(Tnl,Xnl(:,4),'r',Tl,Xl(:,4)+ctes.h0(4)*ones(length(Xl),1),'g');
title('H(4)');
hold off
xlabel('(t)');ylabel('h(t)');
%Ponto de linearização: 
display(['out.hlin=[',num2str(Xnl(length(Xnl),1)),';',num2str(Xnl(length(Xnl),2)),';',num2str(Xnl(length(Xnl),3)),';',num2str(Xnl(length(Xnl),4)),'];']);

end
function plano_de_fase(gama,Tmax,ctes)
hstep = 2;
options = odeset('RelTol',1e-4,'AbsTol',[1e-2 1e-2 1e-2 1e-2]);
figure, plot(0,0), axis([0 40 0 40]), hold on
for x1=0:hstep:40 %Cond. inicial x
    for x2=0:hstep:40 %Cond. inicial y
        [T,X] = ode45(@nonlinsys,[0 Tmax/400],[x1;x2;ctes.h0(3);ctes.h0(4)],options,gama,ctes);     
        plot(X(:,2),X(:,1));
    end
end
hold off
xlabel('h_2(t)');ylabel('h_1(t)');
title('Plano de Fase');
end
function G = transfer_function(gama,ctes)
       sys=ss_linsys(gama,ctes);
       s=tf('s');
       systf = get(sys,'C')/(eye(4)*s-get(sys,'A'))*get(sys,'B')+get(sys,'D'); 
        
        
        G.G4=systf;
        G.G11.Num=[cell2mat(get(systf(1,1),'num'))];
        G.G12.Num=[cell2mat(get(systf(2,1),'num'))];
        G.G13.Num=[cell2mat(get(systf(3,1),'num'))];
        G.G14.Num=[cell2mat(get(systf(4,1),'num'))];
        
        G.G11.Den=[cell2mat(get(systf(1,1),'den'))];
        G.G12.Den=[cell2mat(get(systf(2,1),'den'))];
        G.G13.Den=[cell2mat(get(systf(3,1),'den'))];
        G.G14.Den=[cell2mat(get(systf(4,1),'den'))];

        G.G21.Num=[cell2mat(get(systf(1,2),'num'))];
        G.G22.Num=[cell2mat(get(systf(2,2),'num'))];
        G.G23.Num=[cell2mat(get(systf(3,2),'num'))];
        G.G24.Num=[cell2mat(get(systf(4,2),'num'))];
        
        G.G21.Den=[cell2mat(get(systf(1,2),'den'))];
        G.G22.Den=[cell2mat(get(systf(2,2),'den'))];
        G.G23.Den=[cell2mat(get(systf(3,2),'den'))];
        G.G24.Den=[cell2mat(get(systf(4,2),'den'))]; 
      
        %%
        % Desacolpador U-U

        G.D12.Num=[cell2mat(get(-1/systf(2,2)*systf(2,1),'num'))]; 
        G.D12.Den=[cell2mat(get(-1/systf(2,2)*systf(2,1),'den'))];

        G.D21.Num=[cell2mat(get(-1/systf(1,1)*systf(1,2),'num'))]; 
        G.D21.Den=[cell2mat(get(-1/systf(1,1)*systf(1,2),'den'))];
        
        % Funcao de Transferencia da Planta com Desacoplador em MA (G*D)
        G.GD11.Num=[cell2mat(get(systf(1,1)-systf(1,2)*systf(2,1)/systf(2,2),'num'))];
        G.GD11.Den=[cell2mat(get(systf(1,1)-systf(1,2)*systf(2,1)/systf(2,2),'den'))];
        
        tal1=2;% constante de tempo da planta em MA para h1u1: G.G11.Den(1)/G.G11.Den(2);
        tal2=2;% constante de tempo da planta em MA para h2u2: G.G22.Den(1)/G.G22.Den(2);
        % Controlador Desacoplado U-U
        G.CDa11.Num=[cell2mat(get(1/(tal1*tf('s')*(systf(1,1)-systf(1,2)*systf(2,1)/systf(2,2))),'num'))];
        G.CDa11.Den=[cell2mat(get(1/(tal1*tf('s')*(systf(1,1)-systf(1,2)*systf(2,1)/systf(2,2))),'den'))];
        G.CDa22.Num=[cell2mat(get(1/(tal2*tf('s')*(systf(2,2)-systf(1,2)*systf(2,1)/systf(1,1))),'num'))];
        G.CDa22.Den=[cell2mat(get(1/(tal2*tf('s')*(systf(2,2)-systf(1,2)*systf(2,1)/systf(1,1))),'den'))];
        
        %%
        % Controlador Descentralizado U-U MINIMO
        % (G.G11.Den(2))/(G.G11.Den(1)) = 1/tal  tal: new time constant
        % Controller = 1/G11 * 1/(tal*s)
        tal1=2;% tempo de subida Ts=4/Re(polo)=4*tal1 constante de tempo da planta em MA para h1u1: G.G11.Den(1)/G.G11.Den(2);
        tal2=2;% tempo de subida Ts=4/Re(polo)=4*tal2 constante de tempo da planta em MA para h2u2: G.G22.Den(1)/G.G22.Den(2);
        G.CDc11.Num=[cell2mat(get(1/(tal1*tf('s')*systf(1,1)),'num'))];
        G.CDc11.Den=[cell2mat(get(1/(tal1*tf('s')*systf(1,1)),'den'))];
        G.CDc22.Num=[cell2mat(get(1/(tal2*tf('s')*systf(2,2)),'num'))];
        G.CDc22.Den=[cell2mat(get(1/(tal2*tf('s')*systf(2,2)),'den'))];

        % Controlador Descentralizado U-U Nao minimo       
        % Resposta mais rápida: os dois polos vezes por 2
         G.CDc12NM.Num=[cell2mat(get(G.G12.Den(3)/systf(2,1)*1/(G.G12.Den(1)/4*tf('s')*tf('s')+G.G12.Den(2)/2*tf('s')),'num'))];        
         G.CDc12NM.Den=[cell2mat(get(G.G12.Den(3)/systf(2,1)*1/(G.G12.Den(1)/4*tf('s')*tf('s')+G.G12.Den(2)/2*tf('s')),'den'))];        
         G.CDc21NM.Num=[cell2mat(get(G.G21.Den(3)/systf(1,2)*1/(G.G21.Den(1)/4*tf('s')*tf('s')+G.G21.Den(2)/2*tf('s')),'num'))];
         G.CDc21NM.Den=[cell2mat(get(G.G21.Den(3)/systf(1,2)*1/(G.G21.Den(1)/4*tf('s')*tf('s')+G.G21.Den(2)/2*tf('s')),'den'))];


        
        
        %% 
        % Desacoplador Y-U
        
        Dy3y1 = -systf(1,2)/(systf(3,2)*systf(1,1));        
        Dy4y2 = -systf(2,1)/(systf(4,1)*systf(2,2));
        
        G.Dy3y1.Den=[cell2mat(get(Dy3y1,'den'))];
        G.Dy3y1.Num=[cell2mat(get(Dy3y1,'num'))];
        
        G.Dy4y2.Den=[cell2mat(get(Dy4y2,'den'))];
        G.Dy4y2.Num=[cell2mat(get(Dy4y2,'num'))];
     
        % Controlador do Desacoplado Y-U
        tal1=2;% constante de tempo da planta em MA para h1u1: G.G11.Den(1)/G.G11.Den(2);
        tal2=2;% constante de tempo da planta em MA para h2u2: G.G22.Den(1)/G.G22.Den(2);        
        G.CDay11.Num=[cell2mat(get(1/(tal1*tf('s')*(systf(1,1)-systf(1,2)*systf(2,1)/systf(2,2))),'num'))];
        G.CDay11.Den=[cell2mat(get(1/(tal1*tf('s')*(systf(1,1)-systf(1,2)*systf(2,1)/systf(2,2))),'den'))];
        G.CDay22.Num=[cell2mat(get(1/(tal2*tf('s')*(systf(2,2)-systf(1,2)*systf(2,1)/systf(1,1))),'num'))];
        G.CDay22.Den=[cell2mat(get(1/(tal2*tf('s')*(systf(2,2)-systf(1,2)*systf(2,1)/systf(1,1))),'den'))];
        
        % Desacoplador simplified decoupling GVM12.pdf
        
        G.G2=systf;
        
        g12g11 = -systf(1,2)/systf(1,1);       
        g21g22 = -systf(2,1)/systf(2,2);
        
        if (gama(1)+gama(2)) <= 1
            display('fase nao-minima')
            K=-[g12g11 1;1 g21g22];
            
            G.SDQ=systf*K;
            [G.SDPID1,info] = pidtune(G.SDQ(2,1),'pid')
            [G.SDPID2,info] = pidtune(G.SDQ(1,2),'pid')
            G.Fase = 2
            
            Q=(systf*K);
            Q=[0,Q(1,2);Q(2,1),0];
%             % Controller = 1/G11 * 1/(tal*s)
%             tal1=1000;% constante de tempo da planta ;
%             tal2=1000;% constante de tempo da planta ;
%             G.SD.NMDc12.Num=[cell2mat(get(1/(tal1*tf('s')*Q(2,1)),'num'))];
%             G.SD.NMDc12.Den=[cell2mat(get(1/(tal1*tf('s')*Q(2,1)),'den'))];
%             G.SD.NMDc21.Num=[cell2mat(get(1/(tal2*tf('s')*Q(1,2)),'num'))];
%             G.SD.NMDc21.Den=[cell2mat(get(1/(tal2*tf('s')*Q(1,2)),'den'))];
            
        else
            display('fase minima')                        
            K=[1 g12g11;g21g22 ,1];
            
            G.SDQ=systf*K
            [G.SDPID1,info] = pidtune(G.SDQ(1,1),'pid')
            [G.SDPID2,info] = pidtune(G.SDQ(2,2),'pid')
            G.Fase = 1
            
            Q=(systf*K);         
            Q=[Q(1,1),0;0,Q(2,2)];
                        
        end
        
        G.SD.Q = Q;
        G.SD11.Den=[cell2mat(get(K(1,1),'den'))];
        G.SD11.Num=[cell2mat(get(K(1,1),'num'))];
                
        G.SD21.Den=[cell2mat(get(K(1,2),'den'))];
        G.SD21.Num=[cell2mat(get(K(1,2),'num'))];
        
        G.SD12.Den=[cell2mat(get(K(2,1),'den'))];
        G.SD12.Num=[cell2mat(get(K(2,1),'num'))];
        
        G.SD22.Den=[cell2mat(get(K(2,2),'den'))];
        G.SD22.Num=[cell2mat(get(K(2,2),'num'))];
        
     
end

