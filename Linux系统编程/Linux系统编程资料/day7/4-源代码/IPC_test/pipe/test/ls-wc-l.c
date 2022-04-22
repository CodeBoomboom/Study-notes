#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int ret;
    pid_t pid;

    ret = pipe(fd);                 // 父进程先创建一个管道,持有管道的读端和写端
    if (ret == -1) {
        sys_err("pipe error");
    }

    pid = fork();                   // 子进程同样持有管道的读和写端
    if (pid == -1) {
        sys_err("fork error");
    } else if (pid > 0) {           // 父进程 读, 关闭写端
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);  // 重定向 stdin 到 管道的 读端
        execlp("wc", "wc", "-l", NULL);     // 执行 wc -l 程序
        sys_err("exclp wc error");
    } else if (pid == 0) {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);     // 重定向 stdout 到 管道写端
        execlp("ls", "ls", NULL);       // 子进程执行 ls 命令
        sys_err("exclp ls error");
    }

	return 0;
}
