#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	int result[32];
	scanf_s("%d", &n);
	if (n>0){
		for (int i = 31; i > 0; i--) {
			int k = n >> i;
			if (k & 1) {
				printf("1");

			}
			else {
				printf("0");
			}
		}
	}else if(n<0){
	for (int i = 31; i > 0; i--) {
		int k = -n >> i;
		if (k & 1) {
			//printf("1");
			result[i]=1;
		}
		else {
			//printf("0");
			result[i]=0;
		}
	}
		for (int i = 31;i>1;i--){
			result[i]=!result[i];
		}
		for (int i = 31;i>0;i--){
			printf("%d",result[i]);
		}
		
	}

	getchar();
	return 0;
}