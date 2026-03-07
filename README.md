# MRE-320-Project-1-Sensor_Measurement
## Overview

This project focuses on the **experimental characterization of sensors** commonly used in embedded and mechatronic systems. The purpose of the experiments was to evaluate several **static sensor characteristics** and compare sensor measurements with **ground truth references**.

The experiments were conducted as part of a **Sensors and Actuators laboratory project**.

## Project Summary

This project experimentally evaluates the performance of three sensors:

- **DHT11** – temperature and humidity accuracy and static error  
- **HC-SR04** – distance range accuracy and repeatability  
- **MPU-6050** – acceleration accuracy and drift  

Each sensor was tested against a **ground truth reference measurement** to evaluate its performance under controlled conditions.

This repository documents the **testing methodology, experimental setup, and data collection procedures** used during the characterization process. Experimental results and analysis are documented separately.

---

## Sensors Evaluated

| Sensor | Type | Characteristics Tested |
|------|------|------|
| DHT11 | Temperature & Humidity Sensor | Static Error, Accuracy |
| HC-SR04 | Ultrasonic Distance Sensor | Range Accuracy, Repeatability |
| MPU-6050 | Accelerometer / Gyroscope | Accuracy, Drift |

---

## Accuracy and Error Calculations

The collected measurements were evaluated using the following metrics.

### Accuracy

Accuracy was calculated using:

```
Accuracy = (Ground Truth − Measured Value) / Span
```

### Static Error

```
Error = |Ground Truth − Measured Value|
```

These calculations were applied during post-processing of the experimental data.

---

## Sensor Experiments

### 1. DHT11 Temperature and Humidity Sensor

#### Sensor Description

The **DHT11** is a digital sensor designed to measure **ambient temperature and relative humidity**. It is widely used in low-cost environmental monitoring applications and embedded systems.

Manufacturer specifications:

- **Temperature Accuracy:** ±2 °C  
- **Humidity Accuracy:** ±5 %

---

#### Characteristics Tested

- Static Error  
- Measurement Accuracy (Temperature and Humidity)

---

#### Ground Truth Reference

Environmental reference values were obtained from a **weather application reporting outdoor atmospheric conditions**.

These values served as the **ground truth measurements** for temperature and humidity.

---

#### Experimental Procedure

1. The DHT11 sensor was connected to the microcontroller system.
2. Temperature and humidity data were recorded at **one-hour intervals**.
3. Measurements were collected between **2:00 PM and 11:00 PM**.
4. Each sensor reading was logged alongside the corresponding **weather application measurement** recorded at the same time.

---

### 2. HC-SR04 Ultrasonic Distance Sensor

#### Sensor Description

The **HC-SR04** is an ultrasonic ranging sensor that determines distance by transmitting ultrasonic pulses and measuring the **time-of-flight of the reflected signal**.

Manufacturer specifications:

- **Measurement Range:** 2 cm – 400 cm  
- **Typical Accuracy:** ±3 mm

---

#### Characteristics Tested

- Range Accuracy  
- Measurement Repeatability

---

#### Ground Truth Reference

A **measuring tape** was used to determine the true distance between the sensor and the reflecting surface.

---

#### Experimental Setup

The ultrasonic sensor was positioned facing a **large flat cardboard surface**, which served as the reflecting object for the ultrasonic signal.

---

#### Measurement Procedure

1. The sensor was mounted facing the cardboard target.
2. The distance between the sensor and the target surface was adjusted incrementally.
3. Distances ranged from **2 cm to 580 cm**.
4. The actual distance was measured using the measuring tape.
5. Sensor readings were recorded for each distance.

---

#### Repeatability Testing

To evaluate repeatability:

1. Several distances were selected within the test range.
2. **Three independent measurements** were recorded at each selected distance.
3. These repeated measurements were used to evaluate the consistency of the sensor output.

---

### 3. MPU-6050 Accelerometer

#### Sensor Description

The **MPU-6050** is a 6-axis inertial measurement unit that integrates:

- A **3-axis accelerometer**
- A **3-axis gyroscope**

The device is widely used in **robotics, motion sensing systems, and inertial navigation applications**.

---

#### Characteristics Tested

- Measurement Accuracy  
- Sensor Drift

---

#### Ground Truth Reference

Reference acceleration values were obtained using the **Phyphox mobile application**.

For this experiment, the **Accelerometer (without g)** measurement provided by Phyphox was used as the **ground truth acceleration reference**.

---

#### Accuracy Test Procedure

1. The **MPU-6050 sensor module was securely attached to a smartphone** running the Phyphox application.
2. Both sensors experienced the same motion simultaneously.
3. The system was **randomly accelerated in different directions**.
4. Acceleration values were recorded from both the MPU-6050 sensor and the smartphone application.

---

#### Drift Test Procedure

1. The MPU-6050 sensor was secured to the reference device.
2. The system was carefully **leveled to eliminate external acceleration components**.
3. The device remained **completely stationary** during the test.
4. Sensor readings were recorded over time while the system remained at rest to evaluate potential drift.
