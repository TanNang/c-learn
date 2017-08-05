#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void){
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(8080);

    int sock;
    char msg[512+1];
    while(1){
        sock = socket(AF_INET, SOCK_STREAM, 0);
        connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

        printf("send: ");
        scanf("%s", msg);

        write(sock, msg, strlen(msg));
        if(!strcmp(msg, "exit")){
            break;
        }

        int cnt = read(sock, msg, 512);
        msg[cnt] = '\0';
        printf("recv: %s\n", msg);

        close(sock);
    }

    printf("exit...\n");
    close(sock);
    return 0;
}
