# Function of the Subsystem
- The Control & Compute Subsystem functions as the centralised decision-making and data-coordination unit for the entire system. It ensures safe, synchronised, and autonomous operation by executing real-time control and recording mission data for later analysis. This subsystem bridges mechanical actuation, power flow, GNSS-based timing, and system-level logging, ensuring that all operations occur predictably and safely.
- The subsystem is designed around a dual-processor division of labour that combines real-time control capabilities with high-level data processing. It consists of an STM32F405 Feather (Adafruit 4382) microcontroller, a Raspberry Pi Pico, and a u-blox F9 high-precision GNSS module. The STM32 performs all deterministic, real-time tasks. It controls the charge-input MOSFET and the charge-transfer MOSFET, drives the MG90S servo for the mechanical linear arm, and manages charging enable/disable sequences. In parallel, the Raspberry Pi Pico handles non-real-time computation and system logging. It parses GNSS (ZED-F9P) position and time data, handles PPS synchronisation, records system events to an onboard microSD card, and stores timestamped system logs for post-flight analysis retrieval. Finally, the u-blox F9 GNSS module provides precise global positioning and a highly accurate timing reference. Its PPS output enables the Pico to synchronise all recorded events with sub-millisecond accuracy, allowing later correlation of corona events by the thermal camera timestamps and charge sequences.
- Together, the STM32, Raspberry Pi Pico, and ZED-F9P module form a cohesive computing architecture that maintains real-time safety, timing accuracy, and mission-logging reliability without requiring wireless communication or ground-station links. This subsystem ultimately serves as the “brain” of the entire device, ensuring coordinated operation og every other subsystem.

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
  















