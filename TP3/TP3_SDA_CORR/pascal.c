#include <stdio.h>


void init_pascal(int* tri, int nbl)
{
	// les dux premiere lignes
	*tri++ = 1;
	*tri++ = 1;
	*tri++ = 1;
	
	// puis la formule T[i,j] = T[i-1,j-1] + T[i-1,j]
	
	int i,j;
	for(i=2;i<nbl;i++)
	{
		*tri++ = 1;
		for(j=1;j<i;j++)
		{
			*tri =*(tri-i) + *(tri-i-1);
			tri++;
		}
		*tri++ = 1;
	}
}


void print_pascal(int* tri, int nbl)
{
	int i,j;
	for(i=0;i<nbl;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%4d ",*tri++);			
		}
		puts("");
	}
}

#define N 12

int main(int argc, char **argv)
{
	int triangle[N*(N+1)/2];
	int *ptri = &(triangle[0]);

	init_pascal(ptri,N);
	print_pascal(ptri,N);

	return 0;
}

