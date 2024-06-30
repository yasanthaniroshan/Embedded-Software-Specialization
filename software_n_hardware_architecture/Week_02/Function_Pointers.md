# Function Pointers
- Pointer that points to functions
- Defined just like a function
    - Return type
    - Function parameters
    - Pointer name
- Dereferencing a function pointer will call a function
-       <type> (* <function_pointer_name>)(<parameter list>) = <function-address>;
- ```c
    void (* foo)(); 
    int8_t void (* bar)( int8_t a, int8_t * b );  
    uint32_t (* func)( uint8_t param );
    ```
- Function pointers can be declared with an array
- ```c
    typedef void (* FuncPtr_t[2])();
    FuncPtr_t example = 
    {
        foo,
        bar
    };
    typedef void (* FuncPtr_t());
    FuncPtr_t example[2] = 
    {
        foo,
        bar
    };
    ```
- Interrupts are special events that request the CPU to perform a specific operation
- Interrupt Service Routine (ISR): Function to be called in response to an interrupt request 
- Vector table is an array of function addresses
    - Used to “jump” into a routine when interrupt occurs