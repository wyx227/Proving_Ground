#include <stdio.h>
int func(){
	return 5;
}
int main(int argc, char **argv)
{
	int adr = func;
	printf("%d\n",adr);
	return 0;
}
