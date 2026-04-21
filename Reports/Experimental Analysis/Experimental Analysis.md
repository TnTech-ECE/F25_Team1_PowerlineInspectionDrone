# Experimental Analysis

The following document provides a comprehensive record of all experiments conducted throughout the design, integration, and testing phases of the ArcAngel Powerline Inspection Drone project. Each experiment has been carefully documented with the intention of enabling future teams to fully understand our methodology and reproduce our work with clarity and confidence. By outlining our procedures, hypotheses, results, and interpretations, we aim to offer a transparent foundation on which the next group can build. Our hope is that this documentation not only preserves the lessons learned during our development process but also allows future teams to dedicate their time and effort to advancing the system beyond the challenges we were unable to overcome.


## 1. Power Harvesting and Battery Charging Subsystem (Low-Voltage Validation)

### Purpose and Justification:
The purpose of this experiment is to validate the feasibility of harvesting electrical energy from an external power source and transferring that energy 
into the onboard battery system. This subsystem integrates two primary components: the power harvesting circuit, responsible for extracting usable electrical energy 
from a transmission line, and the battery charging circuit, which regulates and stores the harvested energy safely within the drone’s battery.


### Detailed Procedure:
The following steps describe the low-voltage experimental procedure used to validate subsystem functionality:

1. Configure a controllable low-voltage DC power supply to simulate the transmission line input.  
2. Connect the power supply output to the input of the power harvesting circuit.  
3. Verify all connections, ensuring correct polarity and secure wiring between:
   - Power source → harvesting circuit  
   - Harvesting circuit → charging circuit  
   - Charging circuit → battery  
4. Power on the supply and gradually increase voltage to the desired test level (e.g., 12–24 V).  
5. Measure input voltage and current to the harvesting circuit using a multimeter.  
6. Measure output voltage from the harvesting circuit to ensure proper conditioning/regulation.  
7. Monitor the charging circuit output to the battery, verifying:
   - Stable voltage within charging limits  
   - Presence of charging current into the battery  
8. Record all relevant data, including voltages, currents, and any observed fluctuations.  
9. Repeat the test multiple times to ensure consistency and reliability of results.  

The same procedure can be adapted for future high-voltage testing by incorporating proper isolation, step-down mechanisms, and safety precautions when interfacing with transmission lines.

### Expected Results:

The system is expected to produce a relatively small output voltage due to the limited input excitation of approximately 20 Vpp. As a result, the harvested output should be on the order of a fraction of a volt. This is sufficient for proof of concept, demonstrating that the harvesting and energy transfer mechanisms function correctly and will scale when applied to high-voltage transmission lines.

The primary objective is to verify proper operation rather than maximize power. A stable, measurable output confirms that energy is being successfully extracted, conditioned, and delivered through the system.

It is also critical to ensure that the voltage across the load capacitor does not exceed 36 V, which is the maximum input rating of the voltage converter. As long as the capacitor voltage remains within this operating range, the converter is expected to reliably regulate the output to 5 V for battery charging.

Overall, the expected result is a stable low-level DC output, safe operating voltages across all components, and consistent performance across repeated trials.

### Actual Results:
Measurements were taken at key points in the system to evaluate the performance of both the power harvesting subsystem and the battery charging subsystem. All connections were verified prior to testing to ensure proper system operation.

| Function Tested | Result | Status | Notes |
|----------------|--------|--------|------|
| Voltage across load capacitor | ~3–4 V (with 20 Vpp input) | Not within expected range | Output voltage higher than anticipated for given input |
| Battery charging circuit (with harvested input) | No output (converter inactive) | Did not work | Input voltage not within converter operating range (7–36 V) |
| Battery charging circuit (independent test) | Regulated 5 V output | Worked | Converter operated correctly when supplied with valid input voltage |
| System connections and wiring | Verified | Worked | All connections secure and functioning properly |

The system demonstrated measurable voltage at the load capacitor and confirmed proper operation of the battery charging circuit under valid input conditions. However, the integrated system did not successfully charge the battery under the low-voltage harvesting test conditions.

### Interpretation and Conclusion:
The results of the low-voltage test indicate that while the overall system concept is valid, the current implementation of the power harvesting subsystem does not behave as intended. The measured voltage across the load capacitor (~3–4 V with a 20 Vpp input) was significantly higher than expected for this test condition. This suggests that the system is coupling more strongly to the source than originally predicted.

