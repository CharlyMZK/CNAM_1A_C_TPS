#include <stdio.h>
#include "liste_simple.h"


void foisdeux(int* v)
{
	*v =  *v * 2;
}

int main(int argc, char **argv)
{
	Liste* l = liste_vide();
	
	print(l);
	
	int i;
	for(i=0;i<10;i++)
	{
		push_front(l,i);
		print(l);
	}
	for(i=0;i<11;i++)
	{
		pop_front(l);
		print(l);
	}
	
	puts("===============================");

	for(i=0;i<10;i++)
	{
		push_back(l,i);
		print(l);
	}
	for(i=0;i<11;i++)
	{
		pop_back(l);
		print(l);
	}
	
	puts("===============================");
	
	Noeud* n1 = push_front(l,4);
	print(l);
	push_front(l,2);
	push_back(l,6);
	print(l);
	
	retire(l,n1);
	print(l);
	
	puts("===============================");
	
	push_back(l,9);
	push_front(l,1);
	print(l);
	
	Noeud* n2 = trouve_premier(l,6);
	retire(l,n2);
	print(l);

	puts("===============================");
	
	push_front(l,9);
	print(l);
	printf("Occurences de 9: %d\n",occurence(l,9));
	
	Noeud* n3 = trouve_premier(l,1);
	insert_after(l,n3,4);
	print(l);
	
	puts("===============================");
	
	apply(l,foisdeux);
	print(l);
	
	clear(l);
	
	return 0;
}

