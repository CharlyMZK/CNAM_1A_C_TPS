
typedef struct sNoeud
{
	int val;
	struct sNoeud* next;
	struct sNoeud* prev;
} Noeud;
	

typedef struct
{
	 int nb;
	 Noeud* first;
	 Noeud* last;
} Liste;


Noeud* nouveau_noeud(int v);

Liste* liste_vide();

void clear(Liste* l);

Noeud* push_front(Liste* l, int v);

void pop_front(Liste* l);

int front_val(Liste* l);

void print(Liste* l);

int est_vide(Liste* l);

Noeud* trouve_premier(Liste* l, int v);

int occurence(Liste* l, int v);

Noeud* push_back(Liste* l, int v);

int back_val(Liste* l);

void pop_back(Liste* l);

Noeud* insert_after(Liste* l, Noeud* c, int v);

void retire(Liste* l, Noeud* n);

void apply(Liste* l, void (*fonct)(int*));
