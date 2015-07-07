#include "../include/apue.h"

int globalvar = 6;
char buf[] = "a write to stdout\n";

int main(void){
	int var;
	pid_t pid;

	var = 88;
	if(write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
		err_sys("write error!");
	printf("before fork\n");

	if((pid = fork()) < 0) err_sys("frok error");
	else if (pid == 0) {
		globalvar++;
		var++;
	} else {
		sleep(2);
	}

	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globalvar, var);
	if(write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
		err_sys("write error!");
	exit(0);
}