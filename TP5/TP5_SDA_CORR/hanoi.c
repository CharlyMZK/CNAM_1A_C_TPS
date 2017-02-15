#include <stdio.h>
#include <stdlib.h>

// nb nombre de disque a deplacer
// depuis le piquet "de"
// vers le piquet "vers"
// en utilisant temporairement le piquet par"
void hanoi(int nb, int de , int vers, int par, char* pile)
{
	char pileLocale[1024];
	sprintf(pileLocale,"%s / %d %d %d %d",pile,nb,de,vers,par);
	printf("%s \n",pileLocale);
	
	if (nb>0)
	{
		hanoi(nb-1,de,par,vers,pileLocale);
		printf("deplace de %d vers %d \n", de,vers);
		hanoi(nb-1,par,vers,de,pileLocale);
	}
}


int main(int argc,char **argv)
{
	int nb;
	if (argc ==2)
		nb = atoi(argv[1]);
	nb = 4;
	
	char *pileVide="Pile:";
	
	hanoi(nb,0,2,1,pileVide);
	return 0;
}
