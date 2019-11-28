#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next_ptr;
	struct Node *last_ptr;
};

struct Node* head_ptr;

struct Node* getNewNode(int x);
void InsertAtTail(int x);
void InsertAtHead(int x);
void InsertAfter(struct Node* prev_Node, int x);
void print();
void reverseprint();
void deleteNode(struct Node* NodetoDelete);
void deleteNodeAtGivenPos(int x);
//void menu();
void teil1();
void teil2();
void teil3();
void teil4();


int main()
{
	char eingabe = 0;
	//system("cls");
	printf("\n");
	printf("Wiederholungsprogramm fuer TEL17B\n");
	printf("======================================\n");
	printf("Teil 1. Logische Verknuepfungen und Bitweise Operatoren\n");
	printf("Teil 2. Dynamsiche Speicherverwaltung\n");
	printf("Teil 3. Selbstdefinierte Datentypen und Lineare Listen\n");
	printf("Geben Sie 'q' ein, um das Programm zu beenden.\n");
	printf("Geben Sie den auszufuehrenden Teilbereich an:\n");
	
	while(1){
		scanf_s("%c",&eingabe);
		switch(eingabe){
			case '1':
				printf("\n");
				teil1();
				main();
				
			case '2':
				printf("\n");
				teil2();
				main();
				
			case '3':
				printf("\n");
				teil3();
				main();
				
			case 'q':
				exit(1);
				break;
		}
	}

	return 0;

}

/*void menu(){
	char eingabe;
	//system("cls");
	printf("Wiederholungsprogramm fuer TEL17B\n");
	printf("Teil 1. Logische Verknuepfungen und Bitweise Operatoren\n");
	printf("Teil 2. Dynamsiche Speicherverwaltung\n");
	printf("Teil 3. Selbstdefinierte Datentypen und Lineare Listen\n");
	printf("Geben Sie den auszufuehrenden Teil bereich an:\n");
	scanf_s("%c",&eingabe);
	switch(eingabe){
		case '1':
			teil1();
			menu();
			break;
		case '2':
			teil2();
			main();
			break;
		case '3':
			teil3();
			main();
			break;
		case 'quit':
			break;
	}

}*/

void teil1(){
	int alpha, beta, a_quer, z;
	int zahl;
	int rest;
	int n_bits = sizeof(zahl) * 8;
	int result[32];
	
	printf("Teil 1 Logische Verknuepfungen und Bitweise Operatoren\n");
	
	for (int a= 0;a<=1;a++){
		for (int b = 0;b<=1;b++){
			for (int c=0;c<=1;c++){
				alpha = !(a && b);
				beta = alpha || c;
				a_quer = !a;
				z = (a_quer && !beta)|| (!a_quer && beta);
				printf("a = %d, b= %d, c= %d, alpha= %d, beta= %d, a_quer = %d, z= %d\n",a,b,c,alpha,beta,a_quer,z);
			}
		}
	}
	printf("Teil 1.1 Bitweise Operator\n");
	
	printf("Geben Sie eine Zahl ein: \n");
	scanf_s("%d", &zahl);
	printf("\nEingegeben wird %d. Es sind %d Bits auszugeben.\n", zahl, n_bits);
	printf("Die Zahl lautet in dualer Form: \n");
	for (int i = 0; i<n_bits; i++) {
		rest = zahl % 2;
		result[i] = rest;
		//printf("%d\n",rest);
		zahl = zahl >> 1;
	}
	for (int i = n_bits - 1; i >= 0; i--) {
		printf("%d", result[i]);

	}
	printf("\n");
}


void teil2(){
	int zeile, spalte;
	int *matrix;
	int k=0;
	

	
	printf("Teil 2 Dynamische Speicherverwaltung\n");
	printf("Geben Sie die Anzahl der Zeilen ein:\n");
	scanf_s("%d", &zeile);
	printf("Geben Sie die Anzahl der Reihen ein:\n");
	scanf_s("%d", &spalte);
	
	matrix = (int *)malloc(sizeof(int)*spalte*zeile);
	printf("Die Adresse dieser Matrix ist %p\n",matrix);
	for (int i = 0; i< zeile; i++){
		for (int j = 0; j<spalte;j++){
			*(matrix+i*zeile+j)=k;
			k++;
		}
	}
	
	printf("Nun wird die Matrix ausgegeben\n");
	for (int i = 0; i< zeile; i++){
		for (int j = 0; j<spalte;j++){
			printf("Das %d.te Element dieser Matrix ist %d\n",i*zeile+j+1,*(matrix+i*zeile+j));
		}
	}
	free(matrix);
}

