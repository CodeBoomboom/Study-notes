#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
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
    char *p = NULL;
    int fd;

    fd = open("testmap", O_RDWR|O_CREAT|O_TRUNC, 0644);     // 创建文件用于创建映射区
    if (fd == -1)
        sys_err("open error");
/*
    lseek(fd, 10, SEEK_END);            // 两个函数等价于 ftruncate()函数
    write(fd, "\0", 1);
*/
    ftruncate(fd, 20);                  // 需要借助写权限,才能够对文件进行拓展
    int len = lseek(fd, 0, SEEK_END);

    p = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) {
        sys_err("mmap error");
    }

    // 使用 p 对文件进行读写操作.
    strcpy(p, "hello mmap");            // 写操作

    printf("----%s\n", p);              // 读操作

    int ret = munmap(p, len);           // 释放映射区
    if (ret == -1) {
        sys_err("munmap error");
    }

	return 0;
}
