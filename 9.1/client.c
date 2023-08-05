#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/stat.h>


int main()
{
	int ret = 0;
	int fd = 0, fd1 = 0;
	char filename[20];
	DIR * dp = NULL;
	struct stat sobj;
	struct dirent * entry = NULL;

	dp = opendir("/home/nikhil/Desktop");

	if(dp == NULL)
	{
		printf("Unable to open directory\n");
		return -1;
	}

	fd1 = creat("Demo1.txt", 0777);

	if(fd1 == -1)
	{
		printf("Unable to create file\n");
		return -1;
	}

	fd = open("Demo1.txt", O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}

	while((entry =  readdir(dp)) != NULL)
	{
		strcpy(filename, entry->d_name);
		write(fd,&filename,sizeof(filename));
		printf("%s\n",filename);
	}

	closedir(dp);
	close(fd);
	return 0;

}