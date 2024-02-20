void setup() {
 
Serial.begin(9600);
pinMode(13, OUTPUT);
}

void loop() {
 
for (int i = 1; i < 10; i++) {
    digitalWrite(13,HIGH);
    delay(i*100);
    digitalWrite(13, LOW);
    delay(i*100);
    Serial.println(i);
  }
  delay(1000);
Serial.println("_________");
delay(1000);
}
