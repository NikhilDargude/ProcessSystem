#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include"sharedfile.h"

int CompareFile(char file1[], char file2[])
{
	int fd = 0, fd1 = 0;
	int ret = -1 ;
	char buffer1 [1024];
	char buffer2 [1024];
	struct stat sobj1, sobj2;


	fd = open(file1,O_RDONLY);

	if(fd == -1)
	{
		printf("Unable to open first file\n");
		return -1;
	}

	fd1 = open(file2, O_RDONLY);

	if(fd1 == -1)
	{
		printf("Unable to open secound file\n");
		return -1;
	}

	fstat(fd, &sobj1);
	fstat(fd1, &sobj2);

	printf("Size is sobj1 %ld:\n", sobj1.st_size);
	printf("Size is sobj2 %ld:\n", sobj2.st_size);


	if(sobj1.st_size == sobj2.st_size)
	{
		while((ret = read(fd,buffer1,sizeof(buffer1))) != 0)
		{
			ret = read(fd1,buffer2,sizeof(buffer2));
			if(memcmp(buffer1,buffer2,ret) != 0)
			{
				break;
			}
		}
	}
	else
	{
		printf("Both file are deffrant becouse size is not same\n");
		return -1;
	}


	if(ret == 0)
	{
		printf("Both file is same\n");
	}

	return ret;
}