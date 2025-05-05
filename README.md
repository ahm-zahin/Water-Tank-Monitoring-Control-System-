# 💧 Water Tank Monitoring System (Arduino Based)

This project is an **Arduino-based automatic water level controller and monitoring system**. It uses three water level sensors to detect the tank’s level and controls a motor, LED, and buzzer accordingly.

## 🛠️ Features

- **Three Level Detection:** High, Mid, and Low
- **Motor Control:** Turns on/off based on tank level
- **LED Indicator:**
  - Blinks when water level is mid
  - Solid ON when water level is low
- **Buzzer Alert:**
  - Blinks along with LED when water level is critical
  - Solid ON when tank is empty
- **Failsafe Logic:** Motor stops when tank is full

## 🧠 Logic Table

| Water Level           | Motor | LED        | Buzzer     |
|-----------------------|--------|------------|------------|
| High + Mid + Low      | OFF    | OFF        | OFF        |
| Mid + Low             | ON     | Blinking   | OFF        |
| Low Only              | ON     | Blinking   | Blinking   |
| Empty (No Water)      | ON     | ON         | ON         |

## ⚡ Circuit Connections

| Arduino Pin | Component         |
|-------------|-------------------|
| D7          | High Level Sensor |
| D6          | Mid Level Sensor  |
| D5          | Low Level Sensor  |
| D3          | Motor Relay/Pump  |
| D2          | LED Indicator     |
| D10         | Buzzer            |

> Note: High signal (5V) on level pins means water is present at that level.

## 🔁 Flow Overview

1. When water level is full → Motor stays OFF
2. As water decreases:
   - Mid level: LED blinks
   - Low level: LED & Buzzer blink
   - Empty: All ON to indicate danger

## 📷 Screenshots (Optional)
_Add a picture or video link of your hardware setup here._

## 📦 Requirements

- Arduino UNO or compatible board
- 3x Water level sensors (or conductive probes)
- Buzzer
- LED
- Relay module for motor
- Jumper wires and breadboard

## 🚀 Getting Started

1. Upload the code from `main.ino` to your Arduino board.
2. Connect the components as per the circuit table.
3. Power it up and test by simulating water levels using jumper wires or actual probes.

## 🧑‍💻 Author

**Zahin Ahmed**  
B.Sc. in Mechatronics Engineering  
Passionate about embedded systems, automation, and control.

---
