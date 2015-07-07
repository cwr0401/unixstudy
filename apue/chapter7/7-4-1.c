#include "../include/apue.h"

int main(int argc, char *argv[]){
	printf("argument: \n"); //打印参数
	for(int i = 0; i <= argc; i++)
	{
		printf("argv[%d]:%s\n", i, argv[i] );
	}
	printf("environ: \n");//打印环境表
	extern char **environ;
	for(int j = 0; environ[j] != '\0'; j++)
        {
                printf("%s\n", environ[j]);
        }
    printf("getenv PATH = %s\n", getenv("PATH"));
}
