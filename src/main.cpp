#include <Arduino.h> 
#include <NanitLib.h> 
 
#define RELAY_PIN P4_1 // Пін для реле (IN) 
 
 
void initDisplay(){ 
  tft.fillScreen(ST7735_BLACK); 
  tft.fillRoundRect(10, 10, 90, 90, 10, ST7735_BLUE); 
  tft.setTextColor(ST7735_WHITE, ST7735_BLUE);
  tft.setTextSize(1); 
} 
 
void drawText(String text, int x, int y){ 
  tft.setCursor(x, y); 
  tft.print(text); 
} 
 
 
void setup() { 
  Serial.begin(9600); 
  Nanit_Base_Start(); 
   
  initDisplay(); // ініціалізація дисплея черний фон з синім квадратом 
 
  pinMode(RELAY_PIN, OUTPUT); 
 
} 
 
void loop() { 
  // digitalWrite(RELAY_PIN, 1); 
  // drawText("Relay OFF ", 20, 20); 
  // delay(1000); 
  // digitalWrite(RELAY_PIN, 0); 
  // drawText("Relay ON ", 20, 20); 
  // delay(1000);
  for (int i = 0; i < 255; i++){ 
    analogWrite(RELAY_PIN, i); 
    delay(10); 
  }
}