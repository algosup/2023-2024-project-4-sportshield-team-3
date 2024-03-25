// Get the battery current voltage
float getBatteryVoltage() {
  float rawValue = analogRead(PIN_VBAT);
  float currentVoltage = rawValue * (3.7 / 1023.0);
  return currentVoltage;
}

float getBatteryPercentage() {
  float voltage = getBatteryVoltage();
  float batteryPercentage = ((voltage - MIN_VOLTAGE) / (MAX_VOLTAGE - MIN_VOLTAGE));
  // norlalizedVoltage = constrain(norlalizedVoltage, 0.0, 1.0);
  // float batteryPercentage = norlalizedVoltage ;
  return batteryPercentage;
}

// bool batteryAlertSwitchMode(myConfig* Config) {
//   if (Config->isActivate == true) {
//     Serial.println("The anti-thief mode desactivated, ");
//     Serial.print(getBatteryPercentage());
//     Serial.println(" remaining");
//     Config->isActivate = false;
//     return Config->isActivate;
//   } 
//   else {
//     Serial.println("The anti-thief mode activated, ");
//     Serial.print(getBatteryPercentage());
//     Serial.println(" remaining");
//     Config->isActivate = true;
//     return Config->isActivate;
//   }
// }


// When the battery will reach the 100% of charge the device will make noice + notifiation
int batteryIsFullCharge() {
}

// When the battery will be low (10%) send a notification to the user (no noice)
int batteryIsLow() {
}

// Before reaching the 5% of battery the device will send a notification and pass in extra eco mode avoiding some features
int batteryIsCritical() {
}

// void visualBatteryLevelIndicator(){
  
//   float batteryPercentage = getBatteryPercentage();

//   if (batteryPercentage >= 66.00){
//     digitalWrite(LED_GREEN, HIGH);
//     delay(1000);
//     digitalWrite(LED_GREEN, LOW);
//   }
//   else if (batteryPercentage < 66.00 && batteryPercentage >= 33.00) {
//     digitalWrite(LED_BLUE, HIGH);
//     delay(1000);
//     digitalWrite(LED_GREEN, LOW);
//   }
//   else{
//     digitalWrite(LED_RED, HIGH);
//     delay(1000);
//     digitalWrite(LED_GREEN, LOW);
//   }
// }
