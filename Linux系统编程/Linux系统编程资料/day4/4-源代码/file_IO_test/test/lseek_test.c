#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDWR);
    if (fd == -1)
    {
        perror("open error");
        exit(1);
    }

    int lenth = lseek(fd, 110, SEEK_END);
    printf("file size:%d\n", lenth);
    
    write(fd, "\0", 1);

    close(fd);

	return 0;
}
