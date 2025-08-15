#define IR_USE_AVR_TIMER1

//#include <Servo.h>
#include <IRremote.hpp>
#include <AFMotor.h>
#define IR_RECEIVE_PIN 3

//Servo servoL; // 150 MANGAP
//Servo servoR;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int kodebintang = 22;
int kodepagar = 13;

void kanan() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void kiri() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void berhenti() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void maju() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void mundur() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}


void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);

  motor1.setSpeed(50);
  motor2.setSpeed(50);
  motor3.setSpeed(50);
  motor4.setSpeed(50);

  //  servoL.attach();
  //  servoR.attach();

  //  myservo.write(0);   // makin ditambah makin terbuka
  //  myservo2.write(90);
}

void loop() {
  if (IrReceiver.decode()) {
    uint16_t command = IrReceiver.decodedIRData.command;
    Serial.println(command);
    IrReceiver.resume();
    //    delay(50);
    if (command == 82) {
      Serial.println("Maju");
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      IrReceiver.resume();
    } else if (command == 28) {
      Serial.println("Berhenti");
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      IrReceiver.resume();
    } else if (command == 24) {
      Serial.println("Mundur");
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
      IrReceiver.resume();
    } else if (command == 90) { // KIRI
      Serial.println("Kiri");
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      motor3.run(FORWARD);
      motor4.run(BACKWARD);
      IrReceiver.resume();
    } else if (command == 8) {// KANAN
      Serial.println("Kanan");
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      motor3.run(BACKWARD);
      motor4.run(FORWARD);
      IrReceiver.resume();
    } else if (command == 13) { // tutup servo dengan kode remote pagar
      for (int i = 100; i > 50; i--) { // tutup ke 100 derajat
        servoL.write(i);
        delay(5);
      }
      for (int i = 20; i < 90; i--) { // tutup ke 20 derajat
        servoR.write(i);
        delay(5);
      }
    } else if (command == 22) { // buka servo dengan kode remot bintang
      for (int i = 50; i < 100; i++) { // buka ke 50 derajat
        servoL.write(i);
        delay(5);
      }
      for (int i = 90; i > 20; i++) { // buka ke 90 derajat
        servoR.write(i);
        delay(5);
      }
    }
  }
}
//
//  myservo.write(100);   // kanan makin ditambah makin tutup 100 -
//  myservo2.write(20); // kiri makin ditambah makin buka maks 90

//  myservo.write(50);   // kanan makin ditambah makin tutup 100 -
//  myservo2.write(90); // kiri makin ditambah makin buka maks 90
