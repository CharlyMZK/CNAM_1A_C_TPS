#include <stdio.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

//typedef int INT;
#define INT int


void print2(INT array[][3], int nbl)
{
	int j;
	for (j=0;j<nbl;j++)
	{
		printf("[ ");
		int i;
		for (i=0;i<3;i++)
			printf("%d ",array[j][i]);
		printf("]\n");
	}
}

void read2(INT array[][3], int nbl)
{
	int j;
	for (j=0;j<nbl;j++)
	{
		printf("Entrer ligne %d :",j);
		int i;
		for (i=0;i<3;i++)
			scanf("%d",&(array[j][i]));
	}
}

INT valeur_max2(INT array[][3], int nbl)
{
	INT val_max = array[0][0];
	
	int j;
	for (j=0;j<nbl;j++)
	{
		int i;
		for (i=0;i<3;i++)
		{
			if (array[j][i] > val_max)
				val_max = array[j][i];
		}
	}

	return val_max;
}

int occurrences2(INT array[][3], int nbl, INT el)
{
	int nb_occ=0;
	
	int j;
	for (j=0;j<nbl;j++)
	{
		int i;
		for (i=0;i<3;i++)
		{
			if (array[j][i] == el)
				nb_occ++;
		}
	}
	return nb_occ;
}


BOOL is_sudoku(INT array[3][3])
{
	//init occurences
	int occur[9];
	int k;
	for (k=0;k<9;k++)
		occur[k]=0;
	
	int j;
	for (j=0;j<3;j++)
	{
		int i;
		for (i=0;i<3;i++)
		{
			INT v = array[j][i];
			// si chiffre case i,j pas dans [1-9] alors faux
			if ((v<1) || (v>9))
				return FALSE;
			// si chiffre case i,j déjà utilisé alors faux
			if (occur[v-1]!=0)
				return FALSE;
			occur[v-1]++;
		}
	}
	return TRUE;
}	

int main()
{
	INT t[3][3];
	
	read2(t,3);
	puts("");
	print2(t,3);
	if (is_sudoku(t))
		puts("sudoku");
	else
		puts("pas sudoku");
		
	printf("Max = %d\n",valeur_max2(t,3));
	
	return 0;
}

