// 1. DEFINITIONS AND CONSTANTS
DEFINE UART_ID AS UART1          // Use Pico's UART1 peripheral
DEFINE BAUD_RATE 9600         // Standard GPS communication rate
DEFINE RX_PIN GPIO5            // Pico pin for UART Receive
DEFINE TX_PIN GPIO4            // Pico pin for UART Transmit 

// Define a structure for the latest GPS Fix data (shared buffer)
typedef struct Gps_t:
    float latitude
    float longitude
    int fix_quality          // 0, 1, 2, etc.
    float heading_degrees    // From the integrated compass
    Time_t rtc_time_from_gps // For time synchronization

// Define a FreeRTOS Mutex Handle to protect the shared data
MutexHandle_t GpsDataMutex

// Global variable for the latest valid GPS fix
Gps_t LatestGpsFix
Gps_t InvalidFixMarker // A predefined structure to signify bad data

// 2. UART SETUP FUNCTION
FUNCTION Initialize_UART():
    Configure_UART_Pins(RX_PIN, TX_PIN)
    Set_UART_Baud_Rate(UART_ID, BAUD_RATE)
    // Configure UART to use interrupts for efficient data reception
    Enable_UART_Interrupt(UART_ID)

// 3. MAIN GPS RECEIVER TASK (High Priority)
TASK GPSReceiverTask(Parameters)
{
    // --- Initialization ---
    Initialize_UART()
    Initialize_NMEA_Parser() // Initialize the NMEA library (e.g., TinyGPS++)
    LatestGpsFix = InvalidFixMarker
    GpsDataMutex = Create_Mutex()

    // --- Task Loop (Infinite Loop) ---
    for(;;)
    {

        // 1. Read UART Data
        // Use a non-blocking or short-timeout read to process incoming characters
        WHILE UART_RX_Has_Data(UART_ID):
            character = Read_UART_Character(UART_ID)

            // 2. Process NMEA Sentence
            IF NMEA_Parser_Feed(character) IS successful:
                // Character was accepted and processed by the NMEA library

                // 3. Check for Valid Fix
                IF NMEA_Parser_Has_Valid_Location() AND NMEA_Parser_Has_Valid_Time():

                    // 4. Update Shared Buffer (CRITICAL SECTION)
                    IF xSemaphoreTake(GpsDataMutex, timeout_ms=50) IS successful:
                        
                        // Copy the latest data from the parser library to the shared global structure
                        LatestGpsFix.latitude = NMEA_Parser_Get_Latitude()
                        LatestGpsFix.longitude = NMEA_Parser_Get_Longitude()
                        LatestGpsFix.fix_quality = NMEA_Parser_Get_Fix_Quality()
                        // (Note: Compass read often requires a separate I2C step, but GPS time/loc is here)
                        
                        xSemaphoreGive(GpsDataMutex) // Release the mutex
        // 5. Yield Control
        // Briefly yield the CPU after processing the available buffer to let other tasks run
        taskYIELD()
     }
}
