#include <stdio.h>

int main(int argc, char **argv)
{
	int summe=0;
	int eingabe;
	for (int i=1;i<11;i++){
		scanf("%d",&eingabe);
		summe=summe+eingabe;
		
	}
	printf("Summe = %d\n",summe/10);
}
