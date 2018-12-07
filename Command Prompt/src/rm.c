#include <stdio.h>
#include <dirent.h>
int  main(int argc, char *argv[])
{
        struct dirent *d;
        DIR *dir;
        char buf[256];
        dir = opendir(argv[0]);
        if (argc ==3)
        {
                if (strcmp(argv[2],"*")==0)
                {
                      while(d = readdir(dir))
        {               
                sprintf(buf, "%s/%s", argv[0], d->d_name);
                 if (remove(buf)==0)
                {
                         printf("Deleted.");
                                
                }       
        }  
                }
                else if (remove(argv[2])==0)
        	{
        	       printf("Deleted.");
		}


	}
	
        
        return 0;

}
