# Function of the Subsystem
  The Control & Compute Subsystem serves as the central decision-making, timing, and logging unit for the entire system. Its purpose is to coordinate the Mechanical & Structural subsystem and ensure safe, synchronized, and reliable field operation. It is responsible for executing safe, deterministic control actions, recording mission-critical data, and providing timing, GPS, compass, and telemetry logs for the entire mission.
  

  
# Specifications and Constraints
## Specification: 
### Processor Architecture:
- Raspberry Pi Pico (RP2040 dual-core microcontroller, ARM Cortex-M0+ processor, flexible clock running up to 133 MHz, and 264 kB on-chip SRAM) for high-level data processing and computation.
### Timing System: 
DS3231 RTC, ±2 ppm accuracy, I²C interface.
### GPS / Compass: 
Goku GM10 Nano GPS UART + Compass: fast TTFF, 10 Hz I²C update rate.
### Data Storage
MicroSD card breakout board with an SD/MicroSD Memory Card 8 GB (SDHC).
### Power Consumption: 
≤ 3.5 W total under maximum computational load (~0.45 W MicroSD module + ~0.8 W Pico + ~200 mW Goku GM10, DS3231 RTC negligible).
### Operating Voltage:
3.3 V logic for Pico, MicroSD module, DS3231 RTC, and Goku GM10.
### Weight Limit: 
≤ 20 g combined for all compute and communication components (3.43g MicroSD module + 9 g Raspberry Pi + 2.6 g Goku GM10 + 2.1 g DS3231 RTC).
### Operational Environment:
0°C – 50°C. Insulated housing; static air cooling.
### Data Logging:
SD card logging via Pi Pico; minimum 8 GB storage
### Timestamp Precision: 
≤ 2 ms resolution, maintained by RTC

## Constraint:
### Power and thermal: 
The subsystem must operate within a 5 W power budget due to the confined enclosure and limited passive cooling capabilities. This eliminates the use of high-power processors.
### Weight and Form Factor: 
The subsystem must be extremely lightweight (under 20 g) to prevent shifting the drone’s center of gravity and degrading flight stability. This restricts the use of heavy cooling systems, metal enclosures, or large connector boards.
### EMI/High-Voltage Environment Constraint: 
The computing electronics must maintain signal integrity in the vicinity of high-voltage transmission lines. Shielding and grounding requirements are imposed to meet IEC 61000-6-2/4 electromagnetic compatibility standards for industrial environments.
### Economic:
The total subsystem component cost must remain below $150 USD, aligning with student project budgetary limits and promoting economic feasibility for future prototype scaling.
### Manufacturability and Maintainability: 
Since the subsystem is permanently embedded, components must be soldered and secured for vibration resistance, all boards must be mounted, and must allow easy SD card removal after flight, meeting IPC-A-610 Class 2 workmanship standards for mechanical integrity 



# Overview of Proposed Solution
- The proposed solution integrates a single microcontroller Control & Compute architecture designed to satisfy the subsystem’s requirement for deterministic control, precise timing synchronization, light-weight operation, and reliable mission-data logging. This subsystem integrates one primary component and two supporting components: a Raspberry Pi Pico Feather microcontroller for real-time control, synchronization, and data logging. A DS3231 RTC module for precise and high-accuracy timing, and a Goku GM10 Nano V3 for positioning.

### The architecture is composed of:
- Raspberry Pi Pico  — the data logging and controller.
- DS3231 Precision RTC (Real-Time Clock)  — system-wide timestamp reference.
- Flywoo Goku GM10 Nano V3 GPS + Compass  — lightweight geolocation and heading reference
- MicroSD module + MicroSD memory card — hold the logged data
  
### Roles:
- The Raspberry Pi Pico actuates the MG90S micro servo in the Mechanical & Structural Subsystem. does system logging, timestamp alignment, data collection, and any light computation needed for merging GPS/compass data with system events, and stores logs for post-flight analysis.
- The DS3231 RTC maintains accurate timekeeping (within ±2 ppm), ensuring that all logged events — charging cycles, corona detection markers, servo movements, system faults — are chronologically aligned and traceable.
- The Goku GM10 Nano V3 GPS + Compass provides lightweight positional data and heading information to complement the timestamped logs.
- The MicroSD card breakout board acts as the system's black box. All logged data is recorded and accessible.
  


# Interfaces with other Subsystems
## Raspberry Pi Pico:
### Interfaces with the Mechanical & Structural Subsystem:
#### MG90S Metal-gear Micro Servo (Linear Arm Actuation) Control:
- Signal name: “SERVO_PWM.”
- Signal type: Standard 50 Hz PWM
- Direction: Pi Pico → MG90S Servo
- Connection: GPIO 22/ Pin 29
- Data: Pulse width determines arm position

