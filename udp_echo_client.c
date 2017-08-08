#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define SERV_PORT 8080
#define BUF_SIZE 128

int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "usage: %s <MSG>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd;
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        perror("create_sockfd error");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    if(inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0){
        perror("convert_servaddr error");
        exit(EXIT_FAILURE);
    }
    servaddr.sin_port = htons(SERV_PORT);

    char buf[BUF_SIZE];
    int nbuf = strlen(argv[1]);
    sendto(sockfd, argv[1], nbuf, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    nbuf = recvfrom(sockfd, buf, BUF_SIZE, 0, NULL, NULL);
    buf[nbuf] = 0;
    printf("echo msg: %s\n", buf);

    close(sockfd);
    return 0;
}
