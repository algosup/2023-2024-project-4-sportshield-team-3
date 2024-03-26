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
  // add descriptors
  PasswordCharacteristic.addDescriptor(PasswordDescriptor);
  NameCharacteristic.addDescriptor(NameDescriptor);
  ActivationCharacteristic.addDescriptor(ActivationDescriptor);
  UnlockCharacteristic.addDescriptor(UnlockDescriptor);
  MACCharacteristic.addDescriptor(MACDescriptor);
  // add the characteristic to the service
  PasswordService.addCharacteristic(PasswordCharacteristic);
  ConfigService.addCharacteristic(NameCharacteristic);
  ConfigService.addCharacteristic(ActivationCharacteristic);
  ConfigService.addCharacteristic(UnlockCharacteristic);
  ConfigService.addCharacteristic(MACCharacteristic);
  // add service
  BLE.addService(PasswordService);
  BLE.addService(ConfigService);
  //  Set the initial value for the characeristic:
  PasswordCharacteristic.writeValue(0);
  NameCharacteristic.writeValue("\n");
  ActivationCharacteristic.writeValue(false);
  UnlockCharacteristic.writeValue(false);
  MACCharacteristic.writeValue(BLE.address());
  //set event handler
  BLE.setEventHandler(BLEConnected, onConnect);
  BLE.setEventHandler(BLEDisconnected, onDisconnect);
  PasswordCharacteristic.setEventHandler(BLEWritten, onWritePassword);
  NameCharacteristic.setEventHandler(BLEWritten, onWriteName);
  NameCharacteristic.setEventHandler(BLERead, onReadName);
  ActivationCharacteristic.setEventHandler(BLEWritten, onWriteActivation);
  ActivationCharacteristic.setEventHandler(BLERead, onReadActivation);
  UnlockCharacteristic.setEventHandler(BLEWritten, onWriteUnlock);
  // Start advertising
  BLE.advertise();
}

// Detect when the bluetooth is connected
void onConnect(BLEDevice central) {
  Serial.print("Connected to ");
  Serial.println(central.address());
  Serial.println(BLE.address());
  digitalWrite(LEDB, LOW);
  bluetoothConnected();
}

// Detect when the bluetooth is disconnected
void onDisconnect(BLEDevice central) {
  Serial.print(F("Disconnected from central: "));
  Serial.println(central.address());
  isAuthenticate = false;
  digitalWrite(LEDB, HIGH);
  bluetoothDisconnected();
}


void onWritePassword(BLEDevice central, BLECharacteristic characteristic) {
  const int motDePasseAttendu = 13330;
  short int value = PasswordCharacteristic.value();
  Conversion(value);
  isAuthenticate = (value == motDePasseAttendu);
  Serial.println(isAuthenticate ? "successful authentication" : "wrong password");
}

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

void onReadName(BLEDevice central, BLECharacteristic characteristic) {
  Serial.println("CALLBACK READ");
  Serial.println(isAuthenticate);
  if (isAuthenticate) {
    NameCharacteristic.writeValue(Config.Name);
  } else {
    NameCharacteristic.writeValue("\n");
  }
}

void onWriteActivation(BLEDevice central, BLECharacteristic characteristic) {
  if (isAuthenticate) {
    Config.isActivate = ActivationCharacteristic.value();
    if (Config.isActivate != 0) {
      Serial.println("Alarme enabled");
      digitalWrite(SIM800_DTR_PIN, LOW);  // Put in normal mode
      delay(100);
      sim800l->setPowerMode(NORMAL);  //  Set normal functionnality mode
    } else {
      Serial.print("Désactivation");
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

void onWriteUnlock(BLEDevice central, BLECharacteristic characteristic) {
  if (isAuthenticate) {
    // Activate electromagnet
    Serial.println("Unlock");
    digitalWrite(aimantPin, HIGH);
    delay(2000);
    digitalWrite(aimantPin, LOW);
  }
}