// Get the battery current voltage
float getBatteryVoltage() {
  float rawValue = analogRead(PIN_VBAT);
  float currentVoltage = rawValue * (3.7 / 1023.0);
  return currentVoltage;
}

float getBatteryPercentage() {
  float voltage = getBatteryVoltage();
  float norlalizedVoltage = ((voltage - 3.2) / (4.2 - 3.2));
  norlalizedVoltage = constrain(norlalizedVoltage, 0.0, 1.0);
  float batteryPercentage = norlalizedVoltage * 100;
  return norlalizedVoltage;
}

// When device activated/deactivated send a notification + battery level remaining
void batteryAlertSwitchMode() {
  if (Config.isActivate == true) {
    Serial.println("The anti-thief mode desactivated, ");
    Serial.print(getBatteryPercentage());
    Serial.println(" remaining");
    Config.isActivate = false;
  } 
  else {
    Serial.println("The anti-thief mode activated, ");
    Serial.print(getBatteryPercentage());
    Serial.println(" remaining");
    Config.isActivate = true;
  }
}

// // Check if battery PIN receive more V than usual or USB detection
// void isBatteryInCharge() {
//     if (/* USB PLUGGED condition */) {
//         float batteryPercentage = getBatteryPercentage();
//         if (batteryPercentage <= 5.0) {
//             Config.isBatteryCritical = true;
//             Config.isBatteryLow = false;
//             Config.isBatteryFull = false;
//             Serial.println("Battery is critically low.");
//         } 
//         else if (batteryPercentage > 5.0 && batteryPercentage <= 10.0) {
//             // Battery is low
//             Config.isBatteryCritical = false;
//             Config.isBatteryLow = true;
//             Config.isBatteryFull = false;
//             Serial.println("Battery is low. Please charge soon.");
//         } 
//         else if (batteryPercentage >= 95.0) {
//             // Battery is full
//             Config.isBatteryCritical = false;
//             Config.isBatteryLow = false;
//             Config.isBatteryFull = true;
//             Serial.println("Battery is fully charged.");
//         }
//         else {
//             // Battery is charging within normal range
//             Config.isBatteryCritical = false;
//             Config.isBatteryLow = false;
//             Config.isBatteryFull = false;
//             Serial.println("Battery is currently charging.");
//         }
//     }
// }

// When the battery will be low (10%) send a notification to the user (no noice)
void batteryIsLow() {
  if (getBatteryPercentage() <= 10.00 && Config.isBatteryLow == false){
  }
}

// Before reaching the 5% of battery the device will send a notification and pass in extra eco mode avoiding some features
void batteryIsCritical() {
  if (getBatteryPercentage() <= 5.00 && Config.isBatteryCritical == false){
  }
}
