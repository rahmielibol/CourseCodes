#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 
char bellek_sifre = 5;
int incomingByte = 0; // for incoming serial data

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}
  
void loop(){
  digitalWrite(13,0);
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }

  char customKey = customKeypad.getKey();
  if (customKey == 50) {
    Serial.println(customKey);
    digitalWrite(13,1);
    delay(300);
  }
  else {
  digitalWrite(13,0);
  }
}
