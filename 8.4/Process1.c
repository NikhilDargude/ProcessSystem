#include<stdio.h>
#include<sys/wait.h>

int main()
{
	int stat;

	printf("Inside process1\n");
	wait(&stat);
	
	return 0;
}