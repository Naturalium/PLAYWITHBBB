#include <unistd.h>

int main()
{
  execl("ex07-05", "apple", "option", (char *) 0);
}
