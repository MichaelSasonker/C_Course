#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ex.h"


void SwapTestFunc(int *ptr1, int *ptr2);
void CopyArrFuncTest(int *arr1, int *arr2, int length);
void ArrPrint(int arr1[], size_t size);
void SwapTwoSizeTFuncTest(size_t *ptr1, size_t *ptr2);
void SwapTwoSizeTPtrTest(size_t **ptr1, size_t **ptr2);

/***************************************************/
int main()
{
	int *ptr1 = NULL;
	int *ptr2 = NULL;
	
	int *arr1 = NULL;
    	int *arr2 = NULL;
    
    	int length = 0;
    	int i = 0;
    
    	size_t *size_ptr1 = NULL;
    	/* size_t *size_ptr2 = NULL; */
    
    
    	size_t **ptr_ptr_sizet1 = NULL;
    	size_t **ptr_ptr_sizet2 = NULL;
    
    	length = 10;
    
    	arr1 = (int*) malloc(length * sizeof(int));
    	assert(arr1);
    	arr2 = (int*) malloc(length * sizeof(int));
    	assert(arr2);
    
    	for(i = 0; i < length; ++i)
    	{
    		arr1[i] = i*i;
    	}
    
    	SwapTestFunc(ptr1, ptr2);
    
    	CopyArrFuncTest(arr1, arr2, length);
    
    
    	SwapTwoSizeTFuncTest(size_ptr1, size_ptr1);
    	SwapTwoSizeTPtrTest(ptr_ptr_sizet1, ptr_ptr_sizet2);
	
	free(arr1);
    	free(arr2);
    
    	return (0);
}

/********************************************************/
void SwapTestFunc(int *ptr1, int *ptr2)
{
	int first_number;
	int second_number;
	
	first_number = 100;
	second_number = -55;
	
	ptr1 = &first_number;
	ptr2 = &second_number;
	
	SwapFunc(ptr1, ptr2);
	
	if ((-55 != first_number) || (100 != second_number))
	{
		printf("Error in SwapFunc: test1\n");
		ptr1 = NULL;
		ptr2 = NULL;
		exit (0);
	}
	
	first_number = 0;
	
	SwapFunc(ptr1, ptr2);
	
	if ((100 != first_number) || (second_number))
	{
		printf("Error in SwapFunc: test2\n");
		ptr1 = NULL;
		ptr2 = NULL;
		exit (0);
	}
	printf("Test approved \n");
	ptr1 = NULL;
	ptr2 = NULL;
}

/********************************************************/
void CopyArrFuncTest(int *arr1, int *arr2, int length)
{
    int i = 0;
    
    ArrCopy(arr1, arr2, length);
    
    for (i = 0; i < length; i++)
    {
    	if (arr1[i] != arr2[i])
    	{
    		printf("Error CopyArrFunc: test1\n");
    		exit (0);
    	}
    }
    
    printf("Test approved\n");
}

/*********************************************************/
void SwapTwoSizeTFuncTest(size_t *ptr1, size_t *ptr2)
{
	size_t first_size;
	size_t second_size;

	first_size = sizeof(char);
	second_size = sizeof(double);

	ptr1 = &first_size;
	ptr2 = &second_size;

	SwapSizeT(ptr1, ptr2);

	if ((sizeof(double) != first_size) || (sizeof(char) != second_size))
	{
		printf("Error SwapSizeT: test1\n");
		exit (0);
	}
	else
	{
		printf("Approved\n");
	}
/*
	ptr1 = NULL;

	SwapSizeT(ptr1, ptr2);
	printf("Error SwapSizeT: test2\n");
	exit (0);
	printf("Approved\n");
*/
}

/****************************************************************/
void SwapTwoSizeTPtrTest(size_t **ptr1, size_t **ptr2)
{
	size_t a;
	size_t b;
	
	size_t *first_pointer;
	size_t *second_pointer;
	
	a = sizeof(char);
	b = sizeof(int);
	
	first_pointer = &a;
	second_pointer = &b;
	
	ptr1 = &first_pointer;
	ptr2 = &second_pointer;
	
	SwapSizeTPtr(ptr1, ptr2);
	
	if ((a != **ptr2) || (b != **ptr1))
	{
		printf("Error SwapSizePtr: test1\n");
		exit (0);
	}
	else
	{
		printf("Approved\n");
	}
/*
	ptr1 = NULL;
	if (!SwapSizeTPtr(ptr1, ptr2))
	{
		printf("Error SwapSizePtr: test2\n");
	}
	printf("Approved\n");
*/
}

