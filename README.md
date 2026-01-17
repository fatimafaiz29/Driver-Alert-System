# 🚗 Driver Drowsiness and Speed Monitoring System 💤

This project detects driver drowsiness and over-speeding conditions to improve road safety.

---

## 🔹 Features

| Feature | Description |
|---------|-------------|
| 👁️ Driver Sleep Detection | Monitors driver alertness and triggers alert when drowsiness is detected |
| ⚡ Over-speed Monitoring | Detects when vehicle speed exceeds safe thresholds |
| 🌙 Day/Night Modes | Different speed limits for day (100) and night (90) driving |
| 🔘 Manual Override | Pushbutton to reset or manually turn off the system |
| 💡 RGB LED Status | Green = Normal, Red = Sleep Alert, Blue = Speed Alert |
| 📺 LCD Display | Real-time system status messages |
| 💦 Water Pump | Sprinkler system to wake sleeping drivers |

---

## 🔹 Technologies Used

- **Microcontroller**: Arduino Uno
- **Programming**: Embedded C / Arduino IDE
- **Simulation Platform**: TinkerCAD
- **Sensors**: Ultrasonic / IR Eye Blink / LDR / Hall Effect Sensor

---

## 📁 Project Versions

This project is implemented in **two versions**. Both use the **same logic**, but different sensors due to simulation limitations.

---

### 1️⃣ Tinkercad Simulation Version (`Tinkercad_Code.ino`)

**File**: `tinkercad-simulation/Tinkercad_Code.ino`

