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

void *tfn(void *arg)
{
    int i = (int)arg;           //强转.
    sleep(i);
    printf("--I'm %dth thread: pid = %d, tid= %lu\n", i+1, getpid(), pthread_self());

    return NULL;
}

int main(int argc, char *argv[])
{
    int i;
    int ret;
    pthread_t tid;

    for (i = 0; i < 5; i++) {
        ret = pthread_create(&tid, NULL, tfn, (void *)i);       // i 传参采用 值传递. 借助强转.
        if (ret != 0) {
            sys_err("pthread_create error");
        }
    }

    sleep(i);
    printf("main: I'm Main, pid = %d, tid= %lu\n", getpid(), pthread_self());

	return 0;
}
