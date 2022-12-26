#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 #include <fcntl.h>
 #include<sys/stat.h>


FILE* getFile()
{
    FILE* fPtr;
    char ch;
    fPtr = fopen("deadXam", O_RDWR);
    if (fPtr == NULL) {
        printf("Unable to open file.\n");
        printf("Please check whether file exists\n");
        exit(EXIT_FAILURE);
    }
    printf("File opened successfully\n");
    return fPtr;
}

int main()
{

    int counter = 0;

    const unsigned MAX_LENGTH = 256;
    char rbuffer[MAX_LENGTH];
    char wbuffer[MAX_LENGTH];

    FILE* fptr = getFile();
    int status;

    int fd[2], n;
    pid_t p;
    pipe(fd);
    p = fork();
    if (p > 0) {
        char ch;
        while (fgets(wbuffer, MAX_LENGTH, fptr)) {
            write(fd[1], wbuffer, MAX_LENGTH);
            close(fd[0]);
        }
        close(fd[1]);

        fclose(fptr);
        wait(&status);
    } else // child
    {
        int lenCnt = 0;
        do {
            close(fd[1]);

            n = read(fd[0], rbuffer, MAX_LENGTH);

            do {
                if (rbuffer[lenCnt] == 's') {
                    counter++;
                } else if (rbuffer[lenCnt] == '\n') {
                    break;
                }
                lenCnt++;
            } while (lenCnt < n);
            lenCnt = 0;
        } while (n > 0);

        close(fd[0]);

        printf("Total number of s %d\n", counter);
        exit(EXIT_FAILURE);
    }
}