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

Electrical power infrastructure is one of the most critical assets in modern society, yet it remains vulnerable to damage from storms, environmental stress, and equipment aging. Traditionally, inspection of high-voltage power lines has relied on inefficient and time-consuming methods that can be improved upon. These methods shall continue to pose safety risks, high operational costs, and limited efficiency (EPRI, 2020). There shall be a safer, more autonomous, and cost-effective method of performing routine and emergency inspections.

The proposed project, ArcAngel Drone, is a semi-autonomous inspection system specifically designed to operate near power lines and identify potential faults. Unlike existing solutions that are limited by flight time and require constant operator control, ArcAngel Drone shall feature autonomous navigation, onboard corona detection, and the capability to recharge directly from high-voltage lines using single-wire energy transfer. This would enable operators real time feedback during potentially dangerous scenarios, and could catch impacts before or immediately after occurring, such as fires. Research prototypes have already demonstrated the feasibility of UAV-mounted corona detection sensors (BST Caltek, 2021) and live-line recharging through electromagnetic energy harvesting (Nomadic Drones, 2022). These features shall enable extended missions, rapid post-storm response, and reduced downtime for electric grids. For customers such as power utilities, this technology provides faster fault identification, minimized repair delays, and significant cost savings compared to traditional inspection methods.

The stakeholders for this project include the instructor Dr. Storm Johnson, who shall evaluate academic performance; the technical supervisor Dr. Van Neste, who shall guide the engineering process; the customer JWERC, represented by electric utilities and line maintenance teams, who shall benefit directly from improved inspection safety and efficiency; and the project team members, who are responsible for the design, implementation, and validation of ArcAngel Drone. Successful implementation shall require skills in embedded systems, power electronics, communications, and autonomous navigation. The estimated project cost shall not exceed $2,500, with completion expected within the senior design project timeline.

The customer benefits are clear: ArcAngel Drone reduces human exposure to hazardous environments, lowers inspection costs, and increases operational adaptability during grid failures. Broader impacts extend to environmental sustainability by replacing helicopters and heavy trucks, thereby reducing carbon emissions, as well as ethical responsibilities in ensuring safe operation, reliability, and data privacy. While challenges remain, including regulatory compliance and preventing technical failure near live lines, ArcAngel Drone represents a meaningful advancement in both engineering practice and public safety.

The remainder of this proposal is organized into the following sections:

•	Problem Definition and Objectives – specifying requirements with “shall” statements.

•	Background and Existing Solutions – reviewing prior drones and enabling technologies.

•	Methodology and Design Plan – describing the approach to development.

•	Project Management – outlining resources, costs, skills, and schedule.

•	Success Criteria and Evaluation – defining metrics for performance.

•	Customer Benefits and Broader Implications – addressing value and ethical responsibility.

•	Team Contributions – stating each member’s role.

•	References – citing supporting sources.


## Formulating the Problem

Formulating the problem or objective involves clearly defining it through background information, specifications, and constraints. Think of it as "fencing in" the objective to make it unambiguously clear what is and is not being addressed and why.

Questions to consider:
- Who does the problem affect (i.e. who is your customer)?
- Why do we need this solution?
- What challenges necessitate a dedicated, multi-person engineering team?
- Why aren’t off-the-shelf solutions sufficient?

### Background

Provide context and details necessary to define the problem clearly and delineate its boundaries.

### Specifications and Constraints

Specifications and constraints define the system's requirements. They can be positive (do this) or negative (don't do that). They can be mandatory (shall or must) or optional (may). They can cover performance, accuracy, interfaces, or limitations. Regardless of their origin, they must be unambiguous and impose measurable requirements.

#### Specifications

Specifications are requirements imposed by **stakeholders** to meet their needs. If a specification seems unattainable, it is necessary to discuss and negotiate with the stakeholders.

#### Constraints

Constraints often stem from governing bodies, standards organizations, and broader considerations beyond the requirements set by stakeholders.

Questions to consider:
- Do governing bodies regulate the solution in any way?
- Are there industrial standards that need to be considered and followed?
- What impact will the engineering, manufacturing, or final product have on public health, safety, and welfare?
- Are there global, cultural, social, environmental, or economic factors that must be considered?


## Survey of Existing Solutions

Autonomous inspection of high‑voltage transmission lines increasingly employs ultraviolet (UV) sensing to detect otherwise invisible corona discharge and arcing. Commercial payloads such as BST Caltek’s BC‑20 DR and UV CoroCAM systems are designed for UAV integration, enabling airborne detection of electrical discharges. There are manufacturers that now offer turnkey drones equipped with thermal infrared, ultraviolet, and visible‑spectrum cameras, allowing simultaneous identification of thermal anomalies, corona events, and physical damage in a single flight. Field studies have validated the reliability of UAV‑mounted corona detection sensors.

