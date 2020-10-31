#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
  int p[2];
  pid_t pid;

  if(pipe(p) == -1)
  {
    printf("fail to call pipe()\n");
    exit(1);
  }
  


  if((pid = fork()) == - 1)
  {
    printf("fail to fork()\n");
    exit(1);
  }
  else if(pid > 0)
  {
    printf("[parent]\n");
    close(p[0]);
    dup2(p[1], 1);
    execlp("ls", "ls", "-al", (char *)0);
    printf("[parent] fail to call execlp()");
  }
  else
  {
    printf("[child]\n");
    close(p[1]);
    dup2(p[0], 0);
    execlp("wc", "wc", (char *)0);
    printf("[child] fail to call execlp()\n");
  }
  
}
