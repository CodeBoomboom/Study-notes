// 指定一个进程回收
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
    pid_t pid, wpid, tmpid;
    int i;

    for (i = 0; i < 10; i++) {
        pid = fork();
        if (pid == 0) {
            break;
        }
        if (i == 6) {
            tmpid = pid;
        }
    }

    if (i == 10) {
        sleep(1);

        wpid = waitpid(tmpid, NULL, WNOHANG);
        printf("wait child id: %d\n", wpid);
        
        printf("----parent----- pid: %d\n", getpid());
    } else {
        printf("----%dth child----- pid: %d\n", i+1, getpid());
    }

	return 0;
}
