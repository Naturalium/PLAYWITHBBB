#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  pid_t pid;
  int status;

  pid = fork();

  if(pid > 0)
  {
    printf("parent: waitng...\n");
    wait(&status);
    //status = status & 0xFF;
    printf("parent: status is %d\n", status);
  }
  else if(pid == 0)
  {
    sleep(1);
    printf("child: bye!\n");
    exit(1234);
  }
  else
    printf("fali to fork\n");
  printf("bye!\n");

}
