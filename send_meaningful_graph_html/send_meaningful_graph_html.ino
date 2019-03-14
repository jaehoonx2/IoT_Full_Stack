const char* host = "your_public_addr";
String url = "your_api_key";  
const int httpPort = 3000;
int interval = 15000;

#include "DHT.h"
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#define DHTPIN D2
#define DHTTYPE DHT11

const char* ssid = "";      // your AP name
const char* password = "";  // your AP passwd
DHT dht(DHTPIN, DHTTYPE);

String working() {
  float temp = dht.readTemperature();
  float humid = dht.readHumidity();

  Serial.print("temp : ");Serial.println(temp);
  Serial.print("humid : ");Serial.println(humid);

  return(String("field1=")+String(temp)+String("&field2=")+String(humid));
}

void delivering(String payload) { 
  WiFiClient client;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpPort)) {
    Serial.print("connection failed: ");
    Serial.println(payload);
    return;
  }
  String getheader = "GET "+ String(url) +"&"+ String(payload) +" HTTP/1.1";
  client.println(getheader);
  client.println("User-Agent: ESP8266 Kyuho Kim");  
  client.println("Host: " + String(host));  
  client.println("Connection: close");  
  client.println();

  Serial.println(getheader);
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    Serial.println(line);
  }
  Serial.println("Done cycle.");
}

void connect_ap() {
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n Got WiFi, IP address: ");
  Serial.println(WiFi.localIP());  
}

void setup() {
  Serial.begin(115200);
  connect_ap();

  dht.begin();  // start estimating temp
}

unsigned long mark = 0;
void loop() {
  if (millis() > mark ) {
     mark = millis() + interval;
     String payload = working();
     delivering(payload);
  }
}
