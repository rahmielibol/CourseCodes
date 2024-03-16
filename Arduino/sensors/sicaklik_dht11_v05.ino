/*
Sicaklik ve nem sensoru kullanimi
*/


#include <DHT.h>     // DHT sicaklik ve nem sensoru kutuphanesi

#define dhtPini 2
#define dhtTipi DHT11

DHT dht(dhtPini, dhtTipi);

void setup() {
  // put your setup code here, to run once:

  dht.begin();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  float sicaklik = dht.readTemperature();
  float nem = dht.readHumidity();

  Serial.print("Sicaklik :  " );
  Serial.print(sicaklik);
  Serial.println(" C" );
  Serial.print("Nem : % " );
  Serial.println(nem);
  Serial.println("--- --- --- ---");
  delay(1000);
}
