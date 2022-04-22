#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
    //open/lseek(fd, 249, SEEK_END)/ write(fd, "\0", 1);

    int ret = truncate("dict.cp", 250);

    printf("ret = %d\n", ret);

	return 0;
}
