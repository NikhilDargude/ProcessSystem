#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include"sharedfile.h"


int main()
{
	int iNo1 = 0,iNo2 = 0, Ans = 0;
	void *ptr = NULL;
	int (*fptr1)(int, int);

	ptr = dlopen("./library.so", RTLD_LAZY);
	if(ptr == NULL)
	{
		printf("Unable to load librabry\n");
		return-1;
	}

	printf("Enter your two number\n");
	scanf("%d%d", &iNo1,&iNo2);


	fptr1 = dlsym(ptr, "Addition");
	if(fptr1 == NULL)
	{
		printf(" fptr1 Unable to load the address of function\n");
		return -1;
	}
	
	Ans = fptr1(iNo1,iNo2);
	printf("Addition Ans is %d\n", Ans);	

	fptr1 = dlsym(ptr, "Subtraction");
	if(fptr1 == NULL)
	{
		printf("Sun Unable to load the address of function\n");
		return -1;
	}

	Ans = fptr1(iNo1,iNo2);
	printf("Subtraction is %d\n", Ans);


	fptr1 = dlsym(ptr, "Divison");
	if(fptr1 == NULL)
	{
		printf("Sun Unable to load the address of function\n");
		return -1;
	}

	Ans = fptr1(iNo1,iNo2);
	printf("Divison is %d\n", Ans);


	fptr1 = dlsym(ptr, "Multiplicatioin");
	if(fptr1 == NULL)
	{
		printf("Sun Unable to load the address of function\n");
		return -1;
	}

	Ans = fptr1(iNo1,iNo2);
	printf("Multiplicatioin is %d\n", Ans);


	return 0;
}