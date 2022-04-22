#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

#define N 1024

int main(int argc, char *argv[])
{
	int fd, fd_out;
	int n;
	char buf[N];

	fd = open("dict.txt", O_RDONLY);
	if(fd < 0){
		perror("open dict.txt error");
		exit(1);
	}

	fd_out = open("dict.cp", O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if(fd < 0){
		perror("open dict.cp error");
		exit(1);
	}

	while((n = read(fd, buf, N))){
		if(n < 0){
			perror("read error");
			exit(1);
		}
		write(fd_out, buf, n);
	}

	close(fd);
	close(fd_out);

	return 0;
}
