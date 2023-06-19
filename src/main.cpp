#include <Arduino.h>
#include <NanitLib.h>
#include <NewPing.h>

#define TRIG_PIN P6_1
#define ECHO_PIN P6_4
#define LED_OK_PIN P5_1
#define LED_ALARM_PIN P5_4

#define MAX_DISTANCE 50
#define MIN_DISTANCE 2

long lastBlinkTime = 0;
bool stateLed = false;


void setup() {
  Serial.begin(9600);
  Nanit_Base_Start();
  GET_NANIT.BuildinRGB(0, 0, 0); 
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_OK_PIN, OUTPUT);
  pinMode(LED_ALARM_PIN, OUTPUT);
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
  tft.setTextSize(1);
}

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void blink(int blink_per_second, bool alarm) {
  int led_pin;
  if (alarm) {
    int led_pin = LED_ALARM_PIN;
  } else {
    int led_pin = LED_OK_PIN;
  }
  if (millis() - lastBlinkTime > 1000 / blink_per_second ) {
    lastBlinkTime = millis(); 
    if (stateLed) { 
      stateLed = false; 
      digitalWrite(LED_OK_PIN, LOW);
    }else { 
      stateLed = true; 
      digitalWrite(LED_OK_PIN, HIGH);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  bool alarm;
  long distance = sonar.ping_cm();
  int blink_per_second = map(distance, MIN_DISTANCE, MAX_DISTANCE, 50, 1);
  blink_per_second = constrain(blink_per_second, 1, 50);
  if (distance < (MAX_DISTANCE - MIN_DISTANCE) / 2) {
    alarm = true;
  } else {
    alarm = false;
  }
  if (distance < MIN_DISTANCE) {
    blink_per_second = 1;
  }

  tft.setCursor(30, 60);
  tft.print("Distance: ");
  tft.print(distance);
  tft.println(" cm   ");
  tft.print("blinks: ");
  tft.print(blink_per_second);
  tft.println("   ");
  blink(blink_per_second, alarm);
}
