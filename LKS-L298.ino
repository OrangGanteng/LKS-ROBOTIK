#include <IRremote.hpp>
#define IR_RECEIVE_PIN 9

int motor1 = 3;
int motor2 = 4;
int motor3 = 5;
int motor4 = 6;

int kode_maju = ;
int kode_mundur = ;
int kode_kiri = ;
int kode_kanan = ;

void maju(){
 digitalWrite(motor1, HIGH);
 digitalWrite(motor2, LOW);
 digitalWrite(motor3, HIGH);
 digitalWrite(motor4, LOW);
}

void mundur(){
 digitalWrite(motor1, LOW);
 digitalWrite(motor2, HIGH);
 digitalWrite(motor3, LOW);
 digitalWrite(motor4, HIGH);
}

void kanan(){

}

void kiri(){

}

void berhenti(){
 digitalWrite(motor1, LOW);
 digitalWrite(motor2, LOW);
 digitalWrite(motor3, LOW);
 digitalWrite(motor4, LOW);
}
void setup(){
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);

  IrReceiver.begin(IR_RECEIVE_PIN);

  Serial.begin(9600);
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
