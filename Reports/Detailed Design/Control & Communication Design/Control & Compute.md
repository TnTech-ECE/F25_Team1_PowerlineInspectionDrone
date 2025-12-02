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
  


# Interfaces 
## Interfaces with other subsystems
### Mechanical & Structural Subsystem:
#### MG90S Metal-gear Micro Servo (Linear Arm Actuation) Control:
- Signal name: “SERVO_PWM.”
- Signal type: Standard 50 Hz PWM
- Direction: Pi Pico → MG90S Servo
- Connection: GPIO 22/ Pin 29
- Data: Pulse width determines arm position
#### Housing
- The Pi Pico, DS3231 Precision RTC, MicroSD card breakout board, and MicroSD memory card will be in the housing dome of the drone
- The GOKU GM10 Nano V3 will be outside the housing dome for a clear sky view.

### Battery & BMS Subsystem
- The Pi Pico, DS3231 Precision RTC, MicroSD card breakout board, and GOKU GM10 Nano V3 will be powered by the subsystem's regulated  DC 5V bus.


## Interfaces within itself
### Pi Pico with DS3231 RTC Module
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

### Pi Pico with Goku GM10 Nano V3
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

### Pi Pico with MicroSD card breakout board
#### Logging: MicroSD Card
- Signal name: "SD_SPI."
- Data Stored:  Serial
- Direction: Pico → MicroSD (can be bidirectional if needed)
- Protocol: SPI
- Connection:
  - GPIO 10 / Pin 14: SPI1 SCL
  - GPIO 11 / Pin 15: SPI1 TX
  - GPIO 12 / Pin 16: SPI1 RX
  - GPIO 13 / Pin 17: SPI1 CSn
- Data
  - Arm deployment with time-stamps
  - Positioning and Direction
  - Data and Time
  


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



# Buildable Schematic
<img width="3000" height="2861" alt="circuit_image" src="https://github.com/user-attachments/assets/40d80e0a-f3f7-40c3-b7af-ad37a7f8d878" />



# BOM
| Ref | Component Name | Manufacturer | Part Number | Distributor | Distributor Part Number | Qty | Unit Price (USD) | Total Price (USD) | URL |
|-----|----------------|--------------|--------------|-------------|--------------------------|-----|------------------|-------------------|-----|
| U1  | Raspberry Pi Pico (with headers un-soldered) | Raspberry Pi Foundation | RPI PICO | Adafruit | 5525 | 1 | $4.00 | $5.00 | https://www.adafruit.com/product/4883 |
| U2  | STEMMA QT Real-Time Clock (DS3231) and Cable | Adafruit | 5188 | Adafruit | 5188 | 1 | $13.95 | $14.90 | https://www.adafruit.com/product/5188 and https://www.adafruit.com/product/4209 |
| BT1 | CR1220 Battery for DS3231 | Adafruit | 3801 | Adafruit | 3801 | 1 | $0.95 | $0.95 | https://www.adafruit.com/product/3801 |
| U3  | microSD Card Breakout Board+ | Adafruit | 254 | Adafruit | 254 | 1 | $7.50 | $7.50 | https://www.adafruit.com/product/254 |
| SD1 | microSDHC Memory Card (8GB) | Adafruit | 1294 | Adafruit | 1294 | 1 | $9.95 | $9.95 | https://www.adafruit.com/product/1294 |
| U4  | Goku GM10 Nano V3 GPS + Compass Module | Flywoo | GM10 Nano V3 | Flywoo | GM10-NANO-V3 | 1 | $20.99 | $20.99 | https://flywoo.net/products/goku-gm10-nano-v3-gps-w-compass |
| H1  | Black Nylon Machine Screw and Stand-off Set – M2.5 Thread | Adafruit | 3299 | Adafruit | 3299 | 1 | $16.95 | $16.95 | https://www.adafruit.com/product/3299 |

**Total Estimated Cost:** **$76.24 USD**



