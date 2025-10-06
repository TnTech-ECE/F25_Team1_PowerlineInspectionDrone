# ArcAngel Power Line Inspection Drone

### Matthew Henderson, Brady Goodman, Grant Christy, Daniel Attih, Lawson Stricklin

Department of Electrical and Computer Engineering

Tennessee Technological University

mghenderso43@tntech.edu, brgoodman42@tntech.edu, gbchristy42@tntech.edu, dattih42@tntech.edu, lwstrickli42@tntech.edu

## Introduction

Electrical power infrastructure is one of the most critical assets in modern society, yet it remains vulnerable to damage from storms, environmental stress, and equipment aging. Traditionally, inspection of high-voltage power lines has relied on bucket trucks, helicopters, and personnel climbing utility poles. These methods shall continue to pose safety risks, high operational costs, and limited efficiency [4]. There shall be a safer, more autonomous, and cost-effective method of performing routine and emergency inspections.
The proposed project, ArcAngel Drone, is a semi-autonomous inspection system specifically designed to operate near power lines and identify potential faults. Unlike existing solutions that are limited by flight time and require constant operator control, ArcAngel Drone shall feature autonomous navigation, onboard corona detection, and the capability to recharge directly from high-voltage lines using single-wire energy transfer. Research prototypes have already demonstrated the feasibility of UAV-mounted corona detection sensors [7], [13], [18] and live-line recharging through electromagnetic energy harvesting [2], [5], [14], [20]. These features shall enable extended missions, rapid post-storm response, and reduced downtime for electric grids. For customers such as power utilities, this technology provides faster fault localization, minimized repair delays, and significant cost savings compared to traditional inspection methods [8], [9].

The stakeholders for this project include the instructor, who shall evaluate academic performance; the technical supervisor, who shall guide the engineering process; the customer, represented by electric utilities and line maintenance teams, who shall benefit directly from improved inspection safety and efficiency; and the project team members, who are responsible for the design, implementation, and validation of ArcAngel Drone. Successful implementation shall require skills in embedded systems, power electronics, communications, and autonomous navigation. The estimated project cost shall not exceed $2,500, with completion expected within the senior design project timeline.

The customer benefits are clear: ArcAngel Drone reduces human exposure to hazardous environments, lowers inspection costs, and increases operational adaptability during grid failures. Broader impacts extend to environmental sustainability by replacing helicopters and heavy trucks, thereby reducing carbon emissions, as well as ethical responsibilities in ensuring safe operation, reliability, and data privacy [3], [10], [11], [12], [15], [16]. While challenges remain, including regulatory compliance and preventing technical failure near live lines, ArcAngel Drone represents a meaningful advancement in both engineering practice and public safety.

Proposal Roadmap

The remainder of this proposal is organized into the following sections:

•	Problem Definition and Objectives – specifying requirements with “shall” statements.

•	Background and Existing Solutions – reviewing prior drones and enabling technologies.

•	Methodology and Design Plan – describing the approach to development.

•	Project Management – outlining resources, costs, skills, and schedule.

•	Success Criteria and Evaluation – defining metrics for performance.

•	Customer Benefits and Broader Implications – addressing value and ethical responsibility.

•	References – citing supporting sources.

•	Team Contributions – stating each member’s role.


## Formulating the Problem

Consumers lack a reliable and efficient tool that can effectively follow high-voltage power lines for extended periods after significant storms or other disruptive events. Utility crews are typically dispatched to locate malfunctioning or downed lines, but pinpointing the exact locations can be difficult and time-consuming. Autonomous drones capable of performing effective follow-and-inspect missions could save significant repair time and reduce the duration of inoperable substations.

ArcAngel Drone is a semi-autonomous aerial system designed to operate within a specified distance of a power line while relaying high-resolution video and detecting excess corona discharge without continuous human control. This capability would allow ground personnel to rapidly locate and safely repair downed or damaged lines. ArcAngel Drone is intended to be weather-resistant and operable under mild post-storm conditions.

Key challenges include:
- Autonomous navigation adjacent to high-voltage conductors.
- Sustaining stable flight and effective videography during mild to inclement weather.
- Reliable detection of excess corona as an indicator of line faults or insulation failure.

