#include <Arduino.h>
#include <NanitLib.h>
#include <NewPing.h>
#include <GyverTM1637.h>


#define CLK P9_1
#define DIO P9_2
#define TRIG_PIN P4_1
#define ECHO_PIN P4_2

GyverTM1637 tm(CLK, DIO);

NewPing sonar(TRIG_PIN, ECHO_PIN);

void setup() {
  Serial.begin(9600);
  tm.clear();
  tm.brightness(4);
}

void loop() {
  int dist = sonar.ping_cm();
  tm.displayInt(dist);
  delay(50);
}
