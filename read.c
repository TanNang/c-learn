#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

#define FILENAME "shm"
#define MAXSIZE 1024*4

int main(void){
    int fd = shm_open(FILENAME, O_RDWR, 0);
    if(fd == -1){
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    if(ftruncate(fd, MAXSIZE) == -1){
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    char *data = (char *)mmap(NULL, MAXSIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(data == MAP_FAILED){
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    close(fd);

    printf("data: %s\n", data);

    if(munmap(data, MAXSIZE) == -1){
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    if(shm_unlink(FILENAME) == -1){
        perror("shm_unlink");
        exit(EXIT_FAILURE);
    }

    return 0;
}