The primary cause of this behavior is attributed to the absence of a true ground reference in the experimental setup. Instead of a defined return path, the system relies on a capacitive plate acting as a pseudo-ground. In practice, this creates unintended capacitive coupling effects, allowing a larger portion of the input signal to appear across the load capacitor. As a result, the voltage does not scale down proportionally as expected.

This presents a critical issue when considering high-voltage operation. If the same scaling behavior persists, a transmission line input on the order of 20 kVpp could result in voltages across the load capacitor reaching the kilovolt range. Such conditions would far exceed the 36 V maximum input rating of the voltage converter, leading to component failure and unsafe operating conditions.

Despite this limitation, the battery charging subsystem was successfully validated. Independent testing confirmed that the voltage converter reliably regulates input voltages within its specified range (7–36 V) down to a stable 5 V output suitable for battery charging. This demonstrates that the charging subsystem is fully functional and that the primary issue lies within the power harvesting stage.

Overall, the experiment confirms that the system is capable of harvesting and transferring energy, but highlights a key design flaw in how the input is referenced and coupled. Future improvements should focus on implementing a more controlled grounding or reference scheme, as well as refining the coupling mechanism to limit voltage transfer to safe and predictable levels.

In conclusion, the battery charging subsystem meets design expectations, while the power harvesting subsystem requires further refinement before safe and effective high-voltage operation can be achieved.


## 2. Camera Sensing and Control & Communication Subsystem 

### Purpose and Justification:
The purpose of this experiment is to validate the complete integration of all subsystem components and ensure reliable, synchronized operation under real-world conditions. This includes confirming communication between all modules, verifying coordinated data acquisition, and ensuring proper system response to environmental inputs. The integrated system combines sensing, control, communication, and data logging functionalities to support the detection of thermal faults along transmission lines. By integrating the Raspberry Pi Pico, MLX90640 infrared camera, DS3231 RTC, GPS module, TF card adapter, and servo motor, the system is designed to identify abnormal temperature conditions, associate them with time and location data, actuate a mechanical response, and store all relevant information for analysis.

### Detailed Procedure:
#### The following steps describe the full system integration experimental procedure:
1. Assemble the complete system by connecting all modules to the Raspberry Pi Pico, ensuring correct wiring and stable power distribution.
2. Develop and integrate code modules for each component into a single unified program, ensuring compatibility across all communication protocols (I²C, UART, SPI, and PWM).
3. Initialize all components sequentially and verify successful communication with:
   - MLX90640 infrared camera
   - DS3231 RTC
   - GPS module
   - TF card adapter
   - Servo motor
4. Implement synchronized data acquisition by:
   - Capturing temperature data from the MLX90640 or sending a PWM signal to actuate servo movement
   - Retrieving timestamps from the RTC
   - Obtaining GPS coordinates
5. Format and combine collected data into structured output for both real-time display (serial monitor) and file storage.
6. Configure the TF card adapter to log integrated data, including temperature values, timestamps, and GPS location, into a file.
7. Conduct testing under controlled conditions by:
   - Introducing heat sources to simulate thermal faults
   - Observing system response, including detection, logging, and actuation
8. Verify system performance by:
   - Ensuring continuous operation without communication errors
   - Confirming accurate synchronization of sensor data

### Expected Results:
- All system components will successfully initialize and operate simultaneously without communication conflicts.
- The MLX90640 will continuously provide accurate temperature data reflecting environmental conditions.
- The RTC will provide consistent timestamps synchronized with sensor readings.
- The GPS module will output accurate location data that updates with movement.
- The TF card adapter will log all system data in a structured and readable format.
- The Raspberry Pi Pico will send a proper PWM signal to the servo motor.

### Actual Results:
- All components successfully initialized and operated simultaneously without communication issues.
- The MLX90640 continuously outputs accurate temperature data reflecting environmental conditions.
- The DS3231 RTC consistently provided accurate timestamps in 12-hour format.
- The GPS module reliably outputs latitude and longitude in decimal degrees, with readings varying appropriately based on location.
- The TF card adapter successfully logged synchronized data, including temperature, time, and location, into files.
- The servo motor actuated correctly between 0° and 90° when triggered by a PWM signal from the Raspberry Pi Pico.

### Interpretation and Conclusion:
The results of this experiment confirm the successful integration and coordinated operation of all subsystem components. Each module not only functioned correctly on its own but also contributed effectively to the overall system without causing communication conflicts or performance degradation.

The system demonstrated the ability to simultaneously collect temperature, time, and location data while maintaining synchronization across all inputs. The MLX90640 accurately detected thermal variations, and this data was successfully paired with timestamps from the RTC and positional data from the GPS module. The TF card adapter reliably stored this combined dataset, validating the system’s real-time data logging capability.

