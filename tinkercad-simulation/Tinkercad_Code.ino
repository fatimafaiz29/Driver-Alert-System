#include <Adafruit_LiquidCrystal.h> 

  

// -------- LCD -------- 

Adafruit_LiquidCrystal lcd(0); 

  

// -------- Ultrasonic -------- 

#define TRIG_PIN 2 

#define ECHO_PIN 3 

  

// -------- Inputs -------- 

#define BUTTON_PIN 5 

#define POT_PIN A0 

#define LDR_PIN A1 

  

// -------- Outputs -------- 

#define BUZZER 9 

#define PUMP 10 

  

// -------- RGB LED -------- 

#define LED_GREEN 6 

#define LED_BLUE  7 

#define LED_RED   8 

  

// -------- Thresholds -------- 

#define EYE_DIST 10          // cm (LESS than this = sleep) 

#define SLEEP_TIME 3000      // 3 seconds 

#define DAY_SPEED 100 

#define NIGHT_SPEED 90 

  

// -------- Variables -------- 

unsigned long sleepTimer = 0; 

bool sleepDetected = false; 

  

// -------- Ultrasonic Read -------- 

long getDistance() { 

  digitalWrite(TRIG_PIN, LOW); 

  delayMicroseconds(2); 

  digitalWrite(TRIG_PIN, HIGH); 

  delayMicroseconds(10); 

  digitalWrite(TRIG_PIN, LOW); 

  

  long duration = pulseIn(ECHO_PIN, HIGH, 25000); 

  if (duration == 0) return -1; 

  return duration * 0.034 / 2; 

} 

  

// -------- Setup -------- 

void setup() { 

  pinMode(TRIG_PIN, OUTPUT); 

  pinMode(ECHO_PIN, INPUT); 

  pinMode(BUTTON_PIN, INPUT_PULLUP); 

  

  pinMode(BUZZER, OUTPUT); 

  pinMode(PUMP, OUTPUT); 

  

  pinMode(LED_GREEN, OUTPUT); 

  pinMode(LED_BLUE, OUTPUT); 

  pinMode(LED_RED, OUTPUT); 

  

  Serial.begin(9600);   // 🔥 SERIAL START 

  Serial.println("=== Driver Safety System Started ==="); 

  

  lcd.begin(16, 2); 

  lcd.print("Driver Alert System"); 

  delay(1500); 

  lcd.clear(); 

} 

  

// -------- Loop -------- 

void loop() { 

  

  // ---- Manual OFF ---- 

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

  

    Serial.println("MANUAL OFF pressed"); 

    delay(800); 

    return; 

  } 

  

  // ---- Read Sensors ---- 

  long distance = getDistance(); 

  int speedVal = analogRead(POT_PIN); 

  int lightVal = analogRead(LDR_PIN); 

  

  bool night = (lightVal < 500); 

  int speedLimit = night ? NIGHT_SPEED : DAY_SPEED; 

  

  // ---- SERIAL DEBUG OUTPUT ---- 

  Serial.print("Distance: "); 

  if (distance == -1) Serial.print("No Echo"); 

  else { 

    Serial.print(distance); 

    Serial.print(" cm"); 

  } 

  

  Serial.print(" | Speed: "); 

  Serial.print(speedVal); 

  

  Serial.print(" | Mode: "); 

  Serial.print(night ? "NIGHT" : "DAY"); 

  

  Serial.print(" | Button: "); 

  Serial.print(digitalRead(BUTTON_PIN) == LOW ? "PRESSED" : "RELEASED"); 

  

  // ---- Sleep Logic (OLD WORKING STYLE) ---- 

  if (distance != -1 && distance < EYE_DIST) { 

    if (sleepTimer == 0) 

      sleepTimer = millis(); 

  

    if (millis() - sleepTimer >= SLEEP_TIME) { 

      sleepDetected = true; 

    } 

  } else { 

    sleepTimer = 0; 

    sleepDetected = false; 

  } 

  

  Serial.print(" | Sleep: "); 

  Serial.println(sleepDetected ? "YES" : "NO"); 

  

  // ---- SLEEP ALERT ---- 

  if (sleepDetected) { 

    digitalWrite(LED_RED, HIGH); 

    digitalWrite(LED_GREEN, LOW); 

    digitalWrite(LED_BLUE, LOW); 

  

    tone(BUZZER, 1000); 

    digitalWrite(PUMP, HIGH); 

  

    lcd.setCursor(0, 0); 

    lcd.print("STATUS: SLEEP "); 

    lcd.setCursor(0, 1); 

    lcd.print("ALERT !!!     "); 

  } 

  

  // ---- OVER SPEED ---- 

  else if (speedVal > speedLimit) { 

    digitalWrite(LED_BLUE, HIGH); 

    digitalWrite(LED_GREEN, LOW); 

    digitalWrite(LED_RED, LOW); 

  

    digitalWrite(PUMP, LOW); 

  

    if (night) 

      tone(BUZZER, 2000); 

    else 

      tone(BUZZER, 1200); 

  

    lcd.setCursor(0, 0); 

    lcd.print("STATUS: SPEED "); 

    lcd.setCursor(0, 1); 

    lcd.print(night ? "NIGHT ALERT  " : "DAY ALERT    "); 

  } 

  

  // ---- NORMAL ---- 

  else { 

    digitalWrite(LED_GREEN, HIGH); 

    digitalWrite(LED_BLUE, LOW); 

    digitalWrite(LED_RED, LOW); 

  

    noTone(BUZZER); 

    digitalWrite(PUMP, LOW); 

  

    lcd.setCursor(0, 0); 

    lcd.print("STATUS: NORMAL"); 

    lcd.setCursor(0, 1); 

    lcd.print("DRIVE SAFE   "); 

  } 

  

  delay(300); 

} 

 