// Sound for hardware
const byte COUNT_NOTES = 24;
int melodyDeviceOn[COUNT_NOTES] = {
  262, 294, 330, 349, 392, 440, 494, 523, 523, 494, 440, 392,
  349, 330, 294, 262, 262, 294, 330, 349, 392, 440, 494, 523
};

int melodyDeviceSleepMode[COUNT_NOTES] = {
  200, 150, 130, 110, 100, 80, 70, 60, 50, 40, 30, 20,
  200, 150, 130, 110, 100, 80, 70, 60, 50, 40, 30, 20
};

int melodyBluetoothConnected[COUNT_NOTES] = {
  150, 200, 250, 300, 350, 400, 450, 500, 550, 600,
  550, 500, 450, 400, 350, 300, 250, 200, 150, 200,
  250, 300, 350, 400
};

int durations[COUNT_NOTES] = {
  200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200,
  200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200
};

void deviceOn() {
  for (int i = 0; i < COUNT_NOTES; i++) {
    tone(buzzerPin, melodyDeviceOn[i], durations[i]);
    delay(durations[i]);
    noTone(buzzerPin);
    delay(50); 
  }
  digitalWrite(buzzerPin, LOW);
}

void deviceSleepMode() {
  for (int i = 0; i < COUNT_NOTES; i++) {
    tone(buzzerPin, melodyDeviceSleepMode[i], durations[i]);
    delay(durations[i]);
    noTone(buzzerPin);
    delay(50);
  }
  digitalWrite(buzzerPin, LOW);
  
}

void bluetoothConnected() {
  for (int i = 0; i < COUNT_NOTES; i++) {
    tone(buzzerPin, melodyBluetoothConnected[i], durations[i]);
    delay(durations[i]);
    noTone(buzzerPin);
    delay(50);
  }
  digitalWrite(buzzerPin, LOW);
  
}