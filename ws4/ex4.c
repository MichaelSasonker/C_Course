/****************************************
 * ex4.c                     	        *
 * Developer: Michael Sasonker          *
 * Reviewer: David Elkayam 		        *
 * Status:  approved                    * 	  
 ***************************************/

#include <stdio.h> /* printf */
#include <stdlib.h> /* system */

#define ESC 27
#define NUM_OF_FUNC 256

static void PutsNothing(void (*func_arr[NUM_OF_FUNC])());
static void PrintT(); 
static void PrintA(); 
static void EmptyFunc(); 

/*****************************************************************************/
/* prints messages when 'a'/'A' or 't'/'T' keys are pressed, press ESC to stop*/
void IfAT()
{
	char key = 0;

	system ("stty -icanon -echo");  	/* Disabling bash keyboard       */
	
	while (ESC != key)					/* if the user press ESC stop looping */
	{
		scanf("%c", &key);				/* getting a key from the user     */ 
				
		if ('A' == key || 'a' == key)	/* if the user press 'a'/'A'	 */	
		{
			PrintA();
		}
		
		if ('T' == key || 't' == key)	/* if the user press 't'/'T'	 */
		{
			PrintT();
		}
	}
	
    system ("stty icanon echo");		/* enable bash keyboard  		 */
}

/******************************************************************************/
/* prints messages when 'a'/'A' or 't'/'T' keys are pressed, press ESC to stop*/
void SwitchAT()
{
	char key = 0;
	
	system("stty -icanon -echo"); 		/* Disable bash keyboard */
		
	while (ESC != key)					/* if the user press ESC stop looping*/
	{
		scanf("%c", &key);				/* getting a key from the user     */ 
				
		switch (key)
		{
			case 'A':
			case 'a':					/* if the user pressed 'A'/'a' */
			PrintA();					
			break;
			
			case 'T':					/* if the user pressed 'T'/'t' */
			case 't':
			PrintT();
			break;
		}
	}
	
	system ("stty icanon echo");		/* enable bash keyboard */
}


/*****************************************************************************/
/* look-up-table that prints only when the user press 'a'/'A'/'t'/'T' */
void LutAT()
{
	char key = 0;
	
	void (*func_arr[NUM_OF_FUNC])(void);
	system ("stty -icanon -echo");		/* Disable bash keyboard */
	
	PutsNothing(func_arr);				/* puts nothing in func_arr */
	
	func_arr['T'] =  PrintT;			/* if the user pressed 'T'/'t' */
	func_arr['t'] =  PrintT;			
	
	func_arr['A'] =  PrintA;			/* if the user pressed 'A'/'a' */
	func_arr['a'] =  PrintA;
	
	while (ESC != key)
	{
		scanf ("%c", &key);
		func_arr[(int)key]();
	}
	
	system ("stty icanon echo");		/* enable bash keyboard */
}
/*****************************************************************************/
static void PutsNothing(void (*func_arr[])())
{
	size_t i = 0;
	
	while (i < NUM_OF_FUNC)
	{
		func_arr[i] =  &EmptyFunc;
		++i;
	}
}
/*****************************************************************************/
/* function that do nothing but return   */
static void EmptyFunc()  
{

}

/*****************************************************************************/	
/* prints T is pressed */
static void PrintT()
{
	printf ("T is pressed\n");
}

/*****************************************************************************/
/* prints A is pressed */
static void PrintA() 
{
	printf("A is pressed\n");
}




