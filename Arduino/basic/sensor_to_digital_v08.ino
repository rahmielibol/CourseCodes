
const int ust_esik = 800;
const int alt_esik = 400;  


void setup() {

  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}


void loop() {

  int olcum_Degeri = analogRead(A0);

  Serial.println(olcum_Degeri);
  delay(1);  

 if (olcum_Degeri > ust_esik) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    Serial.println("Yüksek değer");
  } 
  else if (olcum_Degeri < alt_esik) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    Serial.println("Düşük değer");
  }
  else {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    Serial.println("Normal değer");
  }

}
