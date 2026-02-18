// 1. DEFINITIONS AND CONSTANTS
DEFINE SERVO_PIN GPIO 22 // GPIO PIN on PICO
DEFINE PWM_FREQUENCY 50  // Standard 50 Hz 
DEFINE PWM_PERIOD_US 20000 // 20,000 microseconds (20 ms)

// Define Pulse Widths in microseconds (µs) for MG90S
DEFINE PULSE_DOWN_US AS 1000  // Corresponds to 0 degrees (initial down, retracted)
DEFINE PULSE_HOOKED_US AS 1500 // Corresponds to 90 degrees (extended)

// Define Servo Command States (using an enum/integer)
typedef enum ServoState{
    SERVO_STATE_RETRACTED = 0
    SERVO_STATE_EXTENDED = 1
};

// Define FreeRTOS Queue Handle
QueueHandle_t ServoCommandQueue

// 2. PWM SETUP FUNCTION
FUNCTION Initialize_PWM():
    // Configure Pico PWM for 50 Hz operation
    PWM_slice = Get_PWM_Slice(SERVO_PIN)
    Set_PWM_Frequency(PWM_slice, PWM_FREQUENCY)
    Set_PWM_Wrap_Value(PWM_slice, PWM_PERIOD_US) // Sets the ARR value based on the clock divider
    Enable_PWM_Output(SERVO_PIN)
    
// Function to convert microsecond pulse width to PWM duty cycle value
FUNCTION Set_Servo_Pulse_Width(pulse_us):
    PWM_Duty_Cycle_Value = Convert_us_to_PWM_Ticks(pulse_us, PWM_PERIOD_US)
    Set_PWM_Duty_Cycle(PWM_slice, PWM_Duty_Cycle_Value)

// 3. MAIN SERVO TASK
TASK ServoControlTask(Parameters)
{
    
    // Local variable to store the command received from the queue
    ServoState command_received

    // --- Initialization ---
    Initialize_PWM()
    
    // Set initial position immediately upon startup (Initial Down)
    Set_Servo_Pulse_Width(PULSE_DOWN_US) 
    
    // --- Task Loop (Infinite Loop) ---
    for (;;);
    {
    
        // 1. Wait for Command (This is the blocking step that yields the CPU)
        // Wait indefinitely (portMAX_DELAY) for a new state command to arrive in the queue.
        IF xQueueReceive(ServoCommandQueue, &command_received, portMAX_DELAY) IS successful:
            
            // 2. Process Command
          IF SERVO_STATE_RETRACTED  // if the current state of the arm is 0/retratced/the arm is down
            IF command_received IS SERVO_STATE_RETRACTED:
                continue
            IF command_received IS SERVO_STATE_EXTENDED:
                // Set PWM pulse to the 'Hooked' (90 degree) position
                Set_Servo_Pulse_Width(PULSE_HOOKED_US)
                
          ELSE IF command_received IS SERVO_STATE_EXTENDED: // if the current state if the arm is 1/extended or up
            IF command_received IS SERVO_STATE_RETRACTED:
                // Set PWM pulse to the 'Down' position
                Set_Servo_Pulse_Width(PULSE_DOWN_US)
            IF command_received IS SERVO_STATE_EXTENDED:
                continue
            
            // 3. Task Yield (Optional but good practice after minimal work)
            // Since the movement is fast and the task is back to waiting on the queue,
            // we yield to let any other Ready task (like GPS) run immediately.
            taskYIELD() // small time 
    }
}
