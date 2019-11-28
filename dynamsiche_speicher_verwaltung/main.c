#include <stdio.h>
#include <stdlib.h>

int main() {

	int i;
	int *number;
	printf("Geben Sie die Anzahl der Zahlen:\n");
	scanf_s("%d", &i);
	number = (int *)malloc(i);
	if (number == NULL) {
		fprintf(stderr, "Heap-Speicher voll beim Belegen von %d Bytes\n", sizeof(number));
	}
	printf("Geben Sie die Zahlen nacheinander ein:\n");
	for (int n = 0; n < i; n++) {
		scanf_s("%d", &number[n]);
		printf("\n");
	}
	for (int a = 0; a < i; a++) {
		printf("Die Zahl auf dem %d.ten Platz ist %d.\n", a+1, number[a]);
		
	}

	//free(number);
	printf("Geben Sie die neue Groesse ein:\n");
	scanf_s("%d", i);
	number =(int *)malloc(i);
	printf("Geben Sie die Zahlen nacheinander ein:\n");
	for (int n = 0; n < i; n++) {
		scanf_s("%d", &number[n]);
		printf("\n");
	}
	for (int a = 0; a < i; a++) {
		printf("Die Zahl auf dem %d.ten Platz ist %d.\n", a + 1, number[a]);

	}
	free(number);
	return 0;
	
}