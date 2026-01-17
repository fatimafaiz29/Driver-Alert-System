// PRACTICAL HARDWARE IMPLEMENTATION
// IR Eye Blink Sensor + Hall Effect Sensor
// Driver Drowsiness and Speed Monitoring System

#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

// -------- Pin Definitions --------
#define IR_EYE_PIN 2
#define HALL_PIN 3
#define BUTTON_PIN 5

#define LED_GREEN 6
#define LED_BLUE  7
#define LED_RED   8

#define BUZZER 9
#define PUMP 10

#define LDR_PIN A1

// -------- Thresholds --------
#define SLEEP_TIME 3000  // 3 seconds

// -------- Variables --------
unsigned long sleepTimer = 0;
bool sleepDetected = false;

void setup() {
  pinMode(IR_EYE_PIN, INPUT);
  pinMode(HALL_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  pinMode(BUZZER, OUTPUT);
  pinMode(PUMP, OUTPUT);

  Serial.begin(9600);
  lcd.begin(16, 2);

  lcd.print("Driver System");
  delay(1500);
  lcd.clear();
}

void loop() {

  // -------- Manual OFF --------
  if (digitalRead(BUTTON_PIN) == LOW) {
    noTone(BUZZER);
    digitalWrite(PUMP, LOW);

    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_RED, LOW);

    lcd.setCursor(0, 0);
    lcd.print("STATUS: RESET ");
    lcd.setCursor(0, 1);
    lcd.print("MANUAL OFF    ");

    Serial.println("Manual OFF Activated");
    delay(800);
    return;
  }

  // -------- Eye Blink Detection --------
  if (digitalRead(IR_EYE_PIN) == LOW) {  // Eye closed
    if (sleepTimer == 0)
      sleepTimer = millis();

    if (millis() - sleepTimer >= SLEEP_TIME)
      sleepDetected = true;
  } else {
    sleepTimer = 0;
    sleepDetected = false;
  }

  // -------- Sleep Alert --------
  if (sleepDetected) {
    tone(BUZZER, 1000);
    digitalWrite(PUMP, HIGH);

    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, LOW);

    lcd.setCursor(0, 0);
    lcd.print("STATUS: SLEEP ");
    lcd.setCursor(0, 1);
    lcd.print("ALERT !!!     ");

    Serial.println("DROWSINESS DETECTED");
  }

  // -------- Normal State --------
  else {
    noTone(BUZZER);
    digitalWrite(PUMP, LOW);

    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_RED, LOW);

    lcd.setCursor(0, 0);
    lcd.print("STATUS: NORMAL");
    lcd.setCursor(0, 1);
    lcd.print("DRIVE SAFE   ");

    Serial.println("Normal Driving");
  }

  delay(200);
}
