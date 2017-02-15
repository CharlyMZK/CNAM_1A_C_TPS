#include <stdio.h>
#include <stdlib.h>


#define BOOL int
#define TRUE 1
#define FALSE 0


void chiffres_iter(int x)
{
	while (x>0)
	{
		printf("%d / ",x%10);
		x /= 10;
	}
}


	
void chiffres(int x)
{
	if (x<9)
		printf("%d",x);
	else
	{
		chiffres(x/10);
		printf(" / %d",x%10);
	}
}

void chiffres_inv(int x)
{
	if (x<9)
		printf("%d",x);
	else
	{
		printf("%d / ",x%10);
		chiffres_inv(x/10);
	}
}


int main(int argc, char **argv)
{
	chiffres_iter(123456789);
	puts("");

	chiffres(123456789);
	puts("");
	
	chiffres_inv(123456789);	
	puts("");
		
	return 0;
}

