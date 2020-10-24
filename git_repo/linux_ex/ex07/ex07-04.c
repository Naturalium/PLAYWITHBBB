#include <stdio.h>
#include <unistd.h>

int main()
{
  char *arg1[] = {"lsiiiiiiii"};
  char arg2[] = "ls";
  char *arg[] = {"ls", "-l", (char *)0};
  printf("input: %s%s%s\n", arg[0], arg[1], &arg[2]);
  printf("arg: %d\narg[0]: %d\n&arg[1]: %d\n&arg[2]: %d\n&arg[3]: %d\n&arg[4]: %d\n*arg: %d\n*arg[0]: %c\n*arg[1]: %c\n*(&arg[2]): %d\n&arg[0][2]: %d\n&arg[1][2]: %d\n&(*arg[2]): %d\narg[0][0]: %c\narg[0][1]: %c\narg[0][2]: %c\narg[0][3]: %c\narg[1][0]: %c\narg[1][1]: %c\narg[1][2]: %c\narg[1][3]: %c\narg[2]: %c\nsize of arg: %d\n"
	  ,arg, &arg[0], &arg[1], &arg[2], &arg[3], &arg[4], *arg, *arg[0], *arg[1], *(&arg[2]), &arg[0][2], &arg[1][2], &(*arg[2]), arg[0][0], arg[0][1], arg[0][2],arg[0][3],arg[1][0], arg[1][1], arg[1][2],arg[1][3], arg[2], sizeof(arg));

  printf("arg[0]: %d\narg[1]: %d\narg[2]: %d\n", arg[0], arg[1], arg[2]);
  printf("size of *(arg[0]): %d\n", sizeof(*(arg[0])));
  printf("size of arg1[0]: %d\n", sizeof(*arg[0]));
  printf("size of *arg1 %d\n", sizeof(*arg1));
  printf("size of (*arg1)[0]: %d\n", sizeof((*arg1)[0]));
  printf("size of &(*arg1)[0]: %d\n", sizeof(&(*arg1)[0]));
  printf("size of arg1 %d\n", sizeof(arg1));
  printf("size of arg2: %d\n", sizeof(arg2));
  printf("size of arg[0]: %d\n", sizeof(arg[0]));
  printf("size of \"ls\": %d\n", sizeof("ls"));
int a = 0;

  printf("before executing ls -l\n");
  execv("/bin/ls", arg);
  printf("after executing ls -l\n");
}
