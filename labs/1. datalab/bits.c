/* 
 * CS:APP Data Lab 
 * 
 * Xavier Bonavita | mlbonavita@wpi.edu
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /* 
  The left side of this equation (~(x&y)) ensures any paring of bits 
   that contain at least one 0 are true. (Anything that isnt double 1s)
    * Ex: ~(0101 & 1001) is 1110
  The right side of this equation (~(~x & ~y)) ensures any double 0s are false.
    * Ex: ~(~0101 & ~1001) = ~(0010) = 1101
  Combining these, we complete the XOR
    * Ex: 1110 & 1101 is 1100
  */
  return (~(x & y) & (~(~x & ~y)));
}

/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  // this is simply putting 2^0 back by 32 powers of 2, leading to negative 32bit limit
  return 1 << 31;
}

//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  /*
  Using a mask, ^ing it to the input int will give us either a 0 or another value
  To create the mask we just start with 0x7F, left shift by 8 and | with 0xFF. This
   constructs the max integer of 0x7FFFFFFF after 3 iterations
  Iff the value is 0, it is the max number. This first value is then !ed to provide a true or false output
    * Ex) !(1111 ^ 1001) = !(0110) = 0
    * Ex) !(1111 ^ 1111) = ~(0)    = 1
  */

  int _max = 0x7FFFFFFF; // here for debugging.
  int component = 0x000000FF;
  int max = (0x7F << 8) | component;
      max = (max  << 8) | component;
      max = (max  << 8) | component;
  
  return !(max ^ x);
}

/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /*
  Using a mask, &ing it to the input int will cause all bits but odd ones to either become a 0 or 1
    * Ex) 1101 & 1010 is 1000
  Once calculated, if the string still matches the string when XOR-ed, it will return 0.
  This is then inverted to present the true value. If they do not match, it will lead to some other value
   and be turned into a 0 by the !
   * Ex) 1000 ^ 1010 is 0010. This is not all 0s, therefor it will lead to a false output when !ed
   * Ex2) 1010 ^ 1010 is 0000. Once !d, it becomes 0001 
  */
  int _mask = 0xAAAAAAAA; // here for debugging

  int component = 0xAA;
  int mask = 0xAA << 8 | component;
      mask = mask << 8 | component;
      mask = mask << 8 | component;
  return !((x & mask) ^ mask);
}

/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /* NOTE: x-yyy where x is sign bit and y is integer
  Since the sign bit is the most significant bit, all we need to do is 
   just invert all the bits.
    * Ex) (4) ~0-100 is 1-011.
  This will cause an off by one error as, for the sake of understanding, 
   consider 0 (0-000) to be part of the positive numbers. This means we 
   must add 1 to the final result.
    * 1-011 + 1 is 1-100.
  */
  return ~x + 1;
}

//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /*
  This function checks if the input integer x is within the ASCII range for digits '0' to '9'.
  The first condition checks if x is greater than or equal to 0x30.
  The second condition checks if x is less than or equal to 0x39.
  Both conditions are combined using the AND operator to return 1 if both are true, otherwise 0.
  */
  int lowerBound = 0x30;
  int upperBound = 0x39;
  return !((x + (~lowerBound + 1)) >> 31) & !((upperBound + (~x + 1)) >> 31);
}

/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /* 
  The first part of this code converts x to 0 (if it wasn't 0 to begin with) 
   or 1 if it was 0 to begin with.
   
  We then create a mask of all 1s if x is not 0, or all 0s if x is 0.
  (mask & y) | (~mask & z) combines the results of the previous two operations 
   using the | operator. The resulting number will have bits set to 1 if they 
   were set to 1 in either mask & y or ~mask & z.
  */
  int mask = !!x;
  mask = ~mask + 1; 
  return (mask & y) | (~mask & z);
}

/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /*
  This function checks if x is less than or equal to y.
  First, it calculates the difference between y and x.
  Then, it checks if the difference is non-negative.
  It also handles the case where x and y have different signs.
  */
  int diff = y + (~x + 1);
  int xNeg = x >> 31 & 1;
  int yNeg = y >> 31 & 1;
  int diffNeg = diff >> 31 & 1;
  return (xNeg & !yNeg) | (!(xNeg ^ yNeg) & !diffNeg);
}

