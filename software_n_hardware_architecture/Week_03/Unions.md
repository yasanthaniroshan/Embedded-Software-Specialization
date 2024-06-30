# Unions

- Derived data types that can store different types of data in the same memory location.
- Unions can contain multiple members of different data types.
    - Each can be different in size and type.
- The size of a union is the size of the largest member.
- Example 
- ```c
    typedef union 
    {
        struct {
            uint8_t x;
            uint8_t y;
        } point;
        uint16_t point;
    }
    ```
- Unions are used to save memory by sharing the same memory location for different data types.
- Unions are used to access the same memory location in different ways.
- ```c
    union {
        struct {
            uint8_t ABC:1;
            uint8_t DEF:1;
            uint8_t GHI:6;
        } point;
        uint8_t buffer;
    } u;
    u.buffer = 0x3F;
    printf("ABC: %d\n", u.point.ABC);
    ```
- If the memory is limited union can act as a shared memory location.