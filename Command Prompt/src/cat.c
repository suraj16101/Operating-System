#include<stdio.h>
#include<string.h>

int main(int argc , char *argv[])
{
	
	char str[200];
    strcpy(str,argv[2]);
   	
   	
	
   	char split[5][20]={0};
    int i=0,j=0,kk=0;
    for(i=0;i<strlen(str);i++)
	{
        if(str[i]==' ')
		{
            if(str[i+1]!=' ')
			{
                split[kk][j]='\0';
                j=0;
                kk++;
            }
            continue;
        }
        else
		{
            split[kk][j++]=str[i];
        }       
    }
    
    split[kk][j]='\0';
    int ctr =kk;
	char* position = strchr(str, '>');
	char* position1 = strchr(str, '>>');
	
	if (position == NULL && position1 == NULL )
	{
		
		
			int l=0;
			while ( l<=ctr)
		{
			FILE *fptr1;
   			fptr1 = fopen(split[l],"r");

   			if (fptr1 == NULL)
		    {
       		printf("Error");
       		exit(1);
   			}	
			l++;
			char ch = fgetc(fptr1);
    		while (ch != EOF)
    		{
        	printf("%c", ch);
        	ch = fgetc(fptr1);
    		}
    		fclose(fptr1);
    		
		}
		
		
		
	}
	else
	{
		int k=0;
		while ( k<=ctr)
		{
		
		if (strcmp(split[k],">>")==0)
		
		{
			FILE *f;
   			f=fopen(split[k+1],"a");
   			if(f==NULL)
	   		{
			printf("Error");
			exit(1);
			}		
			fprintf(f,"\n");	
			
			int j=0;
			while (j<k )
			{
				FILE *fptr;
   				fptr = fopen(split[j],"r");

   				if (fptr == NULL)
		    	{
       			printf("Error");
       			exit(1);
   				}	
				j++;
				char ch = fgetc(fptr);
    			while (ch != EOF)
    			{
        		fprintf(f,"%c",ch);
        		ch = fgetc(fptr);
    			}
    			fclose(fptr);
			}
			

   			fclose(f);
   			
			
		}
		else if (strcmp(split[k],">")==0)
		{
			FILE *f;
   			f=fopen(split[k+1],"w");
   			if(f==NULL)
	   		{
			printf("Error");
			exit(1);
			}			
			
			int j1=0;
			while ( j1<k )
			{
				FILE *fptr;
   				fptr = fopen(split[j1],"r");

   				if (fptr == NULL)
		    	{
       			printf("Error");
       			exit(1);
   				}	
				j1++;
				char ch = fgetc(fptr);
    			while (ch != EOF)
    			{
        		fprintf(f,"%c",ch);
        		ch = fgetc(fptr);
    			}
    			fclose(fptr);
    			
			}
			

   			fclose(f);
				
   		}
   		
		
		
	
		k++;
		
	 
	}
	}
	
	
	
	return 0;
	
}
