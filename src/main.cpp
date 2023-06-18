#include <Arduino.h>
#include <NanitLib.h>
#include <DHT.h>

#define DHTPIN P6_1 
#define DHTTYPE DHT11


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Nanit_Base_Start();

  dht.begin();

  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
  tft.setTextSize(1);
}

void drawText(String text, int x, int y, int color) {
  tft.setCursor(x, y);
  tft.setTextColor(ST7735_GREEN, ST7735_BLACK);
  tft.print(text);
}

void loop() {
  int t = dht.readTemperature();
  int h = dht.readHumidity();
  Serial.print("Temperature: "); 
  Serial.print(t); 
  Serial.print("C"); 
  Serial.print(" Humidity: "); 
  Serial.print(h); 
  Serial.println("%");

  int color = ST7735_WHITE;
  if (t < 10) {
    color = ST7735_BLUE;
  } else if (t < 20 ) {
    color = ST7735_CYAN;
  } else if (t < 30) {
    color = ST7735_GREEN;
  } else if (t < 40) {
    color = ST7735_YELLOW;
  }
  drawText("Temperature: ", 20, 50, color);
  drawText(String(t), tft.getCursorX(), tft.getCursorY(), color);
  drawText("C   ", tft.getCursorX(), tft.getCursorY(), color);

  drawText("Humidity: ", 20, 67, color);
  drawText(String(h), tft.getCursorX(), tft.getCursorY(), color);
  drawText("%   ", tft.getCursorX(), tft.getCursorY(), color);

  delay(1000);
}
