#define IR_USE_AVR_TIMER2
#include <Servo.h>
Servo myservo;
// #define IR_USE_AVR_TIMER1

#include <IRremote.hpp>
#include <AFMotor.h>
#define IR_RECEIVE_PIN 21

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int speedR = 90;
int speedLeft = speedR - 10;

int speedL = 100;
int speedH = 150;
void bukaServo(){
  myservo.write(100);
}

void tutupServo(){
  myservo.write(180); 
}

void mundur()
{
  motor1.setSpeed(speedLeft);
  motor2.setSpeed(speedR);
  motor3.setSpeed(speedR);
  motor4.setSpeed(speedLeft);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void maju()
{
  motor1.setSpeed(speedLeft);
  motor2.setSpeed(speedR);
  motor3.setSpeed(speedR);
  motor4.setSpeed(speedLeft);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void berhenti()
{
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void kanan90(){
  motor1.setSpeed(speedLeft);
  motor2.setSpeed(speedR);
  motor3.setSpeed(speedR);
  motor4.setSpeed(speedLeft);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void kiri90(){
  motor1.setSpeed(speedLeft);
  motor2.setSpeed(speedR);
  motor3.setSpeed(speedR);
  motor4.setSpeed(speedLeft);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}
void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  myservo.attach(10); // di pin servo2
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()){
    int command = IrReceiver.decodedIRData.command;
    Serial.println(IrReceiver.decodedIRData.command);
    switch(IrReceiver.decodedIRData.command){
      case 82: // kode remote bawah
        Serial.println("Maju");
        mundur();
        break;
      case 28: // kode remote tengah
        Serial.println("berhenti");
        berhenti();
        break;
      case 24: // kode remote atas
        Serial.println("Mundur");
        maju();
        break;
      case 8: // kode remote kiri
        Serial.println("Kiri");
        putarKiri();
        break;
      case 90: // kode remote kanan
        Serial.println("K");
        putarKanan();
        break;
      case 70: // tombol no 2
        Serial.println("Maju With Delay");
        mundur();
        delay(100);
        berhenti();
        break;
      case 68: // kode remote nomor 4
        Serial.println("Kiri With Delay");
        putarKiri();
        delay(100);
        berhenti();
        break;
      case 67: // kode remote nomor 6
        Serial.println("Kanan With Delay");
        putarKanan();
        delay(100);
        berhenti();
        break;
      case 21: // kode remote nomor 8
        Serial.println("Mundur With Delay");
        maju();
        delay(150);
        berhenti();
        break;
      case 13:  // kode remote pagar
        Serial.println("Buka Servo");
        bukaServo();
        break;
      case 22: // kode remote bintang
        Serial.println("Tutup Servo");
        tutupServo();
        break;
      case 71: // tombol 3
        Serial.println("Kanan 90 Derajat");
        kanan90();
        delay(550);
        berhenti();
        break;
      case 69: // kode remote nomor 1
        Serial.println("Kiri 90 Derajat");
        kiri90();
        delay(550);
        berhenti();
        break;
    }
    IrReceiver.resume();
  }
}

/*
1 = 69
2 = 70
3 = 71
4 = 68
5 = 64
6 = 67
7 = 7
8 = 21
9 = 9
0 = 25
* = 22 tutup servo
# = 13 buka servo
atas = 24
Bawah = 82
kiri = 8
kanan = 90
tengah = 28
*/

void kanan()
{
  motor1.setSpeed(speedH);
  motor1.run(FORWARD);
  motor2.setSpeed(speedH);
  motor2.run(BACKWARD);
  motor3.setSpeed(speedH);
  motor3.run(FORWARD);
  motor4.setSpeed(speedH);
  motor4.run(BACKWARD);
}

void kiri()
{
  motor1.setSpeed(speedH);
  motor1.run(BACKWARD);
  motor2.setSpeed(speedH);
  motor2.run(FORWARD);
  motor3.setSpeed(speedH);
  motor3.run(BACKWARD);
  motor4.setSpeed(speedH);
  motor4.run(FORWARD);
}
void majuKanan()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(speedH);
  motor2.run(FORWARD);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(speedH);
  motor4.run(FORWARD);
}
void majuKiri()
{
  motor1.setSpeed(speedH);
  motor1.run(FORWARD);
  motor2.setSpeed(0);
  motor2.run(FORWARD);
  motor3.setSpeed(speedH);
  motor3.run(FORWARD);
  motor4.setSpeed(0);
  motor4.run(BACKWARD);
}
void mundurKanan()
{
  motor1.setSpeed(speedH);
  motor1.run(BACKWARD);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(speedH);
  motor3.run(BACKWARD);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
void mundurKiri()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(speedH);
  motor2.run(BACKWARD);
  motor3.setSpeed(0);
  motor3.run(BACKWARD);
  motor4.setSpeed(speedH);
  motor4.run(BACKWARD);
}
void putarKanan()
{
  motor1.setSpeed(speedLeft);
  motor2.setSpeed(speedR);
  motor3.setSpeed(speedR);
  motor4.setSpeed(speedLeft);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}
void putarKiri()
{
  motor1.setSpeed(speedLeft);
  motor2.setSpeed(speedR);
  motor3.setSpeed(speedR);
  motor4.setSpeed(speedLeft);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}