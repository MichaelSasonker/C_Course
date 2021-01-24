/****************************************
 * WS6 - ex6_test.c                  	*
 * Developer: Michael Sasonker          *
 * Reviewer: Ruslan Goldman		        *
 * Status:  approved                   	* 	  
 ***************************************/

#include <stdio.h>		/* printf 		*/
#include "bitwise.h"	/* my own funcs */


static void PrintBinary(unsigned int num);

int main()
{	
	size_t size_arr = 7;	
	unsigned int arr[] = {5, 8, 10, 7, 11, 15, 0};
	unsigned int *ptr = arr;
	int res = 0;
	unsigned int n1 = 5;
	unsigned int n2 = 5;
	unsigned int n3 = 0;
	unsigned int n4 = 2;
		
	printf("result of Pow2 func is:%ld\n", Pow2(11,0));
	printf("result of Pow2 func is:%ld\n", Pow2(3,5));
	printf("-------------------------------------\n");
		
	printf("IsPowLoop result is:%d, %d, %d, %d\n", IsPow2Loop(8), IsPow2Loop(0), IsPow2Loop(1), IsPow2Loop(5));
	printf("IsPow result is:%d, %d, %d, %d\n", IsPow2(1), IsPow2(0), IsPow2(8), IsPow2Loop(5));
	printf("-------------------------------------\n");

	printf("AddOne result is:%d\n", AddOne(8));
	printf("AddOne result is:%d\n", AddOne(5));
	printf("-------------------------------------\n");
	
	Print3BitsOn(ptr, size_arr);
	printf("-------------------------------------\n");	
	
	printf("the binary char is:\n");
	PrintBinary(217);
	printf("ByteMirror result is:\n");
	PrintBinary(ByteMirror(217));	
	printf("-------------------------------------\n");	
	
	printf("the binary char is:\n");
	PrintBinary('h');
	printf("ByteMirrorNoLoop result is:\n");
	PrintBinary(ByteMirrorNoLoop('h'));	
	printf("-------------------------------------\n");
	
	printf("IsBit2And6On result is:%d\n", IsBit2And6On(68));
	printf("IsBit2Or6On result is:%d\n", IsBit2Or6On(20));
	printf("-------------------------------------\n");
	
	PrintBinary('z');
	printf("SwapBit3And5 result is:\n");
	PrintBinary(SwapBit3And5('z'));
	printf("-------------------------------------\n");
	
	printf("ReturnClosestDivisibleBy16 result is:%u\n", ReturnClosestDivisibleBy16(85));
	printf("-------------------------------------\n");
	
	printf("before SwapValues is:%u, %u\n", n1, n2);
	res = SwapValues(&n1, &n2);
	printf("exit status of SwapValues is:%d\n", res);
	printf("SwapValues result is:%u, %u\n", n1, n2);
	printf("-------------------------------------\n");
	
	printf("before SwapValues is:%u, %u\n", n3, n4);
	res = SwapValues(&n3, &n4);
	printf("exit status of SwapValues is:%d\n", res);
	printf("SwapValues result is:%u, %u\n", n3, n4);
	printf("-------------------------------------\n");

	printf("CountOnBits result is:%u\n", CountOnBits(53));
	printf("-------------------------------------\n");
	
	printf("CountOnBitsNoLoop result is:%u\n", CountOnBitsNoLoop(53));
	printf("-------------------------------------\n");
	
	printf("PrintFloatInBinary result is:\n");
	PrintFloatInBinary(53.0);
	PrintFloatInBinary(-53.0);
	PrintFloatInBinary(-1.0);
	printf("-------------------------------------\n");
	
	
		
	return (0);
}	

/*---------------------------------------------------------------------------*/
/* print number in binary */
static void PrintBinary(unsigned int num)
{
	while (0 != num) 
	{
    	if (num & 1)	/* if the last bit is on */
    	{
    	    printf("1");
	    }
    	else
    	{
    	    printf("0");
		}
    	num >>= 1;		/* devide by 2 */ 
	}
	printf("\n");
}





