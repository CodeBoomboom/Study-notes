#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int var = 100;      //全局变量

int main(void)
{
    pid_t pid;

    pid = fork(); // 创建一个子进程

    if (pid == -1) {
        perror("fork error");
        exit(1);

    } else if (pid > 0) {       // 父进程
        var = 288;              // 写操作,复制var
        printf("parent, var = %d\n", var);
        printf("I'am parent pid= %d, getppid = %d\n", getpid(), getppid());

    } else if (pid == 0) {
//        var = 200;            // 子进程写操作,复制var
        printf("I'am child pid= %d, ppid = %d\n", getpid(), getppid());
        printf("child, var = %d\n", var);       // 读操作,共享
    }

    printf("------------finish---------------\n");

    return 0;
}
