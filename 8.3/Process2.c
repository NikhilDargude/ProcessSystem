#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>



int main(int argc , char *argv[])
{
	int ret = 0;
	char filename[20];
	DIR * dp = NULL;
	struct stat sobj;
	struct dirent * entry = NULL;

	printf("in side process 2\n");

	dp = opendir(argv[0]);
	if(dp == NULL)
	{
		printf("unable to open directory\n");
		return -1;
	}

	while((entry = readdir(dp)) != NULL)
	{
		strcpy(filename, entry->d_name);
		stat(filename,&sobj);

		if(S_ISREG(sobj.st_mode))
		{
			if(sobj.st_size < 0)
			{
				remove(filename);
				printf("Deleted file name is-: %s", filename);
			}
		}
	}

	printf("Return to process 2\n");
	closedir(dp);

	return 0;
}