**🔗 Live Simulation**: [Run on Tinkercad](https://www.tinkercad.com/things/1qmIEP0ASY6-driver-alert-system)

**Sensors Used**:
| Sensor | Purpose |
|--------|---------|
| Ultrasonic Sensor (HC-SR04) | Simulates eye blink/drowsiness detection |
| Potentiometer (250kΩ) | Simulates vehicle speed input |
| LDR (Light Dependent Resistor) | Day/night detection |

**Components Required**:
| Qty | Component |
|-----|-----------|
| 1 | Arduino Uno R3 |
| 1 | Ultrasonic Distance Sensor (HC-SR04) |
| 1 | LCD 16x2 with I2C (MCP23008, Address: 0x20) |
| 1 | Piezo Buzzer |
| 1 | RGB LED |
| 1 | 250kΩ Potentiometer |
| 1 | LDR (Photoresistor) |
| 1 | Pushbutton |
| 1 | DPDT Relay |
| 1 | DC Motor (Water Pump) |
| 1 | 9V Battery |
| 1 | 10kΩ Resistor |
| 2 | 220Ω Resistor |
| 1 | 1kΩ Resistor |

**Pin Configuration**:
| Pin | Component | Function |
|-----|-----------|----------|
| A0 | Potentiometer | Speed input (0-1023) |
| A1 | LDR | Light level sensing |
| 2 | Ultrasonic Trigger | Distance measurement |
| 3 | Ultrasonic Echo | Distance measurement |
| 5 | Pushbutton | Manual reset |
| 6 | RGB LED (Green) | Status indicator |
| 7 | RGB LED (Blue) | Status indicator |
| 8 | RGB LED (Red) | Status indicator |
| 9 | Piezo Buzzer | Audio alerts |
| 10 | Relay/Pump | Water sprayer control |

**Purpose**: Used for simulation and logic verification in TinkerCAD where IR eye-blink and Hall sensors are not available.

---

### 2️⃣ Practical Hardware Implementation Version (`practical_code.ino`)

**File**: `practical-implementation/practical_code.ino`

**Sensors Used**:
| Sensor | Purpose |
|--------|---------|
| IR Eye Blink Sensor | Detects eye closure/blinking (mounted on glasses) |
| Hall Effect Sensor (A3144) | Speed detection using magnetic field |
| LDR (Light Dependent Resistor) | Day/night detection |

**Components Required**:
| Qty | Component |
|-----|-----------|
| 1 | Arduino Uno R3 |
| 1 | IR Eye Blink Sensor |
| 1 | Hall Effect Sensor (A3144) |
| 1 | LCD 16x2 with I2C |
| 1 | Piezo Buzzer |
| 1 | RGB LED |
| 1 | LDR (Photoresistor) |
| 1 | Pushbutton |
| 1 | DC Motor (Water Pump) |
| 1 | 9V Battery |
| 1 | Resistors (as needed) |

**Pin Configuration**:
| Pin | Component | Function |
|-----|-----------|----------|
| 2 | IR Eye Sensor | Eye blink detection |
| 3 | Hall Effect Sensor | Speed detection |
| 5 | Pushbutton | Manual reset |
| 6 | RGB LED (Green) | Status indicator |
| 7 | RGB LED (Blue) | Status indicator |
| 8 | RGB LED (Red) | Status indicator |
| 9 | Piezo Buzzer | Audio alerts |
| 10 | Pump | Water sprayer control |
| A1 | LDR | Light sensing |

**Purpose**: Real-world implementation using actual sensors and hardware components.

---

## ⚠️ Important Notes

### Why Two Different Versions?

Both versions use the **same logic**, but different sensors are used due to simulation platform limitations.

---

### TinkerCAD Simulation Version (`Tinkercad_Code.ino`)

```cpp
// TINKERCAD SIMULATION VERSION
// Located at: tinkercad-simulation/Tinkercad_Code.ino
// Ultrasonic sensor is used to simulate eye-blink detection
// Potentiometer is used to simulate vehicle speed
// A relay-controlled DC motor is used to simulate a water pump
```

**Reason**: TinkerCAD doesn't have IR Eye Blink Sensor or Hall Effect Sensor components, so:
- **Ultrasonic Sensor** simulates eye-blink detection by measuring distance
- **Potentiometer** simulates vehicle speed input (0-1023 values)
- **DC Motor** simulates the water pump mechanism

---

### Practical Implementation Version (`practical_code.ino`)

```cpp
// PRACTICAL IMPLEMENTATION VERSION
// Located at: practical-implementation/practical_code.ino
// Driver drowsiness is detected using an IR Eye Blink Sensor
// Vehicle speed is monitored using a Hall Effect Sensor
// A relay-controlled DC water pump is used to alert the driver
```

**Reason**: Real-world hardware requires actual sensors for accurate detection:
- **IR Eye Blink Sensor** (mounted on glasses) provides accurate drowsiness detection
- **Hall Effect Sensor (A3144)** detects vehicle speed using magnetic field
- **DC Water Pump** with relay for actual driver alert (water spray)

---

| Feature | TinkerCAD Version | Practical Version |
|---------|-------------------|-------------------|
| Drowsiness Detection | Ultrasonic Sensor (simulates) | IR Eye Blink Sensor (real) |
| Speed Detection | Potentiometer (simulates) | Hall Effect Sensor (real) |
| Alert Mechanism | DC Motor (simulates pump) | DC Water Pump (real) |
| Accuracy | Simulation only | Real-world deployment |

---

## 🎓 Academic Use

This project is suitable for:
- ✨ Mini projects
- 🎓 Diploma / B.Tech projects
- 🚗 Driver safety system demonstrations

---

## 📁 Project Files

```
Driver-Alert-System/
├── Circuit Diagram.png                    - Complete circuit schematic
├── Ckt Diagram.pdf                        - PDF circuit diagram
├── Component List.csv                     - Bill of materials
├── PPT .pptx                              - Project presentation
├── README.md                              - This file
├── Screen Recording...mov                 - Demo video
├── tinkercad-simulation/
│   ├── Tinkercad Circuit Diagram.png      - Tinkercad circuit schematic
│   ├── Tinkercad Ckt Diagram.pdf          - Tinkercad circuit PDF
│   ├── Tinkercad Component List.csv       - Tinkercad components
│   ├── Tinkercad_Code.ino                 - TinkerCAD simulation code
│   └── tinkercad_pin_configuration.jpg    - Tinkercad pin diagram
└── practical-implementation/
    ├── practical_code.ino                 - Practical hardware implementation
    ├── practical_components.jpg           - Practical hardware photo
    └── practical_pin_configuration.jpg    - Practical pin diagram
```

---

## 👩‍💻 Author

**Fatima Faiz**

---

## 📜 License

This project is open-source and free to use for academic purposes.

---

**Stay Alert, Stay Safe! 🛡️**

