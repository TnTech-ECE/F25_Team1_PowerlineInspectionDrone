

## Ethical, Professional, and Standards Considerations

The proposed drone system for power line charging and corona detection carries significant implications across culture, society, the environment, public health, safety, and the economy. At its core, the project addresses a critical societal need: maintaining reliable electrical infrastructure while reducing risks to human workers. By shifting inspection and charging tasks from manual crews and helicopters to lightweight autonomous drones, the project enhances public safety. This transition also strengthens public trust in utility providers by ensuring that inspections are performed more frequently, more safely, and with greater precision.

From an environmental perspective, the drone system reduces reliance on fuel-intensive inspection methods, lowering carbon emissions and minimizing the ecological footprint of routine maintenance. The potential use of lightweight materials such as LW‑PLA or PA12, combined with potential efficient energy storage solutions like Li‑Ion or Li‑Po batteries, further reduces energy consumption during flight. 

Public health and safety are central to the project’s mission. By removing workers from high-voltage environments, the risk of electrocution, falls, and other occupational hazards is significantly reduced. The design incorporates safety-critical features such as a Battery Management System (BQ76930) to prevent overcharge, overcurrent, or thermal runaway, and robust mechanical subsystems that can withstand vibration, weather, and debris without failure. These practices ensure that the drone operates reliably in the field without posing risks to bystanders or infrastructure. Indirectly, the project also supports public health by safeguarding the continuity of power delivery, which is essential for hospitals, schools, and emergency services.

Economically, the project offers long-term cost savings by reducing the need for manned inspections and extending the lifespan of power infrastructure through early detection of faults. The modular design approach, which leverages 3D‑printed components for non-critical parts and durable PA12 for structural elements, reduces prototyping and replacement costs. Sensor selection also reflects economic considerations: while ultraviolet cameras provide the most accurate corona detection, they are expensive, so pairing them with lower-cost RGB or multispectral cameras balances precision with affordability. Similarly, Li‑Ion batteries are prioritized for their longer cycle life, reducing replacement frequency compared to Li‑Po packs.

The design process is guided by established standards organizations to ensure compliance, safety, and interoperability. IEEE standards inform the design of rectifiers, communication protocols, and power electronics. IEC standards govern safety requirements for high-voltage equipment and corona detection instrumentation. FAA regulations constrain drone weight, altitude, and autonomous operation, shaping the overall system architecture. UL certification standards for battery safety and ISO guidelines for environmental and quality management further influence material selection, lifecycle planning, and operational practices. Together, these standards ensure that the system is not only technically sound but also safe, sustainable, and legally compliant.

In summary, the broader impacts of this project have directly shaped subsystem choices and design practices. Weight constraints drive the use of lightweight materials and compact electronics; safety requirements necessitate robust BMS integration and sensor calibration; and economic realities guide sensor pairing and modular construction. By aligning with international standards and addressing cultural, societal, environmental, health, safety, and economic impacts, the project delivers a balanced, responsible, and forward-looking solution for power line inspection and charging.


## Resources

### Budget

The total estimated budget for this project is approximately $640, which covers the essential components needed to build a functional prototype drone housing for transmission line inspection. This includes the drone platform, basic sensors, onboard computing,  spare batteries, and components required for charging off of a transmission line. The budget is kept intentionally low by leveraging school-provided lab equipment and low-cost commercial parts.

| **Item**                          | **Description**                                         | **Estimated Cost**      |
|----------------------------------|---------------------------------------------------------|--------------------------|
| **Mechanical/Structural**         |                                                         |                          |
| Drone Base Platform              | Base drone to attach our hardware to                    | Provided by School/Customer |
| 3D Printing Filament             | Filament to print our housing and mounts               | $75                |
| Power Line Hook Assembly   | Conductive hook and insulation materials for safe attachment to transmission line | $75|
| **Subtotal**         |                                                                    |  $150              |
| **Power Line Charging**                |             |               |
| Rectifier + Coupling Circuit Components   | Diodes, capacitors, resistors, and wiring for AC-DC conversion | $100      |
| Metal Plate | Metal plate acting like a coupling capacitor,s providing a path to ground        | $20                     |
| Voltage Divider | Components for voltage divider regulating drone battery voltage        | $30                    |
| BMS | Component to protect battery        | $70                   |
| Drone Battery | Extra drone battery in case of failure        | $50                   |
| **Subtotal**         |                                                                    |  $270              |
| **Sensing and Communication**           |  |             |
| Raspberry Pi Zero | Minimalistic lightweight onboard computer                     | $15              |
| UV Sensor | Minimalistic lightweight UV sensor for detecting excess corona                     | $30              |
| User UI | Web-based dashboard usable on a phone, tablet, or laptop with access to the internet    | $25              |
| **Subtotal**         |                                                                    |  $70              |
| Unforseen Expenses | Expenses not yet thought about like leads, safety equipment, etc.                     | $150             |
| **Project Total**         |                                                                    |  $640            |

### Division of Labor

After evaluating the skills of each team member and the requirements of the project’s subsystems, responsibilities were assigned to align with individual strengths and expertise.

Power Line Charging - Matthew Henderson

Corona Detection and Camera Sensing - Lawson Stricklin

Communication/Computing - Daniel Attih

Battery Safety (BMS) - Brady Goodman

Mechanical/Structural - Grant Christy

### Timeline

![Gantt Chart](gantt%20chart.png)

The capstone team has one academic year to design and develop a drone housing for power line inspection. The drone will be capable of detecting excessive corona discharge and will also incorporate a system to recharge from the transmission line.

In the first semester, the focus will be on defining the project scope, breaking it into smaller tasks, and beginning the design process.

During the second semester, the team will refine the prototype, finalize parts and specifications, and move into system integration. The final phase includes building, testing, troubleshooting, and validating the completed drone.

If the team follows the schedule outlined in the Gantt chart, the project will result in a fully functional inspection drone by May 2026.

