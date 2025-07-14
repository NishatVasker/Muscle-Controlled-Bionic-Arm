# Muscle-Controlled-Bionic-Arm
# 💪 EMG-Controlled Bionic Arm | Arduino + Muscle Sensor + 3D Printed

This open-source project demonstrates a **bionic arm controlled via EMG (Electromyographic) muscle signals**, designed for two core applications:

1. Assisting **people without a left arm** as a low-cost prosthetic solution.  
2. Serving as a functional **robotic limb for humanoid robots**.

The system uses **muscle signals** from a forearm to control **five servo motors** that replicate human hand motions in real-time.

![Bionic_arm_media (6)](https://github.com/user-attachments/assets/fffb97ac-4d90-4ff0-bb9f-9fddfe1fc90f)


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

## ⚡ Circuit Connections

### Servo Motor Setup:
- MG996R servos connected to PCA9685 channels 0–4.
- PCA9685 to Arduino:
  - SDA → A4  
  - SCL → A5

### EMG Sensor:
- Vcc → 9V battery (+)  
- GND → Battery (–) and Arduino GND  
- Signal → Arduino A0

> Important: All grounds (PCA9685, Arduino, EMG) must be connected together.

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
```  <-- ✅ Add this line to close the code block

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
![Bionic_arm_media (11)](https://github.com/user-attachments/assets/69b29c00-ee17-4663-92bd-fad5245137a8)
![Bionic_arm_media (9)](https://github.com/user-attachments/assets/e489ce76-42c8-4b75-8b1c-19d84c7aaf33)
![Bionic_arm_media (5)](https://github.com/user-attachments/assets/83293f5a-e0a6-4b92-8586-d581f3e37d39)




