#define TIMER_INTERRUPT_DEBUG 0
#define _TIMERINTERRUPT_LOGLEVEL_ 0
#include "NRF52_MBED_TimerInterrupt.h"
#include "NRF52_MBED_ISR_Timer.h"
#include <Arduino.h>
// BLE
#include <ArduinoBLE.h>
#include "struct.h"
// IMU
#include <LSM6DS3.h>
#include <Wire.h>
//GPS
#include <Adafruit_GPS.h>
//SIM
#include "SIM800L.h"

//---------------- GLOBAL VARIABLES -----------------------------

myConfig Config;
bool isAuthenticate = false;

// Timer
#define HW_TIMER_INTERVAL_MS 1
NRF52_MBED_Timer ITimer(NRF_TIMER_3);
NRF52_MBED_ISRTimer ISR_Timer;
#define TIMER_INTERVAL_120S 120000L
// BLE
BLEService PasswordService("19B10000-E8F2-537E-4F6C-D104768A1213");  // Bluetooth® Low Energy Service
BLEService ConfigService("19B10000-E8F2-537E-4F6C-D104768A1214");

BLEShortCharacteristic PasswordCharacteristic("19B10000-E8F2-537E-4F6C-D104768A1213", BLEWrite);  // Bluetooth® Low Energy Characteristic
BLEStringCharacteristic NameCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite, 20);
BLEStringCharacteristic MACCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1217", BLERead, 20);
BLEBooleanCharacteristic ActivationCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1215", BLERead | BLEWrite);
BLEBooleanCharacteristic UnlockCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1216", BLEWrite);
BLEBooleanCharacteristic StopAlarmCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1218", BLEWrite);

BLEDescriptor PasswordDescriptor("2901", "Password");  // Bluetooth® Low Energy Descriptor
BLEDescriptor NameDescriptor("2901", "Name");
BLEDescriptor ActivationDescriptor("2901", "Activation");
BLEDescriptor UnlockDescriptor("2901", "Unlock");
BLEDescriptor MACDescriptor("2901", "MAC Address");
BLEDescriptor StopAlarmDescriptor("2901", "Stop Alarm");

bool BLE_activated = true;  // True if the bluetooth is activated
uint32_t tim_connec = 0;    // Time in ms or we start to activate the bluetooth following a detection of movement

//IMU : LSM6DS3
LSM6DS3 imu(I2C_MODE, 0x6A);  // I2C device address 0x6A
uint32_t timer_imu = millis();
bool MotionBig = false;
bool MotionSmall = false;
bool MotionDetect = false;

// GPS PA1010D
Adafruit_GPS GPS(&Serial1);
bool start_gps = false;
bool position_acquired = false;
uint32_t timer = millis();
#define GPS_WKUP_PIN D8

// SIM800L GSM 2G Module
UART Serial2(D0, D1, NC, NC);
#define SIM800_RST_PIN A5
#define SIM800_DTR_PIN A5
#define TIME_OUT_MS_BLE_ACT 5000  // 300s 300000 times in ms or bluetooth enabled to allow connection following motion detection. (value 5000 for 5s tests)
SIM800L* sim800l;
bool send_position = false;
bool send_move = false;

// Buzzer
const int buzzerPin = D2;
void PulseBuzzer(int repetitions, unsigned long durationOn, unsigned long durationOff);
unsigned long previousMillis = 0;
int currentRep = 0;
bool stopBuzzer = false;

// Electromagnet
const int aimantPin = D3;

// Set a threshold to determine a "small" or "big" movement

float SmallMT = 20.0;  // SmallMotionThreshold
float BigMT = 150.0;   // BigMotionThreshold

float SmallRT = 20.0;  // SmallRotationThreshold
float BigRT = 125.0;   // BigRotationThreshold

// Battery
#define VBAT_ENABLE 14

float MotionData;
float RotationData;

unsigned long StartCoolDown = 0;  // Check point for millis aided cooldown


