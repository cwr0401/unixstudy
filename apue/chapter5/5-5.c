#include "../include/apue.h"

int	main(int argc, char *argv[]){
	if(argc != 3) err_quit("usage: 5-5.out <directry> <prefix>");

	printf("%s\n", tempnam(argv[1][0] != ' ' ? argv[1] : NULL, argv[2][0] != ' ' ? argv[1] : NULL));
	exit(0);
}