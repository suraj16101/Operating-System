#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    if (argc==2)
    {
    printf("%s\n", asctime(tm));	
	}
    
    
    char str[200];
    strcpy(str,asctime(tm));
    
    char newString[10][10]={0};
   	
   	int j=0,ctr=0,i=0;
   	for (i=0;i<(strlen(str)); i++)
   	{
   		if(str[i]==' '||str[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;  
            j=0;    
        }
        else
        {
            newString[ctr][j]=str[i];
            j++;
        }
	}
	if(argc==3)
{
	if(strcmp(argv[2],"%a")==0){
	//%a gives shortform of weekday
	char *weekday ;
	weekday= newString[0];
	
	printf("Weekday : %s\n",weekday);
	}

	if(strcmp(argv[2],"%x")==0){
		//%x gives date
	char *dat ;
	dat= newString[2];
	
	printf("Date : %s\n",dat);	
	}
	
	
	if(strcmp(argv[2],"%D")==0){
	
   //%D date and time
    time_t t1 = time(NULL);
    struct tm1 *tm1 = localtime(&t);
    char s[64];
    strftime(s, sizeof(s), "%c", tm1);
    printf("Date and time : %s\n", s);
}
}
    

    
    return 0;
}
