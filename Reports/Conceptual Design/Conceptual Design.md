## Comparative Analysis of Potential Solutions

# Potential Solutions for Power Line Charging

Half Wave Rectifier:
Due to the charging capabilities of the drone attachment, a half wave rectifier to assist in current displacement through the load and into our capacitor plate was considered. Half wave rectifiers are lighter in weight and cheaper overall. Maximum payload for drones is not very high so all types of circuit conditions need to be considered for the operation. The simple design may be needed for payload and an additional non-critical application of half-wave rectifiers could be essential for our charging mount.

Full Wave Rectifier:
A full wave rectifier was also considered for the load charging capabilities it produces. The full-wave rectifier converts both haves of the AC waveform into a DC output, this could be implemented as a bridge rectifier with four diodes. This full wave rectifier gives a lower ripple and better power delivery for the same peak voltage. This improves efficiency and reduces stress on the energy storage with time. Although it seems like the perfect fit, weight is still a major factor in decision making procedures.

Capacitor Load:
Using a capacitor stores energy delivered by the rectifier and will supply short bursts to the downstream internal drone battery. Rectified AC will charge the capacitor, then the capacitor will displace current to the downstream battery when needed. A capacitor load is considered for its smooth output and high instantaneous power at output. Capacitors are very hefty though, using a capacitor really negates how much payload a drone could carry, a DC-DC converter will also be needed because the capacitor falls linearly at discharge.

Battery Load:
Using the internal batteries as the primary energy sink on the mounting device to trickle charge the drone is also considered. The rectifier is designed to safely charge the battery which will provide regulated and dense energy storage for the drone. Charging these internal batteries could be an issue due to safety risks and could need temperature monitoring. A battery management system will need to be implemented as well.

# Potential Solutions for Corona Detection and Camera Sensing

Infrared/Thermal Imaging:
A potential solution for detecting excess corona can be solved with an IR camera which generates localized heating to do ionization and current leaking. Infrared and thermal imaging can detect heat signatures to pinpoint areas of excess thermal signatures or arcing. IR detects emitted infrared radiation hotspots, which will allow for identification of stressed components. These cameras can also monitor overloaded connections and mechanical stress. These are affected by temperature and wind and will need extensive calibration strategies to distinguish excess corona from other thermal sources.

Ultraviolet Imaging Sensors:
Corona discharge emits energy mostly in the ultraviolet spectrum, making UV imaging one of the most reliable methods. These specialized cameras detect UV photons from ionized air near high-voltage conductors in daylight conditions. UV sensors capture short-wavelength emissions, invisible to the naked eye, to identify intensity and location of strongly correlated corona activity. They do need shielding from sunlight to prevent false positives and can be relatively expensive.

Optical/Visual Spectrum Cameras (RGB/Multispectral):
High resolution RGB or multispectral cameras will be useful in providing confirmation of physical damage, arcing, and surface degradation. Image processing and machine learning algorithms can also detect characteristic color changes, carbon tracking, and visible arcing patterns to assist in areas where excess corona could occur. These are readily available at a low cost with very lightweight camera modules. It cannot directly see corona discharge and may be affected by glare.

Depth/Stereo Cameras:
With many drones having their own attached camera, a stereo or structured light camera can compute depth by comparing two or more visual perspectives. These could provide depth maps for autonomous navigation and terrain avoidance which are beneficial for identifying tower geometry and wire positioning. These cameras can be potentially power straining and are sensitive to sunlight interference.

# Potential Solutions for Communication and Computing

Raspberry Pi Zero:
The original Raspberry Pi Zero is a very minimalist, single core computer designed for very low power embedded applications. It does require external Wi-Fi or Bluetooth dongles for communication. The power draw and weight are extremely low compared to other solutions but comparable to the Raspberry Pi Zero 2 W. It will be good for monitoring charging status and battery voltage and current and forwarding periodic GPS position data. It only operates with a single CPU core with 512 MB of RAM, so it cannot handle multitask heavy computations and extreme camera based processing.

Raspberry Pi Zero 2 W:
The updated Raspberry Pi Zero 2 W provides an updated performance over the original Zero while maintaining a very similar size and weight profile. It features a 1 GHz processor with a 512 MB RAM and built in Wi-Fi and Bluetooth capabilities. This provides onboard computations and wireless communication capabilities without external connection. The extra processing allows for reading voltage/current sensors and logging GPS data through a ground Wi-Fi station. It also has the ability to run lightweight image recognition.

