# Add executable. Default name is the project name, version 0.1
# Src folder CMakeLists.txt

add_executable(${ProjectName}
    final.c
    modules/DS3231RTC/DS3231.c
    modules/servoMotor/mg90s.c
    modules/gps_module/gps.c
    modules/thermal_camera/MLX90640_API.c
    modules/thermal_camera/MLX90640_I2C_Driver.c
    modules/sdcard/sd_logger.c
    modules/thermal_camera/thermal_detection.c
)

# Generate PIO header
pico_generate_pio_header(${ProjectName} ${CMAKE_CURRENT_LIST_DIR}/blink.pio)

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(${ProjectName} 0)
pico_enable_stdio_usb(${ProjectName} 1)

# Add the standard include files to the build
target_include_directories(${ProjectName} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/modules/DS3231RTC
        ${CMAKE_CURRENT_LIST_DIR}/modules/servoMotor
        ${CMAKE_CURRENT_LIST_DIR}/modules/gps_module
        ${CMAKE_CURRENT_LIST_DIR}/modules/thermal_camera
        ${CMAKE_CURRENT_LIST_DIR}/modules/sdcard
        ${CMAKE_CURRENT_SOURCE_DIR}/../lib/pico_fatfs
        ${CMAKE_CURRENT_SOURCE_DIR}/../lib/pico_fatfs/fatfs
        ${CMAKE_CURRENT_SOURCE_DIR}/../lib/pico_fatfs/fatfs/conf
)

# Add any user requested libraries
target_link_libraries(${ProjectName} 
        pico_stdlib
        FreeRTOS-Kernel-Heap4
        hardware_spi
        hardware_i2c
        hardware_pio
        hardware_timer
        hardware_clocks
        hardware_pwm
        pico_fatfs
        )

pico_add_extra_outputs(${ProjectName})