Navigation autonomy is evolving from simple GPS waypointing to perception‑driven control capable of tracking conductors while avoiding masts, vegetation, and terrain. The University of Zurich has demonstrated a vision‑only line‑tracking system trained entirely on synthetic data and successfully transferred to real‑world conditions, eliminating the need for pre‑mapped routes. State‑of‑the‑art inspection drones now integrate high‑precision GPS/RTK positioning, LiDAR‑generated 3D corridor maps, and computer vision algorithms that recognize and follow known structures along the route, enabling safer and more efficient autonomous operations.

A key frontier is reducing downtime through on‑line recharging. Research prototypes have demonstrated the ability to perch on live conductors, harvest energy via split‑core current transformers, and autonomously cycle between inspection and charging. Outdoor trials have sustained multi‑hour operations, with harvested power dependent on line current. Alternative approaches mount lightweight charging stations directly on conductors, with laboratory and field tests reporting up to 145 W at 600 A. In industry, Nomadic Drones is developing self‑charging UAVs that draw power from the electromagnetic field surrounding transmission lines, achieving typical recharge times of about two hours, while the University of Washington’s Voltair concept reflects a growing pipeline of self‑sustaining inspection platforms aimed at continuous, autonomous monitoring.


## Measures of Success

The success of the ArcAngel Drone shall be measured by its ability to perform safe and reliable power line inspections while meeting the functional requirements outlined in the specifications. At the most general level, the drone must demonstrate semi- autonomous flight capability near power lines and be able to provide data regarding the inspected lines. Success will also be determined by the drone’s ability to demonstrate power transfer from high-voltage lines. If these objectives are met within the constraints of cost, safety standards, and operability in chosen conditions, the project shall be considered a success.

To verify these outcomes, the team shall conduct a series of structured tests and demonstrations. These will include evaluating navigation and stability during semi-autonomous flight, verifying that onboard sensors correctly capture inspection data. Additional emphasis shall be placed on validating safety protocols, such as obstacle avoidance and adherence to FAA flight limits. While the evaluation process will not replicate every possible real-world condition, successful demonstration under controlled scenarios shall provide sufficient evidence that the design is practical, scalable, and beneficial to the customer.



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

BST Caltek Industrial Ltd. BC20 DR Corona Detection Camera System. DirectIndustry, https://www.directindustry.com/prod/bst-caltek-industrial-ltd/product-50655-2489740.html.  

“Aerial Thermal Inspections for Industry.” Aerial Vista Productions, https://aerialvistaproductions.com/thermal-inspections/.  

“DJI Zenmuse L2 Power Line Follow Mode.” Heliguy, https://www.heliguy.com/blogs/posts/dji-l2-power-line-follow-mode/.  

NASA. Technologies and Operations for High Voltage Corona Detection with UAVs. NASA Technical Reports Server, 2019, https://ntrs.nasa.gov/api/citations/20190027131/downloads/20190027131.pdf.  

Bishop, Todd. “Drone Startup Surveying Power Lines to Prevent Fires Wins Top Prize at Prestigious UW Competition.” GeekWire, 24 May 2025, https://www.geekwire.com/2025/drone-startup-surveying-power-lines-to-prevent-fires-wins-top-prize-at-prestigious-uw-competition/.  

“Autonomous SelfCharging Drones for Continuous Power Line Monitoring.” Transformers Magazine, 2024, https://transformers-magazine.com/tm-news/autonomous-self-charging-drones-for-continuous-power-line-monitoring/.  

Zhang, Zhi, et al. “A Novel Charging Station on Overhead Power Lines for UAVs.” Applied Sciences, vol. 13, no. 18, 2023, p. 10175. MDPI, https://www.mdpi.com/2076-3417/13/18/10175.  

“NonStop Drone Operations via Power Line Recharging.” Interesting Engineering, 2024, https://interestingengineering.com/innovation/non-stop-drone-operations-power-line-recharging.  

UViRCO Technologies. CoroCAM UVS for UAV Integration. UViRCO, https://www.uvirco.com/corocam-uvs1/.  

Xing, Yifan, et al. “PerceptionAware Model Predictive Control for Power Line Inspection.” IEEE/RSJ International Conference on Intelligent Robots and Systems (IROS), 2023, https://rpg.ifi.uzh.ch/docs/IROS23_Xing.pdf.  

AlHussein, Mohammed, et al. “Autonomous Overhead Powerline Recharging for UAVs.” arXiv, 2024, https://arxiv.org/abs/2403.06533.  


## Statement of Contributions

Each team member must contribute meaningfully to the project proposal. In this section, each team member is required to document their individual contributions to the report. One team member may not record another member's contributions on their behalf. By submitting, the team certifies that each member's statement of contributions is accurate.
