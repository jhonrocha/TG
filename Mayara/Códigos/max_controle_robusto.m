function MCR = max_controle_robusto(gama,ctes)
        
        %% l8
        delta=0;
        incremento=0.1;
        while(incremento>0.01)            
            l8=lema8_poli(gama,[delta delta],ctes);
            if(l8.feaseble==(0))
                    incremento=incremento/2;
                    delta=delta-incremento
            else
                    CR.l8=l8;
                    delta8=delta
                    delta=delta+incremento                    
            end        
        end         

        % l6
        delta=0;
        incremento=0.1;
        while(incremento>0.01)
            l6=lema6_poli(gama,[delta delta],ctes);
            if(l6.feaseble==(0))
                    incremento=incremento/2;
                    delta=delta-incremento
            else               
                    CR.l6=l6;
                    delta6=delta
                    delta=delta+incremento
            end        
        end 
        
        % l5
        delta=0;
        incremento=0.1;
        while(incremento>0.01)
            l5=lema5_poli(gama,[delta delta],ctes);
            if(l5.feaseble==(0))
                    incremento=incremento/2;
                    delta=delta-incremento
            else
                    CR.l5=l5;
                    delta5=delta                   
                    delta=delta+incremento
            end        
        end 
        
        
        if((delta8>delta6)&&(delta8>delta5))
            MCR.delta=delta8;
            MCR.K=lema8_poli(gama,[delta8 delta8],ctes);
            MCR.lema=8;
            sys=ss_linsys([gama(1)-delta8 gama(2)-delta8],ctes);
            MCR.B = get(sys,'B');
        else
            if((delta6>delta8)&&(delta6>delta5))
                MCR.delta=delta6;
                MCR.K=lema6_poli(gama,[delta6 delta6],ctes);
                MCR.lema=6;
                sys=ss_linsys([gama(1)-delta6 gama(2)-delta6],ctes);
                MCR.B = get(sys,'B');
            else
                MCR.delta=delta5;
                MCR.K=lema5_poli(gama,[delta5 delta5],ctes);
                MCR.lema=5;
                sys=ss_linsys([gama(1)-delta5 gama(2)-delta5],ctes);
                MCR.B = get(sys,'B');
            end           
        end        
        
end