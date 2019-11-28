/**
 * Einfache Simulation eines Getraenkautomaten.
 * TEL17B2, 05.02.2018
 */
// Standard-Header-Dateien
#include <stdio.h>
#include <stdlib.h>

// Funktionsprototypen
// Bei Anfaengerprogrammbesipielen sieht man oft,
//  dass zuerst verschiedene Funktionsdefinitionen
//  im Quelltext auftauchen und erst ganz am Ende
//  die Funktion main angeschrieben wird. Warum das?
//  Man moechte hier den Anfaengern ersparen, den Sinn
//  von Prototypen zu verstehen, denn wenn eine 
//  Funktionsdefinition angeschrieben wird, bevor diese
//  Funktion erstmals aufgerufen wird, eruebrigt es sich,
//  einen Prototypen anzugeben. Da man aber dann mit
//  der Reihenfolge der Funktionsdefinitionen sehr
//  gebunden ist und vollends scheitert, wenn man
//  mit mehreren Quelldateien arbeiten will, haben wir
//  von vornherein mit Prototypen gearbeitet und diese
//  besprochen. Vom der Programmlogik und dem Top-Down-Ansatz
//  her ist es widersinnig, die Funktion main erst am
//  Dateiende anzuordnen.
// ACHTUNG: Leere Klammern im Prototypen bedeuten
//  nicht "KEINE" Parameter, sondern nur, dass man
//  ueber die moeglichen Parameter keine Aussage
//  getroffen hat. Wenn man ausdruecklich festlegen
//  will, dass eine Funktion keine Parameter hat,
//  muss man in den runden Klammern "void" hinzusetzen.
//  Beim Aufrufen einer derartigen Funktion werden
//  allerdings nur leere runde Klammern angeschrieben.
//  [Java: Da hat man diesen Unsinn weggelassen - leere
//  Klammern bedeuten hier wirklich "KEINE PARAMETER!".]
int auswahlGetraenkeSorte(void);
int eingabeMenge();
// Die folgenden Prototypen zeigen, dass man
//  keine oder beliebige formale Parameternamen
//  angeben kann. Allerdings sollte man immer
//  genau den formalen Parameternamen aus dem
//  entsprechenden Funktionskopf verwenden und
//  bei Aenderungen dort ohn hier nachtragen, damit
//  das Programm wirklich konsistent bleibt.
//  Der formale Parametername ist einerseits nuetzlich,
//  um als Mensch die Bedeutung eines Parameters
//  bereits im Prototypen erkennen zu koennen (vgl.
//  Goll Anhang A!), und andererseits bequem beim
//  Programmieren, damit man einfach den Uebergang 
//  zwischen dem Funktionskopf und dem Prototypen 
//  bewerkstelligen kann.
// Warum darf der Parameter fehlen? - Die Prototypen
//  dienen nur dazu, um dem Compiler mitzuteilen, wie viele
//  formale Parameter eine bestimmte Funktion hat und
//  welche Datentypen diese Parameter haben; ausserdem
//  wird der Datentyp des Funktionsrueckgabewertes
//  festgelegt. Mit Hilfe dieser Informationen kann der
//  Compiler moegliche Funktionsaufrufe auf ihre formale
//  Korrektheit hin ueberpruefen. Dazu ist kein formaler
//  Parametername noetig! Dieser wird erst in der
//  Funktionsdefinition benoetigt, um den Code anschreiben
//  zu koennen.
float ermittleEinzelPreis(int affe);
void bezahlen(float);
void ausgabeGetraenke(int, int);


/**
 * Hauptprogramm.
 * Vgl. Goll Kap.15 und Skizze an der Tafel!
 * Parameter:
 *  argc - ....
 *  argv - ....
 * Rueckgabewert:
 *  .....
 */
int main(int argc, char*argv[])
{
	int sorte, menge; // Nicht verwendet: bezahlt;
	float preis, gesamt_preis;
	
	// ACHTUNG: Beim Aufrufen einer Funktion ohne Parameter
	//  nur leere Klammern anschreiben!!
	sorte = auswahlGetraenkeSorte();
	preis = ermittleEinzelPreis(sorte);
	menge = eingabeMenge();
	gesamt_preis = preis * menge;
	bezahlen(gesamt_preis);
	ausgabeGetraenke(sorte, menge);
	printf("\n\nVielen Dank, bitte entnehmen sie ihre Getraenke.\n");
	
	return EXIT_SUCCESS;
} // main


/**
 * Diese Funktion gestattet es dem Anwender, die
 * gewuenschte Getraenkesorte interaktiv auszuwaehlen.
 * Formale Parameter:
 *  KEINE
 * Rueckgabewert:
 *  Ganzzahl mit der Kennung des Getraenkes (derzeit
 *	die Zahlen 1, 2 oder 3).
 */
int auswahlGetraenkeSorte(void)
{
	// Jede Funktion arbeitet mit einem eigenen Namensraum;
	//  diese Variable sorte hat also formal nichts mit den
	//  anderen gleichnamigen Variablen in den anderen Funktionen
	//  zu tun!
	int sorte;
	printf("Waehlen sie ihr Getraenk aus:\n");
	printf("1) Wasser (0,50 Euro)\n");
	printf("2) Limonade (1,00 Euro)\n");
	printf("3) Bier (2,00 Euro)\n\n");
	// Nach einem sog. Prompt, der den Benutzer zum Eingeben
	//  auffordert, ueblicherweise KEINEN Zeilneumbruch \n
	//  vorsehen!
	printf("Geben sie 1, 2 oder 3 ein: ");
	// Call-by-reference: Es wird die Adresse der Variablen
	//  sorte erfragt und an scanf uebergeben. Dadurch kann
	//  die Funktion scanf gezielt auf die zu aendernde
	//  Variable sorte durch sog. Dereferenzieren zugreifen
	//  und den eingetippten und in eine Dualzahl umgewandelten
	//  Zahlenwert in ihr ablegen.
	scanf("%d", &sorte);
	return sorte;
} // auswahlGetraenkeSorte

int eingabeMenge() {
	int menge=1;
	printf("\nGeben sie die gewuenschte Menge ein: ");
	scanf("%d", &menge);
	return menge;
}

float ermittleEinzelPreis(int getraenke_id) {
	float preis=0;
	switch(getraenke_id) {
		case 1: preis = 0.5; break;
		case 2: preis = 1.0; break;
		case 3: preis = 2.0; break;
	}
	return preis;
}

void bezahlen(float gesamt_preis) {
	float einwurf;
	printf("\n--- Bezahlvorgang ---\n");
	do {
		printf("\nEs fehlen noch %.2f Euro.", gesamt_preis);
		printf("\nBitte werfen sie ein Geldstueck ein: ");
		scanf("%f", &einwurf);

		gesamt_preis -= einwurf;
	} while(gesamt_preis > 0.0);
}

void ausgabeGetraenke(int sorte, int menge) {
	int i;
	printf("\n--- Getraenkeausgabe ---\n");
	for(i=0; i < menge; i++)  {
		printf("\nFlasche %d von %d der Sorte %d wurde ausgegeben.",
			i+1, menge, sorte);
	}
}