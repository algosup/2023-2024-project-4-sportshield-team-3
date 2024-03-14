/*
    Get the remaining battery voltage

      params:
        - None

      return:
        - float voltage
*/
float getBatteryVoltage() {
  int rawValue = analogRead(PIN_VBAT);
  float voltage = rawValue * (3.3 / 1023.0);  // Convert raw ADC value to voltage
  return voltage;
}

/*
    Convert the battery voltage in percent
      
      params:
        - None
      
      return:
        - float percentage
*/
float getBatteryPercentage() {
  // Calculate the percentage charge
  float voltage = getBatteryVoltage();
  float minVoltage = 3.0;                                           // Minimum voltage of the battery in volts
  float maxVoltage = 4.2;                                           // Maximum voltage of the battery when fully charged
  float percentage = map(voltage, minVoltage, maxVoltage, 0, 100);  // Map voltage to percentage
  percentage = constrain(percentage, 0, 100);                       // Ensure percentage stays within 0-100 range
  return percentage;
}

/*
    Allert the user that he turn ON/OFF the device if turn ON receive a notification with the remaining percentage
      status:
        - Not done
      params:
        - myConfig* Config
        - UserInput to activate it

      return:
        - bool Config.isActivate
*/
bool batteryAlertSwitchMode(myConfig* Config) {
  if (Config->isActivate == true) {
    Config->isActivate = false;
    return Config->isActivate;
  } 
  else {
    Serial.println("The anti-thief mode desactivated, ");
    Serial.print(getBatteryPercentage());
    Serial.println(" remaining");
    Config->isActivate = true;
    return Config->isActivate;
  }
}

/*
    Get the remaining battery voltage
      params:
        - None
      return:
        - float voltage
*/
// When the battery will reach the 100% of charge the device will make noice + notifiation
int batteryIsFullCharge() {
}

/*
    Get the remaining battery voltage
      params:
        - None
      return:
        - float voltage
*/
// When the battery will be low (10%) send a notification to the user (no noice)
int batteryIsLow() {
}

/*
    Get the remaining battery voltage
      params:
        - None
      return:
        - float voltage
*/
// Before reaching the 5% of battery the device will send a notification and pass in extra eco mode avoiding some features
int batteryIsCritical() {
}

/*
    Battery LED indactor (Green = 100% to 66%, Blue = 65% to 33, Red = 32% to 0%)
    params:
      - float percentage
    retrun:
      - None
*/
void visualBatteryLevelIndicator(){
  
  float batteryPercentage = getBatteryPercentage();

  if (batteryPercentage >= 66.00){
    digitalWrite(LED_GREEN, HIGH);
    delay(1000);
    digitalWrite(LED_GREEN, LOW);
  }
  else if (batteryPercentage < 66.00 && batteryPercentage >= 33.00) {
    digitalWrite(LED_BLUE, HIGH);
    delay(1000);
    digitalWrite(LED_GREEN, LOW);
  }
  else{
    digitalWrite(LED_RED, HIGH);
    delay(1000);
    digitalWrite(LED_GREEN, LOW);
  }
}
