struct myConfig {
  short int pin = 0;
  String Name = "\n";
  bool isActivate = false; // False == sleep mode

  // String uniqueUser;

  bool isBatteryLow = false;
  bool isBatteryFull = false;
  bool isBatteryCritical = false;
};