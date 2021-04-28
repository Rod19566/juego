/*  AQUÍ COMIENZA EL
       *   CUARTO SPRITE x3 Y
       *  SUS CONDICIONES
       
        if (x3 == 0){ //si x3==0 (que era el ranarrow pasado) es la flecha up
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeuparrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x35002f);
            if (digitalRead(up)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(up)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(up)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(up)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
          }// else
        
        } //switch num

         
      }//if x3 == 0 (flecha up)
      
          
        if (x3 == 1){ //si x3==1 (que era el ranarrow pasado) es la flecha down
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activedownarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x35002f);
            if (digitalRead(down)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(down)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(down)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(down)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
          }// else
        } //switch num 
      }//if x3 == 0 (flecha down)
      
          
        if (x3 == 2){ //si x3==2 (que era el ranarrow pasado) es la flecha left
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeleftarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x35002f);
            if (digitalRead(left)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(left)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(left)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(left)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
          }// else
        } //switch num 
      }//if x3 == 0 (flecha left)
      
          
        if (x3 == 3){ //si x3==3 (que era el ranarrow pasado) es la flecha right
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activerightarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x35002f);
            if (digitalRead(right)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(right)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(right)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(right)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
          }// else
        } //switch num 
      }//if x3 == 3 (flecha right)
      
        if (x3 == 4){ //si x3==4 (que era el ranarrow pasado) es la flecha up
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeuparrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x35002f);
            if (digitalRead(up)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(up)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(up)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(up)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
          }// else
        
        } //switch num

         
      }//if x3 == 4 (flecha up)
      
          
        if (x3 == 5){ //si x3==5 (que era el ranarrow pasado) es la flecha down
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activedownarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x35002f);
            if (digitalRead(down)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(down)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(down)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(down)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
          }// else
        } //switch num 
      }//if x3 == 5 (flecha down)
      
          
        if (x3 == 6){ //si x3==6 (que era el ranarrow pasado) es la flecha left
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeleftarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x35002f);
            if (digitalRead(left)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(left)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(left)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(left)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
          }// else
        } //switch num 
      }//if x3 == 6 (flecha left)
      
          
        if (x3 == 7){ //si x3==7 (que era el ranarrow pasado) es la flecha right
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activerightarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x35002f);
            if (digitalRead(right)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(right)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(right)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f);
               if (digitalRead(right)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x35002f); 
              break; 
          }// else
        } //switch num 
      }//if x3 == 7 (flecha right)
        AQUÍ TERMINA EL
       *  CUERTO SPRITE x3 Y
       *  SUS CONDICIONES
       */
