#include "wifi_client.h"
#include "ntp_time.h"


void setup() {
  Serial.begin(115200);
  wifi_client_setup();
  ntp_setup();
}

void loop() {
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.print(second());
  Serial.println("");
  delay(5000);
}
