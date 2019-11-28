#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char*argv[]){
	
	double a;
	double b;
	double z1;
	double z2;

	printf("Hier ist das Beispiel fuerr die Implmentierung des Nassi-Shneidermann-Diagramms\n");
	printf("a = \n");
	scanf("%lf",&a);
	printf("b = \n");
	scanf("%lf",&b);
	printf("a = %f, b = %f\n",a,b);
	do{
		if(b>a){
			if (b>a){
				z1 = a/5+sqrt(b-a);
				if(sqrt(b-a)==5){
					printf("a=%lf, b=%lf ,z1=%lf ,z2=%lf \n",a,b,z1,z2);	
			
				}else{
					z2=a/5-sqrt(b-a);
					printf("a=%lf, b=%lf ,z1=%lf ,z2=%lf \n",a,b,z1,z2);	
				}
			}else{
				z1 = a/5;
				z2=z1;
				printf("a=%lf, b=%lf ,z1=%lf ,z2=%lf \n",a,b,z1,z2);	
			}
			
		}else{
		
			printf("Die Ergebnis ist imaginaer.\n");
		}
		
		
	}while(a!=99999);
	getchar();

}