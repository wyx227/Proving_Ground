#include <stdio.h>
#include <math.h>
double calculation(double x,double y){
    return sqrt(pow(x,2)+pow(y,2));
    
}
int main()
{
    printf("Result is %lf",calculation(5,4));
    
}