Additionally, the servo motor responded appropriately to the PWM signals, confirming that the system can execute mechanical actions. This demonstrates a complete sensing-to-response workflow, which is critical for real-world applications.

Overall, the integrated system meets its design objectives and is capable of performing transmission line inspection tasks by detecting abnormal temperature conditions, recording critical data, and initiating mechanical responses. The successful operation of all components in a unified system indicates strong potential for deployment in practical environments. Future improvements may include optimizing processing efficiency, enhancing automation logic, and improving robustness for extended field use.


## 3. Mechanical and Structural Experimental Analysis

### Purpose and Justification:
The purpose of this expirement is to validate that we can have our entire subsystem be limited to roughly 200 g to maintain proper weight for most universal drones. The system is divided into three main structural parts: the above drone hooking subsystem that houses the GPS and additional in-house battery if needed, the below drone housing that holds the Charging and BMS Subsystem and the Control and Camera susbsytem, and finally the in-dome structural supports to have easy access to all subsystems to allow for easy manipulations and repairs.

### Detailed Procedure:
1. Weigh each subsystem separately to see how they would weigh based on their original designs.
2. Develop and connect each subsystem to their designated locations and mount them to the housing to get a more accurate estimate as to what the full design will become.
3. Design and correct each location:
Above Drone Housing:
- GPS Module
- Servo Mount
- Hook-to-Line
- In-House Additional Battery
- Voltage Amplifier
Below Drone Housing:
Dome Connection:
- Camera
1st Layer:
- Raspberry Pi Pico
- SD Card Storage Module
2nd Layer:
- Power Harvesting Subsystem
- Charging and BMS Subsystem
4. Make sure eash subsystem is easily accesible and can all function properly based on location.
5. Hooking subsystem has to be able to support the weight of the drone without compromising integrity.
6. Weigh the Above and Below designs separately to obtain final weight of the design.


### Expected Results:
- The hook will be able to support the entire weight of the drone with easy to manage connection to the power harvesting subsystem
- The hook will raise and lower without additional external help
- The entire subsystem will weigh around or less than 200 g
- All systems have a mounted location and work properly in their designed location
- The subsystems do not interact or could damage one another unless they are meant to interact

### Actual Results:
- The hook is able to support the entire weight of the drone and easilhy connects to the power harvesting subsystem
- The hook raises and lowers without external help
- The entire subsystem DOES NOT weigh less or equal to 200 g
- All systems have a mounted location and work properly
- The subsystems do not interact or could damage one another unless they are meant to interact

Weight Before Connection Table:
| Object | Actual Weight | Desired Weight | Total(Actual) | Total(Desired) |
|--------|---------------|----------------|---------------|----------------|
| Dome | 38 g | 31 g | | |
| Inner Support | 23 g | 20 g | | |
| Servo Mount | 37 g | 34 g | | |
| Hook Subsystem | 19 g | 16 g | | |
| Charging & BMS | 47 g | 44 g | | |
| Control & Camera | 59 g | 56 g | 223 g | 205 g |

Weight After Connection Table (Simplfied)
| Object | Actual Weight | Desired Weight | Total(Actual) | Total(Desired) |
|--------|---------------|----------------|---------------|----------------|
| Above Drone Housing | 89 g | 80 g | | |
| Below Drone Housing | 127 g | 120 g | 216 g | 200 g |


### Interpretation and Conclusion:
The results demonstrate that the system is structurally sound and functions as intended; however, it does not yet meet the target mass requirement. The current total mass is approximately 220 g. This excess weight can likely be reduced through optimization measures such as minimizing wire lengths and redesigning the housing with lighter materials.

All subsystems are properly integrated, with effective spatial separation that prevents unintended interaction while maintaining required connectivity. The design also supports ease of maintenance, as components are accessible and can be detached for repair or replacement.

The hooking subsystem has proven capable of supporting the maximum tested drone weight without structural failure, confirming its reliability.

Overall, the design meets all major functional requirements except for the weight constraint. With further refinement, the system is expected to achieve the target mass of 200 g or less.


### 1. Power Harvesting and Battery Charging Success Criteria
#### Success Criterion: 
Demonstrate the ability to harvest energy from an external source and safely convert it into a regulated 5 V output suitable for battery charging.

#### **Result:**
Partially Met

#### Evidence
- Measurable voltage (~3–4 V) was observed across the load capacitor with a 20 Vpp input, confirming energy harvesting.
- The battery charging converter did not activate under harvested conditions due to insufficient/invalid input range.
- Independent testing of the converter verified proper operation, producing a stable 5 V output when supplied with input within the 7–36 V range.
- All system connections and wiring were verified to be functioning correctly.

