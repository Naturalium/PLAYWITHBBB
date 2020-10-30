#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define SIZE 512

int main()
{
  char msg[SIZE];
  int filedes[2];

  pid_t pid;

  if(pipe(filedes) == -1)
  {
    printf("fail to call pipe()\n");
    exit(1);
  }
  
  if((pid = fork()) == -1)
  {
    printf("fail to call fork()\n");
    exit(1);
  }
  else if(pid > 0)
  {
    strcpy(msg, "apple is red.\n");
    write(filedes[1], msg, SIZE);
    printf("[parent] %s\n", msg);
    //pause();
  }
  else
  {
    sleep(1);
    read(filedes[0], msg, SIZE);
    printf("[child] %s\n", msg);
    //raise(SIGINT);
  }
}
