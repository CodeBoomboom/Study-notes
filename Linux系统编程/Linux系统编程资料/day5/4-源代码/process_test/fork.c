#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
    printf("before fork-1-\n");     // 在fork之前打印,父进程执行,只执行一次
    printf("before fork-2-\n");
    printf("before fork-3-\n");
    printf("before fork-4-\n");

    pid_t pid = fork();             // 创建子进程
    if (pid == -1) {
        perror("fork error");
        exit(1);

    } else if (pid == 0) {          // 子进程
        
        printf("---child is created\n");

    } else if (pid > 0) {           // 父进程

        printf("---parent process: my child is %d\n", pid);
    }
    
    printf("===================end of file\n");  // 父子进程各自执行一次.

    return 0;
}
