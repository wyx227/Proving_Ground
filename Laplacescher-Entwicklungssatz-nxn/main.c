#include <stdio.h>
#include <stdlib.h>

int power(int , int); /*Prototype of the function that calculates the power.*/
int **minor(int** , int , int); /*Prototype of the function that determines the minor of the matrix. */ 
int det(int **, int, int); /*Prototype of the recursive function that calculates the determinant of the matrix*/

int main(){
    int order; /* The order of the matrix*/
    int element; /*The element of which the minor will be calculated*/
    char answer; /*The reexecution directive*/

    do{
        printf("The following program calculates the determant of a matrix.\n\n");
        printf("First, Enter the order of your matrix:");
        scanf("%d",&order); /*Reading the order from the user*/

        int **matrix = (int **)malloc(sizeof(int *) * (order)); /*allocating memory for the matrix*/
        for (int i = 0; i < order ; i++) 
            matrix[i] = (int *)malloc((order) * sizeof(int));

        printf("Now, you will fill your %d * %d matrix.\n",order,order);
        for (int i = 0 ; i < order ; i++){  /*Filling the Matrix*/
            for (int j = 0 ; j < order ; j++){
                printf("Enter the element corresponding to the position [%d][%d]:",i,j);
                scanf("%d",&matrix[i][j]);
            }
        }

        printf("Your matrix is now completely filled as the following:\n\n");
        for (int i = 0 ; i < order ; i++){  /*Displaying the matrix*/
            for (int j = 0 ; j < order ; j++)
                printf("\t%d  ",matrix[i][j]);
            printf("\n");
        }

        int x = det(matrix, order, 0);
        printf("%d",x);

        printf("\nRun the program again?\n");
        printf("(1 for yes, any other key for no):");
        scanf(" %c",&answer);
    }while(answer == '1');

    printf("\n\n\t\t\tEnd of Program. Bye\n");
    printf("\n\t\t\t");
    system("PAUSE");
    return 0;
}

int power(int a, int b){
    int result;
    if (!b)
        result = 1;
    else
        result = a * power(a, b - 1); 
    return result;
}

int **minor(int **matrix, int order, int element){
    int **submatrix = (int **)malloc(sizeof(int *) * (order - 1)); /*allocating memory for the submatrix*/
    for (int i = 0; i < order - 1 ; i++) 
        submatrix[i] = (int *)malloc((order - 1) * sizeof(int));

    int row = -1, column = -1,exit_loop = 0;
    for (int i = 0 ; i < order ; i++){  /*Getting the exact position of the element*/
        for (int j = 0 ; j < order ; j++)
        if (element == matrix[i][j]){
            row = i;
            column = j;
            exit_loop = 1;
            break;
        }
        if(exit_loop)
        break;
    }

    int row2 = 0;
    int column2 = 0;
    int i = 0, j= 0;
    while(row2 < order){   /*Copying the original matrix to the sub matrix (minor)*/
        if (row2 != row){
            while(column2 < order){
                if(column2 != column)
                    submatrix[i][j++] = matrix[row2][column2];
                column2++;
            }
            i++;
        }
        row2++;
        column2 = 0;
        j = 0;      
    }
    return submatrix; /*Returning the submatrix*/

}

int det(int **x, int order, int index){
    int sum = 0;
    if(order == 1)
        sum = x[0][0];
    else
        sum = power(-1,x[0][index]) * 
              x[0][index] * 
              det( (minor(x, order - 1, x[0][index])), order - 1, ++index);
    return sum;
}