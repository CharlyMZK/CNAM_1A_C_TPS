#include <stdio.h>

int main()
{
	// variable pour les 2 horaires
	int h1;
	int m1;
	int s1;
	// possible de declarer plusieurs variables sur une ligne
	int h2,m2,s2;
	
	//saisie
	printf("horaire de depart (hh:mm:ss) ? ");
	scanf("%d : %d : %d",&h1,&m1,&s1);
	
	printf("horaire d'arrivee (hh:mm:ss) ? ");
	scanf("%d : %d : %d",&h2,&m2,&s2);
	
	// calcul le decalage des horaires en s par rapport a 0:0:0
	int t1 = 3600*h1+60*m1+s1;
	int t2 = 3600*h2+60*m2+s2;
	
	// petite astuce si les 2 horaires ne sont pas dans la meme journee
	// le decalage du deuxieme est calculé par rapport au jour précédent
	if (t1 > t2)
		t2 += 24*3600;
	
	// calcul de la durée 
	int duree = t2 - t1;
	
	printf("La duree est de %d secondes \n", duree);
	
	// reconversion en h:m:s
	int h3 = duree / 3600;
	int m3 = (duree-h3*3600)/60;
	int s3 = duree-h3*3600-m3*60;
	printf("La duree est de %d h %d m %d s\n", h3,m3,s3);
	
	return 0;
}
	
