#include <stdio.h>


void init(int* array, int s1, int s2, int s3)
{
	int nb = s1*s2*s3;
	
	while (nb>0)
	{
		*array++ = 0;
		nb--;
	}
}

int get(int* array, int s1, int s2, int s3, int i, int j, int k)
{
	// TODO check que l'on est al'interieur du tableau
	int index = i*s2*s3 + j*s3 + k;
	return array[index];
}


void set(int* array, int s1, int s2, int s3, int i, int j, int k, int v)
{
	// TODO check que l'on est al'interieur du tableau
	int index = i*s2*s3 + j*s3 + k;
	array[index]=v;
}


int main(int argc, char **argv)
{
	int table[3][4][5];
	
	int *ptable = &(table[0][0][0]);
	
	init(ptable,3,4,5);
	
	table[1][1][1] = 23;
	
	set(ptable,3,4,5,2,2,2,43);
	
	printf("%d == %d ?\n",table[1][1][1], get(ptable,3,4,5,1,1,1));
	printf("%d == %d ?\n",table[2][2][2], get(ptable,3,4,5,2,2,2));
		
	return 0;
}

