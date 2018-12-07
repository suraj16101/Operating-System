#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>



int main()
{

	
	
	fd_set ms;
	FD_ZERO(&ms);
	fd_set read_fds;
	FD_ZERO(&read_fds);
	int s= 0;
	

		
	int y = 1;
		
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Error : Socket");
		exit(1);
	}
	struct sockaddr_in ad, cad;
	ad.sin_family = AF_INET;
	ad.sin_port = htons(5000);
	ad.sin_addr.s_addr = INADDR_ANY;
	memset(ad.sin_zero, '\0', sizeof ad.sin_zero);
		
	if (setsockopt(	s, SOL_SOCKET, SO_REUSEADDR, &y, sizeof(int)) == -1) {
		exit(1);
	}
		
	if (bind(s, (struct sockaddr *)&ad, sizeof(struct sockaddr)) == -1) {
		perror("Unable to bind");
		exit(1);
	}
	if (listen(s, 10) == -1) {
		
		exit(1);
	}
	printf("Server setup - port 5000\n");
	fflush(stdout);

	FD_SET(s, &ms);
	int max;
	max = s;
	int io;
	while(1)
	{
	read_fds = ms;
		if(select(max+1, &read_fds, NULL, NULL, NULL) == -1)
		{
			
			exit(4);
		}
		io=0;
		while(io <= max)
		{
		if (FD_ISSET(io, &read_fds))
			{
				if (io == s)
				{
				
					
					socklen_t addrlen;
					addrlen = sizeof(struct sockaddr_in);
					int news;
					if((news = accept(s, (struct sockaddr *)&cad, &addrlen)) == -1) 
					{
					perror("Error : Connection not accepted");
					exit(1);
					}
					else 
					{
						FD_SET(news,&ms);
						if(news > max)
							{
								max = news;
							}
					
					printf("%s Connected on port %d \n",inet_ntoa(cad.sin_addr), ntohs(cad.sin_port));
				
					}
				}
				else{
				
					int rbytes, j;
	char msg[1024], buf[1024];
	rbytes = recv(io, msg, 1024, 0);
	
	if (rbytes  <= 0)
	 {
		if (rbytes == 0) 
		{
			printf("Disconnected : Socket %d \n", io);
		}else 
		{
			perror("Error in Receiving");
		}
		close(io);
	FD_CLR(io, &ms);
	 }
	else 
	{
	char pp[200];
	strcpy(pp,msg);
	char a = '/';
				
	int ii=0,flag =0;
	for(ii=0; ii<strlen(pp);ii++)
	{
		if (pp[ii]==a)
		{
			flag =1;
					
		}
	}
	if(flag==1)
	{
			char *ptr;
			int yas='/';
			ptr=strrchr(pp,yas);
			memmove(ptr, ptr+1, strlen(ptr));
			int lo= atoi(ptr);
			int index=ptr-pp;
				char *sss=pp;
				int as=0;
				as=strlen(sss)-(index+1);
				sss[strlen(sss)-as]='\0';
				sss[strlen(sss)-1]='\0';
				
		
		if (FD_ISSET(lo, &ms)){
			if (lo != s && lo != io) {
				if (send(lo, sss, rbytes, 0) == -1) {
					perror("Error in sending");
			}
		}
	}
			
	}
	else 
	{ 

		j=0;
		while(j <= max)
		{
		if (FD_ISSET(j, & ms))
	{
			if (j != s && j != io) 
		{
			if (send(j, msg, rbytes, 0) == -1) 
			{
				perror("Error in sending");
			}
		}
	}
			j++;
		}
	}
	}
		
					}
			}
			io++;
		}
	}
	return 0;
}
