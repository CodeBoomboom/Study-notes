/*
 *./mycp src dst 命令行参数实现简单的cp命令
 */
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char buf[1024];

int main(int argc, char *argv[])
{
	int src, dst;
	int n;

	src = open(argv[1], O_RDONLY); //只读打开源文件
	if(src < 0){
		perror("open src error");
		exit(1);
	}
	//只写方式打开，覆盖原文件内容，不存在则创建，rw-r--r--
	dst = open(argv[2], O_WRONLY|O_TRUNC|O_CREAT, 0644);
	if(src < 0){
		perror("open dst error");
		exit(1);
	}
	while((n = read(src, buf, 1024))){
		if(n < 0){
			perror("read src error");
			exit(1);
		}
		write(dst, buf, n);  //不应写出1024, 读多少写多少
	}

	close(src);
	close(dst);

	return 0;
}
