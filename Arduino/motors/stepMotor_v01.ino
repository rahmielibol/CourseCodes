/*
28 BYJ-48 Redüktörlü Step Motor ve ULN2003A Step Motor Sürücü Kartı kodu
Kutuphane kullanmadan adım motorunun sariglarinin uyarilarak calistirilabilmesi icin yazilan kod...
*/
// Motor pinlerini tanimliyoruz
int motorPin1 = 8;
int motorPin2 = 9;
int motorPin3 = 10;
int motorPin4 = 11;

int motorHizi = 1200; // Motor hızı
int adimSayisi = 0;         // Atılan adım sayısı
int adimSayisiDonus = 512; // Bir tur için adım sayısı

void setup() {
  // Pinleri çıkış olarak ayarla
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void loop() {
  if (adimSayisi < adimSayisiDonus) {
    saatYonu();
  } else if (adimSayisi == adimSayisiDonus * 2) {
    adimSayisi = 0;
  } else {
    TersSaatYonu();
  }
  adimSayisi++;
     ///donus adimlarinin gorunmesi amaciyla
  //delay(250);   ///donus adimlarinin gorunmesi amaciyla
}

void saatYonu() {
  // Saat yönünde faz sıraları
  stepMotor(1, 0, 0, 0);
  stepMotor(1, 1, 0, 0);
  stepMotor(0, 1, 0, 0);
  stepMotor(0, 1, 1, 0);
  stepMotor(0, 0, 1, 0);
  stepMotor(0, 0, 1, 1);
  stepMotor(0, 0, 0, 1);
  stepMotor(1, 0, 0, 1);
}

void TersSaatYonu() {
  // Saat yönünün tersine faz sıraları
  stepMotor(1, 0, 0, 1);
  stepMotor(0, 0, 0, 1);
  stepMotor(0, 0, 1, 1);
  stepMotor(0, 0, 1, 0);
  stepMotor(0, 1, 1, 0);
  stepMotor(0, 1, 0, 0);
  stepMotor(1, 1, 0, 0);
  stepMotor(1, 0, 0, 0);
}

void stepMotor(int p1, int p2, int p3, int p4) {
  digitalWrite(motorPin1, p1);
  digitalWrite(motorPin2, p2);
  digitalWrite(motorPin3, p3);
  digitalWrite(motorPin4, p4);
  delayMicroseconds(motorHizi);
  
  //delay(500);   // Hangi sargilari ne kadar sure ile uyarıyoruz?

}
