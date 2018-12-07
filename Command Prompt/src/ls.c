#include<sys/stat.h>
#include<dirent.h> 
 #include<stdio.h>
#include<time.h>
int main(int argc, char *argv[])
{
   DIR *dir, *dir1, *dir2;
   struct dirent *ent, *ent1, *ent2;
   char cwd[1024];
   getcwd(cwd,sizeof(cwd));
  if(argc==2)
   {
     dir = opendir(argv[0]);
     while((ent = readdir(dir)) !=NULL)
      {
	  printf("%s\t",ent->d_name);
      
    }
   close(dir);
  }
  else if(argc==3 && strcmp(argv[2],"-l")==0)
  {
    dir1 = opendir(argv[0]);
    while((ent1 = readdir(dir1)) !=NULL)
      {
      struct stat lol;
      stat (ent1->d_name,&lol);
	  printf("%s\t",ent1->d_name);
	  if(lol.st_size==0)
        printf("d");
      if(lol.st_mode & S_IREAD)
        printf("r");
      if(lol.st_mode & S_IWRITE)
        printf("w");
      if(lol.st_mode & S_IEXEC)
        printf("x");
    printf("\t%d",lol.st_size);
    printf("\t%s\n",ctime(&lol.st_ctime));
	  
    
    }
   close(dir1);
	}
  else if(argc==3 && strcmp(argv[2],"-Q")==0)
   {
     dir2 = opendir(argv[0]);
     while((ent2 = readdir(dir2)) !=NULL)
      {
	  printf("'%s'\t",ent2->d_name);
      
    }
   close(dir2);
  }
return(0);
}
