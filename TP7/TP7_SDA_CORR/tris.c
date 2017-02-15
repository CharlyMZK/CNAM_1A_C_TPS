#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/// fonctions utilitaires

void print( int* array, int size )
{
	printf("[ ");
	int i;
	for(i=0;i<size;++i)
		printf("%2d ",array[i]);
	printf("]\n");
}

void swap_elt(int* array, int i, int j )
{
	int c = array[j];
	array[j]=array[i];
	array[i]=c;
}

void copie(int dst[], int src[], int size)
{
	int i;
	for(i=0;i<size;++i)
		dst[i] = src[i];
}


/// fonctions d'initialisation

void aleatoires(int* array, int size)
{
	// initialize la graine avec un nombre different a chaque run 
	srand(time(NULL));
	int i;
	for(i=0;i<size;++i)
		array[i] = rand()%100;
}

void decroissant(int* array, int size)
{
	int i;
	for(i=0;i<size;++i)
		array[i] = size-i;
}


/// TRIS

void selection_sort(int* array, int size)
{
	int i,j;
	for (i=0;i<size-1;i++)
	{
		// cherche le min dans [i,fin]
		int min_index = i;
		for (j=i+1;j<size;j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		// le met en i
		swap_elt(array, min_index,i); 
	}
}


void insertion_sort(int* array, int size)
{
	int i,j;
	for (i=1;i<size;i++)
	{
		int current = array[i];
		// cherche la place de l'elt i dans [0,i-1]
		j=i-1;
		while ((j>=0) && (array[j]>current))
		{
			array[j+1] = array[j]; // decale vers la droite
			j--;
		}
		// met l'elt i a sa place dans [0,i-1] -> [0,i] trié
		array[j+1] = current;
	}
}



void bubble_sort(int* array, int size)
{
	int swaps=1; // nb swaps a chaque tour, init à 1 pour commencer
	int i,j;
	for (j=size-1; (j>0)&&(swaps>0); j--)
	{
		swaps=0;
		for (i=1;i<=j;i++)
			if (array[i] < array[i-1])
			{
				swap_elt(array,i,i-1);
				swaps++;
			}
	}		
}

// sans l'optimisaion, on s'arrête si aucun swap
void shaker_sort(int* array, int size)
{
	int i,j,jj;
	
	j=0;
	jj=size-1;
	while (j<jj)
	{
		int swaps=0;
		// on fait descendre les + petits
		for (i=j+1;i<=jj;i++)
		{
			if (array[i-1] > array[i])
			{
				swap_elt(array,i-1,i);
				swaps++;
			}
		}
		if (swaps==0)
			return;
		// on fait remonter les + grands
		for (i=jj-1;i>=j;i--)
		{
			if (array[i+1] < array[i])
			{
				swap_elt(array,i+1,i);
				swaps++;
			}
		}
		if (swaps==0)
			return;

		j++;
		jj--;
	}
}



// partitionne l'intervalle [deb,fin]
// pivot: index du pivot
//  les valeurs <= val_pivot / val_pivot / les valeurs >= val_pivot
int partition(int* array, int deb, int fin, int pivot)
{
	// si 2 valeurs on les mets dans l'ordre.
	if ((fin-deb)<2)
	{
		if (array[fin] < array[deb])
			swap_elt(array,deb,fin);
		return fin; 	// et on sort
	}
	
	// met le pivot en à la fin
	swap_elt(array,pivot,fin);
	
	int val_pivot = array[fin];

	int j=deb; // prichain index des elt avant pivot
	// parcours de l'intervalle
	int i;
	for (i=deb;i<fin;i++)
	{
		if (array[i] <= val_pivot) // place les elts<pivots
		{
			swap_elt(array,i,j);   // en premier
			j++;
		}
	}
	//remet le pivot a sa place
	swap_elt(array,fin,j);
	
	return j;
}




void quick_sort(int* array, int deb, int fin)
{
	if (deb  < fin)
	{
		int pivot = (deb+fin)/2; // choix pivot: au milieu
		int p = partition(array,deb,fin,pivot); // partitionne
		quick_sort(array,deb,p-1); // appels recursif avant pivot
		quick_sort(array,p+1,fin); // appels recursif apres pivot
	}
}

// buffer temporaire
int* tempo;

// fusionne 2 sous-parties triées d'un tableau -> 1 sous-partie triée
void fusion2parts(int* array, int deb, int mil, int fin)
{
	int i = deb;	// index debut sous-partie 1
	int j = mil+1;	// index debut sous-partie 2
	int k = deb;	// index debut  buffer
	
	// TQ i & j pas la fin
	while ((i<=mil) && (j<=fin))
	{
		//mettre le + petit dans le buffer et avancer
		if (array[i]<array[j])	
			tempo[k++] = array[i++];
		else
			tempo[k++] = array[j++];
	}
	
	// ajouter le reste de la sous-partie 1
	while (i<=mil)
		tempo[k++] = array[i++];

	// ajouter le reste de la sous-partie 2
	while (j<=fin)
		tempo[k++] = array[j++];

	// recopie du buffer dans le tableau
	for(k=deb;k<=fin;k++)
		array[k] = tempo[k];
}

void fusion2parts_v2(int* array, int deb, int mil, int fin)
{

	int i = deb;	// index debut sous-partie 1
	int j = mil+1;	// index debut sous-partie 2
	int k = deb;	// index debut  buffer
	
	for (k = deb; k <= fin; k++)
	{
		if (i <= mil && (j > fin || array[i] <= array[j]))
		{
			tempo[k] = array[i];
			i = i + 1;
		}
		else
        {
			tempo[k] = array[j];
			j = j + 1;    
		}
	}
	
	// recopie du buffer dans le tableau
	for(k=deb;k<=fin;k++)
		array[k] = tempo[k];
}


void fusion_sort(int* array, int deb, int fin)
{
	if (fin-deb  > 1)
	{
		int mil = (deb+fin)/2;          // coupe le tableau en 2 parties
		fusion_sort(array,deb,mil);     // tri partie 1
		fusion_sort(array,mil+1,fin);   // tri partie 2
		fusion2parts(array,deb,mil,fin);// fusionne en gardant trié
	}
	else if (fin-deb == 1)				// si 2 elements seulement
	{
		if (array[fin] < array[deb])	// tri facile
			swap_elt(array,deb,fin);
	}
}





int main(int argc, char **argv)
{
	int NB = 20;

	int* table = malloc(NB*sizeof(int));
	int* tabl2 = malloc(NB*sizeof(int));
	tempo = malloc(NB*sizeof(int));


	aleatoires(table,NB);
//	decroissant(table,NB);
	
	print(table,NB);
	
	puts("selection_sort");
	copie(tabl2,table,NB);
	selection_sort(tabl2,NB);
	print(tabl2,NB);
	
	puts("insertion_sort");
	copie(tabl2,table,NB);
	insertion_sort(tabl2,NB);
	print(tabl2,NB);
	
	puts("bubble_sort");
	copie(tabl2,table,NB);
	bubble_sort(tabl2,NB);
	print(tabl2,NB);
	
	puts("shaker_sort");
	copie(tabl2,table,NB);
	shaker_sort(tabl2,NB);
	print(tabl2,NB);
	
	puts("quick_sort");
	copie(tabl2,table,NB);
	quick_sort(tabl2,0,NB-1);
	print(tabl2,NB);
	
	puts("fusion_sort");
	copie(tabl2,table,NB);
	fusion_sort(tabl2,0,NB-1);
	print(tabl2,NB);
	
	free(tempo);
	free(tabl2);
	free(table);
	
	
	return 0;
}

