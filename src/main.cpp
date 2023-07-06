#include <Arduino.h> 
#include <NanitLib.h> 
#include <Stepper.h> 
 
Stepper stepper(200, P4_1, P4_3, P4_2, P4_4); 
 
int angle = 0; 
 
void screenBegin(){ 
  tft.fillScreen(ST7735_BLACK);
  tft.fillRoundRect(10,10,100,100,10,ST7735_BLUE);
  tft.setTextColor(ST7735_WHITE, ST7735_BLUE);
  tft.setCursor(20, 20);
  tft.setTextSize(2);
  tft.print("Angle: ");
  tft.setTextSize(3);
} 
 
 
void printAngle(int angle) { 
  tft.setCursor(20, 60); 
  tft.print(angle); 
  tft.print("  "); 
} 
 
 
void setup() { 
  Nanit_Base_Start(); 
  screenBegin(); 
  stepper.setSpeed(80); 
} 
 
void loop() { 
  for (int a = 0; a < 360; a++) {  
    angle = map(a, 0, 360, 0, 2048);
    stepper.step(angle);
    printAngle(a); 
  } 
  for (int a = 360; a> 0; a--) { 
    angle = map(a, 0, 360, 0, 2048);
    stepper.step(angle); 
    printAngle(a); 
  } 
}