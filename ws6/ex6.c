/****************************************
 * WS6 - ex6.c                     	    *
 * Developer: Michael Sasonker          *
 * Reviewer: Ruslan Goldman		        *
 * Status:  approved                  	* 	  
 ***************************************/

#include <stdio.h> /* printf */

#define BIT_MASK (1) 		/* assumption - LSB is in 0th place */
#define BIT_NUMBER_ONE (2)
#define BIT_NUMBER_TWO (4)
#define BIT_NUMBER_THREE (8)
#define BIT_NUMBER_FOUR (16)
#define BIT_NUMBER_FIVE (32)
#define BIT_NUMBER_SIX (64)

union Number	/* to look on float in the eyes of int */
{
	int i;
	float f;
};


/*---------------------------------------------------------------------------*/
/* compute x*2^y */
long Pow2(unsigned int x, unsigned int y)
{
	return (long)(x << y);  /* move x bit's y times */
}

/*---------------------------------------------------------------------------*/
/* Checks if a number is a power of 2 using loop */
int IsPow2Loop(unsigned int x)
{
	while (0 == (x & BIT_MASK) && x > 1) /* x & 1 give us 0 if it has only one bit on  */
	{							  /* if x equal to 0 it will return 0 		    */
		x >>= BIT_MASK;				  /* equavalent to dividing by 2 			    */
	}
	return (x == 1);			  /* after division x is equal to 1				*/
}

/*---------------------------------------------------------------------------*/
/* Checks if a number is a power of 2 without loop */
int IsPow2(unsigned int x)
{
	if ((0 == x) || (0 == (x - 1)))	/* if x is equal to 0 return 0 	*/
	{
		return (0);
	}
	return (0 == ((x) & (x - 1)));	/* if x is power of 2 than x & (x-1) is equal 0 */
}
/*---------------------------------------------------------------------------*/
/* add one to the an integer */
int AddOne(int x) 
{ 
    int m = BIT_MASK; 

    while (x & m) 	/* loop until one of them is 0 */
    { 
        x ^= m;		/* set 1 only when differnet   */ 
        m <<= BIT_MASK; 	
    } 
 				
    x ^= m; 		/* flip the rightmost 0 bit    */
    
    return x; 
} 
/*---------------------------------------------------------------------------*/
/* Prints numbers that have exactly 3 bits on */
void Print3BitsOn(unsigned int *arr, size_t size_arr)
{
	size_t count = 0;
	size_t num_of_bit_on = 3;
	unsigned int val_arr = 0; /* for saving the value of the int */
	
	while (size_arr > 0)	  
	{
		val_arr = *arr;		  /* saving the value */	
		while ((*arr != 0) && (count < num_of_bit_on))	
		{
			if (*arr & BIT_MASK)	 /* check if the last bit is 1 */
			{
				++count;
			}
			*arr >>= BIT_MASK;		 /* devide by 2 */
		}
		if (num_of_bit_on == count)
		{
			printf("the number is:%d\n", val_arr);
		}
		
		count = 0;			/* reset count var */
		++arr;				
		--size_arr;
	}	
}
/*---------------------------------------------------------------------------*/ 
/* return the mirror of a char */ 
unsigned char ByteMirror(unsigned char c)
{    
    unsigned char mirror_c = 0;
	unsigned char mask = BIT_MASK;
	
	while (mask > 0)
    {
        mirror_c <<= BIT_MASK;
        if (c & mask)			/* loop until one of them is 0 */
        {
            mirror_c |= 1;		/* duplicate the var		   */
    	}
    	mask <<= BIT_MASK;
	}
	
    return (mirror_c);
}