//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {  
  /*
  The first part of this function (x | (~x + 1)) turns x into its negative form.
  This is done as with every number but 0, on a ~ operation, the sign bit will flip. 
    * 1-1010101 | (~1-1010101 + 1) = 1-1010101 | 0-0101011 = 1-1111111.
    * 0000      | (~0100 + 1)      = 0000     | 0100       = 0100
  We then right shift 31 times to have the rignbit in the lowest position possible. 
  1 is then added to change the value to true if it is 0.
  */

  return ((x | (~x + 1)) >> 31) + 1;
}

/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    /*
    The first part of this code is variable definitions. The sign function determines
     if a number is positive or negative as >> 31 any number will result in -1 for negative
     and 0 for non-negative.

    The next secetion of code, 'x = (sign...' is an absolute value.
     if x is negative, (sign & ~x) will result in the bitwise not of x.
     if x is non negative, (~sign & x) will result in x

    The 3rd section, specifically '!!(x >> 16) << 4' checks if any of the higher 16 bits are set. 
    If so, it returns 1, otherwise 0. This rest is then shifted left by 4 bits (<< 4), effectively multiplying it by 16.
    this is then repeted with a narrowing shift.

    These numbers are then added together to give the final count.
    */
    int b16, b8, b4, b2, b1, b0;
    int sign = x >> 31;

    x = (sign & ~x) | (~sign & x);

    b16 = !!(x >> 16) << 4;
    x = x >> b16;
    b8 = !!(x >> 8) << 3;
    x = x >> b8;
    b4 = !!(x >> 4) << 2;
    x = x >> b4;
    b2 = !!(x >> 2) << 1;
    x = x >> b2;
    b1 = !!(x >> 1);
    x = x >> b1;
    b0 = x;

    return b16 + b8 + b4 + b2 + b1 + b0 + 1;
}

//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  /*
  This code takes an unsigned integer and returns that number multiplied by 2
  1. Extract the sign, exponent, and fraction parts from the input.
  2. If the exponent is all 1s (0xFF), the number is either NaN or infinity, so return it as is.
  3. If the exponent is zero, the number is denormalized, so shift the fraction left by 1.
  4. If the exponent is non-zero, increment the exponent by 1.
  5. If incrementing the exponent results in it becoming 0xFF, set the fraction to 0 to represent infinity.
  6. Combine the sign, updated exponent, and fraction back into a single unsigned integer and return it.
  */
  unsigned sign = uf & 0x80000000;
  unsigned exp  = (uf & 0x7F800000) >> 23;
  unsigned frac = uf & 0x007FFFFF;

  if (exp == 0xFF) {
    return uf; // NaN or infinity
  }

  if (exp == 0) {
    frac <<= 1; // Denormalized values
  } else {
    exp += 1; // Normalized values
  }

  if (exp == 0xFF) {
    frac = 0; // Overflow to infinity
  }

  return sign | (exp << 23) | frac;
}

/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  /*
  This code converts a floating-point number to an integer. 
  1. It extracts the exponent and adjusts it by subtracting 127 (the bias).
  2. It extracts the fraction part and adds the implicit leading 1.
  3. If the exponent is too large (>= 31), it returns the minimum signed integer value (overflow).
  4. If the exponent is negative, it returns 0 (underflow).
  5. Depending on the exponent, it shifts the fraction left or right to convert it to an integer.
  6. Finally, it returns the integer, negating it if the sign bit is set.
  */
  unsigned sign = uf >> 31;
  int exp = ((uf >> 23) & 0xFF) - 127;
  unsigned frac = (uf & 0x007FFFFF) | 0x00800000;

  if (exp >= 31) {
    return 0x80000000u;
  }
  if (exp < 0) {
    return 0;
  }

  frac = (exp > 23) ? (frac << (exp - 23)) : (frac >> (23 - exp));

  return sign ? -frac : frac;
}

/* #include "floatPower2.c" commented by Weinstock request by MCV 20210929-1619 */
/* 
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) {
  /*
  This code checks if the given floating-point number is NaN (Not a Number).
  It uses a mask to ignore the sign bit and checks if the exponent bits are 
    all 1s and the fraction bits are non-zero.
  If 'uf' is NaN, it returns 'uf' unchanged.
  Otherwise, it flips the sign bit of 'uf' and returns the result.
  */
  unsigned mask = 0x7FFFFFFF;
  unsigned nanCheck = 0x7F800000;

  if ((uf & mask) > nanCheck) {
      return uf;
  }

  return uf ^ 0x80000000;
}
