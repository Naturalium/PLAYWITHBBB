#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>


#define SIZE sizeof(struct sockaddr_in)



int main()
{
  int sockfd;
  struct sockaddr_in addr;

  addr.sin_family = AF_INET;
  addr.sin_port = 1004;
  addr.sin_addr.s_addr = INADDR_ANY;

  if(bind(sockfd, (struct sockaddr *)&addr, SIZE) == -1)
  {

    printf("fail to call bind()\n");
    exit(1);
  }

  close(sockfd);

}
