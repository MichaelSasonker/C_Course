#include<stdio.h>

float PowerFuncOf10(int num);

int main()
{
	int n = -3; 
	float res = 0.0;
	res = PowerFuncOf10(n);
	printf(" 10^(%d) = %f\n", n, res);

	return 0;
}

/* Function */
float PowerFuncOf10(int num)
{
        float base = 10.0, sum = 1.0;
        int i = 0;

        if (num < 0)
        {
                num *= (-1);
                base = 0.1;
        }

        for (i = 0;i < num; ++i)
        {
                sum *= base;
        }


        return sum;
}


