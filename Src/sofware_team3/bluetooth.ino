BLEService PasswordService("19B10000-E8F2-537E-4F6C-D104768A1213");  // Bluetooth® Low Energy Service
BLEService ConfigService("19B10000-E8F2-537E-4F6C-D104768A1214");

BLEShortCharacteristic PasswordCharacteristic("19B10000-E8F2-537E-4F6C-D104768A1213", BLEWrite);  // Bluetooth® Low Energy Characteristic
BLEStringCharacteristic NameCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite, 20);
BLEStringCharacteristic MACCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1217", BLERead, 20);
BLEBooleanCharacteristic ActivationCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1215", BLERead | BLEWrite);
BLEBooleanCharacteristic UnlockCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1216", BLEWrite);

BLEDescriptor PasswordDescriptor("2901", "Password");  // Bluetooth® Low Energy Descriptor
BLEDescriptor NameDescriptor("2901", "Name");
BLEDescriptor ActivationDescriptor("2901", "Activation");
BLEDescriptor UnlockDescriptor("2901", "Unlock");
BLEDescriptor MACDescriptor("2901", "MAC Address");

bool BLE_activated = true;  //true if the bluetooth is activated
uint32_t tim_connec = 0;    // time in ms or we start to activate the bluetooth following a detection of movement
