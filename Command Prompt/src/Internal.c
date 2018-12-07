#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void) 
{
	int f=0;
	char y[10]="/";
	char s[100]="/mnt/c/Users/HP/";
	char s1[100]="/mnt/c/Users/HP/";
	while(f==0){
	printf("%s",s1);
	
	char str[100];
	gets(str);

	FILE *fptr;
	fptr=fopen("histfile.txt","a");
	if(fptr==NULL)
	{
		printf("Error");
		exit(1);
	}
	fprintf(fptr,"%s\n",str);
	fclose(fptr);
	
    char split[5][20]={0};
    int i=0,j=0,k=0;
    for(i=0;i<strlen(str);i++)
	{
        if(str[i]==' ')
		{
            if(str[i+1]!=' ')
			{
                split[k][j]='\0';
                j=0;
                k++;
            }
            continue;
        }
        else
		{
            //copy other characters
            split[k][j++]=str[i];
        }       
    }
    //char *gg="echo";
    split[k][j]='\0';
    char *sx="";
    sx=split[0];
    char* options[] = {"echo","exit","cd","history","pwd","date","ls","mkdir","rm","cat"};
    int hello=-1;
    int jk=0;
    for(jk=0;jk<10;jk++)
	{
    	if(strcmp(options[jk],sx)==0)
		{
    		hello=jk;
		}
	}
	strcat(sx," ");
	char v[100000];
   	int aa=0;
   	for(aa=1;aa<=k;aa++)
    	{
    		strcat(v,split[aa]);
   			strcat(v," ");
		}
		
	char v1[100000];
   	int aa1=0;
 	for(aa1=1;aa1<=k;aa1++)
  		{
  		strcat(v1,split[aa1]);
		}
	char v2[100000];
	strcpy(v2,v);
	v2[strlen(v2)-1]= '\0';

    switch(hello)
	{
    	
    	case 0://echo
		{
			printf("%s",v);
    		break;
		}
		
    		
    	case 1://exit
		{
    		f=1;
			break;
		}
		
		case 2://cd
		{
			if(strcmp(v1,"-")==0)
			{
				char pp[200];
				strcpy(pp,s);
				pp[strlen(pp)-1]='\0';
				char *ptr;
				int yas='/';
				ptr=strrchr(pp,yas);
				int index=ptr-pp;
				char *sss=pp;
				int as=0;
				as=strlen(sss)-(index+1);
				sss[strlen(sss)-as]='\0';
			
				
				if(strcmp(sss,"/mnt/")==0)
				{
					
				}
				else
				{
				const char *path=sss;
				int ko=chdir(path);
				
				strcpy(s,sss);
				strcpy(s1,sss);
				}
				
				
			}
			else if(strcmp(v1,"..")==0)
			{
				char aa1[100]="/mnt/c/Users/HP/";
				const char *path=aa1;
				chdir(path);
				strcpy(s,aa1);
				strcpy(s1,aa1);	
			}
			else if(strlen(v1)!=0)
			{
				strcat(s,v1);
				strcat(s,y);
				const char *path=s;
				int ko=chdir(path);
				if(ko==-1)
				{
					printf("The system cannot find the path specified.");	
				}
				else if(ko==0)
				{
					strcat(s1,v1);
					strcat(s1,y);	
				}
				strcpy(s,s1);
			}
			
			break;	
		}
		
		case 3://history
		{
			
			if(strcmp(v1,"-c")==0)
			{
				FILE *fpt1;
				fpt1=fopen("histfile.txt","w");
				fprintf(fpt1,"%s\n","");
				fclose(fpt1);
			}
			else
			{
			
			FILE *fpt1;
			fpt1=fopen("histfile.txt","r");
			if(fpt1 ==NULL)
			{
				printf("Error");
				exit(1);	
			}
			char ch=fgetc(fpt1);
			while(ch!= EOF)
			{
				printf("%c",ch);	
				ch=fgetc(fpt1);
			}
			fclose(fpt1);
			}
			break;
		}
		
		
		case 4://pwd
		{
			char ns[200];
			strcpy(ns,s1);
			ns[strlen(ns)-1]='\0';
			printf("%s",ns);
			break;
		}
		
		case 5://date
		{	
			if(strlen(v1)==0){
			pid_t pid;
			pid= fork();
			char *a[100]={"date"};
			if(pid==0){
			execl("/mnt/c/Users/HP/Desktop/Os/2016101/src/date","sadas",a,NULL);		
			}
			else if(pid<0){
				//fork fail
			}
			else {
				wait(NULL);
			}
			}
			else{
			pid_t pid;
			pid= fork();
			char *a[100]={"date"};
			if(pid==0){
			execl("/mnt/c/Users/HP/Desktop/Os/2016101/src/date",a,a,v1,NULL);		
			}
			else if(pid<0){
				//fork fail
			}
			else {
				wait(NULL);
			}


			}
			break;

		}
		case 6: //ls
		{	if(strlen(v1)==0){
			pid_t pid;
			pid= fork();
			char *a[100]={"ls"};
			if(pid==0){
			execl("/mnt/c/Users/HP/Desktop/Os/2016101/src/ls",s1,a,NULL);		
			}
			else if(pid<0){
				//fork fail
			}
			else {
				wait(NULL);
			}
			}
			else{
			pid_t pid;
			pid= fork();
			char *a[100]={"ls"};
			if(pid==0){
			execl("/mnt/c/Users/HP/Desktop/Os/2016101/src/ls",s1,a,v1,NULL);		
			}
			else if(pid<0){
				//fork fail
			}
			else {
				wait(NULL);
			}
			}
			break;
		}
		case 7://mkdir
			{
				pid_t pid;
				pid= fork();
				char *a[100]={"mkdir"};
				if(pid==0){
				execl("/mnt/c/Users/HP/Desktop/Os/2016101/src/mkdir",s1,a,v1,NULL);		
			}
			else if(pid<0){
				//fork fail
			}
			else {
				wait(NULL);
			}
			break;
			}
		case 8://rm
		{
				pid_t pid;
				pid= fork();
				char *a[100]={"rm"};
				if(pid==0){
				execl("/mnt/c/Users/HP/Desktop/Os/2016101/src/rm",s1,a,v1,NULL);		

			}
			else if(pid<0){
				//fork fail
			}
			else {
				wait(NULL);
			}
			break;
		}
		case 9://cat
		{
			pid_t pid;
				pid= fork();
				char *a[100]={"cat"};
				if(pid==0){
					execl("/mnt/c/Users/HP/Desktop/Os/2016101/src/cat",s1,a,v2,NULL);	
			}
			else if(pid<0){
				//fork fail
			}
			else {
				wait(NULL);
			}
			break;
		
		}
    		
    	default :
			printf("'%s' is not recognized as an internal or external command,operable program or batch file.",str)	;
	}
	strcpy(v,""); 
	strcpy(v1,""); 
	int oy=0;
	while(oy<=k)
	{
		strcpy(split[oy],"");
		oy++;
	}
	printf("\n");
}
    


	return 0;
}


