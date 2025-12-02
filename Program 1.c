#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {                      // child
        printf("It is the child process and pid is %d\n", getpid());
        for (int i = 0; i < 8; i++)
            printf("%d\n", i);
        exit(0);                         // terminate child
    } 
    else if (pid > 0) {                  // parent
        printf("It is the parent process and pid is %d\n", getpid());
        wait(NULL);                      // wait for child
        printf("\nChild is reaped\n");
    } 
    else {                               // error
        perror("fork");
        exit(EXIT_FAILURE);
    }
    return 0;
}
