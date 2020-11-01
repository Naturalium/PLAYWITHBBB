#include <stdio.h>
/*

............헤더 추가하라고오오

   */

#define SIZE ssizeof(struct sockaddr_in)

int sockfd_connect;

int main()
{

  /*소켓생성*/
  /*bind 호출*/
  /*listen 호출*/
  while(1)
  {
    while(recv(sockfd_connect, &c, 1, 0) > 0)
      send(sockfd_connect, %c, 1, 0);

    close(sockfd_connect);
  }
}

