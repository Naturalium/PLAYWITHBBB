#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/utsname.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE sizeof(struct sockaddr_in)


int main()
{

  int sockfd;
  char msg;

  struct utsname info;
  struct hostent *hent;
  struct sockaddr_in server = {AF_INET, 2007, INADDR_ANY};
  struct sockaddr_in client;

  int client_len = SIZE;

  uname(&info);
  printf("node name : %s\n", info.nodename);

  hent = gethostbyname(info.nodename);
  printf("official name : %s\n", hent->h_name);

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);

  bind(sockfd, (struct sockaddr *)&server, SIZE);

  recvfrom(sockfd, &msg, 1, 0, (struct sockaddr *)&client, &client_len);
  
  printf("recv from client : %c\n", msg);

  sendto(sockfd, &msg, 1, 0, (struct sockaddr *)&client, client_len);

  sleep(1);
  close(sockfd);



}
