#include <stdio.h>
/*
...............추가하거라
   */

int sockfd_connect;

int main()
{

  int sockfd_listen;
  char c;
  struct sockaddr_in server = {AF_INET, 5000, INADDR_ANY};

  if((sockfd_listen = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    printf("fail to call socket()\n");
    exit(1);
  }
  if(bind(sockfd_listen, (struct *)&server, SIZE) == -1)
  {
    printf("fail to call socket()\n");
    exit(1);
  }
  if(listen(sockfd_listen, 5) == -1)
  {
    printf("fail to call listen()\n");
    exit(1);
  }

  while(1)
  {
    if((sockfd_connect = accept(sockfd_listen, NULL, NULL)) == -1)
    {
      printf("fail to call accept()\n");
      continue;
    }
    /*		do communicate usidng sockfd_connect		*/
  }

}
