#include <Arduino.h>
#include <NanitLib.h>


#define CO2_PIN_A P4_1
#define CO2_PIN_D P4_2

void setup() {
  Serial.begin(9600);
  Nanit_Base_Start();
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
  GET_NANIT.BuildinRGB(0, 0, 0);
}

void loop() {
  // int co2_d = digitalRead(CO2_PIN_D);
  int co2_a = analogRead(CO2_PIN_A);
  Serial.println(co2_a);
  tft.setCursor(30, 50);
  tft.print("CO2: ");
  tft.println(co2_a);
  delay(250);
}

// vcc +
// gnd -
// D P4_2
// A P4_1