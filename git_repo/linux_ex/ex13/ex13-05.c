#include <sys/utsname.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
  struct utsname info;
  char myname[1024];

  uname(&info);
  printf("sysname: %s\n", info.sysname);
  printf("nodename: %s\n", info.nodename);
  printf("release: %s\n", info.release);
  printf("version: %s\n", info.version);
  printf("machine: %s\n", info.machine);

  gethostname(myname, 1024);
  printf("hostname: %s\n", myname);
}
