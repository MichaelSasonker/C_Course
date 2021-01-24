/****************************************
 * WS6 - betwise.h         	            *
 * Developer: Michael Sasonker          *
 * Reviewer: Ruslan Goldman		        *
 * Status:  approved                   	* 	  
 ***************************************/

#ifndef __ILRD_BITWISE_H__
#define __ILRD_BITEWISE_H__


long Pow2(unsigned int x, unsigned int y);
int IsPow2Loop(unsigned int x);
int IsPow2(unsigned int x);
int AddOne(int x);
void Print3BitsOn(unsigned int *arr, size_t size_arr);
unsigned char ByteMirror(unsigned char c);
unsigned char ByteMirrorNoLoop(unsigned char c);
int IsBit2And6On(unsigned char c);
int IsBit2And6On(unsigned char c);
int IsBit2Or6On(unsigned char c);
unsigned char SwapBit3And5(unsigned char c);
unsigned int ReturnClosestDivisibleBy16(unsigned int x);
int SwapValues(unsigned int *xp, unsigned int *yp);
unsigned int CountOnBits(unsigned int x);
unsigned int CountOnBitsNoLoop(unsigned int x);
void PrintFloatInBinary(float number);


#endif
