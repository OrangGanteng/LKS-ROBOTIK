int motor1 = 3;
int motor2 = 4;
int motor3 = 5;
int motor4 = 6;

void setup(){
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
}

void loop(){
  for(int i = 0; i <= 2; i++){
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
    delay(1000);
  }
  for(int i = 2; i >= 0; i--){
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
    delay(1000);
}
