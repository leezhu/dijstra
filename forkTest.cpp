/*
 *fork函数是建立子进程，对原来进程的克隆
 *
 */

#include<unistd.h>
#include<stdio.h>

int main()
{
	pid_t fpid;//fpid表示fork函数返回的值

	int count=0;
	fpid=fork();

	if(fpid<0)
		printf("error in fork");
	else if(fpid==0)	//相当于链表，子进程没有下面的子进程，因此返回0
	{
		printf("子进程，pid=%d\n",getpid());
		count++;
	}
	else
	{
		printf("父进程执行的，pid=%d\n",getpid());
		count++;
	}

	printf("%d\n",count);
	return 0;
}
