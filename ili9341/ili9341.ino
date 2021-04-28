
//***************************************************************************************************************************************
/* Librería para el uso de la pantalla ILI9341 en modo 8 bits
 * Basado en el código de martinayotte - https://www.stm32duino.com/viewtopic.php?t=637
 * Adaptación, migración y creación de nuevas funciones: Pablo Mazariegos y José Morales
 * Con ayuda de: José Guerra
 * IE3027: Electrónica Digital 2 - 2019
 */

//Dina Rodríguez    19566
//Proyecto 3
//Juego Portable

 
//***************************************************************************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include <TM4C123GH6PM.h>
#include <SPI.h>
#include <SD.h>

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"


#include "bitmaps.h"
#include "font.h"
#include "lcd_registers.h"

#define LCD_RST PD_0
#define LCD_CS PD_1
#define LCD_RS PD_2
#define LCD_WR PD_3
#define LCD_RD PE_1
int DPINS[] = {PB_0, PB_1, PB_2, PB_3, PB_4, PB_5, PB_6, PB_7};  //arreglo de pines

//push button flechas
#define up PC_4
#define down PC_5
#define left PC_6
#define right PC_7
const int buttonPin1 = PUSH1; //pushbutton para inicdel juego


int buzzerPin = PF_1; //buzzer

int ar0 = 0;
int ar1 = 0;
int ar2 = 0;
int ar3 = 0;
int ar4 = 0;
int ar5 = 0;
int ar6 = 0;
int points = 0;

//***************************************************************************************************************************************
// Functions Prototypes
//***************************************************************************************************************************************
void LCD_Init(void);
//void LCD_Init_5408(void);

void LCD_CMD(uint8_t cmd);
void LCD_DATA(uint8_t data);
void SetWindows(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
void LCD_Clear(unsigned int c);
void H_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c);
void V_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c);
void Rect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c);
void FillRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c);
void LCD_Print(String text, int x, int y, int fontSize, int color, int background);

void LCD_Bitmap(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned char bitmap[]);
void LCD_Sprite(int x, int y, int width, int height, unsigned char bitmap[],int columns, int index, char flip, char offset);

void randomS(int ran); //

extern uint8_t activeuparrow[];
extern uint8_t activedownarrow[];
extern uint8_t activeleftarrow[];
extern uint8_t activerightarrow[];
extern uint8_t activeuparrow1[];
extern uint8_t activedownarrow1[];
extern uint8_t activeleftarrow1[];
extern uint8_t activerightarrow1[];
extern uint8_t placementarrows[];


/*void randomS(int ran){ //intento de hacer una funcion de tipo char unsigned
  switch (ran){
    case (0): return activeuparrow;
    break; 
    case (1): return activedownarrow;
    break; 
    case (2): return activeleftarrow;
    break; 
    case (3): return activerightarrow;
    break; 
    
  }
}
*/

