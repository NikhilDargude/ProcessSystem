#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/resource.h>

int main(void)
{
	int fd = 0;
	char Buffer[512];
	int icnt = 0;
	int iret = 0;
	int i = 0;

	fd = open("Demo.txt", O_RDONLY);

	while((iret = read(fd, Buffer,sizeof(Buffer))) != 0)
	{
		for(i = 0; i < iret; i++)
		{
			if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
			{
				icnt++;

			}
		}
	}

	printf("Number of small charetoer are : %d\n", icnt);

	close(fd);

	return 0;
}