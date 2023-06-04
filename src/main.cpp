#include <Arduino.h>
#include <NanitLib.h>
#include <Servo.h>

#define SERVO_PIN P7_4
#define POT_PIN P7_1

Servo s1;

int pot_angle() {
  int pot_val = analogRead(POT_PIN);
  return map(pot_val, 0, 1023, 0, 180);
}

void setup() {
  Serial.begin(9600);
  Nanit_Base_Start();
  // GET_NANIT.DrawBattGuage();

  pinMode(POT_PIN, INPUT);
  s1.attach(SERVO_PIN);
  s1.write(pot_angle());
  delay(1000);
}

void loop() {
  int angle = pot_angle();
  Serial.println(angle);
  s1.write(angle);
  delay(20);
}
