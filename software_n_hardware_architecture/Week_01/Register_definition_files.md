# Register Definition Files
- Platform File that provides Interface to peripheral memory by specifying
    - Address List for Peripherals
    - Access Methods
    - Defines for Bit Field and Bit Masks

- Peripheral Access Methods are used to read/write data
    - Direct Dereferencing of Memory
    - Structure Overlays

## Direct Dereferencing of Memory
- Do not need a pointer variable to read/write to memory
- Use preprocessor to define an access method without using hardcoded values
- ```c
    / * 8, 16, & 32 Bit Register Access Macros */
    #define HWREG8(x)       (*((volatile   uint8_t *)(x)))
    #define HWREG16(x)     (*((volatile uint16_t *)(x)))
    #define HWREG32(x)     (*((volatile uint32_t *)(x)))


    #define TA0CTL              (HWREG16(0x40000000))
    ```
## Structure Overlays
- Define a Structure to directly match peripheral region registers
- Structure Overlays require exact replica of peripheral region
    - Size registers to equivalent standard types
    - Order Matters
    - Leave space for reserved bytes
    - Read-Only Registers = **Const**!
    - All registers are **volatile**
- ```c
    #define __IO (volatile)
    #define __I    (volatile const)

    typedef struct {
    __IO uint16_t CTL; 
    __IO uint16_t CCTL[7]; 
    __IO uint16_t R;
    __IO uint16_t CCR[7];
    __IO uint16_t EX0;
    uint16_t RESERVED0[6];
    __I  uint16_t IV;
    } Timer_A_Type;
            /* Define the Base Address of Peripheral Regions */
    #define PERIPH_BASE          ((uint32_t) 0x40000000)
    #define TIMER_A0_BASE     (PERIPH_BASE + 0x00000000) 
    #define TIMER_A0                 ((Timer_A_Type *) TIMER_A0_BASE)
    
    TIMER_A0->CTL = 0x0202;

    ```

## Identifying Correct Register File

- Use Compile Time Switches to include correct Register Definition File
- ```c
    #ifdef MSP432_VER1
    #include “MSP432_Version1.h”
    #else
    #include “MSP432_Version2.h”
    #endif
    ```

## Volatile Keyword
- Volatile tells compiler NOT to optimize this code
    - Volatile variable needs to be directly read and written when specified
- ```c
    / * 8, 16, & 32 Bit Register Access Macros */
    #define HWREG8(x)       (*((volatile   uint8_t *)(x)))
    #define HWREG16(x)     (*((volatile uint16_t *)(x)))
    #define HWREG32(x)     (*((volatile uint32_t *)(x)))
    ```
- Peripherals should be configured as soon as code executes, not moved to a later point in time
