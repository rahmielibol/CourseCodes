/*

HC-SR 04 sensoru ile mesafe olcumu, ve sesli uyari

  */

#define tetiklemePini 3
#define yankiPini 7
#define buzzerPin 10

long yanki_suresi, hesaplanan_mesafe;
const int algilanan_En_Uzak_Mesafe = 200, algilanan_En_Yakin_Mesafe = 2; 


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(tetiklemePini, OUTPUT);
  pinMode(yankiPini, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print(mesafe_olcumu(algilanan_En_Yakin_Mesafe,algilanan_En_Uzak_Mesafe));
  Serial.println(" cm mesafe var.");
  melodi(hesaplanan_mesafe,400);

}


int mesafe_olcumu(int min, int max) {
  // mesafe_olcumu isimli yeni bir fonksiyon tanimlandi.
  digitalWrite(tetiklemePini,LOW);
  delayMicroseconds(2);
  digitalWrite(tetiklemePini,HIGH);
  delayMicroseconds(10);
  digitalWrite(tetiklemePini,LOW);
  yanki_suresi = pulseIn(yankiPini, HIGH);
  hesaplanan_mesafe = (yanki_suresi/2) * 0.0343;    // (Sesin karsidaki nesneye gidip donme suresi / 2 ) * ses hizi (343 m/s = 0.0343 cm/us)
  delay(300);
  if (hesaplanan_mesafe > min && hesaplanan_mesafe < max) {
    return(hesaplanan_mesafe);
  }
  else {return(0);} 
}


int melodi(int gecikme, int tone_degeri) {
    // melodi isimli bir fonksiyon tanimlandi
    tone(buzzerPin, tone_degeri);
    delay(gecikme);
    noTone(buzzerPin);
    delay(gecikme);
  }
