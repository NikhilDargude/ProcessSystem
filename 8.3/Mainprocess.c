#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/wait.h>
#include<string.h>


int main()
{
	int ret = 0;
	char dir[20];
	int stat1,stat2,stat3;

	printf("start Process 0\n");

	ret = fork();

	if(ret == 0)
	{
		execl("./Process1", "Demo",NULL);
	}

	wait(&stat1);

	ret = fork();

	if(ret == 0)
	{
		execl("./Process2", "Demo",NULL);
	}

	wait(&stat2);

	ret = fork();

	if(ret == 0)
	{
		execl("./Process3", "Demo",NULL);
	}

	wait(&stat3);

	printf("End all Process\n");
	return 0;

}