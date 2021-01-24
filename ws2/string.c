/****************************************
 * string.c				                *
 * Developer: Michael Sasonker		    *
 * Reviewer: Yonatan Uzan		        *
 * Status: Send				            *	
 ***************************************/

#include <stdio.h>  /* printf           */
#include <stdlib.h> /* pointers         */
#include <assert.h> /* assert func      */
#include "string.h" /* my own functions */

/* finding the length of a string */
size_t StrLen(const char *str)
{
    const char *start_pnt = str; /* saving the start point of the string */
    assert(str);

    while ('\0' != *str)         /* if *str = \0 stop promoting str */
    {
        ++str;
    }

    return (str - start_pnt); /* return the length of the string */
}

/* compering between the strings charecters */
int StrCmp(const char *str1, const char *str2)
{
    assert(str1);
    assert(str2);

/* if the charecters are different or equal '\0' the loop terminates        */ 
   
    while ((*str2) && (*str1 == *str2))   /* if both of them are equal '\0' */ 
    {                                     /* the while loop will still      */
                                          /* promoting them!!! (unallocated */                                    
        ++str1;
        ++str2;
    }

    return (*str1 - *str2); 
}