# Analysis
### Raspberry Pi Pico
- The Pico is a low-power, lightweight microcontroller (RP2040) well suited to embedded logging and control tasks. At $4 and ~3–5 g, it keeps the subsystem mass and cost down while offering:
  - Dual-core RP2040 CPU for simple multitasking (or running FreeRTOS/Multi-threaded tasks).
  - SPI and I²C peripherals for microSD and RTC interfaces, respectively.
  - Built-in ADCs for simple analog monitoring (if needed).
- This meets the constraints: low weight, low power, and ease of software development, given your embedded background. It can timestamp, log events, control a servo motor, and write files to the microSD breakout (via SPI).

### DS3231 Precision RTC
- The DS3231 is a temperature-compensated RTC with excellent short-term stability and an I²C interface. The STEMMA QT breakout simplifies wiring to the Pico (plug-and-play).
- Functionally, this provides the wall-clock timestamps. The precision of DS3231 (ppm-level stability) is suitable for event logging.
- Low weight (≈2.5 g), low power, and easy interfacing (I²C). The coin-cell backup ensures the RTC keeps time during power cycles — important for post-flight analysis.
  
### GOKU GM10 Nano V3 GPS w/compass
- The GOKU GM10 is a tiny, lightweight GPS/compass module (≈2–3 g).
- provides lightweight positional data and heading information to complement the timestamped logs.
  
### MicroSD card breakoutboard + MicroSD memory card
- The Adafruit MicroSD Card Breakout+ provides level shifting, a 3.3V regulator, and a push-push card socket; it’s designed for microcontroller SPI usage and is robust for field logging.
- With the selected 8GB/16GB/64GB card (recommend 32–64GB for headroom), the Pico can log timestamped events. SPI bandwidth is adequate for periodic logging.
- The breakout + an 8GB card is more than sufficient and meets weight/economic constraints.



# Reference 
[1] Raspberry Pi Ltd., “Raspberry Pi Pico,” Raspberry Pi. [Online]. Available:
https://www.raspberrypi.com/products/raspberry-pi-pico/
(accessed Dec. 2, 2025).

[2] Adafruit Industries, “Raspberry Pi Pico – Adafruit,” Adafruit. [Online]. Available:
https://www.adafruit.com/pico?src=raspberrypi
(accessed Dec. 2, 2025).

[3] Raspberry Pi Ltd., “Pico Series Microcontrollers Documentation,” Raspberry Pi Documentation. [Online]. Available:
https://www.raspberrypi.com/documentation/microcontrollers/pico-series.html
(accessed Dec. 2, 2025).

[4] Adafruit Industries, “Adafruit DS3231 Precision RTC Breakout,” Adafruit. [Online]. Available:
https://www.adafruit.com/product/5188
(accessed Dec. 2, 2025).

[5] Adafruit Industries, “DS3231 Precision RTC – Pinouts,” Adafruit Learn. [Online]. Available:
https://learn.adafruit.com/adafruit-ds3231-precision-rtc-breakout/pinouts
(accessed Dec. 2, 2025).

[6] Adafruit Industries, “Adafruit CR1220 Lithium Coin Cell,” Adafruit. [Online]. Available:
https://www.adafruit.com/product/380
(accessed Dec. 2, 2025).

[7] Flywoo, “GOKU GM10 Nano V3 GPS w/ Compass,” Flywoo Official Store. [Online]. Available:
https://flywoo.net/products/goku-gm10-nano-v3-gps-w-compass
(accessed Dec. 2, 2025).

[8] Adafruit Industries, “MicroSD Card Breakout Board+,” Adafruit. [Online]. Available:
https://www.adafruit.com/product/254
(accessed Dec. 2, 2025).

[9] Adafruit Industries, “8 GB Class 4 microSDHC Card,” Adafruit. [Online]. Available:
https://www.adafruit.com/product/1294
(accessed Dec. 2, 2025).





























































