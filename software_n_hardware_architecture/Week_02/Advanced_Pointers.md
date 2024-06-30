# Advanced Pointers
- Memories of an Embedded System
    - Generic Pointer (void)
    - Double Pointer
    - Restrict Pointer

## Generic Pointer (void *)

- Void pointers are Generic Pointers, they point to a memory address
    - void = Lack of type, dereferencing does not make sense!

- Must cast before using
- No dereferencing on a void *
- No pointer arithmetic on a void *
- Void Pointers are NOT NULL Pointers, but a NULL Pointer is a Void Pointer
- ```c
    #define NULL (void*(0))
    void * ptr1 = NULL;
    ```

- Example 
    - Malloc and Void *
    - Malloc reserves blocks of data, it does not care how it is used
        - Returns a void pointer, you cast this pointer for the intended use
    - ```c
        char * ptr;
        ptr = (char *)malloc(8*sizeof(char));

        if (ptr == NULL) {
        /* Allocation Failed!!! */
        /* …Handle Failure */
        }
        /* Other Code */
        free((void *)ptr);
        ```

## Double Pointer
- Double pointers are a pointer to a pointer
- Must use the ** in declarations
- ```c
    uint32_t var = 0x1234ABCD;
    uint32_t * ptr3 = &var;
    uint32_t ** ptr4 = &ptr3;
    ```
- Used to set value of a pointer (address)
- Single dereference accesses pointer address
- Double dereference accesses pointer data
- Example
    - Copies of pointers are made when passed into a function
        - Original pointer address cannot be altered!
    - ```c
        typedef enum {
            RSP_TYPE_1 = 0,
            RSP_TYPE_2 = 1,
        } RSP_e;

        typedef struct {
            RSP_e rsp_type;
            uint8_t data[4];
        } rsp1;

        int8_t create_rsp1 (rsp1 ** r_p){
        *r_p = (rsp1 *)malloc(sizeof(rsp1));

        if (*r_p == NULL) {
            /* Allocation Failed!!! */
            return -1;
        }
        (*r_p)->rsp_type = RSP_TYPE_1;
        return 0;
        }

## Restrict Qualified Pointer
- Restrict type qualifier helps compiler to optimize memory interactions
    - Must use the restrict qualifier AFTER  the * in declarations
- Only the data at this location or data near is accessed by this pointer

- Largest speedup comes from iterative memory interaction
    - Compiler removes unneeded assembly instructions
    - Couple assembly instructions per loop 