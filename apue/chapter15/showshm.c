#include "../include/apue.h"
#include <sys/shm.h>

int main(int argc, char *argv[]){
	char *shmptr;
	if (argc != 2) 
		err_sys("Usage: showshm keynum");
	printf("%u\n", atoi(argv[1]));

	if((shmptr = shmat(atoi(argv[1]), 0, SHM_RDONLY)) == (void *)-1)
		err_sys("shmat error, shmkey:%d", argv[1]);
	printf("shmptr: %p\n", shmptr);
	for(int i = 0; i < 10; i++){
		printf("%d", shmptr[i]); 
	}	
}