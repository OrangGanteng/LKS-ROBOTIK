/// Using Library Adafruit Motorshield V2

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor motor1 = AFMS.getMotor(1);
Adafruit_DCMotor motor2 = AFMS.getMotor(2);
Adafruit_DCMotor motor3 = AFMS.getMotor(3);
Adafruit_DCMotor motor4 = AFMS.getMotor(4);

void setup(){
  AFMS.begin();

  motor1->setSpeed(150);
  motor2->setSpeed(150);
  motor3->setSpeed(150);
  motor4->setSpeed(150);

  
}

void loop(){
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  motor3->run(FORWARD);
  motor4->run(FORWARD);
}
