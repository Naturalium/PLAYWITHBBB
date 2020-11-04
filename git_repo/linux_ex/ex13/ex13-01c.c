#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE	  sizeof(struct sockaddr_in)


int main()
{


  int sockfd;
  char msg, hostname[1024], *ipaddr;

  struct hostent *hent;
  struct sockaddr_in client = {AF_INET, INADDR_ANY, INADDR_ANY};
  struct sockaddr_in server = {AF_INET, 2007};

  int server_len = SIZE;

  gethostname(hostname, 1024);

  printf("hostname : %s\n", hostname);
  
  hent = gethostbyname(hostname);
  ipaddr = inet_ntoa(*((struct in_addr *)*(hent->h_addr_list)));
  printf("official name : %s\n", hent->h_name);
  printf("IP address : %s\n", ipaddr);

  server.sin_addr.s_addr = inet_addr(ipaddr);

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);

  msg = 'A';
  sendto(sockfd, &msg, 1, 0, (struct sockaddr *)&server, server_len);
  recvfrom(sockfd, &msg, 1, 0, (struct sockaddr *)&server, server_len);

  printf("recv from server : %c\n", msg);

  close(sockfd);

}