#### Reason for Incomplete Success:
The power harvesting subsystem produced a higher-than-expected voltage at low input due to unintended capacitive coupling and lack of a true ground reference. This resulted in improper scaling and prevented the output from falling within the acceptable input range of the voltage converter during integrated testing.

#### Future Improvements:
- Redesign the power harvesting circuit so that the output voltage scales predictably with the input. This will ensure the system produces the correct voltage for the battery charging subsystem when connected to real transmission line voltages.
- Add protection (such as voltage limiting or clamping) to prevent excessive voltage from reaching the converter and damaging components.
- Re-test the fully integrated system after modifications to confirm safe operation within the converter’s allowable voltage range.

### 2. Camera Sensing and Control & Communication Subsystem Success Criteria 

#### **Success Criterion**
The experiment is considered successful if all subsystem components reliably communicate with the Raspberry Pi Pico and operate together as an integrated system, producing accurate temperature, time, and GPS data in a readable format. Additionally, the system must successfully log synchronized data to the TF card and actuate the servo motor in response to the PWM signals without errors.

#### **Result**
Fully Met

#### **Evidence**
- All subsystem components successfully initialized and established communication with the Raspberry Pi Pico without errors.
- The MLX90640 infrared camera consistently outputs temperature data in a clear and readable format.
- Temperature readings varied appropriately, increasing when exposed to heat sources and decreasing in cooler conditions.
- The DS3231 RTC provided stable and accurate timestamps in a 12-hour format.
- The GPS module outputs valid latitude and longitude in decimal degrees, with readings changing appropriately based on location.
- The TF card adapter successfully created files and reliably logged synchronized temperature, time, and GPS data.
- The servo motor responded correctly to PWM signals, consistently actuating between 0° and 90° positions.
- The system produced stable, repeatable results across multiple tests, demonstrating reliable integrated operation.

#### **Reason for Incomplete Success**
N/A

#### **Future Improvements**
Future improvements to the system include enhancing the thermal camera processing logic to improve robustness and reliability in real-world field conditions. Additional improvements may involve optimizing data logging efficiency, refining threshold-based actuation for the servo motor, and improving overall system integration for faster and more stable performance.

---

### 3. Navigation Subsystem Success Criteria

#### **Success Criterion**


#### **Result**


#### **Evidence**


#### **Reason for Incomplete Success**


#### **Future Improvements**


---


---

## **Overall Conclusion**

ArcAngel Drone did **not fully meet** the original project success criteria, but it **successfully validated several essential foundations** required for future teams to complete the system.

#### **Successfully Demonstrated**
- Low-voltage energy harvesting and a fully functional battery charging converter (when supplied within its operating range)
- Successful integration of the Raspberry Pi Pico subsystem, including reliable temperature sensing from the MLX90640 infrared camera, accurate time and GPS data acquisition, synchronized data logging to the TF card, and proper servo motor actuation with readable system outputs

#### **Not Demonstrated**
- End-to-end operation where harvested energy is successfully converted and used to charge the battery


#### **Primary Cause of Performance Gaps**
- Improper voltage scaling due to capacitive coupling and lack of a true ground reference, resulting in out-of-range input to the converter


---

## **Recommended Next Steps**
- Redesign the power harvesting subsystem to include a proper ground/reference path and controlled voltage scaling to ensure safe, converter-compatible output when interfacing with high-voltage transmission lines.
 



## Inventory Table

