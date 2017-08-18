#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>

#define SHM_NAME "shm.test"
#define SEM_NAME "test"
#define SHM_SIZE 1024*4

int main(void){
    int fd = shm_open(SHM_NAME, O_CREAT | O_EXCL | O_RDWR, 0644);
    if(fd == -1){
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    if(ftruncate(fd, SHM_SIZE) == -1){
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    char *data = (char *)mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(data == MAP_FAILED){
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    close(fd);

    sem_t *sem = sem_open(SEM_NAME, O_CREAT | O_EXCL | O_RDWR, 0644, 1);
    if(sem == SEM_FAILED){
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(EXIT_FAILURE);
    }else if(pid > 0){
        if(sem_wait(sem) == -1){
            perror("sem_wait");
            exit(EXIT_FAILURE);
        }

        printf("parent_proc(%d) writing now ... \n", getpid());
        for(int i=0; i<3; i++){
            sprintf(data + 5*i, "www%d ", i);
            sleep(1);
        }
        printf("parent_proc(%d) writing complete\n", getpid());

        if(sem_post(sem) == -1){
            perror("sem_post");
            exit(EXIT_FAILURE);
        }

        if(sem_close(sem) == -1){
            perror("sem_close");
            exit(EXIT_FAILURE);
        }

        if(munmap(data, SHM_SIZE) == -1){
            perror("munmap");
            exit(EXIT_FAILURE);
        }

        wait(NULL);
        if(sem_unlink(SEM_NAME) == -1){
            perror("sem_unlink");
            exit(EXIT_FAILURE);
        }
        if(shm_unlink(SHM_NAME) == -1){
            perror("shm_unlink");
            exit(EXIT_FAILURE);
        }
    }else if(pid == 0){
        usleep(3);

        printf("child_proc(%d) waiting to read ... \n", getpid());
        if(sem_wait(sem) == -1){
            perror("sem_wait");
            exit(EXIT_FAILURE);
        }

        printf("child_proc(%d) read_data: %s\n", getpid(), data);

        if(sem_post(sem) == -1){
            perror("sem_post");
            exit(EXIT_FAILURE);
        }

        if(sem_close(sem) == -1){
            perror("sem_close");
            exit(EXIT_FAILURE);
        }

        if(munmap(data, SHM_SIZE) == -1){
            perror("munmap");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
