#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

const int PORTNUM = 1234;

int main()
{
	int sockfd, nsockfd;

    struct sockaddr_in serv_addr, cli_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		printf("Cant open socket!\n");
		exit(EXIT_FAILURE);
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORTNUM);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	// Bind to socket
	int res = bind(sockfd, (const struct sockaddr *)&serv_addr, sizeof(serv_addr));
	if(res < 0)
	{
		printf("Can't bind socket\n");
		exit(EXIT_FAILURE);
	}

	// listen for connection
	listen(sockfd, 5);

}
