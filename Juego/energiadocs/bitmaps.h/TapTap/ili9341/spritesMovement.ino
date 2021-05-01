/*
int game(int up, int down, int left, int right){
     // for(int cont = 0; cont != 10;cont++){ //la cantidad de veces que pasarán las flechas 
      int ranarrow = 5;            //elige al azar la flecha
      int num = 0;   
      int points = 0;
      int x0 = 0; //van a guardar la la variable ranarrow al cambiarse, estos son las flechas visibles
      int x1 = 1;  //representa el movimiento de cada sprite en pantalla
      int x2 = 2;
      int x3 = 3;
      for(int x = 0; x <320-60; x++){
        delay(10);                  //delay para ver el movimento
        int anim2 = (x/35)%2;
 //String text2 = "Iniciar";
 //LCD_Print(text1, 20, 100, 2, 0xffff, 0x05002f);
       // while (x0==x1 || x0==x2 ||  x0==x3 ||  x1==x2 ||  x1==x3 ||  x2==x3){ //evitará que se repitan las flechas 
         // points++;
          if(x==0){
            num = 1;
            while (ranarrow==x1 || ranarrow==x2 || ranarrow==x3 || ranarrow==x0 ){
               ranarrow = random(8);       //genera un numero al azar para elegir qué flecha ir
            }
            
            x3 = x0;               
            x0 = ranarrow; //se asigna la flecha 
               
        }
          if (x==80){
            num = 2;
            while (ranarrow==x0 || ranarrow==x2 || ranarrow==x3 || ranarrow==x1){
               ranarrow = random(8);       //genera un numero al azar para elegir qué flecha ir
            }
            x0 = x1 ;
            x1 = ranarrow;
        } 
          if (x==160){
            num = 3;
            while (ranarrow==x0 || ranarrow==x1 || ranarrow==x3 || ranarrow==x2){
               ranarrow = random(8);       //genera un numero al azar para elegir qué flecha ir
            }
            x1 = x2; 
            x2 = ranarrow;
        }
          if (x==240){
            num = 4;
            while (ranarrow==x0 || ranarrow==x2 || ranarrow==x1 || ranarrow==x3){
               ranarrow = random(8);       //genera un numero al azar para elegir qué flecha ir
            }
            x2 = x3; 
            x3 = ranarrow;
        }
        
  //    } // 0 y 4 up -- 1 y 5 down -- 2 y 6 left -- 3 y 7 right   arrows WHILE
       // ar1 = randomS(ranarrow);
      
        
      
////SPRITES///////////SPRITES///////////SPRITES///////////SPRITES///////////SPRITES///////////SPRITES///////////SPRITES///////
      /*  AQUÍ COMIENZA EL
       *   PRIMER SPRITE x0 Y
       *  SUS CONDICIONES
       */
  /*      if (x0 == 0){ //si x0==0 (que era el ranarrow pasado) es la flecha up
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeuparrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(up)==0 &&  240<x<290){
              points = points+100;
          }
           // break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        
        } //switch num

         
      }//if x0 == 0 (flecha up)
      
         
        if (x0 == 1){ //si x0==1 (que era el ranarrow pasado) es la flecha down
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activedownarrow,4,anim2,0,1);
            V_line( x - 1, 0, 24, 0x05002f);
            if (digitalRead(down)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x0 == 0 (flecha down)
      
          
        if (x0 == 2){ //si x0==2 (que era el ranarrow pasado) es la flecha left
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeleftarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(left)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x0 == 0 (flecha left)
      
          
        if (x0 == 3){ //si x0==3 (que era el ranarrow pasado) es la flecha right
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activerightarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(right)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x0 == 3 (flecha right)
      
        if (x0 == 4){ //si x0==4 (que era el ranarrow pasado) es la flecha up
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeuparrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(up)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        
        } //switch num

         
      }//if x0 == 4 (flecha up)
      
//        */  
 /*       if (x0 == 5){ //si x0==5 (que era el ranarrow pasado) es la flecha down
          switch (num){
            case(1):
            LCD_Sprite(x,180,60,60,activedownarrow1,4,anim2,0,1);
            V_line( (x)-1 , 180, 60, 0x05002f);
            if (digitalRead(down)==1 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,180,60,60,activedownarrow1,4,anim2,0,1);
              V_line( (x)-1 , 180, 60, 0x05002f);
               if (digitalRead(down)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,180,60,60,activedownarrow1,4,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,180,60,60,activedownarrow1,4,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,180,60,60,activedownarrow1,4,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,180,60,60,activedownarrow1,4,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,180,60,60,activedownarrow1,4,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x0 == 5 (flecha down)
      
          
        if (x0 == 6){ //si x0==6 (que era el ranarrow pasado) es la flecha left
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeleftarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(left)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x0 == 6 (flecha left)
      
         /*
        if (x0 == 7){ //si x0==7 (que era el ranarrow pasado) es la flecha right
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activerightarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(right)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x0 == 7 (flecha right)
      /*  AQUÍ TERMINA EL
       *   PRIMER SPRITE X0 Y
       *  SUS CONDICIONES
       */ 
       /*  AQUÍ COMIENZA EL
       *   SEGUNDO SPRITE x1 Y
       *  SUS CONDICIONES
       *//*
        if (x1 == 0){ //si x1==0 (que era el ranarrow pasado) es la flecha up
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeuparrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(up)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        
        } //switch num

         
      }//if x1 == 0 (flecha up)
      
          
        if (x1 == 1){ //si x1==1 (que era el ranarrow pasado) es la flecha down
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activedownarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(down)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x1 == 0 (flecha down)
      
          
        if (x1 == 2){ //si x1==2 (que era el ranarrow pasado) es la flecha left
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeleftarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(left)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x1 == 0 (flecha left)
      
          
        if (x1 == 3){ //si x1==3 (que era el ranarrow pasado) es la flecha right
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activerightarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(right)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x1 == 3 (flecha right)
      
        if (x1 == 4){ //si x1==4 (que era el ranarrow pasado) es la flecha up
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeuparrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(up)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        
        } //switch num

         
      }//if x1 == 4 (flecha up)
      
          
        if (x1 == 5){ //si x1==5 (que era el ranarrow pasado) es la flecha down
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activedownarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(down)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x1 == 5 (flecha down)
      
          
        if (x1 == 6){ //si x1==6 (que era el ranarrow pasado) es la flecha left
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeleftarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(left)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x1 == 6 (flecha left)
      
          
        if (x1 == 7){ //si x1==7 (que era el ranarrow pasado) es la flecha right
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activerightarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(right)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x1 == 7 (flecha right)
      /*  AQUÍ TERMINA EL
       *  SEGUNDO SPRITE x1 Y
       *  SUS CONDICIONES
       */
       /*  AQUÍ COMIENZA EL
       *   TERCER SPRITE x2 Y
       *  SUS CONDICIONES
       *//*
        if (x2 == 0){ //si x2==0 (que era el ranarrow pasado) es la flecha up
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeuparrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(up)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        
        } //switch num

         
      }//if x2 == 0 (flecha up)
      
          
        if (x2 == 1){ //si x2==1 (que era el ranarrow pasado) es la flecha down
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activedownarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(down)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x2 == 0 (flecha down)
      
          
        if (x2 == 2){ //si x2==2 (que era el ranarrow pasado) es la flecha left
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeleftarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(left)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x2 == 0 (flecha left)
      
          
        if (x2 == 3){ //si x2==3 (que era el ranarrow pasado) es la flecha right
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activerightarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(right)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x2 == 3 (flecha right)
      
        if (x2 == 4){ //si x2==4 (que era el ranarrow pasado) es la flecha up
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeuparrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(up)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        
        } //switch num

         
      }//if x2 == 4 (flecha up)
      
          
        if (x2 == 5){ //si x2==5 (que era el ranarrow pasado) es la flecha down
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activedownarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(down)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x2 == 5 (flecha down)
      
          
        if (x2 == 6){ //si x2==6 (que era el ranarrow pasado) es la flecha left
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeleftarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(left)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x2 == 6 (flecha left)
      
          
        if (x2 == 7){ //si x2==7 (que era el ranarrow pasado) es la flecha right
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activerightarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(right)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x2 == 7 (flecha right)
      /*  AQUÍ TERMINA EL
       *  TERCER SPRITE x2 Y
       *  SUS CONDICIONES
       */
       /*  AQUÍ COMIENZA EL
       *   CUARTO SPRITE x3 Y
       *  SUS CONDICIONES
       *//*
       if (x3 == 0){ //si x3==0 (que era el ranarrow pasado) es la flecha up
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeuparrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(up)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        
        } //switch num

         
      }//if x3 == 0 (flecha up)
      
          
        if (x3 == 1){ //si x3==1 (que era el ranarrow pasado) es la flecha down
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activedownarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(down)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x3 == 0 (flecha down)
      
          
        if (x3 == 2){ //si x3==2 (que era el ranarrow pasado) es la flecha left
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeleftarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(left)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x3 == 0 (flecha left)
      
          
        if (x3 == 3){ //si x3==3 (que era el ranarrow pasado) es la flecha right
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activerightarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(right)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x3 == 3 (flecha right)
      
        if (x3 == 4){ //si x3==4 (que era el ranarrow pasado) es la flecha up
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeuparrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(up)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(up)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        
        } //switch num

         
      }//if x3 == 4 (flecha up)
      
          
        if (x3 == 5){ //si x3==5 (que era el ranarrow pasado) es la flecha down
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activedownarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(down)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(down)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x3 == 5 (flecha down)
      
          
        if (x3 == 6){ //si x3==6 (que era el ranarrow pasado) es la flecha left
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeleftarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(left)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(left)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x3 == 6 (flecha left)
      
          
        if (x3 == 7){ //si x3==7 (que era el ranarrow pasado) es la flecha right
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activerightarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x05002f);
            if (digitalRead(right)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f);
               if (digitalRead(right)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x05002f); 
              break; 
          }// else
        } //switch num 
      }//if x3 == 7 (flecha right)
      /*  AQUÍ TERMINA EL
       *  CUARTO SPRITE x3 Y
       *  SUS CONDICIONES
       */
/////////////SPRITES///////////////////////////////////SPRITES/////////////////////////////////////////SPRITES/////////////////////////SPRITES///////////
      
      } //for 
  //     }//for cont
  return points;
}
