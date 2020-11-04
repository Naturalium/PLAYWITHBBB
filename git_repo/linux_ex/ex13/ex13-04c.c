#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE	sizeof(struct sockaddr_in)
#define MSGSIZE 1024

int main()
{
  int sockfd;
  char msg, prev;

  struct sockaddr_in client = {AF_INET, INADDR_ANY, INADDR_ANY};
  int server_len = SIZE;
  struct sockaddr_in server = {AF_INET, 2007};
  
//  server.sin_addr.s_addr = inet_addr("202.31.200.87");

  if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
  {
    printf("fail to call socket()\n");
    exit(1);
  }

  msg = prev = '\n';
  while(read(0, &msg, 1) != 0)
  {

    if((sendto(sockfd, &msg, 1, 0, (struct sockaddr *)&server, server_len)) == -1)
    {
      printf("fail to send message\n");
      continue;
    }
    if((recvfrom(sockfd, &msg, 1, 0, (struct sockaddr *)&server, &server_len)) == -1)
    {
      printf("fail to receive message\n");
      continue;
    }
    printf("%s%c", (prev == '\n') ? "[recv] " : "", msg);
    prev = msg;
  }

  close(sockfd);


}
