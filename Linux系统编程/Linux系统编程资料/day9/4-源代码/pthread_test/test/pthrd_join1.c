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
    return (void *)74;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    int *retval;

    int ret = pthread_create(&tid, NULL, tfn, NULL);
    if (ret != 0)
        sys_err("pthread_create error");

    ret = pthread_join(tid, (void **)&retval);
    if (ret != 0)
        sys_err("pthread_join error");
    
    printf("child thread exit with %d\n", (void *)retval);

    pthread_exit(NULL);
}
