#include <stdio.h>

#ifdef DOUBLE 
#include "liste_double.h"
#endif

#ifdef SIMPLE
#include "liste_simple.h"
#endif

#ifdef TABLEAU
#include "liste_tableau.h"
#endif


#define NB 50000

int main(int argc, char **argv)
{
	Liste* l = liste_vide();
	
	int i;
	for(i=0;i<NB;i++)
		push_front(l,i);
	printf("push_front %d \n",l->nb);
	for(i=0;i<NB;i++)
		pop_back(l);
	printf("pop_back %d \n",l->nb);
	for(i=0;i<NB;i++)
		push_back(l,i);
	printf("push_back %d \n",l->nb);
	for(i=0;i<NB;i++)
		pop_front(l);
	printf("pop_front %d \n",l->nb);
		
	return 0;
}
