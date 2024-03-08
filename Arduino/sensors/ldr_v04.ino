/*
LDR deger okuma ve isik siddetine gore karar verme
*/

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  cikis_Pini_Belirle(13);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldr_degeri = analogRead(A0);
  Serial.println(ldr_degeri);
  delay(10);
  if (ldr_degeri > 500) {led_Yak(13);}
  else {led_Sondur(13);}
}

void cikis_Pini_Belirle(int pin_numarasi) {
  pinMode(pin_numarasi,OUTPUT);
}

void led_Yak(int pin_numarasi){
digitalWrite(pin_numarasi,HIGH);
}

void led_Sondur(int pin_numarasi){
digitalWrite(pin_numarasi,LOW);
}
