# Power Harvesting & Charging: Detailed Design

## Function of Subsystem

The Power Harvesting & Charging subsystem serves as the electrical energy interface between the drone and the transmission line. Its primary function is to convert the high-voltage AC present on a 13 kV distribution line into a safe, regulated DC supply that can be used by the Battery and BMS subsystem to charge the drone’s onboard battery. This is achieved by harvesting AC energy through a coupling interface, rectifying it using a full-wave rectifier circuit, and stabilizing the output with a load capacitor to minimize ripple and voltage fluctuations before delivery to the BMS.

A secondary function of this subsystem is to provide electrical isolation and protection for all other onboard electronics. It ensures that any high-voltage surges, transients, or faults remain confined within the harvesting circuit, protecting the drone’s compute and sensing systems. Once the DC output is stable and within the required limits, control of charging operations and communication with the onboard computer are managed by the Battery and BMS subsystem.

## Specifications and Constraints

## Overview of Proposed Solution

## Interface with Other Subsystems

## 3D Model of Custom Mechanical Components

## Buildable Schematic

## Printed Circuit Board Layout

## Flowchart

## BOM

## Analysis

## References
