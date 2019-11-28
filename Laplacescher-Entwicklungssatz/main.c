#include <stdio.h>
#include <string.h>  
#include <math.h>
int det_2(int matrix[2][2]);
int main(int argc, char **argv)
{
	int matrix[3][3];
	int det=0;
	int temp[2][2];
	int tmp;
	
	printf("Geben Sie die Matrix ein\n");
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			scanf("%i",&matrix[i][j]);
		}
	}
	printf("Die gegebene Matrix lautet:\n");
	for (int k=1;k<3;k++){
		for (int l=0;l<3;l++){
			printf("%i\t",matrix[k][l]);
		}
		printf("\n");
	}
	
	for (int l=0;l<3;l++){
		int index[3] = {0,1,2};
		for (int m=0;m<3;m++){
			if (index[m]==l){
				for (int c=m;c<3;c++){
					index[m]=index[m+1];
				}
			}
		}
		/**for (int d=0;d<2;d++){
			printf("%i\t",index[d]);
			//printf("\n");
		}**/
		if(l==0){
			temp[0][0]=matrix[0][l+1];
			temp[0][1]=matrix[0][l+2];
			temp[1][0]=matrix[2][l+1];
			temp[1][1]=matrix[2][l+2];			
		}else if(l==1){
			temp[0][0]=matrix[0][l-1];
			temp[0][1]=matrix[0][l+1];
			temp[1][0]=matrix[2][l-1];
			temp[1][1]=matrix[2][l+1];
		}else if(l==2){
			temp[0][0]=matrix[0][0];
			temp[0][1]=matrix[0][1];
			temp[1][0]=matrix[2][0];
			temp[1][1]=matrix[2][1];
		}
		/**
		if (index[0]==index[1]){
			tmp = index[1];
		}else{
			tmp = index[1]+1;
		}
		temp[0][0]=matrix[0][index[0]];
		temp[0][1]=matrix[0][index[1]];
		temp[1][0]=matrix[2][index[0]];
		temp[1][1]=matrix[2][index[1]];	
		**/	
		for (int a=0;a<2;a++){
			for (int b=0;b<2;b++){
				printf("%i\t",temp[a][b]);
			}
			printf("\n"); 
		}
		det=det+pow(-1,l+1)*matrix[1][l]*det_2(temp);
		printf("\n");
	}
	printf("Das Ergebnis ist %i\n ",det);
	//det=-matrix[1][0]*det_2(temp)+matrix[1][1]*det_2(temp)-matrix[1][2]*det_2(temp);

}
int det_2(int matrix[2][2]){
	int det_2 = matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1];
	return det_2;
}
