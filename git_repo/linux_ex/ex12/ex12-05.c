#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>

#define SIZE sizeof(struct sockaddr_in)

int main()
{


  int sockfd_listen;
  char c;

  struct sockaddr_in server = {AF_INET, 5000, INADDR_ANY};

  /* calling socket() */

  /* calling bind() */

  if(listen(sockfd_listen, 5) == -1)
  {
    printf("fail to call listen()\n");
    exit(1);
  }

  /* network process */
  

}
