#include <stdio.h>

void increment(int*);
int main(int argc, char **argv)
{
	//int p;
	int a = 10;
	increment(&a);
	printf("a = %d\n",a);
}

void increment(int *a){
	*a = (*a)+1;
}
