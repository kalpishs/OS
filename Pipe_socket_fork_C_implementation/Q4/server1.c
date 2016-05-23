#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
 
     char resarr[256];//for result error 
     int i,k;
     int result,optval=1;
     int sockfd, newsockfd, portno, clilen;//sockfd and newsockfd file descriptors 
     char buffer[256];// data is read into buffer array
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = 15786;
     
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;//server takes ip address of the machine
     serv_addr.sin_port = htons(portno);// port no provided.
  
         if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
      
        error("ERROR on binding");
while(1)
{
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
while(1)
{
  

bzero(buffer,256);
bzero(resarr,256);
      n = recv(newsockfd,buffer,255,0);// Reading from socket
 
     if (n == 0) break;
i = 0;
k=0;

/*These lines are use for manipulating the character buffer so that ASCII IS acchived*/
printf("String received :%s",buffer);
while(buffer[i] != '\0')
{
       
        i++;
}

i=i-1;
for (result = 0; result < i; result++)
{
    k = k + buffer[result];
    /* k sum up the ASCII value */
}

snprintf(resarr,sizeof(k),"%d",k);
n = send(newsockfd,resarr,18,0);
printf("Sum sent : %s\n",resarr);
if (n < 0) error("ERROR writing to socket");


}  
}
close(newsockfd);// while breaks only when client has left so we close the socket

     return 0; 
}
