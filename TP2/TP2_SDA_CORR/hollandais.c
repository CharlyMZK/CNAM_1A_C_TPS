#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print( char array[], int size )
{
	printf("[ ");
	int i;
	for(i=0;i<size;++i)
	{
		printf("%c",array[i]);
	}
	printf("]\n");
}

void swap_color(char array[], int i, int j )
{
	char c = array[j];
	array[j]=array[i];
	array[i]=c;
}

void aleatoires(char array[], int size)
{
	// initialize la graine avec un nombre different a chaque run 
	srand(time(NULL));
	
	int i;
	for(i=0;i<size;++i)
	{
		int v = rand();
		switch(v%3)
		{
			case 0: array[i] = 'R';
					break;
			case 1: array[i] = 'W';
					break;
			case 2: array[i] = 'B';
					break;
			default:
					break;
		}
	}
}

void hollandais(char drap[], int size)
{
	int b=0;
	int w=0;
	int r=size-1;
	
	while( w<=r)
	{
		if (drap[w] == 'W')
			w++;
		else if (drap[w] == 'B')
		{
			swap_color(drap,w,b);
			w++;
			b++;
		}
		else
		{
			swap_color(drap,w,r);
			r--;
		}
		print(drap,size);
	}
}

int main()
{	
	// surtout pas de ; a la fin de la macro !
	#define NB 20
	
	char drapeau[NB];
	
	aleatoires(drapeau,NB);
	hollandais(drapeau,NB);
	return 0;
}
