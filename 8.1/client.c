#include<stdio.h>
#include"sharedfile.h"


int main()
{
	char filename[20];

	printf("Enter your file name\n");
	scanf("%s",filename);

	DisplayFileDetails(filename);

	return 0;
}