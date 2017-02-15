#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include "liste_tableau.h"

Liste* liste_vide()
{
	Liste* l = malloc(sizeof(Liste));
	l->nb = 0;
	l->data = malloc(1000000*sizeof(Noeud));
	return l;
}


void clear(Liste* l)
{
	free(l->data);
	free(l);
}


Noeud* push_back(Liste* l, int v)
{
	l->data[l->nb].val = v;
	l->nb++;
	return l->data+l->nb-1;
}

void pop_back(Liste* l)
{
	if (l->nb == 0)
		return;
	l->nb--;
}

int back_val(Liste* l)
{
	return l->data[l->nb-1].val;
}



Noeud* push_front(Liste* l, int v)
{
	int i;
	for (i=l->nb-1; i>=0; i--)
		l->data[i+1] = l->data[i];

	l->data[0].val = v;
	l->nb++;
	return l->data;
}

void pop_front(Liste* l)
{
	if (l->nb == 0)
		return;

	int i;
	for (i=1;i<l->nb;i++)
		l->data[i-1] = l->data[i];

	l->nb--;
}


int front_val(Liste* l)
{
	return l->data[0].val;
}

void print(Liste* l)
{
	int i;
	for(i=0;i<l->nb;++i)
		printf("%d / ",l->data[i].val);
	puts("");
}

int est_vide(Liste* l)
{
	return l->nb == 0;
}



Noeud* trouve_premier(Liste* l, int v)
{
	int i;
	for(i=0;i<l->nb;++i)
	{
		if (l->data[i].val == v)
			return l->data+i;
	}
	return NULL;
}

int occurence(Liste* l, int v)
{
	int nb=0;
	
	int i;
	for(i=0;i<l->nb;++i)
	{
		if (l->data[i].val == v)
			nb++;
	}
	return nb;
}


Noeud* insert_after(Liste* l, Noeud* c, int v)
{
	int k = (int)(c-l->data) + 1;

	int i;
	for (i=l->nb-1; i>=k; i--)
		l->data[i+1] = l->data[i];
	
	l->data[k].val = k;
	
	l->nb++;
	
	return l->data+k;
}


void retire(Liste* l, Noeud* n)
{
	int k = (int)(n - l->data);

	int i;
	for (i=k+1; i<l->nb; i++)
		l->data[i-1] = l->data[i];
		
	l->nb--;
}

void apply(Liste* l, void (*fonct)(int*))
{
	int i;
	for (i=0; i<l->nb; i++)
		fonct(&(l->data[i].val));
}

