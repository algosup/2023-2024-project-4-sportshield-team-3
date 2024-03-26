// This file stand for all movement of the device (axes)

void imu_setup(void) {
  if (imu.begin() != 0) {
    Serial.println("Device error");
  } else {
    Serial.println("Accelerometer launched");
  }
}

void PulseBuzzer(int repetitions, unsigned long durationOn, unsigned long durationOff) {
  static int buzzerState = LOW;
  unsigned long currentMillis = millis();

  if (currentRep < repetitions) {
    if (currentMillis - previousMillis >= (buzzerState == LOW ? durationOn : durationOff)) {
      digitalWrite(buzzerPin, buzzerState = !buzzerState);
      previousMillis = currentMillis;
      if (!buzzerState) currentRep++;
    }
  } else {
    // Reset variables after performing all repetitions
    currentRep = 0;
    previousMillis = 0;
    MotionSmall = false;
    MotionBig = false;
  }
}

// Provides the absolute difference in acceleration between consecutive calls, helping to monitor changes in motion over time.
float getMotionData() {
  static float previousAcceleration = 0;
  float accelX = imu.readFloatAccelX();
  float accelY = imu.readFloatAccelY();
  float accelZ = imu.readFloatAccelZ();

  float currentAcceleration = sqrt(accelX * accelX + accelY * accelY + accelZ * accelZ) * 100;
  float MotionDataerence = currentAcceleration - previousAcceleration;  // Calculate the acceleration difference
  previousAcceleration = currentAcceleration;

  return fabs(MotionDataerence);  //  Returns a value always positive
}

float getRotationData() {
  static float previousRotation = 0;

  // Read gyroscope values
  float gyroX = imu.readFloatGyroX();
  float gyroY = imu.readFloatGyroY();
  float gyroZ = imu.readFloatGyroZ();

  float currentRotation = sqrt(gyroX * gyroX + gyroY * gyroY + gyroZ * gyroZ);  // Calculate the current rotation based on gyroscope readings
  float RotationDataerence = currentRotation - previousRotation;                // Calculate the difference in rotation
  previousRotation = currentRotation;                                           // Update the previous rotation value

  return fabs(RotationDataerence);
}