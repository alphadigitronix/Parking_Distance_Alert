# 🅿️ Parking Distance Alert Using Arduino UNO

**ADS Arduino Inventor Kit**

## 📌 Abstract

The **Parking Distance Alert** is an Arduino-based mini project that helps demonstrate a vehicle parking assistance system.

An **HC-SR04 Ultrasonic Sensor** continuously measures the distance between the sensor and a nearby object.

Depending on the measured distance, the system provides visual warnings using **Green, Yellow, and Red LEDs** and an audible warning using a **buzzer**.

As the object moves closer to the sensor, the warning level increases.

---

## 🎯 Objective

To build a simple parking assistance prototype that measures object distance and provides different warning indications according to how close the object is.

---

## 🧰 Components Required

| Component                 |    Quantity |
| ------------------------- | ----------: |
| Arduino UNO               |           1 |
| HC-SR04 Ultrasonic Sensor |           1 |
| Green LED                 |           1 |
| Yellow LED                |           1 |
| Red LED                   |           1 |
| Buzzer                    |           1 |
| 330Ω Resistors            |           3 |
| Breadboard                |           1 |
| Jumper Wires              | As required |
| USB Cable                 |           1 |

---

## 🔌 Component Connections

### HC-SR04 Ultrasonic Sensor

| HC-SR04 | Arduino UNO |
| ------- | ----------- |
| VCC     | 5V          |
| TRIG    | D9          |
| ECHO    | D10         |
| GND     | GND         |

### LED Indicators

| LED                  | Arduino UNO     |
| -------------------- | --------------- |
| Green LED Anode (+)  | D4 through 330Ω |
| Yellow LED Anode (+) | D5 through 330Ω |
| Red LED Anode (+)    | D6 through 330Ω |
| All LED Cathodes (−) | GND             |

### Buzzer

| Buzzer       | Arduino UNO |
| ------------ | ----------- |
| Positive (+) | D8          |
| Negative (−) | GND         |

---

## 🔄 System Flow

**HC-SR04 → Arduino UNO → Distance Calculation → LEDs + Buzzer**

The HC-SR04 measures the distance while Arduino determines the appropriate parking warning level.

---

## 🚦 Distance Alert Levels

| Distance | Status  | Indicator | Buzzer           |
| -------: | ------- | --------- | ---------------- |
|  > 50 cm | SAFE    | 🟢 Green  | OFF              |
| 21–50 cm | CAUTION | 🟡 Yellow | Slow Beep        |
| 10–20 cm | WARNING | 🔴 Red    | Fast Beep        |
|  < 10 cm | STOP    | 🔴 Red    | Continuous Alarm |

The thresholds are demonstration values and can be changed in the Arduino program.

---

## 🖼️ Circuit Diagram

Add the circuit diagram to:

`images/Parking_Distance_Alert_Circuit_Diagram.png`

---

## ⚙️ Working Principle

1. Arduino sends a trigger pulse to the HC-SR04.
2. The ultrasonic sensor transmits an ultrasonic burst.
3. The sound reflects from the nearby object.
4. HC-SR04 returns an ECHO pulse.
5. Arduino measures the echo duration.
6. The approximate distance is calculated.
7. Arduino compares the measured distance with the programmed thresholds.
8. The appropriate LED and buzzer warning is activated.

As the object gets closer, the buzzer warning becomes more urgent.

---

## 🟢 SAFE Mode

When the distance is greater than **50 cm**:

* Green LED ON
* Yellow LED OFF
* Red LED OFF
* Buzzer OFF

Serial Monitor:

`Distance: 75.4 cm | SAFE`

---

## 🟡 CAUTION Mode

When the object is approximately **21–50 cm** away:

* Yellow LED ON
* Slow buzzer warning

Serial Monitor:

`Distance: 35.2 cm | CAUTION`

---

## 🔴 WARNING Mode

When the object is approximately **10–20 cm** away:

* Red LED ON
* Fast buzzer warning

Serial Monitor:

`Distance: 15.6 cm | WARNING`

---

## 🛑 STOP Mode

When the object is less than **10 cm** away:

* Red LED ON
* Continuous buzzer warning

Serial Monitor:

`Distance: 7.8 cm | STOP!`

---

## 💻 Arduino Code

The complete Arduino program is available in:

`Parking_Distance_Alert.ino`

No additional Arduino library is required.

---

## ▶️ How to Run

1. Assemble the circuit according to the connection table.
2. Verify all LED polarities.
3. Connect the Arduino UNO using the USB cable.
4. Open `Parking_Distance_Alert.ino`.
5. Select **Arduino UNO** in Arduino IDE.
6. Select the correct COM port.
7. Upload the program.
8. Open Serial Monitor at **9600 baud**.
9. Place an object in front of the HC-SR04.
10. Slowly move the object toward the sensor.
11. Observe the LEDs and buzzer.

---

## 🧪 Testing

Test the project at several distances:

**70 cm → Green**

**40 cm → Yellow + Slow Beep**

**15 cm → Red + Fast Beep**

**5 cm → Red + Continuous Alarm**

Actual readings may vary slightly depending on the target surface and environment.

---

## 📝 Notes

* Use a 330Ω resistor with each LED.
* Keep the ultrasonic sensor facing the target.
* Flat and solid objects generally provide better readings.
* Soft, small, irregular, or angled objects can produce unstable measurements.
* The threshold distances can be modified in the Arduino program.
* This is an educational parking-assistance prototype and should not be relied upon as an automotive safety device.

---

## 🌍 Applications

* Parking assistance demonstrations
* Reverse-distance warning prototypes
* Robotics
* Proximity warning systems
* Obstacle detection
* Distance-based alarm systems

---

## 🎓 Learning Outcomes

After completing this project, you will understand:

* Ultrasonic distance measurement
* HC-SR04 interfacing
* Multiple LED outputs
* Buzzer control
* Distance thresholds
* Conditional logic
* `pulseIn()`
* `tone()` and `noTone()`
* Real-time sensor monitoring

---

## 📜 License

This project is licensed under the **MIT License**.

Copyright (c) 2026 Alphadigitronix Solutions

See the `LICENSE` file for complete license terms.

---

## 🏢 Alphadigitronix Solutions

**ADS Arduino Inventor Kit**

**THINK • BUILD • INNOVATE**
