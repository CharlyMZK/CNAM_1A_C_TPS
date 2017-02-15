#include <stdio.h>

#define BOOL int
#define TRUE 1
#define FALSE 0


int longueur(char* str)
{
	int l=0;
	while (*str++ != '\0')
		l++;
	return l;
}

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

BOOL palindrome(char* str)
{
	char* str_fin = str;
	
	while (*str_fin != '\0') // va jusqu'au zero
		str_fin++;
	str_fin--;					// pointe sur le char avant le zero
	
	while (str < str_fin)
	{
		printf("%c ?? %c   ", *str, *str_fin);
		printf("%d ?? %d\n", *str, *str_fin);
		if (*str != *str_fin)
			return FALSE;
		str++;
		str_fin--;
	}
	return TRUE;
	
}

//~ int occurences(char*, char)
//~ {
	//~ 
//~ }

BOOL compare_sub(char* str1, char* str2, int nb)
{
	int i;
	for(i=0;i<nb;++i)
	{
		if (*str1 != *str2)
			return FALSE;
		str1++;
		str2++;
	}
	return TRUE;
}

int find_sub_string(char* str, char* sub)
{
	int lstr = longueur(str);
	int lsub = longueur(sub);
	int dif = lstr - lsub; 
	int i;
	for (i=0;i<=dif;i++)
	{
		if (compare_sub(str,sub,lsub))
			return i;
		str++;
	}
	return -1;
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


int main()
{
	char* phrase = "engagelejeuquejelegagne";
	printf("Longueur de la phrase %d \n",longueur(phrase));
	if (palindrome(phrase))
		puts("palindrome");
	else
		puts("pas palindrome");
	
	if (compare("jeu", "que"))
		puts("jeu == que");
	else
		puts("jeu != que");

	if (compare("jeu", "jeu"))
		puts("jeu == jeu");
	else
		puts("jeu != jeu");
		
	if (compare("jeu", "jeux"))
		puts("jeu == jeux");
	else
		puts("jeu != jeux");


	
	printf("position de jeu : %d\n",find_sub_string(phrase,"jeu"));
	printf("position de quel : %d\n",find_sub_string(phrase,"quel"));
	
	int x;
	if (string_to_int("4235",&x))
		printf("4235 = %d\n",x);
		
	if (string_to_int("-78",&x))
		printf("-78 = %d\n",x);

	
	return 0;
}
