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

#define BIND_PORT 8080
#define BUF_SIZE 128

int main(void){
    int sockfd;
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        perror("create_sockfd error");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in bindaddr;
    memset(&bindaddr, 0, sizeof(bindaddr));
    bindaddr.sin_family = AF_INET;
    bindaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bindaddr.sin_port = htons(BIND_PORT);

    if(bind(sockfd, (struct sockaddr *)&bindaddr, sizeof(bindaddr)) < 0){
        perror("bind_sockfd error");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in peeraddr;
    socklen_t peerlen;
    char buf[BUF_SIZE];
    int nbuf;

    for(;;){
        nbuf = recvfrom(sockfd, buf, BUF_SIZE, 0, (struct sockaddr *)&peeraddr, &peerlen);
        buf[nbuf] = 0;
        if(!strcmp(buf, "exit")){
            printf("exit_server\n");
            break;
        }
        printf("new msg(%s:%d): %s\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port), buf);
        sendto(sockfd, buf, nbuf, 0, (struct sockaddr *)&peeraddr, peerlen);
    }

    close(sockfd);
    return 0;
}
