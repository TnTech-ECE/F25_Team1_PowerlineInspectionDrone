# Power Harvesting & Charging: Detailed Design

## Function of Subsystem

The Power Harvesting & Charging subsystem serves as the electrical energy interface between the drone and the transmission line. Its primary function is to convert the high-voltage AC present on a 13 kV distribution line into a safe, regulated DC supply that can be used by the Battery and BMS subsystem to charge the drone’s onboard battery. This is achieved by harvesting AC energy through a coupling interface, rectifying it using a full-wave rectifier circuit, and stabilizing the output with a load capacitor to minimize ripple and voltage fluctuations before delivery to the BMS.

A secondary function of this subsystem is to provide electrical isolation and protection for all other onboard electronics. It ensures that any high-voltage surges, transients, or faults remain confined within the harvesting circuit, protecting the drone’s compute and sensing systems. Once the DC output is stable and within the required limits, control of charging operations and communication with the onboard computer are managed by the Battery and BMS subsystem.

## Specifications and Constraints

### Specifications

- The subsystem shall safely harvest electrical energy from a 13 kV (phase-to-phase) distribution line, capturing the usable portion of the electric field current through the conductive hook and returning it to ground through the capacitive plate.
- The subsystem shall efficiently deliver conditioned DC power to the Battery Management System (BMS) such that the BMS can regulate, convert, and store the harvested energy without exceeding its input limits.
- The subsystem shall rectify the high-voltage AC signal using a diode-array rectifier designed to withstand at least 7.5 kV phase-to-ground and the expected peak line-to-ground voltage under normal operating conditions.
- The subsystem shall include a load capacitor bank that stores harvested charge and periodically discharges into the BMS subsystem once the capacitor reaches a pre-defined voltage threshold suitable for BMS input and conversion
- The subsystem shall maintain a total mass of ≤ 100 g, including the rectifier, load capacitor array, wiring, coupling plate, insulation, and mechanical mounting, to ensure drone stability and flight performance are not compromised.
- The subsystem shall incorporate electrical isolation, buffering, and physical insulation appropriate for operation in proximity to energized transmission lines, preventing hazardous leakage currents through the drone frame or electronics.

### Constraints

- High-voltage environment: The coupling plate and rectifier must withstand stray electric fields up to tens of kilovolts. Creepage and clearance must follow IEC 60664 spacing requirements.
- Capacitive coupling limitations: Plate size is limited by drone weight, meaning the plate’s capacitance to ground cannot exceed practical physical dimensions.
- Operating temperature: Components must function from −10 °C to +50 °C.
- Weather exposure: Though the system is not intended for rain, components must tolerate humidity up to 95% non-condensing.
- Vibration: Subsystem must survive flight vibration and line-contact shock loads.
- The subsystem must not risk unintended conduction into the drone frame or operators, requiring full electrical isolation from user-accessible components.

## Overview of Proposed Solution

The proposed solution for the Power Harvesting and Charging Subsystem is a lightweight, high-voltage-tolerant energy-harvesting module that safely converts the transmission line’s AC signal into a regulated DC power source for the drone’s battery system. The design integrates four primary elements: a high-voltage full-wave diode rectifier, an energy-storage load capacitor, a charge enabling Mosfet acting as a switch, and a capacitive plate that completes the return path to earth. Working together, these components enable reliable power extraction while meeting all subsystem specifications and adhering to weight, safety, environmental, and regulatory constraints defined in the project requirements. All together, these components create this circuit: 

INPUT COMPLETE CIRCUIT HERE

### Full-Wave Rectifier

The rectifier receives the high-voltage AC signal from the transmission line and converts it into a rectified waveform that charges the load capacitor. The rectifier is implemented using two diode arrays arranged in a full-wave configuration, with each array consisting of three high-voltage Diotec HV5 diodes connected in series. Each HV5 diode is rated for 5 kV and 200 mA, and placing three in series provides the necessary voltage withstand capability for safe operation under the expected transmission-line conditions. The resulting configuration creates a robust, buildable high-voltage rectifier suitable for this subsystem. A diagram of the rectifier is provided below:

INSERT RECTIFER PHOTO HERE

### Load Capacitor

### Capacitive Plate

### High Voltage Mosfet

## Interface with Other Subsystems

## Buildable Schematic

## Flowchart

## BOM

## Analysis

## References

