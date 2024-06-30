# Word Size and Data Types

## Architectures
- CISC (Complex Instruction Set Computer)
- RISC (Reduced Instruction Set Computer)
- ARM (Advanced RISC Machine)

## Units of Operation
- Instruction 

    Fundamental unit of work or operation
    - Arithmetic
    - Logical
    - Program Flow Control
    - Load/Store
- Word
    
    The size of the data that the CPU can process in a single operation
    - 8-bit
    - 16-bit
    - 32-bit
    - 64-bit

## Standard Integer Sizes
- There are three standard integer categories

    - Exact Width
    - Minimum Width
    - Fastest

    - Exact Width
        - `int8_t`
        - `int16_t`
        - `int32_t`
        - `int64_t`
    - Minimum Width
        - `int_least8_t`
        - `int_least16_t`
        - `int_least32_t`
        - `int_least64_t`
    - Fastest
        - `int_fast8_t`
        - `int_fast16_t`
        - `int_fast32_t`
        - `int_fast64_t`

    - unsigned for all of the above


