#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	int ret = 0;
	int stat;

	ret = fork();

	if(ret == 0)
	{
		printf("Chaild Process runing stated\n");
		execl("./Chaild","NULL",NULL);
	}

	wait(&stat);

	printf("main process stoped\n");

	return 0;
}
