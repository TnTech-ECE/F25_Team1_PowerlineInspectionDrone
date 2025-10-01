# Project Proposal

This document provides a comprehensive explanation of what a project proposal should encompass. The content here is detailed and is intended to highlight the guiding principles rather than merely listing expectations. The sections that follow contain all the necessary information to understand the requirements for creating a project proposal.


## General Requirements for the Document
- All submissions must be composed in markdown format.
- All sources must be cited unless the information is common knowledge for the target audience.
- The document must be written in third person.
- The document must identify all stakeholders including the instuctor, supervisor, and cusotmer.
- The problem must be clearly defined using "shall" statements.
- Existing solutions or technologies that enable novel solutions must be identified.
- Success criteria must be explicitly stated.
- An estimate of required skills, costs, and time to implement the solution must be provided.
- The document must explain how the customer will benefit from the solution.
- Broader implications, including ethical considerations and responsibilities as engineers, must be explored.
- A list of references must be included.
- A statement detailing the contributions of each team member must be provided.


## Introduction

The introduction must be the opening section of the proposal. It acts as the "elevator pitch" of the project, briefly introducing the objective, its importance, and the proposed solution. Because readers may only read this section, it should effectively capture their attention and encourage them to read further.

Toward the end of the introduction, include a subsection that outlines what the proposal will cover. This helps set reader expectations for the ensuing sections.


## Formulating the Problem

Consumers lack a reliable and efficient tool that can effectively follow high-voltage power lines for extended periods after significant storms or other disruptive events. Utility crews are typically dispatched to locate malfunctioning or downed lines, but pinpointing the exact locations can be difficult and time-consuming. Autonomous drones capable of performing effective follow-and-inspect missions could save significant repair time and reduce the duration of inoperable substations.

ArcAngel Drone is a semi-autonomous aerial system designed to operate within a specified distance of a power line while relaying high-resolution video and detecting excess corona discharge without continuous human control. This capability would allow ground personnel to rapidly locate and safely repair downed or damaged lines. ArcAngel Drone is intended to be weather-resistant and operable under mild post-storm conditions.


Key challenges include:
•	Autonomous navigation adjacent to high-voltage conductors.
•	Sustaining stable flight and effective videography during mild to inclement weather.
•	Reliable detection of excess corona as an indicator of line faults or insulation failure. [9]

Former power-line inspection drones face several limitations. There are over 600,000 circuit miles of transmission infrastructure in the U.S., which represents a large inspection load for manual systems. [2] With typical consumer and enterprise drones offering limited flight endurance, inspecting long line sections requires multiple takeoffs and landings. Additionally, drones operating too close to energized conductors can experience electromagnetic interference that degrades sensor performance and pilot visibility, while flying too far reduces inspection fidelity. Enterprise inspection platforms are commonly manually operated today. [3] Finally, current regulation restricts many drone flights to visual line-of-sight (VLOS) unless special waivers are obtained. [1] 

The proposed solution is a semi-autonomous drone that supports on-line recharging (single-wire transmission concept) to minimize downtime and enable longer mission durations. Autonomy reduces operator burden: ArcAngel can remain in a monitoring state until it detects an anomaly and then reposition to an appropriate communication distance to relay alerts without interference.


### Background

Formerly, the most reliable counterpart to this project is a powerline inspection drone; DJI-branded platforms are most commonly used. These drones are manually operated and are used mostly for above-angle inspections using conventional cameras. Drawing from these traditional approaches, a new system can improve inspection efficiency by combining autonomous flight with advanced sensing. Most current systems use optical cameras for visual inspection; newer integrations also employ thermal optics to detect hotspots and corona, which will be considered for ArcAngel’s sensor suite. 

