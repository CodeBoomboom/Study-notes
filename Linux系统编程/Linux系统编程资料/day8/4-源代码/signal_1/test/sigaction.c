#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}

void sig_catch(int signo)                   // 回调函数
{
    if (signo == SIGINT) {
        printf("catch you!! %d\n", signo);
        sleep(10);
    }
    /*
    else if (signo == SIGQUIT)
        printf("-----------catch you!! %d\n", signo);
    */
    return ;
}

int main(int argc, char *argv[])
{
    struct sigaction act, oldact;

    act.sa_handler = sig_catch;         // set callback function name       设置回调函数
    sigemptyset(&(act.sa_mask));        // set mask when sig_catch working. 清空sa_mask屏蔽字, 只在sig_catch工作时有效
    sigaddset(&act.sa_mask, SIGQUIT);
    act.sa_flags = 0;                   // usually use.                     默认值
    
    int ret = sigaction(SIGINT, &act, &oldact);     //注册信号捕捉函数
    if (ret == -1)
        sys_err("sigaction error");
//    ret = sigaction(SIGQUIT, &act, &oldact);     //注册信号捕捉函数

    while (1);

	return 0;
}
