/**
* Ein Zahl als Dualzahl ausgeben.
*
* TEL17B2, 18.04.2018
*/
// System-Header-Dateien
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/**
* Hauptprogramm.
*/
int main(int argc, char*argv[])
{
	int zahl;
	int n_bits = sizeof(zahl) * 8;
	int i;
	int zahl1;
	int maske1;

	printf("Ein Zahl als Dualzahl ausgeben\n");
	printf("==============================\n");

	printf("Geben Sie eine Ganzzahl ein: ");
	scanf("%d", &zahl);
	printf("Die eingegebene Zahl lautet %d = 0x%X\n",
		zahl, zahl);

	// Version 1
	//printf("%d ", zahl >> (n_bits-1)-0 % 2);
	//printf("%d ", zahl >> (n_bits-1)-1 % 2);
	//printf("%d ", zahl >> (n_bits-1)-2 % 2);
	//printf("%d ", zahl >> (n_bits-1)-3 % 2);
	//// ...
	//printf("%d ", zahl >> 3 % 2);
	//printf("%d ", zahl >> 2 % 2);
	//printf("%d ", zahl >> 1 % 2);
	//printf("%d ", zahl >> 0 % 2);
	for (i = 0; i < n_bits; i++)
		printf("%d ", (zahl >> (n_bits - 1 - i)) % 2);
	printf("\n");

	// Version 2
	for (i = 0; i < n_bits; i++)
		printf("%d ", (zahl >> (n_bits - 1 - i)) & 1);
	printf("\n");

	// Version 3
	// Hoechstwertiges Bit abfragen; relativ verschieben um 1
	// Ternaerer Operator
	zahl1 = zahl;
	for (i = 0; i < n_bits; i++)
	{
		printf("%d ", (zahl1 < 0) ? 1 : 0);
		zahl1 <<= 1;
	}
	printf("\n");

	// Version 4
	// Hoechstwertiges Bit abfragen; relativ verschieben um 1
	// Ternaerer Operator
	zahl1 = zahl;
	for (i = 0; i < n_bits; i++)
	{
		printf("%c ", (zahl1 < 0) ? 'H' : 'L');
		zahl1 <<= 1;
	}
	printf("\n");

	// Version 5
	// Hoechstwertiges Bit abfragen; relativ verschieben um 1
	// Ausnuetzen, dass es in C keinen Boole'schen Datentyp gibt
	// und dass daher beim Vergleichen numerisch 0 oder 1 herauskommt.
	// Ausserdem nutzen wir die Tatsache, dass der Zeichen-Code von
	// dem Schriftsymbol 1 direkt nach demjenigen des Schriftsymbols 0
	// folgt.
	zahl1 = zahl;
	for (i = 0; i < n_bits; i++)
	{
		printf("%c ", '0' + (zahl1 < 0));
		zahl1 <<= 1;
	}
	printf("\n");

	// Version 6
	// maske1 = 1000000...00000 binaer;
	// maske1 = 0x80000000;
	maske1 = 1 << (n_bits - 1);
	for (i = 0; i < n_bits; i++)
	{
		printf("%d ", (zahl & maske1) == maske1);
		maske1 >>= 1;
		// MSBit "erschlagen" (eigentlich nur noetig beim 1. Mal und
		//  nur deshalb, weil wir mit signed und nicht mit unsigned 
		//  arbeiten!)
		// 0111111111 binaer
		// 0x7FFFFFF
		maske1 &= ~(1 << (n_bits - 1));
	}
	printf("\n");
	getchar();
	return EXIT_SUCCESS;
} // main
