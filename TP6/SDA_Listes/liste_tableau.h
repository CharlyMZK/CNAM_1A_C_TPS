
typedef struct sNoeud
{
	int val;
} Noeud;
	

typedef struct
{
	 int nb;
	 Noeud* data; // ici on gere un tableau de Noeuds (alloc dynamique)
} Liste;


// Attention les Noeud* renvoyés ne restent ici valides que si on ne
// fait pas de push_front/pop_front/insert_after/retire
// En effet les Noeuds ne sont pas fixes dans le memoire puisqu'ici
// on décale une partie du tableau tableau !


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
