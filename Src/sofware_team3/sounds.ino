// Sound for hardware
const byte COUNT_NOTES = 5;
int melodyDeviceOn[COUNT_NOTES] = {
  262, 294, 330, 349, 392
  // , 440, 494, 523, 523, 494, 440, 392, 349, 330, 294, 262, 262, 294, 330, 349, 392, 440, 494, 523
};

int melodyDeviceSleepMode[COUNT_NOTES] = {
  200, 150, 130, 110, 100
  // , 80, 70, 60, 50, 40, 30, 20, 200, 150, 130, 110, 100, 80, 70, 60, 50, 40, 30, 20
};

int melodyBluetoothConnected[COUNT_NOTES] = {
  150, 200, 250, 300, 350
  // , 400, 450, 500, 550, 600, 550, 500, 450, 400, 350, 300, 250, 200, 150, 200, 250, 300, 350, 400
};

int melodyBluetoothDisconnected[COUNT_NOTES] = {
  350, 300, 250, 200, 150
  // , 400, 450, 500, 550, 600, 550, 500, 450, 400, 350, 300, 250, 200, 150, 200, 250, 300, 350, 400
};

int durations[COUNT_NOTES] = {
  200, 200, 200, 200, 200
  // , 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200
};

// Play sound when device is set in anti-thief mode
void deviceOn() {
  for (int i = 0; i < COUNT_NOTES; i++) {
    tone(buzzerPin, melodyDeviceOn[i], durations[i]);
    delay(durations[i]);
    noTone(buzzerPin);
    delay(50); 
  }
  digitalWrite(buzzerPin, LOW);
}

// Play sound when device is set in sleep mode
void deviceSleepMode() {
  for (int i = 0; i < COUNT_NOTES; i++) {
    tone(buzzerPin, melodyDeviceSleepMode[i], durations[i]);
    delay(durations[i]);
    noTone(buzzerPin);
    delay(50);
  }
  digitalWrite(buzzerPin, LOW);
  
}

// Play sound when bluetooth is connected
void bluetoothConnected() {
  for (int i = 0; i < COUNT_NOTES; i++) {
    tone(buzzerPin, melodyBluetoothConnected[i], durations[i]);
    delay(durations[i]);
    noTone(buzzerPin);
    delay(50);
  }
  digitalWrite(buzzerPin, LOW);
}

// Play sound when bluetooth is disconnected
void bluetoothDisconnected() {
  for (int i = 0; i < COUNT_NOTES; i++) {
    tone(buzzerPin, melodyBluetoothDisconnected[i], durations[i]);
    delay(durations[i]);
    noTone(buzzerPin);
    delay(50);
  }
  digitalWrite(buzzerPin, LOW);
}

// Play sound when NFC card is detected
void nfcDetection() {
  for (int i = 0; i < 2; i++) {
    tone(buzzerPin, 100, 100);
    delay(100);
    noTone(buzzerPin);
    delay(50);
  }
  digitalWrite(buzzerPin, LOW);
}