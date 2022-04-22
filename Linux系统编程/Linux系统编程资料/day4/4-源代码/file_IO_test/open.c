#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char buf[64];
    int ret = 0;

    fd = open("./file.txt", O_RDONLY);
    if (fd == -1) {
        printf("open file error\n");
        exit(1);
    }
    printf("---open ok---\n");

    while((ret = read(fd, buf, sizeof(buf)))) {
        write(1, buf, ret);
    }

    close(fd);

    return 0;
}
