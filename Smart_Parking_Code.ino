#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin definitions
const int irSensor1 = 2; // Before gate (Entry)
const int irSensor2 = 3; // After gate (Exit)
const int redLED = 6;
const int greenLED = 7;
const int totalSlots = 4;

// Servo setup
Servo gateServo;
const int servoPin = 9;

// Parking counter
int parkedCars = 0;

// --- Gate functions ---
void gateLock() {
  gateServo.write(90); // Closed
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
}

void openGate() {
  gateServo.write(0); // Open
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, HIGH);
}

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Parking");

  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  gateServo.attach(servoPin);
  gateLock();

  delay(2000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Slot Left: ");
  lcd.print(totalSlots - parkedCars);
  lcd.print("   "); // Clear extra digits

  int sensor1State = digitalRead(irSensor1);
  int sensor2State = digitalRead(irSensor2);

  // --- Car entering ---
  if (sensor1State == LOW) {
    delay(100); // Debounce
    if (parkedCars < totalSlots) {
      openGate();
      lcd.setCursor(0, 1);
      lcd.print("Car Entering...   ");

      // Wait for sensor2 to trigger
      while (digitalRead(irSensor2) == HIGH);
      delay(300);
      while (digitalRead(irSensor2) == LOW);
      delay(1000);
      parkedCars++;
      gateLock();      
      delay(500);
      lcd.clear();
    } else {
      lcd.setCursor(0, 1);
      lcd.print("No Space Left");
      delay(2000);
      lcd.clear();
    }
  }

  // --- Car exiting ---
  if (sensor2State == LOW) {
    delay(100); // Debounce
    if (parkedCars > 0) {
      openGate();
      lcd.setCursor(0, 1);
      lcd.print("Car Exiting...    ");

      // Wait for sensor1 to trigger
      while (digitalRead(irSensor1) == HIGH);
      delay(300);
      while (digitalRead(irSensor1) == LOW);
      delay(1000);
      parkedCars--;
      gateLock();      
      delay(500);
      lcd.clear();
    }
  }

  delay(100);
}
