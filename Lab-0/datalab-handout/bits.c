/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 * <Christopher White - ralfil>
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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
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
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
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
   <http://www.gnu.org/licenses/>.  */
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
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* Rating 1 -- 2 points each */
/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  //0x55555555
//(0x55 << 24) + (0x55 << 16) + (0x55 << 8) + 0x55
    //0x55 << 8 + 0x55 = 0x5555
    //0x55 << 24
  return (0x55 << 24) + (0x55 << 16) + (0x55 << 8) + (0x55);
}
/*
 * minusOne - return a value of -1s
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
  //0xFF
  //~0x0
  //(0xFF << 24) + (0xFF << 16) + (0xFF << 8) + (0xFF)
  return ~0x0;
}
/*
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n) {
  //int x = 0x8
  //return x >> n;
  //return 0-n >> n
  //
  //(!!n << 32) >> n
  //
  //return n << (n + 2)
  //(n << (n+2)) << 24
  //((!!n << 31) >> (n + ~0)
  return (!!n << 31) >> (n + ~0);
}
/* Rating 2 -- 3 points each */
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  //((x << shiftLeft) >> 24) & 0xFF
  //if (n = 3)
  //then shiftLeft = 0
  //if (n = 2)
  //then shiftLeft = 8
  //if (n = 1)
  //then shiftLeft = 16
  //if (n = 0)
  //then shiftLeft = 24
  return (x >> (n<<3)) & 0xFF;
}
/*
 * isNotEqual - return 0 if x == y, and 1 otherwise
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  //!!(~x & y)
  //!(x ^ y)
  return !!(x ^ y);
}
/* Rating 3 -- 2 points each */
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  //final = !!x
  //final = 0x1 ^ y ^ final
  //final = 0x0 ^ z ^ final
  //x = !!x;
  //int final = 0x0 ^ z ^ x;
  //final = 0x1 ^ y ^ x;
  //
  //int final1 = y&(~(!!x)+1)
  //int final2 = z&(~(!!x)+1)
  //
  int a = !!x;
  int b = !x;
  int final1 = y & ( ~a + 1);
  int final2 = z & ( ~b + 1);
  //return (y & ((~(!!x)) + 1)) | (y & ((~(!x)) + 1));
  return final1 | final2;
}
/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  //exploits -z == ~z + 1

	int xMSB = (x>>31) & 1;
	int yMSB = (y>>31) & 1; //x most sig bit, y most sig bit


	return (
	( //first calc is if the signs are the same
	  (!(xMSB ^ yMSB)) & //x and y have the same sign
	  ((y + (~x + 1) /*y-x*/ )>>31 & 1) //y-x is a negative number
	)
	| //next, if the signs are different and y is negative, x>y
	(
	  (xMSB ^ yMSB) & //x and y have different signs
	  (yMSB & 1) //y is negative
	));
  //return (((!(xMSB ^ yMSB)) & ((y + (~x + 1))>>31 & 1)) | ((xMSB ^ yMSB) & (yMSB & 1)));
}
/* Rating 4 -- 1 point each */
/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  int mask = x >> 31;
  int ret = x + mask;
  ret = ret ^ mask;
  return ret;
}
/* Float Rating 2 -- 3 points each */
/*
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  int nanCheck = 0x000000FF << 23; //1's in the 8 exponent bits
  int frac = 0x7FFFFF & uf; //contains just the fraction value

  //return argument if exp bits are all 1's and frac is not zero
  if((nanCheck & uf) == nanCheck && frac)
    return uf;

  //otherwise, just flip the sign bit
  return uf ^ (1 << 31);
}
/* Float Rating 4 -- 1 point each */
/*
 * float_f2i - Return bit-level equivalent of expression (int) f
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
int float_f2i(unsigned uf) {
  unsigned sign = uf >> 31;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac =(uf & 0x7FFFFF);
  unsigned bias = 0x7F;
  unsigned res = frac;

  // special cases: NaN and Inf
  if (exp == 0xFF)
  {
    return 0x80000000u;
  }

  // denormalized case and normalized exp less than Bias cases
  if (exp < bias)
  {
    return 0x0;
  }
  // normalized cases
  exp -= bias;

  // overflow case
  if (exp >= 31)
  {
    return 0x80000000u;
  }

  // get integer result after shift corresponding bits
  if (exp > 22)
  {
    res = frac << (exp - 23);
  }
  else
  {
    res = frac >> (23 - exp);
  }

  // add 1 << exp for normalized case
  res += 1 << exp;

  // if sign = 1, change its sign
  if (sign) {
    res = -res;
  }

  return res;
}
