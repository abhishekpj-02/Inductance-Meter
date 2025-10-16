# ![Arduino](https://img.shields.io/badge/Arduino-Project-blue) Standalone Arduino Inductance (L) Meter

A standalone, non-IoT instrument to measure inductance using **Arduino**, **LC Tank Circuit**, and **LM339 Comparator**.  

---

### 🚀 Project Overview

The **Standalone Arduino Inductance (L) Meter** is designed to accurately measure the inductance of unknown inductors ($L_x$) using the **LC Tank Circuit Resonance Method**.  

In this method, an unknown inductor is paired with a known reference capacitor to generate a resonant frequency. This frequency is converted into a clean digital square wave using an **LM339 Comparator IC**, allowing the **Arduino Uno** to measure the frequency precisely. The calculated inductance is then displayed on an **I²C LCD**, making the system fully standalone and user-friendly.  

This project was a great learning experience in **signal conditioning**, **embedded systems design**, and **hardware-software integration**.

---

### 🔹 Features

- Measures inductance in **μH** and **mH** ranges  
- High-precision measurements using **LM339 Comparator** for signal stabilization  
- **Arduino Uno** handles frequency measurement and calculations  
- **I²C LCD** provides real-time, readable output  
- Fully **standalone**, no IoT or network connection required  
- Compact, easy-to-assemble, and robust design  

---

### ⚙️ How It Works

1. Unknown inductor ($L_x$) is connected with a reference capacitor ($C_\text{ref}$) to form an LC tank circuit.  
2. Resonant frequency is generated according to the formula:  
   \[
   f = \frac{1}{2 \pi \sqrt{L_x C_\text{ref}}}
   \]  
3. LM339 converts the analog oscillations into a clean square wave.  
4. Arduino measures the frequency and calculates the inductance, displaying it on an **I²C LCD**.  
5. The design ensures minimal damping and high **Quality Factor (Q)** for precise results.

---

### 🔹 Circuit Components

- Arduino Uno  
- LM339 Comparator IC  
- Unknown inductor ($L_x$)  
- Reference capacitor ($C_\text{ref}$)  
- I²C LCD (16x2 or 20x4)  
- Resistors, wires, and breadboard or PCB  

---
### ⚡ Circuit Diagram

Below is the complete wiring for the Standalone Arduino Inductance (L) Meter:

![Circuit Diagram](https://github.com/abhishekpj-02/Inductance-Meter/blob/main/Wiring%20Diagram.png)

- **Arduino Uno** is connected to an **LM339 Comparator IC** and the **I²C LCD**.  
- The unknown inductor ($L_x$) is paired with a reference capacitor ($C_\text{ref}$) to form the LC tank circuit.  
- LM339 conditions the signal, and the Arduino measures the frequency and calculates the inductance.  
- I²C LCD displays the measured values in real time.  


### 🏁 Getting Started

1. **Clone the repository**  
   ```bash
   git clone https://github.com/your-username/arduino-inductance-meter.git
