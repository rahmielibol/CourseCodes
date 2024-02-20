
int Buton = 7;
int Led = 8;

/*
Alternatif olarak kullanilabilir.
#define Buton 8
#define Led 10
  */

int buton_durumu = 0;

void setup() {

  pinMode(Buton, INPUT);
  pinMode(Led, OUTPUT);


}

void loop() {

  buton_durumu = digitalRead(Buton);

  if(buton_durumu == 1) { 
  digitalWrite(Led,HIGH);
  //delay(1000)  //Butona basip bıraktiktan sonra bir süre daha yanmasi için zaman eklenebilir.
  }
  digitalWrite(Led,LOW);


}
