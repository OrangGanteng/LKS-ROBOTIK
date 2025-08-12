/// Using Library Adafruit Motorshield V2
#include <IRremote.hpp>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#define IR_RECEIVE_PIN 10

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor motor1 = AFMS.getMotor(1);
Adafruit_DCMotor motor2 = AFMS.getMotor(2);
Adafruit_DCMotor motor3 = AFMS.getMotor(3);
Adafruit_DCMotor motor4 = AFMS.getMotor(4);

int kode_maju = ;
int kode_mundur = ;
int kode_kiri = ;
int kode_kanan = ;

void maju(){
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  motor3->run(FORWARD);
  motor4->run(FORWARD);
}

void mundur(){
  motor1->run(BACKWARD);
  motor2->run(BACKWARD);
  motor3->run(BACKWARD);
  motor4->run(BACKWARD);
}

void kanan(){
  motor1->run(BACKWARD);
  motor2->run(FORWARD);
  motor3->run(BACKWARD);
  motor4->run(FORWARD);
}

void kiri(){
  motor1->run(FORWARD);
  motor2->run(BACKWARD);
  motor3->run(FORWARD);
  motor4->run(BACKWARD);
}

void berhenti(){
  motor1->run(RELEASE);
  motor2->run(RELEASE);
  motor3->run(RELEASE);
  motor4->run(RELEASE);
}
void setup(){
  AFMS.begin();

  motor1->setSpeed(150);
  motor2->setSpeed(150);
  motor3->setSpeed(150);
  motor4->setSpeed(150);

  IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop(){
  if (IrReceiver.decode()) {
    uint16_t command = IrReceiver.decodedIRData.command;
    Serial.println(command);
    delay(100);  // wait a bit
    switch (IrReceiver.decodedIRData.command){
      case kode_maju:
        maju();
        break;
      case kode_mundur:
        mundur();
        break;
      case kode_kiri:
        kiri();
        break;
      case kode_kanan:
        kanan();
        break;
      default:
        berhenti();
    }
    IrReceiver.resume();
}
