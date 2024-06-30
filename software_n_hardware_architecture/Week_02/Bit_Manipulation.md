# Bit Manipulation
- Bit Manipulation used to configure microcontrollers
- All arithmetic operations can be done with bitwise operations
- Bitwise operators are needed to configure peripherals
- Peripheral registers require some contents (bit-fields) to be preserved
- Use bit manipulation to change certain bits of a register (not all contents)

## Bitwise Operators
- C-programming provides bitwise operators
    - <<   >>   &  |   ^  ~

## Setting a Bit
- To set a bit, use the bitwise OR operator (|)
- ```c
    uint8_t foo = 0x84;
    foo = foo | 0x30;
    ```
- Using Assignment Operator we can provides a cleaner shorthand for same expression 
- ```c
    foo |= 0x30;
    ```

- Alternatively, `foo |= (0x03 << 4);` can be used to set the 4th and 5th bits of `foo` to 1

## Clearing a Bit
- To clear a bit, use the bitwise AND operator (&)
- ```c
    uint8_t foo = 0xFF;
    foo = foo & 0x3F;    
    ```
- As above using Assignment Operator
- ```c
    foo &= 0x3F;
    ```
- Specifying bits you wish to clear is more readable
- ```c
    foo &= ~(0xC0);    
    ```

## Toggling a Bit
- To toggle a bit, use the bitwise XOR operator (^)
- ```c
    uint8_t foo = 0x0C;

    foo = foo ^ 0x0E;
    ```
- Using Assignment Operator
- ```c
    foo ^= 0x0E;
    ```
- To toggle a single bit, use the XOR operator with a mask
- ```c
    foo ^= (1 << 3);
    ```
- This will toggle the 3rd bit of `foo`

## Bit Masks

- Bit Masks are constant expressions used to set, clear, or toggle a specific set of bits
- Use Preprocessors to make code more readable
- ```c
    #define MASK1 (0x30)
    #define MASK2 (0xC0)
    #define MASK3 (0x0E)
    foo |=  MASK1 ;
    foo &=  MASK2 ;
    foo ^=  MASK3 ;
    ```

## Peripheral Configuration

- Often need to combine set and clear to create desired effect without destroying other bit values
- Example
    - Set Bits: 4 & 5
    - Clear Bits: 6 & 7
    - Preserve Other Bit Values
- ```c
    uint8_t * ptr = (uint8_t *)0x40004C02;
    *ptr &= ~(BIT6 | BIT7) ;
    *ptr |= (BIT4 | BIT5);
    ```
## Bit Band Alias
- Each bit in the Peripheral & SRAM region is bit addressable
    - Bits are word aligned