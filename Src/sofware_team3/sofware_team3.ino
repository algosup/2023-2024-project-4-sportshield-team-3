//---------------- BASIC VARIABLES -----------------------------
#define TIMER_INTERRUPT_DEBUG 0
#define _TIMERINTERRUPT_LOGLEVEL_ 0
#include "NRF52_MBED_TimerInterrupt.h"
#include "NRF52_MBED_ISR_Timer.h"
#include <Arduino.h>
// BLE
#include <ArduinoBLE.h>
// IMU
#include <LSM6DS3.h>
#include <Wire.h>
//GPS
#include <Adafruit_GPS.h>
//SIM
#include "SIM800L.h"

#include "struct.h"

//---------------- GLOBAL VARIABLES -----------------------------
myConfig Config;
#define VBAT_ENABLE 14

const int buzzerPin = D2;
const int electroMagnet = D3;

void deviceOn();
void deviceOff();

void setup() {
  Serial.begin(115200);  // Initialize serial communication
  
  // Setup battery reading
  analogReadResolution(ADC_RESOLUTION);  
  pinMode(PIN_VBAT, INPUT);
  pinMode(VBAT_ENABLE, OUTPUT);
  digitalWrite(VBAT_ENABLE, LOW);

  // Setup LEDS pin
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  pinMode(buzzerPin, OUTPUT);

  deviceOn();
  deviceOff();

}
// Only print the battery percentage every 15 mintutes
void loop() {
    delay(100);
    Serial.print("Battery Percentage: ");
    Serial.print(getBatteryPercentage());
    Serial.println("%");
    visualBatteryLevelIndicator();
}

