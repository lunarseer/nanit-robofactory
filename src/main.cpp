#include <Arduino.h> 
 
#define DATA_PIN 44 // P4_2 
#define CLOCK_PIN 45 // P4_3 
#define LATCH_PIN 46 // P4_4 
 
byte pattern[] = { 
  0b00000101, 
  0b00010010, 
  0b00100100, 
  0b01001000, 
  0b00010010, 
  0b00100010, 
  0b01001000, 
  0b10010000, 
  0b00100010, 
  0b01000100, 
  0b10001000, 
  0b00010010, 
  0b00100100, 
  0b01001000, 
  0b10010000, 
}; 
 
int patternSize = sizeof(pattern) / sizeof(byte); 
 
 
void setLeds(byte leds) { 
  digitalWrite(LATCH_PIN, LOW); 
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, leds); 
  digitalWrite(LATCH_PIN, HIGH); 
} 
 
 
void setup() { 
  pinMode(DATA_PIN, OUTPUT); 
  pinMode(CLOCK_PIN, OUTPUT); 
  pinMode(LATCH_PIN, OUTPUT); 
  randomSeed(analogRead(0)); 
} 
 
void loop() { 
 
    for(int i = 0; i < patternSize; i++) { 
      setLeds(pattern[i]); 
      delay(100); 
    } 
  
}