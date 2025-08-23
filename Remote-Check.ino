#define IR_USE_AVR_TIMER2

#include <IRremote.hpp>

#define IR_RECEIVE_PIN 21


void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()){
    int command = IrReceiver.decodedIRData.command;
    Serial.println(IrReceiver.decodedIRData.command);
    switch(IrReceiver.decodedIRData.command){
      case 82: // kode remote bawah
        Serial.println("Maju");
        break;
      case 28: // kode remote tengah
        Serial.println("berhenti");
        break;
      case 24: // kode remote atas
        Serial.println("Mundur");
        break;
      case 8: // kode remote kiri
        Serial.println("Kiri");
        break;
      case 90: // kode remote kanan
        Serial.println("K");
        break;
      case 70: // tombol no 2
        Serial.println("Maju With Delay");
        break;
      case 68: // kode remote nomor 4
        Serial.println("Kiri With Delay");
        
        break;
      case 67: // kode remote nomor 6
        Serial.println("Kanan With Delay");
        
        break;
      case 21: // kode remote nomor 8
        Serial.println("Mundur With Delay");
        
        break;
      case 13:  // kode remote pagar
        Serial.println("Buka Servo");
        
        break;
      case 22: // kode remote bintang
        Serial.println("Tutup Servo");
        
        break;
      case 71: // tombol 3
        Serial.println("Kanan 90 Derajat");
        
        break;
      case 69: // kode remote nomor 1
        Serial.println("Kiri 90 Derajat");
        
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

