/****************************************
 * string_test.c                        *
 * Developer: Michael Sasonker          *
 * Reviewer: Yaniv Kaplan               *
 * Status: Approved                     *   
 ***************************************/


#define _XOPEN_SOURCE 500         /*for use with strdup /
#define _POSIX_C_SOURCE 200809L    /for use with strdup */

#include <stdio.h>   /* printf      */
#include <stdlib.h>  /* size_t      */
#include <string.h>  /* strcmp      */
#include <strings.h> /* strcasecmp  */
#include <assert.h>  /* assert func */
#include "string.h"  /* my own func */

/*****************************************************************************/
int main()
{
    char str1[20];
    char str2[20];

    char str3[30]; 
    char str4[30];
    size_t num = 4;
    
    char str11[30] = "aaaaaaaaa";
 	char str12[30] = "aaaaaaaaa";

    char str13[30] = "TtAAA";
    char str14[30] = "TtAAA";

    /* test with strcpy */
    printf("strcpy result is: %s\n", strcpy(str1, "aq1xsw2cde3"));
    printf("StrCpy result is: %s\n", StrCpy(str2, "aq1xsw2cde3"));
    
    
    /* test with strncpy */
    printf("strncpy result is: %s\n",strncpy(str3, "This is a test", num)); 
    printf("StrNCpy result is: %s\n",StrNCpy(str4, "This is a test", num)); 
    
    /* test with strcasecmp*/
    printf("strcasecmp result is %d\n", strcasecmp("AbCde", "abcDE"));
    printf("StrCaseCmp result is %d\n", StrCaseCmp("AbCde", "abcDE"));

 
    /* test with strchr */ 
    printf("strchr result is: '%s'\n", strchr("www.google.com", '.')); 
    printf("StrChr result is: '%s'\n", StrChr("www.google.com", '.'));


    /* test with strdup */ 
    printf("strdup result is: %s\n", strdup("AdEfR"));
    printf("StrDup result is: %s\n", StrDup("adEfR"));

    /* test with strcat */
    printf("strcat result is: %s\n", strcat(str11, "ABCd"));
    printf("StrCat result is: %s\n", StrCat(str12, "ABCd"));
    

    /* test with strncat */ 
    printf("strncat result is: %s\n", strncat(str13,"Bla", 2));
    printf("StrNCat result is: %s\n", StrNCat(str14,"Bla", 2));

    /* test with strstr */
    printf("strstr result is %s\n",strstr("I'm Tired", "red"));
    printf("StrStr result is %s\n", StrStr("I'm Trired", "red"));

    /* test with strspn */
    printf("strspn result is %lu\n", strspn("hu", "I'm hungry"));
    printf("StrSpn result is %lu\n", StrSpn("hu", "I'm hungry"));
     
    return (0);
}



