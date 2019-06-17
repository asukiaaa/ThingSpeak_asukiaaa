#ifndef THINGSPEAK_WRITER_ASUKIAAA_H
#define THINGSPEAK_WRITER_ASUKIAAA_H

#include <HTTPClient.h>
const char ThingSpeakHost[] = "api.thingspeak.com";

#define THINGSPEAK_FIELD_LEN 8

class ThingSpeakWriter_asukiaaa {
 public:
  ThingSpeakWriter_asukiaaa(String writeApiKey);
  void setField(uint8_t fieldNumber, String value);
  void setCreatedAt(String createdAt);
  int writeFields();

 private:
  String createdAt;
  String fieldValues[THINGSPEAK_FIELD_LEN];
  String writeApiKey;
  void clearValues();
};

#endif
