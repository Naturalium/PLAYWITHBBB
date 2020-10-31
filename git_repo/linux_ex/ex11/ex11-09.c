#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int nc;
void alarm_action(int);

int main()
{
  int filedes[2], check;
  char msg = 'A';
  char buffer;

  struct sigaction act;
  act.sa_handler = alarm_action;
  sigfillset(&(act.sa_mask));

  if(pipe(filedes) == -1)
  {
    printf("fail to call pipe()\n");
    exit(1);
  }
  
  printf("PIPE size : %d bytes\n", fpathconf(filedes[1], _PC_PIPE_BUF));
  nc = 0;

  sigaction(SIGALRM, &act, NULL);
  alarm(1);
  while(1)
  {
    check = write(filedes[1], &msg, 1);
    if(check != -1)
     nc++;
  }





}

void alarm_action(int signum)
{
  printf("\n\nblocked after %d characters\n", nc);
  exit(1);
}
