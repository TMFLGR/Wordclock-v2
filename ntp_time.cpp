#include "ntp_time.h"

// UDP Config - Do not change this.
const int NTP_PACKET_SIZE = 48;
uint8_t PACKET_BUFFER[NTP_PACKET_SIZE];
const unsigned int NTP_LOCAL_PORT = 8888;
const unsigned int NTP_SYNC_INSECONDS = 60; // 60 seconds


// NTP Config - TODO: Make this configurable and write to EEPROM
char ntpServerName[] = "de.pool.ntp.org";
// 1 wintertime / 2 summertime
int ntpTimeZone = 2;

WiFiUDP UDP;
IPAddress ntpServerIp;

// init / header
void ntp_setup() {
  WiFi.hostByName(ntpServerName, ntpServerIp);
  UDP.begin(NTP_LOCAL_PORT);
  setSyncProvider(get_ntp_time);
  setSyncInterval(NTP_SYNC_INSECONDS);
}

// Get NTP Time Impl
time_t get_ntp_time() {
  printf("[NTP]\tSyncing Time\n");
  // discard previously received packets
  while(UDP.parsePacket() > 0) ;

  // send ntp packet
  send_ntp_packet(ntpServerIp);
  unsigned int startWait = millis();
  while(millis() - startWait < 1500) {
    int packetSize = UDP.parsePacket();
    // check if packet is valid
    if (packetSize >= NTP_PACKET_SIZE) {
      // read packet into buffer
      UDP.read(PACKET_BUFFER, NTP_PACKET_SIZE);
      // convert buffer to unix timestamp
      unsigned long unixTimestamp = (unsigned long) PACKET_BUFFER[40] << 24;
      unixTimestamp |= (unsigned long) PACKET_BUFFER[41] << 16;
      unixTimestamp |= (unsigned long) PACKET_BUFFER[42] << 8;
      unixTimestamp |= (unsigned long) PACKET_BUFFER[43];
      // cast to time_t and append timezone
      return (unixTimestamp - 2208988800UL) + (ntpTimeZone * SECS_PER_HOUR);
    }
  }
  return 0;
}

// Send UDP Packet Impl adress
void send_ntp_packet(const IPAddress &address) {
    // reset buffer
    memset(PACKET_BUFFER, 0, NTP_PACKET_SIZE);
    // Init PACKET_BUFFER
    // LI, Version, Mode
    PACKET_BUFFER[0] = 0b11100011;
    // type of clock 
    PACKET_BUFFER[1] = 0;    
    // Polling Interval
    PACKET_BUFFER[2] = 6;
    // Peer Clock Precision    
    PACKET_BUFFER[3] = 0xEC;  
    // 8 bytes of zero for Root Delay & Root Dispersion
    PACKET_BUFFER[12] = 49;
    PACKET_BUFFER[13] = 0x4E;
    PACKET_BUFFER[14] = 49;
    PACKET_BUFFER[15] = 52;
    // Request the Timestamp on port 123
    UDP.beginPacket(address, 123); 
    UDP.write(PACKET_BUFFER, NTP_PACKET_SIZE);
    UDP.endPacket();
}
