#include "../include/apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

/*
 *文件、目录创建屏蔽紫
 * #include <sys/stat.h>
 * mode_t umask(mode_t cmask);
 * cmask 为S_IRUSR 、S_IWUSR 、S_IXUSR 、S_IRGRP 、S_IWGRP 、S_IXGRP 、S_IROTH 、S_IWOTH 、S_IXOTH的或值组合, 给定位则拒绝该位权限。
 * cmask 为 0 则不屏蔽。
 */
int main(void){
	umask(0);
	if (creat("foo", RWRWRW) < 0)
		err_sys("creat error for foo");
	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if(creat("bar", RWRWRW) < 0)
		err_sys("creat error for bar");
	exit(0);
}