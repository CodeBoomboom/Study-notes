// 回收 多个子进程
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
    pid_t pid, wpid;
    int i;

    for (i = 0; i < 10; i++) {
        pid = fork();
        if (pid == 0) {
            break;
        }
    }

    if (i == 10) {
#if 0
        sleep(1);
        while ((wpid = waitpid(-1, NULL, WNOHANG))) {     //非阻塞方式回收
            if (wpid == 0) {
                sleep(1);
                continue;
            }
            if (wpid > 0) {
                printf("wait child pid = %d\n", wpid);
            }
            if (wpid == -1) {
                perror("waitpid error");
                break;
            }
        }
#else
        while ((wpid = waitpid(-1, NULL, 0)) > 0) {
            printf("wait child pid = %d\n", wpid);
        }
        if (wpid == -1) {
            perror("waitpid error");
            exit(1);
        }
#endif
        printf("----parent----- pid: %d\n", getpid());
    } else {
        printf("----%dth child----- pid: %d\n", i+1, getpid());
    }

	return 0;
}
