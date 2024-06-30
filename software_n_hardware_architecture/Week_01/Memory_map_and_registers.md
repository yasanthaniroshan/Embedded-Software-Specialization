# Memory Map and Registers
- Memories of an Embedded Systems
    - Code Memory (Flash)
    - Data Memory (SRAM)
    - Register Memory (internal to chip)
    - External Memory (if applicable)

- Compilation tracks and maps memory from a program into segments (Specified in linker script)

## Registers

- Registers store temporary data
    -Can Be Read/Write or Read-Only
- Typically divided into multiple bit fields

## Memory Map

- Provides a memory address to physical device mapping within an address space for use in programming

## Memory Allocation

- Compilation tracks and maps memory from program code and program data into segments
    - Code Segment (Flash)
    - Data Segment (SRAM)
- Memory allocation is application dependent
    - Exact address allocation changes at every compile

## Register Memory
- Registers from Peripherals, System and Vendor specific regions have immutable addresses

- Typical Register Memories
    - Internal Core CPU
    - Internal Private Peripherals
    - External Private Peripherals
    - General Peripheral Memory