Unlike traditional powerline inspection drones, ArcAngel Drone must function autonomously and include the capability to recharge from the high-voltage environment (single-wire transmission concept). Previously, fully autonomous persistent inspection was impractical because commercial platforms were not designed for extended autonomous missions. ArcAngel will leverage sensors and onboard regulators to maintain a safe, operable distance from power lines while inspecting for faults. The drone will use a single-wire transmission charging approach (design to be validated in testing) to enable longer missions. Because weather-damaged lines often require prompt repair, ArcAngel’s design prioritizes robust navigation and field-grade safety protocols.

Most crucial to the project is autonomous piloting: the drone must maintain a safe standoff from the conductor while preserving line-of-sight (when required), detecting failing conductors (including excess corona activity), and using flight control strategies suitable for mild to inclement weather. The top priority is ensuring the inspection flights do not create new hazards.


### Specifications and Constraints

Specifications and constraints define the system's requirements. They can be positive (do this) or negative (don't do that). They can be mandatory (shall or must) or optional (may). They can cover performance, accuracy, interfaces, or limitations. Regardless of their origin, they must be unambiguous and impose measurable requirements.

#### Specifications

•	ArcAngel Drone shall be designed to fly semi-autonomously along power lines, execute commands from the controller software, and present data to operators. It shall accept and follow predefined flight paths until a fault is located or a user intervenes.
•	ArcAngel Drone shall operate in mild to inclement weather conditions appropriate for post-storm inspections (see Constraints for exact thresholds).
•	ArcAngel Drone shall maintain safe flight characteristics in accordance with applicable safety guidelines for operations near power lines, including (but not limited to) operating at or below 400 ft AGL when appropriate and within regulatory limits. [1]
•	ArcAngel Drone shall support onboard recharging using a single-wire transmission concept (design and safety validation required).
•	ArcAngel Drone shall transmit real-time telemetry and inspection data, including: current position and travel time, current velocity, live video and still images for line inspection, battery life percentage, and any diagnostic or inspection error codes.
•	ArcAngel Drone shall achieve ≥ 30 minutes of flight endurance under nominal payload/sensor load and report error codes autonomously.
•	ArcAngel Drone shall be rechargeable (field-serviceable).
•	ArcAngel Drone shall communicate efficiently and reliably with line crews and the command station (communications method and frequency to be validated).
•	ArcAngel Drone shall automatically stop or return to base when an error is detected or when commanded, supporting easy data analysis and practical recharging workflows.
•	ArcAngel Drone shall include obstacle avoidance to navigate around limbs, foliage, the power line itself (as a sensing constraint), and transmission towers to avoid self-damage and collateral damage.
Budget: total material cost ≤ $2,500.


#### Constraints

•	The material cost for ArcAngel Drone shall not exceed the outlined budget; any remaining funds will be returned to Tennessee Tech University.
•	ArcAngel Drone shall comply with relevant UAS safety and operational standards, including FAA Part 107 (operational limits, VLOS/BVLOS waiver process, altitude limits). [1]
•	ArcAngel Drone shall comply with machine and workplace safety regulations, including OSHA 29 CFR 1910 Subpart O and OSHA 29 CFR 1910.212 for guarding and general machine safety where applicable. [5]
•	ArcAngel Drone shall adhere to autonomous mobile robot safety guidance such as ANSI/RIA R15.08 for sensor-based obstacle detection, safe stopping performance, and fail-safe behaviors where applicable. [6] 
•	ArcAngel Drone shall incorporate safety considerations and inspection data management aligned with utility industry guidance for transmission-line inspection (e.g., IEEE guides on transmission-line inspection and data management). [7]
•	ArcAngel Drone shall meet applicable electrical equipment safety requirements (e.g., IEC 61010 family) for integrating corona sensors and charging electronics. [8]
•	ArcAngel Drone shall adhere to Remote ID and identification/traceability requirements as required by the FAA for autonomous missions. [1] 
•	ArcAngel Drone shall maintain a minimum clearance (design target: 10 ft / 3 m) from energized conductors during inspection to reduce arcing risk — the precise clearance will be validated against utility procedures and IEEE/industry guidance. [7]
•	ArcAngel Drone shall limit corona-detection operational range to practical distances. [9]
•	ArcAngel Drone shall cap charging current for the single-wire concept to safe levels pending electrical safety validation and utility coordination.
•	ArcAngel Drone shall have a maximum practical wind tolerance design target (nominal) of 20 mph (≈32 kph) for stable autonomous flight and clear video capture; operations beyond this will be classified as unsafe.
•	ArcAngel Drone shall be weather-resistant and operable in light rain and temperatures between 32°F and 104°F (0°C–40°C), but shall not be deployed in lightning, heavy precipitation, or extreme winds.
•	Design, testing, and operations must ensure no hazard or disruption to the public on Tennessee Tech University’s campus or in Cookeville, TN — this includes preventing collisions, limiting electromagnetic interference, and complying with local airspace and campus restrictions.
•	ArcAngel Drone shall conform to any additional client, campus, or utility provider requirements specified before field deployment.



