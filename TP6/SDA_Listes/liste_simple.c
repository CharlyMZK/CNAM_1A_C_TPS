#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include "liste_simple.h"

Noeud* nouveau_noeud(int v)
{
	Noeud* n = malloc(sizeof(Noeud));
	n->val = v;
	n->next = NULL;
	return n;
}

Liste* liste_vide()
{
	Liste* l = malloc(sizeof(Liste));
	l->nb = 0;
	l->first = NULL;
	return l;
}


void clear(Liste* l)
{
	while (l->nb != 0)
		pop_front(l);
	free(l);
}


Noeud* push_front(Liste* l, int v)
{
	Noeud* n = nouveau_noeud(v);
	
	n->next = l->first;
	l->first = n;
	l->nb++;
	return n;
}

void pop_front(Liste* l)
{
	if (l->first == NULL)
		return;
	
	Noeud* f = l->first;
	l->first = f->next;
	l->nb--;
	free(f);
}

int front_val(Liste* l)
{
	assert(l->first != NULL);
	
	return l->first->val;
}

void print(Liste* l)
{
	Noeud* n = l->first;
	while (n!=NULL)
	{
		printf("%d / ",n->val);
		n = n->next;
	}
	puts("");
}

int est_vide(Liste* l)
{
	return l->first == NULL;
}



Noeud* trouve_premier(Liste* l, int v)
{
	Noeud* no = l->first;
	while (no!=NULL)
	{
		if (no->val == v)
			return no;
		no = no->next;
	}
	return NULL;
}


int occurence(Liste* l, int v)
{
	int nb=0;
	Noeud* no = l->first;
	while (no!=NULL)
	{
		if (no->val == v)
			nb++;
		no = no->next;
	}
	return nb;
}


Noeud* push_back(Liste* l, int v)
{
	Noeud* n = nouveau_noeud(v);
	
	if ( l->first == NULL)
	{
		l->first = n;
		n->next = NULL;
		l->nb = 1;
	}
	else
	{
		Noeud* no = l->first;
		while (no->next != NULL)
			no = no->next;
		no->next = n;
		n->next = NULL;
		l->nb++;
	}
	return n;
}


int back_val(Liste* l)
{
	assert(l->first != NULL);
	
	Noeud* no = l->first;
	while (no->next!=NULL)
	{
		no = no->next;
	}
	return no->val;
}


void pop_back(Liste* l)
{
	// cas liste vide
	if ( l->first == NULL)
		return;	

	// cas liste de taille 1
	if (l->first->next == NULL)
	{
		free(l->first);
		l->first = NULL;
		l-> nb = 0;
		return;
	}
	
	Noeud* no = l->first;
	while (no->next->next!=NULL)
	{
		no = no->next;
	}
	free(no->next);
	no->next = NULL;
	l->nb--;
}


Noeud* insert_after(Liste*l, Noeud* c, int v)
{
	Noeud* n = nouveau_noeud(v);
	n->next = c->next;
	c->next = n;

	l->nb++;
	 
	return n;
}


void retire(Liste* l, Noeud* n)
{
	if (l->first==NULL)
		return;
		
	if (l->first == n)
	{
		l->first = n->next;
		free(n);
		l->nb--;
		return;
	}
	
	Noeud* no = l->first;
	while (no->next!=NULL)
	{
		if (no->next == n)
		{
			no->next = n->next;
			free(n);
			l->nb--;
			return;
		}
		no = no->next;
	}
}

void apply(Liste* l, void (*fonct)(int*))
{
	Noeud* n = l->first;
	while (n!=NULL)
	{
		fonct(&(n->val));
		n = n->next;
	}
}

