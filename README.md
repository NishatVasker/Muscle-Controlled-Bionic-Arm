# Muscle-Controlled-Bionic-Arm
# 💪 EMG-Controlled Bionic Arm | Arduino + Muscle Sensor + 3D Printed

This open-source project demonstrates a **bionic arm controlled via EMG (Electromyographic) muscle signals**, designed for two core applications:

1. Assisting **people without a left arm** as a low-cost prosthetic solution.  
2. Serving as a functional **robotic limb for humanoid robots**.

The system uses **muscle signals** from a forearm to control **five servo motors** that replicate human hand motions in real-time.

![Bionic_arm_media (11)](https://github.com/user-attachments/assets/69b29c00-ee17-4663-92bd-fad5245137a8)

---

## 🎯 Features

- EMG-based real-time motor control using Arduino  
- Five degrees of motion via MG996R servos  
- PCA9685 for efficient servo signal handling  
- Fully 3D printed modular arm (lightweight, 400g)  
- Cost-effective and prosthetic-friendly design  
- Can be extended for humanoid robotics

---

## 🧰 Components Used

| Component             | Description / Quantity         |
|----------------------|--------------------------------|
| Arduino Uno          | Microcontroller (1x)           |
| MG996R Servo Motors  | High-torque motors (5x)        |
| PCA9685 Servo Driver | 16-channel PWM driver (1x)     |
| EMG Muscle Sensor    | Generic sensor (1x)            |
| 9V Batteries         | For EMG sensor power (2x)      |
| 3D Printed Arm       | PLA, 30% infill, total ~400g   |
| Jumper Wires         | For connections                |

---

## 🧠 How It Works

- EMG sensor detects electrical activity from your forearm muscles.  
- Arduino reads the EMG signal as analog input.  
- Signal is mapped to servo angles using threshold-based control.  
- PCA9685 generates PWM signals for servo motors.  
- Servo motors rotate fingers/wrist to mimic hand movement.

---

## 🔌 Full Wiring Connections

This section details all the electrical connections between the microcontroller, sensor, servo motors, servo driver, and batteries. It assumes you're using an **Arduino Uno**, **5 MG996R servos**, **a PCA9685 servo driver**, and a **generic EMG muscle sensor** powered by two 9V batteries.

---

### 🧠 EMG Sensor → Arduino Uno

| EMG Sensor Pin | Connects To                |
|----------------|----------------------------|
| VCC            | +9V Battery 1              |
| GND            | GND of Battery 1 and Arduino GND |
| SIG (OUT)      | Arduino A0 (Analog Input)  |

> 🔋 Power the EMG sensor using **two 9V batteries in series** for ±9V operation (as many analog EMG modules require). Ensure the Arduino shares a **common ground** with the battery.

---

### 🔧 PCA9685 Servo Driver → Arduino Uno (I2C)

| PCA9685 Pin | Arduino Uno Pin |
|-------------|------------------|
| VCC         | 5V               |
| GND         | GND              |
| SDA         | A4               |
| SCL         | A5               |

> 🧠 This sets up I2C communication for servo control.

---

### ⚙️ Servo Motors (MG996R) → PCA9685 Channels 0–4

| Servo         | PCA9685 Channel | Signal Pin | VCC (Red) | GND (Brown) |
|---------------|------------------|------------|-----------|-------------|
| Thumb Servo   | 0                | CH0        | 5V Power  | Common GND  |
| Index Servo   | 1                | CH1        | 5V Power  | Common GND  |
| Middle Servo  | 2                | CH2        | 5V Power  | Common GND  |
| Ring Servo    | 3                | CH3        | 5V Power  | Common GND  |
| Wrist Servo   | 4                | CH4        | 5V Power  | Common GND  |

> ⚠️ Do **not power servos from Arduino 5V pin**. Use a **separate 5V–6V external power source** (e.g., 2-cell Li-ion battery or 5V/3A adapter) to VCC of PCA9685 servo rail.

---

### 🔋 Power Supply Summary

| Device           | Power Source           | Notes                                 |
|------------------|------------------------|----------------------------------------|
| Arduino Uno      | USB or 9V adapter      | Can be USB-powered during testing     |
| PCA9685 (logic)  | Arduino 5V             | Connected via VCC pin                 |
| Servo Motors     | External 5–6V (2–5A)   | Do not use Arduino 5V for servos      |
| EMG Sensor       | Two 9V batteries (±9V) | Sensor output to Arduino A0           |

---

### 🧷 Common Ground Wiring (Very Important!)

You **must connect all GNDs together**:
- Arduino GND
- PCA9685 GND
- EMG sensor GND
- Servo motor power GND
- 9V battery GND (used in EMG)

This ensures stable reference voltage for analog signal reading and PWM control.

---

### 🖼️ Suggested Diagram (Optional)



---

## 📐 Mathematical Mapping

Let `V_emg` be the EMG analog signal. The angle θ for servo is calculated as:

- If `V_emg < 250`, then `θ = 0°`  
- Else, map `V_emg` from 250–600 to 0–180°

```cpp
if (V_emg > threshold) {
  angle = map(V_emg, 250, 600, 0, 180);
} else {
  angle = 0;
}
```  

## 🧾 Pseudocode
Start
Initialize I2C and PCA9685
Loop:
    Read EMG signal from A0
    If signal > threshold:
        Map signal to angle
        Move all 5 servos to that angle
    Else:
        Set servos to 0°
Repeat

## 📹 Video

🎥 Watch the Bionic Arm in Action:  
➡️ [https://www.youtube.com/shorts/qkh9qTzFNlg](https://www.youtube.com/shorts/qkh9qTzFNlg)


https://github.com/user-attachments/assets/264a68eb-bbef-4f23-b577-94a843c432ea


![Bionic_arm_media (11)](https://github.com/user-attachments/assets/69b29c00-ee17-4663-92bd-fad5245137a8)
![Bionic_arm_media (6)](https://github.com/user-attachments/assets/fffb97ac-4d90-4ff0-bb9f-9fddfe1fc90f)
![Bionic_arm_media (5)](https://github.com/user-attachments/assets/83293f5a-e0a6-4b92-8586-d581f3e37d39)




