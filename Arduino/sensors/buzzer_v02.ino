#define buzzerPin 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i=1; i<11; i++) {
    Serial.print(i*100);
    Serial.println(" tonu çalınıyor.");

      for (int j=1; j<6; j++){
        melodi(50,i*100); 
        Serial.print(j);  
      }
    Serial.println(" ");
  }
  Serial.println("---");
  delay(1000);
}


int melodi(int gecikme, int tone_degeri) {
    // melodi isimli bir fonksiyon tanimlandi
    tone(buzzerPin, tone_degeri);
    delay(gecikme);
    noTone(buzzerPin);
    delay(gecikme);
  }