//-------------------------------- SETUP ----------------------------------------
void setup() {

  // Setup for buzzer
  pinMode(buzzerPin, OUTPUT);  
  digitalWrite(buzzerPin, HIGH);
  delay(1000);
  digitalWrite(buzzerPin, LOW);
  Serial.println(" buzzer");
  
  // Setup electromagnet
  pinMode(aimantPin, OUTPUT);  
  digitalWrite(aimantPin, HIGH);
  delay(1000);
  digitalWrite(aimantPin, LOW);
  Serial.println("electro");

  // Debug led initialization
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LEDR, LOW);

  // Power bridge control
  pinMode(D4, OUTPUT);
  digitalWrite(D4, HIGH);

  // Power battery control with the transistor
  pinMode(D9, OUTPUT);
  digitalWrite(D9, HIGH);

  // Battery charging enable with high current (LOW)100mA > (HIGH)50mA
  pinMode(P0_13, OUTPUT);
  digitalWrite(P0_13, LOW);

  Serial.begin(115200);
  if (!Serial) delay(1000);
  Serial.println("BLE Antivol Peripheral");

  // Timer
  if (ITimer.attachInterruptInterval(HW_TIMER_INTERVAL_MS * 1000, TimerHandler))  // Interval in microsecs
  {
    Serial.print(F("Starting ITimer OK, millis() = "));
    Serial.println(millis());
  }
  ISR_Timer.setInterval(TIMER_INTERVAL_120S, GPS_ISR);

  ble_setup();
  Serial.println(" ble_setup");
  imu_setup();
  Serial.println(" imu_setup");
  gps_setup();
  Serial.println(" gps_setup");
  Serial2.begin(9600);
  delay(100);
  sim800l = new SIM800L((Stream*)&Serial2, SIM800_RST_PIN, 200, 512);
  pinMode(SIM800_DTR_PIN, OUTPUT);
  delay(1000);
  sim_setup();
  Serial.println("SIM SETUP");

  analogReadResolution(ADC_RESOLUTION);  // Setup battery reading
  pinMode(PIN_VBAT, INPUT);
  pinMode(VBAT_ENABLE, OUTPUT);
  digitalWrite(VBAT_ENABLE, LOW);

  Serial.println("fin setup ");
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, LOW);
  Temps();

}

//-------------------------------- LOOP ----------------------------------------
void loop() {

  MotionData = getMotionData();
  RotationData = getRotationData();

  if (Config.isActivate) {  //  Alarm enable
    activateGPS();

    if (MotionData > BigMT || RotationData > BigRT) {  // Big motion detection
      if (MotionData > BigMT) {
        Serial.print("Motion detected : ");
        Serial.println(MotionData);
      } else {
        Serial.print("Rotation detected : ");
        Serial.println(RotationData);
      }
      MotionBig = true;
      MotionSmall = false;
      send_move = true;

    } else if ((MotionBig == false) && (MotionData > SmallMT || RotationData > SmallRT)) {  //  Small motion detection
      if (MotionData > SmallMT) {
        Serial.print(" Small motion: ");
        Serial.println(MotionData);
      } else {
        Serial.print("Small rota : ");
        Serial.println(RotationData);
      }
      MotionSmall = true;
    }
  }
  
  if (MotionBig) {
    PulseBuzzer(5, 500, 1000);  // repetitions, DurationOn , DurationOff
    //sending positions & shock notif via SIM module
  }

  if (MotionSmall) {
    PulseBuzzer(3, 100, 100);  // repetitions, DurationOn , DurationOff
  }

  MotionDetect = true;
  if ((MotionData > SmallMT) || (RotationData > SmallRT)) {
    if (MotionData > SmallMT) {
      Serial.print("WAKE UP : ");
      Serial.println(MotionData);
    } else {
      Serial.print("WAKE UP Rota: ");
      Serial.println(RotationData);
    }
  }

  //  If a mvt is detected and bluetooth is disabled bluetooth activation
  if (MotionDetect == true) {
    tim_connec = millis();
    MotionDetect = false;
    if (BLE_activated == false) {
      BLE_activated = true;
      Serial.println("MVT_detect->setup");
      ble_setup();
    }
  }

  //  Bluetooth actived when we are interacting with the module or when the alarm is on
  if ((BLE_activated == true) || (Config.isActivate)) {
    BLE.poll();  //communication autorisé
  }

  //  At the end of the time during which the lock has not moved, if bluetooth is activated, and the lock is not in activation mode then it is turned off to save the battery
  if ((millis() - tim_connec > TIME_OUT_MS_BLE_ACT) && (BLE_activated == true) && (Config.isActivate != 1)) {
    BLE_activated = false;
    Serial.println("timeout->BLE_END");
    BLE.end();
  }

  //  Capture clocked GPS data
  GPS.read();
  if (GPS.newNMEAreceived()) {
    Serial.print(GPS.lastNMEA());    // This also sets the newNMEAreceived() flag to false
    if (!GPS.parse(GPS.lastNMEA()))  // This also sets the newNMEAreceived() flag to false
      Serial.println("fail to parse");
    ;  // We can fail to parse a sentence in which case we should just wait for another
  }

  if (GPS.fix && position_acquired == false) {  // If location detected
    Serial.println("fix + false");
    position_acquired = true;
    GPS.fix = 0;
    digitalWrite(GPS_WKUP_PIN, LOW);
    GPS.sendCommand("$PMTK225,4*2F");  // Send to backup mode
  }
  
  //  Sending of positions via SIM module
  if (send_move) {  
    Serial.println("Envoi detection mouvement");
    sim800l->setupGPRS("iot.1nce.net");
    sim800l->connectGPRS();
    String Route = "http://141.94.244.11:2000/sendNotfication/" + BLE.address();
    String RouteCoord = "http://141.94.244.11:2000/updateCoordinate/" + BLE.address();
    String str = "{\"latitude\": \" " + convertDMMtoDD(String(float(GPS.latitude), 4)) + "\", \"longitude\":\"" + convertDMMtoDD(String(float(GPS.longitude), 4)) + "\"}";
    String bat = "{\"latitude\": \" " + convertDMMtoDD(String(float(GPS.latitude), 4)) + "\", \"longitude\":\"" + convertDMMtoDD(String(float(GPS.longitude), 4)) + "\", \"batterie\":\"" + String(getBatteryVoltage()) + "\"}";
    char position[200];
    char posbat[200];
    str.toCharArray(position, str.length() + 1);
    //Serial.println(str);
    bat.toCharArray(posbat, bat.length() + 1);
    Serial.println(posbat);
    char direction[200];
    char directionCoord[200];
    Route.toCharArray(direction, Route.length() + 1);
    RouteCoord.toCharArray(directionCoord, RouteCoord.length() + 1);
    sim800l->doPost(direction, "application/json", position, 10000, 10000);
    sim800l->doPost(directionCoord, "application/json", posbat, 10000, 10000);
    sim800l->disconnectGPRS();
    send_move = false;
  }
  
  //  Regular sending of positions via SIM module
  if (send_position) {  
    Serial.println("Envoi regulier position");
    sim800l->setupGPRS("iot.1nce.net");
    sim800l->connectGPRS();
    String RouteCoord = "http://141.94.244.11:2000/updateCoordinate/" + BLE.address();
    String bat = "{\"latitude\": \" " + convertDMMtoDD(String(float(GPS.latitude), 4)) + "\", \"longitude\":\"" + convertDMMtoDD(String(float(GPS.longitude), 4)) + "\", \"batterie\":\"" + String(getBatteryVoltage()) + "\"}";
    char posbat[200];
    bat.toCharArray(posbat, bat.length() + 1);
    Serial.println(posbat);
    Serial.println(RouteCoord);
    char directionCoord[200];
    RouteCoord.toCharArray(directionCoord, RouteCoord.length() + 1);
    sim800l->doPost(directionCoord, "application/json", posbat, 10000, 10000);
    sim800l->disconnectGPRS();
    send_position = false;
  }
}

