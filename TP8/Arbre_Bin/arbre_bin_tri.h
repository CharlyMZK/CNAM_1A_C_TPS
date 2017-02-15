

#define MAX(X,Y) ((X)>(Y)?(X):(Y))

typedef int T;

typedef struct sArbre
{
	T label;
	struct sArbre* fg;
	struct sArbre* fd;	
} Arbre;


Arbre* fils_gauche(Arbre* a);

Arbre* fils_droit(Arbre* a);

T racine(Arbre* a);

int est_vide(Arbre* a);

int est_feuille(Arbre* a);

int hauteur(Arbre* a);

int taille(Arbre* a);

void save_dot(Arbre* a, char* nom);

void clean(Arbre* a);

Arbre* inserer(Arbre* a, T v);
