#include <AFMotor.h>

AF_DCMotor motor1(3);
AF_DCMotor motor2(4);
AF_DCMotor motor3(5);
AF_DCMotor motor4(6);

void setup(){
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
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