//------------- ADDITIONAL FUNCTIONS ------------------------------

void Temps(void) {
  unsigned long millisPassed = millis();
  unsigned int seconds = (millisPassed / 1000) % 60;
  unsigned int minutes = (millisPassed / (1000 * 60)) % 60;
  unsigned int hours = (millisPassed / (1000 * 60 * 60)) % 24;
  Serial.print("Détecté a : ");
  Serial.print(hours);
  Serial.print("h");
  Serial.print(minutes);
  Serial.print("mn");
  Serial.print(seconds);
  Serial.println("s");
}

void TimerHandler() {
  ISR_Timer.run();
}

char Conversion(unsigned short int data) {
  char mdphexadecimal[5];
  sprintf(mdphexadecimal, "%04X", data);

  for (int i = 0; i < 2; ++i) {
    char temp = mdphexadecimal[i];
    mdphexadecimal[i] = mdphexadecimal[2 + i];
    mdphexadecimal[2 + i] = temp;
  }
  //  Serial.println("Mot de passe : " + String(valeur) + " ");  // Used to see the value in decimal
  Serial.print("Written password  = ");
  Serial.println(mdphexadecimal);
}

String convertDMMtoDD(String dmmCoordinates) {
  int degrees;
  float minutes;
  //  Separate coordinates in degrees and decimal minutes
  if (dmmCoordinates.length() == 9) {
    degrees = dmmCoordinates.substring(0, 2).toInt();
    minutes = dmmCoordinates.substring(2).toFloat();
  } else {
    degrees = dmmCoordinates.substring(0, 1).toInt();
    minutes = dmmCoordinates.substring(1).toFloat();
  }
  //  Convert decimal minutes to decimal degrees
  float decimalDegrees = degrees + (minutes / 60.0);

  // Convert to string and format coordinates to decimal degrees
  String ddCoordinates = String(decimalDegrees, 10);  // You can adjust the number of decimals here

  return ddCoordinates;
}
