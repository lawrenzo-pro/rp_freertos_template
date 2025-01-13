cmake_minimum_required(VERSION 3.13)
set(PICO_BOARD "pico_w")
set(PICO_SDK_PATH "/home/lawrence/.pico-sdk/sdk/2.1.0/")
set(FREERTOS_KERNEL_PATH "/home/lawrence/.local/lib/FreeRTOS-Kernel/")
set(sdkVersion 2.1.0)
set(picotoolVersion 2.1.0)
set(pioasm_DIR "/home/lawrence/.pico-sdk/tools/${sdkVersion}/pioasm")
set(picotool_DIR "/home/lawrence/.pico-sdk/picotool/${picotoolVersion}/picotool")

set(projectName "hello_rtos")

include(pico_sdk_import.cmake)
include(FreeRTOS_Kernel_import.cmake)

project(${projectName} C CXX ASM)


pico_sdk_init()

add_executable(${projectName} main.c)

target_include_directories(${projectName} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(${projectName} pico_stdlib FreeRTOS-Kernel-Heap4)

pico_enable_stdio_usb(${projectName} 1)
pico_enable_stdio_uart(${projectName} 0)
pico_add_extra_outputs(${projectName})