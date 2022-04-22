#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);       // 012  --- 3

    int newfd = dup(fd);    // 4

    printf("newfd = %d\n", newfd);

	return 0;
}
