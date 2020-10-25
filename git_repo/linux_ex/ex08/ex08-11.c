#include <unistd.h>
#include <stdio.h>

int main()
{
  printf("%s\n", getenv("APPLE"));
  unsetenv("APPLE");
  

  if(!getenv("APPLE"))
    printf("APPLE is not found\n");
}
