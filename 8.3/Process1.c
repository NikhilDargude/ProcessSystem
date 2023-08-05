#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>



int main(int argc , char *argv[])
{
	int ret = 0;
	char filename[20];
	DIR * dp = NULL;
	struct stat sobj;
	struct dirent * entry = NULL;

	printf("in side process 1\n");
	printf("argument of zero is %s\n", argv[0]);
	printf("argument of onec is %s\n", argv[1]);

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


	    printf("File name : %s\n",filename);
	    printf("File size is : %ld\n",sobj.st_size);
	    printf("Number of links : %ld\n",sobj.st_nlink);
	    printf("Inode number : %ld\n",sobj.st_ino);
	    printf("File system number : %ld\n",sobj.st_dev);
	    printf("Number of blocks : %ld\n",sobj.st_blocks);

	    printf("*******************************************\n");

	}

	printf("Return to process 3\n");
	closedir(dp);

	return 0;
}