Former power-line inspection drones face several limitations. There are over 600,000 circuit miles of transmission infrastructure in the U.S., which represents a large inspection load for manual systems. With typical consumer and enterprise drones offering limited flight endurance, inspecting long line sections requires multiple takeoffs and landings. Additionally, drones operating too close to energized conductors can experience electromagnetic interference that degrades sensor performance and pilot visibility, while flying too far reduces inspection fidelity. Enterprise inspection platforms are commonly manually operated today. Finally, current regulation restricts many drone flights to visual line-of-sight (VLOS) unless special waivers are obtained. 

The proposed solution is a semi-autonomous drone that supports on-line recharging (single-wire transmission concept) to minimize downtime and enable longer mission durations. Autonomy reduces operator burden: ArcAngel can remain in a monitoring state until it detects an anomaly and then reposition to an appropriate communication distance to relay alerts without interference.


### Background

Formerly, the most reliable counterpart to this project is a powerline inspection drone; DJI-branded platforms are most commonly used. These drones are manually operated and are used mostly for above-angle inspections using conventional cameras. Drawing from these traditional approaches, a new system can improve inspection efficiency by combining autonomous flight with advanced sensing. Most current systems use optical cameras for visual inspection; newer integrations also employ thermal optics to detect hotspots and corona, which will be considered for ArcAngel’s sensor suite. 

Unlike traditional powerline inspection drones, ArcAngel Drone must function autonomously and include the capability to recharge from the high-voltage environment (single-wire transmission concept). Previously, fully autonomous persistent inspection was impractical because commercial platforms were not designed for extended autonomous missions. ArcAngel will leverage sensors and onboard regulators to maintain a safe, operable distance from power lines while inspecting for faults. The drone will use a single-wire transmission charging approach (design to be validated in testing) to enable longer missions. Because weather-damaged lines often require prompt repair, ArcAngel’s design prioritizes robust navigation and field-grade safety protocols.

Most crucial to the project is autonomous piloting: the drone must maintain a safe standoff from the conductor while preserving line-of-sight (when required), detecting failing conductors (including excess corona activity), and using flight control strategies suitable for mild to inclement weather. The top priority is ensuring the inspection flights do not create new hazards.

### Specifications and Constraints

#### Specifications

- ArcAngel Drone shall be designed to fly semi-autonomously along power lines, execute commands from the controller software, and present data to operators. It shall accept and follow predefined flight paths until a fault is located or a user intervenes.
- ArcAngel Drone shall operate in mild to inclement weather conditions appropriate for post-storm inspections (see Constraints for exact thresholds).
- ArcAngel Drone shall maintain safe flight characteristics in accordance with applicable safety guidelines for operations near power lines, including (but not limited to) operating at or below 400 ft AGL when appropriate and within regulatory limits.
- ArcAngel Drone shall support onboard recharging using a single-wire transmission concept (design and safety validation required).
- ArcAngel Drone shall transmit real-time telemetry and inspection data, including: current position and travel time, current velocity, live video and still images for line inspection, battery life percentage, and any diagnostic or inspection error codes.
- ArcAngel Drone shall achieve ≥ 30 minutes of flight endurance under nominal payload/sensor load and report error codes autonomously.
- ArcAngel Drone shall be rechargeable (field-serviceable).
- ArcAngel Drone shall communicate efficiently and reliably with line crews and the command station (communications method and frequency to be validated).
- ArcAngel Drone shall automatically stop or return to base when an error is detected or when commanded, supporting easy data analysis and practical recharging workflows.
- ArcAngel Drone shall include obstacle avoidance to navigate around limbs, foliage, the power line itself (as a sensing constraint), and transmission towers to avoid self-damage and collateral damage.
Budget: total material cost ≤ $2,500.

#### Constraints

