#include <stdio.h>
#include <stdlib.h>


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

char* copy(char* str)
{
	int nb=longueur(str)+1;
	
	char* nc = (char*)malloc(nb*sizeof(char));
	char* ptr = nc;
	
	int i;
	for (i=0;i<nb;++i)
		*ptr++ = *str++;
	
	// remarque: ici nb==longueur+1 donc le boucle a copié le 0
	
	return nc;
}

char* reverse(char* str)
{
	int l=longueur(str);
	
	char* nc = (char*)malloc((l+1)*sizeof(char));
	char* ptr = nc;
	
	str += l-1;
	
	int i;
	for (i=0;i<l;++i)
	{
		*ptr++ = *str--;
		// ptr avance et str recule
	}
	// ici on doit ajouter la fin de chaine !
	*ptr = 0;
	
	return nc;
}

char* sub_string(char* str, int pos, int len)
{
	int l=longueur(str);
	char* nc = (char*)malloc((len+1)*sizeof(char));
	char* ptr = nc;

	str += pos;
	int i=0;
	// copie len charss sauf si la chaine est trop courte
	while ((i <len) && (i+pos < l)) 
	{
		*ptr++ = *str++;
		i++;
	}
	*ptr = 0; // on n'oublie pas la fin de chaine
	
	return nc;
}

char* int_to_string(int n)
{
	// calcul le nbre de chiffres
	int nbd=0;
	int x=n;
	do
	{
		x/=10;
		nbd++;
	} while (x>0);

	// alloue la chaine
	char* nc = (char*)malloc((nbd+1)*sizeof(char));
	// et on se place à la fin
	char* ptr = nc+nbd;

	*ptr-- = 0;
	while(n>0)
	{
		*ptr = '0'+n%10; // on extrait le dernier chiffre
		n /= 10;		// et on l'oublie (/10)
		ptr--;			// on recule dans la chaine
	}
	return nc;
}


int decoupe(char* str, char sep, char*** subs)
{
	// 1ere passe, calcul nbre de sous-chaines 
	int nb_sub=1;
	char* ptr = str;
	while (*ptr != '\0')
	{
		if (*ptr ==  sep)
			nb_sub++;
		ptr++;
	}
	
	// alloue la table de sous-chaine
	*subs = (char**)malloc(nb_sub*sizeof(char*));

	int pos=0;	// position debut de sous-chaine
	int len=0;	// longueur de sous-chaine
	ptr = str;	// ptr en dbut de chaine
	int s=0;	
	for(s=0;s<nb_sub;s++) // on boucle sur le nbre de sous-chaines
	{
		// trouve la fin de la sous-chaine courante
		while ((*ptr != '\0') && (*ptr != sep))
		{
			len++;
			ptr++;
		}
		// alloc pour la sous-chaine
		(*subs)[s] = sub_string(str,pos,len);
		// passage a la sous-chaine suivante;
		pos += len+1;
		ptr++;
		len = 0;
	}
	return nb_sub;
}	

int main()
{
	char* cp = copy("test de copie");
	puts(cp);
	
	char* rv = reverse(cp);
	puts(rv);
	free(cp);
	free(rv);
	
	char* sub = sub_string("bonjour tout le monde",8,4);
	puts(sub);
	free(sub);
	
	sub = sub_string("bonjour tout le monde",13,15);
	puts(sub);
	free(sub);
	
	char* nombre = int_to_string(7896);
	puts(nombre);
	free(nombre);
	
	puts("Decoupe de /usr/local/bin/exec separator=/ :");
	char** subs;
	int nbs = decoupe("/usr/local/bin/exec", '/', &subs);
	int i;
	for(i=0;i<nbs;i++)
	{
		printf(" -> %s \n",subs[i]);
		free(subs[i]); // libere la ieme sous-chaine
	}
	free(subs);// libere le tableau de chaine
	
	
	return 0;
}
