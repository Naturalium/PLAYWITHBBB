#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define MSGSIZE 100

int main()
{
  int filedes;

  printf("[exec] standard output\n");

  sleep(1);

  filedes = open("./fifo", O_WRONLY);
  write(filedes, "from exec via FIFO", MSGSIZE);
  close(filedes);
}
