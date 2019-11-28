#include<stdio.h>
#include<stdlib.h>

int main()
{
	float **input,**Inverse,localVariable;
	int i,j,k,sizeOfMatrix;

	printf("Enter matrix size. It's a square matrix. So enter value of n (nXn)\n"); //CodewithC.com
	scanf("%d",&sizeOfMatrix);

	input = (float **)malloc(sizeOfMatrix*sizeof(float *));			

	for(i=0;i<sizeOfMatrix;i++)
		input[i]=(float *)malloc(sizeOfMatrix*sizeof(float));

	Inverse=(float **)malloc(sizeOfMatrix*sizeof(float *));		

	for(i=0;i<sizeOfMatrix;i++)
	{
	
		Inverse[i]=(float *)malloc(sizeOfMatrix*sizeof(float));
	}

	printf("Now enter the matrix:\n");						
	for(i=0;i<sizeOfMatrix;i++)
		for(j=0;j<sizeOfMatrix;j++)
			scanf("%f",&input[i][j]);

	for(i=0;i<sizeOfMatrix;i++)									
	for(j=0;j<sizeOfMatrix;j++)							
	if(i==j)										
	Inverse[i][j]=1;									
	else											
	Inverse[i][j]=0;								


	for(k=0;k<sizeOfMatrix;k++)									 
	{														
		localVariable=input[k][k];										
		for(j=0;j<sizeOfMatrix;j++)								
		{
			input[k][j]/=localVariable;									
			Inverse[k][j]/=localVariable;									

		}													
		for(i=0;i<sizeOfMatrix;i++)									
		{
			localVariable = input[i][k];									
			for(j=0;j<sizeOfMatrix;j++)							
			{												
				if(i==k)
					break;									
				input[i][j] -= input[k][j]*localVariable;						
				Inverse[i][j] -= Inverse[k][j]*localVariable;						
			}
		}
	}

	printf("The inverse matrix is:\n");				

	for(i=0;i<sizeOfMatrix;i++)
	{
		for(j=0;j<sizeOfMatrix;j++)
			printf("%f	",Inverse[i][j]);
		printf("\n");
	}
	return 0;
	getch();
}

