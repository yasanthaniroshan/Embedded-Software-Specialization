# Endianness

- **Endianness** is the order of bytes in a multi-byte number. There are two types of endianness:
  - **Big-endian**: The most significant byte is stored at the lowest memory address.
  - **Little-endian**: The least significant byte is stored at the lowest memory address.
- Endianness does not affect order of elements Arrays or Structures

- Endianness is Configurable on many modern platforms

- Endianness must be accounted for 
    - Supporting Multiple platforms/Architectures with the same code base
    - Connecting multiple systems together