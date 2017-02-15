#include <stdio.h>

int main()
{
	int mois=0;
	printf("mois (1-12) ? ");
	scanf("%d",&mois);

	switch(mois)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf(" -> 31 jours\n");
			break;
		case 2:
			printf(" -> 28 jours\n");
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf(" -> 30 jours\n");
			break;
		default:
			printf("mois invalide\n");
			break;
	}
	return 0;
}

