/****************************************
 * ex3.c				                *
 * Developer: Michael Sasonker		    *
 * Reviewer: Yonatan			        *
 * Status: approved		   	    	    *	
 ***************************************/

#include <stdio.h>		/* 	printf 		*/
#include <stdlib.h>		/* 	size_t 		*/
#include <string.h>		/* 	strlen 		*/
#include <assert.h>		/* 	assert 		*/

static size_t LenPtrToPtr(char **environ);
static void ToLowerStr(char *str);
static void CopyPtrToPtr(char **environ, char **buffer);
static void PrintBuff(char **buffer);
static void FreeBuff(char **buffer);

/*****************************************************************************/
/* prints the data type of C language */
void PrintDataTypes()
{	
	fprintf(stdout, "List of the data types and their size (bytes):\n");
	
	/* stdout is a pointer to a FILE stream that represents the default output device */
	fprintf(stdout, "char-%lu, signed char-%lu, unsigned char-%lu\n", sizeof(char), sizeof(signed char), sizeof(unsigned char));
	fprintf(stdout, "short-%lu, short int-%lu, unsigned short int-%lu\n", sizeof(short), sizeof(short int), sizeof(unsigned short int));
	fprintf(stdout, "signed int-%lu, unsigned int-%lu\n", sizeof(signed int), sizeof(unsigned int));
	fprintf(stdout, "long-%lu, unsigned long-%lu\n", sizeof(long), sizeof(unsigned long));
	fprintf(stdout, "float-%lu, fdouble-%lu\n", sizeof(float), sizeof(double));
	fprintf(stdout, "flong double-%lu\n", sizeof(long double));
}

/*****************************************************************************/
/* solution of Josephus problem */
size_t Josephus(size_t n)
{
    size_t *start_pnt = NULL;
    size_t *end_pnt = NULL;
    size_t *swrd_pnt = NULL;
    size_t *dead_pnt = NULL;
    size_t res = 1;
    
    if (1 == n)				
    {
        return (res);
    }

    start_pnt = (size_t *)calloc(n, sizeof(size_t));    /* the size is n*sizeof(size_t) */
    if (start_pnt == NULL) 							  /* allocation result 			  */
    { 
        printf("Memory not allocated\n"); 
        exit(0); 
    }
     
	end_pnt = (start_pnt + (n - 1));		/* end of the array 			  		  */
    swrd_pnt = start_pnt;					/* assumption- sword point at start point */
    dead_pnt = start_pnt + 1;				/* kill the next one					  */

    while (dead_pnt != swrd_pnt)			/* can kill only the next one			  */
    {
        *dead_pnt = 1; 						
        swrd_pnt = dead_pnt;

        while (*swrd_pnt)			
        {
            if(swrd_pnt == end_pnt)			/* reach the end			  */				
            {
                swrd_pnt = start_pnt;		
            }
            else
            {
                ++swrd_pnt;					/* pass the sword			  */
            }
        }

        if (swrd_pnt != end_pnt)
        {
            dead_pnt = swrd_pnt + 1;		/* kill the next one		  */
        }
        else
        {
            dead_pnt = start_pnt;
        }

        while (*dead_pnt)					
        {
            if(dead_pnt == end_pnt)
            {
                dead_pnt = start_pnt;
            }
            else
            {
                ++dead_pnt;					/* the next to kill 	      */
            }
        }
    }

    res = ((size_t)(swrd_pnt - start_pnt)) + 1;

    free(start_pnt);
    start_pnt = NULL;

    return (res);
}

/*****************************************************************************/
/* print the evironment variables  	*/
void EnvPrint() 
{
	extern char **environ;					/* calling an external var */
	
	char **buffer = NULL;
	size_t len_env = LenPtrToPtr(environ);  /* len of environ */
	
	buffer = (char **)malloc(len_env * sizeof(char *));
	if (NULL == buffer)
	{
		printf("Error, memory not allocated\n");
		exit (0);
	}
	
	CopyPtrToPtr(environ, buffer);
	PrintBuff(buffer);
	FreeBuff(buffer);	
		
	free(buffer);
	buffer = NULL;
}
/*****************************************************************************/
/* finds the length of ptr to ptr */
static size_t LenPtrToPtr(char **environ)
{
	size_t len = 0;	
	
	assert(environ);
	while (NULL != *environ)		/* length of each string */
	{
		++environ;
		++len;
	}
		
	return (++len);
}

/*****************************************************************************/
/* turns upper case string to lower case */
static void ToLowerStr(char *str)
{
	assert(str);
	
	while ('\0' != *str)
	{
		if (('A' <= *str) && ('Z' >= *str))
		{
			*str += ('A' - 'a');			/* adding 32 to the letter */
		}
		++str;
	}
}
/*****************************************************************************/
/*copy **ptr1 to **ptr2 */
static void CopyPtrToPtr(char **environ, char **buffer)
{	
	assert(environ);
	assert(buffer);
	
	while (NULL != *environ)
	{	/* allocating each time with new string size	*/
		*buffer = (char *)malloc((strlen(*environ) + 1) * sizeof(char));
		if (NULL == buffer)			/* allocation check */
		{
			printf("Error, memory not allocated\n");
			exit (0);
		}

		strcpy(*buffer, *environ); 	/* copy the strings 		 */
		ToLowerStr(*buffer);		/* turn buffer to lower case */
		++environ;
		++buffer;
	}
	*buffer = NULL;					/* for the last environment var */
}
/*****************************************************************************/
/* print the environment variables */
static void PrintBuff(char **buffer)
{
	assert(buffer);
	
	while (NULL != *buffer)
	{
		printf("%s\n", *buffer);		/* prints the strings */
		++buffer;
	}
}
/*****************************************************************************/
/* free the allocated memory  */
static void FreeBuff(char **buffer)
{
	assert(buffer);
	
	while (NULL != *buffer)
	{
		free(*buffer);
		*buffer = NULL;
		++buffer;
	}
	free(*buffer);
	*buffer = NULL;
}
/*****************************************************************************/
