#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>



int main(int argc , char *argv[])
{
	int del = 0;
	char filename[20];
	char Drie[30];
	int max = 1024;
	DIR * dp = NULL;
	struct stat sobj;
	struct dirent * entry = NULL;

	printf("in side process 3\n");
	strcpy(Drie , argv[0]);


	dp = opendir(Drie);
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
            if(sobj.st_size ==  0)
            {
                remove(filename);
                del++;
            }
        }
	}

	printf("Zero size file found : %d\n", del);
	printf("Return to process 3\n");
	closedir(dp);

	return 0;
}