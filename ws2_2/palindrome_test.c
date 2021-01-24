/****************************************
 * palindrome_test.c                    *
 * Developer: Michael Sasonker          *
 * Reviewer: Yaniv Kaplan               *
 * Status: sent                         *   
 ***************************************/

#include <stdio.h>       /* printf      */
#include <stdlib.h>      /* size_t      */
#include <assert.h>      /* assert func */
#include "palindrome.h"  /* my own func */

int main()
{

    /* test Palindrome */
    Palindrome("ABBA");
    Palindrome("abcdcba");
    Palindrome("a1ol");

    return (0);
}

