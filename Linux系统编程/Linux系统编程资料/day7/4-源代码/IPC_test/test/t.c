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

    int fd = open("test", O_RDWR|O_CREAT|O_TRUNC, 0666);
    if (fd == -1)
        sys_err("open err");

    pid_t pid = fork();




	return 0;
}
