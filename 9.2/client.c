#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/resource.h>
#include<sys/wait.h>

int main(void)
{
	int stat1,stat2;
	int ret1 = 0, ret2 = 0;

	ret1 = fork();
	if(ret1 == 0)
	{
		execl("./Process1","NULL", NULL);
	}

	wait(&stat1);

	ret2 = fork();
	if(ret2 == 0)
	{
		execl("./Process2","NULL", NULL);
	}
	wait(&stat2);

	return 0;
}