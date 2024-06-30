# Enumerations

- Enums are an enumerated type built into C program
- They are used to define a collection of named constants
    - int is the default data type for enum
- Enumeration defintion does not allocate memory
- Only the declaration of enum variable allocates memory
- Size of enum variable is defined in ABI
- Practices when defining enums
    - Use all uppercase for enum names
    - Use all uppercase for enum constants
    - Use enum name as prefix for enum constants
    - Use enum name as prefix for enum variable
    - Add final enum constant to define the size of enum

- ```c
    enum DIRECTION {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    enum DIRECTION dir;
    dir = NORTH;
    ```

- ```c
    typedef enum {
        MONDAY,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY,
        SUNDAY,
        DAYS_IN_WEEK
    } WEEKDAY;

    WEEKDAY day;
    day = MONDAY;
    ```

- Enum size can be optimized by flags `gcc -fshort-enums`