/*
void sprgenerator(int arrowi, int xi, int yi);
int choosearrow(int rando);
int nonrepeater(void);
int checkrand(void);
void movement(int ar);

extern uint8_t activeuparrow[];
extern uint8_t activedownarrow[];
extern uint8_t activeleftarrow[];
extern uint8_t activerightarrow[];
extern uint8_t activeuparrow1[];
extern uint8_t activedownarrow1[];
extern uint8_t activeleftarrow1[];
extern uint8_t activerightarrow1[];
extern uint8_t placementarrows[];
//int ranarrow = 6;            //elige al azar la flecha
int ys = 0; //y temporal
/*const int yup = 0; //y up
const int ydown = 180; //y down
const int yleft = 60; //y left
const int yright = 120; //y right
//int anim2 = 0; 
int ar0 = 0;
int ar1 = 1;
int ar2 = 2;
int ar3 = 3;


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


void movement(int ari, int xi, int yi){
   switch (ari){
    case 0: 
    sprgenerator(activeuparrow, xi, yi);
    break;
    case 1: 
    sprgenerator(activedownarrow, xi, yi);
    break;
    case 2: 
    sprgenerator(activeleftarrow, xi, yi);
    break;
    case 3: 
    sprgenerator(activerightarrow, xi, yi);
    break;
    case 4: 
    sprgenerator(activeuparrow1, xi, yi);
    break;
    case 5: 
    sprgenerator(activedownarrow1, xi, yi);
    break;
    case 6: 
    sprgenerator(activeleftarrow1, xi, yi);
    break;
    case 7: 
    sprgenerator(activerightarrow1, xi, yi);
    break;
  } //switch
  V_line( xi -1, yi, 60, 0x05002f);
}//movement

void sprgenerator(unsigned char arrow[], int xsg, int ysg){ //generates arrow
  LCD_Sprite(xsg,ysg,60,60,arrow,4,anim2,0,1);
  V_line( xsg - 1, ysg, 60, 0x05002f);
} //spr

/*int checkrand(void){  //makes sure that the sprites don't repeat
  while (ranarrow == ar1 || ranarrow == ar2 || ranarrow == ar3 || ranarrow == ar0){
    ranarrow = random(8); 
  }
  return checkrand();
}

void game(void){
  // for(int cont = 0; cont != 10;cont++){ //la cantidad de veces que pasarán las flechas 
  int ys = 0; //asignación y del sprite
  int y0 = 0; //y sprite 1
  int y1 = 180; //y sprite 2
  int y2 = 60; //y sprite 3
  int y3 = 120; //y sprite 4
  int x0 = 0; //x sprite 1
  int x1 = 0; //x sprite 2
  int x2 = 0; //x sprite 3
  int x3 = 0; //x sprite 4
      int num = 0;   
      int points = 0;
      for (int cont=0; cont<5; cont++){
        for (int x=0; x<260; x++){ 
          ranarrow = random(8); 
          anim2 = (x/35)%2;
          if (x==0){
            ar0 = choosearrow(ranarrow);
            x0 = 0;
            y0 = ys; 
          } //if 65
          if (x==65){
            ar1 = choosearrow(ranarrow);
            x1 = 0;
            y1 = ys; 
          } //if 65
          if (x==130){
            ar2 = choosearrow(ranarrow);
            x2 = 0;
            y2 = ys; 
          } //if 130
          if (x==195){
            ar3 = choosearrow(ranarrow);
            x3 = 0;
            y3 = ys; 
          } //if 195
          sprgenerator(ar0, x0, y0);
          sprgenerator(ar1, x1, y1);
          sprgenerator(ar2, x2, y2);
          sprgenerator(ar3, x3, y3);
          x0++;
          x1++;
          x2++;
          x3++;
          
        }// for x
        
      }// for cont
}//void game
*/
