#include <dht.h>
dht DHT;

#define DHT11_PIN 7


void setup(){
  Serial.begin(9600);
}


void loop() {
  delay(5000);
  int chk = DHT.read11(DHT11_PIN);
  float h = DHT.humidity;
  float t = DHT.temperature;

  String message = "";

  if (isnan(h) || isnan(t)) {
    return;
  }

  // Create JSON as a message
  message = message + "{\"humidity\": ";
  message = message + h;
  message = message + ", \"temperature\": ";
  message = message + t;
  message = message + "}";

  // Send message
  Serial.println(message);
}
