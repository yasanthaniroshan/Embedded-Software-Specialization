# Attributes and Pragmas

## Attributes
- Attributes can give specific details on how to compile code for
    - Variables
    - Structures & Structure Members
    - Functions
- ```c
    struct struct_name {
    int8_t   var1;
    int32_t var2;
    int8_t   var3; 
    } __attribute__ ((packed))
    ```
### Alignment Attributes

- Alignment attributes specify memory alignment for data 
    - Power of two: 2, 4, 8, 16
- Structures and structure members can be aligned
    - Structure is aligned, all members aligned
    - Structure is packed, alignment ignored
## Function Attributes

- Compiler Attributes can apply to Functions
- `inline` – Skips calling convention, copies function body into calling code
- ```c
    __attribute__ ((always_inline)) inline int32_t add( int32_t x, int32_t y ) {
        return (x + y);
    }
    ```

## Pragmas
- Pragmas are compiler directives
- `#pragma` – Compiler specific directives
### Function Pragmas
- Pragmas provide special instructions to the compiler
- Push/Pop – Add extra option for compilation
- Optimize – Specify a certain level of optimization block of code
- ```c
    #pragma GCC push
    #pragma GCC optimize (“O0”)
    int32_t add( int32_t x, int32_t y ) 
    {
        return (x + y);
    }
    #pragma GCC pop
    ```

## GNUC Support
- Embedded teams can support multiple chipset platforms and multiple architectures
- Different architecture may require different compiler
    - `__attribute__(x)` is only a GCC compiler keyword, 
    Throws errors for other compilers 
- ```c
    #ifndef (__GNUC__)
    #define __attribute__ (x) 
    #endif 
    ```