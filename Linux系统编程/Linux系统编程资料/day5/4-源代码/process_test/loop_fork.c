#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
    int i;
    pid_t pid;

    for (i = 0; i < 5; i++) {       
        if (fork() == 0)        // 循环期间, 子进程不 fork
            break;
    }
    if (5 == i) {       // 父进程, 从 表达式 2 跳出
        sleep(5);
        printf("I'm parent \n");
    } else {            // 子进程, 从 break 跳出
        sleep(i);
        printf("I'm %dth child\n", i+1);
    }

    return 0;
}
