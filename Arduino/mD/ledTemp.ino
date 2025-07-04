
#include <SoftwareSerial.h>

const int RX = 4;
const int TX = 5;

SoftwareSerial bluetooth(RX, TX);

#include <DHT.h>

#define DHTPIN 2       
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  pinMode(9, OUTPUT);     // Red Led
  pinMode(11, OUTPUT);    // Green Led
  bluetooth.begin(9600);

  Serial.begin(9600);

  dht.begin();
}

void loop() {
  if (bluetooth.available()) {
    char veri = bluetooth.read();
    if (veri == '0') {
      digitalWrite(9, LOW);
      digitalWrite(11, LOW);
    } else if (veri == '1') {
      digitalWrite(9, HIGH);
      digitalWrite(11, LOW);
    } else if (veri == '2') {
      digitalWrite(9, LOW);
      digitalWrite(11, HIGH);
    } else if (veri == '3') {
      digitalWrite(9, HIGH);
      digitalWrite(11, HIGH);
    } else if (veri == 'T') {
      float temp = dht.readTemperature();
      float hum = dht.readHumidity();

      if (isnan(temp) || isnan(hum)) {
        bluetooth.println("Sensor Error");
        return;
      }
      String data = "Temperature: " + String(temp) + " C\n" + "Humidity: " + String(hum) + " %";
      bluetooth.print(String(temp));
      Serial.println(data);
      delay(100);
    }

    else if (veri == 'H') {
      float temp = dht.readTemperature();
      float hum = dht.readHumidity();

      if (isnan(temp) || isnan(hum)) {
        bluetooth.println("Sensor Error");
        return;
      }
      String data = "Temperature: " + String(temp) + " C\n" + "Humidity: " + String(hum) + " %";
      bluetooth.print(String(hum));
      Serial.println(data);
      delay(100);
    }
  }
}
