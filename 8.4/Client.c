#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>


int main()
{
	int ret1 = 0;
	int ret2 = 0;
	int stat1, stat2;
	printf("Inside main process\n");

	ret1 = fork();

	if(ret1 == 0)
	{
		execl("./Process1", "NULL", NULL);
	}

	wait(&stat1);

	ret2 = fork();

	if(ret2 == 0)
	{
		execl("./Process2", "NULL", NULL);
	}

	wait(&stat2);

	printf("Terminet main process\n");

	return 0;

}