- The material cost for ArcAngel Drone shall not exceed the outlined budget; any remaining funds will be returned to Tennessee Tech University.
- ArcAngel Drone shall comply with relevant UAS safety and operational standards, including FAA Part 107 (operational limits, VLOS/BVLOS waiver process, altitude limits).
- ArcAngel Drone shall comply with machine and workplace safety regulations, including OSHA 29 CFR 1910 Subpart O and OSHA 29 CFR 1910.212 for guarding and general machine safety where applicable.
- ArcAngel Drone shall adhere to autonomous mobile robot safety guidance such as ANSI/RIA R15.08 for sensor-based obstacle detection, safe stopping performance, and fail-safe behaviors where applicable. 
- ArcAngel Drone shall incorporate safety considerations and inspection data management aligned with utility industry guidance for transmission-line inspection (e.g., IEEE guides on transmission-line inspection and data management).
- ArcAngel Drone shall meet applicable electrical equipment safety requirements (e.g., IEC 61010 family) for integrating corona sensors and charging electronics.
- ArcAngel Drone shall adhere to Remote ID and identification/traceability requirements as required by the FAA for autonomous missions. 
- ArcAngel Drone shall maintain a minimum clearance (design target: 10 ft / 3 m) from energized conductors during inspection to reduce arcing risk — the precise clearance will be validated against utility procedures and IEEE/industry guidance.
- ArcAngel Drone shall limit corona-detection operational range to practical distances.
- ArcAngel Drone shall cap charging current for the single-wire concept to safe levels pending electrical safety validation and utility coordination.
- ArcAngel Drone shall have a maximum practical wind tolerance design target (nominal) of 20 mph (≈32 kph) for stable autonomous flight and clear video capture; operations beyond this will be classified as unsafe.
- ArcAngel Drone shall be weather-resistant and operable in light rain and temperatures between 32°F and 104°F (0°C–40°C), but shall not be deployed in lightning, heavy precipitation, or extreme winds.
- Design, testing, and operations must ensure no hazard or disruption to the public on Tennessee Tech University’s campus or in Cookeville, TN — this includes preventing collisions, limiting electromagnetic interference, and complying with local airspace and campus restrictions.
- ArcAngel Drone shall conform to any additional client, campus, or utility provider requirements specified before field deployment.


## Survey of Existing Solutions

Autonomous inspection of high‑voltage transmission lines increasingly employs ultraviolet (UV) sensing to detect otherwise invisible corona discharge and arcing. Commercial payloads such as BST Caltek’s BC‑20 DR and UV CoroCAM systems are designed for UAV integration, enabling airborne detection of electrical discharges [7], [18]. There are manufacturers that now offer turnkey drones equipped with thermal infrared, ultraviolet, and visible‑spectrum cameras, allowing simultaneous identification of thermal anomalies, corona events, and physical damage in a single flight [1]. Field studies have validated the reliability of UAV‑mounted corona detection sensors [13].

Navigation autonomy is evolving from simple GPS waypointing to perception‑driven control capable of tracking conductors while avoiding masts, vegetation, and terrain. The University of Zurich has demonstrated a vision‑only line‑tracking system trained entirely on synthetic data and successfully transferred to real‑world conditions, eliminating the need for pre‑mapped routes [19]. State‑of‑the‑art inspection drones now integrate high‑precision GPS/RTK positioning, LiDAR‑generated 3D corridor maps, and computer vision algorithms that recognize and follow known structures along the route, enabling safer and more efficient autonomous operations [9].

A key frontier is reducing downtime through on‑line recharging. Research prototypes have demonstrated the ability to perch on live conductors, harvest energy via split‑core current transformers, and autonomously cycle between inspection and charging [2]. Outdoor trials have sustained multi‑hour operations, with harvested power dependent on line current [2]. Alternative approaches mount lightweight charging stations directly on conductors, with laboratory and field tests reporting up to 145 W at 600 A [20]. In industry, Nomadic Drones is developing self‑charging UAVs that draw power from the electromagnetic field surrounding transmission lines, achieving typical recharge times of about two hours [5], while the University of Washington’s Voltair concept reflects a growing pipeline of self‑sustaining inspection platforms aimed at continuous, autonomous monitoring [6].

