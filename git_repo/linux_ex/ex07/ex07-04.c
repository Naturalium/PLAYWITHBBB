#include <stdio.h>
#include <unistd.h>

int main()
{
  char *arg[] = {"ls", "-l", (char *)0};
  printf("input: %s%s%s\n", arg[0], arg[1], &arg[2]);
  printf("arg: %d\narg[0]: %d\narg[1]: %d\narg[2]: %d\narg[3]: %d\narg[4]: %d\n*arg[0]: %c\n*arg[1]: %c\n&arg[0][2]: %d\n&arg[1][2]: %d\narg[0][0]: %c\narg[0][1]: %c\narg[0][2]: %c\narg[0][3]: %c\narg[1][0]: %c\narg[1][1]: %c\narg[1][2]: %c\narg[1][3]: %c\narg[2]: %c\nsize of arg: %d\n"
	  ,arg, &arg[0], &arg[1], &arg[2], &arg[3], &arg[4], *arg[0], *arg[1], &arg[0][2], &arg[1][2], arg[0][0], arg[0][1], arg[0][2],arg[0][3],arg[1][0], arg[1][1], arg[1][2],arg[1][3], arg[2], sizeof(arg));

int a = 0;

  printf("before executing ls -l\n");
  execv("/bin/ls", arg);
  printf("after executing ls -l\n");
}
