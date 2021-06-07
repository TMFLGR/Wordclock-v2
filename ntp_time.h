#ifndef ntp_time_h
#define ntp_time_h

#include <Arduino.h>
#include "wifi_client.h"
#include <WiFiUdp.h>
#include <TimeLib.h>

void ntp_setup();
void send_ntp_packet(const IPAddress &address);
time_t get_ntp_time();
 

#endif