Existing solutions demonstrate clear progress but also reveal important trade‑offs. UV and multisensor payloads provide comprehensive fault detection by capturing thermal anomalies, corona discharge, and visible damage in a single flight [1], [7], [13], [18], though their cost, weight, and sensitivity to weather can limit endurance and reliability. Advances in navigation — from GPS/RTK and LiDAR mapping to vision‑based line tracking — enable safer, more autonomous operations [9], [19], yet they remain constrained by regulatory limits on Beyond Visual Line of Sight (BVLOS) and the need for highly robust obstacle avoidance near energized conductors. Finally, self‑charging concepts such as perching drones and inductive recharging directly from transmission lines promise near‑continuous monitoring and reduced labor costs [2], [5], [20], but these systems are still experimental, with safety concerns, variable charging rates, and long recharge cycles posing barriers to widespread adoption [6].


## Measures of Success

The success of the ArcAngel Drone will be measured by how well it can do safe, reliable, and efficient power line inspections while meeting all the functional and performance specifications. Basically, the drone needs to fly semi-autonomously along power lines, follow commands from the controller software, and give data to operators correctly. It also needs to follow flight paths we preprogram until it finds a fault or the user takes control. How well it does this will show if the drone’s control system and semi-autonomous functions actually work.

Flight stability and navigation will be tested by flying the drone along mock power lines multiple times. The drone should stay on the path and not drift more than about half a meter, and it should respond to controller commands without lag. If it can do these paths without manual correction most of the time, we will call that a success. If a fault or user override is triggered, the drone should stop or change path correctly, to show that the safety and control systems work.

Battery life will be tested by flying the drone under normal payload and sensor load. It should last at least 30 minutes per flight on average from multiple runs. We will watch battery consumption and make sure it can recharge in the field. The single-wire power transfer system will also be tested to make sure it charges safely and transfers enough energy as expected. Some variation in efficiency is ok, but it should be close to what we calculated.

The drone will also be tested in mild to somewhat bad weather like post-storm conditions. This includes wind and maybe light rain. During these tests, it should still fly stably, keep sending telemetry, and record inspection data correctly most of the time. If it fails too often in these conditions, it won’t meet the specifications.

Safety and regulatory compliance will be checked by keeping it under 400 feet AGL when needed and making sure it doesn’t get too close to power lines. Obstacle avoidance will be tested with things like tree branches, the line itself, and towers. The drone should detect and avoid these obstacles without crashing or losing control. This will show the safety systems are actually working in practice.

Data collection will be tested by checking that telemetry like position, speed, battery percentage, error codes, and live video actually gets to the command station. The data should match what’s stored onboard, with only a few errors allowed. If a problem is detected, the drone should stop or return to base automatically. This shows the error handling and reporting system works and is useful for analyzing the flight later.

Finally, the total material cost should stay under $2,500 and communications with the line crew and command station should be reliable. We will measure latency and data quality to make sure the drone can be used in real operations.
If the drone meets all of these tests, then we will say the ArcAngel Drone is successful. Demonstrating that it works like this will show that the design is practical, safe, and useful for power line inspection, and can be scaled for real world use.


## Resources

To successfully design and implement this project, the team must draw on a diverse set of technical skills while working within the constraints of budget, timeline, and stakeholder expectations. Each team member brings complementary strengths, ensuring comprehensive coverage of all aspects of the project. The team has a strong foundation in electrical and computer engineering, with experience in embedded hardware, circuit design, and programming. These competencies will be critical to the development and integration of both the drone platform and its autonomous inspection capabilities.

In addition to designing and integrating a stable drone platform, this project requires specialized sensing to detect early signs of equipment failure such as arcing and corona discharge. To support this, we plan to explore the integration of low-cost ultraviolet sensors and acoustic microphones capable of picking up high-frequency emissions associated with corona effects.

In addition to sensing capabilities, the team is also investigating the feasibility of charging the drone directly from the transmission line. This is an exploratory task, and it is not yet known if such a system can be practically implemented. The concept will likely require the design of a custom circuit with currently unknown parts and specifications, capable of safely attaching to and drawing power from the line. The outcome of this investigation will determine whether in-flight or on-line charging could become part of the prototype.

Key skills include the use of CAD tools for custom component design. The team is proficient in C++ and Python, which will be used to program flight behavior, integrate sensors, and develop navigation algorithms. Knowledge of communication protocols, power systems, and PCB design will also be instrumental in ensuring reliable hardware performance during field tests.

