#include <stdio.h>
#define BOOL int
#define TRUE 1
#define FALSE 0


BOOL compare(char* str1, char* str2)
{
	while ((*str1 != 0) && (*str2 != 0))
	{
		if (*str1 != *str2)
			return FALSE;
		str1++;
		str2++;
	}

	return (*str1 == *str2);
}

BOOL string_to_int(char* str, int* value)
{
	int signe=1;
	if (*str == '-')
	{
		signe = -1;
		str++;
	}
	int v=0;
	while (*str != '\0')
	{
		int chiffre = *str -'0';
		if ((chiffre>9)||(chiffre<0))
			return FALSE;
		v = 10*v+chiffre;
		str++;
	}
	*value = signe*v;
	return TRUE;
}

int main(int argc, char **argv)
{
	printf("Programme: %s\n",argv[0]);
	int i;
	for (i=1;i<argc;i++)
	{
		printf("param %d : %s \n",i,argv[i]);
	}

	int res=0;
	int v;
	
	// check que le nb de param est pair
	if ((argc%2!=0))
	{
		puts("wrong format");
		return 1;
	}

	// et superieur a 2
	if (argc>=2)
		string_to_int(argv[1],&res);
		
	i=2;
	while(i<argc)
	{
		// convertit l'operande
		BOOL b = string_to_int(argv[i+1],&v);
		if (!b)
		{
			puts("not a number");
			return 1;
		}
		
		// suivant l'operateur effectue + ou -
		if (compare (argv[i],"+"))
		{
			res+=v;
		}
		else
			if (compare (argv[i],"-"))
			{
				res-=v;
			}
			else 
			{
				puts("Operation interdite");
				return 1;
			}
			
		i+=2; // passe à l'op suivante
	}
	
	printf("Total = %d \n",res);
	
	return 0;
}

