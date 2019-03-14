// DHT11 sensor tutorial

#include "DHT.h"
#define DHTPIN D2     // only d2 or d4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  float humid = dht.readHumidity();
  float temp = dht.readTemperature();

   if(isnan(humid) || isnan(temp)){
    Serial.println("Failed to read from DHT sensor!");
    return;
   }

   Serial.print((int)temp);Serial.print("°C, ");
   Serial.print((int)humid);Serial.println("%");

   delay(1500);
}
