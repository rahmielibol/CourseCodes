const int bekleme_zamani=500;

void setup() {
  // put your setup code here, to run once:
  for (int i=2; i<7; i++){
  pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=2; i<7; i++){
  digitalWrite(i, HIGH);
  delay(bekleme_zamani);
  digitalWrite(i, LOW);
}
  for (int i=2; i<7; i++){
  digitalWrite(8-i, HIGH);
  delay(bekleme_zamani);
  digitalWrite(8-i, LOW);
}

}
