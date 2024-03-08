/*
Fonksiyon tanimlamak için ornek kod.
*/

int const bekleme_zamani = 500;

void setup() {
  // put your setup code here, to run once:
cikis_Pini_Belirle(13);
}

void loop() {
  // put your main code here, to run repeatedly:

led_Yak(13);
delay(bekleme_zamani);
led_Sondur(13);
delay(bekleme_zamani);
}


// Tanimlanan fonksiyonlar
void cikis_Pini_Belirle(int pin_numarasi) {
  pinMode(pin_numarasi,OUTPUT);
}

void led_Yak(int pin_numarasi){
digitalWrite(pin_numarasi,HIGH);
}

void led_Sondur(int pin_numarasi){
digitalWrite(pin_numarasi,LOW);
}
