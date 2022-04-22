#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

void sys_err(char *str)
{
    perror(str);
    exit(1);
}

int main(int argc, char *argv[])
{
    int fd, len;
    char buf[4096];

    if (argc < 2) {
        printf("./a.out fifoname\n");
        return -1;
    }
    //int fd = mkfifo("testfifo", 644);
    //open(fd, ...);
    fd = open(argv[1], O_RDONLY);   // 打开管道文件
    if (fd < 0) 
        sys_err("open");
    while (1) {
        len = read(fd, buf, sizeof(buf));   // 从管道的读端获取数据
        write(STDOUT_FILENO, buf, len);
        sleep(3);           //多個读端时应增加睡眠秒数,放大效果.
    }
    close(fd);

    return 0;
}
