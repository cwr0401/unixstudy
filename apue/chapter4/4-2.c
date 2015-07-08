#include "../include/apue.h"
#include <fcntl.h>
/*
 * 测试文件的读写权限
 * #include <unistd.h>
 * int access(const char *pathname, int mode);
 * pathname: 文件路径名，绝对路径，相对路径
 * mode:
 *		F_OK   测试文件是否存在
 *		R_OK   测试读权限
 *	 	W_OK   测试写权限
 *	 	X_OK   测试执行权限
 */
int main(int argc, char *argv[]){
	if ( argc != 2)
		err_quit("useage: 4-2.out <pathname>");

	if (access(argv[1], R_OK) < 0)
		err_ret("access error for %s", argv[1]);
	else
		printf("read access OK\n");

	if (open(argv[1], O_RDONLY) < 0)
		err_ret("open error for %s", argv[1]);
	else
		printf("open for reading OK\n");
	exit(0);
}