#include <unistd.h>
#include <netdb.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  struct hostent *hent;
  char **ptr;

  if(argc < 2)
  {
    printf("%s hostname\n", argv[0]);
    exit(1);
  }

  if((hent = gethostbyname(argv[1])) == NULL)
  {
    printf("fail to call gethostbyname()\n");
    exit(1);
  }

  printf("official name : %s\n", hent->h_name);

  for(ptr = hent->h_aliases; *ptr != NULL; *ptr++)
    printf("\talias : %s\n", *ptr);

  if(hent->h_addrtype == AF_INET)
  {
    ptr = hent->h_addr_list;
    for(; *ptr != NULL; ptr++)
      printf("\taddress : %s\n", inet_ntoa(*((struct in_addr *)*ptr)));
  }
}
