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
    int server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    server_addr.sin_port = htons(8080);

    bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    listen(server_sock, 50);

    int client_sock;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char msg[512+1];
    while(1){
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        int cnt = read(client_sock, msg, 512);
        msg[cnt] = '\0';
        if(!strcmp(msg, "exit")){
            printf("close...\n");
            close(client_sock);
            break;
        }
        printf("recv&send: %s\n", msg);
        write(client_sock, msg, cnt);
    }

    close(server_sock);
    return 0;
}
