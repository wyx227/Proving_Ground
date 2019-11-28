#include <stdio.h>

void print(char *C);
int main(int argc, char **argv)
{
	char C[20]="Hello";
	print(C);
}

void print(char *C){
	while (*C != '\0'){
		printf("%C\n",*C);
		C++;
	}
	printf("\n");
}

