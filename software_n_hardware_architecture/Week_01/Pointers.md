# Pointers
- **Pointer** is a variable that stores the memory address of another variable.
- **Pointer type** denotes the **data type** that a pointer will **dereference**
- All Pointers are the same length, regardless of the data type they point to.
- Dereference Operator = *(Accesses data at address)

- Address-of Operator = & (Returns the address of a variable)
- At time of pointer declaration, you might not know the address
    - Use a NULL Pointer for Initialization

- Null Pointers point to nothing
    - Used to check for valid pointer
    - ```c
        #define NULL ((void*)0)
        int *ptr = NULL;
        if(ptr != NULL) {
            // Do something
        }
      ```
- Cast pointers to dereference different sizes from same address
- Pointers exist any part of memory
- Pointers can reference data in different parts of memory