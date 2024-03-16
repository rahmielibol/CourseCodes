/*
PIR sensoru
  */

int sensor_Pini = 8;
int led_Pini = 13;

int sensor_Durum = LOW;
int sensor_Degeri = 0;
int alarm_Sayisi = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor_Pini, INPUT);
  pinMode(led_Pini, OUTPUT);

  Serial.begin(9600);


}
void loop() {
  // put your main code here, to run repeatedly:
  
  sensor_Degeri = digitalRead(sensor_Pini);
  Serial.println(sensor_Degeri);
  
  if (sensor_Degeri == HIGH) {     // Eger sensor HIGH (1) degeri gonderiyor ise
    digitalWrite(led_Pini, HIGH);  
    if (sensor_Durum == LOW) {     // Eger oncesinde bir hareket yoktu ise
      sensor_Durum = HIGH;
      Serial.println("Ortamda hareketli bir nesne var.");
      alarm_Sayisi++;
      Serial.print("Alarm : ");
      Serial.println(alarm_Sayisi);
    }
  } 
  else {   // Eger sensor LOW (0) degeri gönderiyorsa
    digitalWrite(led_Pini, LOW);
    if (sensor_Durum == HIGH) {     // Eger hareket vardi ise
      sensor_Durum = LOW;
    }
  }

delay(100);
}
