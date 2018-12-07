#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#define _GNU_SOURCE

#define __NR_sh_task_info 314

int main(int argc, char** argv)
{
	if (argc==3) 
	{
		long l = syscall(314,argv[1],argv[2]);
		printf("%ld",l);
	}
	else
	{
		printf("Invalid arguments");
	}
	return 0;

}