Texas Instruments INA3221:
The TI is a triple channel, high side current and bus voltage monitor made to measure voltage and current across up to three separate power rails. The design can be implemented to have Channel One monitor the battery, Channel 2 monitor the charging current, and Channel Three monitoring the payload. It communicates over the I^2C bus which allows easy communication with the Raspberry Pi for real time updates. The issue occurs with voltages over 26 V where it can no longer measure and requires very precise shunt resistors.

ADS1115 + Discrete Shunt Amplifiers:
The ADS1115 is a 16-bit, low power analog to digital converter that communicates with I^2C and provides up to four input channels. Each channel can be connected across a shunt resistor placed in current paths and amplified which will then be fed to the Raspberry Pi. It has very low power consumption and flexible gain and channel configuration. It has no maximum voltage measurement as well. It does need extra components and is most susceptible to noise.

u-blox ZED-F9F:
The ZED-F9F is a high precision dual-band, multi-constellation receiver designed for advanced GPS applications. It has four satellite connections leading to accurate location finding within one meter. It can output velocity and heaving with low latency, using up to 30 Hz update rates. It draws around 50-70 mA and also uses I^2C communication. It uses Real-Time Kinematic which is ideal for real time updates of drone location and while using this setting location can be found at approximately 1 cm.

# Potential Solutions for Battery and BMS

Lithium-Ion Battery Pack:
The Lithium-Ion Battery Pack is the most common choice for drones and portable power. It has high energy density, lightweight construction and stable voltage characteristics. A Li-Ion pack configured as a 4S or 6S, which is 14.8V-22.2V nominal, provides a suitable balance of energy storage and weight. When integrated with proper current limiting and BMS protection, it offers long term service of around 500-1000 cycles.

Lithium-Polymer Battery Pack:
The Lithium-Polymer Battery is a subtype of Li-Ion chemistry using a polymer electrolyte which offers higher discharging rates and very light packaging. These are often used in UAVs where high current draw and rapid power responses are required. An Li-Po configuration can deliver high current outage while remaining lightweight but must be paired with a robust BMS to avoid over discharge and contain a shorter lifespan of around 200-300 cycles.

Texas Instruments BQ76930:
For a Battery Management System (BMS) the formerly listed ADS1115 and INA3221 will do more than suffice but a third option could be BQ76930. It provides essential monitoring and protection features: cell voltage measurement, overcurrent protection and cell balancing. It also communicates with I^2C, making it compatible with the Raspberry Pi. It lacks digital configuration customization and is not built with Coulomb counting.

# Potential Solutions for Mechanical and Structural Subsystems

LW-PLA For 3D Printing:
The LW-PLA filament is a foaming thermoplastic material that has a low-density internal structure without requiring a hollow infill. When heated to approximately 220-250 C, the polymer foams resulting in a weight reduction of 30-50% compared to standard PLA, this is crucial for low weight operations. It is easy to print on common FDM printers. It will be most commonly used on areas where high mechanical strength is not required and is sensitive to heat and UV exposure.

PA12 for 3D Printing:
Polyamide-12 is a professional grade material printed using Selective Laser Sintering. It is very common for lightweight structural parts due to it’s excellent mechanical properties, impact resistance, and low moisture absorption. SLS printing does not require support structures which make hollow internal geometries and highly optimized that are both strong and extremely light. This is ideal for mounts, arms, and moving parts where rigidity and weight efficiency are required. It does need outsourced printing and post processing which lead to longer lead times.

Telescoping Extension for Line Connecting Hook:
A telescoping extension uses nested tubes or rails that slide linearly to extend reach. It’s compacted form at rest and longer reach when opened is useful for latching onto a power line from a safer standoff. Nested sections with a round or rectangular profile slide out in sequence by a passive or active drive mechanism that push sections to extend and retract. It has a possibility to have minor sealing and debris issues and could potentially be flexible if extended too thin, vibration from the line and weather conditions must be considered.

Linear Axis Arm for Line Connection Hook:
A linear axis arm uses a rotating axle to convert rotary motion into a linear motion to extend a rigid arm. This will use either a motor or piston to drive the arm up to connect to the line and then let it lay down after disconnection. These decreases moving part counts and is not affected by debris or weather. It is much more accurate and easier to control precisely with less failure points but could increase weight of the mechanism and the stowed volume is unchanged.

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

