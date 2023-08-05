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
		printf("Call Myexe\n");
		execl("./Myexe", "NULL", NULL);
	}

	wait(&stat);
	printf("finally end process start\n");

	return 0;
}
