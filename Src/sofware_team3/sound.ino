const byte COUNT_NOTES = 24;
int frequenciesOn[COUNT_NOTES] = {
  262, 294, 330, 349, 392, 440, 494, 523,
  523, 494, 440, 392, 349, 330, 294, 262,
  262, 294, 330, 349, 392, 440, 494, 523
};

int frequenciesOff[COUNT_NOTES] = {
  200, 150, 130, 110, 100, 80, 70, 60, 50, 40, 30, 20,
  200, 150, 130, 110, 100, 80, 70, 60, 50, 40, 30, 20
};

int durations[COUNT_NOTES] = {
  200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200,
  200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200
};

void deviceOn() {
  for (int i = 0; i < COUNT_NOTES; i++) {
    tone(buzzerPin, frequenciesOn[i], durations[i]);
    delay(durations[i]);
    noTone(buzzerPin);
    delay(50); 
  }
  digitalWrite(buzzerPin, LOW);
}

void deviceOff() {
  for (int i = 0; i < COUNT_NOTES; i++) {
    tone(buzzerPin, frequenciesOff[i], durations[i]);
    delay(durations[i]);
    noTone(buzzerPin);
    delay(50); // Add a small delay between notes
  }
  digitalWrite(buzzerPin, LOW);
  
}