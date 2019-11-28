#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

int main(){
	struct sockaddr_in address;
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char *hello = "Hello from client";
	char buffer[1024] = 0;
	if ((sock = socket(AF_INET, SOCK_STREAM, 0))< 0){
		printf("\n Socket creation error");
		return -1;
	}
	
	memset(&serv_addr,'0',sizeof(serv_addr));
	
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = hton(PORT);
	
	if (inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr)<=0){
		printf("\nInvalid address/ Address not supported\n");
		return -1;
	}
	if (connect(sock, (struct sockaddr *)&serv_addr,sizeof(serv_addr))< 0){
		printf("\Connection failed\n");
		return -1;
	}
	send(sock,hello, strlen(hello),0);
	printf("Hello Message send\n");
	valread = read(sock,buffer,1024);
	printf("%s\n",buffer);
	return 0;
}