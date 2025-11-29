# Function of the Subsystem
  The Control & Compute Subsystem serves as the central decision-making, timing, and logging unit for the entire system. Its purpose is to coordinate all other subsystems and ensure safe, synchronized, and reliable operation in the field. It is responsible for executing safe, deterministic control actions, recording mission-critical data, and providing timing, GPS, compass, and telemetry logs for the entire mission.
  
### The architecture is composed of:
- STM32F405 Feather (Adafruit 4382) — the real-time controller.
- Raspberry Pi Pico  — the data logging and processing controller.
- DS3231 Precision RTC (Real-Time Clock)  — system-wide timestamp reference.
- Flywoo Goku GM10 Nano V3 GPS + Compass  — lightweight geolocation and heading reference
-  
### Functional Role:
- The STM32F405 executes all time-critical control functions, including regulating energy transfer from the power-harvesting capacitor to the battery between the Power Harvesting Subsystem and the Battery & BMS Subsystem, monitoring BMS signals in the Battery & BMS Subsystem, and actuating the MG90S micro servo in the Mechanical & Structural Subsystem.
- The Raspberry Pi Pico manages event markers and DVR timestamps from the Corona Detection & Camera Sensing Subsystem, system logging, timestamp alignment, data collection, and any light computation needed for merging GPS/compass data with system events. It also collects telemetry from the STM32 and stores logs for post-flight analysis.
- The DS3231 RTC maintains accurate timekeeping (within ±2 ppm), ensuring that all logged events — charging cycles, corona detection markers, servo movements, system faults — are chronologically aligned and traceable.
- The Goku GM10 Nano V3 GPS + Compass provides lightweight positional data and heading information to complement the timestamped logs.

By separating real-time control (STM32) from compute and logging tasks (Pico), the subsystem maintains reliability and operation clarity while reducing system mass and power draw.


# Specifications and Constraints
## Specification: 
### Processor Architecture:
- Raspberry Pi Pico (RP2040 dual-core microcontroller, ARM Cortex-M0+ processor, flexible clock running up to 133 MHz, and 264 kB on-chip SRAM) for high-level data processing and computation.
- STM32F405 Feather (Cortex-M4F @ 165 MHz, 1 MB Flash) for real-time control.
### GNSS Module: 
  The U-blox ZED-F9P high-precision GNSS receiver provides < 1 m positional accuracy (stand-alone) and < 5 cm with RTK corrections.
### Communication Interfaces: 
- UART: 
  STM32 ↔ Pico,
  Pico 	↔ GNSS
- SPI:
  Pico 	↔ SD card
- PWM:
  STM32 → Servo
- GPIO digital lines:
  STM32 → MOSFET,
  Pico 	→ Event markers,
  Pico 	→ Timestamp triggers
### Power Consumption: 
≤ 5 W total under maximum computational load (≈1 W STM32 + ≈0.8 W Pico + ≈1 W GNSS ).
### Operating Voltage: 
3.3 V logic for both STM32 and Pico.
### Weight Limit: 
≤ 35 g combined for all compute and communication components (~6.2 g STM32 + ~9 g Raspberry Pi + 19.5 g GNSS).
### Operational Environment:
0°C – 50°C. Insulated housing; static air cooling.
### Event Logging: 
Pico logs GNSS-timestamped system events at a rate of ≤10 Hz to onboard microSD storage (with a capacity of > 32 GB).
### Timing Precision: 
PPS synchronisation accuracy ≤ 10 µs between STM32 and Pi.
## Constraint:
### Power and thermal: 
The subsystem must operate within a 5 W power budget due to the confined enclosure and limited passive cooling capabilities. This eliminates the use of high-power processors.
### Weight and Form Factor: 
The subsystem must be extremely lightweight (under 35 g) to prevent shifting the drone’s center of gravity and degrading flight stability. This restricts the use of heavy cooling systems, metal enclosures, or large connector boards.
### EMI/High-Voltage Environment Constraint: 
The computing electronics must maintain signal integrity in the vicinity of high-voltage transmission lines. Shielding and grounding requirements are imposed to meet IEC 61000-6-2/4 electromagnetic compatibility standards for industrial environments.
### Safety and Reliability: 
The STM32 microcontroller must execute deterministic control functions independently of the Raspberry Pi to ensure safe charging and fault shutdown, satisfying IEC 61508 functional safety principles at the subsystem level.
### Economic:
The total subsystem component cost must remain below $250 USD, aligning with student project budgetary limits and promoting economic feasibility for future prototype scaling.
### Manufacturability and Maintainability: 
Since the subsystem is permanently embedded, components must be soldered and secured for vibration resistance, meeting IPC-A-610 Class 2 workmanship standards for mechanical integrity 

