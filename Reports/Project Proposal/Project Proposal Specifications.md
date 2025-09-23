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

Research existing solutions, whether in literature, on the market, or within the industry. Present these findings in a coherent, organized manner. Remember to cite all information that is not common knowledge.


## Measures of Success

Define how the project’s success will be measured. This involves explaining the experiments and methodologies to verify that the system meets its specifications and constraints.


## Resources

To successfully design and implement this project, the team must draw on a diverse set of technical skills while working within the constraints of budget, timeline, and stakeholder expectations. Each team member brings complementary strengths, ensuring comprehensive coverage of all aspects of the project. The team has a strong foundation in electrical and computer engineering, with experience in embedded hardware, circuit design, and programming. These competencies will be critical to the development and integration of both the drone platform and its autonomous inspection capabilities.

In addition to designing and integrating a stable drone platform, this project requires specialized sensing to detect early signs of equipment failure such as arcing and corona discharge. To support this, we plan to explore the integration of low-cost ultraviolet sensors and acoustic microphones capable of picking up high-frequency emissions associated with corona effects.

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

### Personel

**Faculty:**

Instructor - Dr. Johnson, the team’s instructor, will meet with the team weekly to discuss progression and answer questions the team may have. Dr. Johnson will also attend certain meetings between the team and customer.

Advisor - Dr. Van Neste, the team’s advisor, was chosen because of his expertise in certain aspects of the capstone project. Dr. Van Neste will assist the team with technical questions regarding electrical principles, as well as help keep the project moving forward. 

Customer - unknown atm

**Team Members:**

Matthew Henderson - Experience with AutoCAD, soldering, troubleshooting, and programming

Lawson Stricklin - Experience with Technical drawings/interconnected diagreams, programming, power analysis, and production proposal support

Grant Christy - Experience with Revit 2023-2025, coding and troubleshooting, and circuit design

Daniel Attih - Experience in STM32 microcontrollers, c/c++, Allen Bradley PLC, VHDL code, Assembly code

Brady Goodman - 

### Timeline

![Gantt Chart](ArcAngel%20Gantt%20Chart.png)

The capstone team has one academic year to design and develop a semi-autonomous drone for power line inspection, capable of detecting excessive corona discharge or arcing.

In the first semester, the focus will be on defining the project scope, breaking it into smaller tasks, and beginning the design process.

During the second semester, the team will refine the prototype, finalize parts and specifications, and move into system integration. The final phase includes building, testing, troubleshooting, and validating the completed drone.

If the team follows the schedule outlined in the Gantt chart, the project will result in a fully functional inspection drone by May 2026.

## Specific Implications

Explain the implications of solving the problem for the customer. After reading this section, the reader should understand the tangible benefits and the worthiness of the proposed work.


## Broader Implications, Ethics, and Responsibility as Engineers

Consider the project’s broader impacts in global, economic, environmental, and societal contexts. Identify potential negative impacts and propose mitigation strategies. Detail the ethical considerations and responsibilities each team member bears as an engineer.


## References

All sources used in the project proposal that are not common knowledge must be cited. Multiple references are required.


## Statement of Contributions

Each team member must contribute meaningfully to the project proposal. In this section, each team member is required to document their individual contributions to the report. One team member may not record another member's contributions on their behalf. By submitting, the team certifies that each member's statement of contributions is accurate.
