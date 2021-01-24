/****************************************
 * ex4_test.c                           *
 * Developer: Michael Sasonker          *
 * Reviewer: David Elkayam 		        *
 * Status:  approved               	    * 	  
 ***************************************/

#include <stdio.h> 	/* printf */
#include "ex4.h" /* my own func */

int main ()
{
	printf("testing IfAT func:\n");
	IfAT();
	printf("IfAT is finished\n");
	
	printf("testing SwitchAT func:\n");
	SwitchAT();
	printf("SwitchAT is finished\n");
	
	printf("testing LutAT func:\n");
	LutAT();
	printf("LutAT is finished\n");
	
	return (0);
}


