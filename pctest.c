#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int
main(int argc, char * argv[]){

	pid_t target_pid, solution_pid;
	
	char num[10];
	char num1[10];
	char num2[10];
	char num3[10];
	char num4[10];

	int time = atoi(argv[2]);
	
	FILE * pfile = fopen(argv[1], "r");
	if(pfile == NULL){
		printf("file open: error \n");
		exit(0);
	}
	else{
	
		
		fscanf(pfile, "%s", num);
		fscanf(pfile, "%s", num1);
		fscanf(pfile, "%s", num2);
		fscanf(pfile, "%s", num3);
		fscanf(pfile, "%s", num4);
		printf("%s %s %s %s %s \n", num, num1, num2, num3, num4);

		fclose(pfile);
	}

	printf("input: %s, time: %d, object: %s, object1: %s \n \n", argv[1], time, argv[3], argv[4]);
	

	target_pid = fork();

	if(target_pid == 0){

		execl(argv[3], num, num1, num2, num3, num4, (char *) 0x0);
	}
	else {

		solution_pid = fork();
		if(solution_pid == 0) {

			execl(argv[4], num, num1, num2, num3, num4, (char *) 0x0);
		}
		else {
			pid_t term_pid;
			int exit_code;

			term_pid = wait(&exit_code);
			term_pid = wait(&exit_code);
		}


	}
}
