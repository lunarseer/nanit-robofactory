#include <Arduino.h>
#include <NanitLib.h>

#define MIC_APIN P4_1
#define MIC_DPIN P4_2

void setup() {
  Serial.begin(9600);
  Nanit_Base_Start();
  pinMode(MIC_APIN, INPUT);
  pinMode(MIC_DPIN, INPUT);
}

void loop() {
  int dval = digitalRead(MIC_DPIN);
  int aval = analogRead(MIC_APIN);
  Serial.print("Analog: ");
  Serial.print(aval);
  Serial.print(" ");
  if (aval > 520) {
    GET_NANIT.BuildinRGB(255, 0, 0);
    Serial.println("Sound detected"); 
    delay(1000);
    GET_NANIT.BuildinRGB(0, 0, 0);
  } else {
    Serial.println("No sound");  
  }
}
