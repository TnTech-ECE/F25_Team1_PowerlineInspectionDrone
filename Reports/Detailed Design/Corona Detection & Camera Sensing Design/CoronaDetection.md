# Detailed Design

## Function of the Subsystem

The Corona Detection and Camera Sensing Subsystem is responsible for helping the ArcAngel Drone identify and confirm corona discharge problems on high‑voltage power lines. The ultraviolet (UV) sensor detects the invisible light emitted when corona occurs, which serves as an early indicator of insulation damage or electrical stress. In parallel, the camera provides visual support by assisting with drone navigation and capturing images of any visible damage to the conductors or supporting structures. By combining invisible UV detection with visible imagery, the subsystem delivers more reliable results and reduces the chance of false positives. This integration makes inspections safer and more efficient, allowing crews to spot potential issues early and respond quickly with accurate, actionable information.



## Specifications and Constraints

The Corona Detection and Camera Sensing Subsystem must meet defined specifications to ensure reliable operation while adhering to physical, electrical, and standards‑based constraints.

### Specifications

- **Thermal Imaging Capability:** The subsystem shall be able to record and store thermal imagery of power line components.
- **Camera Performance:**
  - **Resolution:** 256×192
  - **Frame rate:** 25 fps
  - **Interface:** Composite Video Blanking and Sync (CVBS) analog output for integration with FPV systems
- **Recording Module:**
  - **Onboard storage:** First person view (FPV) digital video recorder (DVR) module capable of recording video streams onboard storage
  - **Modes:** Switchable modes for live transmission and recording
  - **Power:** Integrated battery for independent operation

### Constraints

- **Weight:** Combined subsystem weight must remain under 150 g to comply with FAA Part 107 drone mass limits and preserve flight endurance.
- **Cost:** Subsystem bill of materials (BOM) cost must remain below $640 to meet stakeholder affordability requirements.
- **Power Consumption:** The thermal camera and DVR module must operate within a combined power budget of around 2.5 W to align with the Arduinos power constraints.
- **Supply Voltage:** Both modules must be compatible with regulated 3.3–5 V DC from the Arduinos output pins.
- **Standards Compliance:**
  - **IEC 61000 (Electromagnetic Compatibility):** The subsystem must meet conducted and radiated emission limits and demonstrate immunity to disturbances such as electrostatic discharge and RF interference. This requires EMI shielding, filtering in the PCB design, and compliance testing.
  - **FAA Part 107:** Weight and altitude limits constrain subsystem design and integration.



## Overview of Proposed Solution

The Corona Detection and Camera Sensing Subsystem will utilize the **Axisflying High‑Resolution Mini Thermal FPV Camera** as the primary imaging device. This camera provides thermal imagery of transmission line components, enabling the detection of abnormal heat signatures that may indicate electrical stress, arcing, or insulation faults. The camera outputs video through a CVBS analog interface, which is lightweight and compatible with FPV systems commonly used in drone applications.

To capture and store this footage, the subsystem will integrate the **Mini FPV DVR Recorder, Video Capture Module**. This recorder includes a built‑in battery and supports up to 32 GB of onboard storage via a TF card. The DVR module allows for both **live transmission** of thermal video during flight and **local recording** for post‑mission analysis. Recorded footage is stored directly on the TF card, which can be removed after flight and reviewed on a computer to identify potential issues along the transmission lines.

This solution provides a simple, modular, and cost‑effective architecture. The DVR ensures that all inspection data is preserved for later review. Together, these components meet the subsystem’s requirements for lightweight design, low power consumption, and compliance with FAA and IEC standards, while providing operators with reliable diagnostic information to support preventative maintenance and safe power line operation.



## Interface with Other Subsystems

The Corona Detection and Camera Sensing Subsystem interfaces with both the **Mechanical Subsystem** and the **Control/Compute Subsystem** to ensure proper integration and reliable operation.

- **Mechanical Subsystem:** The thermal camera and FPV DVR modules are mounted within a protective housing designed by the mechanical subsystem. This housing provides structural support. It also ensures proper alignment of the camera’s field of view with the transmission lines under inspection. Mounting brackets and modular enclosures allow for easy replacement or upgrades of the camera and DVR components.
- **Control/Compute Subsystem:** The subsystem draws regulated DC power from the drone’s onboard electronics, managed by the control/compute module. Power is supplied through the Arduino interface.

Together, these interfaces ensure that the Corona Detection and Camera Sensing Subsystem is mechanically stable, electrically reliable, and fully integrated into the drone’s overall architecture.



## Flow Chart

