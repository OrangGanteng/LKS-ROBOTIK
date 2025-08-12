#include <AFMotor.h>
#include <IRremote.hpp>
#define IR_RECEIVE_PIN 9

AF_DCMotor motor1(3);
AF_DCMotor motor2(4);
AF_DCMotor motor3(5);
AF_DCMotor motor4(6);

int kode_maju = ;
int kode_mundur = ;
int kode_kiri = ;
int kode_kanan = ;

void maju(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void mundur(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void kanan(){
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void kiri(){
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void berhenti(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void setup(){
  IrReceiver.begin(IR_RECEIVE_PIN);
  
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
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
