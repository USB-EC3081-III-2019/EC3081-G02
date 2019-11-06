   selector1 = n;
    switch(n){
        case'0':
            
            n=' ';
            Visualisar_Config();
            
            break;
        
        case'1':
             n = ' ';
             selector1 = 1;
            switch(selector1) {
                    case'1':
                        Temperatura();
                        if (n =='#'){
                            n = '0';
                        }
                    break;
                case'2':
                    Humedad();
                    if (n =='#'){
                        n = '0';
                        }
                    break;
            }
        case'2':
            
            
            break;
   
    }