| Item # | Description                                                   | Qty | Vendor / Source | Storage Location | Date Acquired | Condition | Notes (Detailed Comments) |
|:-----:|---------------------------------------------------------------|:---:|-----------------|------------------|---------------|-----------|----------------------------|
| 1     | High Voltage Resistor (100MΩ, 5W Glass Glaze)                |  3  | Newegg          |  Lab Station      | Never Acquired | New       | Not in use. |
| 2     | Ceramic Capacitors (1µF, 500V MLCC)                          | 15  | Mouser          |  Lab Station      | 3/1/2026      | New       | In use. |
| 3     | High Voltage Resistor (100MΩ, 0.5W Axial)                    | 25  | Mouser          |  Lab Station      | 3/1/2026      | New       | In use. |
| 4     | Metal Film Resistor (10MΩ, 1W)                               | 10  | Mouser          |  Lab Station      | 3/1/2026      | New       | In use. |
| 5     | Assorted Resistor Kit (1MΩ range)                            |  1  | Amazon          | Lab Station      | 3/1/2026      | New       | In use. |
| 6     | High Voltage Diodes (5kV)                                    | 20  | Mouser          |  Lab Station      | 3/1/2026      | New       | In use. |
| 7     | Printed Circuit Boards                                       |  5  | Mouser          |  Lab Station      | 3/1/2026      | New       | In use. |
| 8     | Stainless Steel Mesh (Capacitive Plate)                      |  1  | Amazon          |  Lab Station      | 3/1/2026      | New       | Not in use. |
| 9     | USB-C Cable                                                  |  1  | Amazon          |  Lab Station      | 3/1/2026      | New       | |
| 10    | Raspberry Pi Pico (RP2040 Microcontroller)                   |  1  | Adafruit        |  Lab Station      | 3/1/2026      | New       | In use. |
| 11    | Real-Time Clock Module (DS3231)                              |  1  | Adafruit        |  Lab Station      | 3/1/2026      | New       | In use. |
| 12    | JST SH 4-Pin Cable                                           |  1  | Adafruit        |  Lab Station      | 3/1/2026      | New       | Not in use. |
| 13    | Coin Cell Battery (CR1220)                                   |  1  | Adafruit        |  Lab Station      | 3/1/2026      | New       | In Use.|
| 14    | Voltage Regulator Module                                     |  1  | Adafruit        |  Lab Station      | 3/1/2026      | New       | |
| 15    | DC-DC Converter Module                                       |  1  | Adafruit        |  Lab Station      | 3/1/2026      | New       | |
| 16    | GPS Breakout Board                                           |  1  | SparkFun        |  Lab Station      | 3/1/2026      | New       | Not in Use. |
| 17    | Additional Power Regulation Components                       |  1  | Adafruit        |  Lab Station      | 3/1/2026      | New       | |
| 18    | USB Interface / Power Module                                 |  1  | Adafruit        |  Lab Station      | 3/1/2026      | New       | |
| 19    | PLA Filament (3D Printing)                                   |  1  | Amazon          |  Lab Station      | 3/1/2026      | New       | |
| 20    | Liquid Electrical Insulation (Flex Seal)                     |  1  | Amazon          |  Lab Station      | 3/1/2026      | New       | |
| 21    | Aluminum Sheet Material                                      |  1  | Amazon          |  Lab Station      | 3/1/2026      | New       | |
| 22    | Epoxy / PCB Coating Material                                 |  1  | DigiKey         |  Lab Station      | 3/1/2026      | New       | |
| 23    | Power Regulation IC                                          |  1  | DigiKey         |  Lab Station      | 3/1/2026      | New       | |
| 24    | Precision Resistors (Vishay Series)                          |  3  | Mouser          |  Lab Station      | 3/1/2026      | New       | |
| 25    | DC-DC Converter (TDK Lambda)                                 |  1  | Mouser          |  Lab Station      | 3/1/2026      | New       | |
| 26    | Power Management IC                                          |  1  | Mouser          |  Lab Station      | 3/1/2026      | New       | |
| 27    | Surface Mount Resistors                                      |  1  | Mouser          |  Lab Station      | 3/1/2026      | New       | |
| 28    | Switching Regulator Module                                   |  1  | Mouser          |  Lab Station      | 3/1/2026      | New       | |
| 29    | USB Connector (Type-C / Interface)                           |  1  | DigiKey         |  Lab Station      | 3/1/2026      | New       | |
| 30    | Resettable Fuse (PTC)                                        |  1  | DigiKey         |  Lab Station      | 3/1/2026      | New       | |
| 31    | TVS Diode (Overvoltage Protection)                           |  1  | DigiKey         |  Lab Station      | 3/1/2026      | New       | |
| 32    | MLX90640 IR Thremal Camera                                   |  1  | Adafruit        |  Lab Station      | 3/1/2026      | New       | In use. |
| 33    | MicroSD card breakout board+                                 |  1  | Adafruit        |  Lab Station      | 3/1/2026      | New       | Not in Use. |

## Statment of Contributions:
- Matthew Henderson - Power Harvesting and Battery Charging Subsystem Experiment, Overall Conclusion, Inventory Table
- Brady Goodman - Power Harvesting and Battery Charging Subsystem Experiment, Inventory Table
- Daniel Attih - Camera Sensing and Control & Communication Subsystem Experiment, Inventory Table
- Lawson Striklin - Camera Sensing and Control & Communication Subsystem Experiment, Inventory Table
- Grant Christy - Mechanical and Structural Experimental Analysis
