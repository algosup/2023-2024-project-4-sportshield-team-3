# Client:
- Name: CORIS INNOVATION
- Founded: 2015
- Employees: 90
- Locations: 5 locations : France (Annecy, Grenoble, Lyon, Bourges) & Switzerland (Lausanne)
- Their Services: 
    - 1 in-house Innovation Lab
    - Systems Engineering and Process Engineering
- Key business sectors: Aerospace, automotive, energy, railway, pharmaceuticals, watchmaking
Their Ambition: 
    - Support European industrial players in their innovation, R&D, digitalization and production challenges
    - The development of their team is key to the projects success.
- Website: [Coris Innovation](https://www.corisinnovation.com/)

# PROJECT BRIEF / BACKGROUND INFO
SportShield is an innovative anti-theft device designed for sports equipment, equipped with sensors and actuators to detect movement, activate an alarm, and notify the owner

---

Target Audience:
- Individual users of medium to high-end skis and snowboards.
- Plans to expand to other sports equipment, camping gear, musical instruments, locker rooms, etc.

Product:
- Currently in development phase.

Alarm System:
- Emitting audible signals upon detecting movement with the 6-DoF IMU.
- Moderate-level beeps for slight movements, loud alarm for significant ones.
- Notifications sent to owners via GPRS connectivity.

Physical security Features:
- Multi-layered cable and electromagnetic lock for physical security.
- Cable automatically retracts into the housing and prevents unwinding when locked.

Mobile App :
- Main functions : Activate/deactivate the anti-theft alarm.
- Unlock the device via Bluetooth connectivity.
- Check device localization on a map.

Robustness:
- Waterproof, cold-resistant, and robust against break-in attempts.

---

The Global Project is composed of 3 main parts:
1. The SportShield device
2. The Mobile App
3. The Backend
   1. Firebase for the Database, the User Account Management and the Notifications
   2. The API for the communication between the Device and the Mobile App

The SportShield Device Communicate with the Mobile App via Bluetooth Low Energy (BLE) for the following features: Unlock the device, Activate the Anti-theft function and for the first pairing of the device with the user account.

The Mobile App Communicate with the API and share the User info(Id ans Password) then it received the following information: Device info(Device name and id, GPS Coordinates, Battery level), and the Notifications when a shock is detected.

The SportShield Device can send informations to the API via the HTTP Post Protocol to send the GPS Coordinates and the Battery level every 15 minutes, and to send a notification when a shock is detected.

# Electronics
The Microcontroller is a Xiao BLE Sense nrf52840 from Seeed Studio. It is a small and powerful microcontroller with a built-in Bluetooth Low Energy 5.0 and a 6 Degrees of Freedom Inertial Measurement Unit (6-DoF IMU). It has 11 GPIOs that can be used as UART, SPI, I2C, etc.

Xiao BLE Sense nrf52840
- 2 x 2 x 0,5 cm 
- BLE 5.0 & 6 DoF IMU
- 11 GPIO (UART, SPI, I2C)
- Work Temperature: -40°C ~ +65°C

---
The GNSS PA1010D is a small and powerful GPS module with an integrated antenna. It can be used to get the GPS coordinates of the device.

GNSS PA1010D
- 2,5 x 2,5 x 1 cm
- Integrated antenna
- UART & I2C
- Work Temperature: -40°C ~ +85°C

---
The SIM800L is a small and powerful GSM/2G module with a SIM card holder. It can be used to send HTTP requests to the API to send the GPS coordinates and the battery level, and to send a notification when a shock is detected.

GSM/2G SIM800L Module
- 2,2 x 1,8 x 0,5 cm
- GPRS & HTTP, UART
- SIM Card holder
- With 1NCE SIM card
- Work Temperature: -40°C ~ +85°C

Although this sensor still uses the 2G network, which will no longer be in use by the end of 2025, we are still using it for the development phase, while this one can be easily replaced by a sensor that uses the 4G network.

---
The electromagnet is used to lock and unlock the security cable. It is powered by the device when the user wants to unlock the security cable.

Electromagnet
- 12V, 500mA
- 2,7 x 1,6 x 1,3 cm
- Work Temperature: until 115°C

---
The Buzzer is used to emit audible signals upon detecting movement with the 6-DoF IMU. It emits moderate-level beeps for slight movements, and a loud alarm for significant ones.

Piezoelectric buzzer
- 12V with control circuit oscillator
- ~ 90-100 dB
- Work Temperature: -20°C ~ +70°C
- 

---
The battery is used to power the device. It is recharged via a USB-C port. For the moment the battery can last less than 3 days in normal use, but we are working on the energy management to increase the battery life.

Lithium-Polymer battery
- 5,1 x 3,5 x 0,6 cm
- 3.7V, 1100mAh, 4.1Wh
- Work Temperature: -20°C ~ +60°C

---
The NFC antenna is used to replace the BLE if the user wants to unlock the device without using the mobile app or don't have mich more battery. The user can unlock the device by approaching the NFC antenna with a NFC security card.

NFC antenna
- 5,5 x 4,5 x 0,017 cm
- 13,56MHz frequency
- Work Temperature: -30°C to +85°C

# Software
Here is the software environment used for the development of the SportShield device:

Work environment
- Language : C / C++
- IDE for compilation & upload on the board

Main libraries
- NRF52_MBED_TimerInterrupt V1.4.1
- ArduinoBLE V1.3.6
- Adafruit GPS Library V1.7.4 (instal all)
- Sim800L http connector V1.14.0
- Seeed Arduino LSM6DS3 V2.0.3
- OneWire V2.3.7

## Already implemented features
Connexion to the device
- Allowed to all users by default
- `MAC Address` characteristic is read only, useful for the device pairing with the user account on the mobile app.

Activate / turn off the anti-theft function via Bluetooth
- `Activation` and `Unlock` characteristics are accessible only after the user has sent the right password (written in `Password` BLE characteristic)
- 0 (turn off) or 1 (activate) is sent to the mobile app via BLE characteristic 

Unlock the security cable via Bluetooth
- `Activation` and `Unlock` characteristics are accessible only after the user has sent the right password (written in `Password` BLE characteristic)
- 1 (unlock) is sent to the mobile app via BLE characteristic

Alarm
- 3 light sounds when a light shock is detected
- 5 long high sounds when a strong shock is detected

Send movement notification via GPRS (when a strong shock is detected)
- Route : `http://141.94.244.11:2000/sendNotfication`
- Message in JSON format as follow (example): `{"latitude":"2.894587573","longitude":"6.5467554"}`

Send GPS position and battery level every 15 minutes
- Route: `http://141.94.244.11:2000/updateCoordinate` 
- Message in JSON format as follow (example): `{"latitude":"2.894587573","longitude":"6.5467554","batterie":"3.68"}`

Sleep mode
- GPRS and GPS functionalities are powered only when an information should be sent.
- When the antitheft system is deactivated, and no movements are detected for 5 minutes, then the BLE function is disabled. As soon as a movement is detected, the BLE turns on again.

## Expected Improvements

Battery consumption management
- Improve energy efficiency of the system (e.g. turn on components only when needed, sleep modes management)
- Management of a low battery situation (e.g. skis are secured and electromagnet cannot be powered to release the cable)
- Increase the battery lifespan (e.g. no charge above 80% of Vmax, no discharge under 20%)

Device management with NFC
- NFC is an expected feature for the users, in order to  activate/deactivate the anti-theft system & unlock the cable 
- Via their smartphone and SportShield app (redundant with Bluetooth function, to increase control options for users)

Alarm management and simultaneous actions
- Add the possibility to stop the alarm when it rings, even if the ringing cycle is not finished.
- Permit the alarm to ring while sending http notification to the server.
- Better management of interruptions

Security issues
- Increase the security level to connect to the key features of the system 
- Access to activation/deactivation of the alarm and unlocking of the cable

# KPIs & Reliability Indicators

Minimal functioning rates 
- Shock detection: 99% (1st most critical function)
    - Accuracy of the detection itself, and accuracy of the detection level (small or major movement)
- Unlock: 99% (2nd most critical function)
- Alarm: 98% (perceived quality of the system)
- Shock notification: 95%
- GNSS position acquisition and transmission: 80%

Battery operating time between two charges
- 7 days operating duration (minimal requirement)
- Considering 6 hours activation mode + 18 hours in stand-by (not activated) mode per day

# Other Precisions

- 3 days is what they get for practical use in ambiant temperature, in a cold environment the battery can be longer than in a hot environment
- The aim of this product is to be used for every type of sports equipment(ski, snowboard, surf, bike)
- Rotation and translation of the device on 3 axis, if the product is slowly moved it can’t be detected for the moment
- No update of the firmware made by bluetooth/usb is planned for the moment


---

# Table of Contents

1. Glossary

2. Introduction
2.1 Overview
2.2 Project Definition
2.2.1 Purpose
2.2.2 Scope
2.2.3 Deliverables
2.3 Project Organisation
2.3.1 Project Representatives
2.3.2 Stakeholders
2.3.3 Project Roles
2.3.4 Project Reviewers
2.4 Project Plan
2.4.1 Retro-Planning
2.4.2 Milestones
2.4.3 Resources
2.4.4 Assumptions and Constraints

1. Personas
3.1 Individual Sports Enthusiasts
3.1.1 The Weekend Warrior
3.1.2 The Extreme Sports Adventurer
3.1.3 The Fitness Fanatic
3.2 Professional Athletes and Performers
3.2.1 The Touring Musician
3.2.2 The Competitive Skier
3.3 Outdoor and Travel Enthusiasts
3.3.1 The Global Backpacker: Uses SportShield to protect their backpack and camping gear across different countries and terrains.
3.3.2 The Tech-Savvy Traveler: Looks for smart solutions to safeguard their electronic devices and luggage during their travels.

1. The Uses Cases
4.1 Use Case 1: Pair the Device with the Mobile App.
4.2 Use Case 2: Add a Security Card to the Device.
4.3 Use Case 3: Activate the Anti-Theft Protection using the Mobile App.
4.4 Use Case 4: Activate the Anti-Theft Protection using the Security Card.
4.5 Use Case 5: Deactivate the Anti-Theft Protection and Unlock the Device using the Mobile App.
4.6 Use Case 6: Deactivate the Anti-Theft Protection and Unlock the Device using the Security Card.
4.7 Use Case 7: Emit an Audible Alarm when a Light Shock is Detected.
4.8 Use Case 8: Emit an Audible Alarm and Send a Notification when a Strong Shock is Detected.
4.9 Use Case 9: Send GPS Coordinates and Battery Level to the API.
4.10 Use Case 10: Receive Notifications from the API.
4.11 Use Case 11: Send a Notification when the Battery is Low.
4.12 Use Case 12: Send a Notification when the Battery is Full.
4.13 Use Case 13: Cut the Alarm with the Mobile App.
4.14 Use Case 14: Cut the Alarm with the Security Card
