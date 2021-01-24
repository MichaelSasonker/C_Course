/****************************************
 * Palindrome.c                         *
 * Developer: Michael Sasonker          *
 * Reviewer: Yaniv Kaplan               *
 * Status: sent                         *   
 ***************************************/

#include <stdio.h>      /* printf           */
#include <stdlib.h>     /* size_t           */
#include <assert.h>     /* assert func      */
#include "palindrome.h" /* my own func      */

/*****************************************************************************/
/* Palindrome checks if a string is a palindrome            */
void Palindrome(const char *str)
{
    size_t i = 0;
    size_t end = StrLen(str) - 1;   /* end of the string                  */
    assert(str);

    while (end > i)                 
    {
        if (str[i] != str[end])     /* if end & start points are not equal */ 
        {
            printf("%s is not palindrome!\n", str);
            return;
        }
        ++i;                    
        --end;                      
    }
    printf("%s is palindrome!\n", str);
}

/*****************************************************************************/
/* finding the length of a string */
size_t StrLen(const char *str)
{
    const char *start_pnt = str; /* saving the start point of the string */
    assert(str);


    while (*str)                 /* if *str = \0 stop promoting str */
    {
        ++str;
    }

    return (str - start_pnt);    /* return the length of the string */
}
