struct myConfig {
  short int pin = 0;
  String Name = "\n";
  unsigned long startTime; // Permit to store the time beetween each switch true/false for isActivate
  bool isActivate = true; // False == sleep mode
};