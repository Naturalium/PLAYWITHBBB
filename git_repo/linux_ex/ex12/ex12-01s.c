#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>


#define SIZE	sizeof(struct sockaddr_in)

int main()
{
  int sockfd_listen;
  int sockfd_connect;


  char c;

  struct sockaddr_in server = {AF_INET, 5000, INADDR_ANY};

  printf("socket()\n");
  sockfd_listen = socket(AF_INET, SOCK_STREAM, 0);

  printf("bind()\n");
  bind(sockfd_listen, (struct sockaddr *) &server, SIZE);

  printf("waiting for client\n");
  sockfd_connect = accept(sockfd_listen, 0, 0);
  printf("accepted\n");

  recv(sockfd_connect, &c, 1, 0);
  printf("recv %c from client\n", c);


  c++;
  printf("send %c to client\n", c);
  send(sockfd_connect, &c, 1, 0);

  printf("close()\n");
  close(sockfd_connect);
  close(sockfd_listen);

}
