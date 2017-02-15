#include <stdio.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

void stats(float array[], int size, float* min, float* max, float *aver)
{
	*min = array[0];
	*max = array[0];
	int  i;
	for(i=0;i<size;i++)
	{
		if (array[i] > *max)
			*max = array[i];
			
		if (array[i] < *min)
			*min = array[i];
			
		*aver += array[i];
	}
	
	*aver /= size;
	
}

int main()
{
	float tab[4] = {0.1, 3.4, 2.3, 1.2};
	
	float min;
	float max;
	float moy;
	
	stats(tab,4,&min,&max,&moy);
	printf("Min: %f  Max: %f  Moyenne: %f \n",min,max,moy);

	puts("table");
	float* ptr = &(tab[0]);
	int i;
	for(i=0;i<4;++i)
		printf("%p -> %f\n",ptr, *ptr++);

	puts("vars");
	printf("%p  %p  %p \n",&min,&max,&moy);
	ptr = &min;
	printf("%p -> %f\n",ptr, *ptr);
	float* optr = ptr;
	ptr+=2;
	printf("%p  %ld -> %f\n",ptr, (long int)ptr - (long int)optr, *ptr);
	optr = ptr;
	ptr+=2;
	printf("%p  %ld -> %f\n",ptr, (long int)ptr - (long int)optr, *ptr);
	
	
	return 0;
}