### Interfaces with DS3231 RTC Module
#### RTC Timing
- Signal Name: RTC_I2C_SCL / RTC_I2C_SDA
- Signal Type: Serial, Half Duplex
- Direction: Pico ↔ DS3231 RTC 
- Protocol: I²C
- Connection:
  - GPIO 0 / Pin 1: I²C0 SDA
  - GPIO 1 / Pin 2: I²C0 SCL
- Data:
  - UNIX timestamp
  - Date (MM/DD/YYYY) / Time (HH:MM:SS)
  - Temperature  (for compensation)

### Interfaces with Goku GM10 Nano V3
#### GPS Positioning
- Signal Name: “GPS_RX/TX”
- Signal Type: Digital UART. Serial
- Direction: GPS → Pi Pico
- Protocol: NMEA UART with a baud-rate of 9600 or 115200
- Connection:
  - GPIO 4 / Pin 6: UART1 TX
  - GPIO 5 / Pin 7: UART1 RX
- Data:
  - Latitude/Longitude
  - Fix quality
  - Satellite count
#### Compass (Magnetometer)
- Signal Name: “COMP_SDA/SCL”
- Signal Type: Serial, Half duplex
- Direction: Pi Pico  ↔  Compass
- Protocol: I²C
- Connection:
  - GPIO 14 / Pin 19: I²C1 SDA
  - GPIO 15 / Pin 20: I²C1 SCL
- Data: Magnetic heading

### Interfaces with Ground Station:
#### Logging: MicroSD Card
- Signal name: "SD_SPI"
- Data Stored:  Serial
- Direction: Pico → MicroSD (can be bidirectional if needed)
- Protocol: SPI
- Data
  - Arm deployment with time-stamps
  - Positioning and Direction
  - Data and Time

### Interfaces with Battery & BMS
- The Pi Pico is powered by the subsystem's regulated 3.3V rail.
  


# 3D Model of Custom Mechanical Components
## Raspberry Pi Pico
### Front:
<img width="1080" height="489" alt="raspberry pi pico" src="https://github.com/user-attachments/assets/90135816-0842-4c15-bbb2-ed15ba956d51" />

### Side: 
<img width="1084" height="550" alt="Screenshot 2025-11-29 172330" src="https://github.com/user-attachments/assets/56626cd8-e067-4b76-8980-445ef0ccff93" />

### Back
<img width="1203" height="668" alt="Screenshot 2025-11-29 172432" src="https://github.com/user-attachments/assets/fd4cbc67-d46a-41b1-bc02-4278824ba93a" />


## DS3231 Precision RTC
### Front:
![5188 DS3231 RTC](https://github.com/user-attachments/assets/c1eb639e-d772-4da4-8bad-9bf00d3c726e)

### Side:
<img width="1221" height="634" alt="Screenshot 2025-11-29 165550" src="https://github.com/user-attachments/assets/6981f262-3458-4c75-af70-99d223468115" />

### Back:
<img width="1118" height="804" alt="Screenshot 2025-11-29 165426" src="https://github.com/user-attachments/assets/bfffabab-d046-4998-9d19-6b7b073c6a80" />


## GOKU GM10 Nano V3 GPS w/compass
### Front:
<img width="505" height="482" alt="Screenshot 2025-12-01 6 58 19 PM" src="https://github.com/user-attachments/assets/5548933c-f7a7-4b41-9b2a-b4886798a1c5" />

### Back:
<img width="466" height="629" alt="Screenshot 2025-12-01 6 58 57 PM" src="https://github.com/user-attachments/assets/fbccb341-5172-4b48-9d76-36b1ecbb19de" />


## MicroSD Card Breakout board
## Front:
<img width="879" height="664" alt="Screenshot 2025-12-01 6 48 26 PM" src="https://github.com/user-attachments/assets/42f571c1-a2ac-4656-a6a1-1872fb62d85c" />

### Side: 
<img width="879" height="624" alt="Screenshot 2025-12-01 6 49 20 PM" src="https://github.com/user-attachments/assets/4507c23d-0c66-4c2f-ab9f-9b0719fb22dd" />

### Back:
<img width="879" height="726" alt="Screenshot 2025-12-01 6 48 58 PM" src="https://github.com/user-attachments/assets/89036de9-3a78-4b0e-9dcd-ab35e2262ac8" />


## MicroSD Memory Card
### Front:
![microSD 0](https://github.com/user-attachments/assets/42053c1c-8f6c-40f0-b010-6c61ac922ebd)

### Side:
![microSD X](https://github.com/user-attachments/assets/b634804b-f43f-41c4-bc0a-2b934118ae6c)

### Back:
![microSD 2](https://github.com/user-attachments/assets/feaba5bd-0aae-4cd6-bfa3-b84e5028f668)




















