<img width="1075" height="696" alt="Screenshot 2025-11-23 231027" src="https://github.com/user-attachments/assets/9008ebdf-eca2-4477-9b5a-42c1010aa342" />
<img width="696" height="414" alt="Screenshot 2025-11-25 125041" src="https://github.com/user-attachments/assets/93eb5eb4-2e50-4c01-8847-ad56716dd0d2" />



## BOM

| Component Name         | Manufacturer | Distributor               | Distributor Part # | QTY | Price   |
|------------------------|--------------|---------------------------|--------------------|-----|---------|
| Thermal Camera Module  | Axisflying   | Banggood                  | 2040939            | 1   | $279.99 | 
| Mini FPV DVR Recorder  | Segrehy      | Amazon (Sold by Kangtes)  | ASIN B0DPJWVW8J    | 1   | $31.71  |

https://usa.banggood.com/Axisflying-High-Res-Mini-Thermal-FPV-Camera-Module,256%C3%97192-or-384%C3%97288-or-640%C3%97512-Options,OEM-Series-w-or-CVBS-Analog-Interface-Low-Power-Consumption-for-Drones-p-2040939.html?utm_source=bingshopping&utm_medium=cpc_organic&gmcCountry=US&utm_content=minha&utm_campaign=aceng-pmax-usg-pc&currency=USD&cur_warehouse=CN&createTmp=1&ID=6335015&utm_source=bing_pa&utm_medium=cpc_us&utm_content=sandra&utm_campaign=aceng-bpla-pmax-usg-all-230819-gmc&ad_id=&msclkid=7e0bddb90f8a1b89f055b4a794059bf0 

https://www.amazon.com/Module-Switchable-Built-Battery-Recorder/dp/B0DPJWVW8J 



## Analysis

The proposed subsystem design effectively meets the requirements for detecting and recording thermal anomalies on transmission lines while adhering to the defined constraints.


•	Functional Performance: The Axisflying thermal camera provides thermal imagery at 256×192 resolution and 25 fps, which is sufficient to identify abnormal heat signatures such as localized hotspots, resistive heating, or early signs of insulation breakdown. The Mini FPV DVR module captures this video stream and stores it on a TF card, ensuring that inspection data can be reviewed post‑flight for accurate fault localization. Together, these components fulfill the specification for thermal imaging capability and recording.

•	Power and Electrical Constraints: The thermal camera requires a regulated 5 V input, which can be supplied from the drone’s onboard electronics via the Arduino interface. The combined power draw of the camera and DVR is approximately 2.5 W, well within the subsystem’s defined power budget. This ensures compatibility with the drone’s limited energy resources and avoids overloading the control electronics. The DVR’s integrated battery also provides resilience against voltage dips, protecting data integrity.

•	Weight and Cost Compliance: Both modules are lightweight, and when combined with mounting hardware remain under the 150 g limit, preserving drone endurance and meeting FAA Part 107 requirements. The total subsystem cost, including camera and DVR, is below the $640 ceiling, satisfying affordability constraints for stakeholders.

•	Connectivity and Integration: The DVR module includes two 3.5 mm AV cables, which provide straightforward connections between the thermal camera’s CVBS output and the DVR’s AV input. This reduces integration complexity and ensures reliable data transfer. The modular design also allows easy dismounting and replacement of components, supporting maintainability.

•	Standards Compliance: The subsystem design incorporates EMI shielding, filtered power inputs, and shielded cabling to meet IEC 61000 electromagnetic compatibility requirements. This ensures immunity to disturbances such as electrostatic discharge and radiated RF fields, which are common near high‑voltage transmission lines. 


#### Conclusion
By combining a lightweight thermal camera with a compact DVR module, the subsystem achieves its intended function of detecting and recording thermal anomalies on transmission lines. It satisfies all defined constraints—weight, cost, power, voltage, and standards compliance—while providing a simple, modular architecture that is easy to integrate and operate. This analysis demonstrates that the design is both feasible and effective for safe, reliable power line inspection missions. 



## References 

[1] Axisflying, "High Res Mini Thermal FPV Camera Module, 256×192/384×288/640×512 Options, OEM Series w/ CVBS Analog Interface Low Power Consumption for Drones," Banggood USA. [Online]. Available: https://www.banggood.com/. [Accessed: Nov. 26, 2025].

[2] Segrehy, "Mini FPV DVR Recorder, Video Capture Module with Built-in Battery & 32GB TF Card Support, NTSC PAL Switchable for FPV Drone RC Model Racing Car," Amazon.com. [Online]. Available: https://www.amazon.com/. [Accessed: Nov. 26, 2025].

[3] "Ultraviolet, thermal cameras: high tech solutions for corona discharges," [Online]. Available: (insert publisher or source URL if known). [Accessed: Nov. 26, 2025].

