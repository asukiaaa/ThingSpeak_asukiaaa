#include <ThingSpeakWriter_asukiaaa.h>

#define WRITE_API_KEY "****"
#define WIFI_SSID "****"
#define WIFI_PASS "****"
#define WIFI_RETRY_MAX_COUNT 5

ThingSpeakWriter_asukiaaa channelWriter(WRITE_API_KEY);

void connectWifiIfNotConnected() {
  uint8_t count = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(2000);
    Serial.println("Connecting to WiFi.." + String(WiFi.status()));
    if (count > WIFI_RETRY_MAX_COUNT) {
      Serial.println("Cannot connect to WiFi");
      break;
    }
    ++count;
  }
}

void setup() {
  WiFi.begin(WIFI_SSID, WIFI_PASS);
}

void loop() {
  connectWifiIfNotConnected();
  channelWriter.setField(1, String(millis()));
  channelWriter.writeFields();
  delay(10000);
}
