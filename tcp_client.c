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
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

int main(void){
    int sockfd;
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    if(inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0){
        perror("inet_pton error");
        exit(EXIT_FAILURE);
    }
    servaddr.sin_port = htons(8080);

    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    char buf[1024] = "www.zfl9.com";
    int nbytes;
    send(sockfd, buf, strlen(buf), 0);
    nbytes = recv(sockfd, buf, sizeof(buf), 0);
    if(nbytes < 0){
        perror("recv error");
        exit(EXIT_FAILURE);
    }else if(nbytes == 0){
        printf("server close\n");
    }else{
        buf[nbytes] = 0;
        printf("%s\n", buf);
    }

    close(sockfd);
    return 0;
}
