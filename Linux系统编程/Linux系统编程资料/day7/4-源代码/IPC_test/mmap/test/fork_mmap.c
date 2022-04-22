#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>

int var = 100;

int main(void)
{
    int *p;
    pid_t pid;

    int fd = open("/dev/zero", O_RDWR);

    //p = (int *)mmap(NULL, 40, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    p = (int *)mmap(NULL, 490, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    //p = (int *)mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
    if(p == MAP_FAILED){		//注意:不是p == NULL
        perror("mmap error");
        exit(1);
    }
    close(fd);

    pid = fork();				//创建子进程
    if(pid == 0){
       *p = 7000;               // 写共享内存
        var = 1000;
        printf("child, *p = %d, var = %d\n", *p, var);
    } else {
        sleep(1);
        printf("parent, *p = %d, var = %d\n", *p, var);     // 读共享内存
        wait(NULL);

        int ret = munmap(p, 4);				//释放映射区
        if (ret == -1) {
            perror("munmap error");
            exit(1);
        }
    }

    return 0;
}
