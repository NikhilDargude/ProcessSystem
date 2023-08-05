#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>


int main()
{
	int ret = -1;
	char file1[20], file2[20];
	void *ptr = NULL;
	int (*fptr)(char file1[], char file2[]);


	ptr = dlopen("./library.so",RTLD_LAZY);
	if(ptr == NULL)
	{
		printf("Unable to load library\n");
		return -1;
	}

	fptr = dlsym(ptr, "CompareFile");
	if(fptr == NULL)
	{
		printf("Unable to load the address of function\n");
		return -1;
	}

	printf("Enter File name to com[pare\n");
	scanf("%s%s", file1, file2);

	fptr(file1, file2);

	return 0;
}