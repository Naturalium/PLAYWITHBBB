#include <stdio.h>
#include <stdlib.h>

void func1(void);
void func2(void);


int main()
{
  printf("hello!\n");
  atexit(func1);
  atexit(func2);

  printf("bye!\n");
  exit(0);
}


void func1()
{
  printf("func1!\n");
}

void func2()
{
  printf("fucn2!\n");
}
