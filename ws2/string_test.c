#include <stdio.h>  /* printf      */
#include <stdlib.h> /* pointers    */
#include <string.h> /* strcmp      */
#include <assert.h> /* assert func */
#include "string.h" /* my own func */

int main ()
{
    int own = 0;
    int str_c = 0;

	const char str[] = "Hello";
	const char str1[] = "NULL";
	const char str2[] = "NULL";
	const char str3[] = "B";

	printf("The legth of the string is: %lu\n", StrLen(str));
	printf("The legth of the string is: %lu\n", StrLen(str1));
	printf("The legth of the string is: %lu\n", StrLen(str2));
	printf("The legth of the string is: %lu\n", StrLen(str3));	

	printf("The value is: %d\n", StrCmp(str1, str3));
	printf("The value is: %d\n", StrCmp(str1, str2));
	printf("The value is: %d\n", StrCmp(str3, str2));	
	
	printf("The value is: %d\n", strcmp(str1, str3));
	printf("The value is: %d\n", strcmp(str1, str2));
	printf("The value is: %d\n", strcmp(str3, str2));	
    
    own = StrCmp(str3, str);
    str_c = strcmp(str3, str);

    if (own == str_c)
    {
        printf("SUCCESS!!!\n");
    }
    else
    {
        printf("FAILED!!!\n");
    }

    return (0);
}

