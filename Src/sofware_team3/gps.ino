// This file stand for the gps location of the device

void gps_setup(void) {
  pinMode(GPS_WKUP_PIN, OUTPUT);
  digitalWrite(GPS_WKUP_PIN, LOW);
  GPS.begin(9600);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  GPS.sendCommand("$PMTK225,4*2F");  // send to backup mode
  // GPS.sendCommand("$PMTK225,8*23");   // send to Always Locate backup mode
  // GPS.sendCommand("$PMTK225,9*22");   // send to Always Locate standby mode
  // GPS.sendCommand("$PMTK225,2,4000,15000,24000,90000*16");  // send to periodic standby mode
  // GPS.sendCommand("$PMTK161,0*28");   // send to standby mode
}

void GPS_ISR() {
  if (Config.isActivate != 0) {
    if (!position_acquired) {
      start_gps = true;
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    } else {
      // digitalWrite(GPS_WKUP_PIN, LOW);
      // GPS.sendCommand("$PMTK225,4*2F");  // send to backup mode
      send_position = true;
      position_acquired = false;
    }
  }
}

void activateGPS() {
  if (start_gps == true) {
    digitalWrite(GPS_WKUP_PIN, HIGH);
    start_gps = false;
  }
}