## Survey of Existing Solutions

Autonomous inspection of high‑voltage transmission lines increasingly employs ultraviolet (UV) sensing to detect otherwise invisible corona discharge and arcing. Commercial payloads such as BST Caltek’s BC‑20 DR and UV CoroCAM systems are designed for UAV integration, enabling airborne detection of electrical discharges. There are manufacturers that now offer turnkey drones equipped with thermal infrared, ultraviolet, and visible‑spectrum cameras, allowing simultaneous identification of thermal anomalies, corona events, and physical damage in a single flight. Field studies have validated the reliability of UAV‑mounted corona detection sensors.

Navigation autonomy is evolving from simple GPS waypointing to perception‑driven control capable of tracking conductors while avoiding masts, vegetation, and terrain. The University of Zurich has demonstrated a vision‑only line‑tracking system trained entirely on synthetic data and successfully transferred to real‑world conditions, eliminating the need for pre‑mapped routes. State‑of‑the‑art inspection drones now integrate high‑precision GPS/RTK positioning, LiDAR‑generated 3D corridor maps, and computer vision algorithms that recognize and follow known structures along the route, enabling safer and more efficient autonomous operations.

A key frontier is reducing downtime through on‑line recharging. Research prototypes have demonstrated the ability to perch on live conductors, harvest energy via split‑core current transformers, and autonomously cycle between inspection and charging. Outdoor trials have sustained multi‑hour operations, with harvested power dependent on line current. Alternative approaches mount lightweight charging stations directly on conductors, with laboratory and field tests reporting up to 145 W at 600 A. In industry, Nomadic Drones is developing self‑charging UAVs that draw power from the electromagnetic field surrounding transmission lines, achieving typical recharge times of about two hours, while the University of Washington’s Voltair concept reflects a growing pipeline of self‑sustaining inspection platforms aimed at continuous, autonomous monitoring.


## Measures of Success

Define how the project’s success will be measured. This involves explaining the experiments and methodologies to verify that the system meets its specifications and constraints.


## Resources

Each project proposal must include a comprehensive description of the necessary resources.

### Budget

Provide a budget proposal with justifications for expenses such as software, equipment, components, testing machinery, and prototyping costs. This should be an estimate, not a detailed bill of materials.

### Personel

Identify the skills present in the team and compare them to those required to complete the project. Address any skill gaps with a plan to acquire the necessary knowledge.

Besides the team, also state who you choose to be you supervisor and why.

State who your instrucotr is and what role you expect them to play in the project.

### Timeline

Provide a detailed timeline, including all major deadlines and tasks. This should be illustrated with a professional Gantt chart.


## Specific Implications

Explain the implications of solving the problem for the customer. After reading this section, the reader should understand the tangible benefits and the worthiness of the proposed work.


## Broader Implications, Ethics, and Responsibility as Engineers

Consider the project’s broader impacts in global, economic, environmental, and societal contexts. Identify potential negative impacts and propose mitigation strategies. Detail the ethical considerations and responsibilities each team member bears as an engineer.


