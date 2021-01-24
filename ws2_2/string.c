/****************************************
 * string.c				                *
 * Developer: Michael Sasonker		    *
 * Reviewer: Yaniv Kaplan		        *
 * Status: Approved      	    	    *	
 ***************************************/

#include <stdio.h>  /* printf           */
#include <stdlib.h> /* size_t           */
#include <assert.h> /* assert func      */
#include "string.h" /* my own functions */

/******************************************************************************/
char *StrCpy(char *dest, const char *source)
{
    char *start = NULL;
    assert(dest);                           /* check its not junk             */
    assert(source);

    start = dest;                           /* pointing to the start address  */
    
    while (*source)                         /* if *source = '\0' stop         */  
    {
        *dest = *source;                    /* copy source to dest            */
        ++dest;          
        ++source;    
    }

    *dest = '\0';                           /* put '\0' at the end            */  

    return (start);
}

/*****************************************************************************/
/* copies up to n charecters from source to dest */
char *StrNCpy(char *dest, const char *source, size_t n)
{
    char *start = NULL;
    assert(dest);
    assert(source);
    
    start = dest;                   /* saving the start point of dest         */

    while ((*source) && (n))        /* if n equal to 0 or *source is '\0'     */
    {                               /* exit the while loop                    */
        --n;
        *dest = *source;            /* copies the values of source            */
        ++dest;                     
        ++source;
    }

    *dest = '\0';                   /* adding \0 to the end                   */

    return (start);
}

/*****************************************************************************/
int StrCaseCmp(const char *string1, const char *string2)
{
	char str1_cpy = '\0';
	char str2_cpy = '\0';

	while ((*string1) && (*string2))
	{
		str1_cpy = *string1;
		str2_cpy = *string2;
		
		if (('A' <= *string1) && (*string1 <= 'Z'))
		{
			str1_cpy = *string1 + 32;
		}
		
		if (('A' <= *string2) && (*string2 <= 'Z'))
		{
			str2_cpy = *string2 + 32;
		}
		
		if (str1_cpy != str2_cpy)
		{
			break;
		}
		
		else
		{
			++string1;
			++string2;
		}
	}
	
	return (str1_cpy - str2_cpy);
}

/*****************************************************************************/
/* search for the first occurence of char c */
char *StrChr(const char *str, int c)
{
    assert(str);

    while (*str)                    
    {
        if (c == *str)                      /* if the value of *str is equal */
        {                                   /* to char c                     */
            return ((char  *)str);          /* return pointer to this place  */
        }
        ++str;
    }
    if ('\0' == c)                          /* if char c is equal to \0      */
    {
        return ((char *)str);               /* return the start point of str */
    }

    if (*str)                               /* if *str is \0 return NULL     */ 
    {
        return (NULL);
    }
    return (0);
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
/*****************************************************************************/
/* StrDup duplicate a string using dynamic memory allocation.                */
char *StrDup(const char *str)
{
    char *str_dup = NULL;
    size_t len = 0;
    char *start = (char *)str;

    assert(str);

    len = StrLen(str);
    ++len;
    str = start;

    str_dup = (char *)malloc(len * sizeof(char)); /* sizeof char equals 1 */
    if (NULL == str_dup)
    {
        return (NULL);
    }

    str_dup = StrCpy(str_dup, str);

    return (str_dup);
}

/*****************************************************************************/
/* StrCat concatenates the dest string and the source string to dest string */
char *StrCat(char *dest, const char *source)
{
    assert(dest);
    assert(source);

    StrCpy(dest + StrLen(dest), source);    /* sent to StrCpy the end point  */
                                            /* of dest with source string    */
    return (dest);
}
/*****************************************************************************/        
/* StrNCat copies up to n characters from the string pointed to,             */
/* by source to dest.                                                        */
char *StrNCat(char *dest, const char *source, size_t n)
{
   
    assert(dest);
    assert(source);

    StrNCpy(dest +StrLen(dest), source, n); /* sent to StrNCpy the end point  */
                                            /* of dest with source string and */
    return (dest);                          /* the number of chars to copy    */  
}

/*****************************************************************************/
/* strstr finds the first occurrence of the substring sub_str in str.        */
char *StrStr(const char *str, const char *sub_str)
{
    char *str_start = NULL;
    char *sub_str_start = NULL;

    assert(str);
    assert(sub_str);

    str = StrChr(str, *sub_str);       /* finding the start point of sub_str */
                                       /* in str.                            */   

    str_start = (char *)str;
    sub_str_start = (char *)sub_str;   /* saving the start points            */

    while (str)                        /* str != NULL                        */
    {
        while (*sub_str == *str)       /* the values are equal               */  
        {
            ++sub_str;
            ++str;
            if (*sub_str == '\0')      /* if sub_str is at his end point     */
            {
                return (str_start);     
            }
        }

        sub_str = sub_str_start;
        str = ++str_start;            /* if not, increment str and search    */
        str = StrChr(str, *sub_str);  /* again for sub_str inside str        */
        str_start = (char *)str;
    }
    
    return (NULL);
}

/*****************************************************************************/
/* StrSpn calculates the length of the initial segment of str1 which consists*/
/* consists  entirely of characters in str2.                                 */
size_t StrSpn(const char *str1, const char *str2)
{
    size_t len = 0;
    
    assert(str1);
    assert(str2);

    while (*str1 && StrChr(str2, *str1))  /* if *str is not \0 and           */
    {                                     /* we have some result from StrChr */
        ++len;
        ++str1;
    }
    return (len);
}

