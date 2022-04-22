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

    //fd = open("testmap", O_RDWR|O_CREAT|O_TRUNC, 0644);
    //fd = open("dict.txt", O_RDWR);
    fd = open("testmap", O_RDONLY);
    if (fd == -1)
        sys_err("open error");

    //ftruncate(fd, 20);                // 需要写权限,才能拓展文件大小
    int len = lseek(fd, 0, SEEK_END);
    printf("file len = %d\n", len);

    p = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (p == MAP_FAILED) {
        sys_err("mmap error");
    }
    close(fd);

    char *tmp = p;

    // 使用 p 对文件进行读写操作.
    strcpy(tmp++, "hello mmap");            // 写操作

    printf("----%s\n", p);      

    int ret = munmap(p, len);
    if (ret == -1) {
        sys_err("munmap error");
   }


	return 0;
}