//***************************************************************************************************************************************
// Inicialización
//***************************************************************************************************************************************
void setup() {
  pinMode(buzzerPin,OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
  Serial.begin(115200);
  GPIOPadConfigSet(GPIO_PORTB_BASE, 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD_WPU);
  lib();
  
 // Serial.println("Inicio");
  LCD_Init(); // LCD_Init(void) 
  LCD_Clear(0x05002f); //pantalla inicialización
//  FillRect(0, 0, 319, 206, 05002f);
 String text1 = "Tap Tap Arrowssss!";
 String text2 = "Iniciar";
 LCD_Print(text1, 20, 100, 2, 0xffff, 0x05002f);
 LCD_Print(text2, 20, 50, 2, 0xffff, 0x05002f);
  
//LCD_Sprite(int x, int y, int width, int height, unsigned char bitmap[],int columns, int index, char flip, char offset);
    
  //LCD_Bitmap(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned char bitmap[]);

 /* 
  for(int x = 0; x <319; x++){
    LCD_Bitmap(x, 52, 16, 16, tile2);
    LCD_Bitmap(x, 68, 16, 16, tile);
    
    LCD_Bitmap(x, 207, 16, 16, tile);
    LCD_Bitmap(x, 223, 16, 16, tile);
    x += 15;
 }
  */
}
//***************************************************************************************************************************************
// Loop Infinito
//***************************************************************************************************************************************
void loop() {
 // /*
    
 if (digitalRead(PUSH1) == LOW){ //begin button
  hbd();
  points = 0;
  FillRect(0, 0, 319, 206, 0X05002f);
  LCD_Bitmap(250, 100, 60, 235, placementarrows); //se pone el objetivo
    //LCD_Bitmap(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned char bitmap[]);
      //int anim = (x1/11)%8; 
      //int anim3 = (x1/11)%4;
      
    for(int cont = 0; cont != 10;cont++){ //la cantidad de veces que pasarán las flechas 
      
      int x0 = 9; //van a guardar la la variable ranarrow al cambiarse, estos son las flechas visibles
      int x1 = 9;  //representa el movimiento de cada sprite en pantalla
      int x2 = 9;
      int x3 = 9;
      int ranarrow = 9;            //elige al azar la flecha
      int num = 0;                 //ayuda con el distanciamiento
      
      for(int x = 0; x <320-60; x++){
        delay(50);                  //delay para ver el movimento
        int anim2 = (x/35)%2;

        while (x0==x1 || x0==x2 ||  x0==x3 ||  x1==x2 ||  x1==x3 ||  x2==x3){ //evitará que se repitan las flechas 
          ranarrow = random(7);       //genera un numero al azar para elegir qué flecha irá
        } // 0 y 4 up -- 1 y 5 down -- 2 y 6 left -- 3 y 7 right   arrows
       // ar1 = randomS(ranarrow);
      
        if(x==0){
          num = 1;
          x0 = ranarrow; //se asigna la flecha
      }
        if (x==80){
          num = 2;
          x1 = ranarrow;
      } 
      if (x==160){
          num = 3;
          x2 = ranarrow;
      }
      if (x==240){
          num = 4;
          x3 = ranarrow;
      }
      
////SPRITES///////////SPRITES///////////SPRITES///////////SPRITES///////////SPRITES///////////SPRITES///////////SPRITES///////
      /*  AQUÍ COMIENZA EL
       *   PRIMER SPRITE x0 Y
       *  SUS CONDICIONES
       */
        if (x0 == 0){ //si x0==0 (que era el ranarrow pasado) es la flecha up
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

         
      }//if x0 == 0 (flecha up)
      
          
        if (x0 == 1){ //si x0==1 (que era el ranarrow pasado) es la flecha down
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
      
          
        if (x0 == 5){ //si x0==5 (que era el ranarrow pasado) es la flecha down
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
       */
        if (x1 == 0){ //si x1==0 (que era el ranarrow pasado) es la flecha up
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeuparrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x15002f);
            if (digitalRead(up)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(up)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(up)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(up)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break; 
          }// else
        
        } //switch num

         
      }//if x1 == 0 (flecha up)
      
          
        if (x1 == 1){ //si x1==1 (que era el ranarrow pasado) es la flecha down
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activedownarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x15002f);
            if (digitalRead(down)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(down)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(down)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(down)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break; 
          }// else
        } //switch num 
      }//if x1 == 0 (flecha down)
      
          
        if (x1 == 2){ //si x1==2 (que era el ranarrow pasado) es la flecha left
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeleftarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x15002f);
            if (digitalRead(left)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(left)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(left)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(left)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break; 
          }// else
        } //switch num 
      }//if x1 == 0 (flecha left)
      
          
        if (x1 == 3){ //si x1==3 (que era el ranarrow pasado) es la flecha right
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activerightarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x15002f);
            if (digitalRead(right)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(right)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(right)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(right)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break; 
          }// else
        } //switch num 
      }//if x1 == 3 (flecha right)
      
        if (x1 == 4){ //si x1==4 (que era el ranarrow pasado) es la flecha up
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeuparrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x15002f);
            if (digitalRead(up)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(up)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(up)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(up)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break; 
          }// else
        
        } //switch num

         
      }//if x1 == 4 (flecha up)
      
          
        if (x1 == 5){ //si x1==5 (que era el ranarrow pasado) es la flecha down
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activedownarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x15002f);
            if (digitalRead(down)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(down)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(down)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(down)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break; 
          }// else
        } //switch num 
      }//if x1 == 5 (flecha down)
      
          
        if (x1 == 6){ //si x1==6 (que era el ranarrow pasado) es la flecha left
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeleftarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x15002f);
            if (digitalRead(left)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(left)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(left)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(left)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break; 
          }// else
        } //switch num 
      }//if x1 == 6 (flecha left)
      
          
        if (x1 == 7){ //si x1==7 (que era el ranarrow pasado) es la flecha right
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activerightarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x15002f);
            if (digitalRead(right)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(right)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(right)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f);
               if (digitalRead(right)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x15002f); 
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
       */
        if (x2 == 0){ //si x2==0 (que era el ranarrow pasado) es la flecha up
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeuparrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x25002f);
            if (digitalRead(up)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(up)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(up)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(up)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeuparrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break; 
          }// else
        
        } //switch num

         
      }//if x2 == 0 (flecha up)
      
          
        if (x2 == 1){ //si x2==1 (que era el ranarrow pasado) es la flecha down
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activedownarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x25002f);
            if (digitalRead(down)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(down)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(down)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(down)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activedownarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break; 
          }// else
        } //switch num 
      }//if x2 == 0 (flecha down)
      
          
        if (x2 == 2){ //si x2==2 (que era el ranarrow pasado) es la flecha left
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeleftarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x25002f);
            if (digitalRead(left)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(left)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(left)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(left)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeleftarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break; 
          }// else
        } //switch num 
      }//if x2 == 0 (flecha left)
      
          
        if (x2 == 3){ //si x2==3 (que era el ranarrow pasado) es la flecha right
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activerightarrow,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x25002f);
            if (digitalRead(right)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(right)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(right)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(right)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activerightarrow,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break; 
          }// else
        } //switch num 
      }//if x2 == 3 (flecha right)
      
        if (x2 == 4){ //si x2==4 (que era el ranarrow pasado) es la flecha up
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeuparrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x25002f);
            if (digitalRead(up)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(up)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(up)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(up)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeuparrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break; 
          }// else
        
        } //switch num

         
      }//if x2 == 4 (flecha up)
      
          
        if (x2 == 5){ //si x2==5 (que era el ranarrow pasado) es la flecha down
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activedownarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x25002f);
            if (digitalRead(down)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(down)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(down)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(down)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activedownarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break; 
          }// else
        } //switch num 
      }//if x2 == 5 (flecha down)
      
          
        if (x2 == 6){ //si x2==6 (que era el ranarrow pasado) es la flecha left
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activeleftarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x25002f);
            if (digitalRead(left)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(left)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(left)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(left)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activeleftarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break; 
          }// else
        } //switch num 
      }//if x2 == 6 (flecha left)
      
          
        if (x2 == 7){ //si x2==7 (que era el ranarrow pasado) es la flecha right
          switch (num){
            case(1):
            LCD_Sprite(x,178,60,60,activerightarrow1,2,anim2,0,1);
            V_line( x - 1, 100, 24, 0x25002f);
            if (digitalRead(right)==0 &&  240<x<290){
              points = points+100;
          }
            break;
            case(2):
            if (x<60){ 
              LCD_Sprite(x+200,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(right)==0 && 40<x<90){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-60,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break;             
            }
            case(3):
            if (x<120){ 
              LCD_Sprite(x+140,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(right)==0 && 100<x<140){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-120,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
              break; 
            }
            case(4):
            if (x<180){ 
              LCD_Sprite(x+80,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f);
               if (digitalRead(right)==0 && 160<x<200){
                points = points+100;
          }
              break;
            } else {
              LCD_Sprite(x-180,178,60,60,activerightarrow1,2,anim2,0,1);
              V_line( x - 1, 100, 24, 0x25002f); 
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
       */
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
      /*  AQUÍ TERMINA EL
       *  CUARTO SPRITE x3 Y
       *  SUS CONDICIONES
       */
/////////////SPRITES///////////////////////////////////SPRITES/////////////////////////////////////////SPRITES/////////////////////////SPRITES///////////
      
      }//for 
       }//for cont
    }// if buttonpin 1 (start)
        LCD_Clear(0x05002f); //pantalla inicialización
      FillRect(0, 0, 319, 206, 0x05002f);
      String text1 = "Tap Tap Arrowssss!";
      String text2 = "Score: ";
       LCD_Print(text1, 20, 100, 2, 0xffff, 0x05002f);
      LCD_Print(text2 + points, 20, 50, 2, 0xffff, 0x05002f);
 
    
 
 //   */
    //LCD_Bitmap(x, 100, 32, 32, prueba);
    /*
    
    LCD_Sprite(x, 20, 16, 32, mario,8, anim,1, 0);
    V_line( x -1, 20, 32, 0x421b);
 
    //LCD_Sprite(x,100,32,32,bowser,4,anim3,0,1);
    //V_line( x -1, 100, 32, 0x421b);
 
 
    LCD_Sprite(x, 140, 16, 16, enemy,2, anim2,1, 0);
    V_line( x -1, 140, 16, 0x421b);
  
    LCD_Sprite(x, 175, 16, 32, luigi,8, anim,1, 0);
    V_line( x -1, 175, 32, 0x421b);
  }
  for(int x = 320-32; x >0; x--){
    delay(5);
    int anim = (x/11)%8;
    int anim2 = (x/11)%2;
    
    LCD_Sprite(x,100,16,24,planta,2,anim2,0,0);
    V_line( x + 16, 100, 24, 0x421b);
    
    //LCD_Bitmap(x, 100, 32, 32, prueba);
    
    //LCD_Sprite(x, 140, 16, 16, enemy,2, anim2,0, 0);
    //V_line( x + 16, 140, 16, 0x421b);
    
    //LCD_Sprite(x, 175, 16, 32, luigi,8, anim,0, 0);
    //V_line( x + 16, 175, 32, 0x421b);

    //LCD_Sprite(x, 20, 16, 32, mario,8, anim,0, 0);
    //V_line( x + 16, 20, 32, 0x421b);
  } 
*/
}
//***************************************************************************************************************************************
// Función para inicializar LCD
//***************************************************************************************************************************************
void LCD_Init(void) {
  pinMode(LCD_RST, OUTPUT);
  pinMode(LCD_CS, OUTPUT);
  pinMode(LCD_RS, OUTPUT);
  pinMode(LCD_WR, OUTPUT);
  pinMode(LCD_RD, OUTPUT);
  for (uint8_t i = 0; i < 8; i++){
    pinMode(DPINS[i], OUTPUT);
  }
  
  //****************************************
  // Secuencia de Inicialización
  //****************************************
  digitalWrite(LCD_CS, HIGH);
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_WR, HIGH);
  digitalWrite(LCD_RD, HIGH);
  digitalWrite(LCD_RST, HIGH);
  delay(5);
  digitalWrite(LCD_RST, LOW);
  delay(20);
  digitalWrite(LCD_RST, HIGH);
  delay(150);
  digitalWrite(LCD_CS, LOW);
  //****************************************
  LCD_CMD(0xE9);  // SETPANELRELATED
  LCD_DATA(0x20);
  //****************************************
  LCD_CMD(0x11); // Exit Sleep SLEEP OUT (SLPOUT)
  delay(100);
  //****************************************
  LCD_CMD(0xD1);    // (SETVCOM)
  LCD_DATA(0x00);
  LCD_DATA(0x71);
  LCD_DATA(0x19);
  //****************************************
  LCD_CMD(0xD0);   // (SETPOWER) 
  LCD_DATA(0x07);
  LCD_DATA(0x01);
  LCD_DATA(0x08);
  //****************************************
  LCD_CMD(0x36);  // (MEMORYACCESS)
  LCD_DATA(0x40|0x80|0x20|0x08); // LCD_DATA(0x19);
  //****************************************
  LCD_CMD(0x3A); // Set_pixel_format (PIXELFORMAT)
  LCD_DATA(0x05); // color setings, 05h - 16bit pixel, 11h - 3bit pixel
  //****************************************
  LCD_CMD(0xC1);    // (POWERCONTROL2)
  LCD_DATA(0x10);
  LCD_DATA(0x10);
  LCD_DATA(0x02);
  LCD_DATA(0x02);
  //****************************************
  LCD_CMD(0xC0); // Set Default Gamma (POWERCONTROL1)
  LCD_DATA(0x00);
  LCD_DATA(0x35);
  LCD_DATA(0x00);
  LCD_DATA(0x00);
  LCD_DATA(0x01);
  LCD_DATA(0x02);
  //****************************************
  LCD_CMD(0xC5); // Set Frame Rate (VCOMCONTROL1)
  LCD_DATA(0x04); // 72Hz
  //****************************************
  LCD_CMD(0xD2); // Power Settings  (SETPWRNORMAL)
  LCD_DATA(0x01);
  LCD_DATA(0x44);
  //****************************************
  LCD_CMD(0xC8); //Set Gamma  (GAMMASET)
  LCD_DATA(0x04);
  LCD_DATA(0x67);
  LCD_DATA(0x35);
  LCD_DATA(0x04);
  LCD_DATA(0x08);
  LCD_DATA(0x06);
  LCD_DATA(0x24);
  LCD_DATA(0x01);
  LCD_DATA(0x37);
  LCD_DATA(0x40);
  LCD_DATA(0x03);
  LCD_DATA(0x10);
  LCD_DATA(0x08);
  LCD_DATA(0x80);
  LCD_DATA(0x00);
  //****************************************
  LCD_CMD(0x2A); // Set_column_address 320px (CASET)
  LCD_DATA(0x00);
  LCD_DATA(0x00);
  LCD_DATA(0x01);
  LCD_DATA(0x3F);
  //****************************************
  LCD_CMD(0x2B); // Set_page_address 480px (PASET)
  LCD_DATA(0x00);
  LCD_DATA(0x00);
  LCD_DATA(0x01);
  LCD_DATA(0xE0);
//  LCD_DATA(0x8F);
  LCD_CMD(0x29); //display on 
  LCD_CMD(0x2C); //display on

  LCD_CMD(ILI9341_INVOFF); //Invert Off
  delay(120);
  LCD_CMD(ILI9341_SLPOUT);    //Exit Sleep
  delay(120);
  LCD_CMD(ILI9341_DISPON);    //Display on
  digitalWrite(LCD_CS, HIGH);
}
//***************************************************************************************************************************************
// Función lcd 5408(comando)
//***************************************************************************************************************************************
void LCD_5408(uint8_t cmd) {
  digitalWrite(LCD_RS, LOW);
  digitalWrite(LCD_WR, LOW);
  GPIO_PORTB_DATA_R = cmd;
  digitalWrite(LCD_WR, HIGH);
}
//***************************************************************************************************************************************
// Función para enviar comandos a la LCD - parámetro (comando)
//***************************************************************************************************************************************
void LCD_CMD(uint8_t cmd) {
  digitalWrite(LCD_RS, LOW);
  digitalWrite(LCD_WR, LOW);
  GPIO_PORTB_DATA_R = cmd;
  digitalWrite(LCD_WR, HIGH);
}
//***************************************************************************************************************************************
// Función para enviar datos a la LCD - parámetro (dato)
//***************************************************************************************************************************************
void LCD_DATA(uint8_t data) {
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_WR, LOW);
  GPIO_PORTB_DATA_R = data;
  digitalWrite(LCD_WR, HIGH);
}
//***************************************************************************************************************************************
// Función para definir rango de direcciones de memoria con las cuales se trabajara (se define una ventana)
//***************************************************************************************************************************************
void SetWindows(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) {
  LCD_CMD(0x2a); // Set_column_address 4 parameters
  LCD_DATA(x1 >> 8);
  LCD_DATA(x1);   
  LCD_DATA(x2 >> 8);
  LCD_DATA(x2);   
  LCD_CMD(0x2b); // Set_page_address 4 parameters
  LCD_DATA(y1 >> 8);
  LCD_DATA(y1);   
  LCD_DATA(y2 >> 8);
  LCD_DATA(y2);   
  LCD_CMD(0x2c); // Write_memory_start
}
//***************************************************************************************************************************************
// Función para borrar la pantalla - parámetros (color)
//***************************************************************************************************************************************
void LCD_Clear(unsigned int c){  
  unsigned int x, y;
  LCD_CMD(0x02c); // write_memory_start
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_CS, LOW);   
  SetWindows(0, 0, 319, 239); // 479, 319);
  for (x = 0; x < 320; x++)
    for (y = 0; y < 240; y++) {
      LCD_DATA(c >> 8); 
      LCD_DATA(c); 
    }
  digitalWrite(LCD_CS, HIGH);
} 
//***************************************************************************************************************************************
// Función para dibujar una línea horizontal - parámetros ( coordenada x, cordenada y, longitud, color)
//*************************************************************************************************************************************** 
void H_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c) {  
  unsigned int i, j;
  LCD_CMD(0x02c); //write_memory_start
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_CS, LOW);
  l = l + x;
  SetWindows(x, y, l, y);
  j = l;// * 2;
  for (i = 0; i < l; i++) {
      LCD_DATA(c >> 8); 
      LCD_DATA(c); 
  }
  digitalWrite(LCD_CS, HIGH);
}
//***************************************************************************************************************************************
// Función para dibujar una línea vertical - parámetros ( coordenada x, cordenada y, longitud, color)
//*************************************************************************************************************************************** 
void V_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c) {  
  unsigned int i,j;
  LCD_CMD(0x02c); //write_memory_start
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_CS, LOW);
  l = l + y;
  SetWindows(x, y, x, l);
  j = l; //* 2;
  for (i = 1; i <= j; i++) {
    LCD_DATA(c >> 8); 
    LCD_DATA(c);
  }
  digitalWrite(LCD_CS, HIGH);  
}
//***************************************************************************************************************************************
// Función para dibujar un rectángulo - parámetros ( coordenada x, cordenada y, ancho, alto, color)
//***************************************************************************************************************************************
void Rect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c) {
  H_line(x  , y  , w, c);
  H_line(x  , y+h, w, c);
  V_line(x  , y  , h, c);
  V_line(x+w, y  , h, c);
}
//***************************************************************************************************************************************
// Función para dibujar un rectángulo relleno - parámetros ( coordenada x, cordenada y, ancho, alto, color)
//***************************************************************************************************************************************
/*void FillRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c) {
  unsigned int i;
  for (i = 0; i < h; i++) {
    H_line(x  , y  , w, c);
    H_line(x  , y+i, w, c);
  }
}
*/

void FillRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c) {
  LCD_CMD(0x02c); // write_memory_start
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_CS, LOW); 
  
  unsigned int x2, y2;
  x2 = x+w;
  y2 = y+h;
  SetWindows(x, y, x2-1, y2-1);
  unsigned int k = w*h*2-1;
  unsigned int i, j;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      LCD_DATA(c >> 8);
      LCD_DATA(c);
      
      //LCD_DATA(bitmap[k]);    
      k = k - 2;
     } 
  }
  digitalWrite(LCD_CS, HIGH);
}
//***************************************************************************************************************************************
// Función para dibujar texto - parámetros ( texto, coordenada x, cordenada y, color, background) 
//***************************************************************************************************************************************
void LCD_Print(String text, int x, int y, int fontSize, int color, int background) {
  int fontXSize ;
  int fontYSize ;
  
  if(fontSize == 1){
    fontXSize = fontXSizeSmal ;
    fontYSize = fontYSizeSmal ;
  }
  if(fontSize == 2){
    fontXSize = fontXSizeBig ;
    fontYSize = fontYSizeBig ;
  }
  
  char charInput ;
  int cLength = text.length();
  Serial.println(cLength,DEC);
  int charDec ;
  int c ;
  int charHex ;
  char char_array[cLength+1];
  text.toCharArray(char_array, cLength+1) ;
  for (int i = 0; i < cLength ; i++) {
    charInput = char_array[i];
    Serial.println(char_array[i]);
    charDec = int(charInput);
    digitalWrite(LCD_CS, LOW);
    SetWindows(x + (i * fontXSize), y, x + (i * fontXSize) + fontXSize - 1, y + fontYSize );
    long charHex1 ;
    for ( int n = 0 ; n < fontYSize ; n++ ) {
      if (fontSize == 1){
        charHex1 = pgm_read_word_near(smallFont + ((charDec - 32) * fontYSize) + n);
      }
      if (fontSize == 2){
        charHex1 = pgm_read_word_near(bigFont + ((charDec - 32) * fontYSize) + n);
      }
      for (int t = 1; t < fontXSize + 1 ; t++) {
        if (( charHex1 & (1 << (fontXSize - t))) > 0 ) {
          c = color ;
        } else {
          c = background ;
        }
        LCD_DATA(c >> 8);
        LCD_DATA(c);
      }
    }
    digitalWrite(LCD_CS, HIGH);
  }
}
//***************************************************************************************************************************************
// Función para dibujar una imagen a partir de un arreglo de colores (Bitmap) Formato (Color 16bit R 5bits G 6bits B 5bits)
//***************************************************************************************************************************************
void LCD_Bitmap(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned char bitmap[]){  
  LCD_CMD(0x02c); // write_memory_start
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_CS, LOW); 
  
  unsigned int x2, y2;
  x2 = x+width;
  y2 = y+height;
  SetWindows(x, y, x2-1, y2-1);
  unsigned int k = 0;
  unsigned int i, j;

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      LCD_DATA(bitmap[k]);
      LCD_DATA(bitmap[k+1]);
      //LCD_DATA(bitmap[k]);    
      k = k + 2;
     } 
  }
  digitalWrite(LCD_CS, HIGH);
}
//***************************************************************************************************************************************
// Función para dibujar una imagen sprite - los parámetros columns = número de imagenes en el sprite, index = cual desplegar, flip = darle vuelta
//***************************************************************************************************************************************
void LCD_Sprite(int x, int y, int width, int height, unsigned char bitmap[],int columns, int index, char flip, char offset){
  LCD_CMD(0x02c); // write_memory_start
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_CS, LOW); 

  unsigned int x2, y2;
  x2 =   x+width;
  y2=    y+height;
  SetWindows(x, y, x2-1, y2-1);
  int k = 0;
  int ancho = ((width*columns));
  if(flip){
  for (int j = 0; j < height; j++){
      k = (j*(ancho) + index*width -1 - offset)*2;
      k = k+width*2;
     for (int i = 0; i < width; i++){
      LCD_DATA(bitmap[k]);
      LCD_DATA(bitmap[k+1]);
      k = k - 2;
     } 
  }
  }else{
     for (int j = 0; j < height; j++){
      k = (j*(ancho) + index*width + 1 + offset)*2;
     for (int i = 0; i < width; i++){
      LCD_DATA(bitmap[k]);
      LCD_DATA(bitmap[k+1]);
      k = k + 2;
     } 
  }
    
    
    }
  digitalWrite(LCD_CS, HIGH);
}
