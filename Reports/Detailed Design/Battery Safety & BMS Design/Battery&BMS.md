## Function of the Subsystem

This segment should elucidate the role of the subsystem within the entire system, detailing its intended function, aligned with the conceptual design.


## Specifications and Constraints

This section should provide a list of constraints applicable to the subsystem, along with the rationale behind these limitations. For instance, constraints can stem from physics-based limitations or requirements, subsystem prerequisites, standards, ethical considerations, or socio-economic factors.

The team should set specifications for each subsystem. These specifications may require modifications, which must be authorized by the team. It could be necessary to impose additional constraints as further information becomes available.

Every subsystem must incorporate at least one constraint stemming from standards, ethics, or socio-economic factors.


## Overview of Proposed Solution

Describe the solution and how it will fulfill the specifications and constraints of this subsystem.


## Interface with Other Subsystems

Provide detailed information about the inputs, outputs, and data transferred to other subsystems. Ensure specificity and thoroughness, clarifying the method of communication and the nature of the data transmitted.

## Buildable Schematic 

Integrate a buildable electrical schematic directly into the document. If the diagram is unreadable or improperly scaled, the supervisor will deny approval. Divide the diagram into sections if the text and components seem too small.

The schematic should be relevant to the design and provide ample details necessary for constructing the model. It must be comprehensive so that someone, with no prior knowledge of the design, can easily understand it. Each related component's value and measurement should be clearly mentioned.


## Printed Circuit Board Layout

Include a manufacturable printed circuit board layout.

## BOM

# Battery & BMS Subsystem – Bill of Materials (BOM)

| Item | Component Description | Part Number | Vendor | Qty | Price (USD) | Notes |
|------|------------------------|-------------|--------|-----|--------------|-------|
| 1 | High-Voltage 10 MΩ Resistor (0.5 W, 10 MΩ) | **VR37000001005FR500** | Mouser | 3 | $2.28 ea | Withstands >3.5 kV; used for voltage scaling from harvested line potential |
| 2 | High-Voltage 4.7 MΩ Resistor (demo/alt value) | VR37000004704FR500 | Mouser | 3 | $2.10 ea | Same family as above, alternative scaling configuration |
| 3 | High-Voltage 2.2 MΩ Resistor (demo option) | VR37000002204FR500 | Mouser | 3 | $1.98 ea | For flexibility in proof-of-concept tuning |
| 4 | Isolation DC-DC Converter, 48 V → 12 V, 2 W | **TDK-Lambda CC3-4812DF-E** | Digi-Key | 1 | ~$24.00 | Lightweight isolated DC–DC converter, safe for harvested AC/DC input |
| 5 | Buck Regulator Module, 12 V → 5 V (USB) | **Murata OKI-78SR-5/1.5-W36H-C** | Digi-Key | 1 | ~$8.75 | Efficient, lightweight, 1.5 A output; ideal for USB-C source power |
| 6 | USB-C Power Source Controller (5 V only) | **Microchip USB Type-C Configuration Channel Controller – UPD301C-A** | Digi-Key | 1 | ~$1.90 | Configures CC1/CC2 for safe 5 V USB source role |
| 7 | USB-C Receptacle (Mid-Mount) | **GCT USB4085-GF-A** | Digi-Key | 1 | ~$1.15 | Lightweight and robust USB-C connector |
| 8 | Input Fuse (Resettable PTC) | **Bourns MF-R050** | Digi-Key | 1 | ~$0.42 | Protects subsystem from input faults |
| 9 | TVS Diode for Surge Protection | **SMBJ58A** | Digi-Key | 1 | ~$0.65 | Protects against surges from harvester front-end |
| 10 | Drone Battery (Spare) | **Parrot Anafi USA Battery Pack** | Parrot Store | 1 | ~$79.00 | Spare 11.55 V, 6800 mAh LiPo battery |
| 11 | Standard USB-C Cable | Anker (or equivalent) | Amazon | 1 | ~$7.99 | Connects subsystem to drone charge port |
Total Cost: $153.09

## Analysis

Deliver a full and relevant analysis of the design demonstrating that it should meet the constraints and accomplish the intended function. This analysis should be comprehensive and well articulated for persuasiveness.

## References

[1] USB Implementers Forum, USB Type-C Cable and Connector Specification, Release 2.2, Aug. 2022.
[2] Digi-Key Electronics, “Murata MGJ2 Series Dual-Output Isolated DC-DC Converters – Datasheet and Specifications,” 2024. [Online].
[3] Texas Instruments, “TPS54531 5-A, 28-V Input Step-Down DC-DC Converter,” Datasheet, 2023.
[4] Texas Instruments, “TPS25940 eFuse and Over-Voltage Protection Switch,” Datasheet, 2022.
[5] TE Connectivity, “USB Type-C Receptacle Connector 12401610E001A – Product Specification,” 2023.
[6] Vishay Dale, “High-Voltage Thick-Film Resistors VR37 Series (VR37000001005FR500),” Datasheet, 2024.
[7] Parrot Drones SAS, Anafi USA / Anafi Series – Battery Specifications and Safety Guidelines, 2023.
[8] M. Petkovšek, J. Persolja, and M. Avgustin, “Design Considerations for Energy Harvesting from High-Voltage Transmission Lines,” IEEE Transactions on Power Delivery, vol. 35, no. 6, pp. 2801–2810, Dec. 2020.
[9] A. K. Shukla and S. Sampath, “Li-ion Batteries: Principles, Materials, and Applications,” Annual Review of Materials Research, vol. 50, pp. 493–529, 2020.
[10] H. Zhang, X. Wang, and P. Li, “Design of Safe Charging Systems for Lithium-Ion Packs Using USB-C Power Delivery,” IEEE Transactions on Power Electronics, vol. 37, no. 4, pp. 4211–4224, Apr. 2022.
