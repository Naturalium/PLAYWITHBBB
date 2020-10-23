#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

void cleanupaction(void);


int main()
{
  pid_t pid;
  int i;

  for(i = 0; i < 3; i++)
  {
    printf("before fork [%d]\n", i);
    sleep(1);
  }
  
  pid = fork();

  if(pid > 0)
  {
    for(; i < 7; i++)
    {
      printf("parent [%d]\n", i);
      sleep(1);
    }
    atexit(cleanupaction);
  }

  else if(pid == 0)
  {
    for(; i < 5; i++)
    {
      printf("child [%d]\n", i);
      sleep(1);
      execl("/bin/ls", "ls", "-l", (char*) 0);
    }
  }
  
  else
    printf("fail to fork child process\n");
  
  
  exit(0);


}

void cleanupaction(void)
{
  printf("clean-up-action\n");
}

