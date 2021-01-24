#include <stdio.h> /* printf */

int SameName ();

static int x1 = 3;
static int x2 = 0;
static int x3;
int x4 = 10;
int x5 = 0;
int x6;
	
int main()
{
/*	x1 = 3;
	x2 = 0;
	x3 = x1;
	x4 = 10;
	x5 = 0;
	x6 = x5;*/
	
	printf ("%d%d%d%d%d%d", x1, x2, x3, x4, x5, x6);
	return (0);
}

int SameName ()
{
	
	return (0);
}
