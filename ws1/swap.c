#include<stdio.h>

void SwapFunc(int *num1, int *num2);

int main() 
{
	int num1 = 10, num2 = -20;

	printf("Before Swap function: num1 = %d num2 = %d\n", num1, num2);
	SwapFunc(&num1, &num2);
	printf("After Swap function: num1 = %d num2 = %d\n", num1, num2);

	return 0; 
}

void SwapFunc(int *num1, int *num2)
{
	int tmp = 0;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
