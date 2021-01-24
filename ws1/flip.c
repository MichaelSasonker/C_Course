#include<stdio.h>
/* #include "flip.h" */

int FlipFunc( int num );

int main() 
{
	int num = -2408;
	int res;

	res = FlipFunc( num );
	printf("The Flip Function result is: %d\n", res);



	return 0;
}

/* Function */
int FlipFunc(int num)
{
        int flip_num = 0;

        while (num)
        {
                flip_num = (num % 10) + (flip_num * 10);
                num /= 10;

        }

        return  flip_num;
}

