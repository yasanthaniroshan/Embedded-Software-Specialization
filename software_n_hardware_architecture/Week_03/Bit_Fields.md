# Bit Fields

- Bit fields allow to allocat,read and write data within union or struct that is smaller than a byte.
- Bit fields are used to optimize memory usage.
- Bit fields are used to access individual bits of a byte.
- ```c
    struct {
        uint8_t ABC:1;
        uint8_t DEF:1;
        uint8_t GHI:6;
    } point;
    ```
- Must be assigned a value that can be represented in the number of bits.
- Bit field must be larger than 0 and less than total type size.
- Bit fields pack into the type listed,until they cannot fit.
- Bit fields can be used in unions and structures.
- Bit fields can be mixed in with normal structure members.
- Bit fields will pack one right after the another until the etype size is met or exceeded.
- Reading / Writing bit fields implicitly use bit manipulation.
    - Reduces the execution efficiency.
    - Increase storage efficiency.
- Bit fields can enforce a particular alignment to internal structure.