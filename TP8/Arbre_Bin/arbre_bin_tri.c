
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arbre_bin_tri.h"


int hauteur(Arbre* a)
{
	if (est_vide(a))
		return 0;
	return 1+ MAX(hauteur(fils_gauche(a)),hauteur(fils_droit(a)));
}

int taille(Arbre* a)
{
	if (est_vide(a))
		return 0;
	return 1+ taille(fils_gauche(a)) + taille(fils_droit(a));
}


Arbre* creer_feuille(T v)
{
	Arbre* a =malloc(sizeof(Arbre));
	a->label = v;
	a->fg = NULL;
	a->fd = NULL;
	return a;
}

Arbre* fils_gauche(Arbre* a)
{
	return a->fg;
}


Arbre* fils_droit(Arbre* a)
{
	return a->fd;
}


T racine(Arbre* a)
{
	return a->label;
}


int est_vide(Arbre* a)
{
	return a == NULL;
}


int est_feuille(Arbre* a)
{
	return (a->fg==NULL)&&(a->fd==NULL);
}


Arbre* inserer_rec(Arbre* a, T v)
{
	// si l' arbre est vide il devient une feuille
	if (est_vide(a))
		return creer_feuille(v); 

	// si v est deja dans l'arbre on ne fait rien
	if (v == racine(a))
		return a;

	// on insere a droite ou a gauche
	if (v > racine(a))
			a->fd = inserer_rec(a->fd,v);
	else 
		a->fg = inserer_rec(a->fg,v);

	// on retourne l'arbre
	return a;
}

T plusPetitElt_rec(Arbre* a)
{
	if ( est_feuille(a) || est_vide(fils_gauche(a)) )
		return racine(a);
	return plusPetitElt_rec(fils_gauche(a));
}

T plusGrandElt_rec(Arbre* a)
{
	if ( est_feuille(a) || est_vide(fils_droit(a)) )
		return racine(a);
	return plusGrandElt_rec(fils_droit(a));
}

int recherche_rec(T elt, Arbre* a)
{
	if (est_vide(a))
		return 0;

	if (elt == racine(a))
		return 1;

	if (elt < racine(a))
		return recherche_rec(elt,fils_gauche(a));
	else
		return recherche_rec(elt,fils_droit(a));
}



void rec_save_dot(Arbre* a, FILE* f)
{
	Arbre *g = fils_gauche(a); 
	if (!est_vide(g))
	{
		fprintf(f,"%d -> %d \n",racine(a),racine(g));
		rec_save_dot(g,f);
	}
	Arbre *d = fils_droit(a); 
	if (!est_vide(d))
	{
		fprintf(f,"%d -> %d \n",racine(a),racine(d));
		rec_save_dot(d,f);
	}
}


void save_dot(Arbre* a, char* nom)
{
	// buffer pour chaine de car
	char* buffer = malloc(512);

	// nom du fichier .dot
	sprintf(buffer,"%s.dot",nom);

	// ouvre le fichier
	FILE* f = fopen(buffer,"w");

	// ecrit dans le fichier
	if (!est_vide(a))
	{
		fprintf(f,"Digraph {\n");
		rec_save_dot(a,f);
		fprintf(f,"}\n");
	}
	fclose(f);

	// commande dans la chaine buffer
	sprintf(buffer, "dot -Tpdf -o %s.pdf %s.dot",nom,nom);

	//  execution de la commande
	system(buffer);

	// commande dans la chaine buffer
	sprintf(buffer, "evince %s.pdf",nom);

	//  execution de la commande
	system(buffer);


	free(buffer);
}


void clean(Arbre* a)
{
	if  (!est_vide(a))
	{
		clean(fils_gauche(a));
		clean(fils_droit(a));
		free(a);
	}
}


void generate(int nb)
{
	Arbre* a = NULL;

	for (int i=0;i<nb;i++)
	{
		int x = rand()%(10*nb);
		a = inserer_rec(a,x);
	}

	int t=taille(a);
	int h=hauteur(a);
	printf("NB = %d   H= %d  (ideal: %f)\n",t,h,log(t)/log(2));

	clean(a);
}


int main()
{
	srand(time(NULL));

 	Arbre* a = NULL;

	int xx=-1;

	for (int i=0;i<100;i++)
	{
		int x = rand()%1000;
		a = inserer_rec(a,x);
		if (i==50)
			xx = x;
	}

	printf("min: %d\n",plusPetitElt_rec(a));
	printf("max: %d\n",plusGrandElt_rec(a));
	printf("oui: %d\n",recherche_rec(xx,a));
	printf("non: %d\n",recherche_rec(-4,a));

	save_dot(a,"arbre_t");
	clean(a);

	 for (int i=1;i<5;i++)
	 	generate(100*i*i);

	return 0;
}
