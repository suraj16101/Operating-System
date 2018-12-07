
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

             
static char receive[256];   

int main(){
   int ret, fd;
   

   fd = open("/dev/decdev", O_RDWR);             
   if (fd >=0){
      
   }
else
{
      return errno;
}
   char msg[256];              
  ret = write(fd, msg, strlen(msg)); 
   if (ret >= 0){
      
   }
else
{

      return errno;
}


  
}
