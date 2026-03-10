# IoT Enabled Groundwater Quality Monitoring System

An IoT based system designed to monitor groundwater quality parameters such as **pH, Total Dissolved Solids (TDS), and Temperature** in real time using the **ESP32 microcontroller and water quality sensors**.  
The system continuously measures water conditions and sends the collected data to an **IoT cloud platform for remote monitoring**.

---

## Project Overview

Groundwater contamination is a major environmental and public health issue caused by industrial waste, agricultural chemicals, and environmental pollution. Traditional monitoring methods require manual sample collection and laboratory analysis, which are time consuming and expensive.

This project provides a **low-cost IoT based solution for real-time groundwater monitoring**. The system uses sensors connected to an ESP32 microcontroller to measure water quality parameters and transmit the data to a cloud platform through WiFi.

The collected data can be viewed locally using an LCD display and remotely through an IoT dashboard.

---

## Features

- Real-time groundwater quality monitoring
- Measurement of **pH, TDS, and temperature**
- Local monitoring using **16x2 LCD display**
- Remote monitoring using **IoT cloud platform**
- WiFi connectivity using **ESP32**
- Threshold-based contamination detection
- Cost-effective and scalable design

---

## System Architecture

The system consists of four main layers:

1. **Sensor Layer** – pH sensor, TDS sensor, and temperature sensor collect water quality data.
2. **Processing Layer** – ESP32 microcontroller processes sensor readings.
3. **Communication Layer** – WiFi module sends data to the IoT cloud platform.
4. **Visualization Layer** – Data is displayed on LCD and IoT dashboard.

---

## Hardware Components

- ESP32 Microcontroller
- pH Sensor
- TDS Sensor
- Temperature Sensor
- 16x2 LCD Display
- Power Supply
- Jumper Wires

---

## Software Used

- Arduino IDE
- Embedded C
- WiFi Libraries
- HTTP Client Libraries
- Arduino JSON Library
- IoT Beginner Cloud Platform

---

## Working Principle

1. Sensors continuously measure groundwater quality parameters.
2. ESP32 reads sensor values using its analog input pins.
3. Sensor data is processed and converted into meaningful parameters.
4. The measured values are displayed on the LCD screen.
5. Data is transmitted to the IoT platform using WiFi.
6. Users can monitor water quality remotely through the dashboard.

---

## Project Output

### LCD Display Output

The system displays real-time water quality parameters directly on a **16x2 LCD display**.

Example output includes:

- pH value
- TDS level (ppm)
- Temperature

![op1](https://github.com/user-attachments/assets/eb611cf1-84a8-4ecd-b788-eafc1dfebf82)


---

### IoT Dashboard Output

The collected data is transmitted to the **IoT Beginner platform**, where users can monitor groundwater quality remotely.

The dashboard displays sensor values and updates them in real time.

<img width="660" height="442" alt="Screenshot 2026-03-04 161410" src="https://github.com/user-attachments/assets/366e0d88-1fbc-467f-98ba-ace3b3332198" />


---


## Applications

- Groundwater quality monitoring
- Rural drinking water monitoring
- Agricultural water management
- Environmental monitoring
- Smart water management systems

---

## Future Improvements

- Integration of turbidity sensors
- Heavy metal detection
- Machine learning for water quality prediction
- Mobile application for monitoring
- Solar powered deployment
