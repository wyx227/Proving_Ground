/******************************************
*
* Dieses C-Programm zeigt, wie man mit
* Bitoperationen eine Ganzzahl als
* Dualzahl ausgeben kann.
*
* Konrad Preiser
*
******************************************/

/* Compiler-Direktiven
fuer den Praeprozessor
*/
/* System-Header-Dateien */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* Eigene Header-Dateien */
/* ... */

/* Globale Variablen */
/* ... */

/* Funktionsprototypen */
/* ... */


/**************************************
*                                    *
* Hauptprogramm ist Funktion main()  *
*                                    *
**************************************/


int main(int argc, char *argv[]) {

	/* Schleifenvariable Loesung 1. */
	int		i;
	/* Naechstes auszugebendes Zeichen ('0' bzw. '1') */
	char	zeichen;
	/* Auszugebende zahl. Es koennen bel. Integer-
	Datentypen verwendet werden! */
	int	zahl;
	int zahl1;
	/* Achtung: Da C alle Integer-Rechnungen mindestens
	im Datentyp int ausfuehrt, wird maske in der
	Schleife z.B. von short auf int erweitert.
	Da das MSBit der Maske gesetzt ist, erweitert C
	bei der Umwandlung in int die Zahl als negative
	Zahl mit fuehrenden 1-Bits. Dies zerstoert die
	Maske.
	Ausweg 1: Die Maske wird auf unsigned gesetzt.
	Dadurch wird eine Erweiterung nur mit 0-Bits
	erzwungen.
	Diese Loesung steht nicht fuer Java zur Verfuegung,
	weil es hier keine unsigned-Typen gibt.
	Ausweg 2: maske wird auf den groesstmoeglichen
	Datentyp vereinbart, also long (bzw. in Visual C
	auch _int64). Dann wird maske nicht erweitert.
	'zahl' wird dagegen implizit auf den Datentyp
	von 'maske' erweitert, falls fuer 'zahl'
	ein kleinerer Datentyp gewaehlt wurde.
	*/
	unsigned char	maske, msbit_maske;

	printf("Geben Sie eine Ganzzahl ein: ");
	scanf_s("%d", &zahl);
	printf("\n");

	/* Loesung 1: Die Zahl wird in einer Schleife
	um eine zuehmende Zahl von Stellen nach links
	verschoben und dann jeweils mit einer Maske
	verknuepft, die das hoechstwertige Bit
	auszuwerten gestattet.
	*/
	/* Damit das Programm unabhaengig von einem bestimmten
	Datentyp der Variablen 'zahl' korrekt arbeitet,
	wird die Zahl der Bits von 'zahl' ermittelt und
	eine 1 um entsprechend viele Stellen nach links
	verschoben. */
	maske = 1;
	maske <<= sizeof(zahl) * 8 - 1;
	/* maske hat jetzt einen Wert des Typs 100...000b */
	printf("Loesung 1:\n");
	printf(" zahl= %d= ", zahl);
	/* sizeof(zahl)*8 gibt die Zahl der Bits in der zahl an.
	Beachte, dass zuerst das hoechstwertige Bit ausgegeben
	werden muss!
	*/
	zahl1=zahl;
	for (i = 0; i<sizeof(zahl) * 8; i++) {
		//zeichen= (((zahl << i) & maske) == 0) ? '0' : '1';
		//		printf("i= %d\tzahl<<i=%X\t((zahl << i) & maske [%X])=%X\n", i, zahl<<i, maske, ((zahl << i) & maske));
		if (((zahl1 << i) & maske) == 0) {
			zeichen = '0';
		}
		else {
			zeichen = '1';
		}
		printf("%c", zeichen);
		zahl1<<=1;
	}
	printf("b\n");
	printf("\n");

	/* Loesung 2: Eine Bitmaske, die anfangs 100...000b
	enthaelt, wird in einer Schleife jeweils um eine
	Dualstelle nach rechts verschoben. Durch eine UND-
	Verknuepfung mit der zahl kann man in jedem
	Schleifendurchlauf den Wert einer Dualstelle
	ermitteln.
	Es ist keine zusaetzliche Schleifenvariable
	erforderlich!
	*/
	maske = 1;
	maske <<= sizeof(maske) * 8 - 1;
	msbit_maske = ~maske;
	/* maske hat jetzt einen Wert des Typs 100...000b */
	/* msbit_maske hat jetzt einen Wert des Typs 011...111b */
	printf("Loesung 2:\n");
	printf(" zahl= %d= ", zahl);
	while (maske != 0) {
		zeichen = ((zahl & maske) == 0) ? '0' : '1';
		printf("%c", zeichen);
		/* In Java koennte man statt der folgenden
		beiden Zeilen einfach schreiben:
		maske >>>= 1;
		In C muss man nach dem allerersten Verschieben
		das auf 1 gesetzte MSBit auf 0 setzen.
		Bei den weiteren Verschiebungen koennte die
		UND-Verknuepfung entfallen, da das MSBit dann
		immer 0 ist. */
		maske >>= 1;
		maske &= msbit_maske; /* MSBit auf 0 setzen. */
	}
	printf("b\n");
	printf("\n");

	printf("Loesung 3:\n");
	printf(" zahl= %d= ", zahl);
	maske = 1;
	maske <<= sizeof(maske) * 8 - 1;
	zeichen = ((zahl & maske) == 0) ? '0' : '1';
	printf("%c", zeichen);
	maske = 1;
	maske <<= sizeof(maske) * 8 - 2;
	/* maske hat jetzt einen Wert des Typs 010...000b */
	while (maske != 0) {
		/* maske
		0100 ... 000b
		0010 ... 000b
		0001 ... 000b
		...
		0000 ... 010b
		0000 ... 001b
		*/
		printf("%c", '0' + ((zahl & maske) != 0));
		/* Unkritisch, da MSBit immer 0 ist. */
		maske >>= 1;
	}
	printf("b\n");
	printf("\n");

	{
		char text[33]; /* Mindestwert! */
		char *c_ptr;

		c_ptr = &text[0];

		printf("Loesung 4:\n");
		printf(" zahl= %d= ", zahl);
		maske = 1;
		maske <<= sizeof(maske) * 8 - 1;
		zeichen = ((zahl & maske) == 0) ? '0' : '1';
		*c_ptr++ = zeichen;
		maske = 1;
		maske <<= sizeof(maske) * 8 - 2;
		/* maske hat jetzt einen Wert des Typs 010...000b */
		while (maske != 0) {
			*c_ptr++ = '0' + ((zahl & maske) != 0);
			/* Unkritisch, da MSBit immer 0 ist. */
			maske >>= 1;
		}
		*c_ptr = '\0';
		printf("%sb\n", text);
		printf("\n");
	}

	{
		char text[33]; /* Mindestwert! */
		char *c_ptr;

		c_ptr = &text[0];

		printf("Loesung 5 (auch fuer Java):\n");
		printf(" zahl= %d= ", zahl);
		maske = 1;
		for (i = sizeof(zahl) * 8 - 1; i >= 0; i--) {
			*c_ptr++ = '0' + ((zahl >> i) & maske);
		}
		*c_ptr = '\0';
		printf("%sb\n", text);
		printf("\n");
	}

	return 0;
}
