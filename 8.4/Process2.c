#include<stdio.h>
#include<sys/wait.h>

int main()
{
	int stat;

	printf("Inside process2\n");
	wait(&stat);

	return 0;
}