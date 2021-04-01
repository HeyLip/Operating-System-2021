#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int 
main(int argc, char* argv[]){

	int i;
	int arr[argc];

	sleep(1);
	printf("argc = %d \n", argc);

	for(i = 0; i <argc; i++)
	{
		printf("argv[%d] = %d \n", i, atoi(argv[i]));
		arr[i-1] = atoi(argv[i]);
	}

	printf("\n");
	return 0;

}
