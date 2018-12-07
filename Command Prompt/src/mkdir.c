#include <string.h>
#include <limits.h>     
#include <sys/stat.h>   
#include <errno.h>

int main(int argc, char *argv[])
{	


	if(argc==3){
	
	char cwd[256];
	strcpy(cwd, argv[0]);
	strcat(cwd,argv[2]);
	int a;																					
	a=mkdir(cwd, S_IRWXU);
	if(a==0){
		printf("Directory Created");
		
	}
	else if(a==-1){
		printf("Directory already exists or Path incorrect");
	}
}
	return 0;
}
