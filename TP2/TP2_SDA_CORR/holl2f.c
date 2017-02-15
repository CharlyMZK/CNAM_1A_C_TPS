#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print( float array[], int size )
{
	printf("[ ");
	int i;
	for(i=0;i<size;++i)
	{
		printf("%.3f ",array[i]);
	}
	printf("]\n");
}

void swap_elt(float array[], int i, int j )
{
	float c = array[j];
	array[j]=array[i];
	array[i]=c;
}

void aleatoires(float array[], int size)
{
	// initialize la graine avec un nombre different a chaque run 
	srand(time(NULL));
	
	int i;
	for(i=0;i<size;++i)
	{
		float r = (float)(rand())/RAND_MAX;
		array[i] = 2.0*r - 1.0;
	}
}

void hollandais2f(float drap[], int size)
{
	int i=0;
	int j=size-1;
	
	while( i<=j)
	{
		if (drap[i] > 0.0)
		{
			if (drap[j] < 0.0)
			{
				swap_elt(drap,i,j);
				i++;
			}
			j--;
		}
		else
			i++;
		print(drap,size);
	}
}

int main()
{	
	// surtout pas de ; a la fin de la macro !
	#define NB 20
	
	float tableau[NB];
	
	aleatoires(tableau,NB);
	hollandais2f(tableau,NB);
	return 0;
}


