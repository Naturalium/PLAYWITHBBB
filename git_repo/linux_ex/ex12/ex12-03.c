#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

  int sockfd;

  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {

    printf("fail to call socket()\n");
    exit(1);

  }

  printf("socket descriptor is %d\n", sockfd);

  close(sockfd);


}
