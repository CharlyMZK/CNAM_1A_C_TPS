#include <stdio.h> // la libc est inclu par default 
#include <math.h> // => compiler avec l'option -lm

int main()
{
	float cote;
	printf ("Entrer le cote du carre:");
	scanf("%f",&cote);
	
	float peri = cote*4.0;
	float surf = cote*cote;
	float diag = sqrtf(2.0*cote*cote); // sqrtf = sqrt pour les float
	
	printf ("perimetre = %f\n",peri);
	printf ("surface = %f\n",surf);
	printf ("diagonale = %f\n",diag);
	
	return 0; // tout c'est bien passé, OK = 0
}

