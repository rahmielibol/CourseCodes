int buton_pini = 2;

void setup() {

  Serial.begin(9600);
  pinMode(buton_pini, INPUT);
}


void loop() {

  int buton_durumu = digitalRead(buton_pini);

  Serial.println(buton_durumu);
  delay(1);  
}
