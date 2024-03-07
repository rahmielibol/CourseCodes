/*

HC-SR 04 sensoru ile mesafe olcumu

  */

#define tetiklemePini 3
#define yankiPini 7

long yanki_suresi, hesaplanan_mesafe;



void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(tetiklemePini, OUTPUT);
  pinMode(yankiPini, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print(mesafe_olcumu());
  Serial.println(" cm mesafe var.");
}


int mesafe_olcumu() {
  // mesafe_olcumu isimli yeni bir fonksiyon tanimlandi.
  digitalWrite(tetiklemePini,LOW);
  delayMicroseconds(2);
  digitalWrite(tetiklemePini,HIGH);
  delayMicroseconds(10);
  digitalWrite(tetiklemePini,LOW);
  yanki_suresi = pulseIn(yankiPini, HIGH);
  hesaplanan_mesafe = (yanki_suresi/2) * 0.0343;    // (Sesin karsidaki nesneye gidip donme suresi / 2 ) * ses hizi (343 m/s = 0.0343 cm/us)
  delay(300);
  return(hesaplanan_mesafe);
}
