 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <unistd.h>
 #include <errno.h>
 	
 	
 int main()
 {
 	
 	
 	
 	fd_set ms;
 	FD_ZERO(&ms);
 	fd_set read_fds;
 	FD_ZERO(&read_fds);
 	FD_SET(0, &ms);
 	int s, max, i;
 	struct sockaddr_in sad;
 	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
 		perror("Error : Socket");
 		exit(1);
 	}
 	sad.sin_family = AF_INET;
 	sad.sin_port = htons(5000);
 	sad.sin_addr.s_addr = inet_addr("127.0.0.1");
 	memset(sad.sin_zero, '\0', sizeof sad.sin_zero);
 	
 	if(connect(s, (struct sockaddr *)&sad, sizeof(struct sockaddr)) == -1) {
 		perror("Error : Connect");
 		exit(1);
 	}
 	max = s;
 	long okay;
 	FD_SET(s, &ms);
 	int no;
 	
 	while(1){
 		int lalala;
		read_fds = ms;
		long hey;
		if(select(max+1, &read_fds, NULL, NULL, NULL) == -1){
			
			exit(4);
		}
		i=0;
		while(i <= max )
		{
				if(FD_ISSET(i, &read_fds))
			{
				char rmsg[1024];
				long gg;
 				int rbytes;
 				int asd;
 				long sooo;
 				char smsg[1024];
 	
 
 	if (i != 0)
	 {
	 	rbytes = recv(s, rmsg, 1024, 0);
 		rmsg[rbytes] = '\0';
 		printf("%s\n" , rmsg);
 		fflush(stdout);
 		
 	}else 
	 {
	 	fgets(smsg, 1024, stdin);
 		if (strcmp(smsg , "quit\n") == 0) {
 			exit(0);
 		}else
 			send(s, smsg, strlen(smsg), 0);
 		
 	}
			}i++;
		}
		
			
 	}
 	printf("Quit : Client\n");
 	close(s);
 	return 0;
 }