void teil3(){
	int i;
	int *number_ptr;
	printf("Teil 3 Dynamische Speicherzuweisung\n");
	printf("Geben Sie die Anzahl der Zahlen:\n");
	scanf_s("%d", &i);
	number_ptr = (int *)malloc(i*sizeof(int));
	if (number_ptr == NULL) {
		fprintf(stderr, "Heap-Speicher voll beim Belegen von %d Bytes\n", sizeof(number_ptr));
	}
	printf("Geben Sie die Zahlen nacheinander ein:\n");
	for (int n = 0; n < i; n++) {
		scanf_s("%d", &number_ptr[n]);
		printf("\n");
	}
	for (int a = 0; a < i; a++) {
		printf("Die Zahl auf dem %d.ten Platz ist %d.\n", a+1, number_ptr[a]);
		
	}
	if (0) {
		free(number_ptr);
		number_ptr = NULL;
	}
	else {
		number_ptr = (int *)realloc(number_ptr, 0);
	}
	//free(number);
	printf("Geben Sie die neue Groesse ein:\n");
	scanf_s("%d", &i);
	number_ptr =(int *)realloc(NULL, sizeof(int)*i);
	printf("Geben Sie die Zahlen nacheinander ein:\n");
	for (int n = 0; n < i; n++) {
		scanf_s("%d", &number_ptr[n]);
		printf("\n");
	}
	for (int a = 0; a < i; a++) {
		printf("Die Zahl auf dem %d.ten Platz ist %d.\n", a + 1, number_ptr[a]);

	}
	free(number_ptr);
	
}

void teil4(){
	head_ptr = NULL;
	for (int i = 0; i < 25; i++) {
		InsertAtTail(i);
	}
	InsertAfter(head_ptr->next_ptr->next_ptr->next_ptr, 100);
	//deleteNodeAtGivenPos(5);
	print();
	reverseprint();
	free(head_ptr);
}

struct Node* getNewNode(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
	temp->data = x;
	temp->last_ptr = NULL;
	temp->next_ptr = NULL;

	return temp;
};

void InsertAtHead(int x) {
	struct Node* newNode = getNewNode(x);
	if (head_ptr == NULL) {
		head_ptr = newNode;
		return;
	}
	head_ptr->last_ptr = newNode;
	newNode->next_ptr = head_ptr;
	head_ptr = newNode;
}

void InsertAtTail(int x) {
	struct Node* newNode = getNewNode(x);
	struct Node* temp = head_ptr;
	if (head_ptr == NULL) {
		InsertAtHead(x);
	}
	else {
		while (temp->next_ptr != NULL) {
			temp = temp->next_ptr;
		}
		temp->next_ptr = newNode;
		newNode->last_ptr = temp;
			//newNode->next_ptr = NULL;
		return;
	}


}

void InsertAfter(struct Node* prev_Node, int x) {
	struct Node* new_Node = getNewNode(x);
	new_Node->next_ptr = prev_Node->next_ptr;
	new_Node->last_ptr = prev_Node;
	prev_Node->next_ptr = new_Node;
	if (new_Node->next_ptr != NULL) {
		new_Node->next_ptr->last_ptr = new_Node;
	}

}

void deleteNode(struct Node* NodetoDelete) {
	if (head_ptr == NULL || NodetoDelete == NULL) {
		printf("Leere Liste\n");
	}
	if (head_ptr == NodetoDelete) {
		head_ptr = NodetoDelete->next_ptr;
	}
	if (NodetoDelete->next_ptr != NULL) {
		NodetoDelete->next_ptr->last_ptr = NodetoDelete->last_ptr;
		//NodetoDelete->last_ptr->next_ptr = NodetoDelete->next_ptr;
	}
	if (NodetoDelete->last_ptr != NULL) {
		NodetoDelete->last_ptr->next_ptr = NodetoDelete->next_ptr;;
	}
	free(NodetoDelete);
	return;
}

void deleteNodeAtGivenPos(int x) {
	struct Node* current = head_ptr;
	
	if (head_ptr == NULL || x <= 0) {
		return;
	}
	for (int i = 0; current != NULL && i < x; i++) {
		current = current->next_ptr;
	}
	if (current == NULL) {
		return;
	}
	deleteNode(current);
}

void print() {
	struct Node* temp = head_ptr;
	printf("Forward\n");
	while (temp != NULL) {
		printf("%d\n", temp->data);
		printf("Die Adresse dieses Knotens ist %p\n", temp);
		temp = temp->next_ptr;
	}
}

void reverseprint() {
	struct Node* temp = head_ptr;
	if (temp == NULL) {
		printf("Leere Liste!\n");
		return;
	}
	printf("Reverse\n");
	while (temp->next_ptr != NULL) {
		temp = temp->next_ptr;
	}
	while (temp != NULL) {
		printf("%d\n", temp->data);
		printf("Die Adresse dieses Knotens ist %p\n", temp);
		temp = temp->last_ptr;
	}
}