# Overview of Proposed Solution
- The proposed solution integrates a dual-processor Control & Compute architecture designed to satisfy the subsystem’s requirement for deterministic safety control, precise timing synchronization, light-weight operation, and reliable mission-data logging. This subsystem integrates three primary components: an STM32F405 Feather microcontroller for real-time control, a Raspberry Pi Pico for GNSS-based timestamping and data logging, and a u-blox ZED-F9P GNSS module for high-accuracy timing and positioning. Together, these devices coordinate the power-harvesting mechanism, mechanical actuation, and system-wide event recording while adhering to all power, weight, thermal, and reliability constraints. 
- The STM32F405 Feather serves as the subsystem’s deterministic control processor, executing microsecond-accurate logic required for safe charging and mechanical movements. It regulates the transfer of energy from the load capacitor into the onboard battery, ensuring that overvoltage, overcurrent, and BMS fault conditions prompt immediate protective action. The STM32 also drives the MG90S micro-servo responsible for deploying and retracting the mechanical linear arm, further reinforcing its role as the subsystem’s primary actuator controller. 
- The Raspberry Pi Pico fulfills all non-deterministic compute tasks. It parses GNSS data streams from the ZED-F9P, aligns all subsystem events using the GNSS PPS timing signal, and performs structured mission logging to an onboard microSD card. By handling timestamping, storage, and system-level data organization, the Pico allows the STM32 to remain dedicated to safety-critical operations without the risk of delays caused by file I/O or background processing. This division of responsibilities ensures both operational safety and robust data integrity.
- The u-blox ZED-F9P GNSS module provides precise positioning data and a highly stable 1 Hz Pulse-Per-Second (PPS) signal that synchronizes the entire subsystem. This timing reference enables sub-millisecond alignment between mechanical actuation events, charging cycles, and analog video timestamps from the thermal camera’s DVR module. Although the camera’s CVBS video stream is not digitally processed onboard, its recorded time markers can be matched post-flight with GNSS-synchronized system logs, allowing accurate correlation of corona-related events.
- Together, the STM32F405 Feather, Raspberry Pi Pico, and ZED-F9P GNSS module constitute a cohesive, efficient, and lightweight control and compute solution optimized for safety, clarity of function, and post-flight analysis. The architecture satisfies subsystem constraints related to power consumption, thermal limits, mass restrictions, EMC robustness, and functional safety, while providing a modular foundation for future enhancements. This proposed solution ensures reliable subsystem performance, high-integrity data capture, and seamless coordination with the broader drone-based inspection system.

# Interfaces with other Subsystems
## STM32F405 Feather:
### Interfaces with the Power Harvesting & BMS/Battery Subsystem (Indirect Control Role):
The STM32F405 does not directly interface with the high-voltage power-harvesting circuitry. Instead, it functions as the system’s intermediary controller, regulating when energy stored in the load capacitor is permitted to transfer into the onboard Battery & BMS subsystem.
#### Charge Transfer Control. From the power harvesting circuit to the on-board battery. Done using a [FILL IN]:
- Signal Name: CAP_TO_BATT_EN
- Signal Type: Digital (3.3 V GPIO)
- Direction: STM32 →
- Data:
  HIGH → (connect capacitor to battery)
  LOW → (disconnect capacitor from battery)
