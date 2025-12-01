# Mechanical and Structural Detailed Design

## Function of the Subsystem
The Mechanical and Structural subsystem design for the Arc Angel drone implementation includes 
housing for all of the other subsystems including: Battery Safety and BMS Design, Control and 
Communication Design, Corona Detection and Camera Sensing, and the Power Harvesting and Charging
Design. 

The Structural Design function will need to effectively house all of the components internally.
This will be achieved by having casings to give structural support to all the subsystems in the
housing undercarriage shown in Figure 2 below. A major confrontation to the
Structural Design is the weight distribution and mass of the housing. It will ensure that
the subsystems housed will not have any displacement from original placement realitive to the 
housing design. The Structural Design shall also not severely effect drone flight, the system
will use major fluid mechanic design and weight distribution to keep flight efficiency as a top
priority.


The Mechanical Design lies mostly in the connection from the Housing and Harvesting Designs
to the power lines that the entire system will be designed around. It ensures safety and opperational
ease in attachment and deattachment from power lines. Once set in a need of charge state, the 
Mechanical Design will communicate with the Control Design to raise and lower an arm on the above
drone housing system that will hook onto the power line. This hook, listed in Figure 3, will provide connection from the line to the Power Harvesting and Charging Subsystem.


## Specification and Constraints
Specifications:
- The Structural Design subsystem shall not affect drone flight or stability.
- The Structural Design subsystem shall be stable and not be affected by weather.
- The Structural and Mechanical design should interface with all other subsystems when needed.
- The Mechanical Design subsystem shall be a stable connection to the power line.
- The Mechanical Design subsystem shall operate around a linear axis scale and not affect drone flight.

Constraints:
-The Structural Design shall keep total capacity under 200 g.
-The Mechanical Design shall provide line-to-harvesting system connection.


## Overview of Proposed Solutions
This system includes the following devices and material:
- LW-PLA: Light weight, stable material for Structural and Mechanical subsystem.
- MG90S Mini Gear Servo: Lightweight, low gear 180 degree servo motor for hook-to-line connection.
- Dome Undercarriage Housing: Aerodynamic, larger space housing for all other subsystems.
- Linear Axis Hook: Efficient and stable connection for line-to-harvesting connection.
- Claw Hook: Provides stability from drone-to-line connection.
- Housing to Drone Connection: Screw housing to drone leg connection to provide stability and simplicity for housing.


## Interface with Other Subsystems
| Subsystems | Interfacing | Connection | Notes |
|------------|-------------|------------|-------|
| Battery and BMS | Supply to ground connection for servo. Housing for stability | Direct positive and ground wire connection. LW-PLA Housing. | 4.8-6V needed for servo application |
| Control and Communication | I^2C Commmunication for 90 degree servo rotation. Housing for stability | Direct one wire connection for dual motion. LW-PLA Housing | Recieves positive or negative degree motion to raise and lower arm |
| Corona Detection and Camera Sensing | External housing connection to undercarriage drone. | LW-PLA external housing | Provides camera and corona detection mounting and pathway to communication devices |
| Power Harvesting and Circuit Design | Hook-to-line connection. Internal housing for stability | Provides single wire connection directly from power line to circuit system. | Allows power draw from power line to internal power harvesting system |


## 3D Models and Buildabe Schematic of Custom Mechanical and Structural Components
Figure 1: MG90s Micro Servo:

<img width="802" height="627" alt="image" src="https://github.com/user-attachments/assets/69c6d31e-b458-40c6-b3bc-a8fddaed869a" />

Figure 2: Structural Subsystem:

<img width="1113" height="807" alt="image" src="https://github.com/user-attachments/assets/176e0940-9a26-4ebd-a275-8facb0581ee8" />

Figure 3: Mechanical Subsystem:

<img width="1031" height="717" alt="image" src="https://github.com/user-attachments/assets/e1ae0ac0-dbda-4284-8d83-ebe39d97a758" />

## Printed Circuit Board Layout

## Flowchart
<img width="1920" height="1080" alt="Structual   Mechanical" src="https://github.com/user-attachments/assets/f243fabb-c983-4541-9552-0a78239d7463" />

## Bill of Materials (BOM)
| Item | Quantity | Part Number / Model | Description | Price |
|------|----------|---------------------|-------------|-------|
| PolyLite LW-PLA | 1 | PA08001 | Lighweight PLA (0.6g/cubic cm) | ~ $33 USD |
| MG90S Mini Gear Servo | 1 | SERVO-MG90S-2 | Mini 180 degree servo | ~ $5 USD |
| 18 Gauge Aluminum Wire | 50 ft. x 1-1/4 in. | 534694 | Conductive Wire for Hook | ~ $6 USD |

## Anaysis
LW-PLA:
- LW-PLA from PolyLite is a very lightweight and highly durable PLA used for many applications. The two biggest needs for drone operation are mainting low capacity goals and being stable during flight. LW-PLA has a density of 0.6g/cm^3, being extremely light for small applications. The hook for the drone, shown in Figure 3, will need high tensile strength to maintain the coil's stability around the hook. The PolyLite LW-PLA has a tensile strength of 23.2 MPa, which is crucial for long life expectancy.
  
Under Drone Housing:
- The Under Drone Housing will implement a dome as the main space to house all internal subsystems. The dome is cruicial to not affect drone flight or stability. By setting the dome placed directly on the center of mass, it keeps prior drone operation similar if not the same. The dome housing system will also maintain all internal housing systems by layering devices based on size and prioritizing centralizing mass.
  
MG90S Mini Servo:
- The MG90S servo is a minilmal, lightweight, low gear micro servo used on RC applications. It has 180 degrees of rotation which will raise and lower the hook to connect the power line to the Power Harvesting Subsystem. The low gear system is cruicial for slow, methodical movement to allow the user time to operate line connection effectively.

Hook Connection:
- A hook design has been implemented to allow easy access to the power line with stable connection. The hook allows for line connection stability with gravity forced connection after the drone has been connected in place and keeps contect with the line. A coil around the trunk of the hook will provide stability and small flexibility to the line while decreasing weight gain on the top of the drone. This is very important to not affect drone flight operation. 

18 Gauge Aluminum:
- 18 Gauge Aluminum is the best choice for line to power harvesting system connection due to the light weight and highly conductive material. 18 Gauge Aluminum, or 6061-T4 Aluminum, has conductivity of 2.534 e7 (Siemens/m) and a resistivity of 3.914 e-8 (Ohm-m). This is cruicial to allow high energy flow from the power line to the power harvesting system. The hooking system will provide stability to this wire, which is fairly bendable.

## References
https://www.electronicoscaldas.com/datasheet/MG90S_Tower-Pro.pdf?srsltid=AfmBOor2NFDJKFQzSEaFWy265cbKKH7PoAjnbNWc5FnZWOXvCtP_IUMd

https://grabcad.com/library/mg90s-micro-servo-2

https://content.ndtsupply.com/media/Conductivity_Al%20Reference%20Chart.pdf

http://homedepot.com/p/OOK-1-1-4-in-x-50-ft-10-lb-18-Gauge-Aluminum-Wire-534694/301977350?source=shoppingads&locale=en-US&srsltid=AfmBOop1IXpyk19yQGG_HrR95LBN4prLwpjBVN4I3ryCrGxJPmbosMdDcgA























