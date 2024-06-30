# Software Interface for Hardware
- Microcontrollers have a variety of
    - Peripherals
    - Registers
    - Memories

- Software Architecture: structured organization of a software project

- Design software to be independent of architecture and platform


- Firmware layer needs to be efficient and bug-free
- Make higher level software independent of low level firmware
    - Example: application software
- Interface methods for hardware
    - Register Definition Files
    - Macro Functions
    - Specialized C-Functions

## Register Definition Files

- Platform File that provides interface to peripheral memory by specifying
    - Address List for Peripherals
    - Access Methods
    - Defines for Bit Fields and Bit Masks

- Peripheral Access Methods used to read/write data
    - Preprocessor Macros
    - Direct Dereferencing of Memory
    - Structure Overlays

## Macro Functions
- ```c
    /* Macro Function to Read Memory */
    #define HWREG16(x)  (*((volatile uint16_t *)(x)))
    ```
- ```c
    #define TA0CTL_ADDR (0x40000000)

    / * 16 Bit Register Access Macros */
    #define HWREG16(x)  (*((volatile uint16_t *)(x)))
    /* Sample Usage */
    (*((volatile uint16_t *)(0x40000000))) = 0x0202;
    /* Same as above */
    HWREG16(TA0CTL_ADDR) = 0x0202;
    ```
- ```c
    #define SET_PORT_PIN_DIR (port, pin) ((port)->DIR |= (1 << pin));
    SET_PORT_PIN_DIR( P1, PIN0 );
    ```
- Numerous Issues with Macro Functions
    - No Type Checking
    - Bug Introduction
    - Complex / Confusing Layers of Macros Calling Macros
    - Code Size and Duplication

## Specialized C-Functions

- Functions are excellent for encapsulating a specialized operation
- Calling a traditional C-function can decrease performance due to calling convention overhead
    - Saving data to stack
    - Creating local variables
    - Branching

- ```c
    __attribute__( ( always_inline ) ) static inline void __enable_irq(void)
    {
    __ASM volatile ("cpsie i" : : : "memory");
    }
    ```
- Static Keyword can apply to functions to create private access

- Combine Static and Inline to prevent integrating all code into calling function
    - Linkage is internal to file
