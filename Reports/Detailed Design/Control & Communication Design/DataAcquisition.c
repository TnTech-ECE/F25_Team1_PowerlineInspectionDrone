// 1. DEFINITIONS AND CONSTANTS
DEFINE LOGGING_INTERVAL_MS AS 1000 // 1 second logging rate

// Define the comprehensive structure for a single log entry
typedef struct LogEntry_t:
    int rtc_hour
    int rtc_minute
    int rtc_second
    float latitude
    float longitude
    int fix_quality
    float heading_degrees // Compass data
    
// Define FreeRTOS Queue Handle for the logger
QueueHandle_t DataLogQueue // Sends LogEntry_t structs to SDLoggerTask

// 2. MAIN DATA ACQUISITION TASK (Medium Priority)
TASK DataAcquisitionTask(Parameters):

    // Local structures for collecting data
    LogEntry_t current_log_record
    GpsFix_t temp_gps_fix // Holds copy of shared GPS data

    // --- Initialization ---
    // (the System Init already initializes I2C bus)
    Initialize_DS3231_RTC()
    Initialize_GOKU_Compass() // Configure the magnetometer part of the module
    
    // --- Task Loop (Periodic Schedule) ---
    LOOP FOREVER:
        
        // 1. Set Logging Schedule (Periodic Block)
        // Wait 1000ms. This is the primary block that controls the logging rate.
        vTaskDelay(LOGGING_INTERVAL_MS) 

        // 2. Read RTC and Compass (I2C)
        current_log_record.rtc_hour = Read_RTC_Hour()
        current_log_record.rtc_minute = Read_RTC_Minute()
        current_log_record.rtc_second = Read_RTC_Second()
        
        // Read compass via I2C
        current_log_record.heading_degrees = Read_Compass_Heading()
        
        // 3. Get GPS Data (CRITICAL SECTION)
        // Safely acquire the mutex to copy the latest GPS data from the shared buffer
        IF xSemaphoreTake(GpsDataMutex, timeout_ms=50) IS successful:
            temp_gps_fix = LatestGpsFix // Copy the entire global structure
            xSemaphoreGive(GpsDataMutex) // Release the mutex immediately
            
            // Populate the log record with GPS data
            current_log_record.latitude = temp_gps_fix.latitude
            current_log_record.longitude = temp_gps_fix.longitude
            current_log_record.fix_quality = temp_gps_fix.fix_quality
            
        ELSE:
            // Handle mutex timeout (rare error)
            current_log_record.fix_quality = -1 // Mark fix as invalid due to read failure
            
        END IF

        // 4. Servo Control Logic (Decision Point)
        // Check the compass heading and current servo state to determine if an action is needed.
        IF current_log_record.heading_degrees > 180 AND ServoState IS SERVO_STATE_DOWN:
            // Send command to the servo task to engage the hook
            xQueueSend(ServoCommandQueue, SERVO_STATE_HOOKED, 0)
            
        // Add logic for disengaging the hook if necessary
        // ELSE IF (Condition_to_Disengage):
        //     xQueueSend(ServoCommandQueue, SERVO_STATE_DOWN, 0)
        
        // 5. Send Data to Logger Queue
        // Send the complete record structure to the logging task queue.
        // Use a short block time (e.g., 10ms) in case the logger queue is momentarily full.
        xQueueSend(DataLogQueue, current_log_record, 10) 
        
    END LOOP
