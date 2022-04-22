//指定回收一个子进程错误示例
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
    int i;
    pid_t pid, wpid;

    for (i = 0; i < 5; i++) {       
        if (fork() == 0) {       // 循环期间, 子进程不 fork 
            if (i == 2) {
                 pid = getpid();
                 printf("------pid = %d\n", pid);
            }
            break;
        }
    }

    if (5 == i) {       // 父进程, 从 表达式 2 跳出
        sleep(5);

        //wait(NULL);                           // 一次wait/waitpid函数调用,只能回收一个子进程.
        //wpid = waitpid(-1, NULL, WNOHANG);    //回收任意子进程,没有结束的子进程,父进程直接返回0 
        //wpid = waitpid(pid, NULL, WNOHANG);   //指定一个进程回收
        
        printf("------in parent , before waitpid, pid= %d\n", pid);
        wpid = waitpid(pid, NULL, 0);  //指定一个进程回收
        if (wpid == -1) {
            perror("waitpid error");
            exit(1);
        }
        printf("I'm parent, wait a child finish : %d \n", wpid);

    } else {            // 子进程, 从 break 跳出
        sleep(i);
        printf("I'm %dth child, pid= %d\n", i+1, getpid());
    }

    return 0;
}
