# Interfacing with Memory

## Memories of an Embedded Systems
- Code Memory (Flash)
- Data Memory (SRAM)
- Register Memory
- The CPU and peripherals contain register memory
    - CPU Registers
        - General Purpose
        - Special Purpose
    - General Peripheral Registers

## Read Modify Write
- **Read** - Data is loaded into CPU
- **Modify** - Data is Operated on
- **Write** - Result is stored back


- Compiler tries to reduce number of loads and stores for execution efficiency

## Peripheral Registers
- Peripheral register require some contents (bit-fields) to be preserved

- Use bit manipulation to change certain bits of a register (not all contents)

## Bit-Banded Regions
- Bit-Banded Regions allow programmer to perform bit-level loads and stores
- Bit-Banded operations are atomic
    - Handled in hardware
    - No CPU Load/Store


## Private Bus Interfaces
- AMBA High-Performance Bus (AHB)
    - Fast/High-Bandwidth Interfaces

- Private Cortex-M4 Busses
    - Internal Private Peripherals Bus (PPB)
        - NVIC, SCS, MPU
    - External Private Peripherals Bus (PPB)
        - External Debugging

## Code and Data Busses
- AHB External Core AHB busses
    - System Bus (AHB-Lite) 
        - SRAM
        - High Speed Peripherals
        - Peripheral Bridge
    - Flash Bus
        - I-Code Bus
        - D-Code Bus

## Peripheral Busses
- Advanced Peripheral Bus (APB)
    - Low Bandwidth Bus
    - Connected to CPU via Bridge to System Bus
- Interfaces with Low Bandwidth
    - Communications
        - UART
        - SPI
        - I2C
    - Timers
    - ADC