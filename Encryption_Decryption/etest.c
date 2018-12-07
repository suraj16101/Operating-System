
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

             
static char receive[256];   

int main(){
   int ret, fd;
   

   fd = open("/dev/encdev", O_RDWR);             
   if (fd >=0){
      
   }
else
{
      return errno;
}
   printf("Enter file to be encrypted:\n");
   char msg[256];
   scanf("%[^\n]%*c", msg);              
  ret = write(fd, msg, strlen(msg)); 
   if (ret >= 0){
      
   }
else
{

      return errno;
}


  
}
