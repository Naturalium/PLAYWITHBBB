#include <stdio.h>
#include <unistd.h>

int main(int argc, char * argv[], char * envlist[])
{
  while(*envlist)
    printf("%s\n", *envlist++);
}
