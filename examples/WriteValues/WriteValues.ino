#include <ThingSpeakWriter_asukiaaa.h>

#define WRITE_API_KEY "****"
#define WIFI_SSID "****"
#define WIFI_PASS "****"

ThingSpeakWriter_asukiaaa channelWriter(WRITE_API_KEY);

void connectWifiIfNotConnected(unsigned long timeoutMs = 10000) {
  if (WiFi.status() == WL_CONNECTED) {
    return;
  }
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  uint8_t startAt = millis();
  Serial.println("Connecting to WiFi.." + String(WiFi.status()));
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    if (millis() - startAt > timeoutMs) {
      Serial.println("Cannot connect to WiFi");
      break;
    }
    delay(1000);
  }
}

void setup() {
}

void loop() {
  connectWifiIfNotConnected();
  channelWriter.setField(1, String(millis()));
  channelWriter.writeFields();
  delay(10000);
}
