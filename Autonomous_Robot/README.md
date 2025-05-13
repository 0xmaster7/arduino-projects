# 🤖 Autonomous Obstacle-Avoiding Robot

This Arduino Uno–powered robot autonomously navigates its environment using an ultrasonic sensor mounted on a servo motor. It detects obstacles and intelligently maneuvers around them using differential steering and a scanning algorithm. The robot continuously moves forward and re-routes itself when an obstacle is encountered, making it ideal for basic autonomous navigation experiments.

---

## 🔧 Components Used

| Component                  | Quantity | Description                                           |
|----------------------------|----------|-------------------------------------------------------|
| Arduino Uno                | 1        | Microcontroller board that runs the control logic     |
| L298N Motor Driver         | 1        | Dual H-bridge motor driver module for motor control   |
| DC Motors                  | 4        | Two on each side for differential steering            |
| Ultrasonic Sensor (HC-SR04)| 1        | Distance sensor used for obstacle detection           |
| Servo Motor (SG90)         | 1        | Rotates the ultrasonic sensor for scanning            |
| Li-ion Batteries (3.7V)    | 2        | Power supply for Arduino and motors                   |
| Switch                     | 1        | Used to toggle the system power on/off                |
| Jumper Wires               | Several  | For connecting components                             |
| Chassis                    | 1        | Frame holding all electronic and mechanical parts     |

---

## 🚗 How It Works

1. **Forward Movement**:  
   The robot drives forward at full speed by default.

2. **Obstacle Detection**:  
   If the ultrasonic sensor detects an obstacle within **30 cm**, the robot pauses.

3. **Scanning Mechanism**:  
   The servo motor rotates the ultrasonic sensor through a set of angles (60° to 120°), measuring distance at each position.

4. **Decision Making**:  
   The robot determines the direction with the most clearance and steers accordingly using differential motor control (via L298N).

5. **Avoidance**:  
   A brief reverse and turn maneuver is executed before resuming forward movement in the new direction.

---

## 💻 Code Summary

- **Sensor Angles**: The servo scans predefined angles in both directions to map out nearby space.
- **Distance Logic**: If any scanned distance is below `SAFE_DISTANCE`, an avoidance routine is triggered.
- **Motor Control**: Each side's motors are independently driven using PWM and direction pins to allow precise turning and reversing.

The behavior is fully autonomous — no remote control or manual intervention required.

---

## 📌 Notes

- The project uses direct wiring without a breadboard.
- Ensure proper power management when using Li-ion batteries for motors.
- Pin configuration and logic can be easily modified for customized navigation strategies.
