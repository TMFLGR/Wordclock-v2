#include "wifi_client.h"


void wifi_client_setup() {
  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFi.setAutoReconnect(true);
  WiFi.hostname("wordclock.local");
  WiFi.begin(WLAN_SSID,WLAN_PSK);
  wifi_client_connect();
}

void wifi_client_connect() {
  Serial.println("Connecting Wifi");
  while(!WiFi.isConnected()) {
    delay(100);
    Serial.print(".");
  }
  Serial.print("\n");
  Serial.printf("WiFi connected, IP: %s\n", WiFi.localIP().toString().c_str());
}
