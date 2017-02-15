#include <stdio.h>


// bissextile: multiple de 4 mais pas de 100 ou multiple de 400
int nbj_fevrier(int a)
{
	if (((a%4==0) && (a%100!=0)) || (a%400==0))
		return 29;
//	else
		return 28;
}


int main()
{
	
	// variable pour la date j/m/a
	int j;
	int m;
	int a;

	//saisie
	printf("Entrer une date (jj/mm/aaaa) ? ");
	scanf("%d / %d / %d",&j,&m,&a);
	
	//passe au jour suivant
	j++;
	// et remet la date au format correct
	switch(m)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			if (j==32)
			{
				j=1;
				m++;
			}
			break;
		case 12:
			if (j==32)
			{
				j=1;
				m=1;
				a++;
			}
			break;
		case 2:
			if (j == nbj_fevrier(a)+1 )
			{
				j=1;
				m=3;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (j==30)
			{
				j=1;
				m++;
			}
			break;
		default:
			break;
		}

	//   %d pour int
	//  %2d pour int avec affichage de 2 caract (remplis avec des blancs)
	// %02d pour int avec affichage de 2 caract (remplis avec des 0)
	printf("jour suivant: %02d/%02d/%4d \n",j,m,a);
	return 0;
}
