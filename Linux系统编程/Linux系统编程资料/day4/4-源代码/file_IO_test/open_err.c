#include <unistd.h>		//read write
#include <fcntl.h>		//open close O_WRONLY O_RDONLY O_CREAT O_RDWR
#include <stdlib.h>		//exit
#include <errno.h>
#include <stdio.h>		//perror
#include <string.h>

int main(void)
{
	int fd;
#if 1
	//打开文件不存在
	fd = open("test", O_RDONLY | O_CREAT);
	if(fd < 0){
        printf("errno = %d\n", errno);
	//	perror("open test error");
        printf("open test error: %s\n" , strerror(errno));

        //printf("open test error\n");
		exit(1);
	}
#elif 0
	//打开的文件没有对应权限(以只写方式打开一个只有读权限的文件)
	fd = open("test", O_WRONLY);		//O_RDWR也是错误的
	if(fd < 0){
        printf("errno = %d\n", errno);
		perror("open test error");
        //printf("open test error\n");
		exit(1);
	}

#endif
#if 0
	//以写方式打开一个目录
	fd = open("testdir", O_RDWR);		//O_WRONLY也是错的	
	if(fd < 0){
		perror("open testdir error");
		exit(1);
	}
#endif

	return 0;
}
