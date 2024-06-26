// This file stand for the bluetooth communication with other device

// Prepare the setup for Bluetooth Low Energie
void ble_setup(void) {
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1)  // Set a reset in this case? risk of card crash?
      ;
  }
  //  Set advertised local name and service UUID:
  BLE.setLocalName("DeviceTeam3");
  BLE.setDeviceName("DeviceTeam3");
  BLE.setAdvertisedService(PasswordService);
  //  Add descriptors
  PasswordCharacteristic.addDescriptor(PasswordDescriptor);
  NameCharacteristic.addDescriptor(NameDescriptor);
  ActivationCharacteristic.addDescriptor(ActivationDescriptor);
  LockUnlockCharacteristic.addDescriptor(LockUnlockDescriptor);
  MACCharacteristic.addDescriptor(MACDescriptor);
  StopAlarmCharacteristic.addDescriptor(StopAlarmDescriptor);
  //  Add the characteristic to the service
  PasswordService.addCharacteristic(PasswordCharacteristic);
  ConfigService.addCharacteristic(NameCharacteristic);
  ConfigService.addCharacteristic(ActivationCharacteristic);
  ConfigService.addCharacteristic(LockUnlockCharacteristic);
  ConfigService.addCharacteristic(MACCharacteristic);
  ConfigService.addCharacteristic(StopAlarmCharacteristic);
  //  Add service
  BLE.addService(PasswordService);
  BLE.addService(ConfigService);
  //  Set the initial value for the characeristic:
  PasswordCharacteristic.writeValue(0);
  NameCharacteristic.writeValue("\n");
  ActivationCharacteristic.writeValue(false);
  LockUnlockCharacteristic.writeValue(false);
  MACCharacteristic.writeValue(BLE.address());
  StopAlarmCharacteristic.writeValue(0);
  //  Set unique paraible device
  BLE.setPairable(ONCE);
  //  Set event handler
  BLE.setEventHandler(BLEConnected, onConnect);
  BLE.setEventHandler(BLEDisconnected, onDisconnect);
  PasswordCharacteristic.setEventHandler(BLEWritten, onWritePassword);
  NameCharacteristic.setEventHandler(BLEWritten, onWriteName);
  NameCharacteristic.setEventHandler(BLERead, onReadName);
  ActivationCharacteristic.setEventHandler(BLEWritten, onWriteActivation);
  ActivationCharacteristic.setEventHandler(BLERead, onReadActivation);
  LockUnlockCharacteristic.setEventHandler(BLEWritten, onWriteLockUnlock);
  StopAlarmCharacteristic.setEventHandler(BLEWritten, stopPulseBuzzer);
  //  Start advertising
  BLE.advertise();
}

//  Detect when the bluetooth is connected
void onConnect(BLEDevice central) {
    String tmp = central.address();
  
  if (uniqueUser == "") {
    uniqueUser = tmp;
  }
   if (uniqueUser == tmp) {
    Serial.print("Connected to ");
    Serial.println(central.address());
    Serial.println(uniqueUser);
    Serial.println(BLE.address());
    digitalWrite(LEDB, LOW);
    bluetoothConnected();
  }
  else {
    Serial.println("Connection attempt from untrusted device.");
  }
}

//  Detect when the bluetooth is disconnected
void onDisconnect(BLEDevice central) {
  Serial.print(F("Disconnected from central: "));
  Serial.println(central.address());
  isAuthenticate = false;
  digitalWrite(LEDB, HIGH);
  bluetoothDisconnected();
}

//  Detect when password is send
void onWritePassword(BLEDevice central, BLECharacteristic characteristic) {
  const int motDePasseAttendu = 13330;
  short int value = PasswordCharacteristic.value();
  Conversion(value);
  isAuthenticate = (value == motDePasseAttendu);
  Serial.println(value);
  Serial.println(isAuthenticate ? "successful authentication" : "wrong password");
}

// Write the new name for the device
void onWriteName(BLEDevice central, BLECharacteristic characteristic) {
  if (isAuthenticate) {
    Config.Name = NameCharacteristic.value();
    String value = NameCharacteristic.value();
    Serial.print("Written name : ");
    Serial.println(value);
  } else {
    NameCharacteristic.writeValue("\n");
  }
}

//  Read the name of the device
void onReadName(BLEDevice central, BLECharacteristic characteristic) {
  Serial.println("CALLBACK READ");
  Serial.println(isAuthenticate);
  if (isAuthenticate) {
    NameCharacteristic.writeValue(Config.Name);
  } else {
    NameCharacteristic.writeValue("\n");
  }
}

//  
void onWriteActivation(BLEDevice central, BLECharacteristic characteristic) {
  if (isAuthenticate) {
    Config.isActivate = ActivationCharacteristic.value();
    if (Config.isActivate != 0) {
      Serial.println("Alarme enabled");
      digitalWrite(SIM800_DTR_PIN, LOW);  // Put in normal mode
      delay(100);
      sim800l->setPowerMode(NORMAL);  //  Set normal functionnality mode
    } else {
      Serial.println("Désactivation");
      sim800l->setPowerMode(MINIMUM);      // Set minimum functionnality mode
      digitalWrite(SIM800_DTR_PIN, HIGH);  // Put in sleep mode
    }
  } else {
    ActivationCharacteristic.writeValue(Config.isActivate);
  }
}

void onReadActivation(BLEDevice central, BLECharacteristic characteristic) {
  // Serial.println("CALLBACK READ");
  // Serial.println(isAuthenticate);
  ActivationCharacteristic.writeValue(Config.isActivate);
}

// Permit to lock or unlock the cable 
void onWriteLockUnlock(BLEDevice central, BLECharacteristic characteristic) {
  if (isAuthenticate && isLock) {
    // Activate electromagnet
    Serial.println("Unlock");
    digitalWrite(aimantPin, LOW);
    isLock = false;
  }
  else if (isAuthenticate && !isLock){
    Serial.println("Lock");
    digitalWrite(aimantPin, HIGH);
    isLock = true;
  }
}

// Stop the alarm during the function
void stopPulseBuzzer(BLEDevice central, BLECharacteristic characteristic) {
  if (isAuthenticate) {
    stopBuzzer = true;
    Serial.println("Alarm desactivated");
  }
}