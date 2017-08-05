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

void do_service(int conn);

int main(void){
    signal(SIGCHLD, SIG_IGN);

    int listenfd;
    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    int on = 1;
    if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0){
        perror("setsockopt error");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        perror("bind error");
        exit(EXIT_FAILURE);
    }

    if(listen(listenfd, SOMAXCONN) < 0){
        perror("listen error");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in peeraddr;
    socklen_t peerlen = sizeof(peeraddr);
    int conn;

    pid_t pid;

    while(1){
        if((conn = accept(listenfd, (struct sockaddr *)&peeraddr, &peerlen)) < 0){
            perror("accept error");
            exit(EXIT_FAILURE);
        }
        printf("accept connect: %s:%d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));

        pid = fork();
        if(pid < 0){
            perror("fork error");
            exit(EXIT_FAILURE);
        }else if(pid == 0){
            close(listenfd);
            do_service(conn);
            exit(EXIT_SUCCESS);
        }else{
            close(conn);
        }
    }

    close(listenfd);
    return 0;
}

void do_service(int conn){
    char buf[1024];
    int nbytes;
    while(1){
        nbytes = recv(conn, buf, sizeof(buf), 0);
        if(nbytes == 0){
            printf("client close\n");
            close(conn);
            break;
        }else if(nbytes < 0){
            perror("recv error");
            exit(EXIT_FAILURE);
        }else{
            buf[nbytes] = 0;
            printf("%s\n", buf);
            send(conn, buf, nbytes, 0);
        }
    }
}
