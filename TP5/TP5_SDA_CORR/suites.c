#include <stdio.h>
#include <stdlib.h>


#define BOOL int
#define TRUE 1
#define FALSE 0

int suite_calc(int n)
{
	if (n > 0)
		return 2*suite_calc(n-1)-1;
	else
		return 5;
}

// u: U0, n nb calculs, m copie de n initial qui ne varie pas
void suite_aff(int u, int n, int m)
{
	printf (" U[%d] = %d\n",m-n,u);
	if (n > 0)
		suite_aff(2*u-1,n-1,m);
//  si on met le printf après l'appel, on inverse l'affichage	
//	printf (" U[%d] = %d\n",m-n,u);
}

void syracuse(int x)
{
	printf ("%d \n", x);
	if ( x > 1)
	{
		if (x%2 == 0)
			syracuse(x/2);
		else
			syracuse(3*x+1);
	}
}


int main(int argc, char **argv)
{
	int r = suite_calc(7);
	printf("U7 = %d\n",r);
	puts("=================");
	suite_aff(5,7,7);
	puts("=================");
	puts("syracuse");
	syracuse(7);

	return 0;
}

