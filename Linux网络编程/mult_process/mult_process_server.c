#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<unistd.h>
#include<errno.h>
#include<signal.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<ctype.h>
#include<pthread.h>
#include"wrap.h"
#include<sys/wait.h>

#define SERV_PORT 8881

void catch_child(int signum)
{
    while(waitpid(0, NULL, WNOHANG)>0);    

    return ;
}

int main(int argc, char *argv[])
{
    int lfd, cfd;   //lfd:监听套接字   cfd: 与客户端成功连接的套接字
    struct sockaddr_in serv_addr,cli_addr;  //serv_addr：服务器端(监听套接字)地址结构  cli_addr: 客户端地址结构
    socklen_t cli_addr_len; //客户端地址结构长度
    pid_t pid;  //进程pid
    char buf[BUFSIZ];
    int ret, i;

    lfd = Socket(AF_INET,SOCK_STREAM,0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    Bind(lfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    Listen(lfd,128);

    cli_addr_len = sizeof(cli_addr);
    while(1){
        cfd = Accept(lfd, (struct sockaddr *)&cli_addr, &cli_addr_len);
        pid = fork();
        if(pid < 0){
            perr_exit("fork error");
        }
        else if(pid == 0){
            close(lfd);
            break;
        }
        else{
            struct sigaction act;           //注册信号捕捉函数，信号捕捉函数中回收子进程
            act.sa_handler = catch_child;
            sigemptyset(&act.sa_mask);  //初始化阻塞信号集
            act.sa_flags =0;
            ret = sigaction(SIGCHLD,  &act, NULL);
            if(ret != 0){
                perr_exit("sigaction error");
            }
            close(cfd);
            continue;
        }
    }
    if(pid == 0){
        for(;;){
            ret = Read(cfd, buf, sizeof(buf));
            if(ret == 0){
                close(cfd);
                exit(1);
            }
            
            for(i = 0; i< ret; i++){
                buf[i] = toupper(buf[i]);
            }
            Write(cfd, buf, ret);
            Write(STDOUT_FILENO, buf, ret);
        }
    }
    return 0;

}