## References
1.	Federal Aviation Administration, “Small Unmanned Aircraft Systems (UAS) Regulations (Part       107).” FAA newsroom and Part 107 resources. Federal Aviation Administration
2.	American Society of Civil Engineers / Infrastructure Report resources (Energy report),          reference for transmission-line network scale (reported ~600,000 circuit miles).                Infrastructure Report Card
3.	DJI Enterprise — Powerline inspection and inspection platform resources (product/white          papers and guidance for drone-based powerline inspections). DJI+1
4.	OSHA, “29 CFR 1910 Subpart O — Machinery and Machine Guarding.” OSHA
5.	OSHA, “29 CFR 1910.212 — General requirements for all machines.” OSHA
6.	ANSI/RIA, “R15.08 — Industrial Mobile Robot (IMR) Safety Requirements” (standard overview).     ANSI Webstore
7.	IEEE, “IEEE Guide for Collecting and Managing Transmission Line Inspection and Maintenance      Data (IEEE 1808).” IEEE Standards
8.	IEC Webstore, “IEC 61010 — Safety requirements for electrical equipment” (relevant parts).      IEC Webstore
9.	E. Stracqualursi et al., “The Corona Phenomenon in Overhead Lines: Critical …”, review of       corona effects and detection approaches. MDPI


BST Caltek Industrial Ltd. BC‑20 DR Corona Detection Camera System. DirectIndustry, https://www.directindustry.com/prod/bst-caltek-industrial-ltd/product-50655-2489740.html.

“Aerial Thermal Inspections for Industry.” Aerial Vista Productions, https://aerialvistaproductions.com/thermal-inspections/.

“DJI Zenmuse L2 Power Line Follow Mode.” Heliguy, https://www.heliguy.com/blogs/posts/dji-l2-power-line-follow-mode/.

NASA. Technologies and Operations for High Voltage Corona Detection with UAVs. NASA Technical Reports Server, 2019, https://ntrs.nasa.gov/api/citations/20190027131/downloads/20190027131.pdf.

Bishop, Todd. “Drone Startup Surveying Power Lines to Prevent Fires Wins Top Prize at Prestigious UW Competition.” GeekWire, 24 May 2025, https://www.geekwire.com/2025/drone-startup-surveying-power-lines-to-prevent-fires-wins-top-prize-at-prestigious-uw-competition/.

“Autonomous Self‑Charging Drones for Continuous Power Line Monitoring.” Transformers Magazine, 2024, https://transformers-magazine.com/tm-news/autonomous-self-charging-drones-for-continuous-power-line-monitoring/.

Zhang, Zhi, et al. “A Novel Charging Station on Overhead Power Lines for UAVs.” Applied Sciences, vol. 13, no. 18, 2023, p. 10175. MDPI, https://www.mdpi.com/2076-3417/13/18/10175.

“Non‑Stop Drone Operations via Power Line Recharging.” Interesting Engineering, 2024, https://interestingengineering.com/innovation/non-stop-drone-operations-power-line-recharging.

UViRCO Technologies. CoroCAM UVS for UAV Integration. UViRCO, https://www.uvirco.com/corocam-uvs1/.

Xing, Yifan, et al. “Perception‑Aware Model Predictive Control for Power Line Inspection.” IEEE/RSJ International Conference on Intelligent Robots and Systems (IROS), 2023, https://rpg.ifi.uzh.ch/docs/IROS23_Xing.pdf.

Al‑Hussein, Mohammed, et al. “Autonomous Overhead Powerline Recharging for UAVs.” arXiv, 2024, https://arxiv.org/abs/2403.06533.


## Statement of Contributions

Each team member must contribute meaningfully to the project proposal. In this section, each team member is required to document their individual contributions to the report. One team member may not record another member's contributions on their behalf. By submitting, the team certifies that each member's statement of contributions is accurate.
