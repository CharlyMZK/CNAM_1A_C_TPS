#include <stdio.h>
#include <stdlib.h>


#define BOOL int
#define TRUE 1
#define FALSE 0

BOOL palind_rec(char* str, char* fin_str)
{
	if (str >= fin_str)
		return TRUE;
		
	if (*fin_str != *str)
		return FALSE;
		
	return palind_rec(str+1,fin_str-1);
}

BOOL palind(char* str)
{
	char* fin = str;
	while (*fin !=0)
		fin++;
	fin--;
	return palind_rec(str,fin);
}



int main(int argc, char **argv)
{
	printf("kayak : ");
	if (palind("kayak"))
		puts("palindrome");
	else
		puts("pas palindrome");
	
	printf("koyak : ");
	if (palind("koyak"))
		puts("palindrome");
	else
		puts("pas palindrome");
	
	
	return 0;
}

