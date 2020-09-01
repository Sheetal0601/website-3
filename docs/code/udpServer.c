#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[ ]) {
  struct sockaddr_in my_addr;
  int fd, len;
 	if (argc != 2) {
		fprintf(stderr, "Usage: server port\n");
		exit(1);
	}

 /* Step 1: create socket in Inet domain for datagram
     communication.  The third argument specifies the
     protocol, but since there's only one such protocol in
     this domain, it's set to zero */
	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket");
		exit(1);
	}

	/* Step 2: set up our address */
	memset(&my_addr, 0, sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	my_addr.sin_port = htons(atoi(argv[1]));

	/* Step 3: bind the address to our socket */
	if (bind(fd, (struct sockaddr *)&my_addr,
		sizeof(my_addr)) < 0) {
		perror("bind");
		exit(1);
	}

	while (1) {
		char buf[1024];
		struct sockaddr_in from_addr;
		int from_len = sizeof(struct sockaddr_in);
		int msg_size;

		/* Step 4: receive message from client */
		if ((msg_size = recvfrom(fd, buf, 1024, 0,
			(struct sockaddr *)&from_addr, &from_len)) < 0) {
			perror("recvfrom");
			exit(1);
		}
		buf[msg_size] = 0;
		printf("message from %s:\n%s\n", inet_ntoa(from_addr.sin_addr), buf);

		/* Step 5: respond to client */
		if (sendto(fd, "thank you", 9, 0,
				(const struct sockaddr *)&from_addr,
				from_len) < 0) {
			perror("sendto");
			exit(1);
		}
	}
}
