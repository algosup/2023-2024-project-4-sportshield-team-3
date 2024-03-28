struct myConfig {
  short int pin = 0;
  String Name = "\n";
  bool isActivate = false; // False == sleep mode

  bool isBatteryLow = false;
  bool isBatteryFull = false;
  bool isBatteryCritical = false;
};