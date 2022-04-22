#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();             // 创建子进程
    if (pid == -1) {
        perror("fork error");
        exit(1);

    } else if (pid == 0) {          // 子进程
        //execlp("ls", "-l", "-d", "-h", NULL);         错误写法
        //execlp("ls", "ls", "-l", "-h", NULL);    
        //execlp("date", "date", NULL);    

//        execl("./a.out", "./a.out", NULL);
        //execl("/bin/ls", "ls", "-l", NULL);

        char *argv[] = {"ls", "-l", "-h", NULL};

        execvp("ls", argv);
        
        perror("exec error");
        exit(1);
    
    } else if (pid > 0) {           // 父进程
        sleep(1);
        printf("I'm parent : %d\n", getpid());
    }
    
    return 0;
}
