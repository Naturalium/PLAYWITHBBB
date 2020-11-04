#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE sizeof(struct sockaddr_in)
#define MSGSIZE 1024

int main()
{
  int sockfd;
  char msg ,prev;

  struct sockaddr_in server = {AF_INET, 2007, INADDR_ANY};

  struct sockaddr_in client;
  int client_len = SIZE;

  if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
  {
    printf("fail to call socket()\n");
    exit(1);
  }



  if((bind(sockfd, (struct sockaddr *)&server, SIZE)) == -1)
  {
    printf("fail to call bind()\n");
    exit(1);
  }

  prev = '\n';
  while(1)
  {
    if(recvfrom(sockfd, &msg, 1, 0, (struct sockaddr *)&client, &client_len) == -1)
    {
      printf("fail to receive message\n");
      continue;
    }
    printf("%s%c", (prev == '\n') ? "[recv] " : "", msg);
    prev = msg;

    if(sendto(sockfd, &msg, 1, 0, (struct sockaddr *)&client, client_len) == -1)
    {
      printf("fail to send message\n");
      continue;
    }
  }



}
