/****************************************
 * ex_test.c				            *
 * Developer: Michael Sasonker		    *
 * Reviewer: Yonatan			        *
 * Status: approved  		  	    	*	
 ***************************************/

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* size_t*/
#include "ex.h"   		/* my own func */

int main()
{
	PrintDataTypes();
	printf("*************************************\n*************************************\n");
	printf("Josephus function result is: %lu\n", Josephus(50));
	printf("Josephus function result is: %lu\n", Josephus(300));
	printf("Josephus function result is: %lu\n", Josephus(1000));
	printf("*************************************\n*************************************\n");
	printf("The environment variables are:\n");
	EnvPrint();

	return (0);
}
/*****************************************************************************/


