# TBWC – Teddy Bear Wheel Chair

## 📸 Project Images

<details>
<summary><strong>Click to Expand Images</strong></summary>

---

### 🖼️ Circuit Schematic  
<img width="1139" height="1029" alt="Screenshot 2025-11-25 002858" src="https://github.com/user-attachments/assets/417a3f79-f3c8-4332-ba06-9ac386fee87c" />

---

### 🛠️ Internal Build (Top View)  
![PXL_20251120_190215718](https://github.com/user-attachments/assets/8123aa79-01b7-4956-bc72-39c2ab289b92)

---

### 🚗 Exterior View (Side Profile)  
![PXL_20251120_190302060](https://github.com/user-attachments/assets/0af60ef0-2f00-43c2-aa7f-4c4fff888850)

</details>

---

## 📌 Project Overview

The **TBWC project** is an embedded-systems prototype designed to simulate and test the **drive train of an electric wheelchair**.  
Its primary purpose is to perform a **Speed & Distance Calibration Test (Speed Test)**.

Using a **time-based open-loop control algorithm**, the system drives a high-torque DC motor for a precise duration to measure linear velocity.  
A physical **master switch** provides full circuit isolation, and a **servo-actuated indicator** signals test completion.

---

## 🛠 Hardware Specifications

The prototype is powered by a **12V subsystem** and controlled using **5V logic**.

### **Microcontroller**
- Arduino Uno (ATmega328P)

### **Drive System**
- High-torque DC Motor (simulating wheelchair traction)
- **L298N Motor Control Unit (H-Bridge)** for bidirectional control

### **Safety & Power**
- **Master Isolation Switch**  
  - SPST switch placed on the 12V main rail  
  - Allows safe startup & emergency shutdown
- **12V Battery Pack** (4-cell configuration)

### **Instrumentation**
- **Micro Servo (Pin 9)**  
  Used as a visual indicator or braking mechanism.

---

## 🔌 Circuit Architecture

The electrical design prioritizes **safety**, **noise reduction**, and **signal reliability**.

### **Power Isolation**
A manual switch sits between the 12V battery pack and the entire system.  
This ensures:
- Safe startup  
- Emergency cutoff  
- Full disconnection during calibration or handling  

### **Motor Control**
The **L298N H-Bridge** interfaces Arduino logic with the high-power motor rail:
- **OUT1 / OUT2 → DC Motor**
- **IN1 / IN2 → Arduino Pins A1 and A2**

### **Common Ground**
A shared ground between 12V and 5V rails ensures:
- Stable Arduino logic levels  
- Reduced electrical noise from the motor system  

---

## 💻 Control Logic

The firmware implements a clean, deterministic **one-shot speed test**.

### **Language**
- C++ (Arduino)

### **Libraries**
- `Servo.h`

### **Test Sequence Overview**

1. **Safety Check**  
   System remains off until the manual switch is engaged.

2. **Initialization**  
   Servo resets to **0°**.

3. **Acceleration Phase**  
   Motor runs at **~78% duty cycle** (`analogWrite(..., 200)`)  
   Duration: **1.75 seconds**

4. **Deceleration**  
   Motor is hard-stopped (**LOW / LOW** logic).

5. **Signal Phase**  
   Servo rotates to **180°** indicating test completion.

6. **Termination**  
   Software enters an infinite loop to prevent accidental restart.


