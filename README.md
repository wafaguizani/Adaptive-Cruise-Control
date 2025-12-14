# Adaptive Cruise Control (ACC) System - AUTOSAR

This project presents the design and simulation of an **Adaptive Cruise Control (ACC)** system using the **AUTOSAR** architecture within MATLAB/Simulink. The core decision logic is managed by a **Stateflow** state machine.

## 📋 Project Description
The system automatically adjusts the vehicle's speed to maintain a safe distance from the preceding vehicle. It operates in two main modes:
1.  **Cruising Mode:** Maintains the driver's set speed (free road).
2.  **Following Mode:** Adapts speed to follow the preceding vehicle (obstacle detected).

## 🛠️ Technical Architecture
*   **Environment:** MATLAB / Simulink R2024b
*   **Control Logic:** Stateflow (Finite State Machine)
*   **Standard:** AUTOSAR (Code Generation: `autosar.tlc`)
*   **Interface:** Interactive Simulink Dashboard

## 🧠 Control Logic (Stateflow)
The system is driven by a state chart (`ACC_Logic`) comprising three main states:

| State | Description | Main Actions |
| :--- | :--- | :--- |
| **OFF** | System Deactivated | `Accel_Req = 0`, `Brake_Req = 0` |
| **CRUISING** | Free Road | P-Control Regulation: `Accel_Req = (Set - Current) * 2` |
| **FOLLOWING** | Obstacle Detected | Active Braking: `Brake_Req = 1`, `Accel_Req = 0` |

### Transition Conditions (Hysteresis Logic)
*   **Activation:** `Switch_ACC == 1`
*   **Obstacle Detection:** Switch to *Following* mode if `Radar_Dist < 50m`.
*   **Return to Cruising:** Switch to *Cruising* mode if `Radar_Dist > 60m` (Safety margin to prevent oscillations).

## 🎮 Simulation and Dashboard
An interactive dashboard has been integrated into the model to test the system in real-time without writing code.

### Inputs (Controls)
*   **Switch ACC:** ON/OFF Toggle.
*   **Set Speed (Knob):** Driver's desired speed (0-200 km/h).
*   **Current Speed (Knob):** Actual vehicle speed (physics simulation).
*   **Radar Distance (Slider):** Simulated distance to the obstacle (0-255 m).

### Outputs (Visualization)
*   **Acceleration Gauge:** Visualizes engine torque request (`Accel_Req`).
*   **Brake Lamp:** Lights up (Red) during emergency braking.
*   **System State (LED):**
    *   ⚪ Grey: OFF
    *   🟢 Green: Cruising Mode
    *   🟠 Orange: Following Mode

## 🚀 Installation and Testing Guide
1.  Clone this repository:
    ```bash
    git clone https://github.com/wafaguizani/Adaptive-Cruise-Control.git
    ```
2.  Open MATLAB and load the file **`ACC_System.slx`**.
3.  Start the simulation (Click **Run**).
4.  Interact with the Dashboard controls:
    *   Activate the Switch.
    *   Simulate a close obstacle (< 50m) using the "Radar" slider to observe braking.
    *   Move the obstacle away (> 60m) to see the system accelerate again.

## 📄 Code Generation (AUTOSAR)
The model is configured for automatic code generation compliant with the AUTOSAR standard:
*   **System Target File:** `autosar.tlc`
*   Software Components and Interfaces are mapped using the **AUTOSAR Component Designer**.

---
*Project created by Wafa Guizani.*