Throughout the project, team members will utilize a combination of school-provided lab equipment, open-source software tools, and low-cost commercial components.

As development progresses, the team will continue to adapt to emerging challenges by applying problem-solving and iterative design strategies. Special attention will be given to sensor implementation and environmental awareness, as these are crucial to safely navigating around transmission lines. Through active collaboration, ongoing testing, and a focus on system-level integration, the team is confident in delivering a working prototype that demonstrates the feasibility of semi-autonomous drone inspection in real-world conditions.


### Budget

The total estimated budget for this project is approximately $2,500, which covers the essential components needed to build a functional prototype of a semi-autonomous drone for transmission line inspection. This includes the drone platform, onboard camera, GPS module, basic sensors, onboard computing,  spare batteries, and components required for arcing and corona detection. The budget is kept intentionally low by leveraging school-provided lab equipment and low-cost commercial parts.

| **Item**                          | **Description**                                         | **Estimated Cost**      |
|----------------------------------|---------------------------------------------------------|--------------------------|
| **Base Drone Platform**          | With enough payload for sensors and onboard computer    | $800 – $1,000            |
| **Visual Camera**                | 1080p/4K for standard visual inspection                 | $100 – $300              |
| **Onboard Computer**             | Raspberry Pi 5 or Jetson Nano for data processing       | $100 – $150              |
| **GPS Module + Proximity Sensors** | Basic navigation and obstacle detection               | $100                     |
| **Extra Batteries + Spare Parts** | For extended flight time and backup components         | $200                     |
| **Low-Cost UV Sensor**           | For detecting corona discharge  | $500 – $1,000            |
| **Ultrasonic Microphone** | For acoustic detection of arcing                     | $100 – $300              |
| **Drone Charging Hardware** | For design of circuit capable of charging drone battery      | $50 – $200              |

### Personnel

**Faculty:**

Instructor - Dr. Johnson, the team’s instructor, will meet with the team weekly to discuss progression and answer questions the team may have. Dr. Johnson will also attend certain meetings between the team and customer.

Advisor - Dr. Van Neste, the team’s advisor, was chosen because of his expertise in certain aspects of the capstone project. Dr. Van Neste will assist the team with technical questions regarding electrical principles, as well as help keep the project moving forward. 

Customer - Joe Wheeler Electric Membership Corp (JWEMC), the project's customer, will help guide the team in completing this project adhering to industry standards. They will give great insight as to what the industry already has and what it needs.

**Team Members:**

Matthew Henderson - Experience with AutoCAD, soldering, troubleshooting, and programming

Lawson Stricklin - Experience with Technical drawings/interconnected diagrams, programming, power analysis, and production proposal support

Grant Christy - Experience with Revit 2023-2025, coding and troubleshooting, and circuit design

Daniel Attih - Experience in STM32 microcontrollers, c/c++, Allen Bradley PLC, VHDL code, Assembly code

Brady Goodman - Experience in single-line diagrams, power quality monitors, computer programming, and project management

All skills that are needed, but not yet present, will be acquired by individual research, and consulting with Dr. Van Neste, Dr Johnson, and JWEMC.

### Timeline

![Gantt Chart](ArcAngel%20Gantt%20Chart.png)

The capstone team has one academic year to design and develop a semi-autonomous drone for power line inspection. The drone will be capable of detecting excessive corona discharge or arcing and may also incorporate a system to recharge from the transmission line.

In the first semester, the focus will be on defining the project scope, breaking it into smaller tasks, and beginning the design process.

During the second semester, the team will refine the prototype, finalize parts and specifications, and move into system integration. The final phase includes building, testing, troubleshooting, and validating the completed drone.

If the team follows the schedule outlined in the Gantt chart, the project will result in a fully functional inspection drone by May 2026.


## Specific Implications

Implementing the ArcAngel Drone offers significant benefits that directly address the challenges and dangers associated with inspecting power lines.

