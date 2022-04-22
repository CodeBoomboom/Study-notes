#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printset(sigset_t *ped)
{
	int i;
	for(i = 1; i < 32; i++){
		if((sigismember(ped, i) == 1)){
			putchar('1');
		} else {
			putchar('0');
		}
	}
	printf("\n");
}

int main(void)
{
	sigset_t set, oldset, ped;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
#if 0
	sigaddset(&set, SIGQUIT);
	sigaddset(&set, SIGKILL);
	sigaddset(&set, SIGSEGV);
	sigfillset(&set);
#endif
	sigprocmask(SIG_BLOCK, &set, &oldset);	

	while(1){
		sigpending(&ped);       //获取未决信号集
		printset(&ped);
		sleep(1);
	}

	return 0;
}
