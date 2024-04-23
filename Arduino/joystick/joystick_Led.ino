

int x = A1;     // VRx pini
int y = A2;     // VRy pini
int buton = 3; // SW buton pini

 
void setup() {
  pinMode(buton, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(buton),interrupt_Fonk,LOW);
}
 
void loop() {
  Serial.print("Buton : ");
  Serial.println(digitalRead(buton));  

  
  Serial.print("X : ");
  Serial.print(analogRead(x));
  
  Serial.print("  ---  Y : ");   
  Serial.println(analogRead(y));
  
  delay(200);


if (analogRead(x) > 600) {
  led_Yak(9);
  led_Son(10);
}
else if (analogRead(x) < 500) {
  led_Yak(10);
  led_Son(9);
}
else {
  led_Son(9);
  led_Son(10);
  }

if (analogRead(y) > 600) {
  led_Yak(11);
  led_Son(8);
}
else if (analogRead(y) < 500) {
  led_Yak(8);
  led_Son(11);
}
else {
  led_Son(8);
  led_Son(11);
  }
}



void led_Yak(int pinNumarasi) {
    digitalWrite(pinNumarasi,1);
}
void led_Son(int pin_Numarasi) {
  digitalWrite(pin_Numarasi,0);
}

void interrupt_Fonk() {
  led_Yak(8);
  led_Yak(9);
  led_Yak(10);
  led_Yak(11);
}
