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
