#include <stdio.h>
#include <stdlib.h>

// compteur nb additions.
int nb_add=0;

/** 
* Fibonacci avec affichage de la pile d'appel
*/
int fibo_rec(int n, char* pile)
{
	char localPile[1024];
	sprintf(localPile,"%s / %d ",pile,n);
	printf("Fibo(%d): %s \n",n,localPile);
	if (n==0) return 0;
	if (n==1) return 1;
	nb_add++;
	return fibo_rec(n-1, localPile) + fibo_rec(n-2,localPile);	
}

/**
 * Fibonacci iteratif
 */
int fibo_iter(int n)
{
	nb_add =0;
	int f1=0;
	int f2=1;
	int i;
	for (i=1;i<n;i++)
	{
		nb_add++;
		int tempo = f1+f2; 
		f1 = f2;
		f2 = tempo;
	}
	return f2;
}	

int main()
{
	char *pileVide="Pile:";
	int f = fibo_rec(7,pileVide);
	printf("Fibo rec= %d\n", f);
	
	printf("NB_ADD = %d\n", nb_add);
	
	f = fibo_iter(7);
	printf("Fibo iter = %d\n", f);

	printf("NB_ADD = %d\n", nb_add);
	return 0;
}