### Interfaces with the Battery & BMS Subsystem:
### Battery & BMS Logging
[BMS]
- Signal Name: “BMS_UART_TX/RX”
- Signal Type: Digital. UART (3.3 V)
- Direction: Bidirectional (STM32 ↔ BMS)
- Data: pack voltage, SoC, SoH, temperature, fault flags
### Interfaces with the Mechanical & Structural Subsystem:
#### MG90S Metal-gear Micro Servo (Linear Arm Actuation) Control:
- Signal name: “SERVO_PWM”
- Signal type: Standard 50 Hz PWM
- Direction: STM32F405 → MG90S Servo
- Data: Pulse width determines arm position
### Interfaces with the Raspberry Pi Pico:
- Signal name: “PI_STM32”
- Signal type: Digital (3.3 V TTL)
- Direction: Bidirectional
- Data 
  - Line to circuit enabled/disabled.
  - Load cap to on-board battery enabled/disabled.
  - Arm deployed/retracted.
## Raspberry Pi Pico:
### Interfaces with the Corona Detecting and Camera Sensing Subsystem:
The Pi does not process the analog video directly; instead, it receives Event markers and DVR timestamps.
#### Axisflying High-Res Mini Thermal FPV Camera Module
- Signal name: “CAM_CVBS_IN”
- Signal Type: Analog CVBS
- Direction: Camera → DVR Recorder 
- Protocol: Analog video Standard
- Data: Composite Video is recorded using an onboard Mini FPV DVR Recorder. Pi receives only DVR timestamps and event markers.
### Interfaces with Ground Station:
Stores all mission data locally for post-flight retrieval and analysis.
#### Logging Strategy
- Data Storage: Raspberry Pi microSD card
- Data Stored: 
  - GNSS timestamped charging logs
  - DVR timestamps
  - Arm deployment timestamps
  - Charging enable/disable timestamps
  - BMS readings
### Interfaces with the STM32F405 Feather:
- Protocol: UART—Pi logs STM32 telemetry and sends operator commands
- Time sync: Pi utilizes GNSS NMEA/UBX and relays commands; timestamp alignments via PPS.
### U-blox F9 GNSS module (ZED_F9P):
Interfaces with the Raspberry Pi Zero 2 W and STM32F405
#### GNSS Data (Position / Time / Satellite Info)
- Signal name: “GNSS_UART”
- Signal type: Digital
- Direction: Input. GNSS → Pi → STM32
- Protocol: UBX/NMEA over UART
- Data:
  - Latitude/longitude
  - Altitude
  - Time of day
#### High-Precision Timing (PPS)
- Signal name: “GNSS_PPS”
- Signal type: Digital Pulse (1 Hz)
- Direction: Input. GNSS → Pi 
- Data: Rising-edge pulse providing sub-millisecond time reference
### Interfaces with the Mechanical & Structural subsystem
#### Antenna: u-blox ANN-MB-00
- Signal name: “GNSS_ANT”
- Signal type: RF Coaxial
- Direction: Antenna → GNSS Receiver
- Protocol: RF (L1/L2 GNSS bands)
- Data: Raw satellite signals

# 3D Model of Custom Mechanical Components
## Raspberry Pi Pico:
<img width="1080" height="489" alt="raspberry pi pico" src="https://github.com/user-attachments/assets/90135816-0842-4c15-bbb2-ed15ba956d51" />
<img width="988" height="568" alt="raspberry pi pico with contacts" src="https://github.com/user-attachments/assets/4df9746b-9b7d-4062-a95e-c45718e82da7" />

## STM32F405 Feather:
<img width="963" height="722" alt="STM32F405_TOP" src="https://github.com/user-attachments/assets/dabc6be2-8e0c-43e2-aef0-a137ff89c77b" />
<img width="1918" height="936" alt="Adafruit Feather STM32F405 Express_TOP" src="https://github.com/user-attachments/assets/168f8e79-19b7-4c51-af58-2965d2030931" />
<img width="970" height="728" alt="image" src="https://github.com/user-attachments/assets/ea15b743-f80b-4f39-a181-8a94c9624a21" />

## u-blox ZED-F9P GNSS




































