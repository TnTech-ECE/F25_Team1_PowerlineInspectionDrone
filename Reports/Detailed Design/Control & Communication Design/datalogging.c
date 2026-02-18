// 1. DEFINITIONS AND CONSTANTS
DEFINE LOG_FILE_NAME AS "FLIGHTLOG.CSV"

// SPI Configuration for MicroSD (Adafruit #254)
DEFINE SPI_PORT SPI1
DEFINE SCK_PIN GPIO_10
DEFINE MOSI_PIN GPIO_12
DEFINE MISO_PIN GPIO_11 // The Slave sends to the master (Pi Pico
DEFINE CS_PIN GPIO_13 // Chip Select Pin (can be any GPIO)

// Handle for the file currently open on the SD card
FileHandle_t LogFileHandle


/**********************************************************************************/
/*************************** Helper Functions *************************************/
/**********************************************************************************/
// Function to initialize the SPI hardware and SD Card
FUNCTION Initialize_SD_Card():
    // 1. Initialize SPI Bus (Clock speed must be appropriate for SD card)
    Configure_SPI_Pins(SPI_PORT, SCK_PIN, MOSI_PIN, MISO_PIN)
    Set_SPI_Baud_Rate(SPI_PORT, low_speed_for_init) 
    
    // 2. Initialize SD Card (Sends SPI command sequence to wake up card)
    IF SD_Card_Init(CS_PIN) IS successful:
        Set_SPI_Baud_Rate(SPI_PORT, high_speed_for_data) // Increase clock for fast writing
        LogFileHandle = Open_File(LOG_FILE_NAME, "a") // Open file in Append mode
        IF LogFileHandle IS NULL:
            // Handle error: SD card initialized, but file could not be opened
            RETURN FAILURE
        END IF
        
        // Write CSV Header if the file is new/empty
        IF Get_File_Size(LogFileHandle) IS 0:
            Write_To_File(LogFileHandle, "Timestamp, Lat, Lon, Fix, Heading\n")
            Flush_File(LogFileHandle) // Ensure header is written
            
        RETURN SUCCESS
    ELSE:
        RETURN FAILURE // SD Card failed to initialize
    END IF

// Function to format the log data as a CSV line
FUNCTION Format_Log_Entry(LogEntry_t record):
    // Example: "09:30:15, 36.1234, -86.5678, 2, 185.5"
    RETURN Formatted_String


/**********************************************************************************/
/*************************** FreeRTOS**********************************************/
/**********************************************************************************/
// 3. MAIN SD LOGGER TASK (Lowest Priority)
TASK SDLoggerTask(Parameters):

    // Local variable to store the received log record
    LogEntry_t received_record
    
    // --- Initialization ---
    // Wait for SD card initialization to complete
    WHILE Initialize_SD_Card() IS NOT SUCCESS:
        vTaskDelay(5000) // Retry every 5 seconds if initialization fails
    END WHILE

    // --- Task Loop (Queue-Driven Block) ---
    LOOP FOREVER:
        
        // 1. Wait for Data (Blocking Step)
        // Wait indefinitely (portMAX_DELAY) for a LogEntry_t struct to arrive
        IF xQueueReceive(DataLogQueue, &received_record, portMAX_DELAY) IS successful:
            
            // 2. Format Data
            log_string = Format_Log_Entry(received_record)
            
            // 3. Write to File (SLOW, BLOCKING OPERATION)
            Write_To_File(LogFileHandle, log_string)
            
            // 4. Flush/Commit Data (Crucial for data integrity)
            // Periodically commit the buffered data to the physical card
            IF Write_Counter MOD 5 IS 0: // Example: Flush every 5 records
                Flush_File(LogFileHandle) 
            END IF
            
            Increment_Write_Counter()
            
            // 5. Yield Control
            // Yield immediately to let higher priority tasks (GPS, Servo, DataAcq) run.
            taskYIELD() 

        END IF
        
    END LOOP
