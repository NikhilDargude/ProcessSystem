#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include"sharedfile.h"


void DisplayFileDetails(char FileName[])
{
	struct stat sobj;

	stat(FileName,&sobj);

	printf("File name : %s\n",FileName);
    printf("File size is : %ld\n",sobj.st_size);
    printf("Number of links : %ld\n",sobj.st_nlink);
    printf("Inode number : %ld\n",sobj.st_ino);
    printf("File system number : %ld\n",sobj.st_dev);
    printf("Number of blocks : %ld\n",sobj.st_blocks);
}
