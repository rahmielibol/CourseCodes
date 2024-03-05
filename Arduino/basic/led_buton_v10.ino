const int bekleme_zamani=500;
#define Buton 8
#define LED 2

void setup() {
  // put your setup code here, to run once:
  pinMode(Buton, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(Buton) == 1) 
  {
  digitalWrite(LED, HIGH);
  delay(bekleme_zamani);   //bekleme zamani eklenebilir...
  }
  else
  digitalWrite(LED, LOW);
   

}
