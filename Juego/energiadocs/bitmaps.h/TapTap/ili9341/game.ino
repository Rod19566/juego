void sprgeneratory(unsigned char arrow, int y);
int choosearrow(int rando);
int nonrepeater(void);

extern uint8_t activeuparrow[];
extern uint8_t activedownarrow[];
extern uint8_t activeleftarrow[];
extern uint8_t activerightarrow[];
extern uint8_t activeuparrow1[];
extern uint8_t activedownarrow1[];
extern uint8_t activeleftarrow1[];
extern uint8_t activerightarrow1[];
extern uint8_t placementarrows[];
const int yup = 0; //y up
const int ydown = 180; //y down
const int yleft = 60; //y left
const int yright = 120; //y right
int ar0 = 0;
int ar1 = 1;
int ar2 = 2;
int ar3 = 3;
int ys = 0; //asignación y del sprite
int y0 = 0; //y sprite 1
int y1 = 180; //y sprite 2
int y2 = 60; //y sprite 3
int y3 = 120; //y sprite 4
int x0 = 0; //x sprite 1
int x1 = 0; //x sprite 2
int x2 = 0; //x sprite 3
int x3 = 0; //x sprite 4


int choosearrow(int rando){ //elige una flecha y asigna y
  switch (rando){
    case 0: 
    return rando; 
    ys = yup;
    break;
    case 1: 
    return rando; 
    ys = ydown;
    break;
    case 2: 
    return rando; 
    ys = yleft;
    break;
    case 3: 
    return rando; 
    ys = yright;
    break;
    case 4:
    return rando;  
    ys = yup;
    break;
    case 5: 
    return rando; 
    ys = ydown;
    break;
    case 6: 
    return rando; 
    ys = yleft;
    break;
    case 7: 
    return rando; 
    ys = yright;
    break;
  }// arrow
}


void movement(int ar, int x, int y){
   switch (ar){
    case 0: 
    sprgeneratory(activeuparrow[], x, y);
    break;
    case 1: 
    sprgeneratory(activedownarrow[], x, y);
    break;
    case 2: 
    sprgeneratory(activeleftarrow[], x, y);
    break;
    case 3: 
    sprgeneratory(activerightarrow[], x, y);
    break;
    case 4: 
    sprgeneratory(activeuparrow1[], x, y);
    break;
    case 5: 
    sprgeneratory(activedownarrow1[], x, y);
    break;
    case 6: 
    sprgeneratory(activeleftarrow1[], x, y);
    break;
    case 7: 
    sprgeneratory(activerightarrow1[], x, y);
    break;
  }
}

void sprgeneratory(unsigned char arrow, int x, int y){ //generates arrow
  LCD_Sprite(x,y,60,60,arrow,4,anim2,0,1);
  V_line( x - 1, y, 60, 0x05002f);
} //spr

int checkrand(void){  //makes sure that the sprites don't repeat
  while (ar0 == ar1 || ar0 == ar2 || ar == ar3 || ar1 == ar2 || ar1 == ar3 || ar2 == ar3){
    ranarrow = random(8); 
  }
}

void game(void){
  // for(int cont = 0; cont != 10;cont++){ //la cantidad de veces que pasarán las flechas 
      int ranarrow = random(8);            //elige al azar la flecha
      int num = 0;   
      int points = 0;
      for (int cont=0; cont<5; cont++){
        for (int x=0; x<260; x++){
          if (x==0){
            ar0 = choosearrow(checkrand());
            x0 = 0;
          } //if 65
          if (x==65){
            ar1 = choosearrow(checkrand());
            x1 = 0;
          } //if 65
          if (x==130){
            ar2 = choosearrow(checkrand());
            x2 = 0;
          } //if 130
          if (x==195){
            ar3 = choosearrow(checkrand());
            x3 = 0;
          } //if 195
          sprgeneratory(ar0, x0, y0);
          sprgeneratory(ar1, x1, y1);
          sprgeneratory(ar2, x2, y2);
          sprgeneratory(ar3, x3, y3);
          x0++;
          x1++;
          x2++;
          x3++;
          
        }// for x
        
      }// for cont
}//void game
