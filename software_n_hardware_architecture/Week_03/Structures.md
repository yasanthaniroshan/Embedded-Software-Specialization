# Structures

- Structures are used to define a new data type that groups together variables of different types.
- Structures require 
    - Struct keyward
    - Unique structure name
    - list of variables

- ```c
    struct Point {
        int x;
        int y;
    };
    ```
- ```c
    typedef struct {
        int x;
        int y;
    } Point;
    ```
- Structures are used give number of parameters to a function without using pointers.
- Also it can be used to return multiple values from a function.