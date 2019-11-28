#include <stdio.h>

int main(int argc, char **argv)
{
	int zahl;
	int rest;
	int n_bits = sizeof(zahl)*8;	
	int result[n_bits];
	printf("Geben Sie eine Zahl ein: \n");
	scanf("%d",&zahl);
	printf("\nEingegeben wird %d. Es sind %d Bits auszugeben.\n",zahl,n_bits);
	printf("Die Zahl lautet in dualer Form: \n");
	for (int i=0;i<n_bits;i++){
		rest = zahl & 1;
		result[i]=rest;
		//printf("%d\n",rest);
		zahl = zahl >> 1;		
	}
	for (int i=n_bits-1;i>=0;i--){
		printf("%d",result[i]);
		
	}
	printf("\n");
}
