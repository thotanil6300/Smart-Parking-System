 Smart Parking System 

 Project Overview

The Smart Parking System is an IoT-based mini project developed to automate and monitor a parking area.

The system uses IR sensors to detect vehicles at the entrance and exit, a servo motor to control the parking gate, and an I2C LCD to display the parking status.

 Objectives

- Automate the parking entrance gate.
- Detect vehicle entry and exit.
- Keep track of the number of parked vehicles.
- Display parking information on an LCD.
- Indicate the gate status using red and green LEDs.
- Make parking management simple and efficient.

Components Used

- Arduino UNO
- 2 × IR Sensors
- Servo Motor
- 16×2 I2C LCD
- Red LED
- Green LED
- Jumper Wires
- Breadboard
- USB Cable / Power Supply

Working Principle

1. The entry IR sensor detects a vehicle approaching the parking gate.
2. The system checks the available parking slots.
3. If a slot is available, the servo motor opens the gate.
4. The green LED indicates that the gate is open.
5. The LCD displays the parking status.
6. When a vehicle leaves, the exit IR sensor detects it.
7. The number of occupied and available slots is updated.
8. When the parking area is full, the gate remains closed and the red LED indicates the closed/full condition.

 Main Connections

- Entry IR Sensor → Arduino digital input
- Exit IR Sensor → Arduino digital input
- Servo Motor → Arduino digital output
- I2C LCD → Arduino I2C pins
- Red LED → Arduino digital output
- Green LED → Arduino digital output

 Software Used

- Arduino IDE
- Arduino C/C++ programming
- Tinkercad for circuit simulation/prototyping

Project Files

- `Smart_Parking_Code.ino` – Main Arduino program.

 Features

- Automatic gate control
- Vehicle entry and exit detection
- Parking slot monitoring
- LCD status display
- LED gate indication
- Simple and low-cost implementation

 Project Type

**IoT Mini Project – Smart Parking System**
