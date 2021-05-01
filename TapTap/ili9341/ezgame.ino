//void sprgenerator(unsigned char arrow, int x, int y);
void sprgenerator(int arrowi, int xi, int yi);
void ezgame(void);
void pointsadder(int pos);
/*
extern uint8_t activeuparrow[];
extern uint8_t activedownarrow[];
extern uint8_t activeleftarrow[];
extern uint8_t activerightarrow[];
extern uint8_t activeuparrow1[];
extern uint8_t activedownarrow1[];
extern uint8_t activeleftarrow1[];
extern uint8_t activerightarrow1[];
extern uint8_t placementarrows[];*/
int ranarrow = 6;            //elige al azar la flecha
const int yup = 0; //y up
const int ydown = 180; //y down
const int yleft = 60; //y left
const int yright = 120; //y right
int anim2 = 0; //push button flechas
int pointrefresher = 0;   

/*
#define up PC_4
#define down PC_5
#define left PC_6
#define right PC_7
*/
//push button flechas
/*int checkrand(void){  //makes sure that the sprites don't repeat
  while (ranarrow == ar1 || ranarrow == ar2 || ranarrow == ar3 || ranarrow == ar0){
    ranarrow = random(8); 
  }
  return checkrand();
}*/
void pointsadder(int pos){
   //points adder  
   
          if (240<=pos && pointrefresher==0){            
           // FillRect(0, 0, 63, 240, 0x05002f);
            if (ranarrow==0 ){            
              if (digitalRead(up)==LOW){
                points = points+100;
                pointrefresher = 1;
                 FillRect(0, 0, 64, 240, 0X05002f);
                LCD_Bitmap(2, 0, 60, 230, perfect); 
          }
              }//if ranarrow == 0
              
          if (ranarrow==1){
              if (digitalRead(down)==LOW){
                points = points+100;
                pointrefresher = 1;
                 FillRect(0, 0, 64, 240, 0X05002f);
                LCD_Bitmap(2, 0, 60, 230, perfect);    
              }
          }
          if (ranarrow==2){
              if (digitalRead(left)==LOW){
                points = points+100;
                pointrefresher = 1;
                 FillRect(0, 0, 64, 240, 0X05002f);
                LCD_Bitmap(2, 0, 60, 230, perfect);   
              }
          }
          if (ranarrow==3){   
              if (digitalRead(right)==LOW){
                points = points+100;
                pointrefresher = 1;
                 FillRect(0, 0, 64, 240, 0X05002f);
                LCD_Bitmap(2, 0, 60, 230, perfect);    
              }
          }
          }// if perfect   
           if (230<pos<240 && pointrefresher==0){
            if (ranarrow==0){            
              if (digitalRead(up)==LOW){
                points = points+50;
                pointrefresher = 1;
                 FillRect(0, 0, 64, 240, 0X05002f);
                LCD_Bitmap(2, 2, 48, 155, early); 
               // LCD_Bitmap(2, 0, 60, 230, perfect);    
              }
              }//if ranarrow == 0
              
          if (ranarrow==1 ){
              if (digitalRead(down)==LOW){
                points = points+50;
                pointrefresher = 1;
                 FillRect(0, 0, 64, 240, 0X05002f);
                 LCD_Bitmap(2, 2, 48, 155, early); 
              }
          }
          if (ranarrow==2){
              if (digitalRead(left)==LOW){
                points = points+50;
                pointrefresher = 1;
                 FillRect(0, 0, 64, 240, 0X05002f);
                 LCD_Bitmap(2, 2, 48, 155, early); 
              }
          }
          if (ranarrow==3){   
              if (digitalRead(right)==LOW){
                points = points+50;
                pointrefresher = 1;
                 FillRect(0, 0, 64, 240, 0X05002f);
                 LCD_Bitmap(2, 2, 48, 155, early); 
              }
          }
          }// if early
           
          
} //void pointsadder


void ezgame(void){
  // for(int cont = 0; cont != 10;cont++){ //la cantidad de veces que pasarán las flechas 
  const int yup = 0; //y up
  const int ydown = 180; //y down
  const int yleft = 60; //y left
  const int yright = 120; //y right
      for (int cont=0; cont<10; cont++){ //cuantos srpites
        LCD_Bitmap(255, 0, 60, 235, placementarrows); //se pone el objetivo
        ranarrow = random(4); 
        for (int x=65; x<260; x=x+4){
          
          V_line( 64 , 0, 240, 0x9BE123);
          delay(1); 
          //int anim3 = (x/11)%4;
          //anim2 = (x/35)%2;
          anim2 = (x/11)%4;
          
          if (ranarrow==0){
            LCD_Sprite(x,yup,60,60,activeuparrow,4,anim2,0,1);
           }
          if (ranarrow==1){
            LCD_Sprite(x,ydown,60,60,activedownarrow,4,anim2,0,1);
          }
          if (ranarrow==2){
            LCD_Sprite(x,yleft,60,60,activeleftarrow,4,anim2,0,1);
          }
          if (ranarrow==3){   
            LCD_Sprite(x,yright,60,60,activerightarrow,4,anim2,0,1);
          }
          V_line( x - 1 , 0, 240, 0x05002f);
          V_line( x - 2 , 0, 240, 0x05002f);
          V_line( x - 3 , 0, 240, 0x05002f);
          V_line( x - 4 , 0, 240, 0x05002f);

   
          pointsadder(x);
        }// for x
        if (pointrefresher==0){   //miss
          FillRect(0, 0, 64, 240, 0X05002f);
          LCD_Bitmap(2, 2, 45, 185, miss);  
          }
          else   {
            pointrefresher = 0;
          }
          
      }// for cont
      
       LCD_Clear(0x05002f); //pantalla inicialización
      String text1 = "Tap Tap Arrowssss!";
      String text2 = "Score: ";
      LCD_Print(text1, 20, 100, 2, 0xffff, 0x05002f);
      LCD_Print(text2 + points , 20, 50, 2, 0xffff, 0x05002f);
      
          delay(1000); 
}//void game
