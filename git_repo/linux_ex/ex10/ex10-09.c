#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void handler(int signum);

int main()
{
  struct sigaction act;

  sigfillset(&(act.sa_mask));
  act.sa_handler = handler;

  sigaction(SIGINT, &act, NULL);
  
  printf("pause return %d\n", pause());

}

void handler(int signum)
{
  printf("\nSIGINT catched\n\n");
}
