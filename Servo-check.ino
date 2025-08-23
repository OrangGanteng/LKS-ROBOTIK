
#include <Servo.h>
Servo myservo;
void bukaServo(){
  myservo.write(100);
}

void tutupServo(){
  myservo.write(180); 
}


void setup() {
  Serial.begin(9600);
  myservo.attach(10); // di pin servo2
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 100; i < 180; i++)
  {
    myservo.write(i);
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