/*---------------------------------------------------------------------------*/	
/* return the mirror of char without using loop */
unsigned char ByteMirrorNoLoop(unsigned char c)
{		  /*11110000*/		/*00001111*/
   c = (c & 0xF0) >> BIT_NUMBER_TWO | (c & 0x0F) << BIT_NUMBER_TWO;	
 		  /*11001100*/  	/*00110011*/								
   c = (c & 0xCC) >> BIT_NUMBER_ONE | (c & 0x33) << BIT_NUMBER_ONE;
   		  /*10101010*/		/*01010101*/
   c = (c & 0xAA) >> BIT_MASK | (c & 0x55) << BIT_MASK;
   
   return (c);
}
/*---------------------------------------------------------------------------*/
/* return true if bit numbers 2 AND 6 are on */
int IsBit2And6On(unsigned char c)
{
	return ((c & BIT_NUMBER_TWO) && (c & BIT_NUMBER_SIX));  	
	/* 					0x04 						0x40 		*/
}   
/*---------------------------------------------------------------------------*/
/* return true if bit numbers 2 OR 6 are on */
int IsBit2Or6On(unsigned char c)
{
	return ((c & BIT_NUMBER_TWO) || (c & BIT_NUMBER_SIX)); 
	/* 					0x04 						0x40 		*/
}

/*---------------------------------------------------------------------------*/
/* swap bit number 3 and 5 */
unsigned char SwapBit3And5(unsigned char c)
{
    c ^= 1 << 3;
    c ^= 1 << 5;
    return c;
}
/*---------------------------------------------------------------------------*/
/* return the cloest number that is divisible by 16 */
unsigned int ReturnClosestDivisibleBy16(unsigned int x)
{
	x &= 0xFFFFFFF0;	/* 28 bits are 1 and the last 4 are set to 0 */
	
	return (x);
}
/*---------------------------------------------------------------------------*/
/* swap two values using bitwise operators */
int SwapValues(unsigned int *xp, unsigned int *yp)
{
	if (*xp == *yp)
	{
		printf("the numbers are equals!\n");
		return (-1);
	}
	else
	{
    	*xp = *xp ^ *yp; 
    	*yp = *xp ^ *yp; 
    	*xp = *xp ^ *yp;
	}
	return (0);
}
/*---------------------------------------------------------------------------*/
/* return how much bit set to 1 */
unsigned int CountOnBits(unsigned int x)
{ 
   int count = 0;
   
   while (0 != x)
   {
      if (x & BIT_MASK)	/* if bit is set to 1 increment count */
      {
         ++count;
      }
      x >>= BIT_MASK;  
   }

   return count;
}
/*---------------------------------------------------------------------------*/
/* return the bits set to 1 without using loop */
unsigned int CountOnBitsNoLoop(unsigned int x)
{
	unsigned int temp_a = 0;  		/* counts odd bits */
	unsigned int temp_b = 0;		/* counts even bits */
	
	temp_a = x & 0x55555555; 		/*1010101010.... 32 bit */
	temp_b = (x >> BIT_MASK) & 0x55555555;
	
	temp_a = temp_a + temp_b;
	
	/* the following lines sum the result of the count: groups of 2, 4, 8 and 16 */	
	temp_a = (temp_a & 0x33333333) + ((temp_a >> BIT_NUMBER_ONE) & 0x33333333); 	/* 001100110011 */
	temp_a = (temp_a & 0x0f0f0f0f) + ((temp_a >> BIT_NUMBER_TWO) & 0x0f0f0f0f); 	/* 000001111 */
	temp_a = (temp_a & 0x00ff00ff) + ((temp_a >> BIT_NUMBER_THREE) & 0x00ff00ff); 	/* 8x0 + 8x1 */
	temp_a = (temp_a & 0x0000ffff) + ((temp_a >> BIT_NUMBER_FOUR) & 0x0000ffff); /* 16x0 + 16x1 */
	
	return (temp_a);
}
/*---------------------------------------------------------------------------*/
/* print float number in binary mode */
void PrintFloatInBinary(float num)
{
	union Number num_int;
	num_int.f = num;
	 
	while (0 != num_int.i) 
	{
    	if (num_int.i & 0x80000000)	/* MSB is 1 and the rest are 0 */
    	{
    	    printf("1");
	    }
    	else
    	{
    	    printf("0");
		}
    	num_int.i <<= BIT_MASK;	/* devide by 2 */ 
	}
	printf("\n");
}
/*---------------------------------------------------------------------------*/


