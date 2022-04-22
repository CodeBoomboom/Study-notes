#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void sys_err(const char *str)
{
    perror(str);
    exit(1);
}
int main(int argc, char *argv[])
{
    int fd[2];
    int ret, i;
    pid_t pid;

    ret = pipe(fd);
    if (ret == -1) {
        sys_err("pipe error");
    }

    for(i = 0; i < 2; i++) {        // 表达式2 出口,仅限父进程使用
        pid = fork();
        if (pid == -1) {
            sys_err("fork error");
        } 
        if (pid == 0)               // 子进程,出口
            break;
    } 

   if (i == 2) {                    // 父进程 . 不参与管道使用. 
        close(fd[0]);               // 关闭管道的 读端/写端.
        close(fd[1]);

        wait(NULL);                 // 回收子进程
        wait(NULL);
    } else if (i == 0) {  // xiong
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);     // 重定向stdout
        execlp("ls", "ls", NULL);
        sys_err("exclp ls error");
    } else if (i == 1) {            //弟弟
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);      // 重定向 stdin
        execlp("wc", "wc", "-l", NULL);
        sys_err("exclp wc error");
    }
    
    return 0;
}
