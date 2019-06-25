#include "ThingSpeakWriter_asukiaaa.h"

ThingSpeakWriter_asukiaaa::ThingSpeakWriter_asukiaaa(String writeApiKey) {
  this->writeApiKey = writeApiKey;
  clearValues();
}

void ThingSpeakWriter_asukiaaa::setField(uint8_t fieldNumber, String value) {
  if (fieldNumber <= 0 || fieldNumber > THINGSPEAK_FIELD_LEN) {
    return;
  }
  fieldValues[fieldNumber-1] = value;
}

void ThingSpeakWriter_asukiaaa::setCreatedAt(String createdAt) {
  createdAt = createdAt;
}

int ThingSpeakWriter_asukiaaa::writeFields() {
  String url = String("http://") + ThingSpeakHost + "/update?api_key=" + writeApiKey;
  for (uint8_t i = 0; i < THINGSPEAK_FIELD_LEN; ++i) {
    String v = fieldValues[i];
    if (v == "") continue;
    url += "&field" + String(i+1) + "=" + v;
  }
  if (createdAt != "") {
    url += "&created_at=" + createdAt;
  }
  HTTPClient http;
  http.begin(url);
  return http.GET();
}

void ThingSpeakWriter_asukiaaa::clearValues() {
  for (uint8_t i = 0; i < THINGSPEAK_FIELD_LEN; ++i) {
    fieldValues[i] = "";
  }
  createdAt = "";
}
