#include <stdio.h>
#include <unistd.h>

int main()
{
  char *envlist[] = {"APPLE=0", "BANANA=0", (char *)0};

  execle("ex08-13", "ex08-13", (char *) 0, envlist);
}
