# Numbers

## Bases

- Each "place" is an order of magnitude larger than the last
- For base 10, starting from right to left we have the 1s place, 10s place, 100s place, and so on.

- 10: these are our 'regular' numbers.
- 8: Octal
  - Right to left, (8^0) 1s place, (8^1) 8s place, (8^2) 64s place
- 2: **Binary**
  - Right to left, 2^0, 2^1, 2^2, 2^3......
  - Either a 0 or a 1 - can be used to express a state
    - These are called **bits**
    - A collection of 8 bits is a **byte**
      - Half of a byte (4 bits) is a **nibble**
- 16: **Hexadecimal**
  - Usually begins with the prefix `0x`
  - From right to left: 16^0, 16^1, 16^2, 16^3......
  - 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F
  - A number like "F3A" is equal to: 16(16^2) + 3(16^1) + 10(16^0)
- Comparison:
  - Using base 2 compared to base 16, 2^8 = 256 = 16^2
  - we need 9 values (2^0 through 2^8) in binary to express what we would need three values for in hexadecimal
