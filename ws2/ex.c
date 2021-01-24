/****************************************
 * ex.c					                *
 * Developer: Michael Sasonker		    *
 * Reviewer: Yonatan Uzan		        *
 * Status: Send				            *	
 ***************************************/

#include <stdio.h>  /* printf */
#include <stdlib.h> /* pointers */
#include "ex.h"     /* my own func */ 

/* swap two integers */
void SwapFunc(int *num1, int *num2)
{
    if (NULL == num1 || NULL == num2) /* real values check */
    {
        printf("ERROR!");
        exit (0);                     /* exit the program */
    }

    *num1 = *num1 + *num2;            /* saving the pointers value without tmp variable */         
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}

/* copy arr1 values to arr2 */
void ArrCopy(int arr1[], int arr2[], size_t size)
{
    size_t i = 0;

    for (i = 0; i < size; ++i)
    {
        arr2[i] = arr1[i]; /* copy the values of arr1 to arr2 */
    }
}

/* printing an array */
void ArrPrint(int arr1[], size_t size)
{
    size_t i = 0;

    printf("The elements of the array are:\n");
    for (i = 0; i < size; ++i)
    {
        printf("%d, ", arr1[i]);
    }
    printf("\n");
}

/* swap two size_t type variables */ 
void SwapSizeT(size_t *num1, size_t *num2)
{
    size_t tmp = 0;

    if (NULL == num1 || NULL == num2) /* real values check */
    {
        printf("ERROR!");
        exit (0);                     /* exit the program */
    }

        tmp = *num1;                  /* saving num1 value in tmp variable */
        *num1 = *num2;                /* saving the value of num2 in num1  */
        *num2 = tmp;                  /* saving the value of num1 in num2  */
}

/* swap two *size_t type variables */
void SwapSizeTPtr(size_t **ptr_to_ptr1, size_t **ptr_to_ptr2)
{
    size_t *tmp = 0;

    if (NULL == *ptr_to_ptr1 || NULL == *ptr_to_ptr2) /* real values check */
    {
        printf("ERROR!");
        exit (0);                                     /* exit the program */
    }

    tmp = *ptr_to_ptr1;            /* saving the address in tmp variable   */
    *ptr_to_ptr1 = *ptr_to_ptr2;   /* saving the address of *ptr2 in *ptr1 */ 
    *ptr_to_ptr2 = tmp;            /* saving the address of *ptr1 in *ptr2 */
}

