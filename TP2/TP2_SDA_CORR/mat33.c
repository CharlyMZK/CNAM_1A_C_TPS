#include <stdio.h>

typedef float Mat33[3][3];


void printMat(Mat33 m)
{
	int j;
	for (j=0;j<3;j++)
	{
		printf("| ");
		int i;
		for (i=0;i<3;i++)
			printf("%8.3f ",m[j][i]);
		printf("|\n");
	}
}

void readMat(Mat33 m)
{
	int j;
	for (j=0;j<3;j++)
	{
		printf("Entrer ligne %d :",j);
		int i;
		for (i=0;i<3;i++)
			scanf("%f",&(m[j][i]));
	}
}


void setId(Mat33 m)
{
	int j,i;
	for (j=0;j<3;j++)
	{
		for (i=0;i<3;i++)
		{
			if (i==j)
				m[j][i]=1;
			else
				m[j][i]=0;
		}
	}
}


void setIdOpt(Mat33 m)
{
	int j,i;
	for (j=0;j<3;j++)
	{
		m[j][j]=1;
		for (i=1;i<3;i++)
			m[j][(i+j)%3]=0;
	}
}




void somme(Mat33 A, Mat33 B, Mat33 ApB)
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			ApB[i][j] = A[i][j] + B[i][j];
}

void produit(Mat33 A, Mat33 B, Mat33 AfB)
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			float v = 0;
			for(k=0;k<3;k++)
				v+= A[i][k] * B[k][j];
			AfB[i][j] = v;
		}
	}
}


int main()
{

	Mat33 A,B,C,I;
	
	setIdOpt(I);
	printMat(I);

	puts("Entrer A");
	readMat(A);
	puts("Entrer B");
	readMat(B);
	
	
	puts("A+B=");
	somme(A,B,C);
	printMat(C);
	
	puts("A*B=");
	produit(A,B,C);
	printMat(C);
	
	
	return 0;
}

