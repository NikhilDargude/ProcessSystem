#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/resource.h>

int main(void)
{
	int ret = 0;


	ret = getpriority(PRIO_PROCESS,0);

	printf(" Current Priority of Process is %d\n", ret);

	ret = nice(5);

	printf(" change Priority of Process is %d\n", ret);



	return 0;
}