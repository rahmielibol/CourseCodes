int Buton = 7;
int Led = 13;



/*
Alternatif olarak kullanilabilir.
#define Buton 7
#define Led 13
  */



int okunan_deger = 0;

void setup() {
  pinMode(Led, OUTPUT);  // sets the digital pin 13 as output
  pinMode(Buton, INPUT);    // sets the digital pin 7 as input
}

void loop() {
  okunan_deger = digitalRead(Buton);
  digitalWrite(Led, okunan_deger);  
 delay(10);
}