Enhanced Personnel Safety:
  The drone system mitigates the substantial risks associated with manual power line inspections, which typically involve human exposure to high-voltage environments, elevated work, and adverse weather conditions. By substituting human inspectors with an autonomous drone, the system minimizes personnel's physical proximity to live power lines and elevated structures. This strategic shift in methodology directly reduces the probability of fatal accidents and injuries, aligning with stringent occupational safety protocols.

Operational Adaptability:
  Equipped with an integrated sensor suite, the drone can be effectively deployed across a variety of complex scenarios. Key technical components include:
- High-Resolution Visual Camera: Captures detailed imagery for precise fault identification.
- GPS Module: Ensures accurate navigation and real-time location tracking.
- Proximity Sensors: Facilitate safe operation and obstacle avoidance in congested environments.
This advanced configuration enables the drone to perform inspections in a wide range of operational conditions, thereby enhancing its tactical adaptability and overall utility.
  
Cost Efficiency and Reduced Risk:
	The deployment of the ArcAngel Drone yields substantial cost savings and enhanced logistical readiness. This is achieved by:
- Reducing Labor Costs: Automating a labor-intensive task minimizes the need for large inspection crews.
- Decreasing Time-on-Task: Drones can complete inspections significantly faster than traditional methods, reducing system downtime.
- Eliminating High-Cost Assets: The system negates the need for expensive and resource-intensive equipment such as helicopters and specialized bucket trucks.
These efficiencies collectively contribute to a more cost-effective and streamlined maintenance paradigm, leading to a demonstrable return on investment and a strengthened long-term operational posture.


## Broader Implications, Ethics, and Responsibility as Engineers

  The adoption of ArcAngel Drone has broad, far-reaching implications that span economic, environmental, and societal domains. This document outlines both the positive and negative impacts, as well as the ethical considerations necessary for responsible implementation.

Global and Economic Impact
  The widespread deployment of these drones can lead to significant economic efficiencies. By lowering maintenance costs for utility companies, this technology can help stabilize energy prices for consumers, making electricity more affordable. On a global scale, these drones bolster grid resilience by enabling faster and more thorough inspections, which reduces the duration of power outages and enhances overall energy infrastructure reliability.

Environmental and Societal Impact
  From an environmental standpoint, the transition from traditional methods (like helicopters and bucket trucks) to drones offers a major benefit. This shift dramatically reduces carbon emissions and noise pollution, contributing to a cleaner, quieter environment. However, this technology also presents potential negative impacts that must be proactively addressed.
- Data Privacy: Drones can inadvertently capture images of individuals or private property, raising significant privacy concerns.
- Technical Failure: The risk of a drone crashing into live power lines could lead to damage to critical infrastructure and pose a hazard to the surrounding environment.
To mitigate these risks, it is essential to implement strict flight protocols and geofencing strategies that prevent the drones from operating in sensitive or restricted areas.

Ethical Responsibilities
  The engineering team behind this project carries a profound ethical responsibility. They must commit to principles of safety, reliability, and transparency to ensure the technology is deployed responsibly and maintains public trust.
- Public Trust: Every team member is accountable for ensuring the drone's operations do not compromise public confidence.
- Sustainability: Engineers must also embed sustainability principles throughout the drone's lifecycle, from the selection of materials and manufacturing processes to end-of-life management, to minimize environmental impact.
By prioritizing these ethical considerations, the team can not only deliver a valuable technological solution but also demonstrate a deep commitment to professional responsibility and the well-being of future generations.


## References

[1] Aerial Vista Productions, “Aerial Thermal Inspections for Industry.” [Online]. Available: https://aerialvistaproductions.com/thermal-inspections/

[2] M. Al-Hussein et al., “Autonomous Overhead Powerline Recharging for UAVs,” arXiv preprint arXiv:2403.06533, 2024. [Online]. Available: https://arxiv.org/abs/2403.06533

[3] American National Standards Institute, ANSI/RIA R15.08 — Industrial Mobile Robot (IMR) Safety Requirements. ANSI Webstore. [Online]. Available: https://webstore.ansi.org/standards/ria/ansiria-r1508-2020

[4] American Society of Civil Engineers, “2021 Report Card for America’s Infrastructure – Energy,” ASCE. [Online]. Available: https://infrastructurereportcard.org/cat-item/energy/

