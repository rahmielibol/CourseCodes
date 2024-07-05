 

#include <SoftwareSerial.h>         // Yazılımsal Seri Port kütüphanesi
 
const int RX = 4;                         // Yazılımsal Seri Port'un RX pini
const int TX = 5;                         // Yazılımsal Seri Port'un TX pini
                  // Arduino'nun dahili LED'i
 
SoftwareSerial bluetooth(RX,TX);    // Kütüphanemizi ayarlıyoruz
 
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);             
  bluetooth.begin(9600);           

  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);

}
 
void loop() {
  if (bluetooth.available()) {      
    char veri = bluetooth.read();   
    if (veri == '0') {             
      digitalWrite(9, LOW);
      digitalWrite(11, LOW);      
    }
    else if (veri == '1') {             
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);      
    }
    else if (veri == '2') {              
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);      
    }
    else if (veri == '3') {            
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);      
    }

  }
  
}
