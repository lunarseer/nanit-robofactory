#include <Arduino.h>
#include <NanitLib.h>

#define PIR_PIN P5_1


int counter = 0;

bool motion_flag = false;
bool status_red_led = false;
bool status_green_led = false;
int red_blink_count = 20;

unsigned long red_blink_last_time = 0;
unsigned long red_blink_interval = 200;

unsigned long green_blink_last_time = 0;
unsigned long green_blink_interval = 1000; // green blink interval

void detectMotion() {
  motion_flag = true;
  counter++;
  Serial.print("Motion Detected: ");
  Serial.println(counter);
}

void setup() {
  Serial.begin(9600);
  Nanit_Base_Start();
  pinMode(PIR_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), detectMotion, RISING);
}

void loop() {
  if (motion_flag){
    if (millis() - red_blink_last_time > red_blink_interval){
      red_blink_last_time = millis();
      status_red_led = !status_red_led;
      if(status_red_led) {
        GET_NANIT.BuildinRGB(255, 0, 0);
      } else {
        GET_NANIT.BuildinRGB(0, 255, 0);
      }
      red_blink_count--;
      if (red_blink_count == 0){
        motion_flag = false;
        red_blink_count = 20;
      }
    }
  } else {
    if (millis() - green_blink_last_time > green_blink_interval){
      green_blink_last_time = millis();
      status_green_led = !status_green_led;
      if (status_green_led){ 
        GET_NANIT.BuildinRGB(0, 255, 0); 
      }else{ 
        GET_NANIT.BuildinRGB(0, 0, 0); 
      } 
    }
  }
}
