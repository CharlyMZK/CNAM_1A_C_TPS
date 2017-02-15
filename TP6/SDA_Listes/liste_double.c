#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include "liste_double.h"


Noeud* nouveau_noeud(int v)
{
	Noeud* n = malloc(sizeof(Noeud));
	n->val = v;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

Liste* liste_vide()
{
	Liste* l = malloc(sizeof(Liste));
	l->nb = 0;
	l->first = NULL;
	l->last = NULL;
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

	if (l->first == NULL)
	{
		l->first = n;
		l->last = n;
	}
	else
	{
		n->next = l->first;
		n->next->prev = n;
		l->first = n;
	}
	l->nb++;
	return n;
}

void pop_front(Liste* l)
{
	Noeud* f = l->first;
	
	if (f == NULL)
		return;
	
	if (f == l->last) //(or nb==1)
	{
		l->first = NULL;
		l->last = NULL;
	}
	else
	{
		l->first = f->next;
		f->next->prev = NULL;
	}
	l->nb--;
	free(f);
}

int front_val(Liste* l)
{
	assert(l->first != NULL);
	return l->first->val;
}


Noeud* push_back(Liste* l, int v)
{
	Noeud* n = nouveau_noeud(v);
	
	if (l->last == NULL)
	{
		l->last = n;
		l->first = n;
		l->nb = 1;
		return n;
	}
	
	n->prev = l->last;
	l->last->next = n;
	l->last = n;
	l->nb++;
		
	return n;
}

void pop_back(Liste* l)
{
	Noeud* la = l->last;

	if (la == NULL)
		return;

	if (la == l->first) //(or nb==1)
	{
		l->first = NULL;
		l->last = NULL;
	}
	else
	{	
		l->last = la->prev;
		la->prev->next = NULL;
	}
	l->nb--;
	free(la);
}

int back_val(Liste* l)
{
	assert(l->last != NULL);
	return l->last->val;
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

Noeud* trouve_dernier(Liste* l, int v)
{
	Noeud* no = l->last;
	while (no!=NULL)
	{
		if (no->val == v)
			return no;
		no = no->prev;
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


Noeud* insert_after(Liste*l, Noeud* c, int v)
{
	Noeud* n = nouveau_noeud(v);
	n->next = c->next;
	c->next = n;
	n->prev = c;
	
	if (c == l->last)
		l->last = n;
	else
		n->next->prev = n;
	
	l->nb--;
	 
	return n;
}


void retire(Liste* l, Noeud* n)
{
	if (l->first==NULL)
		return;
	if (n == l->first)
		pop_front(l);
	else if (n == l->last)
		pop_back(l);
	else
	{
		n->next->prev = n->prev;
		n->prev->next = n->next;
		free(n);
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

