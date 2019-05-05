#include "ESP8266WiFi.h"

const char* ssid = "Chimot.Net";
const char* password =  "ramon2010";

WiFiServer wifiServer(8888);

void setup() {

  Serial.begin(115200);
  pinMode(D8 , OUTPUT);
  pinMode(D7 , OUTPUT);

  delay(1000);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting..");

  }

  Serial.print("Connected to WiFi. IP:");
  Serial.println(WiFi.localIP());

  wifiServer.begin();
}

void loop() {

  WiFiClient client = wifiServer.available();

  if (client) {

    while (client.connected()) {

      while (client.available() > 0) {
        char c = client.read();

        if (c == 'a') {
          digitalWrite(D8 , HIGH);
        } else if (c == 'b') {
          digitalWrite(D8 , LOW);
        } else if (c == 'c') {
          digitalWrite(D7 , HIGH);
        } else if (c == 'd' ) {
          digitalWrite(D7 , LOW);
        }

        Serial.println(c);

      }

      delay(10);
    }

    client.stop();
    Serial.println("Client disconnected");

  }
}
