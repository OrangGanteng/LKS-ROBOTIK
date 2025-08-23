
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
int speed = 200;
void mundur()
{
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void maju()
{
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}


void setup() {
  maju();
}

void loop() {
  // put your main code here, to run repeatedly:
 
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
