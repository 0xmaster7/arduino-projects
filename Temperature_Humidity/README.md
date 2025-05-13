# 🌡️ Temperature & Humidity Monitoring System

This project monitors environmental temperature and humidity using an Arduino Nano and a DHT11 sensor. The readings are continuously checked and transmitted over Bluetooth to a smartphone using the Serial Bluetooth Terminal app. This setup is ideal for remote monitoring of atmospheric conditions in indoor environments like plant enclosures or greenhouses.

---

## 🔧 Components Used

| Component                | Quantity | Description                                 |
|--------------------------|----------|---------------------------------------------|
| Arduino Nano             | 1        | Microcontroller board used for control      |
| DHT11 Sensor             | 1        | Measures temperature and humidity           |
| HC-05 Bluetooth Module   | 1        | Sends sensor data to a smartphone           |
| Breadboard               | 1        | Used for prototyping and connections        |
| Jumper Wires             | Several  | For electrical connections                  |
| USB Cable / Battery Pack| 1        | For powering the Arduino Nano               |

---

## ⚙️ How It Works

1. The **DHT11** sensor continuously reads temperature and humidity values from the surrounding environment.
2. These values are processed by the **Arduino Nano** in real time.
3. The sensor readings are sent over Bluetooth via the **HC-05** module to a smartphone.
4. You can view the data on your phone using the **Serial Bluetooth Terminal** app (available on Android).

---

## 📲 Mobile App Integration

- App Name: **Serial Bluetooth Terminal**
- Platform: Android
- Function: Displays live temperature and humidity data sent from the Arduino Nano via Bluetooth.

Steps:
1. Pair your phone with the HC-05 Bluetooth module.
2. Open the **Serial Bluetooth Terminal** app.
3. Connect to the HC-05 device.
4. You will start receiving live readings in the terminal view.

---

## 📌 Summary

This is a simple and effective project to learn sensor interfacing, Bluetooth communication, and serial data transmission using Arduino. The compact form factor of the **Arduino Nano** and use of a **breadboard** makes it ideal for prototyping
