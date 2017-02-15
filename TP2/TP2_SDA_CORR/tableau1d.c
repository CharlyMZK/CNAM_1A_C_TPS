#include <stdio.h>
#define bool int
#define TRUE 1
#define FALSE 0

//typedef int INT;
#define INT int

void print(INT array[], int size)
{
	printf("[ ");
	int i;
	for (i=0;i<size;i++)
		printf("%d ",array[i]);
	printf("]\n");
}

void read(INT array[], int size)
{
	int i;
	for (i=0;i<size;i++)
		scanf("%d",&(array[i]));
}

INT valeur_max(INT array[], int size)
{
	INT val_max = array[0];
	int i;
	for (i=1;i<size;i++)
	{
		if (array[i] > val_max)
			val_max = array[i];
	}
	return val_max;
}

void swap_elt(INT array[], int size, int i, int j)
{
	if ((i>=size) || (j>=size))
	{
		printf("parametres i & j doivent etre inferieurs a size");
		return;
	}
	INT tempo = array[j];
	array[j] = array[i];
	array[i] = tempo;
}

int occurrences(INT array[], int size, INT el)
{
	int nb_occ = 0;
	int i;
	for (i=0;i<size;i++)
	{
		if (array[i] == el)
			nb_occ++;
	}
	return nb_occ;
	
}

void reverse(INT array[], int size)
{
	int i = 0;
	int j = size-1;
	while (i<j)
	{
		swap_elt(array, size, i, j)	;
		i++;
		j--;
	}
}

void rotate_right(INT array[], int size)
{
	INT last = array[size-1];
	int i;
	for (i=size-1;i>=1;i--)
	{
		array[i] = array[i-1];
	}
	array[0] = last;
}

void rotate_left(INT array[], int size)
{
	INT first = array[0];
	int i;
	for (i=0;i<size-1;i++)
	{
		array[i] = array[i+1];
	}
	array[size-1] = first;
}

bool is_palindrome(INT array[], int size)
{
	int i = 0;
	int j = size-1;
	while (i<j)
	{
		if (array[i] != array[j])
			return FALSE;
		i++;
		j--;
	}
	return TRUE;
}


int find_first(INT array[], int size, INT el)
{
	int i=0;
	while (i<size)
	{
		if (el == array[i])
			return i;
		i++;
	}
	return size; // par convention si on ne trouve pas on renvoit size
}

int find_last(INT array[], int size, INT el)
{
	int i=size-1;
	while (i>=0)
	{
		if (el == array[i])
			return i;
		i--;
	}
	return size;
}


int main()
{
	#define NB 8
	
	int TA[NB] = {1,2,3,4,4,3,2,1};
	int TB[NB] = {1,2,3,4,5,6,7,8};
	int TC[NB];
	
	printf("A = ");
	print(TA,NB);
	printf("B = ");
	print(TB,NB);
	printf("Entrer C: ");
	read(TC,NB);
	printf("C = ");
	print(TC,NB);

	
	puts("Rotation de TB a droite");
	int i;
	for (i=0;i<8;i++)
	{
		rotate_right(TB,NB);
		print(TB,NB);
	}
	puts("Rotation de TB a gauche");
	for (i=0;i<8;i++)
	{
		rotate_left(TB,NB);
		print(TB,NB);
	}
	
	puts("Renverse TB");
	reverse(TB,NB);
	print(TB,NB);
	
	printf ("Occurence de 3 dans TA : %d \n",occurrences(TA,NB,3));
	printf ("Premier 3 dans TA index: %d \n",find_first(TA,NB,3));
	printf ("Dernier 3 dans TA index: %d \n",find_last(TA,NB,3));

	
	if (is_palindrome(TA,NB))
		puts("TA est un palindrome");
	else
		puts("TA n'est pas un palindrome");

	if (is_palindrome(TB,NB))
		puts("TB est un palindrome");
	else
		puts("TB n'est pas un palindrome");
	
	return 0;
}
