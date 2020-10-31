#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SIZE	  sizeof(struct sockaddr_in)

int main()
{
  int sockfd;
  char send_c, recv_c;
  struct sockaddr_in server = {AF_INET, 5000};

  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  printf("socket()\n");
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  printf("connect()\n");
  connect(sockfd, (struct sockaddr *)&server, SIZE);

  send_c = 'A';

  printf("send %c to server\n", send_c);
  send(sockfd, &send_c, 1, 0);

  recv(sockfd, &recv_c, 1, 0);
  printf("recv %c from server\n" , recv_c);

  printf("close()\n");
  close(sockfd);
  

}