[5] “Autonomous Self-Charging Drones for Continuous Power Line Monitoring,” Transformers Magazine, 2024. [Online]. Available: https://transformers-magazine.com/tm-news/autonomous-self-charging-drones-for-continuous-power-line-monitoring/

[6] T. Bishop, “Drone Startup Surveying Power Lines to Prevent Fires Wins Top Prize at Prestigious UW Competition,” GeekWire, May 24, 2025. [Online]. Available: https://www.geekwire.com/2025/drone-startup-surveying-power-lines-to-prevent-fires-wins-top-prize-at-prestigious-uw-competition/

[7] BST Caltek Industrial Ltd., “BC-20 DR Corona Detection Camera System,” DirectIndustry. [Online]. Available: https://www.directindustry.com/prod/bst-caltek-industrial-ltd/product-50655-2489740.html

[8] DJI Enterprise, “Drone Solutions for Powerline Inspection.” [Online]. Available: https://enterprise.dji.com/powerline-inspection

[9] “DJI Zenmuse L2 Power Line Follow Mode,” Heliguy. [Online]. Available: https://www.heliguy.com/blogs/posts/dji-l2-power-line-follow-mode/

[10] Federal Aviation Administration, “Small Unmanned Aircraft Systems (UAS) Regulations (Part 107),” FAA. [Online]. Available: https://www.faa.gov/uas/commercial_operators/part_107_remote_pilot

[11] IEEE Standards Association, IEEE 1808-2011 — Guide for Collecting and Managing Transmission Line Inspection and Maintenance Data. [Online]. Available: https://standards.ieee.org/ieee/1808/5266/

[12] International Electrotechnical Commission, IEC 61010 — Safety Requirements for Electrical Equipment for Measurement, Control, and Laboratory Use. [Online]. Available: https://webstore.iec.ch/publication/61010

[13] NASA, “Technologies and Operations for High Voltage Corona Detection with UAVs,” NASA Technical Reports Server, 2019. [Online]. Available: https://ntrs.nasa.gov/api/citations/20190027131/downloads/20190027131.pdf

[14] “Non-Stop Drone Operations via Power Line Recharging,” Interesting Engineering, 2024. [Online]. Available: https://interestingengineering.com/innovation/non-stop-drone-operations-power-line-recharging

[15] Occupational Safety and Health Administration, “29 CFR 1910 Subpart O — Machinery and Machine Guarding.” [Online]. Available: https://www.osha.gov/laws-regs/regulations/standardnumber/1910/1910SubpartO

[16] Occupational Safety and Health Administration, “29 CFR 1910.212 — General Requirements for All Machines.” [Online]. Available: https://www.osha.gov/laws-regs/regulations/standardnumber/1910/1910.212

[17] E. Stracqualursi et al., “The Corona Phenomenon in Overhead Lines: Critical Review of Effects and Detection Approaches,” Energies, vol. 15, no. 21, p. 7853, 2022. [Online]. Available: https://www.mdpi.com/1996-1073/15/21/7853

[18] UViRCO Technologies, “CoroCAM UVS for UAV Integration.” [Online]. Available: https://www.uvirco.com/corocam-uvs1/

[19] Y. Xing et al., “Perception-Aware Model Predictive Control for Power Line Inspection,” in Proc. IEEE/RSJ Int. Conf. Intell. Robots Syst. (IROS), 2023. [Online]. Available: https://rpg.ifi.uzh.ch/docs/IROS23_Xing.pdf

[20] Z. Zhang et al., “A Novel Charging Station on Overhead Power Lines for UAVs,” Appl. Sci., vol. 13, no. 18, p. 10175, 2023. [Online]. Available: https://www.mdpi.com/2076-3417/13/18/10175


## Statement of Contributions

Matthew Henderson - Contributed to Resources, including budget, personnel, and timeline

Brady Goodman - Contributed to Introduction, Measures of Success, and revisions

Grant Christy - Contributed to Formulating the Problem, including Background, Specifications, Constraints, and revisions

Daniel Attih - Contributed to Specific Implications, Broader Implications, and revisions

Lawson Stricklin - Contributed to Survey of Existing Solutions and revisions
